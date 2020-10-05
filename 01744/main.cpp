#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, tmp1, tmp2, idx, nagCnt = 0, posCnt = 0;
    long long ans=0;
    vector<int> v;
    scanf("%d", &n);
    if(n == 0){
        printf("%d", ans);
        return 0;
    }
    for(int i=0;i<n;++i){
        scanf("%d", &tmp1);
        if(tmp1 < 0){
            ++nagCnt;
        }else if(tmp1 > 0){
            ++posCnt;
        }
        v.push_back(tmp1);
    }
    sort(v.begin(), v.end());
    --nagCnt;
    for(idx=0;idx<nagCnt;++idx) {
        ans += (v[idx] * v[++idx]);
    }

    if(v[idx] < 0){
        if(idx == n-1 || v[idx+1] > 0){
            ans += v[idx];
        }
    }

    while(posCnt  > 1){
        tmp1 = v[--n];
        tmp2 = v[--n];

        if(tmp1 + tmp2 < tmp1 * tmp2){
            ans += (tmp1 * tmp2);
        }else{
            ans += (tmp1 + tmp2);
        }
        posCnt -= 2;
    }

    if(posCnt == 1){
        ans += v[n-1];
    }

    printf("%d", ans);
    return 0;
}