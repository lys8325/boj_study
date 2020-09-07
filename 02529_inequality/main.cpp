#include <iostream>

#define maxK 9
using namespace std;

int k;
char inequalitySign[maxK+1];
bool usedNum[10] = {false};
bool printCheck = false;

int findMax(int target[], int cipher, int index){
    if(cipher == k+1){
        for(int i=0;i<k+1;++i){
            cout<<target[i];
        }
        cout<<endl;
        printCheck = true;
        return 0;
    }

    for(int i=9;i>-1;--i){
        if(printCheck) break;
        if(!usedNum[i]){
            if(index != 0){
                if(inequalitySign[index-1] == '<'){
                    if(target[index-1] < i){
                        usedNum[i] = true;
                        target[index] = i;
                        findMax(target,cipher+1,index+1);
                    }
                }else{
                    if(target[index-1] > i){
                        usedNum[i] = true;
                        target[index] = i;
                        findMax(target,cipher+1,index+1);
                    }
                }
            } else{
                usedNum[i] = true;
                target[index] = i;
                findMax(target,cipher+1,index+1);
            }
            usedNum[i] = false;
        }else{
            continue;
        }
    }
    return 0;
}

int findMin(int target[], int cipher, int index){
    if(cipher == k+1){
        for(int i=0;i<k+1;++i){
            cout<<target[i];
        }
        cout<<endl;
        printCheck = true;
        return 0;
    }

    for(int i=0;i<10;++i){
        if(printCheck) break;
        if(!usedNum[i]){
            if(index != 0){
                if(inequalitySign[index-1] == '<'){
                    if(target[index-1] < i){
                        usedNum[i] = true;
                        target[index] = i;
                        findMin(target,cipher+1,index+1);
                    }
                }else{
                    if(target[index-1] > i){
                        usedNum[i] = true;
                        target[index] = i;
                        findMin(target,cipher+1,index+1);
                    }
                }
            } else{
                usedNum[i] = true;
                target[index] = i;
                findMin(target,cipher+1,index+1);
            }
            usedNum[i] = false;
        }else{
            continue;
        }
    }
    return 0;
}

int main() {
    cin>>k;
    int target[k+1];
    for(int i=0;i<k;++i){
        cin>>inequalitySign[i];
    }

    findMax(target,0,0);
    printCheck =false;
    for(int i=0;i<10;++i){
        usedNum[i]=false;
    }
    findMin(target,0,0);

    return 0;
}