#ifndef SEARCHBYID_H
#define SEARCHBYID_H
#include "../studentRecord.cpp"

void searchById(){
    if(start == NULL){
        cout << "\n[X] THERE IS NO STUDENT RECORDS TO SEARCH!\n\n";
    } else {
        bool isFound = false;
        string targetValue;
        cout << "\n>> ENTER ID: ";
        cin  >> targetValue;
        struct student *current = start;

        while(current != NULL){
            if(current -> id == targetValue){
                isFound = true;
                cout << "\n-------------------------------------\n"
                     << "-> NAME : " << current -> firstName << " " << current -> middleName << " " << current -> lastName << "\n"
                     << "-> AGE  : " << current -> age << "\n"
                     << "-> ID   : " << current -> id << "\n"
                     << "-> GPA  : " << current -> gpa << "\n"
                     << "-> DEP  : " << current -> department << "\n"
                     << "-------------------------------------\n";
                break;
            }
            current = current -> next;
        }

        if(!isFound){
            cout << "\n[X] THERE IS NO STUDENT WITH ID [" << targetValue << "]!\n\n";
        }
    }
}

#endif