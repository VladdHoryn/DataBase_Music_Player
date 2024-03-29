#include "Admin.h"

Admin::Admin()
: nickname{new string("Unknown")}, password{new string("12345")} {}
Admin::Admin(std::string &&new_nickname, std::string &&new_password)
: nickname{new string(new_nickname)}, password{new string(new_password)} {
    cout << "constructor was called" << endl;
}

bool Admin::check_password(string &guess_password) {
    if(*password == guess_password)
        return true;
    else
        return false;
}

bool Admin::Compare_nickname(std::string &obj) {
    string s = *nickname;
    if(s == obj)
        return true;
    return false;
}

bool Admin::Compare_password(std::string &obj) {
    string s = *password;
    if(s == obj)
        return true;
    return false;
}

istream &operator>>(istream &is, Admin &obj)
{
    is >> *obj.nickname >> *obj.password;
    return is;
}
ostream &operator<<(ostream &os, Admin &obj)
{
    os << *obj.nickname << " " << *obj.password;
    return  os;
}
istream &operator>(istream &is, Admin &obj)
{
    cout << "Enter nickname: ";
    is >> *obj.nickname;
    cout << "Enter password: ";
    is >> *obj.password;
    return is;
}

Admin Admin::operator=(Admin &obj) {
    if(this != &obj)
    {
        nickname = obj.nickname;
        password = obj.password;
    }
    return *this;
}

Admin::Admin(const Admin &other) {
    nickname = make_shared<string>(*other.nickname);
    *nickname = *other.nickname;
    password = make_shared<string>(*other.password);
    *password = *other.password;
}
Admin::Admin(Admin &&other) noexcept
: nickname{other.nickname}, password{other.password}{}

