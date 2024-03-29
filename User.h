#ifndef DATABASE_MUSIC_PLAYER_USER_H
#define DATABASE_MUSIC_PLAYER_USER_H
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "Subscription.h"

using namespace std;

struct Date{
    int day;
    int month;
    int year;

    Date(int d, int m, int y): day(d), month(m), year(y){}
};

class User {
protected:
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
    bool Compare_nickname(string &obj);
    virtual void Print();
    User(const User &other);
    User(User &&other);
    friend ostream &operator <<(ostream &os, User &obj);
    friend istream &operator >>(istream &is, User &obj);
    friend istream &operator >(istream &is, User &obj);
    User operator =(User &obj);
};

class PremiumUser : public User{
protected:
    shared_ptr<Subscription> sub = make_shared<Subscription>();
    shared_ptr<int> rang = make_shared<int>();
public:
    virtual ~PremiumUser(){};
    PremiumUser();
    PremiumUser(string &&new_name, string &&new_nickname, string &&new_email, int &&new_day, int &&new_month, int &&new_year,
                string &&new_name_sub, int &&new_price, int &&new_longing, string &&new_features, int &&new_rang);
    void Print() override;
    bool Compare_nickname(string &obj);
    friend istream &operator >>(istream &is, PremiumUser &obj);
    friend ostream &operator <<(ostream &os, PremiumUser &obj);
    friend istream &operator >(istream &is, PremiumUser &obj);
    PremiumUser operator =(PremiumUser &obj);
};

#endif //DATABASE_MUSIC_PLAYER_USER_H
