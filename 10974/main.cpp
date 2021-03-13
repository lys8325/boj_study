#include <iostream>
using namespace std;

int num[9];
int permutation[9];
int combination[9];
bool used[9];
int n, pCnt, cCnt;

void getPermutation(int len){
    if(len == n){
        ++pCnt;
        for(int idx=1;idx<=n;++idx){
            cout<<permutation[idx]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int idx=1;idx<=8;++idx){
        if(used[idx]){
            continue;
        }

        used[idx] = true;
        permutation[len+1] = num[idx];
        getPermutation(len+1);
        used[idx] = false;
    }
}

void getCombination(int pos, int len){
    if(len == n){
        ++cCnt;
        for(int idx=1;idx<=n;++idx){
            cout<<combination[idx]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int idx=pos;idx<=8;++idx){
        combination[len+1] = num[idx];
        getCombination(idx+1, len+1);
    }
}

int main() {
    cin>>n;

    for(int idx=1;idx<=8;++idx){
        num[idx] = idx;
    }

    for(int idx=1;idx<=8;++idx){
        used[idx] = true;
        permutation[1] = num[idx];
        getPermutation(1);
        used[idx] = false;
    }
    cout<<pCnt<<"\n";
    for(int idx=1;idx<=8;++idx){
        combination[1] = num[idx];
        getCombination(idx+1, 1);
    }
    cout<<cCnt<<"\n";
    return 0;
}
