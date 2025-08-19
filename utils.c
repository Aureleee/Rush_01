#include <stdio.h>

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
void    ft_compare_tab(int **bool_rows,  int **bool_columns,int **ultimate, int dim);
void    ft_sub_update(int **THE_ARRAY_OF_INFINITY,int **ultimate,int **bool_rows, int dim, int *tower);
void    ft_update(int **condition,int **ultimate,int **bool_rows, int **bool_columns, int dim, int *tower);
void ft_bool_update(int **bool_rows,int **ultimate, int dim, int *tower);

// void ALORS_PEUT_ETRE(int **ultimate ,int **THE_ARRAY_OF_INFINITY, char *empty_condition,int dim)
// {


//     dim_con = dim + 2;
// 	bool_rows = init_tab(dim);
// 	bool_columns = init_tab(dim);

//     ultimate = set_value(ultimate, empty, dim_con); // in this  we will change the condition
//     THE_ARRAY_OF_INFINITY = set_value(ultimate, empty, dim_con); //array to store the final values 
//     bool_rows = set_value(bool_rows, empty, dim);
//     bool_columns = set_value(bool_columns, empty, dim);

//     while(tower > 0)
//     {
//         ft_compare_tab(bool_rows,bool_columns,ultimate,dim,dim_con);
//         ft_update(ultimate,bool_rows,dim,tower);

//         print_tab(THE_ARRAY_OF_INFINITY, dim + 2);

//         tower--;
//     }

void    ft_cpy(int **destination,int **source, int dim)
{
    int i;
    int j;

    i = 0;
    while (i < dim)
    {
        j = 0;
        while (j < dim)
        {
            destination[i][j] = source[i][j];
            j++;
        }
        i++;
    }
}

// }
void ft_bool_update(int **bool_rows,int **ultimate, int dim, int *tower)
{
    int i;
    int j;

    i = 0;
    while (i < dim)
    {
        j = 0;
        while (j < dim)
        {
            if (bool_rows[i][j] == 1)
            {
                bool_rows[i][j] =9;
                ultimate[i+1][j + 1] = *tower;
            }         
            j++;
        }
        i++;
    }
}



void    ft_update(int **condition,int **ultimate,int **bool_rows, int **bool_columns, int dim, int *tower)
{
    int rows;
    int columns;

    rows = 1;
    columns = 1;
    if(*tower == dim)
        {
            while ( rows < dim + 1 )
                {
                    condition[rows][0]--;
                    condition[rows][dim + 1]--;
                    rows++;
                }
            while ( columns < dim + 1 )
                {
                    condition[0][columns]--;
                    condition[dim +1][columns]--;
                    columns++;
                }
            ft_bool_update(bool_rows,ultimate,dim,tower); // Actualise ultine et reset bool_row
            //ft_bool_update(bool_columns,ultimate,dim,tower);
            ft_cpy(bool_columns,bool_rows,dim);
            printf("First round\n");

            print_tab(ultimate, dim +2);
            //print_tab(bool_rows, dim);

            printf("First round -- condition\n");
            print_tab(condition, dim +2);


        }
    else
    {
        ft_sub_update(condition,ultimate,bool_rows ,dim,tower);//Update condition depending on boll_row
        transpose(condition, dim +2); //prepare THE ARRAY for bool_columns
        transpose(bool_rows, dim);// 
        ft_sub_update(condition,ultimate,bool_columns, dim,tower);
        transpose(condition, dim +2);
        transpose(bool_rows, dim);

        ft_bool_update(bool_rows,ultimate,dim,tower); // Actualise ultine et reset bool_row
        printf("bool -- tower = %d\n", *tower);
        print_tab(bool_rows, dim );

        printf("ultimate -- tower = %d\n", *tower);
        print_tab(ultimate, dim +2);



        printf("condition\n");

        print_tab(condition, dim +2);
    }
    

}
void    ft_sub_update(int **THE_ARRAY_OF_INFINITY,int **ultimate,int **bool_rows, int dim, int *tower)
{
    int rows;
    int columns;
    int side;

    side = 1;
    rows = 0;
    while(rows < dim)
    {
        columns = 0;
        int touched = 0;
        side = 1;
        while (columns < dim)
        {
            if(bool_rows[rows][columns] == 1 && side == 1)
                {side = 0;  // bottom side
                touched = 1;}
            if(bool_rows[rows][columns] == 9 && side == 1)
                {side = dim + 1; // top side
                touched = 1;} 
            if(bool_rows[rows][columns] == 1)
                {bool_rows[rows][columns] = 9;
                ultimate[rows][columns] = *tower;}
            columns++;
        }
        if(touched)
            THE_ARRAY_OF_INFINITY[rows +1][side]--;
        rows++;
    }
}



