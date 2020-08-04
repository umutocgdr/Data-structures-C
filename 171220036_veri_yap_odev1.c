/*
 Uygulamada metin dosyasından okunacak films ve filmslere ait IMDB puan bilgilerinin tutulabileceği tek yönlü bağlı liste şeklinde inputStack ve
aynı yapıya sahip geçici bir yığın olan tmpStack isimlerinde 2 adet yığın (stack) veri yapısı tanımlanacaktır
a) Metin belgesindeki tüm bilgiler okunacak ve okunan bilgilerin yığın mantığına göre inputStack yığınına eklenmesi sağlanacaktır.
b) sortStack() fonksiyonu yazılacaktır. Bu fonksiyon kendisine parametre olarak gelen inputStack yığınındaki filmsleri ikinci yığın olan
tmpStack yığınını kullanarak IMDB puanına göre sıralayacaktır.
(Sıralama işleminin yapılabilmesi için her iki yığın yapısında da gerekli olan yığına ekleme ve yığından çıkarma işlemleri
geçekleştirilmelidir.)
c) filmslerin IMDB puanına göre sıralı olduğu yığın yapısı ekrana yazdırılacaktır.
 Sıralama işlemi yalnızca iki yığın arasında elemanların IMDB puanına göre karşılaştırılarak yığınlar arasında gerekli
 transferlerin yapılması ile gerçekleştirilecektir.

 171220036_veri_yap_odev1
 */


#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
 int count = 0;
struct films
{
    float puan;
    char name[20];
    struct films *next;
}*top,*top1,*temp;



void push(float puan)
{
    if (top == NULL)
    {
        top =(struct films *)malloc(1*sizeof(struct films));
        top->next = NULL;
        top->puan = puan;
//        top->name = name;
    }
    else
    {
        temp =(struct films *)malloc(1*sizeof(struct films));
        temp->next = top;
        temp->puan = puan;
        //        top->name = name;
        top = temp;
    }
    count++;
}

void display()
{    printf("\n birinci yığın");
    top1 = top;
    if (top1 == NULL)
    {
        printf("\n Error ");
        return;
    }
    while (top1 != NULL)
    {
        printf("%s,%f ",top1->name, top1->puan);
        top1 = top1->next;
    }
 }
 int countt = 0;
struct filmst
{
    float puan;
    char name[20];
    struct filmst *next;
}*topt,*top1t,*tempt;

void pusht(float puan)
{
    if (topt == NULL)
    {
        topt =(struct filmst *)malloc(1*sizeof(struct filmst));
        topt->next = NULL;
        topt->puan = puan;
//        top->name = name;
    }
    else
    {
        tempt =(struct filmst *)malloc(1*sizeof(struct filmst));
        tempt->next = topt;
        tempt->puan = puan;
        topt = tempt;
    }
    countt++;
}
void displayt()
{
    printf("\n ikinci yığın");
    top1t = topt;
    if (top1t == NULL)
    {
        printf("\n Error ");
        return;
    }
    while (top1t != NULL)
    {
        printf("%s,%f ",top1t->name, top1t->puan);
        top1t = top1t->next;
    }
 }

FILE *file;
int main()
{

    top = NULL;//bu input stact  create etmek
    topt= NULL;// buda temp stact create etmek
    //    top->puan sı top element
    //stact kac eleman olduğu count tutuyor
//    top == NULL sa stack boş

 /*file=fopen("/Users/umut/Documents/C/u.txt","r");
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
 }*/

    float  ek = 10.0;

    push(1.1);
    push(3.3);
    push(2.2);
    push(1.8);
    // dosya oku
    //sıralı yıgına at
    // ve bu fonksiyonu yap
    int j;
    display();
        temp=top;
    for(j=0;j<12;j++){
        if(temp->puan < ek ){
            ek=temp->puan;
        }
        temp= temp->next;
    }
        pusht(ek);
        del(&top,ek);

    printf("\n degisimlerden sonra");
    display();
    displayt();
    return 0;
}
