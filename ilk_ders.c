#include <stdio.h>
int main(){
	int a=5;
	int *b;
	int **c;
	int ***d;
	printf("%d \n",a);
	b=&a;   //b,a'nın ram'deki yerini tutar
	
	printf("%d \n",b);
	c=&b;   //c,b'nin "" "" ""
	
	printf("%d \n",c);
	d=&c;   //d,c'nin "" "" ""
	
	printf("%d \n",d);
	c++;    //c'nin tuttuğu değer 1 artar yani sallıyoruz 180 ise 181 olur
	***d++; //d, aslında a'yı tuttuğu için a'nın değeri artık 6 olur 
	
	printf("d \n",a);
}
