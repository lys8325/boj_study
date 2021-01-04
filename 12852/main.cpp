#include <iostream>
#include <memory.h>
using namespace std;

int memo[1000001];
int path[1000001];

int dp(int num){
    int &v = memo[num];
    if(num == 1){
        v = 0;
        path[num] = num;
        return 0;
    }

    if(v != -1){
        return v;
    }

    v = dp(num-1) + 1;
    path[num] = num - 1;
    if(num % 2 == 0){
        if(v > dp(num/2)+1){
            v = dp(num/2)+1;
            path[num] = num/2;
        }
    }
    if( num % 3 == 0){
        if(v > dp(num/3)+1){
            v = dp(num/3)+1;
            path[num] = num/3;
        }
    }

    return v;
}

int main() {
    int n, cnt;

    cin>>n;
    memset(memo,-1, 1000001*4);

    cnt = dp(n);
    cout<<cnt<<"\n";

    while(n != 1){
        cout<<n<<" ";
        n = path[n];
    }
    cout<<1;

    return 0;
}
