#include <iostream>
#include <algorithm>
using namespace std;

bool cmp_greater(int a, int b){
    return a < b;
}

bool cmp_les(int a, int b){
    return a > b;
}

int main() {
    int n, sum = 0;
    cin>>n;

    int a[n], b[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a, a+n, cmp_les);

    for(int i=0;i<n;++i){
        cin>>b[i];
    }
    sort(b, b+n, cmp_greater);

    for(int i=0;i<n;++i){
        sum += a[i] * b[i];
    }

    cout<<sum;
    return 0;
}
