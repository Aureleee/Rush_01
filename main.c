// for initialisation
int **init_tab(int dim);    
int 	**set_value(int **tab, char *str,int dim);

// for showing
void	print_tab(int **tab, int dim);
#include <stdio.h>


// for solving the puzzle :D
void    ft_evaluate_tab(int **bool_array,int **condition_array, int dim); 
void	ft_evaluate_line(int *line,int index_line, int dim, int *B, int *T);
void    ft_select(int **bool_rows, int dim, int *no_more_loop);
//useful asf
void transpose(int **tab_src, int dim);
void ft_compare_tab(int **bool_rows, int **bool_columns,int **ultimate, int dim, int dim_con);

int main (int argc, char **argv)
{
	int **bool_rows;
	int **bool_columns;
    int **ultimate;

// for testing
    int line1[] = {0, 0, 0, 0, 0};
    int B = 2;
    int T = 1;
    char *empty ="0000000000000000000000000";
    char *six_empty ="000000000000000000000000000000000000";
    char *sevem_empty = "0000000000000000000000000000000000000000000000000";
    char *one_round ="0000900900900000009009000";
    char *empty_condition= "9332219500000130000031000002200000220090039312239";
    char *one_round_cond = "9221109400009020090020900001100090110900029201129";
    char *six_empty_cond = "9152223910000003400000023000000330000001200000022000000493122439";
    char *seven_empty_cond = "912233239100000003300000002200000004200000003300000002400000001300000004932213329";


// end of for testing
	int dim;
    int dim_con;
	dim = 6;
    dim_con = 8;

	bool_rows = init_tab(dim);
	bool_columns = init_tab(dim);
	ultimate = init_tab(dim_con);

	ultimate = set_value(ultimate, six_empty_cond, dim_con);
    bool_rows = set_value(bool_rows, six_empty, dim);
    bool_columns = set_value(bool_columns, six_empty, dim);
// bool_rows and columns are already initialised filed with 0 :P
    print_tab(ultimate, dim_con);
    // transpose(ultimate, dim_con);
    //print_tab(ultimate, dim_con);
    // print_tab(bool_rows, dim);
    // ft_evaluate_tab(bool_rows,ultimate,dim);
    // print_tab(bool_rows, dim);
    printf("bool_columns\\rows init\n");
    print_tab(bool_columns, dim);


    ft_compare_tab(bool_rows,bool_columns,ultimate,dim,dim_con);

    printf("boll_selected\n");
    print_tab(bool_rows, dim);


	return (0);

}