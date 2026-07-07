#include <crow.h>
#include <unordered_map>
#include "user.h"
#include "json_utils.h"
#include "routes.h"
#include "cors_middleware.h"

int main()
{
    crow::App<cors_middleware> app;

    //Maps to created a sorted in memory database
    std::map<int,Users> users;
    users[1] = {1, "Soham", "AI Engineer"};
    users[2] = {2, "Alex", "Backend Developer"};
    users[3] = {3, "John", "Data Scientist"};

    int nextID = users.rbegin()->first+1;   //Server creates its own id aka primary key

    registerRoutes(app, users, nextID);//testing routes.cpp

    app.port(18080).multithreaded().run();
}