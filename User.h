#ifndef DATABASE_MUSIC_PLAYER_USER_H
#define DATABASE_MUSIC_PLAYER_USER_H
#include <string>
#include <iostream>
#include "Subscription.h"

using namespace std;

struct Date{
    int day;
    int month;
    int year;

    Date(int d, int m, int y): day(d), month(m), year(y){}
};

class User {
private:
    string *name;
    string *nickname;
    string *email;
    Date *date;
public:
    virtual ~User();
    User();
    User(string &&new_name, string &&new_nickname, string &&new_email, int &&new_day, int &&new_month, int &&new_year);
    void New_name(string &&new_name);
    void New_nickname(string &&new_nickname);
    void New_email(string &&new_email);
    void New_date(int &&new_day, int &&new_month, int &&new_year);
    void Print();
    User(const User &other);
    User(User &&other);



};


#endif //DATABASE_MUSIC_PLAYER_USER_H
