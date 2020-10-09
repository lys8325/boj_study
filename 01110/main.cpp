#include <cstdio>

int getFirst(int tmp){
    return tmp / 10;
}

int getSecond(int tmp){
    return tmp % 10;
}

int main() {
    int n, tmp, next, cnt = 0;
    scanf("%d", &n);

    next = n;
    while(true){
        tmp = getFirst(next) + getSecond(next);
        ++cnt;
        next = getSecond(next)*10 + getSecond(tmp);

        if(next == n){
            break;
        }
    }

    printf("%d", cnt);
    return 0;
}
