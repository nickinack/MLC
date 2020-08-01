//
//  routines.h
//  DBSCAN
//
//  Created by Karthik Viswanathan on 01/08/2021.
//

#ifndef routines_h
#define routines_h

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <fstream>
#include <sstream>
using namespace std;

struct point{
    vector<double> coordinates; //Stores coordinates in the form (x,y,z,..)
    long long int clusterId;   //Stores cluster number it currently belongs to. If cluster ID is -2; then it is considered as a noise
    long long int dimensions;   //Stores the dimension
    long long int ptsCnt;      //Stores number of points within ephsilon range
};

void dfs(long long int idx , long long int cluster , vector<point> &Points , long long int minPts, vector<vector<long long int>> adjPoints);
double calcdistance(vector<double> point1 , vector<double> point2 , long long int dimensions);
void dbscan(long long int clustersNo , long long int minPts , double eps , vector<point> &Points);
#endif 