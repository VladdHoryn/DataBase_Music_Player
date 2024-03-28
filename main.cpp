#include <iostream>
#include "Music.h"
#include "Subscription.h"
#include "User.h"
#include "Music.cpp"
#include "Subscription.cpp"
#include "User.cpp"
#include <vector>
#include <fstream>
#include <memory>

template <typename T>
vector<T> Read(string &name_of_file) {
    ifstream file(name_of_file);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
    }

    T obj;
    vector<T> array;
    while (file >> obj)
        array.push_back(T(obj));

    file.close();
    return array;
}

template <typename T>
void Write(vector<T> array, string name_of_file) {
    for(auto& i : array)
        i.Print();
}

template <typename T>
void Write_in_File(vector <T> array, string &name_of_file){
    ofstream file(name_of_file);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
    }
    for(auto& i : array)
    {
        file << i << endl;
    }
    file.close();
}

int main() {
    string name_of_file_music = "Music_Pop.txt";
    string name_of_file_user = "User.txt";
    string name_of_file_PremiumUser = "PremiumUser.txt";
    string name_of_file_subscription = "Subscription.txt";
    vector<User> array_user;
    vector<Music_Pop> array_music;
    vector<PremiumUser> array_PremiumUser;
    vector<Subscription> array_Subscription;

    /*array_user = Read<User>(name_of_file_user);
    array_music = Read<Music_Pop>(name_of_file_music);
    Write(array_music, name_of_file_music);
    Write(array_user, name_of_file_user);
    Write_in_File(array_user, name_of_file_user);
    Write_in_File(array_music, name_of_file_music);*/
    array_PremiumUser = Read<PremiumUser>(name_of_file_PremiumUser);
    Write(array_PremiumUser, name_of_file_PremiumUser);
    Write_in_File(array_PremiumUser, name_of_file_PremiumUser);
    return 0;
}
