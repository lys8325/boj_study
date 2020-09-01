#include <iostream>

using namespace std;

int main() {
    int k;
    cin>>k;

    char inequalitySign[k+1];
    for(int i=0;i<k;++i){
        cin>>inequalitySign[i];
    }

    cout<<inequalitySign;
    return 0;
}