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

    int start = (rand() % num_vertices) + 65;
    int end = 75;

    printf("Complete Graph: \n");
    print_complete_graph(graph_a);

    printf("\nStart: %c End: %c\n\n", start, end);
    int found = dijkstra(start, end);

    if(found){
        printf("=-=-=-=-=-=-=-= Found! =-=-=-=-=-=-=-=\n");

        build_final_path(start, end);

        printf("\nFinal matrix: \n");
        print_final_matrix(final_matrix);

        printf("\nDistance from %c to %c: %d\n", start, end, path_size);
        printf("Path: ");
        for(int i = choice_atu-1; i >=0; i--) printf("%c ", path[i]);
        printf("\n");

    }else printf("Not found!\n");

    fclose(file_a);

    return 0;
}
