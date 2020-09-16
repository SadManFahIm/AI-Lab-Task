#include<bits/stdc++.h>
using namespace std;

 void find_neighbors()
     {
         int nodes, edges, source, dest,node1;
    cout<< "Enter nodes: ";
    cin>> nodes;
    int matrix[nodes][nodes];
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++)
            matrix[i][j]=0;
    }
    cout<< "Enter edges: ";
    cin>>edges;
    if(edges> nodes*(nodes-1)){
        cout<< "Invalid value";
        cin>> nodes;
    }
    for(int i=0; i<edges; i++){
        cin>>source;
        cin>> dest;
        matrix[source-1][dest-1]=1;
    }

         cout<< "Enter neighbor node: ";
    cin>>node1;
         for(int i=0; i<nodes; i++){

      if(matrix[node1-1][i]==1)

          cout<<i+1;


    }
     }
int main(){


     find_neighbors();

}

