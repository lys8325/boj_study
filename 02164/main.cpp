#include <cstdio>
#include <queue>
using namespace std;

int main() {
    int n, tmp;
    queue<int> q;
    scanf("%d", &n);

    for(int i=1;i<=n;++i){
        q.push(i);
    }

    while(q.size() != 1){
        q.pop();
        tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    printf("%d\n", q.front());
    return 0;
}
