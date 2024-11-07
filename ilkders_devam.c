#include <stdio.h>
int main(){
	
	int *x;
	int y = 7;
	x = &y;
	y= ((*x) + 1) <<1; //ikili tabanda sola kaydiriyormus yani 111 = 7 ise 1110 oluyor bu da 14'e eşit
	printf("%d",y);
}
