#include <iostream>
using namespace std;

int num[9];
int permutation[9];
bool used[9];
int n;

void getPermutation(int len){
    if(len == n){
        for(int idx=1;idx<=n;++idx){
            cout<<permutation[idx]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int idx=1;idx<=n;++idx){
        if(used[idx]){
            continue;
        }

        used[idx] = true;
        permutation[len+1] = num[idx];
        getPermutation(len+1);
        used[idx] = false;
    }
}

int main() {
    cin>>n;

    for(int idx=1;idx<=n;++idx){
        num[idx] = idx;
    }

    for(int idx=1;idx<=n;++idx){
        used[idx] = true;
        permutation[1] = num[idx];
        getPermutation(1);
        used[idx] = false;
    }

    return 0;
}
