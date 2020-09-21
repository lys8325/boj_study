#include <cstdio>
using namespace std;

int n;
long long b;
int arr[5][5];
int temp[5][5];
int result[5][5];

void multi(int mat1[][5], int mat2[][5]){
    int tmp;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            tmp = 0;
            for(int k=0;k<n;++k){
                tmp += mat1[i][k] * mat2[k][j];
            }
            temp[i][j] = tmp % 1000;
        }

    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            mat1[i][j] = temp[i][j];
        }
    }

}

int main() {
    scanf("%d %lld", &n, &b);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            scanf("%d", &arr[i][j]);
            if(i == j){
                result[i][j] = 1;
            }
        }
    }

    while(b > 0){
        if(b % 2 == 1){
            multi(result, arr);
        }
        b /= 2;
        multi(arr, arr);
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
