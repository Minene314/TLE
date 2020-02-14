#include <cstdio>
#include <vector>
#define rep(i,l,n) for(int i = l; i < (n); i++)
using namespace std;
using ll = long long;
int main() {
    int n,q,ans = 0;
    scanf("%d",&n);
    vector<int> s(n);
    rep(i,0,n) scanf("%d",&s[i]);
    scanf("%d",&q);
    int t;
    rep(i,0,q) {
        scanf("%d",&t);
        rep(j,0,n) {
            if(s.at(j) == t) {
                ans++;
                break;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}