#include "User.h"
#include <string>
#include <iostream>
#include "Subscription.h"

User::~User() {
    //cout << "User destructor was called" << endl;
};
User::User()
: name{new string("Unknown")}, nickname{new string("Unknown")}, email{new string("Unknown")}, date{new Date(0, 0, 0)}{}
User::User(std::string &&new_name, std::string &&new_nickname, std::string &&new_email, int &&new_day, int &&new_month,
           int &&new_year)
           : name{new string(new_name)}, nickname{new string(new_nickname)}, email{new string(new_email)}, date{new Date(new_day, new_month, new_year)}{
    //cout << "User constructor was called" << endl;
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

bool User::Compare_nickname(std::string &obj) {
    string s = *nickname;
    if(s == obj)
        return true;
    return false;
}

ostream &operator <<(ostream &os, User &obj)
{
    os << *obj.name << " " << *obj.nickname<< " " << *obj.email << " " << obj.date->day << " " << obj.date->month << " "
       << obj.date->year;
    return os;

}

istream &operator >>(istream &is, User &obj)
{
    is >> *obj.name >> *obj.nickname >> *obj.email >> obj.date->day >> obj.date->month >> obj.date->year;
    return is;
}

istream &operator >(istream &is, User &obj)
{
    cout << "Enter name: ";
    is >> *obj.name;
    cout << "Enter nickname: ";
    is >> *obj.nickname;
    cout << "Enter email: ";
    is >> *obj.email;
    cout << "Enter day: ";
    is >> obj.date->day;
    cout << "Enter mounth: ";
    is >> obj.date->month;
    cout << "Enter year: ";
    is >> obj.date->year;
    return is;
}

User User::operator=(User &obj) {
    if(this != &obj)
    {
        name = obj.name;
        nickname = obj.nickname;
        email = obj.email;
        date->day = obj.date->day;
        date->month = obj.date->month;
        date->year = obj.date->year;
    }
    return *this;
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
   // cout << "Deep copy constryctor User was called" << endl;
}
User::User(User &&other)
        : name{other.name}, nickname{other.nickname}, email{other.email}, date{other.date}{
    other.name = nullptr;
    other.name = nullptr;
    other.email = nullptr;
    other.date = nullptr;
    //cout << "User move constructor was called" << endl;
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
    //cout << "PremiumUser costructor was called" << endl;
}

void PremiumUser::Print() {
    User::Print();
    sub->Print();
    cout << "Rang: " << *rang << endl;
}

bool PremiumUser::Compare_nickname(std::string &obj) {
    string s = *nickname;
    if(s == obj)
        return true;
    return false;
}

istream &operator >>(istream &is, PremiumUser &obj)
{
    is >> *obj.name >> *obj.nickname >> *obj.email >> obj.date->day >> obj.date->month >> obj.date->year
    >> *obj.sub->name >> *obj.sub->price >> *obj.sub->longing >> *obj.sub->features >> *obj.rang;
    return is;
}
ostream &operator <<(ostream &os, PremiumUser &obj)
{
    os << " " << *obj.name << " " << *obj.nickname << " " <<  *obj.email << " " <<  obj.date->day << " "
    <<  obj.date->month << " " <<  obj.date->year << " " <<  *obj.sub->name << " " <<  *obj.sub->price << " "
    <<  *obj.sub->longing << " " <<  *obj.sub->features << " " <<  *obj.rang << endl;
    return os;
}

istream &operator >(istream &is, PremiumUser &obj)
{
    cout << "Enter name: ";
    is >> *obj.name;
    cout << "Enter nickname: ";
    is >> *obj.nickname;
    cout << "Enter email: ";
    is >> *obj.email;
    cout << "Enter day: ";
    is >> obj.date->day;
    cout << "Enter mounth: ";
    is >> obj.date->month;
    cout << "Enter year: ";
    is >> obj.date->year;
    cout << "Enter Subscription name: ";
    is >> *obj.sub->name;
    cout << "Enter Subscription price: ";
    is >> *obj.sub->price;
    cout << "Enter Subscription longing: ";
    is >> *obj.sub->longing;
    cout << "Enter Subscription features: ";
    is >> *obj.sub->features;
    cout << "Enter rang: ";
    is >> *obj.rang;
    return is;
}

PremiumUser PremiumUser::operator=(PremiumUser &obj) {
    if(this != &obj)
    {
        name = obj.name;
        nickname = obj.nickname;
        email = obj.email;
        date->day = obj.date->day;
        date->month = obj.date->month;
        date->year = obj.date->year;
        sub->name = obj.sub->name;
        sub->price = obj.sub->price;
        sub->longing = obj.sub->longing;
        sub->features = obj.sub->features;
        rang = obj.rang;
    }
    return *this;
}
