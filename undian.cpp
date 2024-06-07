#include <iostream>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <iomanip>
using namespace std;

struct spec
{
    string tipe;
    string nama;
    string cpu;
    int core;
    int ram;
    int rom;
    float baterai;
    float bobot;
} hadiah[6];

void output (spec a){
    cout<<a.nama<<endl;
    cout<<"Tipe : "<<a.tipe<<endl;
    cout<<"CPU : "<<a.cpu<<endl;
    cout<<"Core : "<<a.core<<endl;
    cout<<"RAM: "<<a.ram<<" GB"<<endl;
    cout<<"ROM: "<<a.rom<<" GB"<<endl;
    if (a.tipe == "Handphone") {
        cout<<"Battery: "<<a.baterai<<" mAh"<<endl;
        cout<<"Berat: "<<a.bobot<<" gr"<<endl;

    }
    else if(a.tipe == "Laptop") {
        cout<<"Battery: "<<a.baterai<<" Wh Li-ion"<<endl;
        cout<<"Berat: "<<a.bobot<<" kg"<<endl;
    }
}
int acak(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void judul() {
    cout << "===================================" << endl;
    cout << " SELAMAT DATANG DI PROGRAM UNDIAN    " << endl;
    cout << "===================================" << endl;
}
void daftar(){
    //Ke - 1
    hadiah[0].nama = "Asus ROG Phone 6 Pro";
    hadiah[0].tipe = "Handphone";
    hadiah[0].cpu = "Snapdragon 8+ Gen 1";
    hadiah[0].core = 8;
    hadiah[0].ram = 18;
    hadiah[0].rom = 512;
    hadiah[0].baterai = 6000;
    hadiah[0].bobot = 239;
    //Ke - 2
    hadiah[1].nama = "OPPO Reno6 5G";
    hadiah[1].tipe = "Handphone";
    hadiah[1].cpu = "Mediatek Dimensity 900";
    hadiah[1].core = 8;
    hadiah[1].ram = 8;
    hadiah[1].rom = 128;
    hadiah[1].baterai = 4300;
    hadiah[1].bobot = 182;
    //Ke - 3
    hadiah[2].nama = "Huawei P50 Pro";
    hadiah[2].tipe = "Handphone";
    hadiah[2].cpu = "Snapdragon 888 4G";
    hadiah[2].core = 8;
    hadiah[2].ram = 8;
    hadiah[2].rom = 256;
    hadiah[2].baterai = 4360;
    hadiah[2].bobot = 195;
    //Ke - 4
    hadiah[3].nama = "Apple MacBook Air M2";
    hadiah[3].tipe = "Laptop";
    hadiah[3].cpu = "Apple M2 Chip";
    hadiah[3].core = 8;
    hadiah[3].ram = 8;
    hadiah[3].rom = 256;
    hadiah[3].baterai = 52.6;
    hadiah[3].bobot = 1.24;
    //Ke - 5
    hadiah[4].nama = "Lenovo Yoga 9i";
    hadiah[4].tipe = "Laptop";
    hadiah[4].cpu = "Intel Core i7-1195G7";
    hadiah[4].core = 4;
    hadiah[4].ram = 16;
    hadiah[4].rom = 1024;
    hadiah[4].baterai = 60;
    hadiah[4].bobot = 1.44;
    //Ke - 6
    hadiah[5].nama = "Advan Workplus";
    hadiah[5].tipe = "Laptop";
    hadiah[5].cpu = "AMD Ryzen 5 6600H";
    hadiah[5].core = 6;
    hadiah[5].ram = 16;
    hadiah[5].rom = 512;
    hadiah[5].baterai = 58;
    hadiah[5].bobot = 1.3;
}
void tampilkanRoda(const vector<int>& angka, int h) {
    for (int i = 0; i < angka.size(); ++i) {
        if (i == h) {
            cout << "[" << setw(2) << angka[i] << "] ";
        } else {
            cout << " " << setw(2) << angka[i] << "  ";
        }
    }
    cout << endl;
}

int putarRoda(const vector<int>& angka) {
    int h = acak(0, angka.size() - 1);
    for (int i = 0; i < 30; ++i) {
        h = (h + 1) % angka.size();
        tampilkanRoda(angka, h);
        usleep(100000); // Delay for animation
    }
    return angka[h];
}
void tampilkanPemenang(int nomorPemenang, int count) {
    cout << "===================================" << endl;
    cout << "        SELAMAT KAMU MENANG!        " << endl;
    cout << "===================================" << endl;
    cout << "Nomor Pemenang: " << nomorPemenang << endl;
    cout << "Kamu mendapatkan: " << endl;
    output(hadiah[count]);
    cout << "===================================" << endl;
}

main() {
    system("cls");
    srand(static_cast<unsigned int>(time(0)));
    
    int jumlahPeserta, nomorPilihan;
    int count = -1;

    char pilihanBalik, pilihan;
    daftar();
    kembali : 
    judul();

    cout << endl;

    cout << "1. Daftar Hadiah" << endl;
    cout << "2. Mulai Putar Roda" << endl;
    cout << "Masukkan pilihan Anda : "; 
    cin >> pilihan;

    if (pilihan == '1'){   
        system("cls");
        for (int i = 0; i < 6; i++){
            cout << "HADIAH KE - " << i+1 << endl << endl;
            output(hadiah[i]);
            cout << endl;
        }
        system("pause");
        system("cls");

        goto kembali;
    }
    else if (pilihan == '2'){
        system("cls");
        cout << "Masukkan jumlah peserta: ";
        cin >> jumlahPeserta;
        vector<int> angka;
        for (int i = 1; i <= jumlahPeserta; ++i) {
            angka.push_back(i);
        }
        balik :
        count += 1;
        cout << "HADIAH KE - " << count + 1 << endl << endl;
        cout << "Pilih angka dari 1 hingga " << jumlahPeserta << ": ";
        cin >> nomorPilihan;

        int nomorPemenang = putarRoda(angka);
        if (nomorPilihan == nomorPemenang) tampilkanPemenang(nomorPemenang, count);
        else cout << "Maaf, Anda kurang beruntung." << endl;
        cout<< "(Alamat nomor Pemenang di memori : " << &nomorPemenang <<")" << endl << endl;
    
        cout << "Apakah Anda ingin mengulang? (y/n) "; 
        cin >> pilihanBalik; 
        if(pilihanBalik == 'Y' || pilihanBalik == 'y') {
            if (count > 4) {
                cout << "Maaf, hadiah undian sudah habis" << endl;
            }
            else {
                system("cls");
                goto balik;
            }
        }
        return 0;
    }
    else {
        cout << "Pilihan Anda tidak valid. Silahkan pilih kembali." << endl;
        system("pause");
        system("cls");
        goto kembali;
    }
}
