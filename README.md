# <h1 align="center">Laporan Praktikum Modul Linked List</h1>
<p align="center">Grahen Maryam Rompas Basiran</p>
<p align="center">2311110062</p>

## Dasar Teori
Linked list adalah struktur data linier yang terdiri dari sejumlah node yang saling terhubung melalui referensi atau pointer [1].
Terdapat dua algoritma Linked List, yaitu:

### Single Linked List
Single Linked List adalah suatu kumpulan elemen data (yang disebut sebagai node) dimana urutannya ditentukan oleh suatu pointer. Single Linked List hanya memiliki 1 petunjuk/pointer (NEXT).

### Double Linked List
Pada Double Linked List, struktur data atas tiap-tiap node memiliki rujukan pada node sebelum (PREV) dan berikutnya (NEXT). Sebagian algoritma membutuhkan taut ganda, contohnya sorting dan reverse traversing. Tiap node memiliki pointer yang menunjuk ke node sesudahnya dan pointer yang menunjuk ke node sebelumnya [2].

## Guided
### 1. PROGRAM SINGLE LINKED LIST NON-CIRCULAR
```C++
#include <iostream>
using namespace std;

///PROGRAM SINGLE LINKED LIST NON-CIRCULAR
//Deklarasi Struct Node
struct Node{
    //komponen/member
    int data;
    Node *next;
};
    Node *head;
    Node *tail;
//Inisialisasi Node
void init(){
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty(){
    if (head == NULL)
        return true;
    else
        return false;
}
//Tambah Depan
void insertDepan(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
}
//Tambah Belakang
void insertBelakang(int nilai){
    //Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true){
        head = tail = baru;
        tail->next = NULL;
    }
    else{
    tail->next = baru;
    tail = baru;
    }
}
//Hitung Jumlah List
int hitungList(){
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while( hitung != NULL ){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
//Tambah Tengah
void insertTengah(int data, int posisi){
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
            bantu = head;
            int nomor = 1;
        while( nomor < posisi - 1 ){
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
//Hapus Depan
void hapusDepan() {
    Node *hapus;
    if (isEmpty() == false){
        if (head->next != NULL){
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Belakang
void hapusBelakang() {
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false){
        if (head != tail){
            hapus = tail;
            bantu = head;
            while (bantu->next != tail){
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        delete hapus;
        }
        else{
            head = tail = NULL;
        }
    }
    else{
        cout << "List kosong!" << endl;
    }
}
//Hapus Tengah
void hapusTengah(int posisi){
    Node *hapus, *bantu, *bantu2;
    if( posisi < 1 || posisi > hitungList() ){
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if( posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else{
        int nomor = 1;
        bantu = head;
        while( nomor <= posisi ){
            if( nomor == posisi-1 ){
                bantu2 = bantu;
            }
            if( nomor == posisi ){
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
    delete hapus;
    }
}
//Ubah Depan
void ubahDepan(int data){
    if (isEmpty() == false){
        head->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Tengah
void ubahTengah(int data, int posisi){
    Node *bantu;
    if (isEmpty() == false){
        if( posisi < 1 || posisi > hitungList() ){
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if( posisi == 1){
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else{
            bantu = head;
            int nomor = 1;
            while (nomor < posisi){
                bantu = bantu->next;nomor++;
            }
            bantu->data = data;
        }
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Ubah Belakang
void ubahBelakang(int data){
    if (isEmpty() == false){
        tail->data = data;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
//Hapus List
void clearList(){
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
//Tampilkan List
void tampil(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == false){
        while (bantu != NULL){
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "List masih kosong!" << endl;
    }
}
int main(){
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7,2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();

    insertTengah(7,1);
    tampil();
    return 0;
}
```
### Penjelasan
Program diatas merupakan implementasi dari struktur data single linked list non-circular. Ia menyediakan fungsionalitas untuk melakukan operasi-operasi dasar pada linked list seperti menambah node baru di depan, tengah, atau belakang list, menghapus node dari depan, tengah, atau belakang list, serta mengubah nilai data pada node depan, tengah, atau belakang.

