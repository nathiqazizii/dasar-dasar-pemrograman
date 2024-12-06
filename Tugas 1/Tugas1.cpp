#include <iostream>
using namespace std;

int main(){
    int angka_tebak, menu;
    int angka_benar = 8 ;
    string nama, nim;
    cout << "Silahkan Login Terlebih Dahulu"<< endl;
    bool check = false;
    cout << "Masukkan Nama dan Nim"<< endl;

    do {
    cout << "Masukkan Nama:";
    cin >> nama;
    cout << "Masukkan Nim:";
    cin >> nim;

    if (nama == "nathiq" && nim == "141") {
        check = true;
        cout << "Login Berhasil"<< endl;
    } else {
        cout << "Nama atau Nim salah!!"<< endl;
    }    
    } while (check == false);

    cout << "Menu:"<< endl;
    cout << "1. Game Tebak Angka"<< endl;
    cout << "Pilih Menu (Angka):"<< endl;
    cin >> menu;

    switch (menu) {
        case 1:
    cout << "SELAMAT DATANG DI PERMAINAN TEBAK ANGKA"<< endl;
    cout << "TEBAK ANGKA 1-10" << endl;
    do {
    cout << "Angka berapa yang anda tebak :"<< endl;
    cin >> angka_tebak;
        if (angka_tebak > angka_benar){
            cout << "angka terlalu besar"<< endl;
        } else if (angka_tebak < angka_benar){
            cout << "angka terlalu kecil"<< endl;
        } else{
            cout <<"angka tebakan anda benar"<< endl;
            break;
        }  

    } while (angka_tebak != angka_benar);

       break;
    }

}