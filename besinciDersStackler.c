#include <stdio.h>
#include <stdlib.h>

struct stack{
	int top;
	unsigned capacity;
	int *array;  //boyutu belli olmayan dizi tanýmlanacaðý için * kullandýk.
};

struct stack *createStack (unsigned capacity){
	struct stack *yeni = (struct stack *) malloc (sizeof (struct stack));
	yeni->capacity = capacity;
	yeni->top = -1;
	yeni->array = (int*) malloc (sizeof (int)* yeni->capacity);
	return yeni;
};

int isFull(struct stack *x){
	return x->top == x->capacity-1; //dizi[0]'dan baþlayacaðý için kapasite-1
}

int isEmpty(struct stack *x){
	return x->top ==-1;
}

void push (struct stack *x, int y){
	if (isFull(x)==1)
		return;
	x->array[++x->top] = y;
}

int pop(struct stack *x){
	if (isEmpty(x))
		return;
	int alinan = x->array[x->top];
	x->top = x->top -1;
	return alinan;
}

void lojik_ifade (int n){
	struct stack s;
	while (n>0){
		push (&s, n%2);
		n = n/2;
	}
	while (isEmpty (&s))
		printf("%d",pop(&s));
}

int main(){
	struct stack * yeni = createStack(10);
	push(yeni,1); push(yeni,2); push(yeni,3);
	int i = 1; int alinan;
	while (i<=3){
		alinan = pop(yeni);
		printf ("Alinan= %d\n",alinan);
		i++;
	}
	return 0;
}


