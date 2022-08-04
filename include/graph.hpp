#include <vector>
#include <iostream>
#include <string>
#include <climits>
using namespace std;
struct Node
{
    int id;
};

struct Edge
{
    int from_node;
    int to_node;
    int traffic;
    float distance;
};

class Graph
{
private:
    vector<Node> nodes;
    vector<Edge> edges;

public:
    void add_node();
    void add_edge(int from, int to, float distance, int traffic = 1);
    float get_edge_total_cost(Edge edge);
    int get_graph_size();
    int get_min_distance_node(float distances[], bool is_visited[]);
    void print_resault(float distances[], string path[]);
    void find_best_path(int from, int to);
};