#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************
 * Structs Implementation
 *******************/

typedef struct Node {
    struct Graph* pointed_letter;
    struct Node* adjacency_list;
} Node;

typedef struct Graph {
    char letter;
    Node* main_list;
} Graph;

Graph* initialize_graph() {
    return NULL;
}

/*******************
 * Function Signatures
 *******************/

/* 
   Function: initialize_graph
   Description: Initializes an empty graph.

   Returns: Graph* (Pointer to an empty Graph structure)
*/
Graph* initialize_graph();

/* 
   Function: is_graph_empty
   Description: Checks if a graph is empty.

   Parameters:
   - list: Pointer to the graph to be checked.

   Returns: int (1 if the graph is empty, 0 otherwise)
*/
int is_graph_empty(Graph* list);

/* 
   Function: is_node_list_empty
   Description: Checks if a node list is empty.

   Parameters:
   - list: Pointer to the node list to be checked.

   Returns: int (1 if the node list is empty, 0 otherwise)
*/
int is_node_list_empty(Node* list);

/* 
   Function: allocate_graph
   Description: Allocates memory for a graph vertex.

   Returns: Graph* (Pointer to the allocated Graph structure)
*/
Graph* allocate_graph();

/* 
   Function: allocate_node
   Description: Allocates memory for a node in the adjacency list.

   Returns: Node* (Pointer to the allocated Node structure)
*/
Node* allocate_node();

/* 
   Function: insert_main_list
   Description: Inserts a vertex into the main list of vertices.

   Parameters:
   - l: Pointer to a pointer to the main list.
   - e: Character representing the vertex to be inserted.

   Returns: int (1 if the insertion is successful, 0 otherwise)
*/
int insert_main_list(Graph** l, char e);

/* 
   Function: find_vertex
   Description: Finds a vertex in the main list by its position.

   Parameters:
   - list: Pointer to the main list of vertices.
   - i: Position of the vertex to be found.

   Returns: Graph* (Pointer to the found vertex or NULL if not found)
*/
Graph* find_vertex(Graph* list, int i);

/* 
   Function: vertex_degree
   Description: Calculates the degree of a vertex.

   Parameters:
   - list: Pointer to the adjacency list of the vertex.

   Returns: int (The degree of the vertex)
*/
int vertex_degree(Node* list);

/* 
   Function: main_list_size
   Description: Calculates the size of the main list of vertices.

   Parameters:
   - complete_list: Pointer to the complete list of vertices.

   Returns: int (The size of the main list)
*/
int main_list_size(Graph* complete_list);

/* 
   Function: get_all_degrees
   Description: Gets an array of all vertex degrees.

   Parameters:
   - complete_list: Pointer to the complete list of vertices.

   Returns: int* (Pointer to an array of vertex degrees)
*/
int* get_all_degrees(Graph* complete_list);

/* 
   Function: insert_at_end_adj_list
   Description: Inserts a vertex at the end of the adjacency list.

   Parameters:
   - l: Pointer to a pointer to the adjacency list.
   - e: Pointer to the vertex to be inserted.

   Returns: int (1 if the insertion is successful, 0 otherwise)
*/
int insert_at_end_adj_list(Node** l, Graph** e);

/* 
   Function: print_node
   Description: Prints a node's adjacency list.

   Parameters:
   - list: Pointer to the node's adjacency list.

   Returns: void
*/
void print_node(Node* list);

/* 
   Function: print_complete_graph
   Description: Prints the complete graph.

   Parameters:
   - complete_list: Pointer to the complete list of vertices.

   Returns: void
*/
void print_complete_graph(Graph* complete_list);

/*******************
 * Function Implementations
*******************/

int is_graph_empty(Graph* list) {
    if (list == NULL) return 1;
    return 0;
}

int is_node_list_empty(Node* list) {
    if (list == NULL) return 1;
    return 0;
}

Graph* allocate_graph() {
    Graph* new_vertex;
    new_vertex = (Graph*) malloc(sizeof(Graph));
    return new_vertex;
}

Node* allocate_node() {
    Node* new_node;
    new_node = (Node*) malloc(sizeof(Node));
    return new_node;
}

int insert_main_list(Graph** l, char e) {
    Graph* new_node, *current;
    new_node = allocate_graph();
    new_node->main_list = allocate_node();

    new_node->letter = e;

    if (new_node == NULL || new_node->main_list == NULL) return 0;

    if (is_graph_empty(*l)) {
        *l = new_node;
    } else {
        current = *l;
        while (current->main_list->pointed_letter != NULL) {
            current = current->main_list->pointed_letter;
        }
        current->main_list->pointed_letter = new_node;
    }
    return 1;
}

Graph* find_vertex(Graph* list, int i) {
    Graph* current;
    current = list;

    int c = 1;
    while ((current != NULL) && (i != c)) {
        current = current->main_list->pointed_letter;
        c++;
    }
    if (current == NULL) return NULL;
    return current;
}

int vertex_degree(Node* list) {
    Node* current;
    current = list;

    int size = 0;
    while (current != NULL) {
        current = current->adjacency_list;
        size++;
    }
    return size;
}

int main_list_size(Graph* complete_list) {
    Graph* current;
    current = complete_list;
    
    int size = 0;
    while (current->main_list->pointed_letter != NULL) {
        current = current->main_list->pointed_letter;
        size++;
    }
    return size;
}

int* get_all_degrees(Graph* complete_list) {
    int* degrees;

    degrees = (int*) malloc(main_list_size(complete_list) * sizeof(int));

    Graph* current;
    current = complete_list;

    int i = 0;
    while (current->main_list->adjacency_list != NULL) {
        int degree = vertex_degree(current->main_list->adjacency_list);
        degrees[i] = degree;
        current = current->main_list->pointed_letter;
        i++;
    }

    return degrees;
}

int insert_at_end_adj_list(Node** l, Graph** e) {
    Node* new_node, *current;
    new_node = allocate_node();
    if (new_node == NULL) return 0;
    new_node->pointed_letter = *e;
    new_node->adjacency_list = NULL;
    if (is_node_list_empty(*l)) {
        *l = new_node;
    } else {
        current = *l;
        while (current->adjacency_list != NULL) {
            current = current->adjacency_list;
        }
        current->adjacency_list = new_node;
    }
    return 1;
}

void print_node(Node* list) {
    Node* current;
    current = list;
    while (current != NULL) {
        if (current->adjacency_list == NULL) {
            printf(" %c\n", current->pointed_letter->letter);
            current = current->adjacency_list;
        } else {
            printf(" %c ->", current->pointed_letter->letter);
            current = current->adjacency_list;
        }
    }
}

void print_complete_graph(Graph* complete_list) {
    Graph* current;
    Node* aux;
    current = complete_list;
    while (current->main_list->pointed_letter != NULL) {
        if (current->letter != ' ')
            printf("%c ->", current->letter);
        print_node(current->main_list->adjacency_list);
        current = current->main_list->pointed_letter;
    }
}
