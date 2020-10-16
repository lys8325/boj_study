#include <iostream>
#include <string.h>
using namespace std;

int t, n;
long long len[101];

long long dp(int num){
    if(num == 1){
        len[1] = 1;
        return 1;
    }
    if(num == 2){
        len[2] = 1;
        return 1;
    }
    if(num == 3){
        len[3] = 1;
        return 1;
    }

    if(len[num] > 0){
        return len[num];
    }

    len[num] = dp(num-2) + dp(num-3);
    return len[num];
}

int main() {
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>n;
        memset(len,0,8*(n+1));
        cout<<dp(n)<<"\n";
    }
    return 0;
}
