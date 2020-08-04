#include "stdio.h"
#include "stdlib.h"


struct node{
  int veri;
  struct node *next;
  struct node *prev;
};

struct node *ilk = NULL, *temp, *gecici;

struct node *dugumOlustur(int x){
  struct node *yeni = (struct node*)malloc(sizeof(struct node*));
  yeni -> veri = x;
  yeni -> next = NULL;
  yeni -> prev = NULL;
  return yeni;
}

void basaekle(int x){
  temp = ilk;
  struct node *yeni = dugumOlustur(x);

  if(ilk == NULL){
    ilk = yeni;
    return;
  }

  ilk -> prev = yeni;
  yeni -> next = ilk;
  ilk = yeni;
}

void sonaekle(int x){
  struct node* yeni = dugumOlustur(x);

  if(ilk == NULL){
    ilk = yeni;
  }else{
    temp = ilk;
    while(temp -> next != NULL){
      temp = temp -> next;
    }
    yeni -> prev = temp;
    temp -> next = yeni;
  }
}

void arayaekle(int indis,int x){
  int sayac = 0;
  struct node *yeni = dugumOlustur(x);

  if(ilk == NULL){
    ilk = yeni;
  }else if ( ilk -> veri == indis){
    basaekle(x);
  }else{
    while(temp -> next != NULL){
      if(temp -> veri == indis){
          gecici = temp -> prev;
          break;
      }
      temp = temp -> next;
    }
    temp -> prev = yeni;
    yeni -> next = temp;
    yeni -> prev = gecici;
    gecici -> next = yeni;
  }
}

void yazdir(){
  temp = ilk;
  while(temp != NULL){
    printf("%d ",temp -> veri);
    temp = temp -> next;
  }
}

int main(int argc, char const *argv[]) {

  basaekle(5);
  sonaekle(7);
  yazdir();
  return 0;
}
