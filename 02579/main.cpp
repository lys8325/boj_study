#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int score[301];
int memo[301][3];

int dp(int num, int cnt){
    int &v = memo[num][cnt];
    if(num == 1){
        v = score[1];
        return v;
    }

    if(num == 2){
        if(cnt == 1){
            v = score[2];
        }else if(cnt == 2){
            v = score[1] + score[2];
        }

        return v;
    }

    if(v != -1){
        return v;
    }

    if(cnt == 1){
        v = max(dp(num-2, 1), dp(num-2, 2)) + score[num];
    }else{
        v = dp(num-1,1) + score[num];
    }

    return v;
}

int main() {
    int n, ans;
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>score[i];
    }

    memset(memo,-1,301*3*4);
    ans = max(dp(n, 1),dp(n, 2));

    cout<<ans;
    return 0;
}
