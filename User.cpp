#include "User.h"
#include <string>
#include <iostream>
#include "Subscription.h"

User::~User() {
    cout << "User destructor was called" << endl;
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
    name = make_shared<string>(*other.name);
    *name = *other.name;
    nickname = make_shared<string>(*other.nickname);
    *nickname = *other.nickname;
    email = make_shared<string>(*other.email);
    *email = *other.email;
    date = make_shared<Date>(*other.date);
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
//--------------------------------------------------------------------------------------------------------------------
PremiumUser::PremiumUser()
: User(), sub(new Subscription()), rang{new int(0)}{}
PremiumUser::PremiumUser(std::string &&new_name, std::string &&new_nickname, std::string &&new_email, int &&new_day,
                         int &&new_month, int &&new_year, std::string &&new_name_sub, int &&new_price,
                         int &&new_longing, std::string &&new_features, int &&new_rang)
                         : User(forward<string>(new_name), forward<string>(new_nickname), forward<string>(new_email),
                                forward<int>(new_day), forward<int>(new_month), forward<int>(new_year)),
                                sub(new Subscription(forward<string>(new_name_sub), forward<int>(new_price), forward<int>(new_longing),
                                                     forward<string>(new_features))), rang{new int (new_rang)} {                       // не працює конструктор до sub!!!!!!
    cout << "PremiumUser costructor was called" << endl;
}

void PremiumUser::Print() {
    User::Print();
    sub->Print();
    cout << "Rang: " << *rang << endl;
}