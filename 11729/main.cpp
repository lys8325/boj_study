#include <iostream>
#include <cmath>
using namespace std;

int n;
void hanoi(int n,int from, int to, int other){
    if(n == 0){
        return;
    }
    hanoi(n-1,from,other,to);
    cout<<from<<" "<<to<<"\n";
    hanoi(n-1,other,to,from);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;

    cout<<(int)pow(2,n)-1<<"\n";
    hanoi(n,1,3,2);
    return 0;
}