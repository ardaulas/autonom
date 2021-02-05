// Enter a one way maze from the starting point, search_row,search_col
// and exit from the maze

// 16 Aug 2013 v1.0.0
// autonom.cpp : Defines the entry point for the console application.

#include "stdafx.h"

int main(int argc, char* argv[])
{
	int ROWS=10;
	int COLS=10;
	int search_row=9;
	int search_col=4;
	bool row_inc=0;
	bool row_dec=0;
	bool col_inc=0;
	bool col_dec=0;
	int dont_look_row=0;
	int dont_look_col=0;
	int a [10][10]={
		{0,0,0,0,0,0,1,0,1,0,},
		{0,0,0,0,0,0,1,0,1,0,},
		{0,0,0,0,0,1,1,0,1,0,},
		{0,0,0,0,0,1,0,0,1,0,},
		{0,0,0,0,0,1,0,1,1,0,},
		{0,0,0,1,1,1,0,1,0,0,},
		{0,0,0,1,0,0,0,1,0,0,},
		{0,0,0,1,0,1,1,1,0,0,},
		{0,0,0,1,0,1,0,0,0,0,},
		{0,0,0,1,0,1,0,0,0,0,},
	};

	for (int i=ROWS-1;i>=0;i--)
		for (int j=0;j<COLS;j++){
			printf("%i",a[i][j]);
			if (j==9) printf("\n");
		}

	printf("Autonom!\n");
	printf("ENTER: %i,%i\n",search_row,search_col);

	do{
		if ( search_row-1 >= 0 && search_row-1 < 10 && search_col > 0 && search_col < 10 ){
				if ( a[search_row-1][search_col] == 1 ){
					printf("%i:%i,closed\n",search_row-1,search_col);
				}
				else{
					if ( search_row-1 == dont_look_row ){
						printf("before cell\n");
					}
					else{
						printf("%i:%i,open\n",search_row-1,search_col);
						row_dec=1;
					}
				}
		}
		if ( search_row+1 >= 0 && search_row+1 < 10 && search_col > 0 && search_col < 10 ){
				if ( a[search_row+1][search_col] == 1 ){
					printf("%i:%i,closed\n",search_row+1,search_col);
				}
				else{
					if ( search_row+1 == dont_look_row ){
						printf("before cell\n");
					}
					else{
						printf("%i:%i,open\n",search_row+1,search_col);
						row_inc=1;
					}
				}
		}
		if ( search_row > 0 && search_row < 10 && search_col-1 >= 0 && search_col-1 < 10 ){
				if ( a[search_row][search_col-1] == 1 ){
					printf("%i:%i,closed\n",search_row,search_col-1);
				}
				else{
					if ( search_col-1 == dont_look_col ){
						printf("before cell\n");
					}
					else{
						printf("%i:%i,open\n",search_row,search_col-1);
						col_dec=1;
					}
				}
		}
		if ( search_row > 0 && search_row < 10 && search_col+1 >= 0 && search_col+1 < 10 ){
				if ( a[search_row][search_col+1] == 1 ){
					printf("%i:%i,closed\n",search_row,search_col+1);
				}
				else{
					if ( search_col+1 == dont_look_col ){
						printf("before cell\n");
					}
					else{
						printf("%i:%i,open\n",search_row,search_col+1);
						col_inc=1;
					}
				}
		}
		dont_look_row=search_row;
		dont_look_col=search_col;
		if (row_dec) search_row--;
		else if (row_inc) search_row++;
		else if (col_dec) search_col--;
		else if (col_inc) search_col++;
		row_dec=0;
		row_inc=0;
		col_dec=0;
		col_inc=0;
	}while( search_row );

	printf("EXIT: %i,%i\n",search_row,search_col);

	return 0;
}

