#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int num[1000];
    int memo[1000];
    int n, ans=1;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num[i];
    }

    for(int i=0;i<n;++i){
        memo[i] = 1;
        for(int j=0;j<i;++j){
            if(num[j] < num[i]){
                memo[i] = max(memo[i], memo[j]+1);
            }
        }
        ans = max(ans, memo[i]);
    }

    cout<<ans;

    return 0;
}
