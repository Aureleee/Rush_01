void ft_update_edge(int *line, int dim, int *top_edge, int *bottom_edge);
void    ft_evaluate_line(int *line,int index_line, int dim, int *B, int *T);
void ft_mult_tab(int **bool_rows, int **bool_columns, int dim);
void transpose(int **tab_src, int dim);
void ft_mult_tab(int **bool_rows, int **bool_columns, int dim);
void    ft_evaluate_tab(int **bool_array,int **condition_array, int dim);
void    ft_select(int **bool_rows, int dim, int *no_more_loop);
void	print_tab(int **tab, int dim);
int **init_tab(int dim);    
int 	**set_value(int **tab, char *str,int dim);
void    ft_sub_update(int **THE_ARRAY_OF_INFINITY,int **bool_rows, int dim);
void    ft_update(int **condition,int **ultimate,int **bool_rows, int **bool_columns, int dim, int *tower);
void ft_bool_update(int **bool_rows,int **ultimate , int dim, int *tower);

void    ft_compare_tab(int **bool_rows,  int **bool_columns,int **ultimate, int dim);
#include <stdio.h>


void    ft_skyscraper_puzzle_solver(int dim,char *condition)
{
    int **ultime; 
    int **tab_condition;
    int **bool_rows;
	int **bool_columns;
    int tower;
    char *empty ="0000000000000000000000000";


	bool_rows = init_tab(dim);
	bool_columns = init_tab(dim);
	ultime = init_tab(dim + 2);
    tab_condition = init_tab(dim + 2);

	ultime = set_value(ultime, condition, dim +2);
	tab_condition = set_value(tab_condition, condition, dim +2);

    bool_rows = set_value(bool_rows, empty, dim);
    bool_columns = set_value(bool_columns, empty, dim);

    tower = dim;
    
    printf("ultime intitialisation\n");
    print_tab(ultime, dim +2);
    printf("bool_columns\\rows init\n");
    print_tab(bool_columns, dim);

    //fin d'initialisation -
    while (tower > 3)
    {
        ft_compare_tab(bool_rows,bool_columns,tab_condition,dim);
        //print_tab(bool_rows,dim);
        ft_update(tab_condition, ultime, bool_rows,bool_columns,dim,&tower);
        tower--;
    }
}

int main(void)
{
    char *empty ="0000000000000000000000000";
    char *empty_condition= "9332219500000130000031000002200000220000039312239";
    int dim;
	dim = 5;

    ft_skyscraper_puzzle_solver(dim,empty_condition);
    return (0);
}
        