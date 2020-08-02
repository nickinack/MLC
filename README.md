
# :sparkles: :sparkles: About :sparkles: :sparkles:
The MLC++ is a collection of C++ Emulators for unsupervised clustering algorithms. The algorithms planned to be coded are KNN clustering , DBSCAN clustering and PCA reduction with optimised space and time complexity. The objective of this project is to get a deeper understanding and working of each of the above mentioned algorithm. Work is in progress. The project uses file handling as a method to store data. Programs have been segmented into modular files in order to have an easier workflow.

# Running
Go to the directory which contains your desired clustering algorithm and type the following commands
```bash
g++ -std=c++2a main_driver.cpp routines.cpp routines.h
```
After compiling, create your input files in <i>input_files/inputs.txt</i>. Run the following commands to execute the code in the driver directory

- For <b>KNN</b>, use the following command
```bash
./a ../input_files/inputs.txt <Number of Clusters>
```
- For <b>DBSCAN</b>, use the following command
```bash
./a ../input_files/inputs.txt <Minimum number of points> <ephsilon> <Point Cluster Comparator integer>
```
-For <b>PCA</b>, use the following command
```bash
./a ../input_files/inputs.txt 
```

Voila! You can get your results at <i>output_files/results.txt</i>

# Input Format
Each input case should be seperated by an <b>end-line</b>. Each coordinate in the input should be seperated by <b>a space</b>. Note that the algorithm supports 10,000 dimensions.
An example of an input is shown below:

```Input
2 4
-3 3
2 3
1 4
-4 5
-4.3 3.4
2.8 2.4
-4.2 2.2
```

# Output Format
The general output format is shown below:

 ```Output
<!--------Points--------->
0  Cluster 1  2 4 
1  Cluster 0  -3 3 
2  Cluster 1  2 3 
3  Cluster 1  1 4 
4  Cluster 0  -4 5 
5  Cluster 0  -4.3 3.4 
6  Cluster 1  2.8 2.4 
7  Cluster 0  -4.2 2.2 
<!-----EndPoints--------->
```

<b><i>Note that KNN will have centroid coordinates written in the output file too.</b></i>

# Testing 
Testing has been done in individual folders with a dataset suitable for that cluster. For example , for KNN , a simple clustering division has been used. But, for DBSCAN, spirals have been used to analyse frontiers with Noise and analyse the perfomance of the algorithm. If any test case does not provide an optimal solution, you are welcome to open an ISSUE / make a PR for the fix.

# Contributors

<a href="https://github.com/nickinack/">Karthik Viswanathan</a>


