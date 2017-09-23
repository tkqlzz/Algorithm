#include <stdio.h>
#define max(a, b) a > b ? a : b
const int maxSize = 100003;

int main(void) {
    int n;
    scanf("%d", &n);

    int top = 1, res = 0;
    int arr[maxSize];
    int stack[maxSize];

    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);
    arr[0] = 0;
    arr[n+1] = 0;
    stack[1] = 0;

    for(int i=1; i<=n+1; i++) {
        while(top && arr[stack[top]] > arr[i]) {
            int height = arr[stack[top--]];
            int width = i - stack[top] - 1;
            res = max(res, height*width);
        }
        stack[++top] = i;
    }
    printf("%d", res);

    return 0;
}

