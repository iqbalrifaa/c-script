#include <iostream>
#include <string>
using namespace std;

// Struct untuk data mahasiswa
struct Mahasiswa {
    string nama;
    int nim;
};

// Node untuk stack
struct Node {
    Mahasiswa data;
    Node* next;
};

// Inisialisasi stack
Node* top = NULL;

// Fungsi untuk push data ke stack
void push(Mahasiswa mhs) {
    Node* newNode = new Node;
    newNode->data = mhs;
    newNode->next = top;
    top = newNode;
}

// Fungsi untuk pop data dari stack
void pop() {
    if (top == NULL) {
        cout << "Stack kosong" << endl;
        return;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
void search(int nim) {
    Node* current = top;
    while (current != NULL) {
        if (current->data.nim == nim) {
            cout << "Data ditemukan:" << endl;
            cout << "Nama: " << current->data.nama << endl;
            cout << "NIM: " << current->data.nim << endl;
            return;
        }
        current = current->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

// Fungsi untuk sorting data mahasiswa berdasarkan NIM (Bubble Sort)
void bubbleSort() {
    Node* current;
    Node* nextNode;
    Mahasiswa temp;
    for (current = top; current != NULL; current = current->next) {
        for (nextNode = current->next; nextNode != NULL; nextNode = nextNode->next) {
            if (current->data.nim > nextNode->data.nim) {
                temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }
        }
    }
}

int main() {
    // Inisialisasi data mahasiswa
    Mahasiswa mhs1 = {"Brerama", 23550024};
    Mahasiswa mhs2 = {"Brenada", 456};

    // Push data mahasiswa ke stack
    push(mhs1);
    push(mhs2);

    // Menampilkan data sebelum sorting
    cout << "Data sebelum sorting:" << endl;
    search(23550024); // Contoh pencarian data
    cout << endl;

    // Sorting data mahasiswa
    bubbleSort();

    // Menampilkan data setelah sorting
    cout << "Data setelah sorting:" << endl;
    search(23550024); // Contoh pencarian data setelah sorting

    return 0;
}
