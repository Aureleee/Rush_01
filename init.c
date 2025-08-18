#include <stdio.h>
#include <stdlib.h>

int 	**set_value(int **tab, char *str,int dim)
{
	int i;
	int j;

	i = 0;
	while (i < dim)
	{
		j = 0;
		while(j < dim)
		{
			tab[i][j] = str[i * dim + j] - '0';
			j++;
		}
		i++;
	}
	return (tab);
}

void	print_tab(int **tab, int dim)
{
	int i;
	int j;


	i = 0;
	while (i < dim)
	{
		j = 0;
		while (j < dim)
		{
			printf("[%d] ", tab[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
    printf("_________________\n");
}

int **init_tab(int dim)
{
	int i;
	int j;
	int **ptr = NULL;

	ptr = (int **)malloc(sizeof(int *) * (dim + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < dim)
	{
		ptr[i] = (int *)malloc(sizeof(int) * dim + 1) ;
		if (!ptr)
			return (NULL);
		j = 0;
		while (j < dim)
		{
			ptr[i][j] = 0;
			j++;
		}
		ptr[i][j] = '\0';
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
