#ifndef INSERTMENU_H
#define INSERTMENU_H
#include "insertFirst.cpp"
#include "insertLast.cpp"
#include "insertAfterId.cpp"
#include "insertBeforeId.cpp"
using namespace std;

void insertionMenu(){
    string choice;
    do {
        cout << "\n----- INSERT -----------------------\n"
             << "1. INSERT FIRST\n"
             << "2. INSERT LAST\n"
             << "3. INSERT AFTER A STUDENT (BY ID)\n"
             << "4. INSERT BEFORE A STUDENT (BY ID)\n"
             << "5. BACK\n\n>> CHOOSE [1-5]: ";
        cin >> choice;
        cout << "-----------------------------------\n";

        if(choice == "1"){
            insertFirst();
            insertMoreFirst();
        } else if(choice == "2"){
            insertLast();
            insertMoreLast();
        } else if(choice == "3"){
            insertAfter();
        } else if(choice == "4"){
            insertBefore();
        } else if(choice == "5"){
            cout << "\n[<] REDIRECTING TO HOMEPAGE...\n\n";
        } else {
            cout << "\n[X] THERE IS NO OPTION \"" << choice << "\"\n\n";
        }
    } while(choice != "5");
}

#endif