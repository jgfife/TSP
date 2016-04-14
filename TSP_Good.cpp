#include "TSP_Good.h"

void TSP::tsp()
{
    std::map<std::pair<int, int>, double> edges;
    int u, v, n = std::numeric_limits<int>::min();
    double w, max_possible_weight, min_possible_weight, weight_of_cycle = 0, heavy_edge = std::numeric_limits<int>::min(), light_edge = std::numeric_limits<int>::max();
    while (std::cin >> u >> v >> w && !std::cin.eof())
    {
        std::pair<int, int> key(u, v);
        edges[key] = w;
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
        if (n < v)
        {
            n = v;
        }
    }

    max_possible_weight = heavy_edge * n;
    min_possible_weight = light_edge * n;
    int j;
    for (int i = 1; i <= n; i++)
    {
        j = (i + 1);
        if (j > n)
        {
            j = 1;
        }
        std::pair<int, int> key(i, j);
        weight_of_cycle += edges[key];
        std::cout << key.first << ' ';
    }

    std::cout << weight_of_cycle << ' ' << (1 - ((weight_of_cycle - min_possible_weight) / (max_possible_weight - min_possible_weight))) << std::endl;
}

int main()
{
    TSP Travelling_Salesman_Problem;
    Travelling_Salesman_Problem.tsp();
}
