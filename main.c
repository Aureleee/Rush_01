// for initialisation
int **init_tab(int dim);    
int 	**set_value(int **tab, char *str,int dim);

// for showing
void	print_tab(int **tab, int dim);

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
    char *one_round ="0000900900900000009009000";
    char *empty_condition= "9332219500000130000031000002200000220090039312239";
    char *one_round_cond = "9221109400009020090020900001100090110900029201129";


// end of for testing
	int dim;
    int dim_con;
	dim = 5;
    dim_con = 7;

	bool_rows = init_tab(dim);
	bool_columns = init_tab(dim);
	ultimate = init_tab(dim_con);

	ultimate = set_value(ultimate, one_round_cond, dim_con);
    bool_rows = set_value(bool_rows, one_round, dim);
// bool_rows and columns are already initialised filed with 0 :P
    print_tab(ultimate, dim_con);
    // transpose(ultimate, dim_con);
    //print_tab(ultimate, dim_con);
    // print_tab(bool_rows, dim);
    // ft_evaluate_tab(bool_rows,ultimate,dim);
    // print_tab(bool_rows, dim);

    print_tab(bool_rows, dim);

    ft_compare_tab(bool_rows,bool_columns,ultimate,dim,dim_con);
    print_tab(bool_rows, dim);


	return (0);

}