# [Dijkstra's Algorithm Implementation](dijkstra_algortihm.c)

## Overview
This repository contains an implementation of Dijkstra's algorithm, a well-known algorithm used for finding the shortest path in a weighted graph. Dijkstra's algorithm is widely applied in various fields, including network routing, transportation optimization, and more.

## Algorithm Complexity
- **Time Complexity**: Dijkstra's algorithm has a time complexity of O(V^2) with an adjacency matrix or O(E + V log V) with a suitable data structure like a binary heap, where V is the number of vertices and E is the number of edges. This implementation employs an adjacency list and a binary heap for optimized performance.

- **Space Complexity**: The space complexity is O(V + E) as it requires storage for the graph representation.

## Files
- **[dijkstra_algorithm.c](dijkstra_algortihm.c)**: This is the main implementation of Dijkstra's algorithm, containing the code for finding the shortest path in a graph.

- **[dijkstra/graph.h](./djisktra/graph.h)**: The header file `graph.h` includes the necessary data structures and functions for graph representation. It is utilized to create the graph.

- **[dijkstra/dijkstra.h](./djisktra/dijkstra.h)**: The header file `dijkstra.h` contains the core logic of Dijkstra's algorithm, including shortest path calculations and relevant data structures.

- **[adj_a.txt](adj_a.txt)**: This text file holds the adjacency list, representing the graph that Dijkstra's algorithm operates on. You can replace this file with your own graph data or use it as a reference.

## Usage
To utilize this implementation, please follow these steps:
1. Compile the code in `dijkstra_algorithm.c` and link it with the other source files.
2. Prepare your graph data in the format specified in `adj_a.txt` or adapt the code to read your custom data format.
3. Execute the compiled program to find the shortest path in your graph.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments
Thank you for exploring this implementation of Dijkstra's algorithm. If you find it helpful or have any suggestions for enhancements, please consider contributing or providing feedback. Your input is highly valued.
