#include<bits/stdc++.h>
using namespace std;



int main(){
    int nodes, edges, source, destination;
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
        cin>> destination;
        matrix[source-1][destination-1]=1;
    }
    for(int i=0; i<nodes; i++){
        for(int j=0; j<nodes; j++)
            cout<<matrix[i][j] << " ";
        cout<<endl;
    }
    int node, flag;
    while(true){
        cout<< "Enter node for neighbors: ";
        cin>>node;
        for(int i =0; i<nodes; i++){
            if(matrix[node-1][i]==1)
                cout<< i+1 << " ";
        }
        cout<<endl;
        cout<< "Enter 1 to continue or 2 to exit: ";
        cin>>flag;
        if(flag==2)
            break;

    }
}
