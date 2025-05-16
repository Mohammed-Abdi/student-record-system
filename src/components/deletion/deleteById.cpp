#ifndef DELETEBYID_H
#define DELETEBYID_H
#include "deleteFirst.cpp"
#include "deleteLast.cpp"
#include "../studentRecord.cpp"
#include "../recordFile/recordFile.cpp"

void deleteById(){
    if(start == NULL){
        cout << "\n[X] THERE IS NO STUDENT RECORDS TO DELETE!\n\n"; 
    } else {
        bool isFound = false;
        string targetIdValue;
        cout << "\n>> ENTER ID: ";
        cin  >> targetIdValue;

        struct student *current;
        current = start;

        while(current != NULL){
            if(current -> id == targetIdValue){
                isFound = true;

                if(start -> next == NULL){
                    string choiceValue;
                    cout << "[!] ARE YOU SURE YOU WANT TO DELETE \"" << current -> firstName << "\"? [Y/N]: ";
                    cin >> choiceValue;

                    if(choiceValue == "Y" || choiceValue == "y"){
                        delete current;
                        start = NULL;
                        saveStudents();
                        cout << "\n[i] STUDENT WITH ID [" << targetIdValue << "] DELETED SUCCESSFULLY!\n\n";
                        break;
                    } else if(choiceValue == "N" || choiceValue == "n"){
                        cout << "\n[<] REDIRECTING TO DELETION PAGE...\n\n";
                    } else {
                        cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n\n";
                    }

                } else if(current -> pre == NULL){
                    cout << "\n[i] STUDENT WITH ID [" << targetIdValue << "] IS THE FIRST STUDENT...!\n";
                    deleteFirst();
                    break;

                } else if(current -> next == NULL){
                    cout << "\n[i] STUDENT WITH ID [" << targetIdValue << "] IS THE LAST STUDENT...!\n";
                    deleteLast();
                    break;

                } else {
                    string choiceValue;
                    cout << "[!] ARE YOU SURE YOU WANT TO DELETE \"" << current -> firstName << "\"? [Y/N]: ";
                    cin >> choiceValue;

                    if(choiceValue == "Y" || choiceValue == "y"){
                        current -> pre -> next = current -> next;
                        current -> next -> pre = current -> pre;
                        delete current;
                        saveStudents();
                        cout << "\n[i] STUDENT WITH ID [" << targetIdValue << "] DELETED SUCCESSFULLY!\n\n";
                        break;
                    } else if(choiceValue == "N" || choiceValue == "n"){
                        cout << "\n[<] REDIRECTING TO DELETION PAGE...\n\n";
                    } else {
                        cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n\n";
                    }
                }
            }

            current = current -> next;
        }

        if(!isFound){
            cout << "\n[X] THERE IS NO STUDENT WITH ID [" << targetIdValue << "]!\n\n";
        }
    }
}

#endif