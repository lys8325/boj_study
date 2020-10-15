#include <iostream>
#include <algorithm>
using namespace std;

int n, maxAns = -1000000001, minAns = 1000000001;
int num[11];
int op[4];

void dfs(int cnt, int res){
    if(cnt == n){
        maxAns = max(maxAns, res);
        minAns = min(minAns, res);
        return;
    }

    int next;
    for(int i=0;i<4;++i){
        if(op[i] > 0){
            switch (i) {
                case 0:
                    next = res + num[cnt];
                    break;
                case 1:
                    next = res - num[cnt];
                    break;
                case 2:
                    next = res * num[cnt];
                    break;
                default:
                    next = res / num[cnt];
                    break;
            }
            --op[i];
            dfs(cnt+1, next);
            ++op[i];
        }
    }
}

int main() {
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>num[i];
    }
    for(int i=0;i<4;++i){
        cin>>op[i];
    }

    dfs(1,num[0]);
    cout<<maxAns<<"\n"<<minAns;
    return 0;
}
