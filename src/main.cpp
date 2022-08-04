#include <iostream>
#include <vector>
#include <climits>
#include "graph.hpp"
using namespace std;



int main(int argc, char const *argv[])
{
    Graph main_graph;

    for (size_t i = 0; i < 16; i++)
    {
        main_graph.add_node();
    }

    main_graph.add_edge(0, 1, 0.2);
    main_graph.add_edge(0, 2, 0.2);
    main_graph.add_edge(0, 3, 0.2, 3);
    main_graph.add_edge(1, 0, 0.2);
    main_graph.add_edge(1, 2, 1.4, 2);
    main_graph.add_edge(1, 3, 1.3, 3);
    main_graph.add_edge(2, 0, 0.2);
    main_graph.add_edge(2, 1, 1.4, 2);
    main_graph.add_edge(2, 3, 0.2, 2);
    main_graph.add_edge(2, 6, 2.4, 2);
    main_graph.add_edge(3, 0, 0.2, 3);
    main_graph.add_edge(3, 1, 1.3, 3);
    main_graph.add_edge(3, 2, 0.2, 2);
    main_graph.add_edge(3, 4, 1.9, 2);
    main_graph.add_edge(3, 5, 2.1, 3);
    main_graph.add_edge(4, 3, 1.9, 2);
    main_graph.add_edge(4, 5, 2);
    main_graph.add_edge(5, 3, 2.1, 3);
    main_graph.add_edge(5, 4, 2);
    main_graph.add_edge(5, 6,1.9, 2);
    main_graph.add_edge(5, 7, 0.1, 3);
    main_graph.add_edge(6, 2, 2.4, 2);
    main_graph.add_edge(6, 5, 1.9, 2);
    main_graph.add_edge(6, 8, 3, 3);
    main_graph.add_edge(7, 5, 0.1, 3);
    main_graph.add_edge(7, 8, 0.1);
    main_graph.add_edge(7, 10, 3.5, 2);
    main_graph.add_edge(7, 11, 0.1, 2);
    main_graph.add_edge(8, 6, 3, 3);
    main_graph.add_edge(8, 7, 0.1);
    main_graph.add_edge(8, 9, 4.1, 2);
    main_graph.add_edge(9, 8, 4.1, 2);
    main_graph.add_edge(9, 10, 1.2, 3);
    main_graph.add_edge(10, 9, 1.2, 3);
    main_graph.add_edge(10, 7, 3.5, 2);
    main_graph.add_edge(10, 12, 0.8, 3);
    main_graph.add_edge(11, 7, 0.1, 2);
    main_graph.add_edge(11, 12, 2);
    main_graph.add_edge(11, 13, 1.1);
    main_graph.add_edge(12, 10, 0.8, 3);
    main_graph.add_edge(12, 11, 2);
    main_graph.add_edge(12, 14, 0.6, 3);
    main_graph.add_edge(13, 11, 1.1);
    main_graph.add_edge(13, 14, 1.8, 2);
    main_graph.add_edge(14, 13, 1.8, 2);
    main_graph.add_edge(14, 12, 0.6, 3);
    main_graph.add_edge(12, 15, 0.2);
    main_graph.add_edge(15, 12, 0.2);

    

    main_graph.find_best_path(0, 15);

    return 0;
}
