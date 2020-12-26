#include <iostream>
using namespace std;

int main() {
    int n, num, ans = 0;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        if(num == 1){
            continue;
        }

        for(int j=2;j<=num;++j){
            if(num % j == 0){
                if(num == j){
                    ++ans;
                }
                break;
            }
        }
    }

    cout<<ans;
    return 0;
}
