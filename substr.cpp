#include<iostream>
#include<cstring>
using namespace std;
void printSubstrings(char inp[],char out[], int i, int j)
{
    if(inp[i]=='\0')
    {
        out[j] = '\0';
        cout<<out<<"\n";
        return;
    }
    /// INclude
    out[j] = inp[i];
    printSubstrings(inp, out, i+1, j+1);

    /// Exclude
    printSubstrings(inp, out, i+1, j );
}

int pow(int n, int p)
{
    if(p==0)
        return 1;
    int smallpow = pow(n, p/2);
    if(! (p&1) )
        return smallpow * smallpow;
    else
        return n * smallpow * smallpow;
}
void helper(char inp[],int n)
{

    int i = 0;
    int j=0;
    char out[100];


    while(n>0)
    {
        if(n&1)
            out[j++] = inp[i];
        i++;
        n >>= 1;
    }
    cout<<"\n"<<out;
}
void subStrBit(char inp[])
{
    int len = strlen(inp);
    for(int i=0;i<pow(2,len);i++)
    {
        helper(inp, i);
    }
}
int main()
{
char inp[] =  "ABC";
char out[10];

printSubstrings(inp, out,0,0);
//    subStrBit(inp);
return 0;}
