#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class User {
private:
    string adminUser = "admin";
    string adminPass = "1234";
    string karyawanUser = "karyawan";
    string karyawanPass = "abcd";
public:
    bool loginAdmin(string u, string p) {
        return (u == adminUser && p == adminPass);
    }
    bool loginKaryawan(string u, string p) {
        return (u == karyawanUser && p == karyawanPass);
    }
};

class Barang {
private:
    struct DataBarang {
        string kode;
        string nama;
        string kategori;
        double harga;
        int stok;
    };

    static const int MAX_BARANG = 1000;
    DataBarang daftar[MAX_BARANG];
    int jumlahBarang = 0; 

public:
    void bacaDariFile() {
        ifstream file("Laporan.txt");
        string line;
        while (getline(file, line) && jumlahBarang < MAX_BARANG) {
            stringstream ss(line);
            getline(ss, daftar[jumlahBarang].kode, ';');
            getline(ss, daftar[jumlahBarang].nama, ';');
            getline(ss, daftar[jumlahBarang].kategori, ';');
            ss >> daftar[jumlahBarang].harga;
            ss.ignore();
            ss >> daftar[jumlahBarang].stok;
            jumlahBarang++;
        }
        file.close();
    }

    void simpanKeFile() {
        ofstream file("Laporan.txt");
        for (int i = 0; i < jumlahBarang; ++i) {
            file << daftar[i].kode << ";" << daftar[i].nama << ";" << daftar[i].kategori << ";" 
                 << daftar[i].harga << ";" << daftar[i].stok << "\n";
        }
        file.close();
    }

    void tambahBarang() {
        if (jumlahBarang >= MAX_BARANG) {
            cout << "Kapasitas penuh. Tidak bisa menambah barang lagi.\n";
            return;
        }

        DataBarang& barang = daftar[jumlahBarang];
        cout << "Masukkan Kode Barang   : ";
        cin >> barang.kode;
        cin.ignore();
        cout << "Masukkan Nama Barang   : ";
        getline(cin, barang.nama);
        cout << "Masukkan Kategori      : ";
        getline(cin, barang.kategori);
        cout << "Masukkan Harga Satuan  : ";
        cin >> barang.harga;
        cout << "Masukkan Jumlah Stok   : ";
        cin >> barang.stok;
        jumlahBarang++;
        simpanKeFile();
        cout << "Barang berhasil ditambahkan dan disimpan ke file!\n";
    }

    void tampilkanSemuaBarang(bool tampilkanStok = false) {
        if (jumlahBarang == 0) {
            cout << "Belum ada barang.\n";
            return;
        }
        cout << "\n=== Daftar Barang ===\n";
        for (int i = 0; i < jumlahBarang; ++i) {
            const auto& b = daftar[i];
            cout << "-----------------------------\n";
            cout << "Kode     : " << b.kode << "\n";
            cout << "Nama     : " << b.nama << "\n";
            cout << "Kategori : " << b.kategori << "\n";
            cout << "Harga    : Rp " << b.harga << "\n";
            if (tampilkanStok)
                cout << "Stok     : " << b.stok << "\n";
        }
        cout << "-----------------------------\n";
    }

    void tampilkanKategori(string kategoriDicari, bool tampilkanStok = false) {
        bool ditemukan = false;
        cout << "\n=== Kategori: " << kategoriDicari << " ===\n";
        for (int i = 0; i < jumlahBarang; ++i) {
            if (daftar[i].kategori == kategoriDicari) {
                ditemukan = true;
                cout << "-----------------------------\n";
                cout << "Kode   : " << daftar[i].kode << "\n";
                cout << "Nama   : " << daftar[i].nama << "\n";
                cout << "Harga  : Rp " << daftar[i].harga << "\n";
                if (tampilkanStok)
                    cout << "Stok   : " << daftar[i].stok << "\n";
            }
        }
        if (!ditemukan) {
            cout << "Tidak ada barang di kategori ini.\n";
        }
        cout << "-----------------------------\n";
    }

