#include <iostream>
#include "database.h"

sqlite3* db = nullptr;

bool openDatabase(){
    int rc = sqlite3_open("/home/soham/rest-api-learning/database/users.db", &db);
    if(rc == SQLITE_OK){
        std::cout<<"DB opened!"<<std::endl;
        return true;
    }
    return false;
}

sqlite3* getDatabase(){
    return db;
}

void closeDatabase(){
    sqlite3_close(db);
    std::cout<<"DB closed!"<<std::endl;
    return;
}