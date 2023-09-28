#include "graph.h"
#include "stack.h"

#define num_vertices 4

int adjacency_matrix_a[50][50];

/*******************
 * Function Signatures
 *******************/

/* 
   Function: read_file_create_graph
   Description: Reads a file and creates a graph based on its contents.

   Parameters:
   - graph: Pointer to a pointer to a Graph structure.
   - file: Pointer to the file to be read.
   - graph_num: An integer indicating which graph (a or b) is being processed.

   Returns: void
*/
void read_file_create_graph(Graph **graph, FILE *file);

/* 
   Function: print_matrix
   Description: Prints a 2D matrix.

   Parameters:
   - matrix: A 2D matrix to be printed.

   Returns: void
*/
void print_matrix(int matrix[50][50]);

/*******************
 * Function Implementations
*******************/

void read_file_create_graph(Graph **graph, FILE *file) {
    int a, i = 0;
    char Line[300];

    Graph *node_to_insert, *base_node;

    node_to_insert = initialize_graph();
    base_node = initialize_graph();
    
    if (fgets(Line, 100, file)) {
        for (a = 0; a < (strlen(Line)); a++) {
            if (Line[a] != ' ') insert_main_list(graph, Line[a]);   
        }
    }

    while (!feof(file)) {
        if (fgets(Line, 100, file)) {
            for (a = 0; a <= (strlen(Line)); a++) {
                if (Line[a] == '1') {
                    node_to_insert = find_vertex(*graph, a + 1);
                    base_node = find_vertex(*graph, (i + 1));
                    insert_at_end_adj_list(&node_to_insert->main_list, &base_node);
                }

                if (Line[a] == '1' || Line[a] == '0') {                
                    adjacency_matrix_a[i][a] = Line[a];
                }
            }
        }
        i++;
    }
}


void print_matrix(int matrix[50][50]) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}
