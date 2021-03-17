#include <iostream>
#include <vector>
using namespace std;

bool visit[10];
vector<int> v(10);
vector<int> combi(10);
vector<int> permu(10);
int cCnt, pCnt;

void getCombi(int n, int cnt, int pos){
    if(n == cnt){
        ++cCnt;
        return ;
    }

    for(int i=pos;i<=9;++i){
        combi[cnt] = v[i];
        getCombi(n, cnt+1, i+1);
    }
}

void getPermu(int n, int cnt){
    if(n == cnt){
        ++pCnt;
        return ;
    }

    for(int i=0;i<=9;++i){
        if(!visit[i]){
            visit[i] = true;
            permu[cnt] = v[i];
            getPermu(n, cnt+1);
            visit[i] = false;
        }
    }
}

int main() {
    int n;

    for(int i=0;i<=9;++i){
        v[i] = i;
    }

    cin>>n;
    getCombi(n, 0, 0);
    cout<<cCnt<<"\n";
    getPermu(n, 0);
    cout<<pCnt<<"\n";

    return 0;
}
