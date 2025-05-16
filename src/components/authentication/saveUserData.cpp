#ifndef SAVEUSERDATA_H
#define SAVEUSERDATA_H
#include "user.cpp"

void saveUsers() {
    ofstream saver(userData);
    struct user* current = head;

    while (current != NULL) {
        saver << current -> firstName << "\n"
              << current -> middleName << "\n"
              << current -> lastName << "\n"
              << current -> id << "\n"
              << current -> age << "\n"
              << current -> userName << "\n"
              << current -> password << "\n"
              << current -> isAdmin << "\n";

        current = current -> next;
    }
    saver.close();
}

#endif