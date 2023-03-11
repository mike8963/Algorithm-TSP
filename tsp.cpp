#include "tsp.hpp"

TSP::TSP(char* filename)
{
    // read file
    fin.open(filename);
    string cityname;
    double temp_x;
    double temp_y;
    cityList.clear();
    while(fin >> cityname)
    {
        fin >> temp_x;
        fin >> temp_y;
        cityList.push_back(city(cityname,temp_x,temp_y));
    }

    // 動態宣告2d array
    distance_between_city = new double*[cityList.size()-1];
    for(int i=0;i<cityList.size()-1;i++)
    {
        distance_between_city[i] = new double[i+1];
    }
    // 儲存各city間距離
    for(int i=0;i<cityList.size()-1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            distance_between_city[i][j] = distance(cityList[i+1],cityList[j]);
        }
    }
    //初始化探訪city順序(0 為未探訪)
    visited = new int[cityList.size()];
    for(int i = 0;i<cityList.size();i++)
    {
        visited[i] = 0;
    }
    // 初始化探訪過city數量為 0
    count_for_visited = 0;
};

double TSP::get_shortest_distance()
{
    for(int i=0;i<cityList.size();i++)
    {
        cout << cityList[i].getName() << "\t" << cityList[i].get_x() << "\t" << cityList[i].get_y() << endl;
    }
    cout << endl;
    for(int i=0;i<cityList.size()-1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            cout << "(" << i+1 << "," << j << "):\t" << distance_between_city[i][j] << "\t";
        }
        cout << endl;
    }
}
/*

distance_between_city 結構:

d[0,0]
d[1,0] d[1,1]
d[2,0] d[2,1] d[2,2]
d[3,0] d[3,1] d[3,2] d[3,3]
...
d[n-1,0] d[n-1,1] d[n-2,2]...d[n-1,n-1]


存的city距離 [city A, city B]
[1,0]
[2,0][2,1]
[3,0][3,1][3,2]
[4,0][4,1][4,2][4,3]
...
[n,0][n,1][n,2]...[n,n-1]

*/