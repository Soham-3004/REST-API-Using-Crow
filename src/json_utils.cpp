#include <json_utils.h>

crow::json::wvalue userToJson(const Users& user)
{
    crow::json::wvalue x;

    x["id"] = user.id;
    x["name"] = user.name;
    x["role"] = user.role;

    return x;
}