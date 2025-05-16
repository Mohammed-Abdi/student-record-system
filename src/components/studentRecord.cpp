#ifndef STUDENT_RECORD_H
#define STUDENT_RECORD_H
#include <iostream>
#include <fstream>
using namespace std;

struct student {
    string firstName, middleName, lastName, id, department;
    int age;
    float gpa;
    struct student *pre;
    struct student *next;
};

struct student *start = NULL;

const string studentRecord = "studentRecord.txt";

#endif