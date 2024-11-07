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
  while (tmp != NULL) {
    printf("%d \t", tmp->data);
    tmp = tmp->next;
  }
  printf("\n");
}


void basaEkle(struct node **head, int key){
  struct node *yeni = newNode (key);
  yeni->next = *head;
  (*head)->prev = yeni;
  *head = yeni;
}

void arayaEkle(struct node **head, int x, int y){
  struct node *yeni = newNode(x);
  struct node *tmp = *head;
  while (tmp->data != y){
    tmp = tmp->next;}
  yeni->prev = tmp;
  yeni->next = tmp->next;
  tmp->next->prev = yeni;
  tmp->next = yeni;
}

void sonaEkle(struct node **head, int x){
  struct node *yeni = newNode (x);
  struct node *tmp = *head;
  while (tmp->next != NULL)
    tmp = tmp->next;
  yeni->prev = tmp;
  tmp->next = yeni;
}

void bastanSil (struct node **head){
  struct node *tmp = *head;
  *head = tmp->next;
  tmp->next->prev = NULL;
  free(tmp);
}

void aradanSil (struct node **head, int x){
  struct node *tmp = *head;
  struct node *silinecek;

  while (tmp->data != x){
    tmp = tmp->next;
    }
    silinecek = tmp;
    tmp = tmp->next;
    tmp ->prev = silinecek->prev;
    tmp->prev->next = tmp;
    free(silinecek);
}

void aradanSil2 (struct node **head, int x) {
  //Bu kod ile sonraki dugume gidilerek silindi
  struct node *tmp = *head;
  struct node *silinecek = NULL;
  while (tmp-> prev -> data != x)
    tmp = tmp->next;
  tmp->next = NULL;
  silinecek = tmp->prev;
  silinecek->prev->next = tmp;
  tmp->prev = silinecek->prev;  
  
  free(silinecek);
}

void sondanSil (struct node **head){
  struct node *tmp = *head;
  while (tmp->next->next != NULL)
    tmp = tmp->next;
  free(tmp->next);
  tmp->next = NULL;
}

void sondanSil2 (struct node **head) {
  struct node *tmp = *head;
  struct node *tmp2;
  while (tmp->next->next != NULL) {
    tmp = tmp->next;
  }
  tmp2 = tmp->next;
  free(tmp2);
  tmp->next = NULL;
}

void klonla (struct node **head1, struct node **head2) {
  struct node *tmp1 = *head1;
  struct node *tmp2 = *head2;
  
  while (tmp1->next != NULL){
    tmp2->data = tmp1->data;
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
  }
  tmp2->data = tmp1->data;
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
  bastir(&yeni1);

  basaEkle(&yeni1, 1);
  bastir(&yeni1);

  arayaEkle(&yeni1, 16, 10);
  bastir(&yeni1);

  sonaEkle(&yeni1, 20);
  bastir(&yeni1);

  bastanSil(&yeni1);
  bastir(&yeni1);

  aradanSil(&yeni1, 16);
  bastir(&yeni1);
  
  arayaEkle(&yeni1, 18, 15);
  bastir(&yeni1);
/*
  aradanSil2(&yeni1, 18);
  bastir(&yeni1);
*/
  sondanSil(&yeni1);
  bastir(&yeni1);  
  
  sondanSil2(&yeni1);
  bastir(&yeni1);

  arayaEkle(&yeni1, 22, 10);
  bastir(&yeni1);
 
  arayaEkle(&yeni1, 23, 22);
  bastir(&yeni1); 
  
  struct node *yeni4 = (struct node*) malloc(sizeof (struct node));
  struct node *yeni5 = (struct node*) malloc(sizeof (struct node));
  struct node *yeni6 = (struct node*) malloc(sizeof (struct node));
  struct node *yeni8 = (struct node*) malloc(sizeof (struct node));   
  struct node *yeni7 = (struct node*) malloc(sizeof (struct node));
    yeni4->data = 1;
    yeni4->next = yeni5;
    yeni5->data = 0;
    yeni5->next = yeni6;
    yeni6->data = 0;
    yeni6->next = yeni7;
	yeni7->data = 0;
    yeni7->next = yeni8;
    yeni8->data = 0;
    yeni8->next = NULL;

bastir(&yeni4);

printf("\n\nKlonlama kismi\n");

  klonla(&yeni1, &yeni4);
  bastir(&yeni1);
  bastir(&yeni4);

}
