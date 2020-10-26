#include <iostream>
#include <algorithm>
using namespace std;

int n;
int memo[1000001];

int dp(int num){
    int &v = memo[num];
    int nextV = 1000000;
    if(num == 1){
        v = 0;
        return v;
    }else if(num == 2){
        v = 1;
        return v;
    }else if(num == 3){
        v = 1;
        return v;
    }

    if(v != 0){
        return v;
    }

    if(num % 2 == 0){
        nextV = min(nextV, dp(num/2)+1);
    }
    if(num % 3 == 0){
        nextV = min(nextV, dp(num/3)+1);
    }
    nextV = min(nextV, dp(num-1)+1);

    v = nextV;
    return v;
}

int main() {
    cin>>n;
    cout<<dp(n);
    return 0;
}
