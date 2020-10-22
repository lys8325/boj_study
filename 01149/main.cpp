#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int n;
int rgb[1000][3];
int memo[1000][3];

int dp(int idx, int color){
    int &minV = memo[idx][color];

    if(idx == 0){
        minV = rgb[idx][color];
        return minV;
    }

    if(memo[idx][color] != 0){
        return minV;
    }

    if(color == 0){
        minV = min(dp(idx-1,1), dp(idx-1,2)) + rgb[idx][0];
    }else if(color == 1){
        minV = min(dp(idx-1,0), dp(idx-1,2)) + rgb[idx][1];
    }else{
        minV = min(dp(idx-1,0), dp(idx-1,1)) + rgb[idx][2];
    }

    return minV;
}

int main() {
    int minR, minG, minB, ans;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>rgb[i][0]>>rgb[i][1]>>rgb[i][2];
    }

    minR = dp(n-1,0);
    minG = dp(n-1,1);
    minB = dp(n-1,2);

    ans = min(minR, minG);
    ans = min(ans, minB);
    cout<<ans;

    return 0;
}