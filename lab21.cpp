#include<bits/stdc++.h>
using namespace std;

string Reflex_Vaccum_Agent(char location, char status){
    if(status=='D')
        return "Suck";
    else if(location=='A')
        return "Right";
    else if (location=='B')
    return "left";
}
int main(){
        char location, status;
        int flag;
        while(1){
            cout<< "Enter location:";
            cin>> location;
            cout<<"Enter Dirt Status:";
            cin>> status;
            cout<< Reflex_Vaccum_Agent(location,status)<<endl;
            cout<< "enter 1 to continue or 2 to exit: ";
            cin>>flag;
            if(flag==1)
                continue;
            else
                break;
        }
}

