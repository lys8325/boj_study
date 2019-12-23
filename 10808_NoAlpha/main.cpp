#include <iostream>
#include <string.h>

using namespace std;
int main() {
    char S[100];
    int mark[26]={0};
    int len,val;

    cin>>S;
    len = strlen(S);
    for(int i=0;i<len;++i){
        val = S[i]-97;
        ++mark[val];
    }

    for(int i=0;i<26;++i){
        cout<<mark[i]<<" ";
    }
    return 0;
}