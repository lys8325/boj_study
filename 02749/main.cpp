#include <iostream>
#include <string.h>
using namespace std;

int fib[1500000] = {0, 1};

int main() {
    long long n;

    cin>>n;
    n %= 1500000;
    for(int i=2;i<=n;++i){
        fib[i] = (fib[i-1] + fib[i-2]) % 1000000;
    }

    cout<<fib[n];
    return 0;
}
