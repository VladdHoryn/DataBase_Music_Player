#ifndef DATABASE_MUSIC_PLAYER_ADMIN_H
#define DATABASE_MUSIC_PLAYER_ADMIN_H
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Admin {
protected:
    shared_ptr <string> nickname = make_shared<string>();
    shared_ptr <string> password = make_shared<string>();
public:
    ~Admin(){};
    Admin();
    Admin(string &&new_nickname, string && new_password);

    bool check_password(string &guess_password);
    bool Compare_nickname(string &obj);
    bool Compare_password(string &obj);

    friend istream &operator>>(istream &is, Admin &obj);
    friend ostream &operator<<(ostream &os, Admin &obj);
    friend istream &operator>(istream &is, Admin &obj);
    Admin operator=(Admin &obj);

    Admin(const Admin &other);
    Admin(Admin &&other) noexcept;

};


#endif //DATABASE_MUSIC_PLAYER_ADMIN_H
