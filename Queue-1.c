#include <stdio.h>
#include <stdlib.h>

//Enqueue kuyruklamadýr.
/* 1.Dolu kontrolü yapýlmalýdýr
   2.Dolu ise fonksiyondan çýkar
   3.Dolu deðilse rear arttýr.
   4.Rear noktasýna eleman ekle
   5.Ýþlemi bitir
*/
//Dequeue kuyruktan eleman almadýr.

struct queue{
	unsigned capacity;
	int front, size, rear;
	int *array;
};

struct queue *createQueue(unsigned capacity){
	struct queue *yeni = (struct queue*) malloc (sizeof(struct queue));
	yeni->capacity = capacity;
	yeni->size = yeni->front = 0;
	yeni->rear = yeni->capacity-1;
	yeni->array = (int *) malloc (yeni->capacity * sizeof(int));
	return yeni;
}

int isFull(struct queue *x){
	return(x->capacity == x->size);
}

int isEmpty(struct queue *x){
	return(x->size ==0);
}

void enqueue(struct queue *x, int y){
	if(isFull(x))
		return;
	x->rear = (x->rear +1) % x->capacity;
	x->array[x->rear]=y;
	x->size ++;
}
	
int dequeue (struct queue *x){
	if(isEmpty(x))
		return;
	int item = x->array[x->front];
	x->front = (x->front +1) % x->capacity;
	x->size --;
	return item;
}

/*Bu çalýþmazsa
void bastir(struct queue *x) {
    if (isEmpty(x)) {
        printf("Queue bos.\n");
        return;
    }
    
    printf("Queue elemanlari: ");
    int index = x->front; // Kuyruðun baþýndan baþla
    int length = x->size;
    for (int i = 0; i < length; i++) {
        printf("%d ", x->array[index]);
        index = (index + 1) % x->capacity; // Döngüsel ilerle
    }
    printf("\n");
}*/

void display(struct queue *x){
	int length = x->size;
	int tmp = x->front;
	while (length>0){
		printf("%d \t", x->array[tmp]);
		tmp++;
		length--;
	}
}

int main(){
	struct queue * yeni = createQueue(3);
	enqueue(yeni,10);
	enqueue(yeni,15);
	dequeue(yeni);
	display(yeni);
}

