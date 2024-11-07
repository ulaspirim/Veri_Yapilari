#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	int *next;
};

void basaEkle(struct node **head, int x){
	struct node *yeni = (struct node *) malloc (sizeof (struct node));
	yeni->data = x;
	yeni->next = *head;
	*head = yeni;
}

int main(){
	struct node *yeni1 = (struct node*) malloc(sizeof (struct node));
	struct node *yeni2 = (struct node*) malloc(sizeof (struct node));
	struct node *yeni3 = (struct node*) malloc(sizeof (struct node));
	
	yeni1 -> data = 5;
	yeni2 -> data = 10;
	yeni3 -> data = 15;
	
	yeni1->next = yeni2;
	yeni2->next = yeni3;
	yeni3->next = NULL;
	
	printf("%d, %d \t %d, %d \t %d, %d ", yeni1->data, yeni1->next, yeni2->data, yeni2->next, yeni3->data, yeni3->next);
}
