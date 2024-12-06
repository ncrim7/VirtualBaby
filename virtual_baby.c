#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IHTIYAC 9 // Toplam ihtiyac sayisi

// Sanal bebegin ihtiyaclari ve baslangicc degerleri
int ihtiyaclar[MAX_IHTIYAC] = {5, 5, 5, 5, 5, 5, 5, 5, 5};

// Ihtiyac isimleri
const char *ihtiyac_isimleri[MAX_IHTIYAC] = {
    "Tokluk", "Uyku", "Sevgi", "Sosyallesme", "Saglik", "Egitim", "Hijyen", "Tuvalet", "Eglence"
};

// Ihtiyaclari gosteren fonksiyon
void ihtiyaclariGoster(int *ihtiyaclar) {
    printf("\nIhtiyaclar:\n");
    for (int i = 0; i < MAX_IHTIYAC; ++i) {
        printf("%s: %d\n", ihtiyac_isimleri[i], ihtiyaclar[i]);
    }
}

    void yemekYeme(int *ihtiyaclar) {
        char giris[50]; // Kullanıcının girişini tutmak için karakter dizisi
        int adet = 0;
        char yemek[20];
         printf("\nIcardi bebege ne yedirmek istersiniz ve kac adet? (arasinda bosluk olmadan) \n(Ornek: '2 mama'\n'1 sut'\n'2 su'): ");
         scanf("%s", giris);

         adet = atoi(giris); // Karakter dizisini tam sayıya dönüştür

         // Girişi parçalayarak miktarı ve yiyeceği elde et
         sscanf(giris, "%d %s", &adet, yemek);

         if (strcmp(yemek, "sut") == 0) {
                ihtiyaclar[0] += 2 * adet; // anne sutu yedikçe tokluk seviyesini arttır
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] > 10) ihtiyaclar[0] = 10;
             printf("Aysun Hanım Icardi bebege %d adet %s icirdi. Tokluk seviyesi: %d\n", adet, yemek, ihtiyaclar[0]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             // Tokluk değerini kontrol et, eğer 10'u geçtiyse bebek öldü, oyunu bitir
             if (ihtiyaclar[0] >= 10) {
                 printf("Icardi bebek tokluktan oldu! Oyun bitti!\n");
                 exit(0); // Programı sonlandır
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzlukan oldu!\n");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu!\n");
                exit(0);
             }

         }
     else if (strcmp(yemek, "su") == 0) {
         ihtiyaclar[0] += 1 * adet; // su yedikçe tokluk seviyesini arttır
            if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
            if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
            if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
            if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
            if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
            if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
            if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 3*adet;
            if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
            if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
            if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
            if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
            if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
            if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
            if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
            if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
            if (ihtiyaclar[0] > 10) ihtiyaclar[0] = 10;
         printf("Aysun Hanim Icardi bebege %d adet %s icirdi. Tokluk seviyesi: %d\n", adet, yemek, ihtiyaclar[0]);
         if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
         if (ihtiyaclar[7] <= 0) {
                ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

         // Tokluk değerini kontrol et, eğer 10'u geçtiyse bebek öldü, oyunu bitir
         if (ihtiyaclar[0] >= 10) {
             printf("Icardi bebek tokluktan oldu! Oyun bitti!\n");
             exit(0); // Programı sonlandır
         }
         else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzlukan oldu!\n");
                exit(0);
             }
         else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu!\n");
                exit(0);
             }
         else if (ihtiyaclar[7] <= 0) {
            printf("Icardi bebek yeterince su icti daha fazla su icirmemelisin!\n");
         }

     }
     else if (strcmp(yemek, "mama") == 0) {
            ihtiyaclar[0] += 3*adet; // �rnek olarak mama yedi�inde tokluk 3 art�yor
            if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
            if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
            if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
            if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
            if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
            if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
            if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
            if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
            if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
            if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
            if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
            if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
            if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
            if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
            if (ihtiyaclar[8] < 0) {
                    ihtiyaclar[8] = 0;
            }
            if (ihtiyaclar[0] > 10) ihtiyaclar[0] = 10;

         printf("Aysun Hanim Icardi bebege %d adet %s yedirdi. Tokluk seviyesi: %d\n", adet, yemek, ihtiyaclar[0]);
         if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0 || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
         if (ihtiyaclar[7] <= 0) {
                ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

         // Tokluk değerini kontrol et, eğer 10'u geçtiyse bebek oldu, oyunu bitir
         if (ihtiyaclar[0] >= 10) {
             printf("Icardi bebek tokluktan oldu! Oyun bitti!\n");
             exit(0); // Programı sonlandır
         }
         else if (ihtiyaclar[1] <= 0) {
            printf("Icardi bebek uykusuzluktan oldu! Oyun Bitti!\n");
            exit(0);
         }
         else if (ihtiyaclar[4] <= 0) {
            printf("Icardi bebek sagliksiz yasamdan oldu!\n");
            exit(0);
             }

 }
 else {
        printf("Bu yiyecegi tanimiyoruz veya desteklenmiyor!\n");
        }
    // Diğer yiyecekler için benzer şekilde işlemler yapılabilir
}

