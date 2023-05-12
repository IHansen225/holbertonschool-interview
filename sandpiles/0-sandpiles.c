#include <stdio.h>

/**
 * _print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void _print_grid(int grid[3][3])
{
	int i, j;

	printf("=\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stabilize_pile - stab
 * @grid: grid
 */
void stabilize_pile(int grid[3][3])
{
	int i, j;
	int out[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	int lim[3][3] = {{-2, -1, -2}, {-1, 0, -1}, {-2, -1, -2}};

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			out[i][j] += grid[i][j];
			if (grid[i][j] <= 3)
				continue;
			out[i][j] += lim[i][j];
			if (i > 0)
				if (grid[i - 1][j] <= 3)
				{
					out[i - 1][j]++;
					out[i][j]--;
				}
			if (i < 2)
				if (grid[i + 1][j] <= 3)
				{
					out[i + 1][j]++;
					out[i][j]--;
				}
			if (j > 0)
				if (grid[i][j - 1] <= 3)
				{
					out[i][j - 1]++;
					out[i][j]--;
				}
			if (j < 2)
				if (grid[i][j + 1] <= 3)
				{
					out[i][j + 1]++;
					out[i][j]--;
				}
		}
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid[i][j] = out[i][j];
}

/**
 * is_sandpile_stable - is sand stable
 * @grid: grid to check
 * Return: int
 */
int is_sandpile_stable(int grid[3][3])
{
	int has_great = 0;
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				has_great = 1;
		}
	return (!has_great);
}

/**
 * sandpiles_sum - sum of sandpiles
 * @grid1: 1
 * @grid2: 2
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	if (is_sandpile_stable(grid1))
		return;
	_print_grid(grid1);
	while (1)
	{
		stabilize_pile(grid1);
		if (is_sandpile_stable(grid1))
			return;
		_print_grid(grid1);
	}
}
