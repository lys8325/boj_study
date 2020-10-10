#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int cnt[26] = {0,};
    int strLen, idx, maxCnt = -1, isUnq = 0;
    string str;
    cin>>str;

    transform(str.begin(),str.end(),str.begin(),::toupper);
    strLen = str.length();

    for(int i=0;i<strLen;++i){
        idx = str[i] - 65;
        ++cnt[idx];
        maxCnt = max(maxCnt, cnt[idx]);
    }

    for(int i=0;i<26;++i){
        if(maxCnt == cnt[i]){
            ++isUnq;
            idx = i;
        }
    }

    if(isUnq == 1){
        cout<<(char)(idx + 65);
    }else{
        cout<<"?";
    }

    return 0;
}
