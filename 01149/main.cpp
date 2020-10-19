#include <iostream>
#include <algorithm>
using namespace std;

int n;
int rgb[1000][3];
int memo[1000][3];

int dp(int idx, int pre){
    int &ret = memo[idx][];
    if(idx == n){
        return v;
    }

    if(memo[idx] != 0){
        return memo[idx];
    }

    for(int i=0;i<3;++i){
        for(i == idx){
            continue;
        }
        
    }
}

int main() {
    int r, g, b;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }
    return 0;
}
