#ifndef LOGIN_H
#define LOGIN_H
#include "user.cpp"
#include "../main/adminMainMenu.cpp"
#include "../main/studentMainMenu.cpp"

void Login(){
    string userNameValue, passwordValue, storeId;
    bool isAdmin, loginSuccessful = false;
    int userNameAttempt = 3;

    cout << "\n---- LOGIN ---------:";

    while(!loginSuccessful && userNameAttempt != 0){
    cout << "\n>> Username: ";
    cin >> userNameValue;

    bool userFound = false;

    struct user *current = head;

    while(current != NULL){
        if(current -> userName == userNameValue){
            storeId = current -> id;
            isAdmin = current -> isAdmin;
            int passwordAttempt = 3;
            userFound = true;

            while(passwordAttempt != 0){
                cout << ">> Password: ";
                cin >> passwordValue;
    
                if(current -> password == passwordValue){
                    loginSuccessful = true;
                    break;
                } else {

                    passwordAttempt--;
    
                    if(passwordAttempt > 0){
                        cout << "\n[X] INCORRECT PASSWORD -- ATTEMPT LEFT (" << passwordAttempt << ")\n";
                        } else {
                            cout << "\n[X] TOO MANY ATTEMPTS\n[<] REDIRECTING TO LOGIN PAGE...";
                        }
    
                }
            }
            break;
        }

        current = current -> next;
    }

    if(!userFound){
        cout << "\n[X] USERNAME NOT FOUND\n";
        userNameAttempt--;
    }

    if(userNameAttempt == 0){
        cout << "[!] TOO MANY ATTEMPT\n";
    }

    }

    if(loginSuccessful){
        cout << "\n[i] LOGIN SUCCESSFUL!\n\n";
        if(isAdmin){
            adminMainMenu();
        } else {
            studentMainMenu(storeId);
        }
    } else {
        cout << "\n[i] LOGIN FAILED!\n\n";
    }
}

#endif