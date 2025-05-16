#ifndef DELETEALL_H
#define DELETEALL_H
#include "../studentRecord.cpp"
#include "../recordFile/recordFile.cpp"

void deleteAll(){
    if(start == NULL){
        cout << "\n[X] THERE IS NO STUDENT RECORDS TO DELETE!\n\n";       
    } else {
        string choiceValue;
        cout << "[!] ARE YOU SURE YOU WANT TO DELETE ALL STUDENT RECORDS? [Y/N]: ";
        cin >> choiceValue;

        if(choiceValue == "Y" || choiceValue == "y"){
            struct student *current, *nextStudent;
            current = start;

            while(current != NULL){
                nextStudent = current -> next;
                delete current;
                current = nextStudent;
            }

            start = NULL;
            saveStudents();

            cout << "\n[i] ALL STUDENT RECORDS DELETED SUCCESSFULLY!\n\n";

        } else if(choiceValue == "N" || choiceValue == "n"){
            cout << "\n[<] REDIRECTING TO DELETION PAGE...\n\n";
        } else {
            cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n\n";
        }
    }
}

#endif