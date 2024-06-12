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
