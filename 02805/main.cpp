#include <iostream>
#define MAX 1000001
using namespace std;

int tree[MAX];
int s, e;

int main(){

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &tree[i]);
        if(tree[i]>e) e=tree[i];
    }

    while(e>s){
        int mid=(s+e)/2;
        long long sum=0;
        for(int i=0; i<n; i++){
            int temp=tree[i]-mid;
            sum+=temp>0?temp:0;
        }


        if(sum>=m){
            s=mid+1;
        } else {
            e=mid;
        }


    }

    printf("%d", e-1);
    return 0;
}