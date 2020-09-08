#include <iostream>
#include <string>
#include <vector>
#define maxStrLen 1000001
#define maxBombLen 37
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
    string str,bomb;
    getline(cin,str);
    getline(cin,bomb);

    vector<int> table = makeTable(bomb);
    vector<int> matchIndex;
    int bombLen = bomb.size();
    bool match = true;
    string temp = str;
    while(match){
        str = temp;
        match  = false;
        matchIndex.clear();
        int strLen = str.size();
        int j = 0;
        for(int i=0;i<strLen;++i){
            while(j > 0 && str[i] != bomb[j]){
                j = table[j-1];
            }
            if(str[i] == bomb[j]){
                if(j == bombLen -1){
                    //matchIndex.push_back(i-bombLen+1);
                    temp.erase(i-bombLen+1,bombLen);
                    j = table[j]-bombLen;
                    match = true;
                }else{
                    ++j;
                }
            }
        }
//        if(matchIndex.empty()){
//            if(str.empty()){
//                cout<<"FRULA";
//            }else{
//                cout<<str;
//            }
//            break;
//        }else{
//            int m = matchIndex.size();
//            for(int i=0;i<m;++i){
//                str.erase(matchIndex[i]-(i*bombLen),bombLen);
//            }
//        }
    }
    str = temp;
    if(str.empty()){
        cout<<"FRULA";
    }else{
        cout<<str;
    }
    return 0;
}
