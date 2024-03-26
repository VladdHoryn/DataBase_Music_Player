#include "Music.h"
#include <string>

using namespace std;

Music::Music() :
    name{new std::string("Unknown")}, author{new std::string("Unknown")}, longing{new int(0)} {};
Music::Music(std::string &&new_name, std::string &&new_author, int &&new_longing) :
    name{new string(new_name)}, author{new string(new_author)}, longing{new int(new_longing)} {};
void Music::New_name(std::string &&new_name) {
    *name = new_name;
}
void Music::New_author(std::string &&new_author) {
    *author = new_author;
}

void Music::New_longing(int &&new_longing) {
    *longing = new_longing;
}

Music::Music(const Music &other) {
    name = make_shared<string>(*other.name);
    *name = *other.name;
    author = make_shared<string>(*(other.author));
    *author = *other.author;
    longing = make_shared<int>(*other.longing);
    *longing = *other.longing;
    cout << "Deep copy constryctor Music was called" << endl;
}

Music::Music(Music &&other) noexcept : name{other.name}, author{other.author}, longing{other.longing}{
    other.name = nullptr;
    other.author = nullptr;
    other.longing = nullptr;
    cout << "Music move constructor was called" << endl;
}
//---------------------------------------------------------------------------------------------------------------------

Music_Pop::Music_Pop()
: Music(), genre{new string("Unknown")} {cout << "Music_Pop constructor was called" << endl;}
Music_Pop::Music_Pop(std::string &&new_name, std::string &&new_author, int &&new_longing, string &&new_genre)
: Music(forward<string>(new_name), forward<string>(new_author), forward<int>(new_longing)), genre{new string(new_genre)} {cout << "Music_Pop constructor was called" << endl;}

void Music_Pop::Play_Music() {
    cout << "Easy, calm pop music is played" << endl;
}
void Music_Pop::Print() {
    cout << "Name: " << *name << endl
    << "Author: " << *author << endl
    << "Longing: " << *longing << endl
    << "Genre: " << *genre << endl;
}

void Music_Pop::New_genre(std::string &&new_genre) {
    *genre = new_genre;
}

ostream &operator <<(ostream &os, Music_Pop &obj)
{
    os << obj.name << endl
    << obj.author << endl
    << obj.longing << endl
    << obj.genre << endl;
    return os;

}

istream &operator >>(istream &is, Music_Pop &obj)
{
    is >> *obj.author >> *obj.longing >> *obj.genre;
    return is;
}

/*void Music_Pop::Read() {
    try
    {
        ifstream file("C:/Users/Vlad/Documents/C++/Laba_OOP/Database_Music_Player/Music_pop.txt");
        if(!file)
            throw FileWasNotOpened();
        file >> *name;
        file >> *author;
        file >> *longing;
        file >> *genre;

        file.close();
    }
    catch(FileWasNotOpened &ex)
    {
        cout << "File was not opened" << endl;
    }
}*/

/*void Music_Pop::Write() {
    try {
        ofstream file("C:/Users/Vlad/Documents/C++/Laba_OOP/Database_Music_Player/Music_pop.txt");
        if(!file)
            throw FileWasNotOpened();
        file << *name << endl;
        file << *author << endl;
        file << *longing << endl;
        file << *genre << endl;

    }
    catch(FileWasNotOpened &ex){
        cout << "File was not opened" << endl;
    }
}*/

Music_Pop::Music_Pop(const Music_Pop &other) : Music(other){
    genre = make_shared<string>(*other.genre);
    *genre = *other.genre;
    /*name = new string;
    *name = *other.name;
    autor = new string;
    *autor = *other.autor;
    longing = new int;
    *longing = *other.longing;*/
    cout << "Deep copy constryctor Music_Pop was called" << endl;
}
Music_Pop::Music_Pop(Music_Pop &&other) noexcept
: Music(other), genre{other.genre}{
    other.genre = nullptr;
    cout << "Music_Pop move constructor was called" << endl;

}
