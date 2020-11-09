#include <iostream>
using namespace std;

int numSet[1000001];

int findNum(int num){
    if(num == numSet[num]){
        return num;
    }else{
        return numSet[num] = findNum(numSet[num]);
    }
}

void unionNum(int num1, int num2){
    int root1 = findNum(num1);
    int root2 = findNum(num2);

    if(root1 < root2){
        numSet[root2] = root1;
    }else{
        numSet[root1] = root2;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, op, num1, num2, root1, root2;

    cin>>n>>m;
    for(int i=0;i<=n;++i){
        numSet[i] = i;
    }

    for(int i=0;i<m;++i){
        cin>>op>>num1>>num2;

        if(op == 0){
            unionNum(num1, num2);
        }else{
            root1 = findNum(num1);
            root2 = findNum(num2);

            if(root1 == root2){
                cout<<"YES\n";
            }else{
                cout<<"NO\n";
            }
        }
    }
    return 0;
}
