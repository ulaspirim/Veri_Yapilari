#include <stdio.h>
int main(){
	int a=5;
	int *b;
	int **c;
	int ***d;
	printf("%d \n",a);
	b=&a;   //b,a'n�n ram'deki yerini tutar
	
	printf("%d \n",b);
	c=&b;   //c,b'nin "" "" ""
	
	printf("%d \n",c);
	d=&c;   //d,c'nin "" "" ""
	
	printf("%d \n",d);
	c++;    //c'nin tuttu�u de�er 1 artar yani sall�yoruz 180 ise 181 olur
	***d++; //d, asl�nda a'y� tuttu�u i�in a'n�n de�eri art�k 6 olur 
	
	printf("d \n",a);
}
