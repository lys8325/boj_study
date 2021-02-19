#include <cstdio>
#include <memory.h>
using namespace std;

int memo[101][101][101];

int w(int a, int b, int c){
    int &v = memo[a+50][b+50][c+50];

    if(v != -1){
        return v;
    }

    if(a <= 0 || b <= 0 || c <= 0){
        v = 1;
    }else if(a > 20 || b > 20 || c > 20){
        v = w(20, 20, 20);
    }else if(a < b && b < c){
        v = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }else{
        v = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }

    return v;
}

int main() {
    memset(memo, -1, 101*101*101*4);
    int a, b, c;

    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a == -1 && b == -1 && c == -1){
            return 0;
        }

        printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }
}
