#include <stdio.h>

int main(){
	int *x;	
	int y = 7;
	int **z;
	x = &y;
	z = &x;
	
	y = ((*x)+1) /*1000 oldu */ << 1; //Bu kod sonras� 10000 oldu. O da 16'ya e�it
	*x = **z + 2;  //Bu kod ile 18'e e�it oldu
	printf("%d \t %d \t %d", y,x,z);
	
	
	**z = 1000;

    printf("\n%p", &z);   // '&z', 'z' pointer'�n�n bellekteki adresini yazd�r�r.
	printf("\n%p", z);    // 'z', 'x' pointer'�n�n adresini yazd�r�r.
    printf("\n%p", x);    // 'x', 'y' de�i�keninin adresini yazd�r�r.
    printf("\n%p", &x);   // '&x', 'x' pointer'�n�n bellekteki adresini yazd�r�r.
    printf("\n%p", y);    // '%p', ancak y bir pointer de�il. Bu yanl��t�r ve y'yi bellekteki adres gibi yazd�rmaya �al���r.
}