void sevgiGoster(int *ihtiyaclar) {
    char giris[50];
    int adet = 0;
    char eylem[20];

    printf("Icardi bebege ne yapmak istersiniz ve kac kez? (arasinda bosluk olmadan) (Ornek: '2 oksa', '1 kucakla', '3 op'): ");
    scanf("%s", giris);

    adet = atoi(giris); // Karakter dizisini tam sayıya dönüştür

    sscanf(giris, "%d %s", &adet, eylem);

    if (strcmp(eylem, "oksa") == 0) {
                ihtiyaclar[2] += 1 * adet; 
                ihtiyaclar[3] += 1 * adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] > 10) ihtiyaclar[2] = 10;
                if (ihtiyaclar[3] > 10) ihtiyaclar[3] = 10;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebegi %d kez oksadi. Sevgi seviyesi: %d\n", adet, ihtiyaclar[2]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[1] <= 0  || ihtiyaclar[8] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             
             if (ihtiyaclar[2] >= 10 || ihtiyaclar[3] >= 10 || ihtiyaclar[7] >= 10) {
                 printf("Icardi bebek yeterince oksandi!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else if (strcmp(eylem, "op") == 0) {
                ihtiyaclar[2] += 1 * adet; 
                ihtiyaclar[3] += 1 * adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] > 10) ihtiyaclar[2] = 10;
                if (ihtiyaclar[3] > 10) ihtiyaclar[3] = 10;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebegi %d kez optu. Sevgi seviyesi: %d\n", adet, ihtiyaclar[2]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[1] <= 0  || ihtiyaclar[8] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             // Tokluk değerini kontrol et, eğer 10'u geçtiyse bebek öldü, oyunu bitir
             if (ihtiyaclar[2] >= 10 || ihtiyaclar[3] >= 10 || ihtiyaclar[7] >= 10) {
                 printf("Icardi bebek yeterince opuldu!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else if (strcmp(eylem, "kucakla") == 0) {
                ihtiyaclar[2] += 1 * adet; // anne sutu yedikçe tokluk seviyesini arttır
                ihtiyaclar[3] += 1 * adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] > 10) ihtiyaclar[2] = 10;
                if (ihtiyaclar[3] > 10) ihtiyaclar[3] = 10;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebegi %d kez kucakladi. Sevgi seviyesi: %d\n", adet, ihtiyaclar[2]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             // Tokluk değerini kontrol et, eğer 10'u geçtiyse bebek öldü, oyunu bitir
             if (ihtiyaclar[2] >= 10 || ihtiyaclar[3] >= 10 || ihtiyaclar[7] >= 10) {
                 printf("Icardi bebek yeterine kucaklandi!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
        else {
            printf("Bu eylemi tanimiyoruz veya desteklenmiyor!\n");
            }
}

void hijyen(int *ihtiyaclar) {
    char giris[50];
    int adet = 0;
    char eylem[20];

    printf("Icardi bebege ne yapmak istersiniz ve kac kez? (arasinda bosluk olmadan) (Ornek: '2 tirnak_kes', '1 dus_al', '3 altini_degis'): ");
    scanf("%s", giris);

    adet = atoi(giris); // Karakter dizisini tam sayıya dönüştür

    sscanf(giris, "%d %s", &adet, eylem);

    if (strcmp(eylem, "tirnak_kes") == 0) {
                ihtiyaclar[6] += 2 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[6] > 10) ihtiyaclar[6] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebegin %d kez tirnagini kesti. Hijyen seviyesi: %d\n", adet, ihtiyaclar[6]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             
             if (ihtiyaclar[6] >= 10) {
                 printf("Icardi bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }

         else if (strcmp(eylem, "dus_al") == 0) {
                ihtiyaclar[6] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[6] > 10) ihtiyaclar[6] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebege %d kez dus aldirdi. Hijyen seviyesi: %d\n", adet, ihtiyaclar[6]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             
             if (ihtiyaclar[6] >= 10) {
                 printf("Icardi bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }

         else if (strcmp(eylem, "altini_degis") == 0) {
                ihtiyaclar[6] += 5 * adet; 
                ihtiyaclar[7] += 5 * adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[6] > 10) ihtiyaclar[6] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebegin %d kez alti degisti. Hijyen seviyesi: %d\n", adet, ihtiyaclar[6]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             
             if (ihtiyaclar[6] >= 10) {
                 printf("Icardi bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else {
            printf("Bu eylemi tanimiyoruz veya desteklenmiyor!\n");
            }
}

void egitim(int *ihtiyaclar) {
    char giris[50];
    int adet = 0;
    char eylem[20];

    printf("Icardi bebege ne yapmak istersiniz ve kac kez? (arasinda bosluk olmadan) (Ornek: '2 kitap_oku', '1 muzik', '3 egzersiz'): ");
    scanf("%s", giris);

    adet = atoi(giris); // Karakter dizisini tam sayıya dönüştür

    sscanf(giris, "%d %s", &adet, eylem);

        if (strcmp(eylem, "kitap_oku") == 0) {
                ihtiyaclar[5] += 3 * adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] > 10) ihtiyaclar[5] = 10;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebege %d kez kitap okudu. Egitim seviyesi: %d\n", adet, ihtiyaclar[5]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

            
             if (ihtiyaclar[5] >= 10) {
                 printf("Icardi bebege yeterince kitap okundu!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
        else if (strcmp(eylem, "muzik") == 0) {
                ihtiyaclar[5] += 2 * adet; 
                ihtiyaclar[8] += adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] > 10) ihtiyaclar[5] = 10;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] > 10) ihtiyaclar[8] = 10;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebege %d kez muzik dinletti. Egitim seviyesi: %d\n Eglence seviyesi: %d\n", adet, ihtiyaclar[5], ihtiyaclar[8]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[3] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             // Tokluk değerini kontrol et, eğer 10'u geçtiyse bebek öldü, oyunu bitir
             if (ihtiyaclar[5] >= 10 || ihtiyaclar[8] >= 10) {
                 printf("Icardi bebek daha fazla muzik dinlememeli!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else if (strcmp(eylem, "egzersiz") == 0) {
                ihtiyaclar[5] += 2 * adet; // anne sutu yedikçe tokluk seviyesini arttır
                ihtiyaclar[8] += adet;
                ihtiyaclar[2] += adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] > 10) ihtiyaclar[2] = 10;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] > 10) ihtiyaclar[5] = 10;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] > 10) ihtiyaclar[8] = 10;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebege %d kez egzersiz yaptirdi. Egitim seviyesi: %d\n Eglence seviyesi: %d\n Sevgi seviyesi: %d\n", adet, ihtiyaclar[5], ihtiyaclar[8], ihtiyaclar[2]);
             if (ihtiyaclar[6] || ihtiyaclar[7] || ihtiyaclar[5] || ihtiyaclar[3]  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             // Tokluk değerini kontrol et, eğer 10'u geçtiyse bebek öldü, oyunu bitir
             if (ihtiyaclar[5] >= 10 || ihtiyaclar[8] >= 10 || ihtiyaclar[2] >= 10) {
                 printf("Icardi bebek yeterince egzersiz yapti!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else {
            printf("Bu eylemi tanimiyoruz veya desteklenmiyor!\n");
         }
}

void eglence(int *ihtiyaclar) {
    char giris[50];
    int adet = 0;
    char eylem[20];

    printf("Icardi bebege ne yapmak istersiniz ve kac kez? (arasinda bosluk olmadan) (Ornek: '2 cee', '1 gidikla', '3 oyuncak'): ");
    scanf("%s", giris);

    adet = atoi(giris); // Karakter dizisini tam sayıya dönüştür

    sscanf(giris, "%d %s", &adet, eylem);

    if (strcmp(eylem, "cee") == 0) {
                ihtiyaclar[8] += 3 * adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[8] > 10) ihtiyaclar[8] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebekle %d kez Ce eee oynadi. Eglence seviyesi: %d\n", adet, ihtiyaclar[8]);

             if (ihtiyaclar[6] || ihtiyaclar[7] || ihtiyaclar[5] || ihtiyaclar[3]  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

           
             if (ihtiyaclar[8] >= 10) {
                 printf("Icardi bebek daha fazla oyun istemiyor!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
    else if (strcmp(eylem, "gidikla") == 0) {
                ihtiyaclar[8] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[8] > 10) ihtiyaclar[8] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Aysun Hanim Icardi bebegi %d kez gidikladi. Eglence seviyesi: %d\n", adet, ihtiyaclar[8]);

             if (ihtiyaclar[6] || ihtiyaclar[7] || ihtiyaclar[5] || ihtiyaclar[3]  || ihtiyaclar[2] <= 0) {
                    printf("Icardi bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Icardi bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

         
             if (ihtiyaclar[8] >= 10) {
                 printf("Icardi bebek yeterince gidiklandi!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Icardi bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Icardi bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Icardi bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
    else if (strcmp(eylem, "oyuncak") == 0) {
                ihtiyaclar[8] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[8] > 10) ihtiyaclar[8] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Bebek %d kez oyuncakla oynadi. Eglence seviyesi: %d\n", adet, ihtiyaclar[8]);

                if (ihtiyaclar[6] < 0 || ihtiyaclar[7] < 0 || ihtiyaclar[5] < 0 || ihtiyaclar[3] < 0  || ihtiyaclar[2] < 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                    }
                if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             if (ihtiyaclar[8] >= 10) {
                 printf("Bebek yeterince oyuncakla oynadi!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else {
            printf("Bu eylemi tanimiyoruz veya desteklenmiyor!\n");
            }
}

void uyu(int *ihtiyaclar, int tekrar) {
    if (tekrar <= 0) {
         printf("Uyku tamamlandi!\n");
        return;
    }
    else if (ihtiyaclar[1] >= 10)
        printf("Bebek uyku ihtiyaci hissetmiyor!\n");
    else {
        printf("Uyku tekrari: %d\n", tekrar);

        if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*tekrar;
        if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*tekrar;
        if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*tekrar;
        if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*tekrar;
        if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*tekrar;
        if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*tekrar;
        if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*tekrar;
        if (ihtiyaclar[1] > 0) ihtiyaclar[1] += 1*tekrar;
            if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
            if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
            if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
            if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
            if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
            if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
            if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
            if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
            if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
            if (ihtiyaclar[1] > 10) ihtiyaclar[1] = 10;

            if (ihtiyaclar[6] < 0 || ihtiyaclar[7] < 0 || ihtiyaclar[5] < 0 || ihtiyaclar[3] < 0  || ihtiyaclar[2] < 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                    }
            else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }


        uyu(ihtiyaclar, tekrar - 10);
    }

void saglik(int *ihtiyaclar) {
    char giris[50];
    int adet = 0;
    char eylem[20];

    printf("Ne yapmak istersiniz ve kac kez? (arasinda bosluk olmadan) (Ornek: '2 serum', '1 surup', '3 asi'): ");
    scanf("%s", giris);

    adet = atoi(giris); // Karakter dizisini tam sayıya dönüştür

    sscanf(giris, "%d %s", &adet, eylem);

    if (strcmp(eylem, "serum") == 0) {
                ihtiyaclar[4] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[4] > 10) ihtiyaclar[4] = 10;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Bebege %d kez serum baglandi. Saglik seviyesi: %d\n", adet, ihtiyaclar[4]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[6] <= 0  || ihtiyaclar[2] <= 0 || ihtiyaclar[3] <= 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             
             if (ihtiyaclar[3] >= 10) {
                 printf("Bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }

         else if (strcmp(eylem, "surup") == 0) {
                ihtiyaclar[4] += 3 * adet;
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[4] > 10) ihtiyaclar[4] = 10;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Bebege %d kez surup icirildi. Saglik seviyesi: %d\n", adet, ihtiyaclar[4]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[6] <= 0  || ihtiyaclar[2] <= 0 || ihtiyaclar[3] <= 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             if (ihtiyaclar[3] >= 10) {
                 printf("Bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }

         else if (strcmp(eylem, "asi") == 0) {
                ihtiyaclar[4] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[3] > 0) ihtiyaclar[3] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[4] > 10) ihtiyaclar[4] = 10;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Bebege %d kez asi vuruldu. Saglik seviyesi: %d\n", adet, ihtiyaclar[4]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[6] <= 0  || ihtiyaclar[2] <= 0 || ihtiyaclar[3] <= 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             if (ihtiyaclar[3] >= 10) {
                 printf("Bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else {
            printf("Bu eylemi tanimiyoruz veya desteklenmiyor!\n");
            }
}

void sosyallesme(int *ihtiyaclar) {
    char giris[50];
    int adet = 0;
    char eylem[20];

    printf("Ne yapmak istersiniz ve kac kez? (arasinda bosluk olmadan) (Ornek: '2 goz_temasi', '1 gulumse', '3 sarki_soyle'): ");
    scanf("%s", giris);

    adet = atoi(giris); // Karakter dizisini tam sayıya dönüştür

    sscanf(giris, "%d %s", &adet, eylem);

    if (strcmp(eylem, "goz_temasi") == 0) {
                ihtiyaclar[3] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[6] < 0) ihtiyaclar[6] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[3] > 10) ihtiyaclar[3] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Bebekle %d kez goz temasi kuruldu. Sosyallesme seviyesi: %d\n", adet, ihtiyaclar[3]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[6] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             if (ihtiyaclar[3] >= 10) {
                 printf("Bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }

         else if (strcmp(eylem, "gulumse") == 0) {
                ihtiyaclar[3] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[3] > 10) ihtiyaclar[3] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Bebege %d kez gulumsendi. Sosyallesme seviyesi: %d\n", adet, ihtiyaclar[3]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[6] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             if (ihtiyaclar[3] >= 10) {
                 printf("Bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }

         else if (strcmp(eylem, "sarki_soyle") == 0) {
                ihtiyaclar[3] += 3 * adet; 
                if (ihtiyaclar[1] > 0) ihtiyaclar[1] -= 1*adet;
                if (ihtiyaclar[5] > 0) ihtiyaclar[5] -= 1*adet;
                if (ihtiyaclar[8] > 0) ihtiyaclar[8] -= 1*adet;
                if (ihtiyaclar[2] > 0) ihtiyaclar[2] -= 1*adet;
                if (ihtiyaclar[6] > 0) ihtiyaclar[6] -= 1*adet;
                if (ihtiyaclar[0] > 0) ihtiyaclar[0] -= 1*adet;
                if (ihtiyaclar[7] > 0) ihtiyaclar[7] -= 1*adet;
                if (ihtiyaclar[1] < 0) ihtiyaclar[1] = 0;
                if (ihtiyaclar[2] < 0) ihtiyaclar[2] = 0;
                if (ihtiyaclar[3] < 0) ihtiyaclar[3] = 0;
                if (ihtiyaclar[4] < 0) ihtiyaclar[4] = 0;
                if (ihtiyaclar[5] < 0) ihtiyaclar[5] = 0;
                if (ihtiyaclar[3] > 10) ihtiyaclar[3] = 10;
                if (ihtiyaclar[7] < 0) ihtiyaclar[7] = 0;
                if (ihtiyaclar[8] < 0) ihtiyaclar[8] = 0;
                if (ihtiyaclar[0] < 0) ihtiyaclar[0] = 0;
             printf("Bebege %d kez gulumsendi. Sosyallesme seviyesi: %d\n", adet, ihtiyaclar[3]);
             if (ihtiyaclar[6] <= 0 || ihtiyaclar[7] <= 0 || ihtiyaclar[5] <= 0 || ihtiyaclar[6] <= 0  || ihtiyaclar[2] <= 0) {
                    printf("Bebegin sagligi azaliyor!");
                    ihtiyaclar[4]--;
                }
             if (ihtiyaclar[7] <= 0) {
                    ihtiyaclar[6] = 0;
                    printf("Bebek altina yapti! Hijyen seviyesi: %d",ihtiyaclar[6]);
                }

             if (ihtiyaclar[3] >= 10) {
                 printf("Bebek yeterince temiz!\n");
             }
             else if (ihtiyaclar[0] <= 0) {
                printf("Bebek acliktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[1] <= 0) {
                printf("Bebek uykusuzluktan oldu! Oyun bitti!");
                exit(0);
             }
             else if (ihtiyaclar[4] <= 0) {
                printf("Bebek sagliksiz yasamdan oldu! Oyun bitti!");
                exit(0);
             }
         }
         else {
            printf("Bu eylemi tanimiyoruz veya desteklenmiyor!\n");
            }
}

// Global değişken: doping fonksiyonunun kaç kere çağrıldığını tutmak için
int dopingKullanmaSayisi = 0;

void doping(int *ihtiyaclar) {
    // Doping fonksiyonu 3 kez çağrılabilir
    if (dopingKullanmaSayisi < 3) {
        // İhtiyaç değerlerini maksimuma (10) çıkar
        for (int i = 0; i < 9; ++i) {
            if (ihtiyaclar[i] < 10) {
                ihtiyaclar[i] = 10;
            }
        }
        // Kullanım sayısını artır
        dopingKullanmaSayisi++;
        printf("Doping yapildi! Degerler maksimuma cikarildi.\n");

        // Eğer kullanım sayısı 3'ü geçtiyse oyunu bitir
        if (dopingKullanmaSayisi >= 3) {
            printf("Kural ihlali! Oyun bitti!\n");
            exit(0); // Programı sonlandır
        }
    } else {
        printf("Kural ihlali! Doping fonksiyonu 3 kezden fazla kullanildi.\nOyun bitti!\n");
        exit(0); // Programı sonlandır
    }
}

// Diger ihtiyac fonksiyonlari buraya eklenebilir...

int main() {
    int ihtiyaclar[MAX_IHTIYAC] = {5, 5, 5, 5, 5, 5, 5, 5, 5}; // İhtiyaçlar ve başlangıç değerleri
    printf("Sanal Bebek Mini Icardi Uygulamasina Hos Geldiniz!\n");
    printf("Sanal Bebek Mini Icardi Sizin Becerilerinize Gore Hayatta Kalacak Ya Da Yeryuzunden Silinecek!\n");
    printf("Lutfen bir islem secin (Cikis icin 0'a basin): \n");
    ihtiyaclariGoster(ihtiyaclar); // Ihtiyaclari goster

    int secim,secim2,secim3,adet;
    while (1) {
        printf("\nNe yapmak istersiniz?\n");
        printf("0. Cikis\n");
        printf("1. Yemek yeme\n");
        printf("2. Uyuma\n");
        printf("3. Sevgi\n");
        printf("4. Hijyen\n");
        printf("5. Egitim\n");
        printf("6. Eglence\n");
        printf("7. Sosyallesme\n");
        printf("8. Saglik\n");
        printf("9. Doping\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 0:
                printf("Cikis yapiliyor...\n");
                return 0;
            case 1:
                yemekYeme(ihtiyaclar);
                break;
            case 2:
                printf("Kac saat uyku: ");
                scanf("%d",&adet);
                uyu(ihtiyaclar,adet);
                break;
            case 3:
                sevgiGoster(ihtiyaclar);
                break;
            case 4:
                hijyen(ihtiyaclar);
                break;
            case 5:
                egitim(ihtiyaclar);
                break;
            case 6:
                eglence(ihtiyaclar);
                break;
            case 7:
                sosyallesme(ihtiyaclar);
                break;
            case 8:
                saglik(ihtiyaclar);
                break;
            case 9:
                doping(ihtiyaclar);
                break;
            default:
                printf("Gecersiz secim! Tekrar deneyin.\n");
                break;
        }

        ihtiyaclariGoster(ihtiyaclar); // Ihtiyaclari guncelle ve ekrana yazdir
        printf("\n");
    }

    return 0;
}

