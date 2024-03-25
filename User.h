#ifndef DATABASE_MUSIC_PLAYER_USER_H
#define DATABASE_MUSIC_PLAYER_USER_H
#include <string>
#include <iostream>
#include <memory>
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
    shared_ptr<string> name = make_shared<string>();
    shared_ptr<string> nickname = make_shared<string>();
    shared_ptr<string> email = make_shared<string>();
    shared_ptr<Date> date = make_shared<Date>(0,0,0);
public:
    virtual ~User();
    User();
    User(string &&new_name, string &&new_nickname, string &&new_email, int &&new_day, int &&new_month, int &&new_year);
    void New_name(string &&new_name);
    void New_nickname(string &&new_nickname);
    void New_email(string &&new_email);
    void New_date(int &&new_day, int &&new_month, int &&new_year);
    virtual void Print();
    User(const User &other);
    User(User &&other);
};

class PremiumUser : public User{
protected:
    shared_ptr<Subscription> sub = make_shared<Subscription>();
    shared_ptr<int> rang = make_shared<int>();
public:
    PremiumUser();
    PremiumUser(string &&new_name, string &&new_nickname, string &&new_email, int &&new_day, int &&new_month, int &&new_year,
                string &&new_name_sub, int &&new_price, int &&new_longing, string &&new_features, int &&new_rang);
    void Print() override;
};

#endif //DATABASE_MUSIC_PLAYER_USER_H
