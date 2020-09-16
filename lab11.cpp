#include<bits/stdc++.h>
using namespace std;

int number = 0;

void fibonacci(int arr[], int index){
    if(index==0 && index<=number){
        arr[0]=1;
        fibonacci(arr,index+1);
    }
    else if(index==1 && index<=number){
        arr[1]=1;
        fibonacci(arr,index+1);
    }
    else if(index>1 && index<=number){
        int sum = arr[index-1]+ arr[index-2];
        arr[index]=sum;
        fibonacci(arr, index+1);
    }

}

int main(){
    cout<< "Enter number: ";
    cin>>number;
    int fib[number];
    fibonacci(fib,0);
    for(int i=0; i<number; i++)
        cout<< fib[i] << " ";
    cout<<endl;

}
