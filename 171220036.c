



//171220036 umut öçgüder

#include"stdio.h"
#include"stdlib.h"
#include"string.h"

    typedef struct stack{
        int veri;
     struct stack *next;
    }yigin;
yigin * head ;

 char array [ 50 ] ;
 int uznlk=0,b=1,verim,datam,reslt=0,j=0;

 void eklemefonks(int value){
         yigin* eklemefonks=new yigin;
            eklemefonks -> veri = value ;
            eklemefonks -> next = NULL;
            if(head == NULL) head=eklemefonks;
            else{eklemefonks->next=head ;
                head=eklemefonks;}
        }

 int Check(){
     if(head==NULL)
            return 0;
            else
            return 1;
        }
int cikartmafonks(){
            int value;
            yigin *temp;
            temp=head;
            if(Check()==1)
            {
            value=temp->veri;
            head=head->next;
            free(temp);
            return value;
            }
            else return 0;
        }
            
        void Hesapla(){
          for(  int a=0;array[a]!='\0';a++)
                     {
            if( array[a]!=' ')
             {
              if( array[a]!='+' && array[a]!='-' && array[a]!='*' && array[a]!='/' )
               {
                if( array[a+1]!= ' ' && array[a+2]!= ' ' &&  array[a+3]!= ' ' && array[a+4]!= ' ' && array[a+5]==  ' '  )
                 {
                    j=array[a];
                   j=((array [a]-48 )*1000) + ((array[a]-48 )*1000) + ((array [a+1]-48)*100) + ((array [a+2 ]-48)*10) + (array [a+3]-48);
                   eklemefonks  (j);
                   a+=4; }
 else if(array[a+1]!=' ' && array[a+2]!=' ' && array[a+3]!=' ' && array[a+4]==' ')
                 {
                    j=array[a];
                   j=((array[a]-48)*1000) + ((array[a+1]-48)*100) + ((array[a+2]-48)*10) + (array[a+3]-48);
                   eklemefonks(j);
                   a+=3;
                 }
          else if(array[a+1]!=' ' && array[a+2]!=' ' && array[a+3]==' ')         {
                    j=array[a];
        j=((array[a]-48)*100)+((array[a+1]-48)*10)+(array[a+2]-48);
                   eklemefonks(j);
                   a=a+2;
                 }
                else if(array[a+1]!=' ' && array[a+2]==' ')
                     {  j=array[a]-48;
                j *=10;
               j+=(array[a+1]-48);
               eklemefonks(j);
                a++;
                 }
                else
                 {  j=array[a]-48;
                   eklemefonks(j);
                  }
        } else{
                verim = cikartmafonks();
                datam = cikartmafonks();
                  if(array[a]=='+'){ reslt=verim+datam;}
                else if(array[a]=='*'){ reslt=verim*datam;}
              else if(array[a]=='/'){reslt=verim/datam;}
            else if(array[a]=='-'){reslt=verim-datam;}
                eklemefonks(reslt);
               }
             }
           } printf("\n\t%d\n",cikartmafonks());
    }

    int main()
    {
    char mystring[50];
printf("lütfen bir giris yapınız --->") ; gets(mystring) ;
    int j,Counter=0;
        for(j=0;mystring[j]!=NULL;j++){
            Counter++;}
    uznlk=Counter;
        int a=0;
    for(j=Counter-1;j>=0;j--)
    { array[a]=mystring[j];
        a++;}
     Hesapla();
        b=1;
    }
