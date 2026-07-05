#pragma once

#include <crow.h>
#include <map>

#include "user.h"

void registerRoutes(
    crow::SimpleApp& app,
    std::map<int, Users>& users,
    int& nextID
);