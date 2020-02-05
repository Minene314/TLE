#include <cstdio>
using namespace std;
int bubble(int a[], int n) {
    int flag = 1;
    int count = 0;
    for(int i = 0; flag; i++) {
        flag = 0;
        for(int j = n-1; j > i; j--) {
            if(a[j] < a[j-1]) {
                a[j] += a[j-1];
                a[j-1] = a[j] - a[j-1];
                a[j] -= a[j-1];
                count++;
                flag = 1;
            }
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int count = bubble(a, n);
    for(int i = 0; i < n; i++) {
        if(i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d", count);
}