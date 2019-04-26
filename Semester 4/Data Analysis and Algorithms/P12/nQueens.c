//Program to implement N-Queens problem using backtracking

#include <stdio.h>

int N;
int board[20][20];

int is_attack(int i,int j) //to check if the next queen to be placed will be attacked in that position(i,j) or not
{
    int k,l;
    for(k=0;k<N;k++) //to check if a queen is present in that row or column
    {
        if((board[i][k] == 1) || (board[k][j] == 1))
            return 1;
    }

    for(k=0;k<N;k++) //to check for the diagonol
    {
        for(l=0;l<N;l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(board[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0; //if there is no attack 
}

int N_queen(int n)
{
    int i,j;
    if(n==0) //to check if all the queens are placed or not
        return 1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if((!is_attack(i,j)) && (board[i][j]!=1)) //to check if that positon is going to be attacked or not also if it is vacant or not
            {
                board[i][j] = 1;
                if(N_queen(n-1)==1) //to check if the queen is placed rightly or not
               		return 1;
                board[i][j] = 0; //if not change the present queen's position
            }
        }
    }
    return 0; //if the queen is not placed rightly
}

int main()
{
    printf("Enter the value of N for NxN chessboard\n");
    scanf("%d",&N);

    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            board[i][j]=0; //to initialize the board
    N_queen(N); //call the function
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",board[i][j]); //print the solution
        printf("\n");
    }

}
