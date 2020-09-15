#include <iostream>
#include <cstring>

using namespace std;
int main() {
    int len,t;
    char a[20],b[20];
    cin>>t;
    for(int i=0;i<t;++i){
        cin>>a>>b;
        len = strlen(a);
        cout<<"Distances:";
        for(int j=0;j<len;++j){
            if(a[j] > b[j]){
                cout<<" "<<(b[j] - 64 + 26) - (a[j] - 64 );
            }
            else{
                cout<<" "<<(b[j] - 64) - (a[j] - 64);
            }
        }
        cout<<endl;
    }
    return 0;
}