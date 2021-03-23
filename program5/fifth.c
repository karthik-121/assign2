#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node* allocate(char* str, int val);
struct graph* createGraph(int num);
struct node* sort( struct node* head, struct node* newNode);
void freeGraph ( struct graph* g, int num);
void freeNodes( struct node* head);
struct stack* buildStack();
void push(struct stack* s, char* name);
void freeStack( struct stack* s);
struct node* checkTop(struct stack* s);
void fill( int* arr, int num);
char checkAll(int* arr,  int num);
int findFirst( int* arr, int num);
struct node* stackAllocate(char* str);
struct stack* topSort(struct graph* g);
void visit( struct stack* s, struct graph* g, int* arr, int num);
int* SSP(struct graph* g, char* name);
int checkDAG( struct stack* s, struct graph* g, int* arr, int num);
int DAG(struct graph* g);


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

		printf("\n");
		if (DAG(g) == 1){
			printf("cycle\n");
		} 
		else {

			char ssp[20];
			while ( fscanf(file2, "%s\n", ssp) != EOF){
				int* arr = SSP(g, ssp);
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

		}
		
		
		

		
		freeGraph(g , num);


	}

	fclose(fp);
	fclose(file2);
	return EXIT_SUCCESS;

}

int checkDAG( struct stack* s, struct graph* g, int* arr, int num){
	int cycle = 0; 
	if ( arr[num] == 1){
		return cycle;  
	}
	if ( arr[num] == 0){
		cycle = 1;
		return cycle;
	}

	arr[num] = 0; 
	for ( struct node* ptr = g->array[num].head; ptr!= 0; ptr = ptr->next ){
		int l;
		for ( l = 0; l < g->vertex; l++){
			if (strcmp(g->array[l].name, ptr->name) == 0){
				break;
			}
		}
		cycle = checkDAG(s, g, arr, l);
		
	}
	arr[num] = 1;
	push(s, g->array[num].name);
	return cycle;
}

int DAG(struct graph* g){
	struct stack* s = buildStack();
	int cycle;
	int* arr = malloc(sizeof(int)* g->vertex);
	fill(arr, g->vertex);
	while ( checkAll(arr, g->vertex) != 'v'){

		int i = findFirst(arr, g->vertex);
		cycle = checkDAG(s, g, arr, i);
	
	}
	while ( s->head != 0 ){
		freeStack(s);
	}
	free(arr);
	free(s);
	return cycle;

}






struct stack* topSort(struct graph* g){
	struct stack* s = buildStack();
	int* arr = malloc(sizeof(int) * g->vertex);
	fill(arr, g->vertex);
	while ( checkAll(arr, g->vertex) != 'v'){


		int i = findFirst(arr, g->vertex);
		visit(s, g, arr, i);
		
		
		
	}

	free(arr);
	return s;
	
}


void visit( struct stack* s, struct graph* g, int* arr, int num){ 
	if ( arr[num] == 1){
		return;  
	}

	arr[num] = 0; 
	for ( struct node* ptr = g->array[num].head; ptr!= 0; ptr = ptr->next ){
		int l;
		for ( l = 0; l < g->vertex; l++){
			if (strcmp(g->array[l].name, ptr->name) == 0){
				break;
			}
		}
		visit(s, g, arr, l);
		
	}
	
	arr[num] = 1;
	push(s, g->array[num].name);
	
}





int* SSP(struct graph* g, char* name){
	int* arr = malloc(sizeof(int) * g->vertex);
	struct stack* s = topSort(g);
	
	for ( int i = 0; i < g->vertex; i++){
		arr[i] = 200000000;
	}
	int m;
	for ( m = 0; m < g->vertex; m++){
		if ( strcmp(g->array[m].name, name) == 0){
			break;
		}
	}
	arr[m] = 0; 
	for ( struct node* ptr = s->head; ptr != 0; ptr = ptr->next){
		int k;
		for ( k = 0; k < g->vertex; k++){
			if ( strcmp(g->array[k].name, ptr->name) == 0){
				break;
			}
		}
		for ( struct node* temp = g->array[k].head; temp != 0; temp = temp->next){
			int l;
			for ( l = 0; l < g->vertex; l++){
				if ( strcmp(g->array[l].name, temp->name) == 0){
					break;
				}
			}
			if ( arr[l] > arr[k] + temp->weight){
				arr[l] = arr[k] + temp->weight;
			}
		}
	}
	
	while( s->head != 0) {
		freeStack(s);
	}
	free(s);
	return arr;

	

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

void freeStack( struct stack* s){
	struct node* temp = s->head;
	s->head = s->head->next;
	free(temp->name);
	free(temp);
	return;
}

struct node* checkTop(struct stack* s){

	struct node* temp = s->head;

	return temp; 


}





void fill( int* arr, int num){
	for ( int i = 0; i < num; i++){
		arr[i] = -1; 
	}
	return;
}

char checkAll(int* arr,  int num){
	char visited = 'v'; 
	for ( int i = 0; i < num; i++){
		if ( arr[i] != 1){
			visited = 'u';
			break;
		}
	}
	return visited;
}

int findFirst( int* arr, int num){
	int k = 0;
	for ( int j = 0; j < num; j++){
		if ( arr[j] == -1){
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