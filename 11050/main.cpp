#include <iostream>
using namespace std;

int memo[11][11];

int calc(int a, int b){
    int &v = memo[a][b];
    if(b == 1){
        v = a;
    }

    if(a == b){
        v = 1;
    }

    if(v != 0){
        return v;
    }
    v = calc(a-1, b) + calc(a-1, b-1);
    return v;
}

int main() {
    int n, k;

    cin>>n>>k;
    if(k == 0){
        cout<<1;
    }else{
        cout<<calc(n, k);
    }
    return 0;
}
