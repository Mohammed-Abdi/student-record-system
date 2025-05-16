#ifndef DELETELAST_H
#define DELETELAST_H
#include "../studentRecord.cpp"
#include "../recordFile/recordFile.cpp"

void deleteLast(){
    if(start == NULL){
        cout << "\n[X] THERE IS NO STUDENT RECORDS TO DELETE!\n\n";
    } else {
        struct student *pointer1;
        struct student *pointer2;
        string storeIdValue;

        pointer1 = start;

        if(start -> next == NULL){
            string choiceValue;
            cout << "[!] ARE YOU SURE YOU WANT TO DELETE \"" << pointer1 -> firstName << "\"? [Y/N]: ";
            cin >> choiceValue;

            if(choiceValue == "Y" || choiceValue == "y"){
                storeIdValue = pointer1 -> id;
                delete pointer1;
                start = NULL;
                saveStudents(); // ✅ update file
                cout << "\n[i] LAST STUDENT WITH ID [" << storeIdValue << "] RECORD DELETED SUCCESSFULLY!\n\n";
            } else if(choiceValue == "N" || choiceValue == "n"){
                cout << "\n[<] REDIRECTING TO DELETION PAGE...\n\n";
            } else {
                cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n\n";
            }
        } else {
            while(pointer1 -> next != NULL){
                pointer2 = pointer1;
                pointer1 = pointer1 -> next;
            }

            string choiceValue;
            cout << "[!] ARE YOU SURE YOU WANT TO DELETE \"" << pointer1 -> firstName << "\"? [Y/N]: ";
            cin >> choiceValue;

            if(choiceValue == "Y" || choiceValue == "y"){
                storeIdValue = pointer1 -> id;
                pointer2 -> next = NULL;
                delete pointer1;
                saveStudents();
                cout << "\n[i] LAST STUDENT WITH ID [" << storeIdValue << "] RECORD DELETED SUCCESSFULLY!\n\n";
            } else if(choiceValue == "N" || choiceValue == "n"){
                cout << "\n[i] REDIRECTING TO DELETION PAGE...\n\n";
            } else {
                cout << "\n[X] THERE IS NO OPTION \"" << choiceValue << "\"\n\n";
            }
        }
    }
}

#endif