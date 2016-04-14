#include "TSP.h"

void TSP::tsp()
{
    std::map<std::pair<int, int>, double> edges; //initial edges
    std::map<std::pair<int, int>, double> solution; //final solution
    std::vector<std::vector<int> > edges_key; //key for lookup within edges
    std::vector<int> loadvec; //used for loading vector of vectors
    std::vector<std::pair<int, int> > solution_key; //key for outputting final solution to cout
    std::vector<int> nodes; //used for tracking purposes
    int u, v, x, current_node, n = std::numeric_limits<int>::min();
    double w, max_possible_weight, min_possible_weight, weight_of_cycle = 0, heavy_edge = std::numeric_limits<double>::min(), light_edge = std::numeric_limits<double>::max(), best = std::numeric_limits<double>::max();
    while (std::cin >> u >> v >> w && !std::cin.eof())
    {
        nodes.push_back(u);
        std::pair<int, int> key(u, v);
        edges[key] = w;
        loadvec.push_back((u));
        loadvec.push_back((v));
        if (u == 1 && w < best)
        {
            x = v;
            best = w;
        }
        if (heavy_edge < w)
        {
            heavy_edge = w;
        }
        if (light_edge > w)
        {
            light_edge = w;
        }
        if (n < u)
        {
            n = u;
        }
        edges_key.push_back(loadvec);
        loadvec.clear();
    }

    std::sort(nodes.begin(), nodes.end()); //sort and remove duplicates 
    nodes.erase(std::unique(nodes.begin(), nodes.end()), nodes.end());

    max_possible_weight = heavy_edge * n;
    min_possible_weight = light_edge * n;

    std::pair<int, int> key(1, x);
    solution[key] = edges[key]; //sets best start into solution
    solution_key.push_back(key);
    nodes.erase(std::remove(nodes.begin(), nodes.end(), 1), nodes.end()); //erase 1 from nodes list
    current_node = x;
    while (nodes.size() > 0)
    {
        best = std::numeric_limits<double>::max();
        for (size_t i = 0; i < edges_key.size(); i++)
        {
            if (nodes.size() == 1)
            {
                x = 1;
                std::pair<int, int> key(current_node, 1);
                break;
            }
            std::pair<int, int> currentKey(edges_key[i][0], edges_key[i][1]);
            if (edges_key[i][0] == current_node && edges[currentKey] < best)
            {
                bool found = false;
                for (size_t n = 0; n < nodes.size(); n++)
                {
                    if (edges_key[i][1] == nodes[n])
                    {
                        found = true;
                    }
                }
                if (found)
                {
                    x = edges_key[i][1];
                    best = edges[currentKey];
                    found = false;
                }
            }
        }
        std::pair<int, int> key(current_node, x);
        solution[key] = edges[key];
        solution_key.push_back(key);
        nodes.erase(std::remove(nodes.begin(), nodes.end(), current_node), nodes.end()); //erase current node from nodes list
        current_node = x;
    }

    for (size_t i = 0; i < solution_key.size(); i++) //output to cout
    {
        weight_of_cycle += solution[solution_key[i]];
        std::cout << solution_key[i].first << ' ';
    }

    std::cout << weight_of_cycle << ' ' << (1 - ((weight_of_cycle - min_possible_weight) / (max_possible_weight - min_possible_weight))) << std::endl;
}

int main()
{
    TSP Travelling_Salesman_Problem;
    Travelling_Salesman_Problem.tsp();
    return 0;
}
