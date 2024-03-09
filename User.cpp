#include "User.h"
#include <string>
#include <iostream>
#include "Subscription.h"

User::~User() {
    cout << "User destructor was called" << endl;
    delete date;
    /*delete name;
    delete nickname;
    delete email;*/
};
User::User()
: name{new string("Unknown")}, nickname{new string("Unknown")}, email{new string("Unknown")}, date{new Date(0, 0, 0)}{}
User::User(std::string &&new_name, std::string &&new_nickname, std::string &&new_email, int &&new_day, int &&new_month,
           int &&new_year)
           : name{new string(new_name)}, nickname{new string(new_nickname)}, email{new string(new_email)}, date{new Date(new_day, new_month, new_year)}{
    cout << "User constructor was called" << endl;
}

void User::New_name(std::string &&new_name) {
    *name = new_name;
}
void User::New_nickname(std::string &&new_nickname) {
    *nickname = new_nickname;
}
void User::New_email(std::string &&new_email) {
    *email = new_email;
}
void User::New_date(int &&new_day, int &&new_month, int &&new_year) {
    *date = Date(new_day, new_month, new_year);
}

void User::Print() {
    cout << "Name: " << *name << endl
    << "Nickname: " << *nickname << endl
    << "Email: " << *email << endl;
    cout << "Date of register: ";
    if(date->day < 10)
        cout << "0" << date->day << ".";
    else
        cout << date->day << ".";
    if(date->month < 10)
        cout << "0" << date->month << ".";
    else
        cout << " " << date->month << ".";
    cout << date->year << endl;
}

User::User(const User &other) {
    name = new string();
    *name = *other.name;
    nickname = new string();
    *nickname = *other.nickname;
    email = new string();
    *email = *other.email;
    date = new Date(0, 0, 0);
    *date = *other.date;
    cout << "Deep copy constryctor User was called" << endl;
}
User::User(User &&other)
        : name{other.name}, nickname{other.nickname}, email{other.email}, date{other.date}{
    other.name = nullptr;
    other.name = nullptr;
    other.email = nullptr;
    other.date = nullptr;
    cout << "User move constructor was called" << endl;
}

