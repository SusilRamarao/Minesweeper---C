#include<iostream>
#include<conio.h>
#include<random>
#include<time.h>
#include<stdlib.h>
using namespace std;


void display(char mat[100][100], int r, int c)
{
    int i, j;
    printf("\n");
    for(i = 0; i < r; i++)
    {
        printf("\n");
        for(j = 0; j < c; j++)
        {
            printf("%c ", mat[i][j]);
        }
    }

    printf("\n");
}

void genMines(int row,int col,int minesarr[100][100],int choice)
{

    int i = 0, j = 0, k = 0, mines = 0, r=0,c=0 ,flag = 0, tempc = 0, tempr = 0, rowarr[10], colarr[10];
    time_t t;

    mines = 6;
    srand(time(NULL));
    while(i < mines)
    {
        //flag = 1;
        tempr = rand() % (row - 1);
        flag = 0;

        for(j = 0; j < r; j++)
        {
            if(tempr == rowarr[j])
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            rowarr[r++] = tempr;
            i++;
        }
    }

    while(j < mines)
    {
        //flag = 1;

        tempc = rand() % (col - 1);
        flag = 0;

        for(k = 0; k < c; k++)
        {
            if(tempc == colarr[k])
            {
                flag = 1;
                break;
            }
        }
        if(!flag)
        {
            colarr[c++] = tempc;
            j++;
        }
    }

    for(i = 0; i < r && i < c; i++)
    {
        tempr = rowarr[i];
        tempc = colarr[i];
        minesarr[tempr][tempc] = 1;
    }
    printf("\n\nMINES GEN\n\n");
    for(i = 0; i < row; i++)
    {
        printf("\n");
        for(j = 0; j < col; j++)
        {
            printf("%d ", mines[i][j]);
        }
    }

}
int checkMines(int r, int c, int row, int col, int mines[100][100])
{
    printf("Mines array\n");
    int i = 0, j = 0;
    for(i = 0; i < row; i++)
    {
        printf("\n\n");
        for(j = 0; j < col; j++)
        {
            printf("%d ", mines[i][j]);
        }
    }
    int rows[4] = {-1, 0, 0, 1};
    int cols[4] = {0, 1, -1, 0};
    int checks[4] = {0, 0, 0, 0};

    int counts = 0, k, l;

    if(r - 1 >= 0)
    {
        checks[0] = 1;
    }
    if(c + 1 < col - 1)
    {
        checks[1] = 1;
    }
    if(c - 1 >= 0)
    {
        checks[2] = 1;
    }
    if(r + 1 < row - 1)
    {
        checks[3] = 1;
    }
    printf("\nCHECK --- check\n");
    for(k = 0; k < 4; k++)
        printf("%d ", checks[k]);
    printf("\n");
    for(k = 0; k < 4; k++)
    {
        if(checks[k])
        {
            if(mines[r + rows[k]][c + cols[k]])
            {
                printf("IN CHECKd %d %d\n", rows[k], cols[k]);
                counts++;
            }
        }
    }

    return counts;
}
int isRange(int r, int c, int row, int col)
{
    if((r >= 0 && r < row)&&(c >= 0 && c < col))
    {
        return 1;
    }
    else
        {
            return 0;
        }
}
int main()
{

    char mat[100][100], inp;
    int i, j, k, minesarr[100][100], row = 0, col = 0, level = 0, mcount = 0, mines = 0, gc = 0, r = 0, c = 0;


    printf("Enter the row and column number\n");

    scanf("%d %d", &row, &col);

    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            mat[i][j] = '*';
            minesarr[i][j] = 0;
        }
    }

    //clrscr();

    printf("\t\t\tWelcome to minesweeper\n");

    printf("You will be given a grid as shown below\n\n");

    display(mat, row, col);

    printf("Please enter the row and column number to lock a cell\n");
    printf("For example ROW - 2 COL - 1");
    mat[2][1] = 2 + 48;
    display(mat, row, col);
    mat[2][1] = '*';

    printf("Enter level \n1.Easy\n2.Medium\n3.Hard");
    //scanf("%d", &level);


   // ------------------------ >>>>>>>>>>> IMPORTANT;

    printf("Enjoy the game\n");
    //clrscr();


    while(1)
    {
            //clrscr();
            display(mat, row, col);
            printf("\n\nEnter the row and column index to lock\n");
            scanf("%d %d", &r, &c);
            if(!isRange(r, c, row, col) || mat[r][c] != '*')
            {
                printf("Please enter a valid row and column index\n");
                continue;
            }

            if(minesarr[r][c] == 1)
            {
                printf("\t\t\tYou have entered in a MINE CELL\n");
                printf("\t\t\tGAME OVER");
                break;
            }

            mcount = checkMines(r, c, row, col, minesarr);
            printf("CHECK -- %d %d %d\n", r, c, mcount);
            mat[r][c] = mcount + 48;
            gc++;

            if(gc == ((row * col) - mines))
            {
                printf("\t\t\tGAME WON");
                getch();
                break;

            }
    }
}

