//
// Created by upup3 on 09/12/2024.
//

#include <stdio.h>
#include <stdlib.h>

struct queue {
	int front, rear, size;
	unsigned capacity;
	int *dizi;

};

struct queue *createQueue(unsigned capacity){
	struct queue *x = (struct queue*) malloc (sizeof(struct queue));
	x->capacity = capacity;
	int y = x->capacity;
	x->front = x->size = 0;
	x->rear = y-1;
	x->dizi = (int *) malloc (sizeof(int) * y);
	return x;
}

int isFull(struct queue *x){
	return(x->capacity == x->size);
}

int isEmpty(struct queue *x){
	return(x->size ==0);
}

int enqueue (struct queue *x, int a){
	if(isFull(x))
		return printf("\nKuyruk dolu");
	x->rear = (x->rear +1) % x->capacity;
	x->dizi[x->rear] = a;
	x->size++;
}

int dequeue (struct queue*x){
	if(isEmpty(x))
		return printf("\nKuyruk bos");
	int item = x->dizi[x->front];
	x->front = (x->front +1) % x->capacity;
	x->size--;
	return item;
}

void display(struct queue *x){
	int length = x->size;
	int tmp = x->front;
	printf("\n");
	while (length>0){
		printf("%d \t", x->dizi[tmp]);
		tmp++;
		length--;
	}
	
}

int main(){
	struct queue * yeni = createQueue(3);
	display(yeni);
	dequeue(yeni);
	enqueue(yeni,5);
	display(yeni);
	enqueue(yeni,6);
	display(yeni);
	enqueue(yeni,7);
	display(yeni);
	enqueue(yeni,8);
	display(yeni);
}
