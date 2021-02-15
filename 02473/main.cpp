#include<cstdio>
#include<algorithm>
using namespace std;
long long arr[5050], ans[3];
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lld", arr+i);
    }
    sort(arr, arr+n);
    long long mini = 3*10e9+10;
    for(int i=0; i<n-2; i++){
        int j, k;
        j = i+1; k = n-1;
        while(1){
            if(j>=k) break;
            long long x = arr[i]+arr[j]+arr[k];
            long long nx = x<0?-x:x;
            if(mini > nx){
                mini = nx;
                ans[0]=arr[i];
                ans[1]=arr[j];
                ans[2]=arr[k];
            }
            if(x>0){
                k--;
            }else{
                j++;
            }
        }
    }
    for(int i=0; i<3; i++){
        printf("%lld ", ans[i]);
    }
    return 0;
}
