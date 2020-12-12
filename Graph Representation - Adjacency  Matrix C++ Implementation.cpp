/* Sample Input:
    5 6
    0 1 1 1 0
    1 0 0 0 1
    1 0 0 0 1
    1 0 0 0 1
    0 1 1 1 0 */

/*Smaple Output:
    0----1 2 3 
    1----0 4 
    2----0 4 
    3----0 4 
    4----1 2 3 

*/



#include <bits/stdc++.h>
using namespace std;

int vertex,edges;

void printGraph(int a[][100])
{
    for(int i=0;i<vertex;i++)
    {
        cout<<i<<"----"; //source 
        for(int j=0;j<vertex;j++)
        {
           if(a[i][j]==1)
           {
               cout<<j<<" ";
           }
        }
        cout<<endl;
    }
    cout<<endl;
}

void createGraph(int a[][100])
{
    
    
    for(int i=0;i<vertex;i++)
    {
       for(int j=0;j<vertex;j++)
       {
           cin>>a[i][j];
       }
    }
}
int main() 
{
    cin>>vertex>>edges;
    int a[100][100];
    createGraph(a);
    printGraph(a);

    return 0;
}
