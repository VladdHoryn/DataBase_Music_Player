#include <iostream>
#include "Music.h"
#include "Subscription.h"
#include "User.h"
#include "Music.cpp"
#include "Subscription.cpp"
#include "User.cpp"
#include "Admin.h"
#include "Admin.cpp"
#include <vector>
#include <fstream>
#include <memory>

bool test_enter = false, test_user = false, test_premiumuser = false, test_admin = false;

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
void Write(vector<T> array) {
    int number  = 1;
    for(auto& i : array)
    {
        cout << number << ")" << endl;
        i.Print();
        number++;
    }
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

template <typename T>
vector <T> Add_element(vector <T> &array)
{
    T obj;
    cin > obj;
    array.push_back(obj);
    return array;
}

template <typename T>
T Find(vector <T> &array, string &nick)
{
    for(auto &i : array)
        if(i.Compare_nickname(nick)) {
            test_enter = true;
            return i;
        }
}

template <typename T>
void Password(T &obj, string &password)
{
    test_enter = false;
    if(obj.Compare_password(password)) {
        test_enter = true;
    }
}

/*
template <typename T>
vector<T> Delete_element(vector <T> &array, int number)
{
    number--;
    int step = 0;
    T obj;
    bool test = false;
    for(auto &i : array)
    {
        if(step == number)
            test = true;
        if(test)
        {
            i = obj;
        }
        obj = i;
        ++step;
    }
    return array;
}
*/

template <typename T>
vector <T> Charnge_element(vector<T> array, int num)
{
    T obj;
    cin > obj;
    int step = 1;
    for(auto &i : array)
    {
        if(step == num) {
            i = obj;
            return array;
        }
        ++step;
    }
}

template <typename T>
T Play(vector <T> &array, int &number)
{
    int step = 1;
    for(auto &i : array)
        if(number == step)
            i.Play_Music();
    cout << "Uncorrect number" << endl;
}


/*enum MENU
{
            EXIT, READ, ADD, WRITE, SHOW, PLAY, EDIT, DELETE, USER, ADMIN
};*/

template <typename T>
T userr;

int main() {
    shared_ptr<User> user;
    shared_ptr<PremiumUser> premiumuser;
    shared_ptr<Admin> admin;
    //Admin ad;

    Admin admin1("Vlad", "54321");
    string name_of_file_music = "Music_Pop.txt";
    string name_of_file_user = "User.txt";
    string name_of_file_PremiumUser = "PremiumUser.txt";
    string name_of_file_subscription = "Subscription.txt";
    string name_of_file_admin = "Admin.txt";
    vector<User> array_user;
    vector<Music_Pop> array_music;
    vector<PremiumUser> array_PremiumUser;
    vector<Subscription> array_Subscription;
    vector<Admin> array_admin;
    array_user = Read<User>(name_of_file_user);
    array_music = Read<Music_Pop>(name_of_file_music);
    array_PremiumUser = Read<PremiumUser>(name_of_file_PremiumUser);
    array_Subscription = Read<Subscription>(name_of_file_subscription);
    array_admin = Read<Admin>(name_of_file_admin);

    int k;
    int n;

    while(!test_enter)
    {
        cout << "Enter accoun you want to use" << endl;
        cout << "0 - USER\n1 - ADMIN" << endl;
        cin >> k;
        switch (k) {
            case 0:{
                cout << "Enter nickname of your accoun: ";
                string nick;
                cin >> nick;
                user = make_shared<User>(Find<User>(array_user, nick));
                if(test_enter)
                    test_user = true;
                premiumuser = make_shared<PremiumUser>(Find<PremiumUser>(array_PremiumUser, nick));
                if(test_enter)
                    test_premiumuser = true;
                break;
            }
            case 1:{
                cout << "Enter nickname of your admin accoun: ";
                string nick;
                cin >> nick;
                cout << "Enter nickname of your admin password: ";
                string password;
                cin >> password;
                admin = make_shared<Admin>(Find<Admin>(array_admin, nick));
                if(test_enter)
                {
                    Password(*admin, password);
                    if(test_enter)
                        test_admin = true;
                }
                break;
            }
            advance:{
                cout << "Enter correct number" << endl;
            };

        }
    }
    cout << "You have enter in account" << endl;

    if(test_admin)
        while(true)
        {
            cout << "Enter sutable number: " << endl;
            cout << "0 - EXIT\n1 - WRITE\n2 - WRITE ALL\n3 - PLAY\n4 - ADD\n5 - DELETE\n6 - CHANGE\n";
            cin >> k;
            switch (k) {
                case 0:{
                    return 0;
                    break;
                }
                case 1:{
                    cout << "Enter list of objects you want to see" << endl;
                    cout << "0 - MUSIC\n1 - USERS\n2 - PREMIUMUSERS\n3 - SUBSCRIPTIONS\n";
                    cin >> n;
                    switch (n) {
                        case 0:{
                            Write(array_music);
                            break;
                        }
                        case 1:{
                            Write(array_user);
                            break;
                        }
                        case 2:{
                            Write(array_PremiumUser);
                            break;
                        }
                        case 3:{
                            Write(array_Subscription);
                            break;
                        }
                    }
                    break;
                }
                case 2:{
                    Write(array_music);
                    cout << "----------------------------------------" << endl;
                    Write(array_user);
                    cout << "----------------------------------------" << endl;
                    Write(array_PremiumUser);
                    cout << "----------------------------------------" << endl;
                    Write(array_Subscription);
                    break;
                }
                case 3:{
                    Write(array_music);
                    cout << "Choose number of music you want to play: ";
                    int music_number;
                    cin >> music_number;
                    Play(array_music, music_number);
                    break;
                }
                case 4:{
                    cout << "Enter list of objects to which you want to add element" << endl;
                    cout << "0 - MUSIC\n1 - USER\n2 - PREMIUMUSER\n3 - SUBSCRIPTION\n4- ADMIN\n";
                    cin >> n;
                    switch (n) {
                        case 0:{
                            Add_element(array_music);
                            break;
                        }
                        case 1:{
                            Add_element(array_user);
                            break;
                        }
                        case 2:{
                            Add_element(array_PremiumUser);
                            break;
                        }
                        case 3:{
                            Add_element(array_Subscription);
                            break;
                        }
                        case 4:{
                            Add_element(array_admin);
                            break;
                        }
                    }
                    break;
                }
                case 5:{
                    cout << "Enter list of objects to which you want to delete" << endl;
                    cout << "0 - MUSIC\n1 - USER\n2 - PREMIUMUSER\n3 - SUBSCRIPTION\n4- ADMIN\n";
                    cin >> n;
                    switch (n) {
                        case 0:{
                            //Delete_element(array_music);
                            break;
                        }
                        case 1:{
                            //Delete_element(array_user);
                            break;
                        }
                        case 2:{
                            //Delete_element(array_PremiumUser);
                            break;
                        }
                        case 3:{
                            //Delete_element(array_Subscription);
                            break;
                        }
                        case 4:{
                            //Delete_element(array_admin);
                            break;
                        }
                    }
                    break;
                }
                case 6:{
                    cout << "Enter list of objects in which you want change element" << endl;
                    cout << "0 - MUSIC\n1 - USER\n2 - PREMIUMUSER\n3 - SUBSCRIPTION\n";
                    cin >> n;
                    switch (n) {
                        case 0:{
                            Write(array_music);
                            cout << "Enter number of ellement you want to change : ";
                            int number;
                            cin >> number;
                            Charnge_element(array_music, number);
                            break;
                        }
                        case 1:{
                            Write(array_user);
                            cout << "Enter number of ellement you want to change : ";
                            int number;
                            cin >> number;
                            Charnge_element(array_user, number);
                            break;
                        }
                        case 2:{
                            Write(array_PremiumUser);
                            cout << "Enter number of ellement you want to change : ";
                            int number;
                            cin >> number;
                            Charnge_element(array_PremiumUser, number);
                            break;
                        }
                        case 3:{
                            Write(array_Subscription);
                            cout << "Enter number of ellement you want to change : ";
                            int number;
                            cin >> number;
                            Charnge_element(array_Subscription, number);
                            break;
                        }
                    }
                    break;
                }

            }
        }
    else
        while(true)
        {
            cout << "Enter sutable number: " << endl;
            cout << "0 - EXIT\n1 - WRITE\n2 - WRITE ALL\n3 - PLAY\n4 - CHOW STATUS";
            cin >> k;
            switch (k) {
                case 0:{
                    return 0;
                    break;
                }
                case 1:{
                    cout << "Enter list of objects you want to see" << endl;
                    cout << "0 - MUSIC\n1 - USERS\n2 - PREMIUMUSERS\n3 - SUBSCRIPTIONS\n";
                    cin >> n;
                    switch (n) {
                        case 0:{
                            Write(array_music);
                            break;
                        }
                        case 1:{
                            Write(array_user);
                            break;
                        }
                        case 2:{
                            Write(array_PremiumUser);
                            break;
                        }
                        case 3:{
                            Write(array_Subscription);
                            break;
                        }
                    }
                    break;
                }
                case 2:{
                    Write(array_music);
                    cout << "----------------------------------------" << endl;
                    Write(array_user);
                    cout << "----------------------------------------" << endl;
                    Write(array_PremiumUser);
                    cout << "----------------------------------------" << endl;
                    Write(array_Subscription);
                    break;
                }
                case 3:{
                    Write(array_music);
                    cout << "Choose number of music you want to play: ";
                    int music_number;
                    cin >> music_number;
                    Play(array_music, music_number);
                    break;
                }
                case 4:{
                    if(test_user)
                        user->Print();
                    else if(test_premiumuser)
                        premiumuser->Print();
                    break;
                }
            }
        }

    Write_in_File(array_user, name_of_file_user);
    Write_in_File(array_music, name_of_file_music);
    Write_in_File(array_PremiumUser, name_of_file_PremiumUser);
    Write_in_File(array_Subscription, name_of_file_subscription);
    Write_in_File(array_admin, name_of_file_admin);

    return 0;
}
