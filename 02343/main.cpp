#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n,m, blue = 0, idx = 0, maxL = 0;
    long long left = 0, right = 0, mid, tmp, total = 0;
    int lesson[100000]={0,};
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%d", &lesson[i]);
        total += lesson[i];
        maxL = (maxL, lesson[i]);
    }

    left = maxL-1; right = total;
    while(left <= right){
        mid = (left+right) / 2;
        tmp = 0; blue = 0;

        for(int i=0;i<n;++i){
            if(tmp + lesson[i] > mid){
                ++blue;
                tmp = 0;
            }
            tmp += lesson[i];
        }

        if(tmp != 0){
            ++blue;
        }

        if(blue <= m){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    printf("%d", left);
    return 0;
}

