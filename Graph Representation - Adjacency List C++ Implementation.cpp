#include <bits/stdc++.h>
using namespace std;

typedef pair <int,int> PII; //destination and cost
vector<PII> v[100];
int vertex,edges;


void printGraph()
{
    for(int i=0;i<vertex;i++)
    {
        cout<<i<<"----"; //source 
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j].first<<"-"<<v[i][j].second<<" "; //destination and cost
        }
        cout<<endl;
    }
    cout<<endl;
}

void createGraph()
{
    int source,temp;
    PII p;
    cin>>vertex>>edges;
    for(int i=0;i<edges;i++)
    {
        cin>>source>>p.first>>p.second; //source,destination,cost
        v[source].push_back(p); //store
        
        
        //this doing for bi-directional grapph
        temp=p.first;
        p.first=source;
        v[temp].push_back(p);
    }
}
int main() 
{
    createGraph();
    printGraph();

    return 0;
}
