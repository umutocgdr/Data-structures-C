#include <stdio.h>
#include <stdlib.h>

struct Node{

  char film[100];
  float puan;

  struct Node *next;

};

struct Node *inputStack=NULL, *tempStack = NULL, *tmp, *new, *temp;



void push(char dizi[50], float imdb){

  int counter = 0;

  if (inputStack == NULL){
    inputStack = (struct Node*)malloc(sizeof(struct Node));
    inputStack->next = NULL;
  }
  for(counter = 0; dizi[counter]!= NULL; counter++){
    inputStack->film[counter] = dizi[counter];
  }
  inputStack->puan = imdb;
    new = (struct Node*)malloc(sizeof(struct Node));
  new->next = inputStack;
  inputStack = new;


}

struct Node *pop(){

  if(inputStack== NULL){
    return NULL;
  }else {
    tmp = inputStack;
    inputStack = inputStack->next;
    return tmp;
  }
}


void siraliEkle(struct Node *new){

  int i;
  if(tempStack == NULL){
    tempStack = (struct Node*)malloc(sizeof(struct Node));
    for(i = 0; new->film[i]!= NULL; i++){
      tempStack->film[i] = new->film[i];
    }
    tempStack->puan = new->puan;
    tempStack->next = NULL;
  }else{
    if (tempStack->puan > new->puan) {
      temp = (struct Node*)malloc(sizeof(struct Node));
      for(i = 0; new->film[i]!= NULL; i++){
        temp->film[i] = new->film[i];
      }
      temp->puan = new->puan;
      temp->next = tempStack;
      tempStack = temp;
    }else{
      tmp = tempStack;
      temp = (struct Node*)malloc(sizeof(struct Node));
      for(i = 0; new->film[i]!= NULL; i++){
        temp->film[i] = new->film[i];
      }
      temp->puan = new->puan;
      temp->next = NULL;
      while (!tmp) {
        if((tmp->puan) < (new->puan)){
          if (tmp->next == NULL) {
             
            temp->next = NULL;
            tmp->next = temp;
            break;
          }
        }else if (tmp->next->puan > new->puan) {
            
          temp->next = tmp->next;
          tmp->next = temp;
          break;
        }
        tmp = tmp->next;
      }
    }
  }
}



int main(int argc, char const *argv[]) {
    
 FILE *file;
  file = fopen("/Users/umut/Desktop/171220036_veri_yap_odev1 copy/u.txt","tempStack ");
  char dizi[50];
  int counter = 0,a,b,j,k;
  float f;
  char c;
  char alfabe[25],junk;
    
  do {
       c = getc(file);
       if(c == 44){
         getc(file);
         a = (int)(getc(file));
         a = a-48;
         getc(file);
         b = (int)(getc(file));
         b = b-48;
         f = (float)(a) + ((float)(b)/10);
         push(dizi,f);
         for(j=0;j<=counter;j++ ){
           dizi[j] = NULL;
         }
         counter = 0;
       }else if(c != 44){
         dizi[counter] = c;
         counter++;
       }
     } while (c != EOF);
    
   tmp = inputStack;
   
   while (tmp != NULL ){
     printf("%s: %.1f\n",tmp->film,tmp->puan);
     tmp = tmp->next;
   }
    
  printf("\n\n\n\n\n\n\n\n\n");
    
    
    
   
 tmp = pop();tmp = pop();
    while (tmp != NULL) {
      siraliEkle(tmp);
        tmp = pop();
    }
      if(inputStack==NULL){
          printf("\n suan stack bos");
      }
    
    
      printf("\n\n\n\n\n\n\n\n\n");
    
    tmp = tempStack;
  while (tmp != NULL) {
    printf("%s : %.1f \n",tmp->film,tmp->puan );
    tmp = tmp->next;
  }

  return 0;
}
