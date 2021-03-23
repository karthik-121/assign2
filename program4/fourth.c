#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node* allocate(char* str, int val);
struct graph* createGraph(int num);
struct node* sort( struct node* head, struct node* newNode);
void freeGraph ( struct graph* g, int num);
void freeNodes( struct node* head);
void dfs( struct graph* g);
struct stack* buildStack();
void push(struct stack* s, char* name);
void pop ( struct stack* s);
struct node* checkTop(struct stack* s);
void fill( int* arr, int num);
int checkAll(int* arr,  int num);
int findFirst( int* arr, int num);
struct node* stackAllocate(char* str);

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

struct stack{
	struct node* head;
};

int main ( int argc, char *argv[argc+1]){
	int num; 
	FILE *fp = fopen(argv[1], "r");
	if ( fp == 0 ){
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


		dfs(g);
		printf("\n");
		freeGraph(g, num);



	}
	fclose(fp);
	return EXIT_SUCCESS;


}

void dfs( struct graph* g){

	int* arr = malloc(sizeof(int) * g->vertex);
	fill(arr, g->vertex);
	int j = 0; 

	// island check
	while ( checkAll(arr, g->vertex) != 1 ){
 
		struct stack* s = buildStack();
		push(s, g->array[j].name);

		// empty stack check
		while ( s->head != 0){

			struct node* p = checkTop(s);
			pop(s);
			int l;
			for ( l = 0; l < g->vertex; l++){
				if ( strcmp(g->array[l].name, p->name) == 0){
					break;
				}
			}
			if (arr[l] == 0){
				arr[l] = 1;
				printf("%s ", p->name);
			}
			for ( struct node* ptr = g->array[l].head; ptr != 0; ptr = ptr->next){
				int m;
				for ( m = 0; m < g->vertex; m++){
					if ( strcmp(g->array[m].name, ptr->name) == 0){
						if ( arr[m] == 0){
							push(s, ptr->name);
						}
						break;
					}
				}
			}
			free(p->name);
			free(p);	

		}
		j = findFirst(arr, g->vertex);
		free(s);

	}

	free(arr);

}



struct stack* buildStack(){

	struct stack* s = malloc(sizeof(struct stack));
	s->head = 0; 
	return s;
}


void push(struct stack* s, char* name){
	struct node* temp = stackAllocate(name);

	if ( s->head == 0){
		s->head = temp;
		return;
	}
	temp->next = s->head;
	s->head = temp; 
	return;
}

void pop ( struct stack* s){
	s->head = s->head->next;
	return;
}

struct node* checkTop(struct stack* s){

	struct node* temp = s->head;

	return temp; 


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

struct node* stackAllocate(char* str){
	struct node* temp = malloc(sizeof(struct node));
	temp->name = malloc(strlen(str)+1);
	strcpy(temp->name, str);
	temp->next = 0; 
	return temp; 
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
		if ( strcmp( newNode->name, ptr->name) > 0){
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