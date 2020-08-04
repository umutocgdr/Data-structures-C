#include <stdio.h>
#include <stdlib.h>

struct Node{

  char adi[100];
  float puan;

  struct Node *next;

};

struct Node *inputStack=NULL, *tempStack = NULL, *gecici, *yeni, *temp;
FILE *db;

struct Node *dugumOlustur(){
  gecici =  (struct Node*)malloc(sizeof(struct Node));
  return gecici;
}

void push(char dizi[50], float imdb){

  int sayac = 0;

  if (inputStack == NULL){
    inputStack = dugumOlustur();
    inputStack->next = NULL;
  }
  for(sayac = 0; dizi[sayac]!= NULL; sayac++){
    inputStack->adi[sayac] = dizi[sayac];
  }
  inputStack->puan = imdb;
  yeni = dugumOlustur();
  yeni->next = inputStack;
  inputStack = yeni;


}

struct Node *pop(){

  if(inputStack->next == NULL){
    return NULL;
  }else {
    gecici = inputStack;
    inputStack = inputStack->next;
    return gecici;
  }
}





void siraliEkle(struct Node *yeni){

  int i;
  if(tempStack == NULL){ // ilk bossa
    tempStack = dugumOlustur();
    for(i = 0; yeni->adi[i]!= NULL; i++){
      tempStack->adi[i] = yeni->adi[i];
    }
    tempStack->puan = yeni->puan;
    tempStack->next = NULL;
  }else{
    if (tempStack->puan > yeni->puan) { // ilkten kucukse
      temp = dugumOlustur();
      for(i = 0; yeni->adi[i]!= NULL; i++){
        temp->adi[i] = yeni->adi[i];
      }
      temp->puan = yeni->puan;
      temp->next = tempStack;
      tempStack = temp;
    }else{
      gecici = tempStack;
      temp = dugumOlustur();
      for(i = 0; yeni->adi[i]!= NULL; i++){
        temp->adi[i] = yeni->adi[i];
      }
      temp->puan = yeni->puan;
      temp->next = NULL;
      while (!gecici) {
        if((gecici->puan) < (yeni->puan)){
          if (gecici->next == NULL) {
             
            temp->next = NULL;
            gecici->next = temp;
            break;
          }
        }else if (gecici->next->puan > yeni->puan) {
            
          temp->next = gecici->next;
          gecici->next = temp;
          break;
        }
        gecici = gecici->next;
      }
    }
  }
}

void tempYazdir() {


}
void printStack(){
  gecici = inputStack ->next;
    if(gecici==NULL){
        printf("bos");
    }
  while (gecici != NULL ){
    printf("%s: %.1f\n",gecici->adi,gecici->puan);
    gecici = gecici->next;
  }
}



int main(int argc, char const *argv[]) {
    
 
  db = fopen("/Users/umut/Desktop/171220036_veri_yap_odev1 copy/u.txt","r");
  char dizi[50];
  int sayac = 0,a,b,j;
  float f;
  char c;

  do {
       c = getc(db);
       if(c == 44){
         getc(db);
         a = (int)(getc(db));
         a = a-48;
         getc(db);
         b = (int)(getc(db));
         b = b-48;
         f = (float)(a) + ((float)(b)/10);
         push(dizi,f);
         for(j=0;j<=sayac;j++ ){
           dizi[j] = NULL;
         }
         sayac = 0;
       }else if(c != 44){
         dizi[sayac] = c;
         sayac++;
       }
     } while (c != EOF);

  printStack();
  printf("\n\n\n\n\n\n\n\n\n");
    
//    steği boşaltıyoruz
    gecici = pop();
    gecici = pop();
    while (gecici != NULL) {
      siraliEkle(gecici);
      gecici = pop();
    }
    
    
    printStack();
    
    
      printf("\n\n\n\n\n\n\n\n\n");
    
//  temp yazdirma
    gecici = tempStack;
  while (gecici != NULL) {
    printf("%s Puani: %.1f \n",gecici->adi,gecici->puan );
    gecici = gecici->next;
  }

  return 0;
}
