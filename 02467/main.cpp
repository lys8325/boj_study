#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b){
    return abs(a) < abs(b);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, num1, num2, num, tmpSum, absSum = 2000000001;
    vector<int> v;

    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end(), cmp);


    for(int i=1;i<n;++i){
        tmpSum = abs(v[i] + v[i-1]);
        if(absSum > tmpSum){
            absSum = tmpSum;
            if(v[i] < v[i-1]){
                num1 = v[i];
                num2 = v[i-1];
            }else{
                num1 = v[i-1];
                num2 = v[i];
            }
        }
        if(tmpSum == 0){
            break;
        }
    }

    cout<<num1<<" "<<num2;
    return 0;
}
