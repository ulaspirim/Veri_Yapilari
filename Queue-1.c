#include <stdio.h>
#include <stdlib.h>

//Enqueue kuyruklamad�r.
/* 1.Dolu kontrol� yap�lmal�d�r
   2.Dolu ise fonksiyondan ��kar
   3.Dolu de�ilse rear artt�r.
   4.Rear noktas�na eleman ekle
   5.��lemi bitir
*/
//Dequeue kuyruktan eleman almad�r.

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

/*Bu �al��mazsa
void bastir(struct queue *x) {
    if (isEmpty(x)) {
        printf("Queue bos.\n");
        return;
    }
    
    printf("Queue elemanlari: ");
    int index = x->front; // Kuyru�un ba��ndan ba�la
    int length = x->size;
    for (int i = 0; i < length; i++) {
        printf("%d ", x->array[index]);
        index = (index + 1) % x->capacity; // D�ng�sel ilerle
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

