#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, maxNum = 0, cnt = 0;
    bool isPrime[250000];
    vector<int> v;
    while(1){
        cin>>n;
        if(n == 0){
            break;
        }else{
            if(maxNum < n){
                maxNum = n;
            }
            v.push_back(n);
        }
    }

    maxNum *= 2;
    for(int i=2;i<=maxNum;++i){
        isPrime[i] = true;
    }

    for(int i=2;i*i<=maxNum;++i){
        if(isPrime[i]){
            for(int j=i*i;j<=maxNum;j+=i){
                isPrime[j] = false;
            }
        }
    }

    for(int i : v){
        cnt = 0;
        for(int j=i+1;j<=2*i;++j){
            if(isPrime[j]){
                ++cnt;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