Program dimulai dengan mengimpor library iostream untuk memfasilitasi input/output. Kemudian, ia mendefinisikan sebuah struct bernama Node yang memiliki dua anggota, yaitu data untuk menyimpan nilai dan next untuk menyimpan alamat memori dari node berikutnya dalam list. Terdapat juga dua pointer global, head dan tail, yang masing-masing menunjuk ke node pertama dan terakhir dalam list.

Berbagai fungsi disediakan untuk melakukan operasi-operasi pada linked list, seperti inisialisasi list, pengecekan apakah list kosong, penambahan node baru, penghapusan node, pengubahan nilai node, penghitungan jumlah node, serta penampilan isi list.

Pada fungsi utama main(), berbagai operasi dasar pada linked list dipanggil secara berurutan untuk menguji implementasi yang telah dibuat.

### 2. PROGRAM DOUBLE LINKED LIST
```C++
#include <iostream>
using namespace std;

class Node {
    public:int data;
    Node* prev;
    Node* next;
};
class DoublyLinkedList {
        public:
        Node* head;
        Node* tail;
        DoublyLinkedList() {
            head = nullptr;
            tail = nullptr;
    }
    void push(int data) { //tambahdepan
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } 
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } 
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add " << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
```
### Penjelasan
Program diatas merupakan implementasi struktur data double linked list. Double linked list mirip dengan single linked list, namun setiap node memiliki dua pointer, satu menunjuk ke node sebelumnya (prev) dan satu lagi menunjuk ke node berikutnya (next).

Program diawali dengan mengimpor library iostream untuk memfasilitasi input/output. Kemudian, didefinisikan sebuah kelas bernama Node yang memiliki tiga atribut, yaitu data untuk menyimpan nilai, prev untuk menunjuk ke node sebelumnya, dan next untuk menunjuk ke node berikutnya. Selain itu, didefinisikan juga sebuah kelas DoublyLinkedList yang memiliki atribut head dan tail sebagai pointer ke node pertama dan terakhir dalam list.

Berbagai operasi pada double linked list diimplementasikan dalam bentuk metode atau fungsi, seperti menambah node baru di depan, menghapus node pertama, mengubah nilai data pada node tertentu, menghapus semua node, serta menampilkan isi list.

Pada fungsi utama main(), pengguna diberi pilihan untuk melakukan berbagai operasi seperti menambah data, menghapus data, mengubah data, menghapus semua data, menampilkan data, atau keluar dari program. Setiap pilihan akan diproses sesuai dengan operasi yang telah didefinisikan sebelumnya.

