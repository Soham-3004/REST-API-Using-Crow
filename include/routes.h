#pragma once

#include <crow.h>
#include <map>
#include "cors_middleware.h"
#include "user.h"

void registerRoutes(
    crow::App<cors_middleware>& app,
    std::map<int, Users>& users,
    int& nextID
);