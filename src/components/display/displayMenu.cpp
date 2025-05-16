#ifndef DISPLAYMENU_H
#define DISPLAYMENU_H
#include "displayAll.cpp"
#include "searchById.cpp"

void displayMenu(){
    string choice;
    do{
        cout << "\n----- Display ----------\n"
             << "1. Display All\n"
             << "2. Search By ID\n"
             << "3. Back\n\n>> choose[1-5]: ";
        cin >> choice;
        cout << "------------------------\n";

        if(choice == "1"){
            displayAll();
        } else if(choice == "2"){
            searchById();
        } else if(choice == "3"){
            cout << "\n[i]  Redirecting to homepage...\n\n";
        } else {
            cout << "\n[X] There is no option \"" << choice << "\"\n";
        }

    } while(choice != "3");
}

#endif