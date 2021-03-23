#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node* sort( struct node*, struct node*);
struct node* allocate(char*);
struct graph* createGraph( int);
void print(FILE* , struct graph* );
void freeGraph ( struct graph* , int );
void freeNodes( struct node* );


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



int main( int argc, char *argv[argc+1] ){
	int num;

	

	FILE *fp = fopen(argv[1],"r");
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

		print(file2, g);
		
		freeGraph(g, num);
		

	}

	fclose(fp);
	fclose(file2);
	return EXIT_SUCCESS;
}

void print(FILE* fp, struct graph* g){
	char c;
	char ver[20];
	while( fscanf(fp, "%c %s\n", &c, ver) != EOF){
		if ( c == 'a'){
			int i; 
			for ( i = 0; i < g->vertex; i++ ){
				if ( strcmp(g->array[i].name, ver) == 0){
					break;
				}

			}
			for (struct node* ptr = g->array[i].head; ptr != 0; ptr = ptr->next){
				printf("%s ", ptr->name);
			}
			printf("\n");
		} else {
			int count = 0; 
			int i; 
			for ( i = 0; i < g->vertex; i++ ){
				if ( strcmp(g->array[i].name, ver) == 0){
					break;
				}

			}
			for ( struct node* ptr = g->array[i].head; ptr != 0; ptr = ptr->next){
				count++; 
			}
			printf("%d\n",count);

		}

	}
	return; 
	
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

