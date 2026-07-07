#pragma once
#include <crow.h>

struct cors_middleware
{
    struct context
    {
        /* data */
    };
    void before_handle(crow::request& req, crow::response &res, context &ctx){

    }
    void after_handle(crow::request& req, crow::response &res, context &ctx){
        res.add_header( "Access-Control-Allow-Origin","*");
    }
};