// void    ft_skyscraper_puzzle_solver(int dim,char *condition)
// {
//     int **ultime; 
//     int **tab_condition;
//     int **bool_rows;
// 	int **bool_columns;
//     int tower;

// 	bool_rows = init_tab(dim);
// 	bool_columns = init_tab(dim);
// 	ultime = init_tab(dim + 2);
//     tab_condition = init_tab(dim + 2);
//     tower = dim;
    
//     printf("ultime intitialisation\n");
//     print_tab(ultime, dim +2);
//     printf("bool_columns\\rows init\n");
//     print_tab(bool_columns, dim);

// //fin d'initialisation -


// }





//selectionne les lignes qui ne contiennent qu'un seul 1, et efface les 1 sur les colonnes respectives
// IMportant pour reduire le nombre de possibiblity
// But you need to transpose and do the same for the columns
void    ft_select(int **bool_rows, int dim, int *no_more_loop)
{
    int rows;
    int columns;
    int count;
    int pos;
    int row_sub;

    count = 0;
    rows = 0;
    while (rows < dim)
    {
        columns = 0;
        count = 0;
        
        while (columns < dim)
        {
            if (bool_rows[rows][columns] == 1)
            {   count++;
                pos = columns;
            }
            columns++;
        }
        if (count == 1)
        {
            // printf("rows = %d ",rows );
            // printf("columns = %d\n",pos );

            row_sub = 0;
            while (row_sub < dim)
            {
                if (row_sub != rows && bool_rows[row_sub][pos] != 9)
                {
                    bool_rows[row_sub][pos] = 0;
                }
                row_sub++;

            }
        if (count != 1)
            *no_more_loop = 1;
        }
        rows++;
    }
}


// This functions: as bool_rows and bools_columns as input ONLY composed with either 0 for empty or 
// 9 for full. and the array ultimate with the condition on the sides. 
// it output is in the bool_rows. With only ones (the place to play) in each line, and zero for the other
// and 9 for the full. (full = there's already a tower here)
// 
void    ft_compare_tab(int **bool_rows,  int **bool_columns,int **ultimate, int dim)
{
    int no_more_loop;
    int count_transpo;

    no_more_loop = 1;
    count_transpo = 0;

    ft_evaluate_tab(bool_rows,ultimate,dim); // This function evaluate the rows. (with the condition in ultimate)
    //print_tab(bool_rows, dim);


    transpose(ultimate, dim + 2); // then we transpose utimate...
    transpose(bool_columns, dim);
    ft_evaluate_tab(bool_columns,ultimate,dim); // ...to evaluate the columns

    transpose(ultimate, dim + 2); //transpose back again ultimate

    transpose(bool_columns, dim);// same for bool_columns (so we can multiply terms by terms)
    //print_tab(bool_columns, dim);
    // printf("bool_columns evaluation\n");



    ft_mult_tab(bool_rows,bool_columns,dim);// mutiplication



    int i = 0;
    // count number of possibility on each row and if only one, erase the corresponding columns.
    //We need to made a loop here, because it might be require to select multiple time before having 
    // a clear array :)
    while (i < 8)
    {
        no_more_loop = 0;
        ft_select(bool_rows, dim,&no_more_loop);
        transpose(bool_rows,dim);  // l'idee derriere la transposition c'est de select une fois sur 
        //deux sur les colonnes et les lignes :)
        i++;
    }
    //if(count_transpo % 2)
     //   transpose(bool_rows,dim);
    // il faut bien la remettre a l'endroit hahah
    printf("evaluation\n");

    print_tab(bool_rows, dim);
}


