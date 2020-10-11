#include <cstdio>
#include <cmath>
using namespace std;

bool arr[2187][2187];

void calc(int k){
    if(k == 0){
        arr[0][0] = true;
        return;
    }
    int idx = (int)pow(3, k);
    int midStart = idx / 3;
    int midEnd = midStart + idx/3;

    calc(k-1);

    for(int i=0;i<idx;++i){
        for(int j=0;j<idx;++j){
            if((midStart <= i && i < midEnd) && (midStart <= j && j < midEnd)){
                continue;
            }
            arr[i][j] = arr[i%(idx/3)][j%(idx/3)];
        }
    }
}

int main() {
    int n, tmp, k = 0;
    scanf("%d", &n);
    tmp = n;

    while(tmp > 1){
        tmp /= 3;
        ++k;
    }

    calc(k);

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(arr[i][j]){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
