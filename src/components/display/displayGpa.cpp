#ifndef DISPLAYGPA_H
#define DISPLAYGPA_H
#include "../studentRecord.cpp"

void displayGpa(string id){
    if(start == NULL){
        cout << "\n[X] YOUR INFORMATION WAS NOT FOUND ON THE SERVER!\n\n";
    } else {
        struct student *currentUser = start;
        bool isFound = false;

        while(currentUser != NULL){
            if(currentUser -> id == id){
                isFound = true;
                cout << "\n[i] HEY " << currentUser -> firstName << " --------\n"
                     << "[?] YOUR GPA IS \"" << currentUser -> gpa << "\"\n";
                break;
            }
            currentUser = currentUser -> next;
        }

        if(!isFound){
            cout << "\n[X] YOU INFORMATION WAS NOT FOUND ON THE SERVER!\n\n";
        }
    }
}

#endif