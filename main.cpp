//Accounts class detail
#include <iostream>
using namespace std;
#include <fstream>
#include <random>

class Accounts{
private:
    char first_name[50];
    char last_name[50];
    int std_id;
    int std_age;
    char std_major[50];
    int user_input;
public:
    //gathering info of student
    void getStd(void);
    //display info o student
    void display_std(void);
    void Title(void);
    void Menu(void);
    void new_Account(); //user create new account
    void sign_in_Account(void); //
    void lost_password(void); //recover user info
    void input_number(void); //input only integer and not char
};
void Accounts::getStd(void) {
    cout<<"Enter the student information"<<endl;
    cout<<"Accounts name: ";cin >> first_name;
    cout<<"Accounts Age: ";cin>>std_age;
    cout<<"Accounts ID: ";cin>>std_id;
    cout<<"Accounts Major: ";cin>>std_major;
}
void Accounts::display_std(void) {
    cout<<"The Accounts information"<<endl;
    cout << "Name: " << first_name << endl;
    cout<<"Age: "<<std_age<<endl;
    cout<<"ID: "<<std_id<<endl;
    cout<<"Major: "<<std_major<<endl;
}
void Accounts::Title(){
    cout<<"|_____Registration Title_____|"<<endl;
}
void Accounts::Menu(){
    cout<<"|_____Main Page_____|"<<endl;
    cout<<"1) Make New Account"<<endl;
    cout<<"2) Sign in Account"<<endl;
    cout<<"3) Recover Account Info"<<endl;

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
    return Menu(); //return to main page if user input wrong
}
void Accounts::new_Account() {
    cout<<"Registration Account Page"<<"\nPlease enter fill in your information"<<endl;
    fstream account_info;
    //User Enter information
    cout<<"\nFirst Name: ";cin >> first_name;
    cout<<"\nLast Name: ";cin>>last_name;
    input_number();
    cout<<"\nStudent ID: ";cin>>std_id;
    cout<<"\nWhat is your major: "<<endl;cin>>std_major;
    //Save user info into text file
    ofstream userName("A_username.txt",ios::app);//ios::app allow to add input to txt
    if(userName.is_open()){
        userName << "Name:" << first_name << " " << last_name << " " << "|Age: " << std_age << " " << "|Student ID: "
        << std_id << " "<< "|Major: " << std_major << endl;
        userName.close();
    }
    display_std();
    return sign_in_Account();
}
void Accounts::input_number() {
    //user force to enter number and no char
    while((cout<<"\nEnter your age: ") && (!(cin>>std_age)|| std_age < 1 || std_age > 110)){
    cout<<"Invalid input, Try entering a number";
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
}

void Accounts::sign_in_Account() {
    int loginID = 0;
    int loginAttempt = 0;
    char loginLastName[50];

    cout << "\nSign-In Page" << endl;

    cout << "\nPlease Enter Student Last Name: ";
    cin >> loginLastName;

    // Asks for students ID to sign in
    cout << "\nPlease Enter Student ID: ";
    cin >> loginID;
    if (loginID == std_id){
        cout << "\nWelcome back " << first_name << " " << last_name << " !" << endl;
        display_std();
    }
    else {
        cout << "\nEntered ID does not match any ID in the database, please try again" << endl;
        loginAttempt ++;
    }

    // If the user enters a wrong student ID too many times, sends them to Menu
    if (loginAttempt >= 5){
        cout << "\nIf ID was forgotten please go to lost password page" << endl;
        Menu();
    }
}
void Accounts::lost_password() {
    int answer = 0;
    int new_stdID;
    cout << "\nWelcome to the Lost Password Page";
    cout << "Would you like to renew Student ID: ";
    cout << "\n 1. Yes";
    cout << "\n 2. No";
    cin >> answer;
    if (answer == 1){
        cout << "You have chosen to renew Student ID" << endl;
        cout << "Please Enter Student Last and First Name" << endl;
        cout << "\n First Name: ";
        cin >> first_name;
        cout << "\n Last Name: ";
        cin >> last_name;
        if (first_name && last_name == first_name && last_name){
            cout << "Enter new Student ID: ";
            std_id = new_stdID;
        }
        else
            cout << "Entered student name not in database" << endl;
    }
    else
        cout << "You have chosen to not renew password" << endl;
}
int main() {
    Accounts info;
    info.Title();
    info.Menu();
    //.getStd();
    //info.display_std();
    return 0;
}
