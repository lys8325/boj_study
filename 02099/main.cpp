#include <cstdio>

int n, k, m;
int map[201][201];
int direction[201][201];
int temp[201][201];
void multi(int mat1[][201], int mat2[][201]){
    int tmp;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            tmp = 0;
            for(int k=1;k<=n;++k){
                tmp += mat1[i][k] * mat2[k][j];
            }
            temp[i][j] = tmp;
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            mat1[i][j] = temp[i][j];
        }
    }
}

int main(){
    int target1, target2, y, x;

    scanf("%d %d %d", &n, &k, &m);
    for(int i=1;i<=n;++i){
        scanf("%d %d", &target1, &target2);
        map[i][target1] = 1;
        map[i][target2] = 1;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(i == j){
                direction[i][j] = 1;
            }
        }
    }

    while(k > 0){
        if(k % 2 == 1){
            multi(direction, map);
        }
        multi(map, map);
        k /= 2;
    }

    for(int i=0;i<m;++i){
        scanf("%d %d", &y, &x);
        if(direction[y][x]){
            printf("death\n");
        }else{
            printf("life\n");
        }
    }
}

// dfs 이용하여 풀기
//#include <cstdio>
//#include <set>
//using namespace std;
//
//pair<int, int> v[201];
//set<int> answer;
//int n, k, m, start, target;
//
//void dfs(int s, int c){
//    int nextS1, nextS2, vCount;
//    nextS1 = v[s].first;
//    nextS2 = v[s].second;
//    vCount = c + 1;
//
//    if(vCount < k){
//        dfs(nextS1, vCount);
//        dfs(nextS2, vCount);
//    }else if(vCount == k){
//        answer.insert(nextS1);
//        answer.insert(nextS2);
//    }
//}
//
//int main() {
//    int p1, p2;
//
//    scanf("%d %d %d", &n, &k, &m);
//    for(int i=1;i<=n;++i){
//        scanf("%d %d", &p1, &p2);
//        v[i].first = p1;
//        v[i].second = p2;
//    }
//
//    for(int i=0;i<m;++i){
//        scanf("%d %d", &start, &target);
//        dfs(start, 0);
//        if(answer.find(target) != answer.end()){
//            printf("death\n");
//        }else{
//            printf("life\n");
//        }
//        answer.clear();
//    }
//
//    return 0;
//}

// bfs 이용하여 풀기
//#include <cstdio>
//#include <set>
//#include <queue>
//using namespace std;
//queue<pair<int, int>> q;
//int main() {
//    int n, k, m, p1, p2, start, end, nextS1, nextS2, vCount,tmpS, tmpC;
//    pair<int, int> v[201];
//    set<int> answer;
//    scanf("%d %d %d", &n, &k, &m);
//    for(int i=1;i<=n;++i){
//        scanf("%d %d", &p1, &p2);
//        v[i].first = p1;
//        v[i].second = p2;
//    }
//
//    for(int i=0;i<m;++i){
//        scanf("%d %d", &start, &end);
//        q.push({start, 0});
//        while (!q.empty()){
//            tmpS = q.front().first;
//            tmpC = q.front().second;
//            q.pop();
//
//            nextS1 = v[tmpS].first;
//            nextS2 = v[tmpS].second;
//            vCount = tmpC + 1;
//            if(vCount < k){
//                q.push({nextS1, vCount});
//                q.push({nextS2, vCount});
//            }else if(vCount == k){
//                answer.insert(nextS1);
//                answer.insert(nextS2);
//            }
//        }
//        if(answer.find(end) != answer.end()){
//            printf("death\n");
//        }else{
//            printf("life\n");
//        }
//        answer.clear();
//    }
//
//    return 0;
//}