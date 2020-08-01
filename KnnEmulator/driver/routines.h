//
//  routines.h
//  knn
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
    long long int clusterId;   //Stores cluster number it currently belongs to
    long long int dimensions;   //Stores the dimension
    long long int pointId;      //Id given to the point
};

struct cluster{

    vector<double> centroid;    //Stores the centroid coordinates
    long long int clusterId;    //Stores the Id of the current cluster

};

double calcdistance(vector<double> point , vector<double> centroid , long long int dimensions);  //Calculates distance between a point and a cluster centroid
void kmeans(vector<point> &points , vector<cluster> &clusters , long long int pointsNo , long long int clustersNo , long long int iter);  //Function computing one iteration of K-Means
#endif 