    void cariBarang() {
        string keyword;
        cin.ignore();
        cout << "Masukkan nama atau kode barang yang ingin dicari: ";
        getline(cin, keyword);

        bool ditemukan = false;
        cout << "\n=== Hasil Pencarian ===\n";
        for (int i = 0; i < jumlahBarang; ++i) {
            const auto& b = daftar[i];
            if (b.nama.find(keyword) != string::npos || b.kode == keyword) {
                ditemukan = true;
                cout << "-----------------------------\n";
                cout << "Kode     : " << b.kode << "\n";
                cout << "Nama     : " << b.nama << "\n";
                cout << "Kategori : " << b.kategori << "\n";
                cout << "Harga    : Rp " << b.harga << "\n";
                cout << "Stok     : " << b.stok << "\n";
            }
        }
        if (!ditemukan) {
            cout << "Barang tidak ditemukan.\n";
        }
        cout << "-----------------------------\n";
    }

    void editBarang() {
        string kodeEdit;
        cout << "Masukkan kode barang yang ingin diedit: ";
        cin >> kodeEdit;

        for (int i = 0; i < jumlahBarang; ++i) {
            if (daftar[i].kode == kodeEdit) {
                auto& b = daftar[i];
                cout << "\nBarang ditemukan:\n";
                cout << "Nama     : " << b.nama << "\n";
                cout << "Kategori : " << b.kategori << "\n";
                cout << "Harga    : Rp " << b.harga << "\n";
                cout << "Stok     : " << b.stok << "\n";

                cin.ignore();
                cout << "\n--- Masukkan data baru ---\n";
                cout << "Nama baru     : ";
                getline(cin, b.nama);
                cout << "Kategori baru : ";
                getline(cin, b.kategori);
                cout << "Harga baru    : ";
                cin >> b.harga;
                cout << "Stok baru     : ";
                cin >> b.stok;

                simpanKeFile();
                cout << "Barang berhasil diperbarui!\n";
                return;
            }
        }

        cout << "Barang dengan kode tersebut tidak ditemukan.\n";
    }

    void hapusBarang() {
        string kodeHapus;
        cout << "Masukkan kode barang yang ingin dihapus: ";
        cin >> kodeHapus;

        for (int i = 0; i < jumlahBarang; ++i) {
            if (daftar[i].kode == kodeHapus) {
                for (int j = i; j < jumlahBarang - 1; ++j) {
                    daftar[j] = daftar[j + 1]; // Geser data
                }
                jumlahBarang--;
                simpanKeFile();
                cout << "Barang berhasil dihapus!\n";
                return;
            }
        }

        cout << "Barang dengan kode tersebut tidak ditemukan.\n";
    }

    void tampilkanStokRendah(int batas = 5) {
        cout << "\n=== Daftar Barang dengan Stok Rendah (di bawah " << batas << ") ===\n";
        bool ada = false;
        for (int i = 0; i < jumlahBarang; ++i) {
            if (daftar[i].stok < batas) {
                ada = true;
                cout << "-----------------------------\n";
                cout << "Kode     : " << daftar[i].kode << "\n";
                cout << "Nama     : " << daftar[i].nama << "\n";
                cout << "Kategori : " << daftar[i].kategori << "\n";
                cout << "Stok     : " << daftar[i].stok << "\n";
            }
        }
        if (!ada) {
            cout << "Semua stok aman.\n";
        }
        cout << "-----------------------------\n";
    }
};

