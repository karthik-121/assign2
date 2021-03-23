#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node* allocate(char* str, int val);
struct graph* createGraph(int num);
struct node* sort( struct node* head, struct node* newNode);
void freeGraph ( struct graph* g, int num);
void freeNodes( struct node* head);
struct queue* makeQueue();
void enqueue(struct queue* q, char* name, int weight);
void dequeue(struct queue* q, struct graph* g, int* arr);
void fill( int* arr, int num);
int* Dijktra(struct graph* g, char* ver);
struct node* checkTop(struct queue* q);

struct node{
	struct node* next;
	char* name;
	int weight;
};

struct list{
	struct node* head; 
	char* name;
};

struct graph{
	int vertex;
	struct list* array;
};

struct queue{
	struct node* front;
	struct node* back;

};


int main ( int argc, char *argv[argc + 1]){
	int num; 
	FILE *fp = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "r");
	if ( fp == 0 || file2 == 0){
		printf("error\n");
	} else {
		fscanf(fp, "%d\n", &num);
		struct graph* g = createGraph(num);
		char str[20];
		char verticies[20];
		for ( int i = 0; i < num; i++){
			fscanf(fp, "%s\n", str);
			g->array[i].name = malloc(strlen(str)+1);
			strcpy(g->array[i].name, str);
		}
		for ( int i = 0; i < num; i++){
			for ( int j = i + 1; j < num; j++){
				if ( strcmp(g->array[i].name, g->array[j].name) > 0){
					strcpy(verticies, g->array[i].name);
					strcpy(g->array[i].name, g->array[j].name);
					strcpy(g->array[j].name, verticies);
				}
			}
		}
		
		char str1[20];
		char str2[20];
		int val; 
		while ( fscanf(fp, "%s %s %d\n", str1, str2, &val) != EOF){
			int j = 0; 

			for ( j = 0; j < num; j++){
				if (strcmp(g->array[j].name, str1) == 0){
					break;
				}
			}
			struct node* newNode = allocate(str2, val);
			g->array[j].head = sort(g->array[j].head, newNode);
		}

		char start[20];
		while (fscanf(file2, "%s\n", start) != EOF){
			int* arr = Dijktra(g, start);
			for ( int i = 0; i < g->vertex; i++){
				if ( arr[i] == 200000000){
					printf("%s INF\n", g->array[i].name);
				}
				else {
					printf("%s %d\n", g->array[i].name, arr[i]);
				}
				
			}
			printf("\n");

			free(arr);
		}

		freeGraph(g , num);


	}

	fclose(fp);
	fclose(file2);
	return EXIT_SUCCESS;

		
}

int* Dijktra(struct graph* g, char* ver){
	int* visited = malloc(sizeof(int) * g->vertex);
	int* distance = malloc(sizeof(int) * g->vertex);
	fill(visited, g->vertex); 
	for ( int i = 0; i < g->vertex; i++){
		distance[i] = 200000000;
	}
	int j;
	for ( j = 0; j < g->vertex; j++){
		if (strcmp(g->array[j].name, ver) == 0){
			break;
		}
	}
	distance[j] = 0; 
	struct queue* q = makeQueue();
	enqueue(q, g->array[j].name, 0);
	while ( q->back != 0){

		struct node* temp = checkTop(q);
		dequeue(q, g, distance);
		int l; 
		for ( l = 0; l < g->vertex; l++){
			if ( strcmp(g->array[l].name, temp->name) == 0){
				break;
			}
		}
		if ( visited[l] == 0){
			visited[l] = 1;
			for ( struct node* n = g->array[l].head; n != 0; n = n->next){
				int k; 
				for ( k = 0; k < g->vertex; k++){
					if ( strcmp(g->array[k].name, n->name) == 0){
						break;
					}
				}
				int weight = temp->weight + n->weight;
				enqueue(q, g->array[k].name, weight);


			}
			free(temp->name);
			free(temp);
		}
		


	}
	free(visited);

	return distance;




}

struct queue* makeQueue(){

	struct queue* q = malloc(sizeof(struct queue));
	q->front = 0; 
	q->back = 0;
	return q;
}




void enqueue(struct queue* q, char* name, int weight){

	struct node* newNode = allocate(name, weight);
	struct node* ptr = q->front;
	struct node* last = 0;

	if ( q->back == 0){
		q->front = newNode;
		q->back = newNode;
		return;
	}
	while( ptr!= 0 ){
		if ( newNode->weight < ptr->weight ){
			break;
		}
		last = ptr;
		ptr = ptr->next;

	}
	newNode->next = ptr; 
	if ( last != 0){
		last->next = newNode;
	} else {
		q->front = newNode;
	}
	return;
}

void dequeue(struct queue* q, struct graph* g, int* arr){


	if ( q->front == 0){
		return;
	} else {
		struct node* head = q->front;
		int i; 
		for ( i = 0; i < g->vertex; i++){
			if ( strcmp(g->array[i].name, head->name) == 0){
				break;
			}
		}
		if ( arr[i] > head->weight){
			arr[i] = head->weight;
		}
		q->front = q->front->next; 

		if ( q->front == 0){
			q->back = 0; 
		}


		
		
	}

}

struct node* checkTop(struct queue* q){

	struct node* temp = q->front;

	return temp; 


}







void fill( int* arr, int num){
	for ( int i = 0; i < num; i++){
		arr[i] = 0; 
	}
	return;
}



struct node* allocate(char* str, int val){
	struct node* temp = malloc(sizeof(struct node));
	temp->name = malloc(strlen(str)+1);
	strcpy(temp->name, str);
	temp->next = 0; 
	temp->weight = val;
	return temp; 
}

struct graph* createGraph(int num){
	struct graph* graph = malloc(sizeof(struct graph));
	graph->vertex = num; 
	graph->array = malloc(num * sizeof(struct list));
	for ( int i = 0; i < num; i++){
		graph->array[i].head = 0; 
	}
	return graph;

}





struct node* sort( struct node* head, struct node* newNode){
	if ( head == 0){
		head = newNode; 
		
	} else {
	struct node* ptr = head;
	struct node* prev = 0;
	while ( ptr!= 0 ){
		if ( strcmp( newNode->name, ptr->name) < 0){
			break;
		}
		prev = ptr;
		ptr = ptr->next;
		
	}
	if ( ptr == 0){
		prev->next = newNode; 
	}
	else {
		if ( prev != 0){
			newNode->next = prev->next;
			prev->next = newNode; 
		} 
		else {
			newNode->next = head; 
			head = newNode; 
		}
	} 
	
}
return head;
}

void freeGraph ( struct graph* g, int num){
	for ( int i = 0; i < num; i ++){
		freeNodes(g->array[i].head);
		free(g->array[i].name);


	}
	free(g->array);
	free(g);
}
void freeNodes( struct node* head){
	struct node* ptr = head;
	struct node* temp = 0; 
	while (ptr != 0){
       	temp = ptr->next;
	free(ptr->name);
        free(ptr);
	ptr = temp;
       
    }
    
}