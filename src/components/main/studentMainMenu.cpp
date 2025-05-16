#ifndef STUDENTMAINMENU_H
#define STUDENTMAINMENU_H
#include "../display/displayGpa.cpp"
#include "../display/displayUserInfo.cpp"
#include "../aboutUs.cpp"

void studentMainMenu(string storeId){
    string choiceValue;
    do{
        cout << "\n----- MAIN MENU --------\n"
             << "1. MY INFO\n"
             << "2. MY GPA\n"
             << "3. ABOUT US\n"
             << "4. LOGOUT\n\n>> CHOOSE [1-4]: ";
        cin >> choiceValue;
        cout << "------------------------\n";

        if(choiceValue == "1"){
            displayUserInfo(storeId);
        } else if(choiceValue == "2"){
            displayGpa(storeId);
        } else if(choiceValue == "3"){
            aboutUs();
        } else if(choiceValue == "4"){
            cout << "\n[i] LOGOUT SUCCESSFUL\n\n";
        } else {
            cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n\n";
        }
    } while(choiceValue != "4");
}

#endif