// Fungsi utama
int main() {
    User user;
    Barang barang;
    barang.bacaDariFile();

    int menuUtama;
    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Login sebagai Admin\n";
        cout << "2. Login sebagai Karyawan\n";
        cout << "3. Lihat Daftar Barang (Pembeli)\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> menuUtama;

        if (menuUtama == 1) {
            string u, p;
            cout << "Username Admin: ";
            cin >> u;
            cout << "Password Admin: ";
            cin >> p;

            if (user.loginAdmin(u, p)) {
            	cout << "Login Admin berhasil!\n";
                int pilihAdmin;
                do {
				    cout << "\n=== MENU ADMIN ===\n";
				    cout << "1. Tambah Barang\n";
				    cout << "2. Lihat Semua Barang\n";
				    cout << "3. Cari Barang\n";
				    cout << "4. Edit Barang\n";
				    cout << "5. Hapus Barang\n"; 
				    cout << "6. Lihat Barang Stok Rendah\n";
				    cout << "0. Logout\n";
				    cout << "Pilih: ";
				    cin >> pilihAdmin;
				
				    if (pilihAdmin == 1)
				        barang.tambahBarang();
				    else if (pilihAdmin == 2)
				        barang.tampilkanSemuaBarang(true);
				    else if (pilihAdmin == 3)
				    	barang.cariBarang();
				    else if (pilihAdmin == 4)
				    	barang.editBarang();
				    else if (pilihAdmin == 5)
				        barang.hapusBarang(); 
				    else if (pilihAdmin == 6)
   						barang.tampilkanStokRendah();
				    else if (pilihAdmin == 0)
				        cout << "Logout admin.\n";
				    else
				        cout << "Pilihan tidak valid.\n";
				} while (pilihAdmin != 0);
            } else {
                cout << "Login Admin gagal.\n";
            }

        } else if (menuUtama == 2) {
            string u, p;
            cout << "Username Karyawan: ";
            cin >> u;
            cout << "Password Karyawan: ";
            cin >> p;

            if (user.loginKaryawan(u, p)) {
                cout << "Login Karyawan berhasil!\n";
                int pilihKaryawan;
                do {
				    cout << "\n=== MENU ADMIN ===\n";
				    cout << "1. Lihat Semua Barang\n";
				    cout << "2. Cari Barang\n";
				    cout << "0. Logout\n";
				    cout << "Pilih: ";
				    cin >> pilihKaryawan;
				
				    if (pilihKaryawan == 1)
				        barang.tampilkanSemuaBarang(true);
				    else if (pilihKaryawan == 2)
				    	barang.cariBarang();
				    else if (pilihKaryawan == 0)
				        cout << "Logout admin.\n";
				    else
				        cout << "Pilihan tidak valid.\n";
				} while (pilihKaryawan != 0);
            } else {
                cout << "Login Karyawan gagal.\n";
            }

        } else if (menuUtama == 3) {
            int pilihKategori;
            do {
                cout << "\n=== Lihat Barang Berdasarkan Kategori ===\n";
                cout << "1. Snack\n";
                cout << "2. Shampo\n";
                cout << "3. Sabun\n";
                cout << "4. Obat-obatan\n";
                cout << "5. Bakery\n";
                cout << "6. Parfum\n";
                cout << "7. Skincare\n";
                cout << "8. Minuman\n";
                cout << "9. Sembako\n";
                cout << "10. Baju\n";
                cout << "11. ATK\n";
                cout << "12. Bumbu dapur\n";
                cout << "13. Buah-buahan\n";
                cout << "14. Frozen food\n";
                cout << "15. Kembali ke Menu Utama\n";
                cout << "Pilih: ";
                cin >> pilihKategori;

                switch (pilihKategori) {
                    case 1:
                        barang.tampilkanKategori("Snack");
                        break;
                    case 2:
                        barang.tampilkanKategori("Shampo");
                        break;
                    case 3:
                        barang.tampilkanKategori("Sabun");
                        break;
                    case 4:
                        barang.tampilkanKategori("Obat-obatan");
                        break;
        			case 5:
                        barang.tampilkanKategori("Bakery");
                        break;
                    case 6:
                        barang.tampilkanKategori("Parfum");
                        break;
                    case 7:
                        barang.tampilkanKategori("Skincare");
                        break;
                    case 8:
                        barang.tampilkanKategori("Minuman");
                        break;
                    case 9:
                        barang.tampilkanKategori("Sembako");
                        break;
                    case 10:
                        barang.tampilkanKategori("Baju");
                        break;
                    case 11:
                        barang.tampilkanKategori("ATK");
                        break;
                    case 12:
                        barang.tampilkanKategori("Bumbu dapur");
                        break;
                    case 13:
                        barang.tampilkanKategori("Buah-buahan");
                        break;
                    case 14:
                        barang.tampilkanKategori("Frozen food");
                        break;
                    case 15:
                        break;
                    default:
                        cout << "Pilihan tidak valid.\n";
                }
            } while (pilihKategori != 5);

        } else if (menuUtama == 4) {
            cout << "Terima kasih. Program selesai.\n";
        } else {
            cout << "Pilihan tidak valid.\n";
        }
    } while (menuUtama != 4);

    return 0;
}

