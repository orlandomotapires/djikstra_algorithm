/*
Authors:

    Orlando Mota Pires https://github.com/orlandomotapires
    Pedro Menezes https://github.com/pedromenezes49

*/

#include "djisktra/dijkstra.h"

int main() {
    FILE *file_a;
    Graph *graph_a;

    file_a = fopen("./adj_a.txt", "rt");

    graph_a = initialize_graph();

    if (file_a == NULL) {
        printf("Problems opening the file\n");
        return 1;
    }

    read_file_create_graph(&graph_a, file_a);

    print_matrix(adjacency_matrix_a);

    dijkstra('A', 'D');

    fclose(file_a);

    return 0;
}
