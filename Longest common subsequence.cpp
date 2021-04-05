#include <bits/stdc++.h>
using namespace std;

int c[1000][1000];
string getSubsequence(string s1,string s2)
{
    int size1=s1.size();
    int size2=s2.size();
    string result="";
    for(int i=size1;i>0;i--)
    {
        for(int j=size2;j>0;j--)
        {
            if(c[i][j]!=c[i][j-1] && c[i][j]!=c[i-1][j])
            {
                result=s1[i-1]+result;
                i--;
                if(i<=0)
                    break;
            }
            else if(c[i][j]==c[i-1][j])
            {
                i--;
                j++;
            }
        }
    }
    return result;
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}
int getLCSLength(string s1,string s2)
{
    s1="0"+s1;
    s2="0"+s2;
    int size1=s1.size();
    int size2=s2.size();
    
    for(int i=0;i<size1;i++)
    {
        for(int j=0;j<size2;j++)
        {
            if(i==0 || j==0)
            {
                c[i][j]=0;
            }
            else if(s1[i]==s2[j])
            {
                c[i][j]=1+c[i-1][j-1];
            }
            else
            {
                c[i][j]=max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    return c[size1-1][size2-1];
}


int main() 
{
    string s1,s2;
    cin>>s1>>s2;
    int getLenght=getLCSLength(s1,s2);
    string getResult=getSubsequence(s1,s2);
    
    cout<<"The lenght of LCS is : "<<getLenght<<endl;
    cout<<"LCS is : "<<getResult<<endl;
    return 0;
}
