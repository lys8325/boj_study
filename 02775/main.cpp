#include <iostream>
using namespace std;

int memo[15][15];

int dp(int h, int w){
    int &v = memo[h][w];
    if(h == 0){
        v = w;
        return v;
    }

    if(v != 0){
        return v;
    }

    for(int i=1;i<=w;++i){
        v += dp(h-1, i);
    }

    return v;
}

int main() {
    int t, k, n;

    cin>>t;
    for(int i=0;i<t;++i){
        cin>>k>>n;
        cout<<dp(k, n)<<"\n";
    }
    return 0;
}
