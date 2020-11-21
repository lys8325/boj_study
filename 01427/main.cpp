#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main() {
    vector<int> v;
    int num;

    cin>>num;

    while(num > 0){
        v.push_back(num % 10);
        num /= 10;
    }

    sort(v.begin(), v.end(), cmp);

    for(auto i : v){
        cout<<i;
    }
    return 0;
}
