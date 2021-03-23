#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node* sort( struct node*, struct node*);
struct node* allocate(char*);
struct graph* createGraph( int);
struct queue* makeQueue();
void enqueue(struct queue* q, char* name);
void dequeue(struct queue* q);
struct node* checkTop(struct queue* q);
void bfs(struct graph* g, char* ver );
void fill( int* arr, int num);
int checkAll(int* arr,  int num);
int findFirst( int* arr, int num);
void freeGraph ( struct graph* g, int num);
void freeNodes( struct node* head);



struct node{
	struct node* next;
	char* name;
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

int main ( int argc, char *argv[argc+1]){

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
		while ( fscanf(fp, "%s %s\n", str1,str2) != EOF){
		
			int j = 0; 
			int k = 0;
			for ( j = 0; j < num; j++){
				if (strcmp(g->array[j].name, str1) == 0){
					break;
				}
			}
			for ( k = 0; k < num; k++){
				if (strcmp(g->array[k].name, str2) == 0){
					break;
				}
			}
			struct node* newNode = allocate(str2);
			
			g->array[j].head = sort(g->array[j].head, newNode);
			struct node* newNode2 = allocate(str1);
		
			g->array[k].head = sort(g->array[k].head, newNode2);
			

		}

		char verName[20];
		while ( fscanf(file2, "%s\n", verName) != EOF){
			bfs(g, verName);
			printf("\n");
		}
		freeGraph(g, num);



	}
	fclose(fp);
	fclose(file2);
	return EXIT_SUCCESS;
}


void bfs(struct graph* g, char* ver ){

	int* arr = malloc(sizeof(int) * g->vertex);
	fill(arr, g->vertex);
	
	int j; 
	for ( j = 0; j < g->vertex; j++ ){
		if ( strcmp(g->array[j].name, ver) == 0){
			break;
		}
	}
	

	

		struct queue* q = makeQueue();
		enqueue(q, g->array[j].name);
		arr[j] = 1;
		int k = j; 
		
		while ( q->back != 0 ){
			
			struct node* ptr;
			struct node* temp = checkTop(q);
			dequeue(q);
			free(temp->name);
			free(temp);
			
			for ( ptr = g->array[k].head; ptr != 0; ptr = ptr->next){

				int l;
				for ( l = 0; l < g->vertex; l++){
					if ( strcmp(g->array[l].name, ptr->name ) == 0) {

						if ( arr[l] == 0){
							enqueue(q, ptr->name);
							arr[l] = 1;
						}
						break;
					}
				}

			}
			
			

			if ( q-> back != 0){
				ptr = checkTop(q);
				int m; 
				for ( m = 0; m < g->vertex; m++){
					if ( strcmp(g->array[m].name, ptr->name ) == 0){
						break;
					}
				}
				k = m;
			} else {
				break;
			}
			
			
		}
		
		
		free(q);

	

	free(arr);
		
	

}

void fill( int* arr, int num){
	for ( int i = 0; i < num; i++){
		arr[i] = 0; 
	}
	return;
}

int checkAll(int* arr,  int num){
	int val = 1; 
	for ( int i = 0; i < num; i++){
		if ( arr[i] == 0){
			val = 0;
			break;
		}
	}
	return val;
}
int findFirst( int* arr, int num){
	int k = 0;
	for ( int j = 0; j < num; j++){
		if ( arr[j] == 0){
			k = j;
			break;
		}
	}
	return k; 
}



struct queue* makeQueue(){

	struct queue* q = malloc(sizeof(struct queue));
	q->front = 0; 
	q->back = 0;
	return q;
}

void enqueue(struct queue* q, char* name){

	struct node* newNode = allocate(name);
	struct node* ptr = q->front;
	struct node* last = 0;

	if ( q->back == 0){
		q->front = newNode;
		q->back = newNode;
		return;
	}
	while( ptr!= 0 ){
		last = ptr;
		ptr = ptr->next;

	}
	last->next = newNode;
	return;
}

void dequeue(struct queue* q){

	if ( q->front == 0){
		return;
	} else {
		struct node* head = q->front;
		printf("%s ", head->name);
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


struct node* allocate(char* str){
	struct node* temp = malloc(sizeof(struct node));
	temp->name = malloc(strlen(str)+1);
	strcpy(temp->name, str);
	temp->next = 0; 
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

