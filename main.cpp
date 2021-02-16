#include<iostream>
#include<stdlib.h>
#include<fstream>
#include<string>
#include<string.h>

using namespace std;

void registerInput(){

    //Prijungiamas csv failas, kad butu galima skaityti ir rasyti vartotoju informacija

    fstream infoout;
    fstream infoin;
    fstream sizeout;
    fstream sizein;

    infoout.open("info.csv", ios::out | ios::app); //irasyti i csv
    infoin.open("info.csv", ios::in); //skaityti csv
    sizeout.open("size.txt", ios::out | ios::app); //irasyti i size.txt
    sizein.open("size.txt", ios::in); //skaityti size.txt

    // Priskiriami vartotojo vardas ir slaptazodis kintamiesiems ir kiti reikiami dalykai

    string username, password;
    int userssize, place, temp=0;
    sizein >> userssize;
    string arr[userssize];

    //FORMA

    cout << "REGISTER" << endl;
    cout << "--------" << endl;
    cout << "ENTER YOUR USERNAME: ";
    cin >> username;
    cout << "ENTER YOUR PASSWORD: ";
    cin >> password;

    // Tikrina ar jau toks vartotojo vardas yra naudojamas ar ne

    for(int i = 0; i<userssize; i++){
        infoin >> arr[i];
        place = arr[i].find(",");
        arr[i].erase(arr[i].begin()+place, arr[i].end());
        if(username != arr[i]){
            temp++;
        } else {
            system("cls");
            cout << "THE USERNAME IS ALREADY IN USE" << endl;
            registerInput();
        }
    }

    // Jei toks vardas neegzistuoja uzregistruoja

    if(temp == userssize){
        infoout << username << ","
                << password
                << "\n";
        ofstream sizevalue;
        sizevalue.open("size.txt", ios::out | ios::trunc); //Istrinam kas viduje
        sizeout << userssize+1;
        system("cls");
        cout << "REGISTER" << endl;
        cout << "--------" << endl;
        cout << "SUCCESSFULLY REGISTERED";
    }
}

void logingIn(){

    //Prijungiamas csv failas, kad butu galima skaityti ir rasyti vartotoju informacija

    fstream infoin;
    fstream sizein;

    infoin.open("info.csv", ios::in); //skaityti csv
    sizein.open("size.txt", ios::in); //skaityti size.txt

    // Priskiriami vartotojo vardas ir slaptazodis kintamiesiems ir kiti reikiami dalykai

    string username, password;
    int userssize, place, check=0;
    sizein >> userssize;
    string arr[userssize];

    //FORMA

    cout << "LOGIN" << endl;
    cout << "--------" << endl;
    cout << "ENTER YOUR USERNAME: ";
    cin >> username;
    cout << "ENTER YOUR PASSWORD: ";
    cin >> password;

    // Tikrina ar jau toks vartotojo vardas yra naudojamas ar ne

    for(int i = 0; i<userssize; i++){
        infoin >> arr[i];
        place = arr[i].find(",");
        string user = arr[i].substr(0, place);
        string pass = arr[i].substr(place+1);
        //cout << "vardas: " << vardas << " pavardas: " << pavarde << endl;
        if(username == user && password == pass){
            check++;
        }
    }

    if(check == 1){
        system("cls");
        cout << "LOGIN" << endl;
        cout << "--------" << endl;
        cout << "SUCCESSFULLY LOGGED IN";
    }else {
        system("cls");
        cout << "USERNAME OR PASSWORD IS INCORRECT" << endl;
        logingIn();
    }
}

int main(){

    string input;

    cout << "LOGIN OR REGISTER" << endl;
    cout << "-----------------" << endl;
    cout << "REGISTER [1]" << endl;
    cout << "LOGIN [2]" << endl;
    cout << "-----------------" << endl;
    cout << "WHAT DO YOU WANT TO DO? ";
    cin >> input;

    if(input == "1"){
        system("cls");
        registerInput();
    } else if(input == "2"){
        system("cls");
        logingIn();
    }

    return 0;
}
