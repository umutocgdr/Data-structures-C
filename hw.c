/*Alfabe={a,b,c,d,e,f}
Frekans={2,3,6,1,5,4}

A) Yukarıdaki içeriği verilen bir metin dosyasındaki tüm harfler ve harflerin frekans bilgileri
tek yönlü bir bağlı listeye eklenecektir.
- Kullanıcı isterse yeni harf ve frekans bilgisi ekleyebilecektir. Ekleme harf sırasına
göre yapılacaktır. Bu harfin daha önceden olup olmadığı kontrol edilecektir (harf
tekrarı olmayacaktır) .
Kullanıcı isterse var olan bir harfi frekans bilgisi ile birlikte silebilecektir.

Örnek bir veri yapısı aşağıda verilmiştir.
Struct Liste
{
Char harf;
int frekans;
Struct Liste *sonraki;
}
B) Yukarıdaki bağlı liste yapısı kullanılarak kullanıcıdan kaç harf istediği (n) sorulacaktır.
İstenilen bu sayıya göre random n tane birbirinden farklı harf belirlenecek ve frekans
değerleri dikkate alınarak random bir veri oluşturulup ekrana yazdırılacaktır.
Örnek1: Bir sayı giriniz (n): 3
d, e, b sıralı olarak seçilmiş olduğunu varsayalım;
d-> 1
e-> 5
b-> 3 ise;
Sonuç Çıktı: deeeeebbb
-----------------------------------------------------------
Örnek2: Bir sayı giriniz (n): 4
d, f, a, b sıralı olarak seçilmiş olduğunu varsayalım;
Sonuç Çıktı: dffffaabbb
a, 2 b, 3 c, 6 d, 1 e, 5 f, 4

C) Kullanıcıdan bir veri girilmesi istenecektir. Bu verinin, bağlı listedeki harf ve frekans
değerlerine göre elde edilip edilmediği kontrol edilecektir. Uygun değilse yanlış yazılan harf
ve frekansı ekrana yazdırılacaktır.

Bir karakter dizisi giriniz... dffffaabbb
Bu veri uygundur.
----------------------------------------------
Bir karakter dizisi giriniz... aaffffbbb
Bu veri uygundur.
----------------------------------------------
Bir karakter dizisi giriniz... aaffffbb
Bu veri uygun değildir. Çünkü b nin frekansı 3tür. Kullanıcı ise b harfini 2 kez girmiştir.
Not:
1) Kopya ödevlere -50 puan verilecektir.
2) Program dosyaları Öğrenci_No_Veri_Yap_Odev1.rar (1512XX0XX_veri_yap_odev1.rar)
formatında olmak zorundadır. Kodlarınıza açıklama satırları eklemek zorunludur.
3) Ödevler 16 Ekim 2019 Çarşamba günü saat 23:55’e kadar Google Classroom sistemine
yüklenecektir. Mail yoluyla gönderilen ödevler kesinlikle kabul edilmeyecektir. Bu tarihten sonra
teslim edilecek ödevler değerlendirmeye alınmayacaktır.
4) Ödev grupları duyurulacaktır. Her öğrencinin hangi gruptaysa o hocanın duyurduğu saatte ve
yerde ödev kontrolüne gitmesi zorunludur.*/

//kütüphane tanımları
// oneda 3 4  açlışıyor
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"

//struct yapımı oluşturuyorum
struct n{
 int frekans;
 char harf;
 struct n * next;
};

typedef struct n node;
FILE* dosya;

//listlema fonksşyonu
void listle( node *  r){
  node * go=r;
  printf("%c%d  ", go->harf,go->frekans);
  go = go -> next;
 while (go != NULL){
  printf("%c%d  ", go->harf,go->frekans);
  go = go -> next;
 }
 printf("\n");
}



//sirali ekleme fonksiyonum
node * ekleSirali ( node * r, char har,int frekans){
 if( r == NULL){
  r = (node *) malloc ( sizeof ( node) );
  r -> next = NULL;
  r -> frekans = frekans;
    r -> harf = har;
  return r;
 }
    
 if(r->harf > har){
  node * temp = ( node * ) malloc ( sizeof ( node ) );
  temp -> frekans = frekans;
    temp -> harf = har;
  temp -> next = NULL;
  node * go=r;
  while(go->next!=NULL){
    go=go->next;
  }
  go->next=temp;
  return temp;
 }
 node * go = r;
 while( go -> next != NULL && go -> next -> harf < har ){
  go = go -> next;
 }

 node * temp = (node*)malloc(sizeof(node));
 temp->next = go->next;
 go->next = temp;
 temp->frekans = frekans;
  temp -> harf = har;
 return r;
}
//silme fonksiyonumuz
node * sil(node *r,char harf){
 node *temp;
 node *go = r;
 if( r->harf == harf){
   while(go->next!=NULL){
     go=go->next;
   }
   go->next=r->next;
   free(r);
   return go->next;
 }

 while ( go->next != NULL && go->next->harf != harf){
  go = go->next;
 }
 if ( go->next == NULL){
  printf( "deger bulunamadi!\n" );
  return r;
 }
 temp = go->next;
 go->next = go->next->next;
 free (temp);
 return r;
}

int boyutAl(node *  r){
  int counter = 0;

    node * go=r;
//  printf("%c %d  ", go->harf,go->frekans);
    go = go -> next;
    counter++;
   while (go->next != NULL){
     counter++;
//    printf("%c %d  ", go->harf,go->frekans);
    go = go -> next;
   }
   printf("\n");
   return counter;
}

