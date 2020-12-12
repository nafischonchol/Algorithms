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

/*
    createSet(),findParent(),join()
    this three function used in Disjoint-set algorithms
*/
#include <bits/stdc++.h>
using namespace std;

int parent[100];
int rankParent[100];


struct edgeStructure
{
    int u;
    int v;
    int w;
};

vector<edgeStructure> v;
//this function set parent and rank
void createSet(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rankParent[i]=0;
    }
}

//for finding parrent
int findParent(int x)
{
    if(parent[x]!=x)
        return parent[x]=findParent(parent[x]);
    else
        return x;
}

//for join
void join (int x,int y)
{
    int px=findParent(x);
    int py=findParent(y);
    if(px==py)
        return;
    if(rankParent[px]<rankParent[py])
        parent[px]=py;
    else if(rankParent[px]>rankParent[py])
        parent[py]=px;
    else
    {
        parent[py]=px;
        rankParent[px]++;
    }
}


//this bool helping,sort function  in kruskal block
bool operator < (edgeStructure lhs,edgeStructure rhs)
{
    return lhs.w < rhs.w;
}

int kruskal(int n)
{
    createSet(n);
    sort(v.begin(),v.end());  //sorted by weight
    
    int sz=v.size();
    int ans=0;
    for(int i=0;i<sz;i++)
    {
        if(findParent(v[i].u)!=findParent(v[i].v))
        {
            join(v[i].u,v[i].v);
            ans+=v[i].w;
        }
    }
    return ans;
}
int main() 
{
    int vertex,edge;
    cin>>vertex>>edge;
    for(int i=0;i<edge;i++)
    {
        edgeStructure e;
        cin>>e.u>>e.v>>e.w;
        v.push_back(e);
        
    }
    
    cout<<"MST Cost : "<<kruskal(vertex)<<endl;
    

    return 0;
}
