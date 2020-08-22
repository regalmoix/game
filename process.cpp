#include "./global.h"
#include "randomgen.cpp"
//#include <algorithm>

using namespace std;

void addrandom(vector<vector<int>>& board)
{
    if(!emptypos.empty())
    {    
        int randvalue = 2; //could be changed later

        pair<int,int> p = *select_randomly(emptypos.begin(), emptypos.end());

        board[p.first][p.second] = randvalue;
    }

    else
    {
        //Break, display score etc.
    }
}

void left (vector<vector<int>>& board, int n)
{
    for (auto& row : board)
    {
        vector<int> temp(n, 0);
        int i = 0;

        for (int& x : row)
        {
            if (x != 0)
            {
                temp[i] = x;
                i++;
            }
        }

        row = temp;

        vector<int> temp2(n, 0);

        int j = 0;

        for (int i = 0; i < n; i += 0)
        {
            if (row[i] == row[i+1])
            {
                temp2[j] = 2 * row[i];
                score += 2*row[i];
                i += 2;
                j++;
            }

            else
            {
                temp2[j] = 1 * row[i];
                i++;
                j++;
            }
        }

        row = temp2;
    }

    emptycell(board, n);
}

void right (vector<vector<int>>& board, int n)
{
    for (auto& row : board)
    {
        reverse(row.begin(), row.end());
    }

    left(board, n);

    for (auto& row : board)
    {
        reverse(row.begin(), row.end());
    }

    emptycell(board, n);
}

void up (vector<vector<int>>& board, int n)
{
    rotateMatrix(board, n);

    left(board, n);

    rotateMatrix(board, n);
    rotateMatrix(board, n);
    rotateMatrix(board, n);

    emptycell(board, n);
}

void down (vector<vector<int>>& board, int n)
{
    rotateMatrix(board, n);
  
    right(board, n);

    rotateMatrix(board, n);
    rotateMatrix(board, n);
    rotateMatrix(board, n);

    emptycell(board, n);
}

void rotateMatrix (vector<vector<int>>& mat, int N) 
{ 
    for (int x = 0; x < N / 2; x++) 
    {        
        for (int y = x; y < N - x - 1; y++) 
        { 
            int temp = mat[x][y]; 

            mat[x][y] = mat[y][N - 1 - x]; 

            mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y]; 

            mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x]; 

            mat[N - 1 - y][x] = temp; 
        } 
    } 
} 

void emptycell(vector<vector<int>>& board, int n)
{
    emptypos.clear();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 0)
                emptypos.push_back({i, j});
        }
    }
}

