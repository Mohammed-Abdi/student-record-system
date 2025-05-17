#ifndef REGISTER_H
#define REGISTER_H
#include "user.cpp"
#include "saveUserData.cpp"

void Register(){
    string firstNameValue, middleNameValue, lastNameValue, idValue,
           userNameValue, passwordValue, password, confirmPassword,
           adminKey = "DDU", key, checkResponse;
    bool isAdminValue,
         passwordMatch = false,
         userNameTaken = true;
    int ageValue;

    cout << "\n\n----- REGISTERING ------------:\n"
         << "\n[i] ENTER PERSONAL INFO\n>> First Name: ";
    cin >> firstNameValue;
    cout << ">> Middle Name: ";
    cin >> middleNameValue;
    cout << ">> Last Name: ";
    cin >> lastNameValue;
    cout << ">> Age: ";
    cin >> ageValue;
    cout << ">> ID: ";
    cin >> idValue;
    cout << "[i] ENTER CREDENTIALS\n";

    while(userNameTaken){
       cout << ">> Username: ";
       cin >> userNameValue;
       
       userNameTaken = false;
       struct user *check = head;

       while(check != NULL){
        
        if(check -> userName == userNameValue){
            cout << "\n[X] USERNAME TAKEN\n\n";
            userNameTaken = true;
        }

        check = check -> next;
       }

       if(!userNameTaken){
        cout << "\n[i] USERNAME VALID\n\n";
       }
    }

    while(passwordMatch == false){
        cout << ">> Password: ";
        cin >> password;
        cout << ">> Confirm password: ";
        cin >> confirmPassword;
        if(password == confirmPassword){
            passwordMatch = true;
            passwordValue = password;
        } else {
            cout << "\n[X] PASSWORD DONT MATCH\n[>] PLEASE ENTER AGAIN!\n";
        }
    }

    while(true){
        cout << "\n>> ARE YOU ADMIN? [Y/N]: ";
        cin >> checkResponse;
    
        if(checkResponse == "Y" || checkResponse == "y"){
            int attempt = 3;
            while(attempt != 0){
            cout << "\n[?] ADMIN CHECK\n>> Enter the Admin Key: ";
            cin >> key;
    
            string isPlural = "ATTEMPT";
    
            if(attempt > 1){
                isPlural = "ATTEMPTS";
            }
    
            if(key == adminKey){
                isAdminValue = true;
                cout << "\n\n[i] PROMOTED TO ADMIN\n[i] REGISTRATION COMPLETED\n";
                break;
            } else{
                isAdminValue = false;
                if(attempt > 1){
                    cout << "\n\n[INCORRECT] " << attempt - 1 << " " << isPlural  << " LEFT\n\n";
                } else {
                    cout << "\n[!] YOU ARE NOT ADMIN!" 
                         << "\n[i] PROMOTED TO STUDENT BY DEFAULT"
                         << "\n[i] REGISTRATION COMPLETED\n\n";
                }
            }
            attempt--;
            }
            break;
        } else if (checkResponse == "N" || checkResponse == "n"){
            isAdminValue = false;
            cout << "\n[i] PROMOTED TO STUDENT\n[i] REGISTRATION COMPLETED\n\n";
            break;
        } else {
            cout << "\n[X] INPUT INVALID\n\n";
        }
    }

    struct user *temp = new user;
    temp -> firstName = firstNameValue;
    temp -> middleName = middleNameValue;
    temp -> lastName = lastNameValue;
    temp -> age = ageValue;
    temp -> id = idValue;
    temp -> userName = userNameValue;
    temp -> password = passwordValue;
    temp -> isAdmin = isAdminValue;

    if(head == NULL){
        head = temp;
        head -> next = NULL;
        head -> pre = NULL;
    } else {
        temp -> next = head;
        temp -> pre = NULL;
        head -> pre = temp;
        head = temp;
    }
    saveUsers();
}

#endif