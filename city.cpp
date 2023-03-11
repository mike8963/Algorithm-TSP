#include "tsp.hpp"

city::city(string str,double a,double b) 
{
    cityname = str;
    x = a;
    y = b;
}
double distance(city a,city b)
{
    double distance_x = a.x - b.x;
    double distance_y = a.y - b.y;
    return sqrt(distance_x*distance_x + distance_y*distance_y);
}
string city::getName()
{
    return cityname;
}
double city::get_x()
{
    return x;
}
double city::get_y()
{
    return y;
}
