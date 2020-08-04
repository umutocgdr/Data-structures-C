#include "stdio.h"
#include "stdlib.h"


struct node{
  int veri;
  struct node *next;
};

struct node* temp,*ilk = NULL,*gecici;

struct node *dugumOlustur(){
  struct node* yeni = (struct node*)malloc(sizeof(node*));
  return yeni;
}

void basaekle(int x){
  struct node *yeni = dugumOlustur();
  yeni -> veri = x;
  temp = ilk;
  yeni -> next = temp;
  ilk = yeni;
}

void sonaekle(int x){
  struct node *yeni = dugumOlustur();
  yeni -> veri = x;
  yeni -> next = NULL;
  if(ilk == NULL){
    ilk = yeni;
  }else{
    temp = ilk;
    while(temp->next != NULL){
      temp = temp->next;
    }
    temp -> next = yeni;
  }
}

  void arayaekle(int indis,int x){
    int sayac = 0;
    struct node* yeni = dugumOlustur();
    yeni -> veri = x;
    temp = ilk;

    if(ilk == NULL){
      basaekle(x);
    }else{
      while(temp != NULL){
        if (sayac+1 == indis) {
          break;
        }
        temp = temp -> next;
        sayac++;
      }
      gecici = temp -> next;
      temp -> next = yeni;
      yeni -> next = gecici;
    }
  }

  void yazdir(){
    temp = ilk;
    if(ilk == NULL){
      printf("eleman yok");
    }else{
      while(temp -> next != NULL){
        printf("%d ",temp->veri);
        temp = temp->next;
      }      
    }
  }


int main(int argc, char const *argv[]) {
  basaekle(5);
  sonaekle(7);
  arayaekle(1,6);
  yazdir();
  return 0;
}
