#include "routines.h"

double calcdistance(vector<double> point1 , vector<double> point2 , long long int dimensions)  //Calculates distance between a point and a cluster centroid
{
    double dist = 0.0;
    for(long long int i = 0 ; i < dimensions ; i++)
    {
        dist += pow((point1[i] - point2[i]) , 2.0);
    }
    return sqrt(dist);
}

void dbscan(long long int clustersNo , long long int minPts , double eps , vector<point> &Points)
{
    long long int size = Points.size();
    long long int dimension = Points[0].dimensions;
    vector<vector<long long int>> adjPoints;
    adjPoints.resize(size);
    vector<vector<long long int>> cluster;
    long long int clusterIdx = -1;
    long long int i = 0 , j = 0;

    cout<<"Inside dbscan"<<endl;   
    //Calculate all reachable points from a given point and store them in a vector
    for(i = 0 ; i < size; i++)
    {
        for(j = 0 ; j < size ; j++)
        {
            
            double dist = calcdistance(Points[i].coordinates , Points[j].coordinates , dimension);
            if(i!=j &&  ((dist - eps)<= 0.0001))
            {

                Points[i].ptsCnt++;
                adjPoints[i].push_back(j);
            }
            
        }
    }
    
    cout<<"Distances calculated"<<endl;
    //Classify them into clusters and Noise
    for(i=0 ; i<size ; i++)
    {
        if(Points[i].ptsCnt >= minPts)  //Core Point
        {
            if(Points[i].clusterId == -1){
            clusterIdx++;      //Increase the cluster Index (It is going to act as the clusterId for the cluster)
            dfs(i,clusterIdx,Points,minPts,adjPoints); 
            }  //Do a dfs to collect all points within the catch of this given point
        }
        else if(Points[i].clusterId != -1)    //Has been classified
        {
            continue;                       //Continue as it is a border point
        }
        else
        {
            Points[i].clusterId = -2;       //Classify it as Noise
        }
        

    }

}

void dfs(long long int idx , long long int cluster , vector<point> &Points , long long int minPts, vector<vector<long long int>> adjPoints)
{
    Points[idx].clusterId = cluster;
    if(!(Points[idx].ptsCnt >= minPts)) return;
    long long int size = adjPoints[idx].size();
    //Start going through the graph
    for(long long int i = 0 ; i < size ; i++)
    {
        if(Points[adjPoints[idx][i]].clusterId != -1) continue;   //If already classified, let it be
        dfs(adjPoints[idx][i] , cluster,Points,minPts,adjPoints);    //If not classified, check if it can be added to this cluster.
    }
    
}
