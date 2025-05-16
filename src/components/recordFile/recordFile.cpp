#ifndef RECORDFILE_H
#define RECORDFILE_H
#include <iostream>
#include <string>
#include <fstream>
#include "../studentRecord.cpp"
using namespace std;

void saveStudents(){
    ofstream saver(studentRecord);
    struct student *current = start;

    while(current != NULL){
        saver << current -> firstName << "\n"
              << current -> middleName << "\n"
              << current -> lastName << "\n"
              << current -> id << "\n"
              << current -> age << "\n"
              << current -> gpa << "\n"
              << current -> department << "\n";

        current = current -> next;
    }

    saver.close();
}


void loadStudents(){
    ifstream loader(studentRecord);

    if(loader.is_open()){
        string firstNameValue, middleNameValue, lastNameValue, idValue, departmentValue;
        int ageValue;
        float gpaValue;

        while(getline(loader, firstNameValue)){
            getline(loader, middleNameValue);
            getline(loader, lastNameValue);
            getline(loader, idValue);
            loader >> ageValue;
            loader >> gpaValue;
            loader.ignore();
            getline(loader, departmentValue);

            struct student *temp;
            temp = new student;
            temp -> firstName = firstNameValue;
            temp -> middleName = middleNameValue;
            temp -> lastName = lastNameValue;
            temp -> id = idValue;
            temp -> age = ageValue;
            temp -> gpa = gpaValue;
            temp -> department = departmentValue;

            if(start == NULL){
                start = temp;
                temp -> pre = NULL;
                temp -> next = NULL;
            } else {
                temp -> next = start;
                temp -> pre = NULL;
                start -> pre = temp;
                start = temp;
            }
        }

        loader.close();
    } else {
        return;
    }
}

#endif