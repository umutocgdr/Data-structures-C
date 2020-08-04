#include<stdio.h>
#include<stdlib.h>
typedef struct Liste{
                     int num;//her düðümün içinde tutacaðý deðer
                     Liste *sonraki;// sonraki düðümü gösteren pointer
                     }BListe;
BListe *ilk=NULL,*son=NULL;
BListe* BilgiAl(){
                  BListe * bilgi;
                  bilgi=(BListe*)malloc(sizeof(BListe));//yer ayýrdýk
                  puts("num gir");
                  scanf("%d",&bilgi->num);
                  bilgi->sonraki=NULL;
                  return bilgi;
                  }
void Ekle(BListe *bilgi){
                         if(ilk==NULL){
                                       ilk=bilgi;
                                       son=bilgi;
                                       }
                         else{
                             son->sonraki=bilgi;
                             son=bilgi;
                             son->sonraki=NULL;
                             }
                         }
void Listele(){
              BListe *gecici;
              int sayac=0;
              gecici=ilk;
              while(gecici){
                            printf("%d\t",gecici->num);
                            sayac++;
                            gecici=gecici->sonraki;
                            }
               printf("bagli listemde %d tane elemanim var\n",sayac);
               }
void Ters( BListe *gecici){
                          if(gecici!=NULL){
                          	 
                                           Ters(gecici->sonraki);
                                           printf("%d\n",gecici->num);
                                          
                            }
           }
void Sirala(){
              BListe *gecici,*gezici;
              int kova;
              gecici=ilk;
              gezici=gecici->sonraki;
              while(gecici){
                            while(gezici){
                                          if((gecici->num)<(gezici->num)){
                                                                          kova=gezici->num;
                                                                          gezici->num=gecici->num;
                                                                          gecici->num=kova;
                                                                          }
                                          else
                                          gezici=gezici->sonraki;
                                          }
                            gezici=gecici->sonraki;
                            gecici=gecici->sonraki;
                            }
              gecici=ilk;
              while(gecici){
                            printf("%d\t",gecici->num);
                            gecici=gecici->sonraki;
                            }
                            
              }
int Arama(int ara){
                  BListe *gecici;
                  gecici=ilk;
                  while(gecici){
                                if(gecici->num==ara){
                                                     printf("bulundu\n");
                                                     return 1;
                                                     }
                                else
                                gecici=gecici->sonraki;
                                }
                  return 0;
                 }
void *Sil(int n){
                   BListe *gecici;
                   BListe *onceki;
                   onceki=NULL;
                   gecici=ilk;
                   while(gecici!=NULL){
                                   if(gecici->num==n)break;
                                   onceki=gecici;
                                   gecici=gecici->sonraki;
                                   }
                   if(gecici!=NULL){//aranan kayýt bulundu ise
                                    if(gecici==ilk){//ilk dugummu
                                                    if(ilk->sonraki!=NULL){//listede birden cok dugum var
                                                    ilk=ilk->sonraki;
                                                    }
                                    else{//listede yalnýzca birdugum var
                                         ilk=NULL;
                                         son=NULL;
                                        }
                                   }
                   else{//aradan bir dugummu
                        if(gecici==son){//silinen son dugum ise
                                        onceki->sonraki=NULL;
                                        son=onceki;
                                        }
                        else
                        onceki->sonraki=gecici->sonraki;
                        }
                        }
               free(gecici);
               }
int main(){
          int sayi;
          BListe *a,*a1,*a2,*a3,*a4;
          a=BilgiAl();
          Ekle(a);
          a1=BilgiAl();
          Ekle(a1);
          a2=BilgiAl();
          Ekle(a2);
          a3=BilgiAl();
          Ekle(a3);
          a4=BilgiAl();
          Ekle(a4);
          Listele();
          printf("\naranacak numarayi gir\n");
          scanf("%d",&sayi);
          if(Arama(sayi)!=0)
          printf("buldukkk\n");
          else
          printf("yok ole biseyyy\n");
          Ters(ilk);
          Sirala();
          printf("\nsilinecek numarayi gir\n");
          scanf("%d",&sayi);
          Sil(sayi);
          Listele();
          getch();
         }
