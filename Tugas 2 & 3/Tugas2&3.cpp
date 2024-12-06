#include <iostream>
using namespace std;

struct Matkul_mhs
{
    string nama_matkul;
    int id_matkul;
    float nilai_matkul;
};

void inputData(Matkul_mhs *&Matkul, int &jumlahmatkul)
{
    cout << "Masukkan Jumlah Matkul: ";
    cin >> jumlahmatkul;
    cin.ignore();
    Matkul = new Matkul_mhs[jumlahmatkul];

    for (int i = 0; i < jumlahmatkul; i++)
    {
        cout << endl;
        cout << "Data Matkul ke-" << (i + 1) << ":" << endl;
        cout << "Masukkan Nama Matkul: ";
        getline(cin, Matkul[i].nama_matkul);
        cout << "Masukkan Id Matkul: ";
        cin >> Matkul[i].id_matkul;
        cin.ignore();
        cout << "Masukkan Nilai Matkul: ";
        cin >> Matkul[i].nilai_matkul;
        cin.ignore();
    }
}

void tampilData(Matkul_mhs *Matkul, int jumlahMatkul)
{
    cout << "\nData Matkul:" << endl;
    for (int i = 0; i < jumlahMatkul; i++)
    {
        cout << "\nData Matkul ke-" << (i + 1) << ":" << endl;
        cout << "Nama Matkul: " << Matkul[i].nama_matkul << endl;
        cout << "Id Matkul: " << Matkul[i].id_matkul << endl;
        cout << "Nilai Matkul: " << Matkul[i].nilai_matkul << endl;
    }
}

void hitungRatanilaimatkul(Matkul_mhs *Matkul, int jumlahMatkul)
{
    if (jumlahMatkul > 0)
    {
        float totalnilaimatkul = 0;
        for (int i = 0; i < jumlahMatkul; i++)
        {
            totalnilaimatkul += Matkul[i].nilai_matkul;
        }

        float ratanilaimatkul = totalnilaimatkul / jumlahMatkul;
        cout << "\nRata-rata nilai matkul: " << ratanilaimatkul << endl;
    }
    else
    {
        cout << "Belum ada data matkul untuk dihitung." << endl;
    }
}

int main()
{
    int pilih;
    int jumlahMatkul = 20;
    Matkul_mhs *Matkul;

    do
    {
        cout << "\n===SELAMAT DATANG===" << endl;
        cout << "Silahkan Pilih Menu:" << endl;
        cout << "1. Input Data Matkul" << endl;
        cout << "2. Tampilkan Data Matkul" << endl;
        cout << "3. Hitung Rata-rata Nilai Matkul" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih)
        {
        case 1:
            inputData(Matkul, jumlahMatkul);
            break;
        case 2:
            if (jumlahMatkul > 0)
            {
                tampilData(Matkul, jumlahMatkul);
            }
            else
            {
                cout << "Belum ada data matkul yang diinput." << endl;
            }
            break;
        case 3:
            hitungRatanilaimatkul(Matkul, jumlahMatkul);
            break;
        case 4:
            cout << "Terima Kasih" << endl;
            break;
        default:
            cout << "Pilihan tidak valid, silahkan coba lagi." << endl;
            break;
        }
    } while (pilih != 4);
}
