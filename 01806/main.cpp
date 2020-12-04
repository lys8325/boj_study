#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, s, sum = 0, cnt, ans = 100001, start = 0, end = 0;
    int num[100000];

    cin>>n>>s;

    for(int i=0;i<n;++i){
        cin>>num[i];
    }

    sum = num[0];
    cnt = 1;
    while(end < n){
        if(sum < s){
            sum += num[++end];
            ++cnt;
        }else{
            ans = min(ans, cnt);
            sum -= num[start++];
            --cnt;
        }
    }
    if(ans == 100001){
        cout<<0;
    }else{
        cout<<ans;
    }
    return 0;
}
