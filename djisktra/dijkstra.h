#include "graph.h"

int num_vertices = 0;
int path_size = 0;
int choice_atu = 0;
char path[50];

typedef struct{
    int letter;
    int weight;
}tp_node;

#define MAX_INT 5000

int adjacency_matrix_a[50][50];
int final_matrix[50][50];
int visited[500];
int num_visited = 0;

void read_file_create_graph(Graph **graph, FILE *file) {
    int a, i = 0;
    char Line[300];

    Graph *node_to_insert, *base_node;

    node_to_insert = initialize_graph();
    base_node = initialize_graph();
    
    if (fgets(Line, 100, file)) {
        for (a = 0; a < (strlen(Line)); a++) {
            if (Line[a] != ' '){
                insert_main_list(graph, Line[a]);
                if(Line[a] >= 65) num_vertices++;
            }   
        }
    }

    int weight;
    while (!feof(file) && i < num_vertices) {
        for (a = 0; a < num_vertices; a++) {
            fscanf(file, "%d", &weight);

            if(weight > 0){
                node_to_insert = find_vertex(*graph, a + 1);
                base_node = find_vertex(*graph, (i + 1));

                insert_at_end_adj_list(&node_to_insert->main_list, &base_node, weight);
            }
    
            if(weight >= 0) adjacency_matrix_a[i][a] = weight;
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

void print_final_matrix(int matrix[50][50]) {
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int final_matrix_line_atu = 1;

int dijkstra(int start, int end){
    memset(final_matrix, 0, sizeof(final_matrix));
    final_matrix[0][start-'A'] = 0; // path from start to start = 0

    for(int i = 0; i < num_vertices; i++) if(i != start-'A') final_matrix[0][i] = MAX_INT; // Start the other nodes with MAX_INT
    
    int current = start - 'A'; // starts at the second line
    visited[start] = 1; // close the start

    for(int i = current; i < num_vertices; i++){

        int sh_path = MAX_INT;
        int pos_sh_path = i;
        
        for(int j = 0; j < num_vertices; j++){
            
            if(adjacency_matrix_a[i][j] != 0 && visited['A' + j] == 0){                             
                
                if(final_matrix[final_matrix_line_atu-1][j] > adjacency_matrix_a[i][j] + path_size || final_matrix[final_matrix_line_atu-1][j] == 0) 
                    final_matrix[final_matrix_line_atu][j] = adjacency_matrix_a[i][j] + path_size;
                else final_matrix[final_matrix_line_atu][j] = final_matrix[final_matrix_line_atu-1][j]; 
                
                if(sh_path > final_matrix[final_matrix_line_atu][j]){
                    pos_sh_path = j;
                    sh_path = final_matrix[final_matrix_line_atu][j];
                }                         

            }else final_matrix[final_matrix_line_atu][j] = 0;
        }

        if(i + 65 == end) return 1;
        else if(num_visited == num_vertices) return 0;
        else path_size = sh_path;
        
        num_visited++;
        
        visited[pos_sh_path + 'A'] = 1; // close the shortest
        i = pos_sh_path-1; // goes for the shortest
        final_matrix_line_atu++;
        
    }

    return 0;
}

void build_final_path(int start, int end){
    int atu = end - 65;

    for(int i = final_matrix_line_atu; i > 1; i--){
        if(final_matrix[i][atu] != final_matrix[i-1][atu]){
            int smaller = MAX_INT;
            for(int j = 0; j < num_vertices; j++){
                if(final_matrix[i-1][j] < smaller && final_matrix[i-1][j] != 0){              
                    smaller = final_matrix[i-1][j];
                    atu = j;        
                }
            }
            path[choice_atu++] = atu+65;
        }     
    }

    path[choice_atu++] = start;

}