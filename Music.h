#ifndef DATABASE_MUSIC_PLAYER_MUSIC_H
#define DATABASE_MUSIC_PLAYER_MUSIC_H
#include <string>
#include <iostream>

using namespace std;
class Music {
protected:
    string *name = new string();
    string *autor = new string();
    int *longing = new int();

public:
    virtual ~Music(){
        cout << "Music dectructor was called" << endl;
        delete name;
        delete autor;
        delete longing;
    };
    Music();
    Music(string &&new_name, string &&new_author, int &&new_longing);
    virtual void Play_Music() = 0;
    void New_name(string &&new_name);
    void New_author(string &&new_author);
    void New_longing(int &&new_longing);
    virtual void Print() = 0;
    Music(const Music &other);
    Music(Music &&other) noexcept;
};

class Music_Pop: public Music{
protected:
    string *genre;
public:
    virtual ~Music_Pop(){
        cout << "Music_Pop dectructor was called" << endl;
        delete genre;
    };
    Music_Pop();
    Music_Pop(string &&new_name, string &&new_author, int &&new_longing);
    void Play_Music() override;
    void Print() override;

    Music_Pop(const Music_Pop &other);
    Music_Pop(Music_Pop &&other) noexcept;
};


#endif //DATABASE_MUSIC_PLAYER_MUSIC_H
