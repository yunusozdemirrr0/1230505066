#include <stdio.h>

struct Teklif {
    char Alici_isim[50];//al�c�n� en fazla 50 karakterlik al�c� ismini depolayan bir dizi ifadesidir.
    float meblag;
};

struct Artirma {
    float girisseviyesifiyat;
    float ensonfiyat;
    int teklifSayisi;
    struct Teklif maxTeklif;
};
/*Bu fonksiyon, Artirma ad�nda bir struct yap�s�n� parametre olarak al�r ve
 * ayn� zamanda bir ba�lang�� fiyat�n� girisseviyesifiyat al�r. Fonksiyonun amac�,
 * bir art�rma i�leminin ba�lang�c�n� belirlemektir. */
void artirmaBaslat(struct Artirma *artirma, float girisseviyesifiyat  ) {
    artirma->girisseviyesifiyat = girisseviyesifiyat;//Art�rman�n ba�lang�� fiyat�n�,
    // fonksiyonun ald��� girisseviyesifiyat de�eri olarak ayarlar.
    artirma->ensonfiyat = girisseviyesifiyat;// Art�rman�n ba�lang�� fiyat�n�,
    // ayn� zamanda art�rman�n �u ana kadar g�r�len en son fiyat olarak belirler.
    artirma->teklifSayisi = 0;//Art�rma ba�lang�c�nda hen�z hi� teklif yap�lmam��
    // oldu�u i�in teklif say�s�n� s�f�ra ayarlar.
}
//Bu fonksiyon, bir art�rma s�recinde kullan�c�dan teklif almak i�in tasarlanm��t�r.
// Kullan�c�dan al�c� ad�n� ve teklifi al�r, ard�ndan mevcut en son fiyat� kontrol eder.
// E�er yeni teklif, mevcut en son fiyattan y�ksekse, teklifi kabul eder ve ilgili
// bilgileri g�nceller. Aksi takdirde, teklif reddedilir ve mevcut fiyat ekrana yazd�r�l�r.
void teklifGir(struct Artirma *artirma) {
    struct Teklif yeniTeklif;
// Yeni bir Teklif yap�s� olu�tur
// Kullan�c�dan al�c� ismini iste ve yeniTeklif'e ata

    printf("Ad�n�z� girin: ");
    scanf("%s", yeniTeklif.Alici_isim);

// Kullan�c�dan teklifi iste ve yeniTeklif'e ata

    printf("Teklifinizi girin: ");
    scanf("%f", &yeniTeklif.meblag);

// Yeni teklif, mevcut en son fiyattan y�ksekse i�lem yap

    if (yeniTeklif.meblag > artirma->ensonfiyat){

        // En son fiyat� g�ncelle

        artirma->ensonfiyat = yeniTeklif.meblag;

        // Maksimum teklifi g�ncelle

        artirma->maxTeklif = yeniTeklif;

        // Teklif say�s�n� art�r

        artirma->teklifSayisi++;

        // Kullan�c�ya teklifin kabul edildi�ini ve g�ncel durumu bildir

        printf("%s, %.2f TL teklif verdi. (Toplam teklif: %d, Toplam tutar: %.2f TL)\n",
               yeniTeklif.Alici_isim, yeniTeklif.meblag, artirma->teklifSayisi, artirma->ensonfiyat);
    } else {

        // E�er yeni teklif, mevcut fiyattan d���kse reddedildi�ini bildir

        printf("Teklif reddedildi. Mevcut fiyat: %.2f TL\n", artirma->ensonfiyat);
    }
}
//bir a��k art�rmay� sonland�rmak ve kazanan teklifi ekrana yazd�rmak i�in tasarlanm��t�r
void artirmaBitir(struct Artirma *artirma) {

    // A��k art�rma sona erdi�inde kazanan� ve toplam teklif say�s�n� ekrana yazd�r

    printf("A��k art�rma sona erdi. Kazanan: %s, Toplam teklif: %d, Toplam tutar: %.2f TL\n",
           artirma->maxTeklif.Alici_isim, artirma->teklifSayisi, artirma->ensonfiyat);
}
//bir d�ng� i�inde kullan�c�dan teklif almaya devam eder ve kullan�c�n�n devam etmek
// isteyip istemedi�ini sorduktan sonra, kullan�c�n�n iste�ine ba�l� olarak d�ng�y�
// devam ettirir veya sonland�r�r.
// Sonunda, art�rmay� sonland�r�r ve kazanan teklifi ekrana yazd�r�r.
int main() {

    // Art�rma yap�s� olu�tur

    struct Artirma acikArtirma;

    // Art�rmay� ba�lat, ba�lang�� fiyat�n� 100.0 olarak belirle

    artirmaBaslat(&acikArtirma, 100.0);

    // Kullan�c�dan teklif almak i�in d�ng�y� ba�lat

    char devam;
    do {

        // Kullan�c�dan yeni teklifi al ve art�rma bilgilerini g�ncelle

        teklifGir(&acikArtirma);

        // Kullan�c�ya devam etmek isteyip istemedi�ini sor

        printf("Devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devam);
    } while (devam == 'E' || devam == 'e');

    // Art�rmay� sonland�r ve kazanan teklifi ekrana yazd�r

    artirmaBitir(&acikArtirma);

    return 0;
}

