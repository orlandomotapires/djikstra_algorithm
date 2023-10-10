#include "graph.h"
#include "stack.h"

#define num_vertices 4
#define MAX_INT 5000

int adjacency_matrix_a[50][50];
int final_matrix[50][50];
int closed_nodes[500];
int num_closed_nodes = 0;

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

int dijkstra(int start, int end){

    memset(final_matrix, 0, sizeof(final_matrix));
    memset(closed_nodes, 0, sizeof(closed_nodes));
    
    final_matrix[0][start-'A'] = 0; // path from start to start = 0

    for(int i = 0; i < num_vertices; i++){
        if(i != start-'A') final_matrix[0][i] = MAX_INT; // Start the other nodes with MAX_INT
    }

    int current = start - 'A';
    int final_matrix_line_atu = 1; // starts at the second line
    closed_nodes[start] = 1; // close the start

    for(int i = current; i < num_vertices; i++){

        int sh_path = MAX_INT;
        for(int j = 0; j < num_vertices; j++){
            if(adjacency_matrix_a[i][j] != 0){
                if(closed_nodes['A' + j] == 0){
                    final_matrix[final_matrix_line_atu][j] = adjacency_matrix_a[i][j];

                    if(sh_path > final_matrix[final_matrix_line_atu][j]) sh_path = j;
                    
                }else{
                    final_matrix[final_matrix_line_atu][j] = final_matrix[final_matrix_line_atu-1][j]; // repeat the last value
                }          
            }
        }

        num_closed_nodes++;
        closed_nodes[sh_path + 'A'] = 1; // close the shortest
        current = sh_path; // goes for the shortest

        if(current + 'A' == end) return 1;
        else if(num_closed_nodes == num_vertices) return 0;

        final_matrix_line_atu++;
    }

    return 0;
}
