#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

string a("a"), b("b"), tmp;
int aLen, bLen;
int mat[1001][1001];

int lcs(int i, int j){
    int &v = mat[i][j];
    if(i == 0 || j == 0){
        v = 0;
        return v;
    }

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
    cin>>tmp;
    a.append(tmp);
    cin>>tmp;
    b.append(tmp);

    aLen = a.length()-1;
    bLen = b.length()-1;

    memset(mat,-1,1001*1001*4);
    cout<<lcs(aLen, bLen)<<"\n";

    return 0;
}
