//
//  veri_son.c
//  one
//  171220036
//  Created by Umut Öçgüder on 20.12.2019.
//
/*Müşteri numarası ve müşteri ad, soyad bilgilerinin müşteri numarası indeksine göre tutulacağı uygulama-1
ve uygulama-2 için iki ayrı hash tablosu için gerekli veri yapısını tanımlayarak aşağıdaki iki uygulamayı
gerçekleştiriniz. Hash tablo boyutu kullanıcıdan istenecektir ve hash fonksiyonu olarak key mod tablo boyutu
kullanılacaktır. Ekleme işlemi her iki uygulama içinde gerçekleştirilecektir.
Uygulama-1: Hash tablosuna ekleme fonksiyonu müşteri numarası, ad ve soyad bilgilerini parametre olarak
alarak, müşteri numarasına göre hash tablosuna ekleyecektir. Herhangi bir çakışma (collision) oluşması
durumunda ise hash tablosunun mevcut satırından itibaren adım adım bir sonraki satırdan itibaren ilk bulunan
boş satıra ekleme yapılacaktır. Bu esnada tablo dolu ise “tablo dolu” mesajı verilerek ekleme işlemi bitirilecektir.
Uygulama-2: Hash tablosuna ekleme fonksiyonu müşteri numarası, ad ve soyad bilgilerini parametre olarak
alarak, müşteri numarasına göre hash tablosuna ekleyecektir. Bu uygulamadaki hash tablosunda ilave olarak bir
sonraki gidilecek satır numarasını içeren bir link tutulacaktır. Herhangi bir çakışma oluşması durumunda ise
hash tablosunun başından sonuna doğru ilk bulunan boş satıra ekleme yapılacaktır ve ilgili linkler takip edilerek
takip listesinin son elemanının link alanı boş bulunan satır numarası olarak güncellenecektir. Bu esnada tablo
dolu ise “tablo dolu” mesajı verilerek ekleme işlemi bitirilecektir.
Her iki uygulama için;
a) Her iki uygulama içinde yazacağınız iki ayrı search fonksiyonu müşteri numara bilgisini alarak kayıtları
hash tablosunda arayacak ve kayıtların kaç adımda bulunduğunu geriye döndürecektir. (Aranan kayıt
bulunmazsa -1 geriye dönecektir)
b) Her iki uygulama içinde yazacağınız iki ayrı listeleme fonksiyonu hash tablosunun içeriğini
listeleyecektir.
 Uygulama-1 için örnek: Tablo boyutu 5 olsun. Sırasıyla 10, 13, 23 ve 18 key değerleri eklenirse
 Başlangıçta 10 eklenince 13 eklenince 23 eklenince 18 eklenince
 Değer
 0 -1
 1 -1
 2 -1
 3 -1
 4 -1

 Değer
 0 10
 1 -1
 2 -1
 3 -1
 4 -1

 Değer
 0 10
 1 -1
 2 -1
 3 13
 4 -1

 Değer
 0 10
 1 -1
 2 -1
 3 13
 4 23

 Değer
 0 10
 1 18
 2 -1
 3 13
 4 23

 18 aradığımız zaman hash_indeks=18 mod 5= 3 heseplanır. Takip listesi: 3. Satır (13 var)-> 4. Satır (23 var)
 -> 0. Satır (10 var) -> 1. Satır (18 var) şeklinde olacaktır. 18 değerine 4 adımda ulaşılmaktadır.
 
 
 Uygulama-2 için örnek: Tablo boyutu 5 olsun. Sırasıyla 10, 13, 23 ve 18 key değerleri eklenirse
 Başlangıçta 10 eklenince 13 eklenince 23 eklenince 18 eklenince
 Değer Link
 0 -1 -1
 1 -1 -1
 2 -1 -1
 3 -1 -1
 4 -1 -1

 Değer Link
 0 10 -1
 1 -1 -1
 2 -1 -1
 3 -1 -1
 4 -1 -1

 Değer Link
 0 10 -1
 1 -1 -1
 2 -1 -1
 3 13 -1
 4 -1 -1

 Değer Link
 0 10 -1
 1 23 -1
 2 -1 -1
 3 13 1
 4 -1 -1

 Değer Link
 0 10 -1
 1 23 2
 2 18 -1
 3 13 1
 4 -1 -1
 18 aradığımız zaman hash_indeks=18 mod 5= 3 heseplanır. Takip listesi: 3. Satır (13 var)-> 1. Satır (23 var)
 -> 2. Satır (18 var) şeklinde olacaktır. 18 değerine 3 adımda ulaşılmaktadır.
 
 
 Öğrenci_No_Veri_Yap_Odev3.rar
 formatında olmak zorundadır. Kodlarınıza açıklama satırları eklemek zorunludur.
 (171220036_veri_yap_odev1.rar). Ödevler 22 Aralık 2019 Pazar günü saat 23:55’e
 */
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

