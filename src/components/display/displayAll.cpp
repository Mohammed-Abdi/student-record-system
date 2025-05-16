#ifndef DISPLAYALL_H
#define DISPLAYALL_H
#include "../studentRecord.cpp"

void displayAll(){
    if(start == NULL){
        cout << "\n[X] THERE IS NO STUDENT RECORD TO DISPLAY!\n\n";
    } else {
        struct student *displayAll = start;

        while(displayAll != NULL){
            cout << "\n-------------------------------------\n"
                 << "-> NAME : " << displayAll -> firstName << " " << displayAll -> middleName << " " << displayAll -> lastName << "\n"
                 << "-> AGE  : " << displayAll -> age << "\n"
                 << "-> ID   : " << displayAll -> id << "\n"
                 << "-> GPA  : " << displayAll -> gpa << "\n"
                 << "-> DEP  : " << displayAll -> department << "\n"
                 << "-------------------------------------\n";
            displayAll = displayAll -> next;
        }
    }
}

#endif