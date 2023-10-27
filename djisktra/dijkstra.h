#include "graph.h"
#include "stack.h"

int num_vertices = 0;
int path_size = 0;
char path[50];
int choice_atu = 0;
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

int dijkstra(int start, int end){
    printf("\nStart: %c End: %c\n\n", start, end);

    memset(final_matrix, 0, sizeof(final_matrix));

    final_matrix[0][start-'A'] = 0; // path from start to start = 0

    for(int i = 0; i < num_vertices; i++){
        if(i != start-'A') final_matrix[0][i] = MAX_INT; // Start the other nodes with MAX_INT
    }

    int current = start - 'A';
    int final_matrix_line_atu = 1; // starts at the second line
    visited[start] = 1; // close the start

    for(int i = current; i < num_vertices; i++){
        printf("Current: %c\n", i+65);

        int sh_path = MAX_INT;
        int pos_sh_path;

        for(int j = 0; j < num_vertices; j++){
            
            if(adjacency_matrix_a[i][j] != 0){           
                
                if(visited['A' + j] == 0){
                    final_matrix[final_matrix_line_atu][j] = adjacency_matrix_a[i][j] + path_size;
                 
                    if(sh_path > final_matrix[final_matrix_line_atu][j] + path_size){
                        pos_sh_path = j;
                        sh_path = final_matrix[final_matrix_line_atu][j] + path_size;
                    }
                    
                }else{
                    final_matrix[final_matrix_line_atu][j] = final_matrix[final_matrix_line_atu-1][j]; // repeat the last value
                }          
            }
        }

        printf("shortest_path: %d\n", sh_path);
        printf("next_node: %c\n\n", pos_sh_path+65);

        path_size += sh_path;
        path[choice_atu++] = pos_sh_path+65;

        if(i + 65 == end){
            printf("FOUND!\n");
            return path_size;
        }else if(num_visited == num_vertices) return 0;

        num_visited++;
        
        visited[pos_sh_path + 'A'] = 1; // close the shortest
        i = pos_sh_path-1; // goes for the shortest
        final_matrix_line_atu++;
        
    }

    

    return 0;
}
