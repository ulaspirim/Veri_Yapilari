#include <stdio.h>
struct node{
	int data;
	int *next;
};

struct node * newNode (int data){
	struct node *yeni = (struct node*) malloc(sizeof (struct node));
	yeni->data = data;
	yeni->next = NULL;
	return yeni;
}
void arayaEkle(struct node *head, int x, int y){
	struct node *yeni = newNode(x);
	struct node *tmp = head;
	while(tmp->data != y)
		tmp = tmp->next;
	yeni->next = tmp->next;
	tmp->next = yeni;
	
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

}
