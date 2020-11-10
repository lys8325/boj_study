#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c;
    long long tmp, ans = 1;
    cin>>a>>b>>c;

    tmp = a;
    while(b > 0){
        if(b % 2 == 1){
            ans = (ans * tmp) % c;
        }

        b /= 2;
        tmp = (long long)powl(tmp, 2) % c;
    }

    cout<<ans;
    return 0;
}
