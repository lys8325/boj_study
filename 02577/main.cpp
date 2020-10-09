#include <iostream>
using namespace std;

int main() {
    int a, b, c, res, tmp, idx = 1;
    int num[10] = {0,};

    cin>>a>>b>>c;
    res = a*b*c;

    while(res > 0){
        tmp = res % 10;
        ++num[tmp];
        res /= 10;
    }

    for(int i=0;i<10;++i){
        cout<<num[i]<<"\n";
    }
    return 0;
}
