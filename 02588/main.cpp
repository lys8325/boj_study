#include <cstdio>
#include <cmath>
using namespace std;

int main() {
    int a, b, tmp, num, sum = 0, idx = 0;

    scanf("%d %d", &a, &b);
    while(b > 0){
        tmp = b % (int)pow(10, idx+1);
        num = tmp / (int)pow(10, idx);

        printf("%d\n", a*num);
        sum += a * num * (int)pow(10, idx);

        b -= num * (int)pow(10, idx);
        ++idx;
    }

    printf("%d", sum);
    return 0;
}