## Unguided
### 1. Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
![Screenshot]
```C++
#include <iostream>
#include <string>
using namespace std;

int Grahen_2311110062;

// Struktur Node untuk menyimpan data nama dan usia
struct Node {
    string nama;
    int usia;
    Node* next; // Pointer ke node berikutnya
};

// Deklarasi pointer head untuk awal list
Node* head = nullptr;

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR\n";
    cout << "=========================================\n";
    cout << "1. Tambah Depan\n";
    cout << "2. Tambah Belakang\n";
    cout << "3. Tambah Tengah\n";
    cout << "4. Ubah Depan\n";
    cout << "5. Ubah Belakang\n";
    cout << "6. Ubah Tengah\n";
    cout << "7. Hapus Depan\n";
    cout << "8. Hapus Belakang\n";
    cout << "9. Hapus Tengah\n";
    cout << "10. Hapus List\n";
    cout << "11. TAMPILKAN\n";
    cout << "0. KELUAR\n";
    cout << "Pilih Operasi : ";
}

// Fungsi untuk menambahkan node di depan list
void tambahDepan(){
    string nama;
    int usia;
    cout << "\nMasukkan Nama : ";
    cin >> nama;
    cout << "Masukkan Usia : ";
    cin >> usia;

    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;

    cout << "Data " << nama << " telah ditambahkan di depan list.\n";
}

// Fungsi untuk menambahkan node di belakang list
void tambahBelakang() {
    string nama;
    int usia;
    cout << "\nMasukkan Nama : ";
    cin >> nama;
    cout << "Masukkan Usia: ";
    cin >> usia;

    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Data " << nama << " telah ditambahkan di belakang list.\n";
}

// Fungsi untuk menambahkan node di tengah list
void tambahTengah() {
    string nama;
    int usia;
    int posisi;

    cout << "\nMasukkan Nama : ";
    cin >> nama;
    cout << "Masukkan Usia : ";
    cin >> usia;
    cout << "Masukkan Posisi : ";
    cin >> posisi;

    if (posisi <= 0){
        cout << "Posisi tidak valid. Data tidak ditambahkan.\n";
        return;
    }

    Node* newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;

    int count = 1;
    Node* prev = nullptr;
    Node* curr = head;

    while (curr != nullptr && count < posisi){
        prev = curr;
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Posisi melebihi jumlah node. Data tidak ditambahkan.\n";
    } else {
        newNode->next = curr;
        if (prev == nullptr) {
            head = newNode;
    } else {
        prev->next = newNode;
    }
    cout << "Data " << nama << " telah ditambahkan di tengah list (posisi " << posisi << ").\n";
    }
}

// Fungsi untuk mengubah data node di depan list
void ubahDepan() {
    if (head == nullptr) {
        cout << "List masih kosong. Tidak ada data yang diubah.\n";
        return;
    }

    string namaBaru;
    int usiaBaru;
    cout << "\nMasukkan Nama Baru : ";
    cin >> namaBaru;
    cout << "Masukkan Usia Baru : ";
    cin >> usiaBaru;

    head->nama = namaBaru;
    head->usia = usiaBaru;
    
    cout << "Data di depan telah diubah.\n";
}

// Fungsi untuk mengubah data node di belakang list
void ubahBelakang() {
    if (head == nullptr) {
        cout << "List masih kosong. Tidak ada data yang diubah.\n";
        return;
    }

    string namaBaru;
    int usiaBaru;
    cout << "\nMasukkan Nama Baru : ";
    cin >> namaBaru;
    cout << "Masukkan Usia Baru : ";
    cin >> usiaBaru;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->nama = namaBaru;
    temp->usia = usiaBaru;

    cout << "Data di belakang telah diubah.\n";
}

// Fungsi untuk mengubah data node di tengah list
void ubahTengah() {
    if (head == nullptr) {
        cout << "List masih kosong. Tidak ada data yang diubah.\n";
        return;
    }

    string namaBaru;
    int usiaBaru;
    int posisi;
    cout << "\nMasukkan Nama Baru : ";
    cin >> namaBaru;
    cout << "Masukkan Usia Baru : ";
    cin >> usiaBaru;
    cout << "Masukkan Posisi : ";
    cin >> posisi;

    if (posisi <= 0) {
        cout << "Posisi tidak valid. Tidak ada data yang diubah.\n";
        return;
    }

    int count = 1;
    Node* temp = head;
    while (temp != nullptr && count < posisi) {
        temp = temp->next;
        count++;
    }
    
    if (temp == nullptr) {
        cout << "Posisi melebihi jumlah node. Tidak ada data yang diubah.\n";
    } else {
        temp->nama = namaBaru;
        temp->usia = usiaBaru;
        cout << "Data pada posisi " << posisi << " telah diubah.\n";
    }
}

// Fungsi untuk menghapus node di depan list
void hapusDepan() {
    if (head == nullptr) {
        cout << "List masih kosong. Tidak ada data yang dihapus.\n";
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;

    cout << "Data di depan telah dihapus.\n";
}

// Fungsi untuk menghapus node di belakang list
void hapusBelakang() {
    if (head == nullptr) {
        cout << "List masih kosong. Tidak ada data yang dihapus.\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while (temp->next != nullptr) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == nullptr) {
        head = nullptr;
    } else {
        prev->next = nullptr;
    }

    delete temp;
    cout << "Data di belakang telah dihapus.\n";
}

// Fungsi untuk menghapus node di tengah list
void hapusTengah() {
    if (head == nullptr) {
        cout << "List masih kosong. Tidak ada data yang dihapus.\n";
        return;
    }

    int posisi;
    cout << "Masukkan Posisi yang akan dihapus: ";
    cin >> posisi;

    if (posisi <= 0) {
        cout << "Posisi tidak valid. Tidak ada data yang dihapus.\n";
        return;
    }

    Node* temp = head;
    Node* prev = nullptr;
    int count = 1;

    while (temp != nullptr && count < posisi) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Posisi melebihi jumlah node. Tidak ada data yang dihapus.\n";
    } else {
        if (prev == nullptr) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "Data pada posisi " << posisi << " telah dihapus.\n";
    }
}

// Fungsi untuk menghapus seluruh list
void hapusList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    cout << "Seluruh list telah dihapus.\n";
}

// Fungsi untuk menampilkan isi list
void tampilkan() {
    if (head == nullptr) {
        cout << "List kosong.\n";
    } else {
        cout << "Daftar Mahasiswa:\n";
        Node* temp = head;
        while (temp != nullptr) {
        cout << "Nama: " << temp->nama << ", Usia: " << temp->usia << endl;
        temp = temp->next;
        }
    }
}

// Fungsi utama
int main() {
    int choice;

    do {
        tampilkanMenu();
        cin >> choice;

    switch (choice) {
        case 1:
            tambahDepan();
            break;
        case 2:
            tambahBelakang();
            break;
        case 3:
            tambahTengah();
            break;
        case 4:
            ubahDepan();
            break;
        case 5:
            ubahBelakang();
            break;
        case 6:
            ubahTengah();
            break;
        case 7:
            hapusDepan();
            break;
        case 8:
            hapusBelakang();
            break;
        case 9:
            hapusTengah();
            break;
        case 10:
            hapusList();
            break;
        case 11:
            tampilkan();
            break;
        case 0:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Operasi tidak valid.\n";
        }
    } while (choice != 0);

    return 0;
}
```

