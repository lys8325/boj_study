#include <iostream>
using namespace std;

int memo[200001][20];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int m, q, n, x, tmp, idx;
    int binary[21];

    cin>>m;
    for(int i=1;i<=m;++i){
        cin>>memo[i][1];
    }


    for(int j=2;j<=20;++j){
        for(int i=1;i<=m;++i){
            memo[i][j] = memo[memo[i][j-1]][j-1];
        }
    }

    cin>>q;
    for(int i=0;i<q;++i){
        cin>>n>>x;

        tmp = n; idx = 1;
        while(tmp > 0){
            if(tmp % 2 == 1){
                binary[idx++] = 1;
            }else{
                binary[idx++] = 0;
            }
            tmp /= 2;
        }

        for(int j=1;j<idx;++j){
            if(binary[j]){
                x = memo[x][j];
            }
        }

        cout<<x<<"\n";
    }
    return 0;
}
