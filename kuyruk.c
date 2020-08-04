#include "stdio.h"
#include "stdlib.h"

struct node{
  int veri;
  struct node *next;
};

struct node *ilk = NULL,*son = NULL, *temp,*gecici;

struct node *dugumOlustur(){
  struct node *yeni = (struct node*)malloc(sizeof(node *));
  return yeni;
}

void kuyrugaEkle(int x){//eklerken sona ekliyoruz.
  struct node *yeni = dugumOlustur();
  yeni -> veri = x;
  yeni -> next = NULL;
  if(ilk == NULL){
    ilk = yeni;
  }else{
    temp = ilk;
    while(temp -> next != NULL){
      temp = temp-> next;
    }
    temp -> next = yeni;
  }
}

void kuyruktanSil(){
  if(ilk -> next == NULL){
    ilk = NULL;
  }else{
    temp = ilk;
    while(temp -> next -> next != NULL){
      temp = temp -> next;
    }
    temp -> next = NULL;
  }
}

void yazdir(){
  if(ilk == NULL){
    printf("kuyruk boş");
  }else{
  temp = ilk;
  while(temp -> next != NULL){
    printf("%d ",temp -> veri);
    temp = temp -> next;
  }
  printf("%d",temp-> veri);
}
}

int main(int argc, char const *argv[]) {
  kuyrugaEkle(5);
  kuyrugaEkle(10);
  kuyrugaEkle(15);
  kuyruktanSil();
  yazdir();
  return 0;
}