#### Output:
![Screenshot]
### Penjelasan
Program diatas merupakan implementasi struktur data single linked list non-circular yang digunakan untuk menyimpan data nama dan usia mahasiswa. Program diawali dengan memanggil library iostream untuk memfasilitasi input/output dan library string untuk menggunakan tipe data string.

Didefinisikan sebuah struktur Node yang memiliki tiga atribut, yaitu nama (bertipe string) untuk menyimpan nama mahasiswa, usia (bertipe integer) untuk menyimpan usia mahasiswa, dan next sebagai pointer untuk menunjuk ke node berikutnya dalam list. Terdapat pula pointer head yang awalnya diinisialisasi dengan nullptr untuk menunjuk ke node pertama dalam list.

Program menampilkan menu operasi yang dapat dilakukan pada linked list, seperti menambah data di depan, belakang, atau tengah list, mengubah data, menghapus data, menampilkan data, dan keluar dari program.

Berbagai fungsi disediakan untuk melakukan operasi-operasi tersebut, seperti menambahkan node baru di depan atau belakang list dengan menerima input nama dan usia dari pengguna, menyisipkan node baru pada posisi tertentu, mengubah data pada node tertentu, menghapus node dari depan, belakang, atau posisi tertentu dalam list, menghapus seluruh node, serta menampilkan data nama dan usia dari setiap node.

