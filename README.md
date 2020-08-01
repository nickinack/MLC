# MLC++
:sparkles: :sparkles: :sparkles: :sparkles: :sparkles: :sparkles: :sparkles: :sparkles: Work In Progress :sparkles: :sparkles: :sparkles: :sparkles: :sparkles: :sparkles: :sparkles: :sparkles:

# About
The MLC++ is a collection of C++ Emulators for unsupervised clustering algorithms. The algorithms planned to be coded are KNN clustering , DBSCAN clustering and Hirearchial clustering with optimised space and time complexity. The objective of this project is to get a deeper understanding and working of each of the above mentioned algorithm. Work is in progress. The project uses file handling as a method to store data. Programs have been segmented into modular files in order to have an easier workflow.

# Running
Go to the directory which contains your desired clustering algorithm and type the following commands
```bash
g++ -std=c++2a main_driver.cpp routines.cpp routines.h
```
After compiling, create your input files in <i>input_files/inputs.txt</i>. Run the following commands to execute the code
```bash
./a
```
Voila! You can get your results at <i>output_files/results.txt</i>

# Input Format
Each input case should be seperated by an <b>end-line</b>. Each coordinate in the input should be seperated by <b>a space</b>.
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
The output format is shown below:

 ```Output
 <!--------Clusters------->
-3.875 3.4 
1.95 3.35 
<!-----EndClusters------->
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

# Contributors

<a href="https://github.com/nickinack/">Karthik Viswanathan</a>


