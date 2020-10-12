#include <iostream>
using namespace std;

int calc(int num){
    int rem;
    int res = num;
    while(num > 0){
        rem = num % 10;
        num /= 10;
        res += rem;
    }
    return res;
}

int main() {
    int n;
    cin>>n;

    for(int i=1;i<=1000000;++i){
        if(n == calc(i)){
            cout<<i;
            return 0;
        }
    }

    cout<<0;
    return 0;
}
