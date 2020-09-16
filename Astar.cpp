#include<iostream>
#include<utility>
#include<queue>


using namespace std;

int node, hur_val[1000];
int edge;
int adjMat[1000][1000], d[1000], par[1000];
int start,finish,pathcost=0;

    pair <int, int> p;
    pair <int, string> path[1000];

    priority_queue < pair<int, int> > pq;
    priority_queue < pair<int, int> > coutcost;
    priority_queue < pair<int, int> > coutcost_hur;



void input()
{
    cout<<"Enter The Number of Nodes and Edges:"<<endl;
     cin >> node>>edge;

    cout<<"Edges:"<<endl;
    for( int i = 0; i < edge; i++ )
    {
        int u, v, cost;
        cin >> u;
        cin >> v;
        cin >> cost;
        cin >> hur_val[v];
        adjMat[u][v] = cost;
    }
}
void output()
{
    while(!pq.empty())
    {
        pq.pop();
    }
    pq=coutcost_hur;
    while(!coutcost_hur.empty())
    {
        p=coutcost_hur.top();
        if (p.second==finish)
        pathcost =p.first;
        coutcost_hur.pop();
    }
    if(pathcost!=0)
        {
            cout<<"Node "<<finish<< " found!\n"<<"COST = " << pathcost << endl;
            cout<<"Path:\n"<<path[finish].second<<endl;
        }
    else
        {cout<<"Node not found !!"<<endl;}

        while(!pq.empty())
                {
                    p=pq.top();
                       cout << "1 to "<<p.second<<" cost is -> "<<p.first<<endl;
                    pq.pop();
                }

}

void initiate()
{
     for( int i = 0; i < 1000; i++ )
    {
        par[i] = -1;
        d[i] = 1000;
        for( int j = 0; j < 1000; j++ )
        {
        adjMat[i][j] = 1000;
        }
    }
}

void ucs_making()
{
    d[start] = 0;
    par[start] = 0;

    p.first = 0;
    p.second = start;

    pq.push( p );

    while( !pq.empty() )
    {
        p = pq.top();
        pq.pop();

        int u = p.second;

        for( int v = 1; v <=node; v++ )
        {
        if( adjMat[u][v] != 1000 )
        {
        if( d[v] > d[u] + adjMat[u][v] )
        {
        d[v] = d[u] + adjMat[u][v];

        p.first = d[v]; ///path cost
        p.second = v;  ///for a node
        coutcost.push( p );  ///ucs
        p.first = d[v] + hur_val[v]; ///path cost with hur value
        coutcost_hur.push( p );  ///A*
        path[v].second=path[u].second; ///path for that node
        }
        pq=coutcost_hur;
        while(!pq.empty())
                {
                    p=pq.top();
                    if (p.second==path[v].first)
                        if(p.first<(d[v] + hur_val[v]))
                        {
                            path[v].first=v; ///jei node er path ber korbo
                            path[v].second=path[u].second; ///path for that node
                        }

                    pq.pop();
                }

        }
        }

        while(!pq.empty())
                {
                    pq.pop();
                }
        for(int i=1; i<=node; i++)
        {
            if(par[i]!=0)
            {
                par[i]=0;
                start=i;
                //for(int i=1; i<node; i
                pq=coutcost;
                while(!pq.empty())
                {
                    p=pq.top();
                    if (p.second==i)
                        d[i]=p.first;
                    pq.pop();
                }

                p.first = 0;
                p.second = start;

                pq.push( p );
                break;
            }
        }


    }
}

int main()
{
    initiate();
    input();
    cout<<endl;
    cout<<endl;
    cout << "START NODE: ";
    cin >> start;
    cout<<endl;
    cout<<endl;
    cout << "GOAL NODE: ";
    cin >> finish;


    ucs_making();


    output();

    return 0;
}
