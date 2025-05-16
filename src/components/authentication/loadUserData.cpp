#ifndef LOADUSERDATA_H
#define LOADUSERDATA_H
#include "user.cpp"

void loadUsers() {
    ifstream loader(userData);

if(loader.is_open()){
    string firstName, middleName, lastName, id, userName, password;
    int age;
    bool isAdmin;

    while (getline(loader, firstName)) {
        getline(loader, middleName);
        getline(loader, lastName);
        getline(loader, id);
        loader >> age;
        loader.ignore();
        getline(loader, userName);
        getline(loader, password);
        loader >> isAdmin;
        loader.ignore();

        struct user* temp = new user;
        temp -> firstName = firstName;
        temp -> middleName = middleName;
        temp -> lastName = lastName;
        temp -> id = id;
        temp -> age = age;
        temp -> userName = userName;
        temp -> password = password;
        temp -> isAdmin = isAdmin;

        if (head == NULL) {
            head = temp;
            head -> next = NULL;
            head -> pre = NULL;
        } else {
            temp -> next = head;
            temp -> pre = NULL;
            head -> pre = temp;
            head = temp;
        }
    }

    loader.close();
} else {
    return;
}
}

#endif