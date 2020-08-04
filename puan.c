
#include <stdio.h>
int main(){
    float a,sonuc,b,kalan,kalanYeni,gereken;
    int c;
    while(1){
    printf("\nvize gir");
    scanf("%f",&a);
    c=40;
    kalan = a*0.4;
    kalanYeni = c-kalan;
    gereken = (kalanYeni * 100)/60;
    printf("\ndc %f",gereken);
    c=50;
    kalan = a*0.4;
    kalanYeni = c-kalan;
    gereken = (kalanYeni * 100)/60;
    printf("\ncc %f",gereken);
    c=58;
    kalan = a*0.4;
    kalanYeni = c-kalan;
    gereken = (kalanYeni * 100)/60;
    printf("\ncb %f",gereken);
    c=65;
    kalan = a*0.4;
    kalanYeni = c-kalan;
    gereken = (kalanYeni * 100)/60;
    printf("\nbb %f",gereken);
    c=74;
    kalan = a*0.4;
    kalanYeni = c-kalan;
    gereken = (kalanYeni * 100)/60;
    printf("\nba %f",gereken);
    c=82;
    kalan = a*0.4;
    kalanYeni = c-kalan;
    gereken = (kalanYeni * 100)/60;
    printf("\naa %f",gereken);
}
    return 0;
}
