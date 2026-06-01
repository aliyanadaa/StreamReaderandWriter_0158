#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <vector>

using namespace std;

// Class Toko Elektronik
class TokoElektronik
{
private:
    array<string, 3> etalase;

public:
    // Constructor
    TokoElektronik()
    {
        etalase[0] = "Laptop ASUS";
        etalase[1] = "TV Samsung";
        etalase[2] = "Kulkas LG";
    }

    // Method mengambil produk
    string ambilProduk(size_t nomorRak)
    {
        try
        {
            return etalase.at(nomorRak);
        }
        catch (out_of_range &e)
        {
            throw runtime_error(
                "Gagal Mengambil Barang : Rak nomor "
                + to_string(nomorRak)
                + " kosong atau tidak tersedia!");
        }
    }
};

// CREATE
void tambahBarang()
{
    ofstream outfile;
    outfile.open("gudang.txt", ios::app);

    string barang;

    cin.ignore();

    cout << "Masukkan nama barang : ";
    getline(cin, barang);

    outfile << barang << endl;

    outfile.close();

    cout << "Data berhasil ditambahkan.\n";
}

// READ
void tampilBarang()
{
    ifstream infile;
    infile.open("gudang.txt");

    string data;

    cout << "\nData Barang di Gudang\n";

    while (getline(infile, data))
    {
        cout << data << endl;
    }

    infile.close();
}

// UPDATE
void updateBarang()
{
    ifstream infile;
    infile.open("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(infile, barang))
    {
        data.push_back(barang);
    }

    infile.close();

    int pilih;

    cout << "\nData Barang\n";

    for (int i = 0; i < data.size(); i++)
    {
        cout << i + 1 << ". " << data[i] << endl;
    }

    cout << "Pilih nomor yang ingin diubah : ";
    cin >> pilih;

    cin.ignore();

    cout << "Masukkan nama barang baru : ";
    getline(cin, data[pilih - 1]);

    ofstream outfile;
    outfile.open("gudang.txt");

    for (int i = 0; i < data.size(); i++)
    {
        outfile << data[i] << endl;
    }

    outfile.close();

    cout << "Data berhasil diubah.\n";
}

// DELETE
void hapusBarang()
{
    ifstream infile;
    infile.open("gudang.txt");

    vector<string> data;
    string barang;

    while (getline(infile, barang))
    {
        data.push_back(barang);
    }

    infile.close();

    int pilih;

    cout << "\nData Barang\n";

    for (int i = 0; i < data.size(); i++)
    {
        cout << i + 1 << ". " << data[i] << endl;
    }

    cout << "Pilih nomor yang ingin dihapus : ";
    cin >> pilih;

    data.erase(data.begin() + (pilih - 1));

    ofstream outfile;
    outfile.open("gudang.txt");

    for (int i = 0; i < data.size(); i++)
    {
        outfile << data[i] << endl;
    }

    outfile.close();

    cout << "Data berhasil dihapus.\n";
}

// Simulasi Exception
void cekEtalase()
{
    TokoElektronik toko;

    try
    {
        cout << "\nSkenario 1\n";
        cout << toko.ambilProduk(1) << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }

    try
    {
        cout << "\nSkenario 2\n";
        cout << toko.ambilProduk(5) << endl;
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
}

int main()
{
    int pilihan;

    do
    {
        cout << "\n===== TOKO ELEKTRONIK GIBRAN JAYA =====\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Lihat Barang\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Cek Etalase\n";
        cout << "0. Keluar\n";
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tambahBarang();
            break;

        case 2:
            tampilBarang();
            break;

        case 3:
            updateBarang();
            break;

        case 4:
            hapusBarang();
            break;

        case 5:
            cekEtalase();
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak tersedia.\n";
        }

    } while (pilihan != 0);

    return 0;
}