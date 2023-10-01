#include "graph.h"
#include "stack.h"

#define num_vertices 4
#define MAX_INT 5e10

int adjacency_matrix_a[50][50];
int final_matrix[50][50];
int visited_nodes[500];

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

void dijkstra(int start, int end){
    final_matrix[0][start-'A'] = 0; // path from start to start = 0

    for(int i = 0; i < num_vertices; i++){
        if(i != start-'A') final_matrix[0][i] = MAX_INT; // Start the other nodes with inf
    }

    int current = start - 'A';
    int final_matrix_line_atu = 1;
    visited_nodes[start] = 1;

    int sh_path = MAX_INT;

    for(int i = current; i < num_vertices; i++){
        for(int j = 0; j < num_vertices; j++){
            if(adjacency_matrix_a[i][j] != 0){
                final_matrix[final_matrix_line_atu][j] = adjacency_matrix_a[i][j];
                if(sh_path > final_matrix[final_matrix_line_atu][j]){
                    sh_path = j;
                }              
            }
        }

        visited_nodes[sh_path + 'A'] = 1;
        current = sh_path;
        final_matrix_line_atu++;
    }
}
