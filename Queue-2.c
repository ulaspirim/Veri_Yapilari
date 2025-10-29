#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

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
		return 0;
	int item = x->array[x->front];
	x->front = (x->front +1) % x->capacity;
	x->size --;
	return item;
}

void reverse(struct queue *x){
	int dizi[MAX_SIZE];
	int top=-1;
	while(!isEmpty(x))
		dizi[++top] = dequeue(x);
	while(top != -1)
		enqueue(x,dizi[top--]);
}

void sort(struct queue *x){
	int i,j,tmp;
	int n = x->size;
	for(i=0; i <= n-1; i++){
		for(j = i+1; j<=n ; j++){
			if (x->array[j] < x->array[i]){
				tmp = x->array[i];
				x->array[i] = x->array[j];
				x->array[j] = tmp;
			}
		}
	}
}

/*ChatGPT'ye g�re ��yle olmal�ym��
void sort(struct queue *x) {
    int n = x->size;
    int tmp;
    int *sortedArray = (int *)malloc(n * sizeof(int));
    int index = x->front;

    // Kuyruktaki elemanlar� d�z bir diziye aktar
    for (int i = 0; i < n; i++) {
        sortedArray[i] = x->array[index];
        index = (index + 1) % x->capacity; // D�ng�sel ilerleme
    }

    // Diziyi d�zg�n s�ralama
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sortedArray[j] < sortedArray[i]) {
                tmp = sortedArray[i];
                sortedArray[i] = sortedArray[j];
                sortedArray[j] = tmp;
            }
        }
    }

    // S�ral� elemanlar� kuyruk yap�s�na geri y�kle
    index = x->front;
    for (int i = 0; i < n; i++) {
        x->array[index] = sortedArray[i];
        index = (index + 1) % x->capacity; // D�ng�sel ilerleme
    }

    free(sortedArray);
}
*/

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
	struct queue * yeni = createQueue(25);
	enqueue(yeni,10);
	enqueue(yeni,45);
	enqueue(yeni,50);
	enqueue(yeni,43);
	enqueue(yeni,70);
	enqueue(yeni,60);	
	
	display(yeni);
	printf("\n");
	//reverse(yeni);
	//display(yeni);
	printf("\n");
	sort(yeni);
	display(yeni);
	printf("\n");
}


