#ifndef DELETEMENU_H
#define DELETEMENU_H
#include "deleteFirst.cpp"
#include "deleteLast.cpp"
#include "deleteById.cpp"
#include "deleteAll.cpp"

void deletionMenu(){
    string choiceValue;
    do{
        cout << "\n----- DELETING ----------------------\n"
             << "1. DELETE FIRST\n"
             << "2. DELETE LAST\n"
             << "3. DELETE BY ID\n"
             << "4. DELETE ALL\n"
             << "5. BACK\n\n>> CHOOSE [1-5]: ";
        cin >> choiceValue;
        cout << "-------------------------------------\n";

        if(choiceValue == "1"){
            deleteFirst();
        } else if(choiceValue == "2"){
            deleteLast();
        } else if(choiceValue == "3"){
            deleteById();
        } else if(choiceValue == "4"){
            deleteAll();
        } else if(choiceValue == "5"){
            cout << "\n[i] REDIRECTING TO HOMEPAGE...\n\n";
        } else {
            cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n";
        }

    } while(choiceValue != "5");
}

#endif