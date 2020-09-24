#include <cstdio>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, x, y;

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d %d", &x, &y);
        pq.push({x, y});
    }
    for(int i=0;i<n;++i){
        printf("%d %d\n", pq.top().first, pq.top().second);
        pq.pop();
    }
    return 0;
}
