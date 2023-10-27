/*
Authors:

    Orlando Mota Pires https://github.com/orlandomotapires
    Pedro Menezes https://github.com/pedromenezes49

*/

#include "djisktra/dijkstra.h"
#include <time.h>

int main() {
    FILE *file_a;
    Graph *graph_a;

    file_a = fopen("./adj_a.txt", "rt");

    graph_a = initialize_graph();

    memset(visited, 0, sizeof(visited));
    srand(time(NULL));

    if (file_a == NULL) {
        printf("Problems opening the file\n");
        return 1;
    }

    read_file_create_graph(&graph_a, file_a);

    // Gere um número aleatório no intervalo de 1 a num_vertices para ser o no inicial
    int letra_aleatoria_1 = (rand() % num_vertices) + 65;
    
    // Gere uma letra aleatório no intervalo de A a num_vertices para ser o no final
    int letra_aleatoria_2 = (rand() % num_vertices) + 65;

    printf("Complete Graph: \n");
    print_complete_graph(graph_a);

    dijkstra(letra_aleatoria_1, letra_aleatoria_2);

    printf("\nFinal matrix: \n");
    print_final_matrix(final_matrix);

    fclose(file_a);

    return 0;
}
