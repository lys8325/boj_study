#include <iostream>

#define maxK 9

using namespace std;

int k;
char inequalitySign[maxK+1];
bool usedNum[10] = {false};
int maxAnswer = 0;
int minAnswer = 100000000;

int findAnswer(){
    int target;
    for(int i=0;i<k;++i){
        for(int j=0;j<10;++j){
            if(!usedNum[j]){
                target = j;
                usedNum[j] = true;
                break;
            }
        }
    }
}

int main() {

    cin>>k;
    for(int i=0;i<k;++i){
        cin>>inequalitySign[i];
    }

    cout<<inequalitySign<<endl;

    return 0;
}
