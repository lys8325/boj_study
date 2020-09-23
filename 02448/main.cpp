#include <cstdio>
#include <cmath>
using namespace std;

int n, level, totalW, totalH, targetW, targetH;
bool star[6144][6144];
int sY, sX, tY, tX;
void mark(){
    for(int i=0;i<targetH;++i){
        for(int j=0;j<targetW;++j){
            if(star[i+sY][j+sX]){
                star[i+tY][j+tX] = true;
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    n /= 3;
    totalW = 6 * n;
    totalH = 3 * n;
    while(n % 2 == 0){
        ++level;
        n /= 2;
    }

    int startY = 0;
    int startX = totalW/2 -3;
    star[startY][startX+2] = true;
    star[startY+1][startX+1] = true;
    star[startY+1][startX+3] = true;
    star[startY+2][startX] = true;
    star[startY+2][startX+1] = true;
    star[startY+2][startX+2] = true;
    star[startY+2][startX+3] = true;
    star[startY+2][startX+4] = true;

    for(int i=1;i<=level;++i){
        targetH = 3 * (int)(pow(2, i-1));
        targetW = 6 * (int)(pow(2, i-1));
        sY = 0;
        sX = startX - 3 * (int)(pow(2, i-1)-1);
        tY = sY + 3 * (int)(pow(2, i-1));
        tX = sX - 3 * (int)(pow(2, i-1));
        mark();
        tX = sX + 3 * (int)(pow(2, i-1));
        mark();
    }

    for(int i=0;i<totalH;++i){
        for(int j=0;j<totalW;++j){
            if(star[i][j]){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
