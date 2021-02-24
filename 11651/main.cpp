#include <cstdio>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, x, y;

int main() {
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        scanf("%d %d", &x, &y);
        pq.push({y, x});
    }
    for(int i=0;i<n;++i){
        printf("%d %d\n", pq.top().second, pq.top().first);
        pq.pop();
    }
    return 0;
}