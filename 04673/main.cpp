#include <iostream>
using namespace std;

int d(int n){
    int tmp;
    int res = n;

    while(n > 0){
        tmp = n % 10;
        n /= 10;
        res += tmp;
    }

    return res;
}

int main() {
    bool notSelf[10001] = {false,};
    int idx;

    for(int i=1;i<10001;++i){
        idx = d(i);
        if(idx <= 10000){
            notSelf[idx] = true;
        }
    }

    for(int i=1;i<=10000;++i){
        if(!notSelf[i]){
            cout<<i<<"\n";
        }
    }
    return 0;
}
