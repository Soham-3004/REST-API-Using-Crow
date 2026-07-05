#include <crow.h>
#include <unordered_map>
#include "user.h"
#include "json_utils.h"

int main()
{
    crow::SimpleApp app;
    //simple get routes
    CROW_ROUTE(app, "/")    //lambda code [capture] (parameters) {  /*code*/ }  
    ([]()   
    {
        return "Hello REST API\n";
    });
    //Using JSON
    CROW_ROUTE(app, "/about")    //These are static routes
    ([]()   
    {
        crow::json::wvalue x;
        x["name"] = "Soham";
        x["role"] = "Systems Engineer";
        x["learning"] = "REST API";

        return x;
    });

    CROW_ROUTE(app, "/skills")    //Using JSON
    ([]()   
    {
        crow::json::wvalue x;
        x["skill 1"] = "C";
        x["skill 2"] = "C++";
        x["skill 3"] = "CUDA";

        return x;
    });    
    //Maps to created a sorted in memory database
    std::map<int,Users> users;
    users[1] = {1, "Soham", "AI Engineer"};
    users[2] = {2, "Alex", "Backend Developer"};
    users[3] = {3, "John", "Data Scientist"};
    //Search in database using GET
    CROW_ROUTE(app,"/users/<int>")
    ([&users](int id){
        auto it = users.find(id);
        if(it == users.end()){
            return crow ::response(404,"User not found");
        }

        return crow::response{userToJson(it->second)};
    });
    //Returning entire database as an array of json
    CROW_ROUTE(app,"/users")
    ([&users](){
        crow::json::wvalue userJSON;
        int i=0;
        for(const auto& [id, user] : users){
            userJSON[i++] = userToJson(user);
        }
        return userJSON;
    });
    //Update or  POST method
    int nextID = users.rbegin()->first+1;   //Server creates its own id aka primary key
    CROW_ROUTE(app,"/users").methods(crow::HTTPMethod::Post)    //using post method
    ([&users,&nextID](const crow::request& req){
        auto body = crow::json::load(req.body);
        if (!body){
            return crow::response(400, "Invalid JSON");
        }

        Users user;
        user.id = nextID++;
        user.name = body["name"].s();
        user.role = body["role"].s();
        users[user.id] = user;

        return crow::response{userToJson(user)};
    });
    //updating database with PUT which is a Idempotent method
     CROW_ROUTE(app,"/users/<int>").methods(crow::HTTPMethod::Put)
     ([&users](const crow::request& req, int id){
        auto it = users.find(id);
        if(it == users.end()){
            return crow ::response(404,"User not found");
        }

        auto body = crow::json::load(req.body);
        if(!body){
            return crow::response(400, "Invalid JSON");
        }

        it->second.name = body["name"].s();
        it->second.role = body["role"].s();

        return crow::response{userToJson(it->second)};
     });
     //Delete
     CROW_ROUTE(app,"/users/<int>").methods(crow::HTTPMethod::Delete)
     ([&users](int id){
        auto it = users.find(id);
        if(it == users.end()){
            return crow ::response(404,"User not found");
        }
        users.erase(it);
        return crow::response(204, "User deleted successfully!");
     });

    app.port(18080).multithreaded().run();
}