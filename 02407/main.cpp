#include <cstdio>
#define maxValue 1000000000000000
using namespace std;

long long combi[101][101];
long long carry[101][101];

int main(){
    int n, m;
    long long tmp;

    scanf("%d %d", &n, &m);
    if(m > n/2){
        m = n-m;
    }

    for(int i=1;i<=n;++i){
        for(int j=0;j<=n;++j){
            if(j == 0 || j == i ){
                combi[i][j] = 1;
            }else if(j == 1){
                combi[i][j] = i;
            }else{
                carry[i][j] = carry[i - 1][j] + carry[i - 1][j - 1];
                tmp = combi[i - 1][j] + combi[i - 1][j - 1];
                if(tmp >= maxValue){
                    ++carry[i][j];
                    combi[i][j] = tmp - maxValue;
                }else{
                    combi[i][j] = tmp;
                }
            }
        }
    }

    if(carry[n][m] > 0){
        printf("%lld%015lld", carry[n][m], combi[n][m]);
    }else{
        printf("%lld", combi[n][m]);
    }
    return 0;
}