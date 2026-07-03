#include <crow.h>
#include <unordered_map>

struct Users{
    int id;
    std::string name;
    std::string role;
};

int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")    //lambda code [capture] (parameters) {  /*code*/ }
    ([]()   
    {
        return "Hello REST API\n";
    });

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

    std::map<int,Users> users;
    users[1] = {1, "Soham", "AI Engineer"};
    users[2] = {2, "Alex", "Backend Developer"};
    users[3] = {3, "John", "Data Scientist"};

    CROW_ROUTE(app,"/users/<int>")
    ([&users](int id){
        auto it = users.find(id);
        if(it == users.end()){
            return crow ::response(404,"User not found");
        }

        crow::json::wvalue x;
        x["id"] = it->second.id;
        x["name"] = it->second.name;
        x["role"] = it->second.role;

        return crow::response{x};
    });

    crow::json::wvalue userJSON;
    int i=0;
    for(const auto& [id, user] : users){
        crow::json::wvalue obj;
        obj["id"] = user.id;
        obj["name"] = user.name;
        obj["role"] = user.role;
        userJSON[i++] = std::move(obj);
    }
    CROW_LOG_INFO << userJSON.dump(); 

    app.port(18080).multithreaded().run();
}