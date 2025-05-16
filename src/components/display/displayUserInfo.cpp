#ifndef DISPLAYUSERINFO_H
#define DISPLAYUSERINFO_H
#include "../studentRecord.cpp"

void displayUserInfo(string id){
    if(start == NULL){
        cout << "\n[X] YOUR INFORMATION WAS NOT FOUND ON THE SERVER!\n\n";
    } else {
        struct student *currentUser = start;
        bool isFound = false;

        while(currentUser != NULL){
            if(currentUser -> id == id){
                isFound = true;
                cout << "\n--- MY INFO -------------------------\n"
                 << "-> NAME : " << currentUser -> firstName << " " << currentUser -> middleName << " " << currentUser -> lastName << "\n"
                 << "-> AGE  : " << currentUser -> age << "\n"
                 << "-> ID   : " << currentUser -> id << "\n"
                 << "-> DEP  : " << currentUser -> department << "\n"
                 << "--------------------------------------\n";

                break;
            }
            currentUser = currentUser -> next;
        }

        if(!isFound){
            cout << "\n[X] YOUR INFORMATION WAS NOT FOUND ON THE SERVER!\n\n";
        }
    }
}

#endif