Pada fungsi utama main(), program memberikan pilihan operasi kepada pengguna secara berulang hingga pengguna memilih untuk keluar dari program. Operasi yang dipilih akan diproses sesuai dengan fungsi yang telah didefinisikan sebelumnya.

### 2. Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.
![Screenshot]

```C++
#include <iostream>
#include <string>
#include <iomanip> // Untuk format data agar lebih rapih
using namespace std;

int Grahen_2311110062;

class Node {
public:
    string namaProduk;
    double harga; 
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(string namaProduk, double harga) {
        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }

        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }

        Node* temp = head;
        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
    }

    bool update(string oldNamaProduk, string newNamaProduk, double newHarga) {
        Node* current = head;
        while (current != nullptr) {
            if (current->namaProduk == oldNamaProduk) {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        cout << setw(20) << left << "Nama Produk" << "Harga" << endl;
        cout << setfill('-') << setw(30) << "-" << endl;
        cout << setfill(' ');
        while (current != nullptr) {
            cout << setw(20) << left << current->namaProduk << fixed << setprecision(3) << current->harga << endl;
            current = current->next;
        }
        cout << endl;
    }

    void insertAtPosition(string namaProduk, double harga, int position) {
        if (position < 1) {
            cout << "Posisi tidak tersedia" << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        if (position == 1) {
            newNode->next = head;
            newNode->prev = nullptr;
            if (head != nullptr) {
                head->prev = newNode;
            } else {
                tail = newNode;
            }
            head = newNode;
            return;
        }

        Node* current = head;
        int currentPosition = 1;
        while (currentPosition < position - 1 && current != nullptr) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            cout << "Posisi tidak tersedia" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }
        current->next = newNode;
    }

    void deleteAtPosition(int position) {
        if (head == nullptr || position < 1) {
            cout << "Posisi tidak tersedia" << endl;
            return;
        }

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* current = head;
        int currentPosition = 1;
        while (currentPosition < position && current != nullptr) {
            current = current->next;
            currentPosition++;
        }

        if (current == nullptr) {
            cout << "Posisi tidak tersedia" << endl;
            return;
        }

        if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
            return;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "Toko Skincare Purwokerto" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Update Data" << endl;
        cout << "4. Tambah Data Urutan Tertentu" << endl;
        cout << "5. Hapus Data Urutan Tertentu" << endl;
        cout << "6. Hapus Seluruh Data" << endl;
        cout << "7. Tampilkan Data" << endl;
        cout << "8. Exit" << endl;
        int choice;
        cout << "Pilih operasi: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string namaProduk;
                double harga;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                list.push(namaProduk, harga);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                string oldNamaProduk, newNamaProduk;
                double newHarga;
                cout << "Masuk nama produk yang akan di update: ";
                cin >> oldNamaProduk;
                cout << "Masukkan nama produk yang baru: ";
                cin >> newNamaProduk;
                cout << "Masukkan harga produk yang baru: ";
                cin >> newHarga;
                bool updated = list.update(oldNamaProduk, newNamaProduk, newHarga);
                if (!updated) {
                    cout << "Data tidak ada" << endl;
                }
                break;
            }
            case 4: {
                string namaProduk;
                double harga;
                int position;
                cout << "Masukkan nama produk: ";
                cin >> namaProduk;
                cout << "Masukkan harga: ";
                cin >> harga;
                cout << "Masukkan posisi: ";
                cin >> position;
                list.insertAtPosition(namaProduk, harga, position);
                break;
            }
            case 5: {
                int position;
                cout << "Masukkan posisi yang akan di hapus: ";
                cin >> position;
                list.deleteAtPosition(position);
                break;
            }
            case 6: {
                list.deleteAll();
                break;
            }
            case 7: {
                list.display();
                break;
            }
            case 8: {
                return 0;
            }
            default: {
                cout << "Pilihan salah. Masukkan operasi yang benar" << endl;
                break;
            }
        }
    }
    return 0;
}
```
#### Output:
![Screenshot]
### Penjelasan
Program diatas merupakan implementasi struktur data double linked list yang digunakan untuk menyimpan data nama produk skincare beserta harganya di Toko Purwokerto. Diawali dengan mengimpor library iostream untuk memfasilitasi input/output dan string untuk menggunakan tipe data string.

