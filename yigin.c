#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define boyut 5

int yigin[boyut -1];
int top = -1;

bool dolumu(){
  if( top >= boyut -1){
    return true;
  }else{
    return false;
  }
}

bool bosmu(){
  if(top < 0){
    return true;
  }else{
    return false;
  }
}

void ekle(int x){
  bool control = dolumu();
  if(control == false){
    top = top + 1;
    yigin[top] = x;
  }else{
    printf("hata");
  }
}

void cikar(){
    bool control = bosmu();
    if(control == false){
      top = top -1;
    }
}

void yazdir(){
  int i;
  for(i=0;i<top +1;i++){
    printf("%d ",yigin[i]);
  }
}

int main(int argc, char const *argv[]) {
  ekle(5);
  ekle(10);
  yazdir();
  cikar();
  yazdir();
  return 0;
}
