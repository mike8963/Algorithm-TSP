#include "tsp.hpp"

int main(int argc,char* argv[])
{
    TSP tsp(argv[1]);
    tsp.get_shortest_distance();
    return 0;
}