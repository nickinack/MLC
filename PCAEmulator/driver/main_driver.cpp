#include "routines.h"


using namespace std;
int main(int argc, char **argv)
{
	if(argc!=2) return 1;
	string filename = argv[1];         //Read Filename
    ifstream infile;
    infile.open(filename.c_str());
    if(!infile.is_open()){
        cout<<"Error opening "<<filename<<endl;
        return 1;
    }
	int M=2, N=10;
	double** data = new double*[N];
	for(int i=0;i<N;i++)
		data[i] = new double[M];
	double val;
	 string line;
	long long int m = 0 , n = 0;
    while(getline(infile, line)){
        stringstream is(line);
		n=0;
        while(is >> val){
            data[m][n] = val;
			n++;
        }
		m++;
    }
    infile.close();
		
	double** result=PCA(data,M,N,true); 

	  ofstream outfile;
    outfile.open("../output_files/results.txt");
    if(outfile.is_open()){
        outfile<<"<!-----------------RESULTS--------------->"<<endl;
		outfile<<result[0][0]<<" "<<result[0][1]<<" "<<result[0][2]<<endl;
	    outfile<<result[1][0]<<" "<<result[1][1]<<" "<<result[1][2]<<endl;
		outfile<<"<!-----------------RESULTS--------------->"<<endl;
        outfile.close();
        }
	
	
	
	for(int i=0;i<M;++i)
		delete [] result[i];
	delete [] result;
	return 0;
}