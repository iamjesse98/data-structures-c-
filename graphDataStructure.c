#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node *next; 
}node;

void read_graph(node *ad[], int no_of_nodes);
void print_graph(node *ad[], int no_of_nodes);

int main(){
	int i, j, k, nodes;
	printf("Enter the nodes ");
	scanf("%d", &nodes);
	node *adj[nodes];
	for(i = 0; i < nodes; i++)
		adj[i] = NULL;
	read_graph(adj, nodes);
	print_graph(adj, nodes);
	return 0;
}

void read_graph(node *ad[], int no_of_nodes){
	node *new_node;
	int i, j, k, val;
	for(i = 0; i < no_of_nodes; i++){
		node *last = NULL;
		printf("\nEnter the Number of neighbours of %d ", i+1);
		scanf("%d", &k);
		for(j = 0; j < k; j++){
			printf("Enter the value of %d(st/nd/rd) neighbour of %d ", j+1, i+1);
			scanf("%d", &val);
			new_node = (node *)malloc(sizeof(node *));
			new_node->data = val;
			new_node->next = NULL;
			if(ad[i] == NULL)
				ad[i] = new_node;
			else
				last->next = new_node;
			last = new_node;
		}
	}
}

void print_graph(node *ad[], int no_of_nodes){
	node *ptr = NULL;
	int i, j;
	for(i = 0; i < no_of_nodes; i++){
		ptr = ad[i];
		printf("\nThe Neighbours of %d are: ", i+1);
		while(ptr != NULL){
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
	}
	printf("\n");
}
