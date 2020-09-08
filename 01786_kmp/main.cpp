#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeTable(string target){
    int strLen = target.size();
    int j=0;
    vector<int> table(strLen,0);
    for(int i=1;i<strLen;++i){
        while(j > 0 && target[i] != target[j]){ // j 초기값이 0이라 첫 루프에 실행 x
            j = table[j-1];
        }
        if(target[j] == target[i]){
            table[i] = ++j;
        }
    }
    return table;
}

int main() {
    string src,dst;
    getline(cin, src);
    getline(cin, dst);

    vector<int> table = makeTable(dst);
    vector<int> matchIndex;
    int dstLen = dst.size();
    int srcLen = src.size();
    int j = 0;
    for(int i=0; i < srcLen; ++i){
        while(j > 0 && src[i] != dst[j]){
            j = table[j-1];
        }
        if(src[i] == dst[j]){
            if(j == dstLen - 1){
                matchIndex.push_back(i - dstLen + 1);
                j = table[j];
            }else{
                ++j;
            }
        }
    }
    int m = matchIndex.size();
    cout<<m<<endl;
    for(int i=0;i<m;++i){
        cout<<matchIndex[i]+1<<" ";
    }

    return 0;
}
