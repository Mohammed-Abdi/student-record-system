#ifndef ADMINMAINMENU_H
#define ADMINMAINMENU_H
#include "../deletion/deletionMenu.cpp"
#include "../aboutUs.cpp"
#include "../display/displayMenu.cpp"
#include "../insertion/insertionMenu.cpp"
#include "../updaterecord.cpp"

void adminMainMenu(){
    string choice;
    do{
        cout << "\n----- MAIN MENU --------\n"
             << "1. INSERT STUDENT\n"
             << "2. DISPLAY STUDENT\n"
             << "3. DELETE STUDENT\n"
             << "4. UPDATE STUDENT\n"
             << "5. ABOUT US\n"
             << "6. LOGOUT\n\n>> CHOOSE [1-6]: ";
        cin >> choice;
        cout << "------------------------\n";

        if(choice == "1"){
            insertionMenu();
        } else if(choice == "2"){
            displayMenu();
        } else if(choice == "3"){
            deletionMenu();
        } else if(choice == "4"){
            updateMenu();
        } else if(choice == "5"){
            aboutUs();
        } else if(choice == "6"){
            cout << "\n[i] LOGOUT SUCCESSFUL\n\n";
        } else {
            cout << "\n[X] THERE IS NO OPTION \"" << choice << "\"\n\n";
        }
    } while(choice != "6");
}

#endif