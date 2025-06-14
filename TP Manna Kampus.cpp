#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Swalayan {
private:
    struct Barang {
        string kode; 
		string nama; 
		string kategori;
        double harga;
        int stok;
    } daftar[1000];

    struct Transaksi {
        string nama;
        int jumlah;
        double hargaTotal;
    } transaksi[1000];

    string userAdmin = "admin"; 
	string passAdmin = "1234";
    string userKasir = "kasir"; 
	string passKasir = "abcd";

    int jumlahBarang = 0; 
	int jumlahTransaksi = 0;
    double totalPendapatan = 0;
    int jumlahDibeli[500] = {0};

public:
    void start() {
        int pilihan;
        
        do {
            system("cls");
            cout << "\n===== Manna Kampus =====\n";
            cout << "1. Login Admin" << endl;
            cout << "2. Login Kasir" << endl;
            cout << "3. Keluar" << endl;
            cout << "-------------------------" << endl;
            cout << "Pilihan: ";
            cin >> pilihan;
            switch (pilihan) {
                case 1: 
					loginAdmin(); 
					break;
                case 2: 
					loginKasir(); 
					break;
                case 3: 
					cout << "Keluar..." << endl; 
					break;
                default: 
					cout << "Pilihan tidak valid!\n"; 
					system("pause");
            }
        } while (pilihan != 3);
    }

    void iniBarang() {
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
        daftar[10] = {"B011", "Pringles Original", "Snack", 25000, 50};
		daftar[11] = {"B012", "Doritos Nacho Cheese", "Snack", 9000, 60};
		daftar[12] = {"B013", "Malkist Crackers", "Snack", 8000, 70};
		daftar[13] = {"B014", "Beng-Beng", "Snack", 2000, 150};
		daftar[14] = {"B015", "Choki-Choki", "Snack", 1000, 200};
		daftar[15] = {"B016", "Potabee BBQ", "Snack", 7200, 65};
		daftar[16] = {"B017", "Happy Tos Merah", "Snack", 6700, 58};
		daftar[17] = {"B018", "Sponge Crunch Coklat", "Snack", 4500, 77};
		daftar[18] = {"B019", "Pilus Garuda", "Snack", 5500, 88};
		daftar[19] = {"B020", "Kacang Garuda Rosta", "Snack", 10000, 40};
		daftar[20] = {"B021", "Kuaci Rebo Original", "Snack", 6000, 90};
		daftar[21] = {"B022", "Permen Relaxa", "Snack", 3000, 120};
		daftar[22] = {"B023", "Permen Kopiko", "Snack", 3500, 110};
		daftar[23] = {"B024", "Roma Kelapa", "Snack", 7000, 80};
		daftar[24] = {"B025", "Gery Saluut Malkist Coklat", "Snack", 9000, 60};
		daftar[25] = {"B026", "Ahoy Wafer Coklat", "Snack", 4000, 75};
		daftar[26] = {"B027", "Yupi Burger", "Snack", 2500, 95};
		daftar[27] = {"B028", "Chacha Peanut", "Snack", 5000, 85};
		daftar[28] = {"B029", "Superstar Wafer", "Snack", 1500, 130};
		daftar[29] = {"B030", "Momogi Jagung Bakar", "Snack", 1000, 160};
		daftar[30] = {"B031", "Hello Panda Coklat", "Snack", 8000, 55};
		daftar[31] = {"B032", "Pocky Coklat", "Snack", 7500, 63};
		daftar[32] = {"B033", "Tim Tam Classic", "Snack", 10000, 48};
		daftar[33] = {"B034", "Slai Olai Strawberry", "Snack", 6500, 72};
		daftar[34] = {"B035", "Biskuat Original", "Snack", 5800, 81};
		daftar[35] = {"B036", "Better Sandwich Biscuit", "Snack", 6200, 79};
		daftar[36] = {"B037", "Choco Pie", "Snack", 15000, 35};
		daftar[37] = {"B038", "Koko Krunch Bar", "Snack", 4000, 67};
		daftar[38] = {"B039", "Astor Coklat", "Snack", 12000, 42};
		daftar[39] = {"B040", "Twister Black", "Snack", 3000, 99};

        // Shampo
        daftar[40] = {"B041", "Sunsilk", "Shampo", 15000, 50};
		daftar[41] = {"B042", "Pantene", "Shampo", 16000, 45};
		daftar[42] = {"B043", "Clear", "Shampo", 17000, 40};
		daftar[43] = {"B044", "Head & Shoulders", "Shampo", 18000, 35};
		daftar[44] = {"B045", "Lifebuoy", "Shampo", 14000, 60};
		daftar[45] = {"B046", "Tresemme", "Shampo", 20000, 30};
		daftar[46] = {"B047", "Rejoice", "Shampo", 13000, 55};
		daftar[47] = {"B048", "Herbal Essences", "Shampo", 22000, 25};
		daftar[48] = {"B049", "Zinc", "Shampo", 12000, 70};
		daftar[49] = {"B050", "Wardah", "Shampo", 19000, 33};
		daftar[50] = {"B051", "Dove Daily Shine Shampoo", "Shampo", 17500, 42};
		daftar[51] = {"B052", "Emeron Black Shine Shampoo", "Shampo", 11000, 68};
		daftar[52] = {"B053", "Natur Pencuci Rambut Ginseng", "Shampo", 25000, 28};
		daftar[53] = {"B054", "Serasoft Serum Shampoo", "Shampo", 16500, 38};
		daftar[54] = {"B055", "Mane 'n Tail Original Shampoo", "Shampo", 150000, 15};
		daftar[55] = {"B056", "Selsun Blue Anti Dandruff", "Shampo", 45000, 22};
		daftar[56] = {"B057", "L'Oreal Paris Elseve Total Repair", "Shampo", 35000, 30};
		daftar[57] = {"B058", "Mustika Ratu Shampoo Bayam", "Shampo", 18000, 40};
		daftar[58] = {"B059", "Garnier Neril Anti-Loss Guard", "Shampo", 32000, 25};
		daftar[59] = {"B060", "Kerastase Bain Prevention", "Shampo", 350000, 10};
		daftar[60] = {"B061", "Petal Fresh Rose & Honeysuckle", "Shampo", 85000, 20};
		daftar[61] = {"B062", "The Body Shop Ginger Shampoo", "Shampo", 120000, 18};
		daftar[62] = {"B063", "Cultusia Creambath Ginseng", "Shampo", 28000, 33};
		daftar[63] = {"B064", "Ichikami Smoothing Shampoo", "Shampo", 95000, 16};
		daftar[64] = {"B065", "Love Beauty Planet Coconut Water", "Shampo", 75000, 23};

        //sabun
        daftar[65] = {"B066", "Lifebuoy Bar", "Sabun", 3000, 80};
		daftar[66] = {"B067", "Lux", "Sabun", 3500, 90};
		daftar[67] = {"B068", "Dettol", "Sabun", 4000, 70};
		daftar[68] = {"B069", "Palmolive", "Sabun", 4500, 60};
		daftar[69] = {"B070", "Biore", "Sabun", 5000, 65};
		daftar[70] = {"B071", "Giv", "Sabun", 2500, 100};
		daftar[71] = {"B072", "Nuvo", "Sabun", 3700, 75};
		daftar[72] = {"B073", "Imperial Leather", "Sabun", 4800, 55};
		daftar[73] = {"B074", "Shinzui", "Sabun", 5200, 50};
		daftar[74] = {"B075", "Leivy", "Sabun", 6000, 45};
		daftar[75] = {"B076", "Dettol Cair Original", "Sabun", 25000, 55};
		daftar[76] = {"B077", "Biore Guard Body Foam", "Sabun", 28000, 60};
		daftar[77] = {"B078", "Lux Magical Spell Body Wash", "Sabun", 27000, 50};
		daftar[78] = {"B079", "Lifebuoy Cair Lemon Fresh", "Sabun", 22000, 70};
		daftar[79] = {"B080", "Shinzui Kirei Body Cleanser", "Sabun", 30000, 45};
		daftar[80] = {"B081", "Palmolive Aroma Therapy", "Sabun", 32000, 40};
		daftar[81] = {"B082", "Asepso Sabun Antiseptik", "Sabun", 7000, 80};
		daftar[82] = {"B083", "Dove Beauty Bar White", "Sabun", 8000, 75};
		daftar[83] = {"B084", "Citra Pearly White Bar", "Sabun", 4000, 90};
		daftar[84] = {"B085", "Giv White Bengkoang Bar", "Sabun", 3000, 100};
		daftar[85] = {"B086", "Nuvo Family Cair Cool", "Sabun", 20000, 66};
		daftar[86] = {"B087", "Zen Antibacterial Body Wash", "Sabun", 35000, 38};
		daftar[87] = {"B088", "Cussons Imperial Leather Classic Bar", "Sabun", 5000, 82};
		daftar[88] = {"B089", "Johnson's Baby Bath Milk+Rice", "Sabun", 33000, 48};
		daftar[89] = {"B090", "JF Sulfur Acne Protect Bar", "Sabun", 15000, 53};
			
		// Obat-obatan
		daftar[90] = {"B091", "Paracetamol", "Obat-obatan", 2000, 100};
		daftar[91] = {"B092", "OBH Combi", "Obat-obatan", 12000, 60};
		daftar[92] = {"B093", "Antangin", "Obat-obatan", 1500, 90};
		daftar[93] = {"B094", "Tolak Angin", "Obat-obatan", 3000, 70};
		daftar[94] = {"B095", "Bodrex", "Obat-obatan", 2500, 80};
		daftar[95] = {"B096", "Promag", "Obat-obatan", 2000, 85};
		daftar[96] = {"B097", "Panadol", "Obat-obatan", 3500, 75};
		daftar[97] = {"B098", "Decolgen", "Obat-obatan", 2700, 65};
		daftar[98] = {"B099", "Neozep", "Obat-obatan", 2900, 60};
		daftar[99] = {"B100", "Konidin", "Obat-obatan", 2400, 95};
		daftar[100] = {"B101", "Minyak Kayu Putih Cap Lang", "Obat-obatan", 18000, 70};
		daftar[101] = {"B102", "Betadine Antiseptic Solution", "Obat-obatan", 15000, 60};
		daftar[102] = {"B103", "Hansaplast Plester", "Obat-obatan", 5000, 100};
		daftar[103] = {"B104", "Counterpain Cream", "Obat-obatan", 30000, 40};
		daftar[104] = {"B105", "Sangobion Kapsul", "Obat-obatan", 12000, 50};
		daftar[105] = {"B106", "Diapet Kapsul", "Obat-obatan", 7000, 80};
		daftar[106] = {"B107", "Insto Tetes Mata", "Obat-obatan", 13000, 55};
		daftar[107] = {"B108", "Vicks Vaporub", "Obat-obatan", 20000, 45};
		daftar[108] = {"B109", "Strepsils Permen Pelega", "Obat-obatan", 10000, 90};
		daftar[109] = {"B110", "Norit Karbon Aktif", "Obat-obatan", 9000, 65};
		daftar[110] = {"B111", "Panadol Extra Merah", "Obat-obatan", 4000, 78};
		daftar[111] = {"B112", "Tempra Sirup Anak", "Obat-obatan", 22000, 35};
		daftar[112] = {"B113", "Mylanta Cair", "Obat-obatan", 11000, 63};
		daftar[113] = {"B114", "Vitamin C IPI Tablet", "Obat-obatan", 6000, 110};
		daftar[114] = {"B115", "Neurobion Forte Tablet", "Obat-obatan", 28000, 33};
		daftar[115] = {"B116", "Ambeven Kapsul", "Obat-obatan", 17000, 42};
		daftar[116] = {"B117", "Salep 88 Anti Jamur", "Obat-obatan", 8000, 72};
		daftar[117] = {"B118", "Woods Peppermint Sirup", "Obat-obatan", 25000, 30};
		daftar[118] = {"B119", "CDR Effervescent", "Obat-obatan", 40000, 25};
		daftar[119] = {"B120", "Entrostop Tablet Anak", "Obat-obatan", 5000, 85};
		
		// Bakery
		daftar[120] = {"B121", "Roti Tawar", "Bakery", 7000, 80};
		daftar[121] = {"B122", "Croissant", "Bakery", 8000, 75};
		daftar[122] = {"B123", "Roti Pisang", "Bakery", 5000, 85};
		daftar[123] = {"B124", "Kue Lapis", "Bakery", 4500, 60};
		daftar[124] = {"B125", "Bolu Gulung", "Bakery", 7500, 50};
		daftar[125] = {"B126", "Roti Sisir", "Bakery", 6000, 70};
		daftar[126] = {"B127", "Kue Cubit", "Bakery", 4000, 65};
		daftar[127] = {"B128", "Roti Sosis", "Bakery", 8500, 40};
		daftar[128] = {"B129", "Roti Coklat", "Bakery", 8000, 55};
		daftar[129] = {"B130", "Brownies Amanda Original", "Bakery", 35000, 30};
		daftar[130] = {"B131", "Bika Ambon Zulaikha", "Bakery", 50000, 20};
		daftar[131] = {"B132", "Roti Boy Original", "Bakery", 12000, 40};
		daftar[132] = {"B133", "Donat JCO Assorted", "Bakery", 9000, 50};
		daftar[133] = {"B134", "Muffin Coklat Chip", "Bakery", 7000, 60};
		daftar[134] = {"B135", "Pastel Isi Sayur Ayam", "Bakery", 4000, 70};
		daftar[135] = {"B136", "Lemper Ayam Bakar", "Bakery", 3500, 80};
		daftar[136] = {"B137", "Kue Sus Original", "Bakery", 3000, 90};
		daftar[137] = {"B138", "Bolu Kukus Mekar", "Bakery", 2500, 100};
		daftar[138] = {"B139", "Lapis Surabaya Potong", "Bakery", 6000, 55};
		daftar[139] = {"B140", "Pizza Mini Sosis", "Bakery", 10000, 45};
		daftar[140] = {"B141", "Bagelen Keju Kering", "Bakery", 15000, 38};
		daftar[141] = {"B142", "Roti Gambang Klasik", "Bakery", 5000, 65};
		daftar[142] = {"B143", "Klapertart Mini Cup", "Bakery", 18000, 33};
		daftar[143] = {"B144", "Cheese Stick Edam", "Bakery", 22000, 28};

		// Parfum
		daftar[144] = {"B145", "Parfum Vanilla", "Parfum", 20000, 30};
		daftar[145] = {"B146", "Parfum Lavender", "Parfum", 22000, 25};
		daftar[146] = {"B147", "Parfum Ocean", "Parfum", 21000, 35};
		daftar[147] = {"B148", "Parfum Musk", "Parfum", 25000, 20};
		daftar[148] = {"B149", "Parfum Rose", "Parfum", 23000, 28};
		daftar[149] = {"B150", "Parfum Jasmine", "Parfum", 24000, 26};
		daftar[150] = {"B151", "Parfum Citrus", "Parfum", 19000, 32};
		daftar[151] = {"B152", "Parfum Green Tea", "Parfum", 26000, 18};
		daftar[152] = {"B153", "Parfum Coffee", "Parfum", 27000, 22};
		daftar[153] = {"B154", "Parfum Sandalwood", "Parfum", 28000, 24};
		daftar[154] = {"B155", "Axe Body Spray Dark Temptation", "Parfum", 35000, 40};
		daftar[155] = {"B156", "Bellagio Homme Rave Culture", "Parfum", 45000, 30};
		daftar[156] = {"B157", "Casablanca Body Mist Femme", "Parfum", 28000, 50};
		daftar[157] = {"B158", "Pucelle Eau De Luxe Cologne", "Parfum", 22000, 60};
		daftar[158] = {"B159", "Regazza Femme Spray Cologne", "Parfum", 30000, 45};
		daftar[159] = {"B160", "Vitalis Eau De Cologne Magnifique", "Parfum", 33000, 38};
		daftar[160] = {"B161", "Morris Eau De Parfum Tropical", "Parfum", 40000, 33};
		daftar[161] = {"B162", "Evangeline Eau De Parfum Sakura", "Parfum", 38000, 35};
		daftar[162] = {"B163", "Christian Jornald Eau De Parfum", "Parfum", 50000, 25};
		daftar[163] = {"B164", "Eskulin Cologne Gel Romantic", "Parfum", 15000, 70};
		
		// Skincare
		daftar[164] = {"B165", "Garnier Micellar Water Pink", "Skincare", 28000, 55};
		daftar[165] = {"B166", "Wardah Lightening Day Cream", "Skincare", 32000, 50};
		daftar[166] = {"B167", "Emina Bright Stuff Face Wash", "Skincare", 20000, 70};
		daftar[167] = {"B168", "Ponds White Beauty Facial Foam", "Skincare", 25000, 60};
		daftar[168] = {"B169", "Viva Milk Cleanser Lemon", "Skincare", 8000, 100};
		daftar[169] = {"B170", "Pixy UV Whitening Two Way Cake", "Skincare", 35000, 45};
		daftar[170] = {"B171", "Nivea Creme Tin", "Skincare", 15000, 80};
		daftar[171] = {"B172", "Vaseline Repairing Jelly", "Skincare", 22000, 65};
		daftar[172] = {"B173", "Clean & Clear Foaming Face Wash", "Skincare", 23000, 63};
		daftar[173] = {"B174", "Hada Labo Gokujyun Lotion", "Skincare", 45000, 40};
		daftar[174] = {"B175", "Biore UV Aqua Rich Watery Essence", "Skincare", 120000, 25};
		daftar[175] = {"B176", "Laneige Water Sleeping Mask", "Skincare", 300000, 15};
		daftar[176] = {"B177", "Somethinc Niacinamide Serum", "Skincare", 119000, 30};
		daftar[177] = {"B178", "Avoskin Miraculous Refining Toner", "Skincare", 150000, 22};
		daftar[178] = {"B179", "Scarlett Whitening Body Lotion Romansa", "Skincare", 75000, 38};
		daftar[179] = {"B180", "Citra Hazeline Pearly White UV", "Skincare", 26000, 58};
		daftar[180] = {"B181", "Acnol Lotion Jerawat", "Skincare", 18000, 72};
		daftar[181] = {"B182", "Herborist Lulur Tradisional Bali", "Skincare", 20000, 68};
		daftar[182] = {"B183", "Mustika Ratu Masker Bengkoang", "Skincare", 12000, 85};
		daftar[183] = {"B184", "St. Ives Apricot Scrub", "Skincare", 80000, 32};
		
		// Minuman
		daftar[184] = {"B185", "Teh Botol", "Minuman", 4000, 100};
		daftar[185] = {"B186", "Aqua 600ml", "Minuman", 3000, 120};
		daftar[186] = {"B187", "Susu Ultra", "Minuman", 6000, 90};
		daftar[187] = {"B188", "Kopi Kapal Api", "Minuman", 2500, 150};
		daftar[188] = {"B189", "Floridina", "Minuman", 4000, 85};
		daftar[189] = {"B190", "Good Day", "Minuman", 4500, 80};
		daftar[190] = {"B191", "Pocari Sweat", "Minuman", 7000, 75};
		daftar[191] = {"B192", "Coca Cola", "Minuman", 6000, 100};
		daftar[192] = {"B193", "Sprite", "Minuman", 6000, 95};
		daftar[193] = {"B194", "You C1000", "Minuman", 8000, 70};
		daftar[194] = {"B195", "Fanta Strawberry Kaleng", "Minuman", 6000, 98};
		daftar[195] = {"B196", "NutriSari Jeruk Sachet", "Minuman", 1000, 250};
		daftar[196] = {"B197", "Milo Activ-Go Kotak", "Minuman", 7000, 88};
		daftar[197] = {"B198", "Bear Brand Susu Steril", "Minuman", 10000, 70};
		daftar[198] = {"B199", "Hydro Coco Original", "Minuman", 9000, 75};
		daftar[199] = {"B200", "Teh Kotak Jasmine", "Minuman", 3500, 110};
		daftar[200] = {"B201", "Indomilk Susu UHT Coklat", "Minuman", 5500, 92};
		daftar[201] = {"B202", "Le Minerale 600ml", "Minuman", 3000, 115};
		daftar[202] = {"B203", "Torabika Cappuccino Sachet", "Minuman", 2800, 140};
		daftar[203] = {"B204", "Larutan Penyegar Cap Badak", "Minuman", 7000, 83};
		daftar[204] = {"B205", "Frestea Apel Botol", "Minuman", 4500, 87};
		daftar[205] = {"B206", "Big Cola Strawberry", "Minuman", 5000, 100};
		daftar[206] = {"B207", "Ultra Mimi Kids Coklat", "Minuman", 3000, 120};
		daftar[207] = {"B208", "Pulpy Orange Botol", "Minuman", 6500, 77};
		daftar[208] = {"B209", "Sari Kacang Ijo ABC", "Minuman", 5000, 82};
		daftar[209] = {"B210", "Kratingdaeng Energy Drink", "Minuman", 7500, 69};
		daftar[210] = {"B211", "Nescafe Classic Sachet", "Minuman", 1500, 180};
		daftar[211] = {"B212", "Susu Bendera Kental Manis", "Minuman", 10000, 60};
		daftar[212] = {"B213", "Marjan Sirup Cocopandan", "Minuman", 20000, 40};
		daftar[213] = {"B214", "ABC Squash Delight Jeruk", "Minuman", 12000, 50};
		daftar[214] = {"B215", "Green Sands Lime Apple", "Minuman", 8000, 66};
		daftar[215] = {"B216", "Mizone Isotonic Lychee", "Minuman", 5500, 93};
		daftar[216] = {"B217", "Nutriboost Strawberry", "Minuman", 7000, 71};
		daftar[217] = {"B218", "Teh Pucuk Harum Original", "Minuman", 3500, 130};
		daftar[218] = {"B219", "S-tee Teh Melati Botol", "Minuman", 3000, 125};
		daftar[219] = {"B220", "Fruit Tea Apel Botol", "Minuman", 4000, 105};
		daftar[220] = {"B221", "Fatigon Hydro Coco", "Minuman", 8500, 73};
		daftar[221] = {"B222", "Sariwangi Teh Celup Asli", "Minuman", 6000, 96};
		daftar[222] = {"B223", "Adem Sari Ching Ku", "Minuman", 4000, 108};
		daftar[223] = {"B224", "Hemaviton Jreng Sachet", "Minuman", 2000, 160};
		daftar[224] = {"B225", "Kopiko 78C Coffee Latte", "Minuman", 9000, 64};
		daftar[225] = {"B226", "Golda Coffee Dolce Latte", "Minuman", 3500, 112};
		daftar[226] = {"B227", "Cimory Yoghurt Drink Strawberry", "Minuman", 7000, 81};
		daftar[227] = {"B228", "Yakult Probiotic Drink", "Minuman", 10000, 55};
		daftar[228] = {"B229", "Tropicana Slim Cafe Latte", "Minuman", 8000, 67};
		daftar[229] = {"B230", "Jahe Merah AMH Sachet", "Minuman", 1500, 170};
		daftar[230] = {"B231", "Teh Celup Sosro", "Minuman", 5500, 99};
		daftar[231] = {"B232", "Sirup Kurnia Raspberry", "Minuman", 22000, 37};
		daftar[232] = {"B233", "Extra Joss Active Sachet", "Minuman", 1800, 175};
		daftar[233] = {"B234", "Pristine 8+ Air Mineral", "Minuman", 4000, 103};

		// Sembako
		daftar[234] = {"B235", "Beras 5kg", "Sembako", 60000, 40};
		daftar[235] = {"B236", "Minyak Goreng 1L", "Sembako", 15000, 60};
		daftar[236] = {"B237", "Gula Pasir 1kg", "Sembako", 14000, 50};
		daftar[237] = {"B238", "Telur Ayam 1kg", "Sembako", 28000, 55};
		daftar[238] = {"B239", "Tepung Terigu 1kg", "Sembako", 10000, 45};
		daftar[239] = {"B240", "Garam Dapur", "Sembako", 3000, 80};
		daftar[240] = {"B241", "Kecap Manis", "Sembako", 9000, 70};
		daftar[241] = {"B242", "Saus Sambal", "Sembako", 8000, 65};
		daftar[242] = {"B243", "Mi Instan", "Sembako", 3000, 100};
		daftar[243] = {"B244", "Susu Bubuk", "Sembako", 35000, 30};
		daftar[244] = {"B245", "Beras BMW Pandan Wangi 5kg", "Sembako", 75000, 30};
		daftar[245] = {"B246", "Minyak Goreng Bimoli 2L", "Sembako", 30000, 40};
		daftar[246] = {"B247", "Gula Merah Batok 500g", "Sembako", 10000, 60};
		daftar[247] = {"B248", "Telur Puyuh 1 Papan", "Sembako", 15000, 35};
		daftar[248] = {"B249", "Tepung Beras Rose Brand 500g", "Sembako", 7000, 70};
		daftar[249] = {"B250", "Santan Kara 200ml", "Sembako", 5000, 80};
		daftar[250] = {"B251", "Kecap Asin ABC Botol", "Sembako", 7000, 65};
		daftar[251] = {"B252", "Saus Tomat Indofood Botol", "Sembako", 7500, 63};
		daftar[252] = {"B253", "Mi Instan Sedaap Goreng", "Sembako", 2800, 120};
		daftar[253] = {"B254", "Susu Kental Manis Frisian Flag Gold", "Sembako", 11000, 55};
		daftar[254] = {"B255", "Kopi Bubuk ABC Susu Sachet", "Sembako", 2000, 150};
		daftar[255] = {"B256", "Energen Sereal Coklat", "Sembako", 2500, 130};
		daftar[256] = {"B257", "Blue Band Margarin Sachet", "Sembako", 5000, 90};
		daftar[257] = {"B258", "Sarden ABC Tomat Kaleng", "Sembako", 12000, 45};
		daftar[258] = {"B259", "Kornet Sapi Pronas Kaleng", "Sembako", 20000, 38};
		daftar[259] = {"B260", "Agar-agar Swallow Globe Plain", "Sembako", 4000, 100};
		daftar[260] = {"B261", "Coklat Bubuk Van Houten", "Sembako", 18000, 33};
		daftar[261] = {"B262", "Bihun Jagung Cap Tanam", "Sembako", 6000, 77};
		daftar[262] = {"B263", "Makaroni Spiral Sedani", "Sembako", 9000, 58};
		daftar[263] = {"B264", "MSG Sasa Penyedap Rasa", "Sembako", 3000, 110};
		daftar[264] = {"B265", "Cuka Dixi Botol", "Sembako", 4000, 88};
		daftar[265] = {"B266", "Minyak Zaitun Borges Extra Virgin", "Sembako", 70000, 20};
		daftar[266] = {"B267", "Bubur Instan Sun Beras Merah", "Sembako", 10000, 53};
		daftar[267] = {"B268", "Kecap Ikan Royal Gold", "Sembako", 13000, 43};
		daftar[268] = {"B269", "Tepung Maizena Haway", "Sembako", 5000, 81};
		daftar[269] = {"B270", "Saus Tiram Saori Sachet", "Sembako", 3000, 105};
		daftar[270] = {"B271", "Gula Aren Asli 250g", "Sembako", 12000, 49};
		daftar[271] = {"B272", "Ragi Instan Fermipan", "Sembako", 6000, 76};
		daftar[272] = {"B273", "Kacang Hijau Kupas 250g", "Sembako", 11000, 51};
		daftar[273] = {"B274", "Terasi Udang ABC Sachet", "Sembako", 2000, 140};

		// Baju
		daftar[274] = {"B275", "Kaos Polos", "Baju", 25000, 40};
		daftar[275] = {"B276", "Kemeja Lengan Pendek", "Baju", 45000, 30};
		daftar[276] = {"B277", "Jaket Hoodie", "Baju", 70000, 25};
		daftar[277] = {"B278", "Celana Jeans", "Baju", 80000, 20};
		daftar[278] = {"B279", "Kaos Lengan Panjang", "Baju", 30000, 35};
		daftar[279] = {"B280", "Kemeja Flanel", "Baju", 50000, 28};
		daftar[280] = {"B281", "Sweater", "Baju", 60000, 22};
		daftar[281] = {"B282", "Rok Pendek", "Baju", 40000, 18};
		daftar[282] = {"B283", "Celana Bahan", "Baju", 45000, 26};
		daftar[283] = {"B284", "Kaos Oblong", "Baju", 20000, 50};
		daftar[284] = {"B285", "Daster Batik Ibu Rumah Tangga", "Baju", 35000, 50};
		daftar[285] = {"B286", "Celana Pendek Olahraga Pria", "Baju", 40000, 45};
		daftar[286] = {"B287", "Legging Wanita Hitam Polos", "Baju", 30000, 55};
		daftar[287] = {"B288", "Piyama Set Anak Laki-laki", "Baju", 60000, 30};
		daftar[288] = {"B289", "Tank Top Wanita Tali Kecil", "Baju", 20000, 65};
		daftar[289] = {"B290", "Sarung Tenun Gajah Duduk", "Baju", 55000, 38};
		daftar[290] = {"B291", "Baju Koko Lengan Panjang Putih", "Baju", 75000, 28};
		daftar[291] = {"B292", "Gamis Syari Wanita Modern", "Baju", 150000, 20};
		daftar[292] = {"B293", "Kaos Kaki Sekolah Putih Panjang", "Baju", 10000, 80};
		daftar[293] = {"B294", "Topi Baseball Polos Dewasa", "Baju", 25000, 60};
		daftar[294] = {"B295", "Jaket Parasut Anti Air", "Baju", 90000, 25};
		daftar[295] = {"B296", "Celana Training Jogger Pria", "Baju", 65000, 33};
		daftar[296] = {"B297", "Rok Plisket Panjang Wanita", "Baju", 70000, 29};
		daftar[297] = {"B298", "Singlet Pria Rider Putih", "Baju", 22000, 70};
		daftar[298] = {"B299", "Baju Renang Anak Perempuan", "Baju", 85000, 22};
	
		// ATK (Alat Tulis Kantor)
		daftar[299] = {"B300", "Stapler", "ATK", 15000, 40};
		daftar[300] = {"B301", "Isi Staples", "ATK", 5000, 60};
		daftar[301] = {"B302", "Lakban", "ATK", 8000, 55};
		daftar[302] = {"B303", "Gunting", "ATK", 10000, 50};
		daftar[303] = {"B304", "Cutter", "ATK", 9000, 45};
		daftar[304] = {"B305", "Kertas HVS", "ATK", 30000, 30};
		daftar[305] = {"B306", "Map Kertas", "ATK", 2000, 70};
		daftar[306] = {"B307", "Lem Kertas", "ATK", 4000, 65};
		daftar[307] = {"B308", "Papan Klip", "ATK", 12000, 25};
		daftar[308] = {"B309", "Spidol Whiteboard", "ATK", 7000, 35};
		daftar[309] = {"B310", "Pulpen Standard AE7 Hitam Lusin", "ATK", 20000, 80};
		daftar[310] = {"B311", "Pensil 2B Faber Castell Isi 12", "ATK", 30000, 70};
		daftar[311] = {"B312", "Penghapus Steadler Putih Kecil", "ATK", 3000, 150};
		daftar[312] = {"B313", "Penggaris Besi 30cm Butterfly", "ATK", 8000, 60};
		daftar[313] = {"B314", "Buku Tulis Sinar Dunia Isi 38 Lembar", "ATK", 2500, 200};
		daftar[314] = {"B315", "Stabilo Boss Original Kuning", "ATK", 7000, 90};
		daftar[315] = {"B316", "Tipe-X Kertas Joyko Roll", "ATK", 5000, 100};
		daftar[316] = {"B317", "Binder Clip Kenko No.107 Isi 12", "ATK", 6000, 85};
		daftar[317] = {"B318", "Kertas Origami Asturo Warna Warni", "ATK", 10000, 55};
		daftar[318] = {"B319", "Sampul Buku Plastik Mika Roll", "ATK", 12000, 50};
		daftar[319] = {"B320", "Lem Stik UHU Kecil", "ATK", 4000, 120};
		daftar[320] = {"B321", "Buku Gambar A4 Sinar Dunia", "ATK", 8000, 75};
		daftar[321] = {"B322", "Pensil Warna Faber Castell Classic 12", "ATK", 35000, 40};
		daftar[322] = {"B323", "Rautan Pensil Putar Kenko", "ATK", 9000, 65};
		daftar[323] = {"B324", "Sticky Notes Post-It Kuning", "ATK", 11000, 58};
		daftar[324] = {"B325", "Buku Ekspedisi Kecil", "ATK", 7000, 82};
		daftar[325] = {"B326", "Kalkulator Scientific Casio FX-991ID", "ATK", 250000, 15};
		daftar[326] = {"B327", "Jangka Set Matematika Joyko", "ATK", 15000, 48};
		daftar[327] = {"B328", "Kertas Manila Putih Gulung", "ATK", 5000, 95};
		daftar[328] = {"B329", "Papan Jalan Plastik Folio", "ATK", 10000, 63};
		daftar[329] = {"B330", "Cutter Besar Kenko L-500", "ATK", 12000, 53};
		daftar[330] = {"B331", "Isi Cutter L-150 Kenko", "ATK", 8000, 77};
		daftar[331] = {"B332", "Spidol Permanen Snowman Hitam", "ATK", 4000, 110};
		daftar[332] = {"B333", "Tinta Stempel Yamura Biru", "ATK", 9000, 61};
		daftar[333] = {"B334", "Bantalan Stempel Hero Kecil", "ATK", 7000, 81};
		daftar[334] = {"B335", "Map Snelhecter Plastik Bening", "ATK", 3000, 130};
		daftar[335] = {"B336", "Double Tape Foam Nachi", "ATK", 6000, 89};
		daftar[336] = {"B337", "Kertas Stiker HVS A4 Glossy", "ATK", 15000, 46};
		daftar[337] = {"B338", "Buku Kas Folio", "ATK", 20000, 42};
		daftar[338] = {"B339", "Klip Kertas Trigonal No.3 Joyko", "ATK", 5000, 92};
		
		// Bumbu Dapur
		daftar[339] = {"B340", "Bawang Putih", "Bumbu dapur", 20000, 50};
		daftar[340] = {"B341", "Bawang Merah", "Bumbu dapur", 18000, 55};
		daftar[341] = {"B342", "Cabai Merah", "Bumbu dapur", 25000, 40};
		daftar[342] = {"B343", "Ketumbar", "Bumbu dapur", 6000, 60};
		daftar[343] = {"B344", "Kunyit", "Bumbu dapur", 4000, 65};
		daftar[344] = {"B345", "Jahe", "Bumbu dapur", 5000, 50};
		daftar[345] = {"B346", "Lengkuas", "Bumbu dapur", 4000, 45};
		daftar[346] = {"B347", "Merica Bubuk", "Bumbu dapur", 10000, 30};
		daftar[347] = {"B348", "Garam Halus", "Bumbu dapur", 3000, 80};
		daftar[348] = {"B349", "Penyedap Rasa", "Bumbu dapur", 5000, 75};
		daftar[349] = {"B350", "Bawang Bombay Utuh 500g", "Bumbu dapur", 12000, 40};
		daftar[350] = {"B351", "Cabai Rawit Merah 100g", "Bumbu dapur", 10000, 35};
		daftar[351] = {"B352", "Daun Salam Segar Ikat", "Bumbu dapur", 3000, 70};
		daftar[352] = {"B353", "Sereh Batang Ikat", "Bumbu dapur", 4000, 65};
		daftar[353] = {"B354", "Kemiri Pecah 100g", "Bumbu dapur", 8000, 50};
		daftar[354] = {"B355", "Kayu Manis Batang Pack", "Bumbu dapur", 7000, 55};
		daftar[355] = {"B356", "Cengkeh Kering Pack", "Bumbu dapur", 9000, 45};
		daftar[356] = {"B357", "Pala Bubuk Sachet", "Bumbu dapur", 5000, 60};
		daftar[357] = {"B358", "Asam Jawa Tanpa Biji", "Bumbu dapur", 6000, 58};
		daftar[358] = {"B359", "Ebi Kering Sangrai", "Bumbu dapur", 15000, 30};
		daftar[359] = {"B360", "Kaldu Jamur Totole Sachet", "Bumbu dapur", 3000, 80};
		daftar[360] = {"B361", "Bumbu Racik Nasi Goreng", "Bumbu dapur", 2000, 100};
		daftar[361] = {"B362", "Bumbu Instan Bamboe Soto Ayam", "Bumbu dapur", 7000, 42};
		daftar[362] = {"B363", "Jeruk Nipis 250g", "Bumbu dapur", 5000, 63};
		daftar[363] = {"B364", "Daun Jeruk Segar Ikat", "Bumbu dapur", 3000, 72};
		daftar[364] = {"B365", "Kencur Segar 100g", "Bumbu dapur", 6000, 53};
		daftar[365] = {"B366", "Jintan Bubuk Sachet", "Bumbu dapur", 4000, 67};
		daftar[366] = {"B367", "Kapulaga Putih Pack", "Bumbu dapur", 10000, 38};
		daftar[367] = {"B368", "Bunga Lawang (Star Anise) Pack", "Bumbu dapur", 12000, 33};
		daftar[368] = {"B369", "Oregano Kering Botol Kecil", "Bumbu dapur", 18000, 28};
		
		// Buah-buahan
		daftar[369] = {"B370", "Apel", "Buah-buahan", 15000, 60};
		daftar[370] = {"B371", "Jeruk", "Buah-buahan", 12000, 70};
		daftar[371] = {"B372", "Pisang", "Buah-buahan", 10000, 80};
		daftar[372] = {"B373", "Anggur", "Buah-buahan", 25000, 40};
		daftar[373] = {"B374", "Semangka", "Buah-buahan", 20000, 35};
		daftar[374] = {"B375", "Melon", "Buah-buahan", 18000, 30};
		daftar[375] = {"B376", "Pepaya", "Buah-buahan", 9000, 45};
		daftar[376] = {"B377", "Mangga", "Buah-buahan", 13000, 50};
		daftar[377] = {"B378", "Nanas", "Buah-buahan", 8000, 55};
		daftar[378] = {"B379", "Kiwi", "Buah-buahan", 27000, 25};
		daftar[379] = {"B380", "Pir Xiang Li Manis 1kg", "Buah-buahan", 20000, 40};
		daftar[380] = {"B381", "Salak Pondoh Super 1kg", "Buah-buahan", 18000, 45};
		daftar[381] = {"B382", "Lengkeng Bangkok 500g", "Buah-buahan", 22000, 35};
		daftar[382] = {"B383", "Strawberry Pack Kecil", "Buah-buahan", 15000, 50};
		daftar[383] = {"B384", "Naga Merah Super 1 Buah", "Buah-buahan", 17000, 38};
		daftar[384] = {"B385", "Alpukat Mentega Matang 1kg", "Buah-buahan", 28000, 30};
		daftar[385] = {"B386", "Belimbing Madu Manis 500g", "Buah-buahan", 13000, 52};
		daftar[386] = {"B387", "Jambu Biji Merah 1kg", "Buah-buahan", 12000, 58};
		daftar[387] = {"B388", "Markisa Asam Manis 500g", "Buah-buahan", 16000, 42};
		daftar[388] = {"B389", "Sirsak Matang Besar 1 Buah", "Buah-buahan", 19000, 33};
		daftar[389] = {"B390", "Kurma Ajwa Premium Pack", "Buah-buahan", 70000, 20};
		daftar[390] = {"B391", "Delima Merah Segar", "Buah-buahan", 25000, 28};
		daftar[391] = {"B392", "Blewah Segar Utuh", "Buah-buahan", 10000, 60};
		daftar[392] = {"B393", "Timun Suri Matang", "Buah-buahan", 9000, 62};
		daftar[393] = {"B394", "Manggis Ratu Manis 1kg", "Buah-buahan", 30000, 25};
		daftar[394] = {"B395", "Rambutan Binjai Rapiah 1 Ikat", "Buah-buahan", 15000, 47};
		daftar[395] = {"B396", "Duku Palembang Manis 1kg", "Buah-buahan", 23000, 31};
		daftar[396] = {"B397", "Cempedak Matang Harum", "Buah-buahan", 27000, 26};
		daftar[397] = {"B398", "Kesemek Manis Renyah", "Buah-buahan", 14000, 49};
		daftar[398] = {"B399", "Sawo Manis Legit 1kg", "Buah-buahan", 11000, 56};
		
		// Frozen Food
		daftar[399] = {"B400", "Nugget Ayam", "Frozen food", 25000, 40};
		daftar[400] = {"B401", "Sosis Sapi", "Frozen food", 23000, 50};
		daftar[401] = {"B402", "Bakso Ikan", "Frozen food", 20000, 60};
		daftar[402] = {"B403", "Dimsum Ayam", "Frozen food", 28000, 30};
		daftar[403] = {"B404", "Kentang Beku", "Frozen food", 22000, 35};
		daftar[404] = {"B405", "Chicken Karaage", "Frozen food", 30000, 25};
		daftar[405] = {"B406", "Tempura", "Frozen food", 27000, 28};
		daftar[406] = {"B407", "Tahu Bakso", "Frozen food", 18000, 45};
		daftar[407] = {"B408", "Lumpia Frozen", "Frozen food", 20000, 32};
		daftar[408] = {"B409", "Risol Mayo", "Frozen food", 24000, 38};
		daftar[409] = {"B410", "Bakpao Mini Coklat Frozen", "Frozen food", 18000, 40};
		daftar[410] = {"B411", "Siomay Ikan Frozen Fiesta", "Frozen food", 26000, 35};
		daftar[411] = {"B412", "Cireng Salju Original Frozen", "Frozen food", 15000, 50};
		daftar[412] = {"B413", "Pempek Lenjer Frozen Palembang", "Frozen food", 30000, 30};
		daftar[413] = {"B414", "Pizza Mini Frozen Topping Sosis", "Frozen food", 22000, 38};
		daftar[414] = {"B415", "Udang Kupas Beku 250g", "Frozen food", 40000, 25};
		daftar[415] = {"B416", "Daging Ayam Giling Beku 500g", "Frozen food", 35000, 28};
		daftar[416] = {"B417", "Kulit Pangsit Frozen Tipis", "Frozen food", 10000, 60};
		daftar[417] = {"B418", "Edamame Kupas Beku", "Frozen food", 20000, 42};
		daftar[418] = {"B419", "Donat Kentang Frozen Isi Coklat", "Frozen food", 28000, 33};
		daftar[419] = {"B420", "Roti Maryam Original Frozen", "Frozen food", 23000, 37};
		daftar[420] = {"B421", "Mantau Goreng Frozen Polos", "Frozen food", 19000, 44};
		daftar[421] = {"B422", "Sayuran Campur Beku (Wortel, Buncis, Jagung)", "Frozen food", 17000, 47};
		daftar[422] = {"B423", "Cumi Ring Tepung Frozen", "Frozen food", 38000, 26};
		daftar[423] = {"B424", "Otak-otak Ikan Bakar Frozen", "Frozen food", 24000, 36};
		daftar[424] = {"B425", "Spring Roll Sayur Frozen", "Frozen food", 21000, 39};
		daftar[425] = {"B426", "Kebab Mini Daging Sapi Frozen", "Frozen food", 32000, 29};
		daftar[426] = {"B427", "French Fries Crinkle Cut Golden Farm", "Frozen food", 25000, 32};
		daftar[427] = {"B428", "Pisang Coklat Lumer Frozen", "Frozen food", 20000, 41};
		daftar[428] = {"B429", "Daging Sapi Slice US Beef Yakiniku", "Frozen food", 60000, 20};
	
		//Produk Bayi
		daftar[429] = {"B430", "Popok Bayi Merries Pants M", "Produk bayi", 70000, 30};
		daftar[430] = {"B431", "Susu Formula SGM Eksplor 1+ Madu", "Produk bayi", 80000, 25};
		daftar[431] = {"B432", "Minyak Telon My Baby Plus", "Produk bayi", 20000, 60};
		daftar[432] = {"B433", "Bedak Bayi Cussons Mild & Gentle", "Produk bayi", 15000, 70};
		daftar[433] = {"B434", "Tisu Basah Bayi Mitu Baby Wipes", "Produk bayi", 12000, 80};
		daftar[434] = {"B435", "Sabun Mandi Bayi Zwitsal Classic", "Produk bayi", 25000, 50};
		daftar[435] = {"B436", "Shampo Bayi Johnson's Active Kids", "Produk bayi", 22000, 55};
		daftar[436] = {"B437", "Bubur Bayi Sun Beras Merah", "Produk bayi", 10000, 65};
		daftar[437] = {"B438", "Botol Susu Pigeon Peristaltic", "Produk bayi", 40000, 35};
		daftar[438] = {"B439", "Dot Bayi Huki Orthodontic", "Produk bayi", 18000, 75};
		daftar[439] = {"B440", "Baby Oil Johnson's Regular", "Produk bayi", 17000, 68};
		daftar[440] = {"B441", "Popok Sweety Silver Pants L", "Produk bayi", 75000, 28};
		daftar[441] = {"B442", "Sikat Gigi Bayi Pigeon Step 1", "Produk bayi", 30000, 42};
		daftar[442] = {"B443", "Diaper Rash Cream Sleek Baby", "Produk bayi", 28000, 40};
		daftar[443] = {"B444", "Cologne Bayi Zwitsal Eau De Toilette", "Produk bayi", 23000, 47};
		daftar[444] = {"B445", "Perlak Bayi Motif Lucu", "Produk bayi", 35000, 33};
		daftar[445] = {"B446", "Gunting Kuku Bayi Chicco", "Produk bayi", 25000, 44};
		daftar[446] = {"B447", "Termometer Digital Bayi Rossmax", "Produk bayi", 60000, 22};
		daftar[447] = {"B448", "Teether Bayi Bentuk Buah", "Produk bayi", 15000, 72};
		daftar[448] = {"B449", "Mainan Rattle Bayi Set", "Produk bayi", 50000, 29};
		daftar[449] = {"B450", "Selimut Bayi Carter's Fleece", "Produk bayi", 80000, 20};
		daftar[450] = {"B451", "Topi Bayi Katun Halus", "Produk bayi", 20000, 58};
		daftar[451] = {"B452", "Kaos Kaki Bayi Anti Slip", "Produk bayi", 12000, 78};
		daftar[452] = {"B453", "Pembersih Botol Susu Sleek", "Produk bayi", 19000, 51};
		daftar[453] = {"B454", "Sterilizer Botol IQ Baby", "Produk bayi", 150000, 12};
		daftar[454] = {"B455", "Makanan Ringan Bayi Promina Puffs", "Produk bayi", 13000, 61};
		daftar[455] = {"B456", "Losion Anti Nyamuk Bayi Zwitsal", "Produk bayi", 26000, 46};
		daftar[456] = {"B457", "Empeng Bayi Philips Avent", "Produk bayi", 45000, 31};
		daftar[457] = {"B458", "Deterjen Pakaian Bayi Sleek", "Produk bayi", 30000, 37};
		daftar[458] = {"B459", "Tas Perlengkapan Bayi Dialogue", "Produk bayi", 120000, 18};
		daftar[459] = {"B460", "Popok Kain Clodi Modern", "Produk bayi", 55000, 26};
		daftar[460] = {"B461", "Biskuit Bayi Milna Original", "Produk bayi", 11000, 66};
		daftar[461] = {"B462", "Baby Walker Family Standard", "Produk bayi", 250000, 10};
		daftar[462] = {"B463", "Susu Ibu Hamil Prenagen Mommy", "Produk bayi", 70000, 23};
		daftar[463] = {"B464", "Pumping ASI Manual Pigeon", "Produk bayi", 200000, 14};
		daftar[464] = {"B465", "Kain Bedong Bayi Libby", "Produk bayi", 60000, 27};
		
        jumlahBarang = 465; 
    }

    void loginAdmin() {
        string u; 
		string p;
        
        system("cls");
        cout << "\n======[Login Admin]=======\n";
		cout << "Username: "; 
		cin >> u;
        cout << "Password: "; 
		cin >> p;
        if(u == userAdmin && p == passAdmin) 
			menuAdmin();
		else { 
			cout << "Login gagal!" << endl; 
			system("pause"); 
		}
    }

    void loginKasir() {
        string u; 
		string p;
        
        system("cls");
        cout << "\n=====[Login Kasir]======\n";
		cout << "Username: "; 
		cin >> u;
        cout << "Password: "; 
		cin >> p;
        if(u == userKasir && p == passKasir) 
			menuKasir();
        else { 
			cout << "Login gagal!" << endl; 
			system("pause"); 
		}
    }

    void menuAdmin() {
        int pilih;
        
        do {
            system("cls");
            cout << "\n=====[Menu Admin]=====\n";
            cout << "1. Lihat  Daftar Barang" << endl;
            cout << "2. Tambah Barang" << endl;
            cout << "3. Edit Barang" << endl;
            cout << "4. Hapus Barang" << endl;
            cout << "5. Cari Barang" << endl;
            cout << "6. Cari Kategori" << endl;
            cout << "7. Laporan Penjualan" << endl;
            cout << "8. Logout" << endl;
            cout << "----------------------------" << endl;
            cout << "Pilihan: ";
            cin >> pilih;
            switch (pilih) {
                case 1: 
					lihatBarang(); 
					break;
                case 2: 	
					tambahBarang(); 
					break;
                case 3: 
					editBarang(); 
					break;
                case 4: 
					hapusBarang(); 
					break;
				case 5:
					cariBarang(); 
					break;
                case 6: 
					cariKategori(); 
					break;
                case 7: 
					laporan(); 
					break; 
            }
        } while (pilih != 8);
    }
    
    void menuKasir() {
	    int pilihan;
	    
	    do {
	        system("cls");
	        cout << "\n=====[Menu Kasir]=====\n";
	        cout << " 1. Lihat Daftar Barang" << endl;
	        cout << " 2. Beli Barang" << endl;
	        cout << " 3. Lihat Barang" << endl;
	        cout << " 4. Cari Barang" << endl;
	        cout << " 5. Cari Kategori" << endl;
	        cout << " 6. Hapus Barang" << endl;
	        cout << " 7. Batalkan Barang" << endl;
	        cout << " 8. Bayar Barang" << endl;
	        cout << " 9. Home" << endl;
	        cout << "--------------------------" << endl;
	        cout << "Masukkan pilihan: ";
	        cin >> pilihan;

	        switch (pilihan) {
	            case 1: 
					lihatBarang(); 
					break;
	            case 2: 
					beliBarang(); 
					break;
	            case 3: 
					lihatPesanan(); 
					break;
				case 4:
					cariBarang(); 
					break;
				case 5: 
					cariKategori(); 
					break; 
				case 6:
					hapusPesanan(); 
					break;
	            case 7: 
					batalkanPesanan(); 
					break;
	            case 8: 
					bayarPesanan(); 
					break;
	        }
	    } while (pilihan != 9);
	}

   void beliBarang() {
	    int index;
		int jumlah;
	    char lagi;
	    
	    do {
	        system("cls");
	        lihatBarang();
	        cout << "\nMasukkan nomor barang yang ingin dipesan: ";
	        cin >> index;
	        if (index < 1 || index > jumlahBarang) {
	            cout << "Barang tidak ditemukan." << endl; 
				system("pause"); 
				return;
	        }
	        cout << "Jumlah: "; 
			cin >> jumlah;
			
	        if (jumlah > daftar[index - 1].stok) {
	            cout << "Stok tidak cukup!" << endl; 
				system("pause"); 
				return;
	        }
	
	        transaksi[jumlahTransaksi].nama = daftar[index - 1].nama;
	        transaksi[jumlahTransaksi].jumlah = jumlah;
	        transaksi[jumlahTransaksi].hargaTotal = jumlah * daftar[index - 1].harga;
	        daftar[index - 1].stok -= jumlah;
	        
	        for (int j = 0; j < jumlahBarang; j++) {
			    if (daftar[j].nama == daftar[index - 1].nama) {
			        jumlahDibeli[j] += jumlah;
			        break;
			    }
			}
	        jumlahTransaksi++;
	
	        cout << "Tambah barang lagi? (y/n): ";
	        cin >> lagi;
	        
	    } while (lagi == 'y' || lagi == 'Y');
	}
	
	void lihatPesanan() {
	    system("cls");
	    if (jumlahTransaksi == 0) {
	        cout << "Belum ada pesanan yang dibuat." << endl;
	    } else {
	        cout << "===== PESANAN ANDA =====\n";
	        double total = 0;
	        for (int i = 0; i < jumlahTransaksi; i++) {
	            cout << i + 1 << ". " << transaksi[i].nama
	                 << " x" << transaksi[i].jumlah
	                 << " = Rp" << fixed << setprecision(0) << transaksi[i].hargaTotal << endl;
	            total += transaksi[i].hargaTotal;
	        }
	        cout << "---------------------------\n";
	        cout << "Total Belanja: Rp" << fixed << setprecision(0) << total << endl;
	    }
	    system("pause");
	}
	
	void hapusPesanan() {
	    if (jumlahTransaksi == 0) {
	        cout << "Belum ada pesanan yang bisa dihapus." << endl;
	        system("pause");
	        return;
	    }
	
	    system("cls");
	    cout << "======= HAPUS PESANAN =======\n";
	    for (int i = 0; i < jumlahTransaksi; i++) {
	        cout << i + 1 << ". " << transaksi[i].nama
	             << " x" << transaksi[i].jumlah
	             << " = Rp" << transaksi[i].hargaTotal << endl;
	    }
	
	    int hapusIndex;
	    cout << "Masukkan nomor pesanan yang ingin dihapus: ";
	    cin >> hapusIndex;
	
	    if (hapusIndex < 1 || hapusIndex > jumlahTransaksi) {
	        cout << "Nomor tidak valid." << endl;
	        system("pause");
	        return;
	    }
	
	    for (int i = 0; i < jumlahBarang; i++) {
	        if (daftar[i].nama == transaksi[hapusIndex - 1].nama) {
	            daftar[i].stok += transaksi[hapusIndex - 1].jumlah;
	            break;
	        }
	    }
	
	    for (int i = hapusIndex - 1; i < jumlahTransaksi - 1; i++) {
	        transaksi[i] = transaksi[i + 1];
	    }
	
	    jumlahTransaksi--;
	    cout << "Pesanan berhasil dihapus." << endl;
	    system("pause");
	}

	
	void batalkanPesanan() {
	    if (jumlahTransaksi == 0) {
	        cout << "Tidak ada pesanan yang bisa dibatalkan." << endl;
	    } else {
	        for (int i = 0; i < jumlahTransaksi; i++) {
	            for (int j = 0; j < jumlahBarang; j++) {
	                if (transaksi[i].nama == daftar[j].nama) {
	                    daftar[j].stok += transaksi[i].jumlah;
	                    break;
	                }
	            }
	        }
	
	        jumlahTransaksi = 0;
	        cout << "Semua pesanan telah dibatalkan dan stok dikembalikan." << endl;
	    }
	    system("pause");
	}

	void bayarPesanan() {
	    if (jumlahTransaksi == 0) {
	        cout << "Tidak ada pesanan untuk dibayar." << endl;
	        system("pause");
	        return;
	    }
	
	    system("cls");
	    double total = 0;
	    char member;
	    bool isMember = false;
	
	    cout << "===== BAYAR PESANAN =====\n";
	    cout << "-----------------------------------------\n";
	    cout << "===== DAFTAR PESANAN ANDA =====\n";
	    cout << "-----------------------------------------\n";
	
	    for (int i = 0; i < jumlahTransaksi; i++) {
	        cout << i + 1 << ". " << transaksi[i].nama
	             << " - Rp" << transaksi[i].hargaTotal
	             << " x " << transaksi[i].jumlah << endl;
	        total += transaksi[i].hargaTotal;
	    }
	
	    cout << "-----------------------------------------\n";
	    cout << "Total Harga Sebelum Diskon: Rp" << total << endl;
	
	    cout << "\nApakah Anda member Manna Kampus? (y/n): ";
	    cin >> member;
	
	    if (member == 'y' || member == 'Y') {
	        cout << "Anda mendapatkan diskon 10% sebagai member!" << endl;
	        total *= 0.9;
	        isMember = true;
	    } else {
	        char daftar;
	        cout << "Ingin daftar jadi member sekarang dan dapat diskon 10%? (y/n): ";
	        cin >> daftar;
	        if (daftar == 'y' || daftar == 'Y') {
	            cout << "Selamat! Anda sekarang terdaftar sebagai member." << endl;
	            total *= 0.9;
	            isMember = true;
	        } else {
	            cout << "Anda tetap belanja sebagai non-member." << endl;
	        }
	    }
	
	    cout << "\nTotal Harga Setelah Diskon : Rp" << total << endl;
	    cout << "-----------------------------------------\n";
	
	    int metode;
	    cout << "Pilih Metode Pembayaran:" << endl;
	    cout << "1. Tunai" << endl;
	    cout << "2. Transfer Bank" << endl;
	    cout << "3. QRIS" << endl;
	    cout << "Masukkan pilihan Anda: ";
	    cin >> metode;
	
	    double bayar = 0, kembalian = 0;
	    string metodeStr;
	
	    switch (metode) {
	        case 1:
	            metodeStr = "Tunai";
	            while (bayar < total) {
	                double tambah;
	                cout << "Masukkan jumlah uang yang dibayarkan: Rp";
	                cin >> tambah;
	                bayar += tambah;
	                if (bayar < total) {
	                    cout << "Uang yang dibayarkan kurang." << endl;
						cout << "Silakan tambahkan pembayaran." << endl;
	                }
	            }
	            kembalian = bayar - total;
	            break;
	
	        case 2:
	            metodeStr = "Transfer Bank";
	            cout << "Silakan transfer ke rekening BCA 1234567890 a.n. Manna Kampus" << endl;
	            bayar = total;
	            break;
	
	        case 3:
	            metodeStr = "QRIS";
	            cout << "Silakan scan QRIS yang tersedia untuk melanjutkan pembayaran." << endl;
	            bayar = total;
	            break;
	
	        default:
	            cout << "Metode tidak valid." << endl;
	            system("pause");
	            return;
	    }
	
	    for (int i = 0; i < jumlahTransaksi; i++) {
	        totalPendapatan += transaksi[i].hargaTotal;
	    }
	
	    system("cls");
	    cout << "======= STRUK PEMBAYARAN =======\n";
	    for (int i = 0; i < jumlahTransaksi; i++) {
	        cout << i + 1 << ". " << transaksi[i].nama
	             << " x" << transaksi[i].jumlah
	             << " = Rp" << transaksi[i].hargaTotal << endl;
	    }
	    cout << "--------------------------------\n";
	    cout << "Total Harga Pesanan Anda : Rp" << total << endl;
	    cout << "Metode Pembayaran        : " << metodeStr << endl;
	    if (isMember) {
	        cout << "(Diskon Member 10% telah diterapkan)\n";
	    }
	    if (metode == 1) {
	        cout << "Total Uang Dibayar       : Rp" << bayar << endl;
	        cout << "Kembalian                : Rp" << kembalian << endl;
	    }
	    cout << "=========================================\n";
	    cout << "Terima kasih telah berbelanja di Manna Kampus!\n";
	
	    jumlahTransaksi = 0;
	    system("pause");
	}

    void lihatBarang() {
    	system("cls");
        cout << "\n===== DAFTAR BARANG =====\n";
        for (int i = 0; i < jumlahBarang; ++i) {
            cout << i+1 << ". ";
			cout << "Nama : " << daftar[i].nama << endl; 
			cout << "Kategori: " << daftar[i].kategori << endl;
			cout << "Harga: " << daftar[i].harga << endl;
			cout << "Stok: " << daftar[i].stok << endl;
        }
        system("pause");
    }

    void tambahBarang() {
        cout << "\nMasukkan nama barang: "; 
		cin.ignore(); 
		getline(cin, daftar[jumlahBarang].nama);
        cout << "Kategori: "; 
		getline(cin, daftar[jumlahBarang].kategori);
        cout << "Harga: "; 
		cin >> daftar[jumlahBarang].harga;
        cout << "Stok: "; 
		cin >> daftar[jumlahBarang].stok;
        daftar[jumlahBarang].kode = "B" + to_string(100 + jumlahBarang);
        jumlahBarang++;
        cout << "Barang berhasil ditambahkan!" << endl; 
		system("pause");
    }

    void editBarang() {
        lihatBarang();
        int idx;
        
        cout << "\nNomor barang yang ingin diedit: "; cin >> idx;
        if (idx < 1 || idx > jumlahBarang) return;
        cin.ignore();
        cout << "Nama baru: "; 
		getline(cin, daftar[idx-1].nama);
        cout << "Kategori baru: "; 
		getline(cin, daftar[idx-1].kategori);
        cout << "Harga baru: "; 
		cin >> daftar[idx-1].harga;
        cout << "Stok baru: ";
		cin >> daftar[idx-1].stok;
        cout << "Data berhasil diubah!" << endl; 
		system("pause");
    }

    void hapusBarang() {
        lihatBarang();
        int idx;
        
        cout << "\nNomor barang yang ingin dihapus: "; 
		cin >> idx;
        if (idx < 1 || idx > jumlahBarang) return;
        for (int i = idx - 1; i < jumlahBarang - 1; ++i) {
            daftar[i] = daftar[i+1];
        }
        jumlahBarang--;
        cout << "Barang berhasil dihapus!" << endl; 
		system("pause");
    }
    
    void cariBarang() {
	    string keyword;
	    
	    system("cls");
	    cout << "===== CARI BARANG =====\n";
	    cout << "Masukkan nama atau kategori barang: ";
	    cin.ignore();
	    getline(cin, keyword);
	
	    bool ditemukan = false;
	    
	    cout << "\nHasil pencarian:\n";
	    for (int i = 0; i < jumlahBarang; i++) {
	        if (daftar[i].nama.find(keyword) != string::npos ||
	            daftar[i].kategori.find(keyword) != string::npos) {
	            cout << i + 1 << ". " << daftar[i].nama
	                 << " | " << daftar[i].kategori
	                 << " | Rp" << daftar[i].harga
	                 << " | Stok: " << daftar[i].stok << endl;
	            ditemukan = true;
	        }
	    }
	
	    if (!ditemukan) {
	        cout << "Barang tidak ditemukan." << endl;
	    }
	
	    system("pause");
	}

    void laporan() {
        system("cls");
        cout << "=====LAPORAN PENJUALAN=====" << endl;
        cout << "Daftar Barang & Jumlah Dibeli:\n";

        for (int i = 0; i < jumlahBarang; i++) {
            if (jumlahDibeli[i] > 0) {
                cout << i + 1 << ". " << daftar[i].nama << " - " << jumlahDibeli[i] << " kali" << endl;
            }
        }

        cout << "-----------------------------------------\n";
        cout << "Total Pemasukan : Rp" << fixed << setprecision(0) << totalPendapatan << endl;
        cout << "-----------------------------------------\n";
        system("pause");
    }
    
    void cariKategori() {
	    string kategori;
	    bool ditemukan = false;
		
		system("cls");
	    cout << "===== CARI BARANG BERDASARKAN KATEGORI =====\n";
	    cout << "Masukkan nama kategori : ";
	    cin.ignore();
	    getline(cin, kategori);
	
	    cout << "\nHasil pencarian kategori \"" << kategori << "\":" << endl;
	    for (int i = 0; i < jumlahBarang; i++) {
	        if (daftar[i].kategori == kategori) {
	            cout << i + 1 << ". " << daftar[i].nama
	                 << " | Rp" << daftar[i].harga
	                 << " | Stok: " << daftar[i].stok << endl;
	            ditemukan = true;
	        }
	    }
	
	    if (!ditemukan) {
	        cout << "Tidak ditemukan barang dalam kategori \"" << kategori << "\"." << endl;
	    }
	
	    system("pause");
	}
};

int main() {
    Swalayan app;
    app.iniBarang();
    app.start();
    return 0;
}
