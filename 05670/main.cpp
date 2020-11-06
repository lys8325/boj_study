#include <cstdio>
using namespace std;

struct trie{
    bool term;
    int nextCnt;
    trie *next[26];

    trie(){
        term = false;
        nextCnt = 0;
        for(int i=0;i<26;++i){
            next[i] = NULL;
        }
    }

    ~trie(){
        for(int i=0;i<26;++i){
            delete next[i];
        }
    }

    void insert(char *str){
        if(*str == '\0'){
            ++nextCnt;
            term = true;
        }else{
            int tmp = *str - 'a';

            if(!next[tmp]){
                next[tmp] = new trie();
                ++nextCnt;
            }
            next[tmp]->insert(str+1);
        }
    }

    int find(char *str, int cnt){
        if(*str == '\0'){
            if(term){
                return cnt;
            }else{
                return -1;
            }
        }else{
            int tmp = *str - 'a';
            if(!next[tmp]){
                return -1;
            }else{
                if(nextCnt == 1){
                    return next[tmp]->find(str+1, cnt);
                }
                return next[tmp]->find(str+1, cnt+1);
            }
        }
    }
};

int main() {

    int n;
    float sum, ans;
    char str[100000][81];

    while(scanf("%d", &n) > 0){
        trie *root = new trie();

        sum = 0;
        for(int i=0;i<n;++i){
            scanf("%s", str[i]);
            root->insert(str[i]);
        }

        for(int i=0;i<n;++i){
            sum += root->find(str[i], 0);
        }

        if(root->nextCnt == 1){
            sum += n;
        }
        ans = sum / n;
        printf("%.2f\n", ans);

        delete root;
    }

    return 0;
}
