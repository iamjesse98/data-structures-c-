#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *link;
}node;



int main(){
	//creation of node
	
	node *a = (node *)malloc(sizeof(node));
	node *b = (node *)malloc(sizeof(node));
	node *c = (node *)malloc(sizeof(node));
	
	printf("a data = ?");
	scanf("%d", &a->data);
	
	printf("b data = ?");
	scanf("%d", &b->data);
	
	printf("c data = ?");
	scanf("%d", &c->data);
	
	a->link = b;
	b->link = c;
	c->link = NULL;
	
	printf("\n\t");
	
	printf("%d", a->data);
	
	printf("\n");
	return 0;
}
