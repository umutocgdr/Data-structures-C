
#include<stdio.h>
#include<conio.h>
#include<locale.h>
#include<stdlib.h>

void clrscr()
{
	system("@cls||clear");
}





int max = 0;

int iterasyon = 0;


int recursiveMaxDiziElemani(int dizi[], int elemanSayisi)
{
	if(elemanSayisi == 0)
	{
		return max;
	}
	
	else
	{
		if(dizi[elemanSayisi-1] > max)
		{
			max = dizi[elemanSayisi-1];
		}
		
		recursiveMaxDiziElemani(dizi,elemanSayisi-1);
	}
}




int main()
{
	setlocale(LC_ALL, "Turkish");		// Türkçe Karakter Kullanmak Ýçin
	
	int array[10] = {9999,2,32,2,2,312,3,12,9};
	
	
	
	for(int i=0; i<10; i++)
	{
		printf("%d. eleman -> %d\n",i,array[i]);
	}
	
	
	recursiveMaxDiziElemani(array,10);
	
	printf("\n\n\n\t\t\tDizideki max eleman -> %d",max);
	
	getch();
	return 0;
}
