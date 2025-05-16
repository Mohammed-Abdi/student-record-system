#include "components/authentication/register.cpp"
#include "components/authentication/login.cpp"
#include "components/authentication/loadUserData.cpp"
#include "components/recordFile/recordFile.cpp"


int main(){
    string choice;
    loadUsers();
    loadStudents();

    cout << "\nWELCOME TO STUDENT RECORD SYSTEM";

    do{
        cout << "\n1. LOGIN\n2. REGISTER\n3. EXIT\nchoose[1-3]: ";
        cin >> choice;
        if(choice == "1"){
            Login();
        } else if(choice == "2"){
            Register();
        } else if(choice == "3"){
            cout << "[i] PROGRAM ENDED";
        } else {
            cout << "[X] THERE IS NO \"" << choice << "\" OPTION";
        }
    } while(choice != "3");

    return 0;
}
