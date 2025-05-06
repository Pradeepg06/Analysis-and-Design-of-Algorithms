#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n, int K[n+1][W+1]) {
    int i, w;

    // Fill the DP table
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    // Print the DP table
    printf("\nDP Table (K[i][w]):\n");
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            printf("%4d", K[i][w]);
        }
        printf("\n");
    }

    return K[n][W];
}


void printSelectedItems(int W, int wt[], int K[][W+1], int n) {
    int w = W;
    printf("\nSelected items:\n");

    // Traverse the DP table to find the selected items
    for (int i = n; i > 0 && w > 0; i--) {
        if (K[i][w] != K[i-1][w]) {  // Item i is included
            printf("Item %d (Profite: %d, Weight: %d)\n", i, wt[i-1], wt[i-1]);
            w -= wt[i-1];
        }
    }
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter %d item profits (space-separated):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }

    printf("Enter %d item weights (space-separated):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &W);

    int K[n + 1][W + 1];

    // Get the maximum value that can be achieved
    int result = knapsack(W, wt, val, n, K);
    printf("\nMaximum value/profit in Knapsack = %d\n", result);

    // Print the selected items
    printSelectedItems(W, wt, K, n);

    return 0;
}
