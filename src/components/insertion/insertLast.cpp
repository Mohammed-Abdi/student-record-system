#ifndef INSERTLAST_H
#define INSERTLAST_H
#include "../studentRecord.cpp"
#include "../recordFile/recordFile.cpp"
using namespace std;

void insertLast(){
    string firstNameValue, middleNameValue, lastNameValue, idValue, departmentValue;
    float gpaValue;
    int ageValue;

    cout << "\n----- INSERTING LAST ------------------------\n"
         << ">> First Name: ";
    cin  >> firstNameValue;
    cout << ">> Middle Name: ";
    cin  >> middleNameValue;
    cout << ">> Last Name: ";
    cin  >> lastNameValue;
    cout << ">> Age: ";
    cin  >> ageValue;
    cout << ">> Student ID: ";
    cin  >> idValue;
    cout << ">> Student GPA: ";
    cin  >> gpaValue;
    cout << ">> Department: ";
    cin.ignore();
    getline(cin, departmentValue);
    cout << "---------------------------------------------\n";

    struct student *temp;
    temp = new student;
    temp -> firstName = firstNameValue;
    temp -> middleName = middleNameValue;
    temp -> lastName = lastNameValue;
    temp -> age = ageValue;
    temp -> id = idValue;
    temp -> gpa = gpaValue;
    temp -> department = departmentValue;

    if(start == NULL){
        start = temp;
        start -> pre = NULL;
        start -> next = NULL;
    } else {
        struct student *pointer = start;

        while(pointer -> next != NULL){
            pointer = pointer -> next;
        }

        pointer -> next = temp;
        temp -> pre = pointer;
        temp -> next = NULL;
    }

    cout << "\n[i] STUDENT INSERTED AT LAST SUCCESSFULLY!\n\n";
    saveStudents();
}

void insertMoreLast(){
    string choice;
    do{
        cout << ">> DO YOU WANT TO ADD MORE? [Y/N]: ";
        cin >> choice;

        if(choice == "Y" || choice == "y"){
            insertLast();
        } else if(choice == "N" || choice == "n"){
            cout << "\n[<] REDIRECTING TO INSERT PAGE...\n\n";
            break;
        } else {
            cout << "\n[X] THERE IS NO OPTION \"" << choice << "\"\n\n";
        }
    } while(choice != "N" && choice != "n");
}

#endif