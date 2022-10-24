//Accounts class detail
#include <iostream>
using namespace std;
#include <fstream>
#include <random>

class Accounts{
private:
    char first_Name[40];
    char last_Name[40];
    int std_id;
    int std_age;
    int std_major;
    int user_input;
public:
    //gathering info of student
    void getStd(void);
    //display info o student
    void display_std(void);
    void Title(void);
    void Menu(void);
    void new_Account();
    void sign_in_Account(void);
    void lost_password(void);
};
void Accounts::getStd(void) {
    cout<<"Enter the student information"<<endl;
    cout<<"Accounts name: ";cin>>first_Name;
    cout<<"Accounts ID: ";cin>>std_id;
    cout<<"Accounts Age: ";cin>>std_age;
    cout<<"Accounts Major: ";cin>>std_major;
}
void Accounts::display_std(void) {
    cout<<"The Accounts information"<<endl;
    cout<<"Name: "<<first_Name<<endl;
    cout<<"ID: "<<std_id<<endl;
    cout<<"Age: "<<std_age<<endl;
    cout<<"Major: "<<std_major;
}
void Accounts::Title(void){
    cout<<"|_____Registration Title_____|"<<endl;
}
void Accounts::Menu(void){
    cout<<"1) Make New Account"<<endl;
    cout<<"2) Sign in Account"<<endl;
    cout<<"3) Forgot Account Info"<<endl;

    cout<<"\nPress one of the number: ";
    cin>>user_input;
    if(user_input==1){
        new_Account();
    }
    else if(user_input==2){
        sign_in_Account();
    }
    else if(user_input==3){
        lost_password();
    }
    else
        cout<<"Sorry error, please press one of the number on the screen."<<endl;
    return Menu();
}
void Accounts::new_Account() {
    fstream account_info;
    cout<<"\nFirst Name: ";cin>>first_Name;
    cout<<"\nLast Name: ";cin>>last_Name;
    cout<<"\nWhat your age: ";cin>>std_age;

    ofstream userName("A_username.txt");
    if(userName.is_open()){
        userName<<first_Name<<" "<<last_Name<<" "<<std_age;
        userName.close();
    }
}

void Accounts::sign_in_Account() {

}
void Accounts::lost_password() {

}



int main() {
    Accounts info;
    info.Title();
    info.Menu();
    //.getStd();
    //info.display_std();
    return 0;
}
