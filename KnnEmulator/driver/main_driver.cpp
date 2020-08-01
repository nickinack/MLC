#include "routines.h"

int main(int argc, char **argv){

    //File Handing
   
    if(argc != 3){
        cout<<"Wrong number of arguments"<<endl;
        return 1;
    }

    long long int K = atoi(argv[2]);  //Count the Number of Clusters
    string filename = argv[1];         //Read Filename
    ifstream infile;
    infile.open(filename.c_str());

    if(!infile.is_open()){
        cout<<"Error opening "<<filename<<endl;
        return 1;
    }

    cout<<"File handling execution over!"<<endl;

    //Points Initialisation

    long long int pointId = 0;
    vector<point> points;
    vector<double> values;
    double val;
    long long int dimensions = 0;
    string line;

    while(getline(infile, line)){
        stringstream is(line);
        dimensions = 0;
        values.clear();
        while(is >> val){
            values.push_back(val);
            dimensions++;
        }
        point Point = {values , 0 , dimensions, pointId};
        points.push_back(Point);
        pointId++;
    }
    infile.close();

    if(pointId < K)
    {
        cout<<"Number of clusters greater than number of points"<<endl;
        return 1;
    }

    cout<<"Points Initialised"<<endl;
    //Clusters Initialisation

    vector<long long int> used_pointIds;
    vector<cluster> clusters;
    vector<double> centroid;

    for(long long int i=0; i<K; i++)
    {
        centroid.clear();
        while(true)
        {
            long long int index = rand() % (pointId);

            if(find(used_pointIds.begin(), used_pointIds.end(), index) == used_pointIds.end())
            {
                used_pointIds.push_back(index);
                points[index].clusterId = i;
                for(long long int j = 0 ; j < dimensions; j++)
                {
                    centroid.push_back(points[index].coordinates[j]);
                }
                clusters.push_back({centroid , i});
                break;
            }
        }
    }
    cout<<"Clusters Initialised"<<endl;

    // Run K-Means for 100 iterations

    for(long long int i = 0 ; i < 100 ; i++)
    {
        kmeans(points , clusters , pointId , K , i);
        
    }

    cout<<"Kmeans over"<<endl;

    // Print the results

    ofstream outfile;
    outfile.open("../output_files/results.txt");
    if(outfile.is_open()){
        outfile<<"<!--------Clusters------->"<<endl;
        for(long long int i=0; i<K; i++){
            for(long long int j=0; j<dimensions; j++){
                outfile<<clusters[i].centroid[j]<<" ";  //Output to file
            }
            outfile<<endl;
            }
        outfile<<"<!-----EndClusters------->";
        outfile<<endl;
        outfile<<"<!--------Points--------->"<<endl;
        for(long long int i = 0 ; i < pointId ; i++)
        {
            outfile<<points[i].pointId<<"  ";
            outfile<<"Cluster "<<points[i].clusterId<<"  ";
            for(long long int j = 0 ; j < dimensions ; j++)
            {
                outfile<<points[i].coordinates[j]<<" ";
            }
            outfile<<endl;
        }
        outfile<<"<!-----EndPoints--------->";
        outfile<<endl;
        outfile.close();
        }
    else{
        cout<<"Unable to write Results";
        return 1;
    }
    cout<<"Info written into result.txt"<<endl;

    return 0;
}