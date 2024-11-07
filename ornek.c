#include <stdio.h>
void updateValue(int **ptr2) {
    **ptr2 = 20;
}

int main() {
    int var = 10;
    int *ptr = &var;
    int **ptr2 = &ptr;

    updateValue(ptr2);

    printf("Updated Value: %d", var); // 20 yazdýrýr
}

