#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string a, b;
int aLen, bLen;
int mat[1000][1000];

int lcs(int i, int j){
    if(i < 0 || j < 0){
        return 0;
    }

    int &v = mat[i][j];
    if(v != -1){
        return v;
    }

    if(a[i] == b[j]){
        v = lcs(i-1, j-1) + 1;
    }else{
        v = max(lcs(i-1,j), lcs(i,j-1));
    }

    return v;
}

int main() {
    cin>>a>>b;

    aLen = a.length();
    bLen = b.length();

    memset(mat,-1,1000*1000*4);
    cout<<lcs(aLen-1, bLen-1)<<"\n";

    return 0;
}
