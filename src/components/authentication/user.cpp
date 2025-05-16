#ifndef USER_CPP
#define USER_CPP
#include <iostream>
#include <fstream>
using namespace std;

struct user {
    string firstName, middleName, lastName, id, userName, password;
    int age;
    bool isAdmin;
    struct user *pre, *next;
};

struct user *head = NULL;

const string userData = "users.txt";

#endif