int main(int argc, char const *argv[]) {
    
    /*
           Alfabe={a,b,c,d,e,f}
           Frekans={2,3,6,1,5,4}
           A) Yukarıdaki içeriği verilen bir metin dosyasındaki tüm harfler ve harflerin frekans bilgileri
           tek yönlü bir bağlı listeye eklenecektir.
           */
    char alfabe[20],junk;
      int frekans[20],i=0,kullanilanlar[10];
      int frek,istenen,random,flag=0;
      char har;
      node * root;
    char t;
    int e;
    root=NULL;
      dosya = fopen("/Users/umut/Desktop/C/v.txt","r");
      while(!feof(dosya)){
        fscanf(dosya,"%s",&alfabe);
        for (i=0;i<(strlen(alfabe)+1)/2;i++){
          fscanf(dosya,"%d",&frekans[i]);
          fscanf(dosya,"%c",&junk);
        }
      }
      for (i=0;i<(strlen(alfabe)+1)/2;i++){
        har = alfabe[i*2];
        frek = frekans[i];
      root=ekleSirali(root,har,frek);
      }
      listle(root);

    
    while(1){
    printf("\n silme yapmak için 1\n ekleme yapmak için 2\n b fonksiyonu için 3\n c fonksiyonu için 4\n" );
        int o;
    scanf("%d",&o);
    if(o==1){

//         Kullanıcı isterse var olan bir harfi frekans bilgisi ile birlikte silebilecektir.
        char f;
        printf("silmek istediginiz degiskeni giriniz\n");
            scanf("%s",&f);
        sil(root,f);
        listle(root);
        }

    if(o==2){
        /*
              - Kullanıcı isterse yeni harf ve frekans bilgisi ekleyebilecektir. Ekleme harf sırasına
              göre yapılacaktır. Bu harfin daha önceden olup olmadığı kontrol edilecektir (harf
              tekrarı olmayacaktır) .
            */
        
           
         printf("deger giriniz\n");
         scanf("%c",&t);
         scanf("%d",&e);
         
         ekleSirali(root, t, e);
         listle(root);
      
    }
    if (o==3) {
        /*
        Struct Liste
        {
        Char harf;
        int frekans;
        Struct Liste *sonraki;
        }
        B) Yukarıdaki bağlı liste yapısı kullanılarak kullanıcıdan kaç harf istediği (n) sorulacaktır.
        İstenilen bu sayıya göre random n tane birbirinden farklı harf belirlenecek ve frekans
        değerleri dikkate alınarak random bir veri oluşturulup ekrana yazdırılacaktır.
        Örnek1: Bir sayı giriniz (n): 3
        d, e, b sıralı olarak seçilmiş olduğunu varsayalım;
        d-> 1
        e-> 5
        b-> 3 ise;
        Sonuç Çıktı: deeeeebbb
        -----------------------------------------------------------
        Örnek2: Bir sayı giriniz (n): 4
        d, f, a, b sıralı olarak seçilmiş olduğunu varsayalım;
        Sonuç Çıktı: dffffaabbb
        a, 2 b, 3 c, 6 d, 1 e, 5 f, 4
        */
       printf("kac harf isti\n");
        scanf("%d",&istenen);
      srand(time(NULL));

        for (int k=0;k<istenen;k++){

          random=rand()%boyutAl(root);

          while(1){
            for (int m=0;m<10;m++){
              flag=0;
              if(kullanilanlar[m] == random){
                flag = 1;
                random=rand()%boyutAl(root);
              }

            }
            if (flag==0){
              kullanilanlar[k]=random;
              break;
            }
          }


//          printf("%d: ",random );
          node * go=root;
            
          for (int i=0;i<random;i++){
            go = go->next;
          }
          for (int l=0;l<go->frekans;l++){
            printf("%c",go->harf );
          }

        }
        
    }
    if (o==4) {
        /*
        C) Kullanıcıdan bir veri girilmesi istenecektir. Bu verinin, bağlı listedeki harf ve frekans
        değerlerine göre elde edilip edilmediği kontrol edilecektir. Uygun değilse yanlış yazılan harf
        ve frekansı ekrana yazdırılacaktır.

        Bir karakter dizisi giriniz... dffffaabbb
        Bu veri uygundur.
        ----------------------------------------------
        Bir karakter dizisi giriniz... aaffffbbb
        Bu veri uygundur.
        ----------------------------------------------
        Bir karakter dizisi giriniz... aaffffbb
        Bu veri uygun değildir. Çünkü b nin frekansı 3tür. Kullanıcı ise b harfini 2 kez girmiştir.
        
         */
        
        char kelime[20],suanki;
        int k=0,counter=1,a=0;
        char alfabe2[20];
        int frekans2[20];
        printf("\n" );
        scanf("%s",&kelime);
        suanki = kelime[k];

        while(k<strlen(kelime)){
          if (kelime[k+1] == suanki){
            counter++;
          }
          else{
            alfabe2[a] = suanki;
            frekans2[a] = counter;
            suanki = kelime[k+1];
            counter=1;
            a++;
          }
          k++;
        }
        int coon=0;
        for (int q=0;q<strlen(alfabe2);q++){
                 printf("%c %d\n",alfabe2[q],frekans2[q] );
                   
                
               }
        for (int q=0;q<strlen(alfabe2);q++){
        node * tmp=root;
            while( tmp->next != NULL){
           
                if(tmp->frekans==frekans2[q]&&tmp->harf==alfabe2[q]){
                    coon++;
                }
                  tmp = tmp->next;
                 }
            }
        if(coon==strlen(alfabe2)){
            printf("true ");
            
        }
        else {
            
            printf("false ");
        }
        coon=0;
    }
    }
  return 0;
}
