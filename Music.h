#ifndef DATABASE_MUSIC_PLAYER_MUSIC_H
#define DATABASE_MUSIC_PLAYER_MUSIC_H
#include <string>
#include <iostream>
#include <memory>

using namespace std;
class Music{
protected:
    shared_ptr<string> name = make_shared<string>();
    shared_ptr<string> author = make_shared<string>();
    shared_ptr<int> longing = make_shared<int>();

public:
    virtual ~Music(){
        cout << "Music dectructor was called" << endl;
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
    shared_ptr<string> genre = make_shared<string>();
public:
    virtual ~Music_Pop(){
        cout << "Music_Pop dectructor was called" << endl;
    };
    Music_Pop();
    Music_Pop(string &&new_name, string &&new_author, int &&new_longing, string &&new_genre);
    void Play_Music() override;
    void Print() override;
    void New_genre(string &&new_genre);

    Music_Pop(const Music_Pop &other);
    Music_Pop(Music_Pop &&other) noexcept;
};


#endif //DATABASE_MUSIC_PLAYER_MUSIC_H
