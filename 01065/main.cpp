#include <iostream>
#include <vector>
using namespace std;

bool isNum(int n){
    vector<int> v;
    int tmp, vLen, d;

    while(n > 0){
        tmp = n % 10;
        n /= 10;
        v.push_back(tmp);
    }

    vLen = v.size();
    if(vLen <= 2){
        return true;
    }

    d = v[1] - v[0];
    for(int i=2;i<vLen;++i){
        if(d != v[i] - v[i-1]){
            return false;
        }
    }

    return true;
}

int main() {
    int N, ans = 0;
    cin>>N;

    for(int i=1;i<=N;++i){
        if(isNum(i)){
            ++ans;
        }
    }

    cout<<ans;
    return 0;
}