Didefinisikan sebuah kelas Node yang memiliki atribut namaProduk (string) untuk menyimpan nama produk, harga (double) untuk menyimpan harga produk, serta pointer prev dan next untuk menunjuk ke node sebelumnya dan selanjutnya dalam list. 

Didefinisikan pula kelas DoublyLinkedList yang mengatur berbagai operasi pada linked list ganda, seperti menambah node baru di depan (push), menghapus node pertama (pop), mengupdate data node, menghapus semua data, menampilkan data, serta menyisipkan dan menghapus node pada posisi tertentu.

Berbagai fungsi disediakan untuk melakukan operasi-operasi tersebut, seperti push untuk menambah node baru di depan dengan menerima input nama produk dan harganya, pop untuk menghapus node pertama, update untuk mengubah nama dan harga produk tertentu, deleteAll untuk menghapus seluruh node, insertAtPosition untuk menyisipkan node baru pada posisi yang ditentukan pengguna, dan deleteAtPosition untuk menghapus node pada posisi yang ditentukan pengguna.  

Pada fungsi main, program memberikan menu pilihan operasi kepada pengguna seperti menambah, menghapus, mengupdate, menyisipkan, menghapus pada posisi tertentu, menghapus semua, menampilkan data, atau keluar dari program. Program akan terus berjalan hingga pengguna memilih untuk keluar.

## Kesimpulan
#### Hasil praktikum:
Pada praktikum kali ini, Saya mempelajari struktur data yang disebut linked list. Linked list merupakan kumpulan elemen data yang bertipe sama, di mana setiap elemennya saling terhubung satu sama lain melalui pointer. Pointer adalah alamat memori di mana elemen data tersebut disimpan. Penggunaan pointer untuk mengacu ke elemen menyebabkan elemen-elemen tersebut terhubung secara logika meskipun secara fisik tidak bersebelahan di memori.

Terdapat dua jenis algoritma linked list berdasarkan operasinya, yaitu single linked list dan double linked list. Pada single linked list, setiap elemen hanya memiliki satu pointer yang menunjuk ke elemen berikutnya, sedangkan pada double linked list, setiap elemen memiliki dua pointer, satu menunjuk ke elemen sebelumnya dan satu lagi menunjuk ke elemen berikutnya.

#### Pelajaran yang didapat: 
Linked list adalah suatu bentuk struktur data yang berupa sekumpulan elemen data yang bertipe sama dimana tiap elemen saling berkaita atau dihubungkan dengan elemen lain melalui suatu pointer. Pointer itu sendiri adalah alamat elemen data yang tersimpan di memori. Penggunaan pointer untuk mengacu elemen berakibat elemen-elemen bersebelahan secara logik walau tidak bersebelahan secara fisik di memori. Berdasarkan jenis operasinya, terdapat dua algoritma Linked List yaitu Single Linked List (suatu kumpulan elemen data (yang disebut sebagai node) dimana urutannya ditentukan oleh suatu pointer) dan Double Linked List (mirip dengan single linked list, namun setiap node dalam double linked list memiliki dua pointer: satu untuk menunjuk ke node sebelumnya (prev) dan satu untuk menunjuk ke node berikutnya (next)).

## Referensi
[1] Johnson Sihombing, “PENERAPAN STACK DAN QUEUE PADA ARRAY DAN LINKED LIST DALAM JAVA”, 2019.

[2] Abdi Dharma, Hendra Handoko Syahputra P, "Aplikasi Pembelajaran Linked List Berbasis Mobile Learning", 2017. 