#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    int num;
    node *parent;
};
node arr[10001];
bool root[10001];
bool flag;
int t, n, a, b, target1, target2, rootNode, ni, pSize;
vector<int> parents;

int main() {
    node tmp;
    scanf("%d",&t);
    for(int i=0;i<t;++i){
        scanf("%d", &n);
        for(int j=0;j<n-1;++j){
            scanf("%d %d", &a, &b);
            arr[b].num = b;
            arr[b].parent = &arr[a];
            root[b] = true; // 루트가 아님
        }
        scanf("%d %d", &target1, &target2);
        for(int c=1;c<=n;++c){
            if(!root[c]){ // 앞 과정에서 true 를 못 받았으면 루트이다
                arr[c].num = c;
                arr[c].parent = nullptr;
                rootNode = c;
                break;
            }
        }
        // 타겟들중 루트 노드가 있으면 바로 출력
        if(target1 == rootNode || target2 == rootNode){
            printf("%d\n",rootNode);
            for(int d=1;d<=n;++d){
                root[d] = false;
            }
            continue;
        }

        tmp = arr[target1];
        while(tmp.parent != nullptr){ // 한쪽 노드의 조상들을 가까운 순서부터 담는다.
            parents.push_back(tmp.num); // tmp 가 루트노드에 왔을 때에는 담기지 않는다.
            tmp = *tmp.parent;
        }
        parents.push_back(rootNode); // 루트 노드도 담아준다

        tmp = arr[target2];
        pSize = parents.size();
        flag = false;
        while(tmp.parent != nullptr){
            ni=0;
            for(int c=0;c<pSize;++c) {
                if (tmp.num == parents[ni++]) {// parents 를 순서대로 비교해가며 겹치는게 있는 지 탐색
                    printf("%d\n",tmp.num);
                    flag =true;
                    break;
                }
            }
            if(flag){ // 출력했음 탈출
                break;
            }
            tmp = *tmp.parent;
        }
        if(!flag){ // 겹치는게 루트일 때 이다.
            printf("%d\n",rootNode);
        }

        for(int d=1;d<=n;++d){
            root[d] = false;
        }
        parents.clear();
    }

    return 0;
}