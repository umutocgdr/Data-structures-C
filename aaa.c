
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int mus_no;
  char ad[50];
  char soyad[50];
}n;


int hash(int mus,int say){
  return  mus%say;
}

int dolumu(n dizi[],int say){

  int i,sayac = 0;
  for (i = 0; i < say; i++) {
    if(dizi[i].mus_no == -1){
      sayac++;
    }
  }
  if (sayac == 0) {
    return 1;
  }else{
    return -1;
  }
}

void ekle(n dizi[], int say, int mus_no, char ad[],char soyad[]){

  if (dolumu(dizi,say) == -1) {
    int i ;
    if (dizi[hash(mus_no, say)].mus_no == -1)  {
      dizi[hash(mus_no,say)].mus_no = mus_no;
      for (i = 0; i < 50; i++) {
        dizi[hash(mus_no,say)].ad[i] = ad[i];
        dizi[hash(mus_no,say)].soyad[i] = soyad[i];
      }
    }else{
      int sayi = hash(mus_no,say);
      while (dizi[sayi].mus_no != -1) {
        sayi++;
      }
      dizi[sayi].mus_no = mus_no;
      for (i = 0; i < 50; i++) {
        dizi[sayi].ad[i] = ad[i];
        dizi[sayi].soyad[i] = soyad[i];
      }
    }
  }else{
    printf("Dolu \n");
  }

}

int arama(n dizi[],int mus, int say){

  int sayac=1;
  if(dizi[hash(mus,say)].mus_no == mus){
    printf("\nBulunan kisinin bilgileri : mus_no: %d ad: %s soyad: %s\n",dizi[hash(mus,say)].mus_no,dizi[hash(mus,say)].ad,dizi[hash(mus,say)].soyad);
    return 1;
  }else{
    int i;
    i = hash(mus,say);
    while (dizi[i].mus_no == mus || i<say) {
      i++;
      sayac++;
      if (dizi[i].mus_no == mus) {
        printf("\nBulunan kisinin bilgileri : %d %s %s\n",dizi[i].mus_no,dizi[i].ad,dizi[i].soyad);
        return sayac;
      }
    }
    return -1;
  }

}

void listele(n dizi[], int say){
  int i ;
  printf("\n");
  for (i = 0; i < say; i++) {
    printf("%d %s %s\n", dizi[i].mus_no,dizi[i].ad,dizi[i].soyad);
  }
  printf("\n");
}

void dizisifirla(n dizi[],int say){
  int i = 0;
  for(i = 0; i< say; i++){
    dizi[i].mus_no = -1;
  }
}

int main(int argc, char const *argv[]) {

  int kullanici_say;

  printf("Kullanici Sayisi Giriniz:\n");
  scanf("%d",&kullanici_say );

  n dizi[kullanici_say];

  dizisifirla(dizi,kullanici_say);

  while (1) {
    int a;
    printf("ekleme icin 1, listelemek icin 2, aramak icin 3\n");
    scanf("%d",&a );
    if (a== 1) {
      int mus_no;
      char ad[50],soyad[50];
      printf("musteri no giriniz:  \n");
      scanf("%d",&mus_no );
      printf("isim :\n");
      scanf("%s",&ad );
      printf("soyisim:\n");
      scanf("%s",&soyad );
      ekle(dizi,kullanici_say,mus_no,ad,soyad);
    }else if (
              a == 2) {
      listele(dizi,kullanici_say);
    }else if(a == 3){
      int mus;
      printf("mus no giriniz:\n");
      scanf("%d",&mus );
      int sonuc=arama(dizi,mus,kullanici_say);
      if (sonuc > 0) {
        printf("%d.inci adimda bulundu \n",sonuc);
      }else{
        printf("Bulunamadi..\n");
      }
    }else {
      break;
    }
  }

  return 0;
}
