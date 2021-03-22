#include <iostream>
using namespace std;

int main() {
    int n, tmp, ans = 0;
    cin>>n;

    while(n >= 5){
        tmp = n;
        while(tmp >= 5){
            if(tmp % 5 == 0){
                ++ans;
                tmp /= 5;
            }else{
                break;
            }
        }
        --n;
    }

    cout<<ans;
    return 0;
}
