
#include <bits/stdc++.h>
using namespace std;

int parent[100];
int rankParent[100];

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

//for print the result
void result(int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<"Node is "<<i<<" parent is "<<parent[i]<<" rank is "<<rankParent[i]<<endl;
    }
    cout<<endl;
}
int main() 
{
    int n;
    //here, n=5
    cin>>n;
    createSet(n);
    
    join(0,1);
    join(4,2);
    join(3,1);
    join(0,3);
    
    
    result(n);

    return 0;
}
