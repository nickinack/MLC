#include "routines.h"

double calcdistance(vector<double> point , vector<double> centroid , long long int dimensions)  //Calculates distance between a point and a cluster centroid
{
    double dist = 0.0;
    for(long long int i = 0 ; i < dimensions ; i++)
    {
        dist += double(pow((point[i] - centroid[i]) , 2.0));
    }
    return dist;
}


void kmeans(vector<point> &points , vector<cluster> &clusters , long long int pointsNo , long long int clustersNo , long long int iter)  //Function computing one iteration of K-Means
{
   long long int i = 0 , j = 0, dimension = points[0].dimensions;
   //Calculate Distance between all the points and the centroids
   //Assign point to cluster such that the cluster and the point have the least distance
   double min = DBL_MAX;
   double dist;
   long long int min_cluster_id;
   for(i=0; i<pointsNo; i++)
   {
       min = DBL_MAX;
       for(j=0 ; j<clustersNo ; j++)
       {
            dist = calcdistance(points[i].coordinates , clusters[j].centroid , dimension);
            if(iter==1 && dist==0){cout<<points[i].pointId<<endl;}
            if(min - dist > 0.0001)
            {
                min = dist;
                min_cluster_id = clusters[j].clusterId;
            }
       }
       points[i].clusterId = min_cluster_id;
   }

   //Recalculate clusters by taking the mean of all the points in the cluster
   double centroidMean[clustersNo+1][dimension] = {0};    //For each ID , it stores the sum of the points in the cluster
   long long int clusterCount[clustersNo+1] = {0};
   for(i=0; i<pointsNo; i++)
   {
       clusterCount[points[i].clusterId]++;
       for(j=0; j<dimension ; j++)
       {
           centroidMean[points[i].clusterId][j] += double(points[i].coordinates[j]);
       }  
   }

   for(i=0 ; i<clustersNo ; i++)    //Calculate mean of the additive coordinates and assign it to appropriate clusterId's
   {
       for(j=0; j<dimension; j++)
       {
           if(clusterCount[i] != 0){
                centroidMean[i][j]/= clusterCount[i];
                clusters[i].centroid[j] = centroidMean[i][j];
           }
       }

   }

}
