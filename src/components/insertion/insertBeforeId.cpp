#ifndef INSERTBEFORE_H
#define INSERTBEFORE_H
#include "../studentRecord.cpp"
#include "../recordFile/recordFile.cpp"
using namespace std;

void insertBefore(){
    string targetValue;
    cout << "\n>> Enter ID: ";
    cin  >> targetValue;

    if(start == NULL){
        cout << "\n[X] THERE IS NO STUDENT RECORDS!\n\n";
    } else {
        bool isFound = false;
        struct student *current = start;
        struct student *studentFound = NULL;

        while(current != NULL){
            if(current -> id == targetValue){
                isFound = true;
                studentFound = current;
                break;
            }
            current = current -> next;
        }

        if(isFound){
            cout << "\n[i] STUDENT WITH ID \"" << targetValue << "\" IS FOUND!\n\n";

            string firstNameValue, middleNameValue, lastNameValue, idValue, departmentValue;
            int ageValue;
            float gpaValue;

            cout << "\n----- INSERTING BEFORE [" << targetValue << "] -------\n"
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

            struct student *temp = new student;
            struct student *previousStudent = studentFound -> pre;

            temp -> firstName = firstNameValue;
            temp -> middleName = middleNameValue;
            temp -> lastName = lastNameValue;
            temp -> age = ageValue;
            temp -> id = idValue;
            temp -> gpa = gpaValue;
            temp -> department = departmentValue;

            temp -> next = studentFound;
            temp -> pre = previousStudent;

            if(previousStudent != NULL){
                previousStudent -> next = temp;
            } else {
                start = temp;
            }

            studentFound -> pre = temp;

            cout << "\n[i] STUDENT INSERTED BEFORE [" << studentFound -> id << "] SUCCESSFULLY!\n\n";
            saveStudents();
        } else {
            cout << "\n[i] STUDENT WITH ID \"" << targetValue << "\" WAS NOT FOUND!\n\n";
        }
    }
}

#endif