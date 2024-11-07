#include <stdio.h>

int main(){
	int *x;	
	int y = 7;
	int **z;
	x = &y;
	z = &x;
	
	y = ((*x)+1) /*1000 oldu */ << 1; //Bu kod sonrası 10000 oldu. O da 16'ya eşit
	*x = **z + 2;  //Bu kod ile 18'e eşit oldu
	printf("%d \t %d \t %d", y,x,z);
	
	
	**z = 1000;

    printf("\n%p", &z);   // '&z', 'z' pointer'ının bellekteki adresini yazdırır.
	printf("\n%p", z);    // 'z', 'x' pointer'ının adresini yazdırır.
    printf("\n%p", x);    // 'x', 'y' değişkeninin adresini yazdırır.
    printf("\n%p", &x);   // '&x', 'x' pointer'ının bellekteki adresini yazdırır.
    printf("\n%p", y);    // '%p', ancak y bir pointer değil. Bu yanlıştır ve y'yi bellekteki adres gibi yazdırmaya çalışır.
}
