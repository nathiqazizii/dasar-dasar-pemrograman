#include <iostream>
using namespace std;

struct Penulis
{
    string nama;
};

struct Buku
{
    int id;
    string judul;
    Penulis penulis;
    int harga;
};

void tambahBuku(Buku bukuList[], int &jumlahBuku)
{
    int jumlahinput;
    cout << "Masukkan jumlah buku yang ingin ditambahkan: ";
    cin >> jumlahinput;
    for (int i = 0; i < jumlahinput; i++)
    {
        cout << endl;
        cout << "Masukkan data buku\n";
        cout << "ID Buku: ";
        cin >> bukuList[jumlahBuku].id;
        cout << "Judul Buku: ";
        cin.ignore();
        getline(cin, bukuList[jumlahBuku].judul);
        cout << "Nama Penulis: ";
        getline(cin, bukuList[jumlahBuku].penulis.nama);
        cout << "Harga: ";
        cin >> bukuList[jumlahBuku].harga;
        jumlahBuku++;
    }
}

void tampilkanDaftarBuku(Buku bukuList[], int jumlahBuku)
{
    cout << "\nDaftar Buku:\n";
    for (int i = 0; i < jumlahBuku; ++i)
    {
        cout << "ID: " << bukuList[i].id << endl;
        cout << "Judul: " << bukuList[i].judul << endl;
        cout << "Penulis: " << bukuList[i].penulis.nama << endl;
        cout << "Harga: " << bukuList[i].harga << endl;
        cout << endl;
    }
}

void ubahbuku(Buku bukuList[], int jumlahBuku)
{
    int idBuku;
    cout << "Masukkan ID Buku yang ingin diubah: ";
    cin >> idBuku;
    for (int i = 0; i < jumlahBuku; ++i)
    {
        if (bukuList[i].id == idBuku)
        {
            cout << endl;
            cout << "Masukkan data buku yang baru :\n";
            cout << "ID Buku: ";
            cin >> bukuList[i].id;
            cout << "Judul Buku: ";
            cin.ignore();
            getline(cin, bukuList[i].judul);
            cout << "Nama Penulis: ";
            getline(cin, bukuList[i].penulis.nama);
            cout << "Harga: ";
            cin >> bukuList[i].harga;
            break;
        }
    }
}

void hapusBuku(Buku bukuList[], int &jumlahBuku)
{
    int idBuku;
    cout << "Masukkan ID Buku yang ingin dihapus: ";
    cin >> idBuku;
    for (int i = 0; i < jumlahBuku; ++i)
    {
        if (bukuList[i].id == idBuku)
        {
            for (int j = i; j < jumlahBuku - 1; ++j)
            {
                bukuList[j] = bukuList[j + 1];
            }
            jumlahBuku--;
            cout << "Buku berhasil dihapus.\n";
            break;
        }
        else
        {
            cout << endl;
            cout << "Buku dengan ID tersebut tidak ditemukan.\n";
        }
    }
    cout << endl;
    cout << "Buku tidak ditemukan.\n";
}

void hitungTotalHarga(Buku bukuList[], int jumlahBuku)
{
    int totalHarga, totalHarga1, totalHarga3 = 0;
    int idBuku, jumlahBeli = 0;
    bool diskonPenulis = false;
    string kodeVoucher;
    string adaVoucher;

    cout << "\nMasukkan jumlah buku yang ingin dibeli: ";
    cin >> jumlahBeli;

    int pilihanBuku[jumlahBeli];
    string penulisPertama;

    for (int i = 0; i < jumlahBeli; ++i)
    {
        cout << "Masukkan ID Buku ke-" << i + 1 << ": ";
        cin >> idBuku;
        for (int j = 0; j < jumlahBuku; ++j)
        {
            if (bukuList[j].id == idBuku)
            {
                totalHarga += bukuList[j].harga;
                if (i == 0)
                {
                    penulisPertama = bukuList[j].penulis.nama;
                }
                else if (bukuList[j].penulis.nama == penulisPertama)
                {
                    diskonPenulis = true;
                }
                break;
            }
        }
    }
    if (diskonPenulis)
    {
        totalHarga *= 0.95;
        cout << endl;
        cout << "Diskon 5% untuk buku dari penulis yang sama diterapkan.\n";
        cout << "Total Harga setelah diskon: " << totalHarga << endl;
    }
    cout << endl;
    cout << "Masukkan Voucher lain (ada/tidak) : ";
    cin >> adaVoucher;
    if (adaVoucher == "ada")
    {
        cout << endl;
        cout << "Masukkan kode voucher : ";
        cin >> kodeVoucher;
        if (kodeVoucher == "JPYUM")
        {
            totalHarga *= 0.90;
            cout << endl;
            cout << "Diskon 10% dengan kode voucher 'JPYUM' diterapkan.\n";
        }
        else
        {
            cout << endl;
            cout << "Kode voucher tidak valid.\n";
        }
    }
    else
    {
        cout << "Tidak ada diskon voucher yang diterapkan.\n";
    }
    cout << "Harga setelah diskon: " << totalHarga << endl;
}

int main()
{
    Buku bukuList[100];
    int jumlahBuku = 0;
    int pilihan;

    do
    {
        cout << "\nSelamat Datang di Menu Buku:\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Daftar Buku\n";
        cout << "3. Ubah Data Buku\n";
        cout << "4. Hapus Buku\n";
        cout << "5. Hitung Total Harga Pembelian\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBuku(bukuList, jumlahBuku);
            break;
        case 2:
            tampilkanDaftarBuku(bukuList, jumlahBuku);
            break;
        case 3:
            ubahbuku(bukuList, jumlahBuku);
            break;
        case 4:
            hapusBuku(bukuList, jumlahBuku);
            break;
        case 5:
            hitungTotalHarga(bukuList, jumlahBuku);
            break;
        case 6:
            cout << "Terima kasih anda telah menggunakan Program ini.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }
    } while (pilihan != 6);

    return 0;
}
