#include "graph.hpp"
#include <iostream>
using namespace std;

void Graph::add_node()
{
    Node temp_node;
    temp_node.id = nodes.size();
    nodes.push_back(temp_node);
}

void Graph::add_edge(int from, int to, float distance, int traffic)
{
    if (from != to && from < nodes.size() && to < nodes.size() && from >= 0 && to >= 0)
    {
        Edge temp_edge;
        temp_edge.from_node = from;
        temp_edge.to_node = to;
        temp_edge.distance = distance;
        temp_edge.traffic = traffic;
        edges.push_back(temp_edge);
    }
    else
    {
        cout << "Cannot find the node!!!\t" << from << '\t' << to << endl;
    }
}

float Graph::get_edge_total_cost(Edge edge)
{
    return edge.distance * edge.traffic;
}
int Graph::get_graph_size()
{
    return nodes.size();
}
int Graph::get_min_distance_node(float distances[], bool is_visited[])
{
    float min = INT_MAX;
    float min_index;

    for (int v = 0; v < get_graph_size(); v++)
    {
        if (!is_visited[v] && distances[v] <= min)
        {
            min = distances[v];
            min_index = v;
        }
    }
    return min_index;
}

void Graph::print_resault(float distances[], string path[])
{
    cout << "Vertex \t Distance from Source \t Path" << endl;
    for (int i = 0; i < get_graph_size(); i++)
    {
        cout << i << " \t\t" << distances[i] << "\t\t" << path[i] << endl;
    }
}

void Graph::find_best_path(int from, int to)
{
    float distances[get_graph_size()];
    bool is_visited[get_graph_size()];
    string path[get_graph_size()];

    for (int v = 0; v < get_graph_size(); v++)
    {
        distances[v] = INT_MAX;
        is_visited[v] = false;
    }

    distances[from] = 0;
    path[from] = to_string(from);

    for (int i = 0; i < get_graph_size() - 1; i++)
    {
        int min_index = get_min_distance_node(distances, is_visited);
        is_visited[min_index] = true;
        for (auto &edge : edges)
        {
            if (edge.from_node == min_index && !is_visited[edge.to_node] && distances[edge.from_node] + get_edge_total_cost(edge) < distances[edge.to_node])
            {
                distances[edge.to_node] = distances[edge.from_node] + get_edge_total_cost(edge);
                path[edge.to_node] = path[edge.from_node] + "->" + to_string(edge.to_node);
            }
        }
    }
    print_resault(distances, path);
    cout << "Best path from " << from << " to " << to << " is: " << distances[to] << endl;
}