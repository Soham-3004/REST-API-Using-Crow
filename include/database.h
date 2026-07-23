#pragma once

#include<sqlite3.h>

bool openDatabase();
void closeDatabase();
sqlite3* getDatabase();