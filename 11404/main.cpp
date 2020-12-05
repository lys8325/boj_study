#include <iostream>
#include <vector>
#define INF 10000001
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, from, to, w;
    int floyd[101][101];

    cin>>n>>m;

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i == j){
                floyd[i][j] = 0;
            }else{
                floyd[i][j] = INF;
            }
        }
    }

    for(int i=0;i<m;++i){
        cin>>from>>to>>w;
        if(floyd[from][to] < w){
            continue;
        }
        floyd[from][to] = w;
    }

    for(int k=1;k<=n;++k){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(floyd[i][j] > floyd[i][k] + floyd[k][j]){
                    floyd[i][j] = floyd[i][k] + floyd[k][j];
                }
            }
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(floyd[i][j] == INF){
                cout<<0<<" ";
            }else{
                cout<<floyd[i][j]<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}
