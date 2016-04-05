#include "TSP.h"

void TSP::tsp()
{
    std::map<std::pair<int, int>, double> edges;
    int u, v, highest_vertice = 0;
    double w, heavy_weight = std::numeric_limits<int>::min(), light_weight = std::numeric_limits<int>::max();
    while (std::cin >> u >> v >> w && !std::cin.eof())
    {
        std::pair<int, int> key(u, v);
        edges[key] = w;
        if (heavy_weight < w)
        {
            heavy_weight = w;
        }
        if (light_weight > w)
        {
            light_weight = w;
        }
        if (highest_vertice < u)
        {
            highest_vertice = u;
        }
        if (highest_vertice < v)
        {
            highest_vertice = v;
        }
    }

    //std::pair<int, int> key(3, 7); will look up pair also key.first and key.second are publicly accessible
}

int main()
{
    TSP Travelling_Salesman_Problem;
    Travelling_Salesman_Problem.tsp();
}
