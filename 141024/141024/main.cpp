#include <iostream>

using namespace std;

struct node {
    int data; // Düğümdeki veri
    struct node* next; // Sonraki düğümü gösteren işaretçi
};

// Baş düğümüne eleman ekleme fonksiyonu
struct node* basaekle(struct node* head, int key) {
    struct node* temp = new node(); // Yeni düğüm oluştur
    temp->data = key; // Veriyi ata
    temp->next = head; // Yeni düğümün sonraki işaretçisini mevcut başa eşitle
    head = temp; // Baş işaretçisini yeni düğüme güncelle
    cout << "Düğümün başına eleman eklendi: " << key << endl;

    return head; // Yeni başı döndür
}

// Son düğüme eleman ekleme fonksiyonu
struct node* sonaekle(struct node* head, int key) {
    struct node* temp = new node(); // Yeni düğüm oluştur
    temp->data = key; // Veriyi ata
    temp->next = NULL; // Son düğüm olduğu için next'i NULL yap

    if (head == NULL) { // Eğer liste boşsa
        head = temp; // Yeni düğümü baş olarak ayarla
        cout << "İlk düğüm oluşturuldu: " << key << endl;
    } else {
        struct node* temp2 = head; // Geçici işaretçi ile listenin sonuna git
        while (temp2->next != NULL) { // Son düğümü bul
            temp2 = temp2->next;
        }
        temp2->next = temp; // Son düğümün sonraki işaretçisini yeni düğüme eşitle
        cout << "Düğümün sonuna eleman eklendi: " << key << endl;
    }

    return head; // Baş işaretçisini döndür
}

int main() {
    struct node* head = NULL; // Başlangıçta boş liste

    // Düğümlerin başına ekle
    head = basaekle(head, 11);
    head = basaekle(head, 22);
    head = basaekle(head, 33);

    // Düğümlerin sonuna ekle
    head = sonaekle(head, 44);
    head = sonaekle(head, 55);
    head = sonaekle(head, 66);

    // Tüm düğüm verilerini yazdır
    struct node* temp = head; // Geçici işaretçi
    while (temp != NULL) {
        cout << temp->data << " "; // Düğüm verisini yazdır
        temp = temp->next; // Sonraki düğüme geç
    }

    cout << endl; // Satır sonu

    return 0; // Programı başarıyla bitir
}
