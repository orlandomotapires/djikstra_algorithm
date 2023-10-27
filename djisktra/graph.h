#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************
 * Structs Implementation
 *******************/

typedef struct Node {
    struct Graph* pointed_letter;
    struct Node* adjacency_list;
    int weight;
} Node;

typedef struct Graph {
    char letter;
    Node* main_list;
} Graph;

Graph* initialize_graph() {
    return NULL;
}

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

int insert_at_end_adj_list(Node** l, Graph** e, int num) {
    Node* new_node, *current;
    new_node = allocate_node();
    if (new_node == NULL) return 0;
    new_node->pointed_letter = *e;
    new_node->adjacency_list = NULL;
    new_node->weight=num;

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
            printf(" %c|%d \n", current->pointed_letter->letter, current->weight);
            current = current->adjacency_list;
        } else {
            printf(" %c|%d ->", current->pointed_letter->letter, current->weight);
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