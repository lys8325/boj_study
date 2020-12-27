#include <iostream>
using namespace std;

int main() {
    int m, n, min, sum = 0;
    bool isPrime[10001];

    cin>>m>>n;
    for(int i=2;i<=n;++i){
        isPrime[i] = true;
    }

    for(int i=2;i*i<=n;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }

    min = n+1;
    for(int i=m;i<=n;++i){
        if(isPrime[i]){
            if(i < min){
                min = i;
            }
            sum += i;
        }
    }
    if(min == n+1){
        cout<<-1;
    }else{
        cout<<sum<<"\n"<<min;
    }
    return 0;
}
