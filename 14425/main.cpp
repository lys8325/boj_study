#include <cstdio>
using namespace std;

struct trie{
    bool term;
    trie *next[26];

    trie(){
        term = false;
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
            term = true;
        }else{
            int tmp = *str - 'a';

            if(!next[tmp]){
                next[tmp] = new trie();
            }
            next[tmp]->insert(str+1);
        }
    }

    bool find(char *str){
        if(*str == '\0'){
            if(term){
                return true;
            }else{
                return false;
            }
        }else{
            int tmp = *str - 'a';
            if(!next[tmp]){
                return false;
            }else{
                return next[tmp]->find(str+1);
            }
        }
    }
};
int main() {
    trie *root = new trie();
    int n, m, ans = 0;
    char str[501];

    scanf("%d %d", &n, &m);
    for(int i=0;i<n;++i){
        scanf("%s", str);
        root->insert(str);
    }

    for(int i=0;i<m;++i){
        scanf("%s", str);
        if(root->find(str)){
            ++ans;
        }
    }

    printf("%d", ans);
    return 0;
}
