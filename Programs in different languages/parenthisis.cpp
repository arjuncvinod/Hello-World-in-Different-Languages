#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string S="{()}\0";
    char* x;
        int j=0;
        for(int i=3;i>=0;i--){
            x[j]=S[i];
            j++;
        }
        cout<<x;
    return 0;
}
