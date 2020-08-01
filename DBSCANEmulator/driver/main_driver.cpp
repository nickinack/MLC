#include "routines.h"

int main(int argc, char **argv){

    //File Handing
   
    if(argc != 5){
        cout<<"Wrong number of arguments"<<endl;
        return 1;
    }

    long long int K = atoi(argv[4]);  //Count the Number of Clusters
    string filename = argv[1];         //Read Filename
    ifstream infile(filename.c_str());

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
        pointId++;
        point Point = {values , -1 , dimensions , 0};
        points.push_back(Point);
    }
    infile.close();

    if(pointId < K)
    {
        cout<<"Number of clusters greater than number of points"<<endl;
        return 1;
    }

    cout<<"Points Initialised"<<endl;

    // Run DBSCAN
    dbscan(K , atoi(argv[2]) , atoi(argv[3]) , points);
    cout<<"DSCAN has run successfully"<<endl;

    // Write to output file
    ofstream outfile;
    outfile.open("../output_files/results.txt");
    cout<<"Opened output file"<<endl;

    if(outfile.is_open()){
        outfile<<"<!--------Points--------->"<<endl;
        for(long long int i = 0 ; i < pointId ; i++)
        {
            outfile<<i<<"  ";
            if(points[i].clusterId != -2)
            {
                outfile<<"Cluster "<<points[i].clusterId<<"  ";
            }
            else 
            {
                outfile<<"NOISE  ";
            }
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
    cout<<"Info written into results.txt"<<endl;

    return 0;
}

