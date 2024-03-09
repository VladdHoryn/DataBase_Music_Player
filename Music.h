#ifndef DATABASE_MUSIC_PLAYER_MUSIC_H
#define DATABASE_MUSIC_PLAYER_MUSIC_H
#include <string>
#include <iostream>

using namespace std;
class Music {
protected:
    string *name = new string();
    string *autor = new string();
    int *longin = new int();

public:
    virtual ~Music(){cout << "Music dectructor was called" << endl;};
    Music();
    Music(string *new_name, string *new_author, int *new_longing);
    virtual void Play_Music() = 0;
    virtual void New_name(string &&new_name);
    virtual void New_author(string &&new_author);
    virtual void New_longing(int &new_longing);
};

class Music_Pop: public Music{
public:
    virtual ~Music_Pop(){cout << "Music_Pop dectructor was called" << endl;};
    Music_Pop();
    Music_Pop(string *new_name, string *new_author, int *new_longing);
    void Play_Music() override;

};


#endif //DATABASE_MUSIC_PLAYER_MUSIC_H
