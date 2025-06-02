#include <iostream>
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

    static const int MAX_BARANG = 180;
    DataBarang daftar[MAX_BARANG];
    int jumlahBarang = 0; 

public:
    void initBarang() {
        //Snack
        daftar[0] = {"B001", "Chitato", "Snack", 7000, 100};
        daftar[1] = {"B002", "Taro", "Snack", 6000, 90};
        daftar[2] = {"B003", "Qtela", "Snack", 6500, 80};
        daftar[3] = {"B004", "Lay's", "Snack", 7500, 70};
        daftar[4] = {"B005", "Tic Tac", "Snack", 4000, 60};
        daftar[5] = {"B006", "Oreo", "Snack", 5000, 85};
        daftar[6] = {"B007", "SilverQueen", "Snack", 12000, 40};
        daftar[7] = {"B008", "Cheetos", "Snack", 6800, 55};
        daftar[8] = {"B009", "Nextar", "Snack", 3500, 95};
        daftar[9] = {"B010", "Good Time", "Snack", 7000, 75};

        // Shampo
        daftar[10] = {"B011", "Sunsilk", "Shampo", 15000, 50};
        daftar[11] = {"B012", "Pantene", "Shampo", 16000, 45};
        daftar[12] = {"B013", "Clear", "Shampo", 17000, 40};
        daftar[13] = {"B014", "Head & Shoulders", "Shampo", 18000, 35};
        daftar[14] = {"B015", "Lifebuoy", "Shampo", 14000, 60};
        daftar[15] = {"B016", "Tresemme", "Shampo", 20000, 30};
        daftar[16] = {"B017", "Rejoice", "Shampo", 13000, 55};
        daftar[17] = {"B018", "Herbal Essences", "Shampo", 22000, 25};
        daftar[18] = {"B019", "Zinc", "Shampo", 12000, 70};
        daftar[19] = {"B020", "Wardah", "Shampo", 19000, 33};

        //sabun
        daftar[20] = {"B021", "Lifebuoy Bar", "Sabun", 3000, 80};
		daftar[21] = {"B022", "Lux", "Sabun", 3500, 90};
		daftar[22] = {"B023", "Dettol", "Sabun", 4000, 70};
		daftar[23] = {"B024", "Palmolive", "Sabun", 4500, 60};
		daftar[24] = {"B025", "Biore", "Sabun", 5000, 65};
		daftar[25] = {"B026", "Giv", "Sabun", 2500, 100};
		daftar[26] = {"B027", "Nuvo", "Sabun", 3700, 75};
		daftar[27] = {"B028", "Imperial Leather", "Sabun", 4800, 55};
		daftar[28] = {"B029", "Shinzui", "Sabun", 5200, 50};
		daftar[29] = {"B030", "Leivy", "Sabun", 6000, 45};
		
		// Obat-obatan
		daftar[30] = {"B031", "Paracetamol", "Obat-obatan", 2000, 100};
		daftar[31] = {"B032", "OBH Combi", "Obat-obatan", 12000, 60};
		daftar[32] = {"B033", "Antangin", "Obat-obatan", 1500, 90};
		daftar[33] = {"B034", "Tolak Angin", "Obat-obatan", 3000, 70};
		daftar[34] = {"B035", "Bodrex", "Obat-obatan", 2500, 80};
		daftar[35] = {"B036", "Promag", "Obat-obatan", 2000, 85};
		daftar[36] = {"B037", "Panadol", "Obat-obatan", 3500, 75};
		daftar[37] = {"B038", "Decolgen", "Obat-obatan", 2700, 65};
		daftar[38] = {"B039", "Neozep", "Obat-obatan", 2900, 60};
		daftar[39] = {"B040", "Konidin", "Obat-obatan", 2400, 95};
		
		// Bakery
		daftar[40] = {"B042", "Roti Tawar", "Bakery", 7000, 80};
		daftar[41] = {"B043", "Croissant", "Bakery", 8000, 75};
		daftar[42] = {"B044", "Roti Pisang", "Bakery", 5000, 85};
		daftar[43] = {"B045", "Kue Lapis", "Bakery", 4500, 60};
		daftar[44] = {"B046", "Bolu Gulung", "Bakery", 7500, 50};
		daftar[45] = {"B047", "Roti Sisir", "Bakery", 6000, 70};
		daftar[46] = {"B048", "Kue Cubit", "Bakery", 4000, 65};
		daftar[47] = {"B049", "Roti Sosis", "Bakery", 8500, 40};
		daftar[48] = {"B050", "Roti Coklat", "Bakery", 8000, 55};
		
		// Parfum
		daftar[49] = {"B051", "Parfum Vanilla", "Parfum", 20000, 30};
		daftar[50] = {"B052", "Parfum Lavender", "Parfum", 22000, 25};
		daftar[51] = {"B053", "Parfum Ocean", "Parfum", 21000, 35};
		daftar[52] = {"B054", "Parfum Musk", "Parfum", 25000, 20};
		daftar[53] = {"B055", "Parfum Rose", "Parfum", 23000, 28};
		daftar[54] = {"B056", "Parfum Jasmine", "Parfum", 24000, 26};
		daftar[55] = {"B057", "Parfum Citrus", "Parfum", 19000, 32};
		daftar[56] = {"B058", "Parfum Green Tea", "Parfum", 26000, 18};
		daftar[57] = {"B059", "Parfum Coffee", "Parfum", 27000, 22};
		daftar[58] = {"B060", "Parfum Sandalwood", "Parfum", 28000, 24};
		
		// Skincare
		daftar[59] = {"B061", "Moisturizer", "Skincare", 30000, 45};
		daftar[60] = {"B062", "Sunscreen", "Skincare", 35000, 40};
		daftar[61] = {"B063", "Serum Wajah", "Skincare", 50000, 35};
		daftar[62] = {"B064", "Facial Wash", "Skincare", 25000, 50};
		daftar[63] = {"B065", "Night Cream", "Skincare", 45000, 30};
		daftar[64] = {"B066", "Toner", "Skincare", 27000, 38};
		daftar[65] = {"B067", "Sheet Mask", "Skincare", 15000, 60};
		daftar[66] = {"B068", "Eye Cream", "Skincare", 48000, 28};
		daftar[67] = {"B069", "Lip Balm", "Skincare", 12000, 55};
		daftar[68] = {"B070", "Peeling Gel", "Skincare", 33000, 25};
		
		// Minuman
		daftar[69] = {"B071", "Teh Botol", "Minuman", 4000, 100};
		daftar[70] = {"B072", "Aqua 600ml", "Minuman", 3000, 120};
		daftar[71] = {"B073", "Susu Ultra", "Minuman", 6000, 90};
		daftar[72] = {"B074", "Kopi Kapal Api", "Minuman", 2500, 150};
		daftar[73] = {"B075", "Floridina", "Minuman", 4000, 85};
		daftar[74] = {"B076", "Good Day", "Minuman", 4500, 80};
		daftar[75] = {"B077", "Pocari Sweat", "Minuman", 7000, 75};
		daftar[76] = {"B078", "Coca Cola", "Minuman", 6000, 100};
		daftar[77] = {"B079", "Sprite", "Minuman", 6000, 95};
		daftar[78] = {"B080", "You C1000", "Minuman", 8000, 70};
		
		// Sembako
		daftar[79] = {"B081", "Beras 5kg", "Sembako", 60000, 40};
		daftar[80] = {"B082", "Minyak Goreng 1L", "Sembako", 15000, 60};
		daftar[81] = {"B083", "Gula Pasir 1kg", "Sembako", 14000, 50};
		daftar[82] = {"B084", "Telur Ayam 1kg", "Sembako", 28000, 55};
		daftar[83] = {"B085", "Tepung Terigu 1kg", "Sembako", 10000, 45};
		daftar[84] = {"B086", "Garam Dapur", "Sembako", 3000, 80};
		daftar[85] = {"B087", "Kecap Manis", "Sembako", 9000, 70};
		daftar[86] = {"B088", "Saus Sambal", "Sembako", 8000, 65};
		daftar[87] = {"B089", "Mi Instan", "Sembako", 3000, 100};
		daftar[88] = {"B090", "Susu Bubuk", "Sembako", 35000, 30};
		
		// Baju
		daftar[89] = {"B091", "Kaos Polos", "Baju", 25000, 40};
		daftar[90] = {"B092", "Kemeja Lengan Pendek", "Baju", 45000, 30};
		daftar[91] = {"B093", "Jaket Hoodie", "Baju", 70000, 25};
		daftar[92] = {"B094", "Celana Jeans", "Baju", 80000, 20};
		daftar[93] = {"B095", "Kaos Lengan Panjang", "Baju", 30000, 35};
		daftar[94] = {"B096", "Kemeja Flanel", "Baju", 50000, 28};
		daftar[95] = {"B097", "Sweater", "Baju", 60000, 22};
		daftar[96] = {"B098", "Rok Pendek", "Baju", 40000, 18};
		daftar[97] = {"B099", "Celana Bahan", "Baju", 45000, 26};
		daftar[98] = {"B100", "Kaos Oblong", "Baju", 20000, 50};
		
		// ATK (Alat Tulis Kantor)
		daftar[99] = {"B101", "Stapler", "ATK", 15000, 40};
		daftar[100] = {"B102", "Isi Staples", "ATK", 5000, 60};
		daftar[101] = {"B103", "Lakban", "ATK", 8000, 55};
		daftar[102] = {"B104", "Gunting", "ATK", 10000, 50};
		daftar[103] = {"B105", "Cutter", "ATK", 9000, 45};
		daftar[104] = {"B106", "Kertas HVS", "ATK", 30000, 30};
		daftar[105] = {"B107", "Map Kertas", "ATK", 2000, 70};
		daftar[106] = {"B108", "Lem Kertas", "ATK", 4000, 65};
		daftar[107] = {"B109", "Papan Klip", "ATK", 12000, 25};
		daftar[108] = {"B110", "Spidol Whiteboard", "ATK", 7000, 35};
		
		// Bumbu Dapur
		daftar[109] = {"B111", "Bawang Putih", "Bumbu dapur", 20000, 50};
		daftar[110] = {"B112", "Bawang Merah", "Bumbu dapur", 18000, 55};
		daftar[111] = {"B113", "Cabai Merah", "Bumbu dapur", 25000, 40};
		daftar[112] = {"B114", "Ketumbar", "Bumbu dapur", 6000, 60};
		daftar[113] = {"B115", "Kunyit", "Bumbu dapur", 4000, 65};
		daftar[114] = {"B116", "Jahe", "Bumbu dapur", 5000, 50};
		daftar[115] = {"B117", "Lengkuas", "Bumbu dapur", 4000, 45};
		daftar[116] = {"B118", "Merica Bubuk", "Bumbu dapur", 10000, 30};
		daftar[117] = {"B119", "Garam Halus", "Bumbu dapur", 3000, 80};
		daftar[118] = {"B120", "Penyedap Rasa", "Bumbu dapur", 5000, 75};
		
		// Buah-buahan
		daftar[119] = {"B121", "Apel", "Buah-buahan", 15000, 60};
		daftar[120] = {"B122", "Jeruk", "Buah-buahan", 12000, 70};
		daftar[121] = {"B123", "Pisang", "Buah-buahan", 10000, 80};
		daftar[122] = {"B124", "Anggur", "Buah-buahan", 25000, 40};
		daftar[123] = {"B125", "Semangka", "Buah-buahan", 20000, 35};
		daftar[124] = {"B126", "Melon", "Buah-buahan", 18000, 30};
		daftar[125] = {"B127", "Pepaya", "Buah-buahan", 9000, 45};
		daftar[126] = {"B128", "Mangga", "Buah-buahan", 13000, 50};
		daftar[127] = {"B129", "Nanas", "Buah-buahan", 8000, 55};
		daftar[128] = {"B130", "Kiwi", "Buah-buahan", 27000, 25};
		
		// Frozen Food
		daftar[129] = {"B131", "Nugget Ayam", "Frozen food", 25000, 40};
		daftar[130] = {"B132", "Sosis Sapi", "Frozen food", 23000, 50};
		daftar[131] = {"B133", "Bakso Ikan", "Frozen food", 20000, 60};
		daftar[132] = {"B134", "Dimsum Ayam", "Frozen food", 28000, 30};
		daftar[133] = {"B135", "Kentang Beku", "Frozen food", 22000, 35};
		daftar[134] = {"B136", "Chicken Karaage", "Frozen food", 30000, 25};
		daftar[135] = {"B137", "Tempura", "Frozen food", 27000, 28};
		daftar[136] = {"B138", "Tahu Bakso", "Frozen food", 18000, 45};
		daftar[137] = {"B139", "Lumpia Frozen", "Frozen food", 20000, 32};
		daftar[138] = {"B140", "Risol Mayo", "Frozen food", 24000, 38};

        jumlahBarang = 139; 
    }
	
	void tambahBarang() {
        if (jumlahBarang >= MAX_BARANG) {
            cout << "Kapasitas barang penuh, tidak bisa tambah lagi.\n";
            return;
        }
        DataBarang barang;
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
        daftar[jumlahBarang++] = barang;
        cout << "Barang berhasil ditambahkan!\n";
    }
    
    void tampilkanSemuaBarang(bool tampilkanStok = false) {
        if (jumlahBarang == 0) {
            cout << "Belum ada barang.\n";
            return;
        }
        cout << "\n=== Daftar Semua Barang ===\n";
        for (int i = 0; i < jumlahBarang; i++) {
            cout << "-----------------------------\n";
            cout << "Kode     : " << daftar[i].kode << "\n";
            cout << "Nama     : " << daftar[i].nama << "\n";
            cout << "Kategori : " << daftar[i].kategori << "\n";
            cout << "Harga    : Rp " << daftar[i].harga << "\n";
            if (tampilkanStok)
                cout << "Stok     : " << daftar[i].stok << "\n";
        }
        cout << "-----------------------------\n";
    }

    void tampilkanKategori(string kategoriDicari, bool tampilkanStok = false) {
        bool ditemukan = false;
        cout << "\n=== Kategori: " << kategoriDicari << " ===\n";
        for (int i = 0; i < jumlahBarang; i++) {
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

    void cariBarang(const string& kunci) {
	    bool ditemukan = false;
	    for (int i = 0; i < MAX_BARANG; ++i) {
	        if (daftar[i].kode == kunci || daftar[i].nama == kunci) {
	            cout << "Barang ditemukan:\n";
	            cout << "Kode: " << daftar[i].kode << "\n";
	            cout << "Nama: " << daftar[i].nama << "\n";
	            cout << "Kategori: " << daftar[i].kategori << "\n";
	            cout << "Harga: " << daftar[i].harga << "\n";
	            cout << "Stok: " << daftar[i].stok << "\n";
	            ditemukan = true;
	            break;
	        }
	    }
	    if (!ditemukan) {
	        cout << "Barang tidak ditemukan.\n";
	    }
	}
	
	void editBarang(const string& kode) {
	    bool ditemukan = false;
	    for (int i = 0; i < MAX_BARANG; i++) {
	        if (daftar[i].kode == kode) {
	            ditemukan = true;
	            cout << "\nBarang ditemukan:\n";
	            cout << "Kode: " << daftar[i].kode << endl;
	            cout << "Nama: " << daftar[i].nama << endl;
	            cout << "Kategori: " << daftar[i].kategori << endl;
	            cout << "Harga: " << daftar[i].harga << endl;
	            cout << "Stok: " << daftar[i].stok << endl;
	
	            cout << "\nMasukkan data baru:\n";
	            cout << "Nama baru: ";
	            getline(cin >> ws, daftar[i].nama);
	            cout << "Kategori baru: ";
	            getline(cin >> ws, daftar[i].kategori);
	            cout << "Harga baru: ";
	            cin >> daftar[i].harga;
	            cout << "Stok baru: ";
	            cin >> daftar[i].stok;
	
	            cout << "\nData barang berhasil diperbarui.\n";
	            break;
	        }
	    }
	    if (!ditemukan) {
	        cout << "\nBarang dengan kode " << kode << " tidak ditemukan.\n";
	    }
	}
	
	    void hapusBarang(string kode) {
	        bool ditemukan = false;
	        for (int i = 0; i < MAX_BARANG; i++) {
	            if (daftar[i].kode == kode) {
	                ditemukan = true;
	                // Geser elemen ke kiri untuk menimpa elemen yang dihapus
	                for (int j = i; j < MAX_BARANG - 1; j++) {
	                    daftar[j] = daftar[j + 1];
	                }
	                // Kosongkan data terakhir
	                daftar[MAX_BARANG - 1] = {"", "", "", 0.0, 0};
	                cout << "Barang dengan kode " << kode << " berhasil dihapus." << endl;
	                break;
	            }
	        }
	        if (!ditemukan) {
	            cout << "Barang dengan kode " << kode << " tidak ditemukan." << endl;
	        }
	    }
	
	void tampilkanStokRendah(int batas = 30) {
	    cout << "\n=== Daftar Barang dengan Stok Rendah (stok < " << batas << ") ===\n";
	    bool ditemukan = false;
	    for (int i = 0; i < jumlahBarang; i++) {
	        if (daftar[i].stok < batas) {
	            cout << daftar[i].kode << " | " << daftar[i].nama 
	                 << " | Kategori: " << daftar[i].kategori 
	                 << " | Harga: " << daftar[i].harga 
	                 << " | Stok: " << daftar[i].stok << endl;
	            ditemukan = true;
	        }
	    }
	    if (!ditemukan) {
	        cout << "Tidak ada barang dengan stok di bawah " << batas << ".\n";
	    }
	}

};

int main() {
    User user;
    Barang barang;
    barang.initBarang();
    string kunci;
    string kodeEdit;
    string kodeHapus;

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
                    else if (pilihAdmin == 3){
                    	cout << "Masukkan kode atau nama barang yang ingin dicari: ";
						cin >> kunci;
						barang.cariBarang(kunci);
					} else if (pilihAdmin == 4){
						cout << "Masukkan kode barang yang ingin diedit: ";
						cin >> kodeEdit;
						barang.editBarang(kodeEdit);
					} else if (pilihAdmin == 5){
						cout << "Masukkan kode barang yang ingin dihapus: ";
						cin >> kodeHapus;
						barang.hapusBarang(kodeHapus);
					} else if (pilihAdmin == 6)
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
				    cout << "\n=== MENU KARYAWAN ===\n";
				    cout << "1. Lihat Semua Barang\n";
				    cout << "2. Cari Barang\n";
				    cout << "0. Logout\n";
				    cout << "Pilih: ";
				    cin >> pilihKaryawan;
				
				    if (pilihKaryawan == 1)
				        barang.tampilkanSemuaBarang(true);
				    else if (pilihKaryawan == 2){
				    	cout << "Masukkan kode atau nama barang yang ingin dicari: ";
						cin >> kunci;
						barang.cariBarang(kunci);
					}
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
