#include <stdio.h>
#include <stdlib.h>

struct queue {
    int front, rear, size;
    unsigned capacity;
    int *dizi;
};

struct queue *createQueue (unsigned capacity){
    struct queue *yeni = (struct queue *) malloc(sizeof(struct queue));

    yeni->capacity = capacity;
    yeni->front = yeni->size = 0;
    yeni->rear = yeni->capacity -1;
    yeni->dizi = (int *) malloc (sizeof(int) * yeni->capacity);
    return yeni;
};

int isFull(struct queue *x) {
    return x->size == x->capacity;
}

int isEmpty(struct queue *x) {
    return x->size == 0;
}

/* bunlar yanlış
int isFull(struct queue * x){
    if(x->size == x->capacity-1){
        return printf("Maalesef sira dolu");
    }
}

int isEmpty(struct queue *x){
    if(x->size == 0){
        return printf("Sira bos");
    }
}*/

int enqueue (struct queue *x, int data){
    if (isFull(x)) {
        printf("Maalesef sıra dolu.\n");
        return 0;
    }

    x->rear = (x->rear +1) % x->capacity;
    x->dizi[x->rear] = data;
    x->size++;
    return 1;
}

int dequeue (struct queue *x){
    if (isEmpty(x)) {
        printf("Sıra boş.\n");
        return 0;
    }

    int item = x->dizi[x->front];
    x->front = (x->front +1) % x->capacity;
    x->size--;
    return item;
}

void siralama (struct queue *x){
    if (isEmpty(x))
        return;

    for(int i=0; i < x->size-1 ; i++){
        for(int j=i+1; j < x->size; j++){
            int tmp1 = (x->front + i) % x->capacity;
            int tmp2 = (x->front + j) % x->capacity;

            if (x->dizi[tmp1] > x->dizi[tmp2]){
                int item = x->dizi[tmp1];
                x->dizi[tmp1] = x->dizi[tmp2];
                x->dizi[tmp2] = item;
            }
        }
    }
}

void display(struct queue *x){
    if (isEmpty(x)) {
        printf("Sıra boş.\n");
        return;
    }
    int index = x->front;
    int length = x->size;
    for(length; length > 0; length--){
        printf("%d\t",x->dizi[index]);
        index = (index + 1) % x->capacity;
    }
    printf("\n");
}

int main(){
    struct queue *yıgın = createQueue(5);
    enqueue(yıgın,10);
    enqueue(yıgın,15);
    display(yıgın);
    enqueue(yıgın,35);
    display(yıgın);
    enqueue(yıgın,20);
    display(yıgın);
    enqueue(yıgın,6);
    display(yıgın);

    siralama(yıgın);
    display(yıgın);
}