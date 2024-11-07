#include  <stdio.h>

int main (){
	
	int a, b, i, *ptr;
	printf("Boyut giriniz: ");
	scanf("%d",&a);
	ptr = (int *)malloc (a * sizeof(int));
	
	for(i=0; i<a; i++){
		printf("%p \t", *(ptr+i));
		printf("%d \n", *(ptr+i));
	}
	
	*(ptr+0) = 1;
	*(ptr+1) = 2;
	*(ptr+2) = 3;
	
	printf("\n\n");
	for(i=0; i<a; i++){
		printf("%p \t", *(ptr+i));
		printf("%d \n", *(ptr+i));
	}
	//Bu for döngüsünde bir hata olabilir. Çünkü ram'deki deðerler de 00001 falan oldu
}
