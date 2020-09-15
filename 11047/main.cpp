#include <iostream>
#define maxN 10

using namespace std;

int n,k;
int coin[maxN];
int change,coinCount = 0;

int main() {
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>coin[i];
    }
    change = k;
    coinCount = 0;
    int index = n-1;
    while(change != 0){
        if(change - coin[index] >= 0){
            change -= coin[index];
            ++coinCount;
        }else{
            --index;
        }
    }
    cout<<coinCount;
    return 0;
}
