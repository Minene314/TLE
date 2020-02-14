#include <cstdio>
#include <vector>
#define rep(i,l,n) for(int i = l; i < (n); i++)
using namespace std;
using ll = long long;
bool binary_search(vector<int> a, int t) {
    int left = 0,right = a.size();
    while(left < right) {
        int m = (right+left)/2;
        if(a.at(m) == t) return true;
        else if(a.at(m) < t) left = m+1;
        else right = m;
    }
    return false;
}
int main() {
    int n,q,t,ans = 0;
    scanf("%d",&n);
    vector<int> s(n);
    rep(i,0,n) scanf("%d",&s[i]);
    scanf("%d",&q);
    rep(i,0,q) {
        scanf("%d",&t);
        if(binary_search(s,t)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}