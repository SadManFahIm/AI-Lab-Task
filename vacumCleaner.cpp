#include<iostream>
using namespace std;

string cleaning (string location, string status){
    if(status=="Dirty")
    {
        return "Suck";
    }
    else if(location=="A")
    {
        return "Right";
    }
    else if(location=="B")
    {
        return "Left";
    }


}
int main()
{
    string loc,stat;
    while(true){
        cout<<"location:";
        cin>>loc;
        cout<<"Status:";
        cin>>stat;


        cout<<"ACTION: "<<cleaning(loc,stat)<<endl;
    }
}
