#include <cstdio>
#include <utility>
using namespace std;
int selection_sort(int a[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        int min = i;
        for(int j = i; j < n; j++) {
            if(a[j] < a[min]) min = j;
        }
        swap(a[i], a[min]);
        if(i != min) count++;
    }
    return count;
}
int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int count = selection_sort(a, n);
    for(int i = 0; i < n; i++) {
        if(i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n%d\n", count);
}