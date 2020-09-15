#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k,n;
    vector<int> v;
    cin>>k>>n;
    int vSize, num;
    long long  len, minLen, maxLen=0,totalLen=0,target;
    for(int i=0;i<k;++i){
        cin>>len;
        totalLen += len;
        v.push_back(len);
        if(maxLen < len){
            maxLen = len;
        }
    }

    vSize = v.size();
    target = totalLen/n;
    minLen = 1;
    while(minLen <= maxLen){
        num = 0;
        for(int i=0;i<vSize;++i){
            num += v[i] / target;
        }
        if(num >= n){
            minLen = target + 1;
        }else{
            maxLen = target - 1;
        }
        target = (minLen + maxLen) / 2;
    }
    cout<<target;
    return 0;
}