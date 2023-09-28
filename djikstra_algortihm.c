/*
Authors:

    Orlando Mota Pires https://github.com/orlandomotapires
    Pedro Menezes https://github.com/pedromenezes49

*/

#include "./libraries/isomorphism.h"

int main() {
    FILE *file_a, *file_b;
    Graph *graph_a, *graph_b;

    file_a = fopen("./matrixes/adj_a.txt", "rt");
    file_b = fopen("./matrixes/adj_b.txt", "rt");

    graph_a = initialize_graph();
    graph_b = initialize_graph();

    if (file_a == NULL || file_b == NULL) {
        printf("Problems opening the file\n");
        return 1;
    }

    read_file_create_graph(&graph_a, file_a, 0);
    read_file_create_graph(&graph_b, file_b, 1); // Need this to create the adjacency_matrix_b for start the permutations on the brute_force

    /* 
        Verifying if they are isomorphic with the brute_force. The brute_force just call the is_isomorphism (check the isomorphism between two graphs) function of each one possible 
        permutation from the original graph. If any one of all the possible permutations pass, they are isomorphic.
    */

    if(!brute_force(graph_a)) printf("They are isomorphic!\n");

    fclose(file_a);
    fclose(file_b);

    return 0;
}