typedef struct node{
  int no;
  char ad[50];
  char soyad[50];
}nodem;

int hash(int numara,int say){ return  numara%say;}
int dolumu (nodem array[],int say){

  int i,counter = 0;
  for (i = 0; i < say; i++) {
    if(array[i].no == -1)
      counter++;
    
  }
  if (counter == 0) return 1;
  else  return -1;
}
int arama(nodem dizi[],int mus, int say){

  int sayac=1;
  if(dizi[hash(mus,say)].no == mus){
      printf("\nBulunan kisinin bilgileri : mus_no: %d ad: %s soyad: %s\n",dizi[hash(mus,say)].no,dizi[hİ;ash(mus,say)].ad,dizi[hash(mus,say)].soyad);
    return 1;
  }else{
    int i;
    i = hash(mus,say);
    while (dizi[i].no == mus || i<say) {
      i++;
      sayac++;
      if (dizi[i].no == mus) {
        printf("\nBulunan kisinin bilgileri : %d %s %s\n",dizi[i].no,dizi[i].ad,dizi[i].soyad);
        return sayac;
      }
    }
    return -1;
  }

}

void add(nodem array[], int say){

  if (dolumu(array,say) == -1) {
    int no,i;
    char ad[50],soyad[50];
    printf("musteri no giriniz:\n");
    scanf("%d",&no );
    printf("isim :\n");
    scanf("%s",&ad);
    printf("soyisim:\n");
    scanf("%s",&soyad);
    if (array[hash(no, say)].no == -1)  {
      array[hash(no,say)].no = no;
      for (i = 0; i < 50; i++) {
        array[hash(no,say)].ad[i] = ad[i];
        array[hash(no,say)].soyad[i] = soyad[i];
      }
    }else{
      int sayi = hash(no,say);
      while (array[sayi].no != -1) {
        sayi++;
      }
      array[sayi].no = no;
      for (i = 0; i < 50; i++) {
        array[sayi].ad[i] = ad[i];
        array[sayi].soyad[i] = soyad[i];
      }
    }
  }else printf("Dolu bro\n");

}

void print(nodem array[], int say){
  int i ;
  for ( i = 0; i < say; i++) {
    printf("%d %s\n ",array[i].no,array[i].ad);
  }
}

void sifirla(nodem array[],int say){
  int i = 0;
  for(i = 0; i< say; i++){
    array[i].no = -1;
  }
}






int main(int argc, char const *argv[]) {

  int sayi;
  printf("Kullanici Sayisi Giriniz:\n ");
  scanf("%d",&sayi );

  nodem array[sayi];

  sifirla(array,sayi);

  while (1) {
    int a;
    printf("ekleme icin 1, listelemek icin 2, aramak icin 3\n ");
    scanf("%d",&a);
    if (a==1)add(array,sayi);
    if (a==2)print(array,sayi);
    if (a==3){
      int numara,result;
      printf("mus no giriniz:\n");
      scanf("%d",&numara);
        
        
      result=arama(array,numara,sayi);
      if (result > 0)printf("%d.inci adimda bulundu \n",result);
      else  printf("Bulunamadi..\n");
    }
    else break;
  }

  return 1;
}
