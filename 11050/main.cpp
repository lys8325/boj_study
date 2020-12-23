#include <iostream>
using namespace std;

int memo[11][11];

int calc(int a, int b){
    if(b == 1){
        return a;
    }

    return calc(a-1, b) + calc(a-1, b-1);
}

int main() {
    int n, k;

    cin>>n>>k;
    cout<<calc(n, k);
    return 0;
}
