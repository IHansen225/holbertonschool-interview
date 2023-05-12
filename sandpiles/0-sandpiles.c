#include <stdio.h>

/* Helper function to check if a sandpile is stable */
int is_stable(int grid[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return 0;
            }
        }
    }
    return 1;
}

/* Helper function to topple a cell in the sandpile */
void topple(int grid[3][3], int i, int j) {
    grid[i][j] -= 4;
    if (i > 0) grid[i-1][j]++;
    if (j > 0) grid[i][j-1]++;
    if (i < 2) grid[i+1][j]++;
    if (j < 2) grid[i][j+1]++;
}

/* Function to compute the sum of two sandpiles */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;

    /* Add the two sandpiles together */
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* Topple the unstable cells until the sandpile is stable */
    while (!is_stable(grid1)) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                printf("%d ", grid1[i][j]);
            }
            printf("\n");
        }

        /* Topple the cells that are unstable */
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (grid1[i][j] > 3) {
                    topple(grid1, i, j);
                }
            }
        }
    }
}