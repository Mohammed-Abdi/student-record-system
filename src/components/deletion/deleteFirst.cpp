#ifndef DELETEFIRST_H
#define DELETEFIRST_H
#include "../studentRecord.cpp"
#include "../recordFile/recordFile.cpp"

void deleteFirst(){
    if(start == NULL){
        cout << "\n[X] THERE IS NO STUDENT RECORDS TO DELETE!\n\n";
    } else {
        struct student *current;
        struct student *nextStudent;
        string storeIdValue;

        current = start;

        string choiceValue;
        cout << "[!] ARE YOU SURE YOU WANT TO DELETE \"" << current -> firstName << "\"? [Y/N]: ";
        cin >> choiceValue;

        if(choiceValue == "Y" || choiceValue == "y"){
            storeIdValue = current -> id;

            if(current -> next == NULL){
                delete current;
                start = NULL;
            } else {
                nextStudent = current -> next;
                start = nextStudent;
                nextStudent -> pre = NULL;
                delete current;
            }

            cout << "\n[i] FIRST STUDENT WITH ID [" << storeIdValue << "] RECORD DELETED SUCCESSFULLY!\n\n";
            saveStudents();

        } else if(choiceValue == "N" || choiceValue == "n"){
            cout << "\n[<] REDIRECTING TO DELETION PAGE...\n\n";
        } else {
            cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n\n";
        }
    }
}

#endif