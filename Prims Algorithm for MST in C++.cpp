/* Sample input
8 9
0 3 3
0 4 6
1 5 5
1 6 1
2 4 6
3 5 8
5 6 3
5 7 2
6 7 6
Output: 29
*/


/* Sample Input
4 5
0 1 10
0 2 6
0 3 5
1 3 15
2 3 14
 Output: 21
*/


#include <bits/stdc++.h>
using namespace std;

struct node{
    int u;
    int cost;
};

typedef pair <int,int> PII; //destination and cost
vector<PII> v[100];
int vertex,edges;
priority_queue<node> pq;
int cost[100];
bool taken[100];


bool operator < (node a,node b)
{
    return a.cost > b.cost;
}


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

int prim(int source)
{
    for(int i=0;i<vertex;i++)
    {
        cost[i]=INT_MAX;
        taken[i]=false;
    }
    cost[source]=0;
    node temp;
    temp.u=source;
    temp.cost=0;
    pq.push(temp);
    int ans=0;
    while(!pq.empty())
    {
        node current=pq.top();
        pq.pop();
        if(taken[current.u])
            continue;
        taken[current.u]=true;
        ans+=current.cost;
        
        for(int i=0;i<v[current.u].size();i++)
        {
            if(taken[v[current.u][i].first])
                continue;
            if(v[current.u][i].second < cost[v[current.u][i].first])
            {
                node temp2;
                temp2.u=v[current.u][i].first;
                temp2.cost=v[current.u][i].second;
                pq.push(temp2);
                cost[v[current.u][i].first]=v[current.u][i].second;
            }
        }
            
    }
    return ans;
}
int main() 
{
    createGraph();
    printGraph();
    cout<<"Mst Cost : "<<prim(0)<<endl;

    return 0;
}
