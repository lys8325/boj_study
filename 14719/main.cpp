#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int h, w, l, r, lv, rv, maxR, sum = 0;
    cin>>h>>w;

    int block[w];
    for(int i=0;i<w;++i){
        cin>>block[i];
    }

    l = 0; r = l+1;
    while(l < w-1 && r <= w-1){
        lv = block[l];
        rv = block[r];

        if(lv > rv && r < w-1){
            ++r;
        }else if(lv > rv && r == w-1){
            maxR = l+1;
            for(int i=l+1;i<w;++i){
                if(block[i] > block[maxR]){
                    maxR = i;
                }
            }

            for(int i=l+1;i<maxR;++i){
                sum += (block[maxR] - block[i]);
            }

            l = maxR;
            r = l+1;
        }else{
            for(int i=l+1;i<r;++i){
                sum += (lv - block[i]);
            }

            l = r;
            r = l+1;
        }
    }

    cout<<sum;
    return 0;
}
