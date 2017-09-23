#include <stdio.h>
#define MIN(A, B) A<B ? A : B
#define MAX_VALUE 987654321
#define MAX_SIZE 501


int main(void) {
    int d[MAX_SIZE];
    int M[MAX_SIZE][MAX_SIZE];

    int n;
    scanf("%d", &n);
    scanf("%d %d", &d[0], &d[1]);
    int t;
    for(int i=2; i<=n; i++)
        scanf("%d %d", &t, &d[i]);

    for (int diagonal = 0; diagonal < n; diagonal++) {
        for(int i=1; i<=n-diagonal; i++) {
            int j = i + diagonal;
            if (j == i) {
                M[i][j] = 0;
                continue;
            }
            M[i][j] = MAX_VALUE;
            for(int k=i; k<j; k++)
                M[i][j] = MIN(M[i][j], M[i][k] + M[k+1][j] + d[i-1]*d[k]*d[j]);
        }
    }

    printf("%d", M[1][n]);

    return 0;
}

