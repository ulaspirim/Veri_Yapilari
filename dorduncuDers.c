#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
  
};

struct node *newNode(int item) {
  struct node *yeni = (struct node *)malloc(sizeof(struct node));
  struct node *prev;
  yeni->data = item;
  yeni->next = yeni->prev = NULL;
  return yeni;
}

void bastir(struct node **head) {

	struct node *tmp = *head;
	
	while (tmp != NULL && tmp->next != *head) {
		printf("%d \t", tmp->data);
		tmp = tmp->next;
	}
	printf("%d \t", tmp->data);
	printf("\n\n");
}

void bastanSil (struct node **dugum1){
	
	struct node *tmp = *dugum1;
	struct node *del = *dugum1;
	
	tmp = tmp->next;
	
	while (tmp->next != del)
		tmp = tmp->next;
	
	tmp->next = del->next;
	del->next->prev = tmp;
	*dugum1 = del->next; 
	free(del);
}

void sondanSil (struct node *dugum){
	
	struct node *tmp = dugum;
	struct node *tmp2;
	struct node *del = dugum;
	
	while (del->next->next != tmp)
		del = del->next;
	
	tmp2 = del;
	del = del->next;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	free(del);
}

int main(){
	
	struct node *dugum1 = newNode(5);
	struct node *dugum2 = newNode (10);
	struct node *dugum3 = newNode (15);
		dugum1->next = dugum2; 
		dugum2->next = dugum3;
		dugum3->next = dugum1;
		dugum2->prev = dugum1;
		dugum3->prev = dugum2;
		dugum1->prev = dugum3;
	
	
	bastir(&dugum1);
	
	bastanSil(&dugum1);
	bastir(&dugum1);

	sondanSil(dugum1);
	bastir(&dugum1);
	
}
