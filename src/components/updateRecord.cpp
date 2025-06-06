#ifndef UPDATE_H
#define UPDATE_H
#include "studentrecord.cpp"
#include "recordFile/recordFile.cpp"
void updateMenu(){
    string choice;
        if(start == NULL){
            cout << "\n[X] THERE IS NO STUDENT RECORDS TO SEARCH!\n\n";
        } else {
            bool isFound = false;
            string target;
            cout << "\n>> ENTER ID: ";
            cin  >> target;

            struct student *current;
            current = start;

            while(current != NULL){
                if(current -> id == target){
                    isFound = true;

                    string newFirstNameValue, newMiddleNameValue, newLastNameValue, newIdValue, newDepartmentValue;
                    int newAgeValue;
                    float newGpaValue;

                    do{
                        cout << "\n------------------------------------\n"
                             << "-> NAME : " << current -> firstName << " " << current -> middleName << " "<< current -> lastName << "\n"
                             << "-> AGE  : " << current -> age << "\n"
                             << "-> ID   : " << current -> id << "\n"
                             << "-> GPA   : " << current -> gpa << "\n"
                             << "-> DEP  : " << current -> department << "\n"
                             << "------------------------------------\n"
                             << "1. UPDATE NAME\n"
                             << "2. UPDATE AGE\n"
                             << "3. UPDATE ID\n"
                             << "4. UPDATE GPA\n"
                             << "5. UPDATE DEPARTMENT\n"
                             << "6. BACK\n\n>> CHOOSE [1-6]: ";
                        cin >> choice;
                        cout << "------------------------------------\n\n";

                        if(choice == "1"){
                            cout << ">> UPDATE FIRST NAME: ";
                            cin >> newFirstNameValue;
                            current -> firstName = newFirstNameValue;
                            
                            cout << ">> UPDATE MIDDLE NAME: ";
                            cin >> newMiddleNameValue;
                            current -> middleName = newMiddleNameValue;

                            cout << ">> UPDATE LAST NAME: ";
                            cin >> newLastNameValue;
                            current -> lastName = newLastNameValue;

                            saveStudents();

                        } else if(choice == "2"){
                            cout << ">> UPDATE AGE: ";
                            cin >> newAgeValue;
                            current -> age = newAgeValue;

                            saveStudents();

                        } else if(choice == "3"){
                            cout << ">> UPDATE ID: ";
                            cin >> newIdValue;
                            current -> id = newIdValue;

                            saveStudents();

                        } else if(choice == "4"){
                            cout << ">> UPDATE GPA: ";
                            cin >> newGpaValue;
                            current -> gpa = newGpaValue;

                            saveStudents();

                        } else if(choice == "5"){
                            cout << ">> UPDATE DEPARTMENT: ";
                            cin.ignore();
                            getline(cin, newDepartmentValue);
                            current -> department = newDepartmentValue;

                            saveStudents();

                        } else if(choice == "6"){
                            cout << "\n[i] STUDENT INFO UPDATED SUCCESSFULLY!"
                                 << "\n[<] REDIRECTING TO HOMEPAGE...\n\n";
                        } else {
                            cout << "\n[X] THERE IS NO OPTION \"" << choice << "\"\n";
                        }
                    } while(choice != "6");

                    break; 
                }
                current = current -> next;
            }

            if(!isFound){
                cout << "\n[X] THERE IS NO STUDENT WITH ID [" << target << "]!\n\n";
            }
        }
}

#endif