#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, minSum = 2000000000, tmpSum, ans1, ans2;
    cin>>n;

    int num[n];

    for(int i=0;i<n;++i){
        cin>>num[i];
    }
    sort(num, num+n);

    int l=0, r=n-1;
    while(l < r){
        tmpSum = num[l] + num[r];
        if(abs(tmpSum) < minSum){
            minSum = abs(tmpSum);

            ans1 = num[l];
            ans2 = num[r];
        }

        if(tmpSum > 0){
            --r;
        }else if(tmpSum < 0){
            ++l;
        }else{
            break;
        }
    }

    cout<<ans1<<" "<<ans2;
    return 0;
}
