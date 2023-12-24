#include <stdio.h>

struct Teklif {
    char Alici_isim[50];//alýcýný en fazla 50 karakterlik alýcý ismini depolayan bir dizi ifadesidir.
    float meblag;
};

struct Artirma {
    float girisseviyesifiyat;
    float ensonfiyat;
    int teklifSayisi;
    struct Teklif maxTeklif;
};
/*Bu fonksiyon, Artirma adýnda bir struct yapýsýný parametre olarak alýr ve
 * ayný zamanda bir baþlangýç fiyatýný girisseviyesifiyat alýr. Fonksiyonun amacý,
 * bir artýrma iþleminin baþlangýcýný belirlemektir. */
void artirmaBaslat(struct Artirma *artirma, float girisseviyesifiyat  ) {
    artirma->girisseviyesifiyat = girisseviyesifiyat;//Artýrmanýn baþlangýç fiyatýný,
    // fonksiyonun aldýðý girisseviyesifiyat deðeri olarak ayarlar.
    artirma->ensonfiyat = girisseviyesifiyat;// Artýrmanýn baþlangýç fiyatýný,
    // ayný zamanda artýrmanýn þu ana kadar görülen en son fiyat olarak belirler.
    artirma->teklifSayisi = 0;//Artýrma baþlangýcýnda henüz hiç teklif yapýlmamýþ
    // olduðu için teklif sayýsýný sýfýra ayarlar.
}
//Bu fonksiyon, bir artýrma sürecinde kullanýcýdan teklif almak için tasarlanmýþtýr.
// Kullanýcýdan alýcý adýný ve teklifi alýr, ardýndan mevcut en son fiyatý kontrol eder.
// Eðer yeni teklif, mevcut en son fiyattan yüksekse, teklifi kabul eder ve ilgili
// bilgileri günceller. Aksi takdirde, teklif reddedilir ve mevcut fiyat ekrana yazdýrýlýr.
void teklifGir(struct Artirma *artirma) {
    struct Teklif yeniTeklif;
// Yeni bir Teklif yapýsý oluþtur
// Kullanýcýdan alýcý ismini iste ve yeniTeklif'e ata

    printf("Adýnýzý girin: ");
    scanf("%s", yeniTeklif.Alici_isim);

// Kullanýcýdan teklifi iste ve yeniTeklif'e ata

    printf("Teklifinizi girin: ");
    scanf("%f", &yeniTeklif.meblag);

// Yeni teklif, mevcut en son fiyattan yüksekse iþlem yap

    if (yeniTeklif.meblag > artirma->ensonfiyat){

        // En son fiyatý güncelle

        artirma->ensonfiyat = yeniTeklif.meblag;

        // Maksimum teklifi güncelle

        artirma->maxTeklif = yeniTeklif;

        // Teklif sayýsýný artýr

        artirma->teklifSayisi++;

        // Kullanýcýya teklifin kabul edildiðini ve güncel durumu bildir

        printf("%s, %.2f TL teklif verdi. (Toplam teklif: %d, Toplam tutar: %.2f TL)\n",
               yeniTeklif.Alici_isim, yeniTeklif.meblag, artirma->teklifSayisi, artirma->ensonfiyat);
    } else {

        // Eðer yeni teklif, mevcut fiyattan düþükse reddedildiðini bildir

        printf("Teklif reddedildi. Mevcut fiyat: %.2f TL\n", artirma->ensonfiyat);
    }
}
//bir açýk artýrmayý sonlandýrmak ve kazanan teklifi ekrana yazdýrmak için tasarlanmýþtýr
void artirmaBitir(struct Artirma *artirma) {

    // Açýk artýrma sona erdiðinde kazananý ve toplam teklif sayýsýný ekrana yazdýr

    printf("Açýk artýrma sona erdi. Kazanan: %s, Toplam teklif: %d, Toplam tutar: %.2f TL\n",
           artirma->maxTeklif.Alici_isim, artirma->teklifSayisi, artirma->ensonfiyat);
}
//bir döngü içinde kullanýcýdan teklif almaya devam eder ve kullanýcýnýn devam etmek
// isteyip istemediðini sorduktan sonra, kullanýcýnýn isteðine baðlý olarak döngüyü
// devam ettirir veya sonlandýrýr.
// Sonunda, artýrmayý sonlandýrýr ve kazanan teklifi ekrana yazdýrýr.
int main() {

    // Artýrma yapýsý oluþtur

    struct Artirma acikArtirma;

    // Artýrmayý baþlat, baþlangýç fiyatýný 100.0 olarak belirle

    artirmaBaslat(&acikArtirma, 100.0);

    // Kullanýcýdan teklif almak için döngüyü baþlat

    char devam;
    do {

        // Kullanýcýdan yeni teklifi al ve artýrma bilgilerini güncelle

        teklifGir(&acikArtirma);

        // Kullanýcýya devam etmek isteyip istemediðini sor

        printf("Devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devam);
    } while (devam == 'E' || devam == 'e');

    // Artýrmayý sonlandýr ve kazanan teklifi ekrana yazdýr

    artirmaBitir(&acikArtirma);

    return 0;
}

