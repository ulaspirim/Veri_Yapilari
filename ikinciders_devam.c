#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void bastir(struct node **head) {
	
	struct node *tmp = *head;
	while (tmp != NULL) {
		printf("%d \t", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}


void basaEkle(struct node **head, int x){
	struct node *yeni = (struct node *) malloc (sizeof (struct node));
	yeni->data = x;
	yeni->next = *head;
	*head = yeni;
}

void arayaEkle(struct node **head, int p, int k){
	struct node *yeni = (struct node *) malloc (sizeof (struct node));
	struct node *tmp = *head;
	
	yeni->data = k;
	int a=1;
	p = p-1;
	
	while(a < p) {
		a++;
		tmp = tmp->next;
	}
	
	yeni->next = tmp->next;
	tmp->next = yeni;

}

void sonaEkle(struct node **head, int y) {
	struct node *yeni = (struct node *) malloc (sizeof (struct node));
	yeni->data = y;

	struct node *tmp = *head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = yeni;
	yeni->next = NULL;
}

void bastanSil(struct node **head){
	struct node *tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void aradanSil(struct node **head, int z){
	struct node *tmp = *head;
	struct node *silinecek;
	
	int a=1;
	z = z-1;
	while(a < z) {
		a++;
		tmp = tmp->next;
	}

	silinecek = tmp->next;
	tmp->next = tmp->next->next;
	free(silinecek);	
	
}

void sondanSil(struct node **head){
	struct node *tmp = *head;
	struct node *prev;
	
	while(tmp->next != NULL){
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next =NULL;
	free(tmp);
	
}

void terstenSirala(struct node **head){
	struct node *tmp = *head;
	struct node *prev = NULL;
	struct node *yeni = *head;
	
	while(tmp->next != NULL){
		prev = tmp;
		tmp = tmp->next;
		yeni = yeni->next;
	}
	
	tmp->next = prev;	
	tmp = *head;
	
	while(tmp != prev ){

		while(tmp->next != prev){
			tmp = tmp->next;
		}

		prev->next = tmp;
		prev = *head;
		
		while(prev->next != tmp){
			prev = prev->next;
		}
		tmp->next = prev;
		tmp = *head;
	}
	tmp->next = NULL;
	*head = yeni;

}

int main(){
	struct node *yeni1 = (struct node*) malloc(sizeof (struct node));
	struct node *yeni2 = (struct node*) malloc(sizeof (struct node));
	struct node *yeni3 = (struct node*) malloc(sizeof (struct node));
	yeni1->data = 5;
		yeni1->next = yeni2;
	yeni2->data = 10;
		yeni2->next = yeni3;
	yeni3->data = 15;
		yeni3->next = NULL;
	struct node *head = yeni1;
	
	bastir(&head);
	
	int i;
	for (i=0; i<4; i++) {
		sonaEkle(&head, i*3);
	}
	bastir(&head);
	
	
	
	basaEkle(&head, 2);
	bastir(&head);
	
	bastanSil(&head);
	bastir(&head);
	
	aradanSil(&head,3);
	bastir(&head);
	
	sondanSil(&head);
	bastir(&head);
	
	arayaEkle(&head,3,11);
	bastir(&head);
	
	terstenSirala(&head);
	bastir(&head);
	
	free(yeni1);
	free(yeni2);
	free(yeni3);
	
	return 0;
}
