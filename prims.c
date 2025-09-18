#include <stdio.h>
#define I 32767

int t[2][4];
int near[6] = {I, I, I, I, I, I};
int cost[6][6] = {
    {I, I, I, I, I, I},       
    {I, I, 2, I, 6, I},       
    {I, 2, I, 3, 8, 5},       
    {I, I, 3, I, I, 7},       
    {I, 6, 8, I, I, 9},       
    {I, I, 5, 7, 9, I}        
};

int main() {
    int i, j, k, u, v, min = I, n = 5, s = 0;

    // Step 1: Find minimum edge
    for (i = 1; i <= n; i++) {
        for (j = i; j <= n; j++) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    // Step 2: Initialize near array
    for (i = 1; i <= n; i++) {
        if (near[i] != 0) {
            if (cost[i][u] < cost[i][v])
                near[i] = u;
            else
                near[i] = v;
        }
    }

    // Step 3: Construct MST
    for (i = 1; i < n - 1; i++) {
        min = I;
        for (j = 1; j <= n; j++) {
            if ((near[j] != 0) && (cost[j][near[j]] < min)) {
                k = j;
                min = cost[j][near[j]];
            }
        }

        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for (j = 1; j <= n; j++) {
            if ((near[j] != 0) && (cost[j][k] < cost[j][near[j]])) {
                near[j] = k;
            }
        }
    }

    // Step 4: Print MST and total cost
    for (i = 0; i < n - 1; i++) {
        u = t[0][i];
        v = t[1][i];
        printf("Edge: (%d,%d)  Weight = %d\n", u, v, cost[u][v]);
        s += cost[u][v];
    }
    printf("Minimum cost: %d\n", s);

    return 0;
}
