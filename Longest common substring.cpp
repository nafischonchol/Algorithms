#include <bits/stdc++.h>
using namespace std;

int c[1000][1000];
string getSubString(string s1,string getResult)
{
    int i=getResult[1]-'0'; //get max value index
    int j=getResult[2]-'0'; //get max value index
    string result="";
    while(c[i][j]!=0)
    {
        result=s1[i-1]+result;
        i--;
        j--;
    }
    return result;
}
string getSubStringLength(string s1,string s2)
{
    s1="0"+s1;
    s2="0"+s2;
    int size1=s1.size();
    int size2=s2.size();
    string position="",result="";
    int max=0;
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
                if(c[i][j]>max)
                {
                    max=c[i][j];
                    position=to_string(i)+to_string(j); //store max index
                }    
            }
            else
            {
                c[i][j]=0;
            }
        }
    }
    result=to_string(max)+position; //store max value and max index
    return result;
}


int main() 
{
    string s1,s2;
    cin>>s1>>s2;
    string getResult=getSubStringLength(s1,s2);
    string getSubStr=getSubString(s1,getResult);
    
    cout<<"The lenght of common substring is : "<<getResult[0]<<endl;  //print max sub string value
    cout<<"Longest Common Substring is : "<<getSubStr<<endl;
    return 0;
}
