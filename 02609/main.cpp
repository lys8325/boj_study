#include <iostream>
using namespace std;

int main() {
    int a, b, tmp, gcd, lcm;

    cin>>a>>b;
    lcm = a * b;


    if(a < b){
        tmp = a;
        a = b;
        b = tmp;
    }

    while(b > 0){
        tmp = b;
        b = a % b;
        a = tmp;
    }

    gcd = a;
    lcm /= gcd;

    cout<<gcd<<"\n";
    cout<<lcm<<"\n";

    return 0;
}
