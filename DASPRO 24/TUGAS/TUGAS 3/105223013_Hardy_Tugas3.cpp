#include <iostream>
#include <fstream>
using namespace std;

const int MAKS_BUKU = 100;

struct Book {
    char judul[100];
    char penulis[100];
    int tahunTerbit;
    char ISBN[20];
};

Book koleksiBuku[MAKS_BUKU];
int jumlahBuku = 0;

bool isSubString(const char* text, const char* keyword) {
    for (int i = 0; text[i] != '\0'; i++) {
        int j = 0;
        while (text[i + j] == keyword[j] && keyword[j] != '\0') {
            j++;
        }
        if (keyword[j] == '\0') return true;
    }
    return false;
}

bool isStringEqual(const char* a, const char* b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) return false;
        i++;
    }
    return (a[i] == '\0' && b[i] == '\0');
}

void tambahBuku() {
    if (jumlahBuku >= MAKS_BUKU) {
        cout << "Koleksi penuh!\n";
        return;
    }

    cout << "\n=== Tambah Buku ===\n";
    cout << "Judul       : "; cin.getline(koleksiBuku[jumlahBuku].judul, 100);
    cout << "Penulis     : "; cin.getline(koleksiBuku[jumlahBuku].penulis, 100);
    cout << "Tahun Terbit: "; cin >> koleksiBuku[jumlahBuku].tahunTerbit;
    cin.ignore(10000, '\n');
    cout << "ISBN        : "; cin.getline(koleksiBuku[jumlahBuku].ISBN, 20);

    jumlahBuku++;
    cout << "Buku berhasil ditambahkan!\n";
}

void simpanKeFile(const char* namaFile) {
    ofstream file(namaFile);
    for (int i = 0; i < jumlahBuku; i++) {
        file << koleksiBuku[i].judul << ","
             << koleksiBuku[i].penulis << ","
             << koleksiBuku[i].tahunTerbit << ","
             << koleksiBuku[i].ISBN << "\n";
    }
    file.close();
    cout << "Data berhasil disimpan ke file: " << namaFile << endl;
}

void urutkanBuku() {
    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = i + 1; j < jumlahBuku; j++) {
            if (koleksiBuku[i].tahunTerbit > koleksiBuku[j].tahunTerbit) {
                Book temp = koleksiBuku[i];
                koleksiBuku[i] = koleksiBuku[j];
                koleksiBuku[j] = temp;
            }
        }
    }
    cout << "Data buku berhasil diurutkan berdasarkan tahun terbit.\n";
}

void cariJudul(const char* keyword) {
    cout << "\nHasil pencarian berdasarkan judul: " << keyword << "\n";
    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (isSubString(koleksiBuku[i].judul, keyword)) {
            cout << koleksiBuku[i].judul << " oleh " << koleksiBuku[i].penulis
                 << " (" << koleksiBuku[i].tahunTerbit << "), ISBN: " << koleksiBuku[i].ISBN << "\n";
            ditemukan = true;
        }
    }
    if (!ditemukan) cout << "Buku tidak ditemukan.\n";
}

void cariISBN(const char* keyword) {
    cout << "\nHasil pencarian berdasarkan ISBN: " << keyword << "\n";
    bool ditemukan = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (isStringEqual(koleksiBuku[i].ISBN, keyword)) {
            cout << koleksiBuku[i].judul << " oleh " << koleksiBuku[i].penulis
                 << " (" << koleksiBuku[i].tahunTerbit << "), ISBN: " << koleksiBuku[i].ISBN << "\n";
            ditemukan = true;
            break;
        }
    }
    if (!ditemukan) cout << "Buku tidak ditemukan.\n";
}

void tampilkanBuku() {
    cout << "\n=== Daftar Buku ===\n";
    for (int i = 0; i < jumlahBuku; i++) {
        cout << koleksiBuku[i].judul << " oleh " << koleksiBuku[i].penulis
             << " (" << koleksiBuku[i].tahunTerbit << "), ISBN: " << koleksiBuku[i].ISBN << "\n";
    }
    if (jumlahBuku == 0) cout << "Belum ada buku.\n";
}

int main() {
    int pilihan;
    char keyword[100];

    do {
        cout << "\n=== Menu Perpustakaan Digital ===\n";
        cout << "1. Tambah Buku\n";
        cout << "2. Tampilkan Semua Buku\n";
        cout << "3. Simpan ke File\n";
        cout << "4. Urutkan Berdasarkan Tahun\n";
        cout << "5. Cari Buku (Judul)\n";
        cout << "6. Cari Buku (ISBN)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: tambahBuku(); break;
            case 2: tampilkanBuku(); break;
            case 3: simpanKeFile("data_buku.txt"); break;
            case 4: urutkanBuku(); break;
            case 5:
                cout << "Masukkan judul yang dicari: ";
                cin.getline(keyword, 100);
                cariJudul(keyword);
                break;
            case 6:
                cout << "Masukkan ISBN yang dicari: ";
                cin.getline(keyword, 100);
                cariISBN(keyword);
                break;
            case 0: cout << "Keluar dari program.\n"; break;
            default: cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 0);

    return 0;
}
