#include <cstdio>

int main() {
    int t, n, sum, cnt;
    int score[1000] = {0,};
    double avg, ans;

    scanf("%d", &t);
    for(int i=0;i<t;++i){
        scanf("%d", &n);
        sum = 0;
        cnt = 0;
        for(int j=0;j<n;++j){
            scanf("%d", &score[j]);
            sum += score[j];
        }
        avg = (double)sum / n;

        for(int j=0;j<n;++j){
            if(score[j] > avg){
                ++cnt;
            }
        }
        ans = (double)cnt / n * 100;

        printf("%.3lf%%\n", ans);
    }

    return 0;
}