void ft_mult_tab(int **bool_rows, int **bool_columns, int dim)
{
    int i;
    int j;

    i = 0;
    while (i < dim)
    {
        j = 0;
        while (j < dim)
        {
            bool_rows[i][j] *= bool_columns[i][j];
            if (bool_rows[i][j] == 81)
                bool_rows[i][j] = 9;
            j++;
        }
        i++;
    }
}




void    ft_evaluate_tab(int **bool_array,int **condition_array, int dim)  // dim of condition_array = dim + 2 
{
    int index;
    int B;
    int T;
    
    index = 0;
    while (index < dim)
    {
        B = condition_array[index + 1][0];
        T = condition_array[index + 1][dim +1];
        ft_evaluate_line(bool_array[index],index ,dim, &B, &T);
        printf("B = %d ", B);
        printf("T = %d\n", T);
        index++;
    }
}


void    ft_evaluate_line(int *line,int index_line, int dim, int *B, int *T)   //index_line is needed to update_condition :)
{
	int	indexB;
	int	indexT;
    int top_edge;
    int bottom_edge;


    ft_update_edge(line, dim, &top_edge, &bottom_edge);
    if (*B == 1)
        bottom_edge = 1;
    if (*T == 1)
        top_edge = dim - 2;
// gives us the edges of Bottom and Top 
    //printf("top_edge = %d\n", top_edge);
    //printf("bottom_edge = %d\n", bottom_edge);

	indexB = *B - 1;
	indexT = dim - *T;
    if (dim - *T - *B + 1 < 0)    // We might need to update here
        printf("no solution\n");
    else if (bottom_edge - top_edge - 2 >= 0)
    {
        //printf("i'm tired\n");
        //printf("indexB = %d\n", indexB);
        //printf("indexT = %d\n", indexT);
        while(indexB < indexT + 1 && indexB < bottom_edge && *B == 1)  // The +1 is necessary to reach indexT
        { 
            line[indexB] = 1;
            indexB++;
            
        }
        while(indexB -1 < indexT  && indexT > top_edge && *T == 1)  // The -1 is necessary to reach indexBs
        { 
            line[indexT] = 1;
            indexT--;
            
        }
        while(indexB < indexT + 1 && *B != 1 && *T != 1)
        {
            line[indexB] = 1;
            indexB++;   
        }
    }
    else
    {
        while (indexB < bottom_edge)
        {
            line[indexB] = 1;
            indexB++;
        }
        while (indexT > top_edge)
        {
            line[indexT] = 1;
            indexT--;
        }
        
    }
}

void ft_update_edge(int *line, int dim, int *top_edge, int *bottom_edge)
{
    int index;
    
    *bottom_edge = 0;
    index = 0;
    while (index < dim && line[index] != 9)
    {
        (*bottom_edge)++;
        index++;
    }
    index = dim -1;
    *top_edge = dim -1;
    while (index > -1 && line[index]!= 9)
    {
        (*top_edge)--;
        index--;
    }
}




void transpose(int **tab_src, int dim)
{
    int i;
    int j;
    int swp;

    i = 0;
    while (i < dim)
    {
        j = i;
        while (j < dim)
        {
            swp = tab_src[i][j];
            tab_src[i][j] = tab_src[j][i];
            tab_src[j][i] = swp;
            j++;
        }
        i++;
    }
}

// if((*B==1))
//     {
//         line[indexB] = 1;    
//         ft_please_increase_the_maximum_length_of_function(line,length_line);
//     }
//     if((*tR == 1 && line[*tR] != 9))
//     {
//         line[indexT] = 1;
//         ft_please_increase_the_maximum_length_of_function(line,length_line);
//     }