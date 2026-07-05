#pragma once

#include <crow.h>
#include "user.h"

crow::json::wvalue userToJson(const Users& user);