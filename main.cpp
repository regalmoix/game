#include <bits/stdc++.h>
#include <fstream>
#include <random>
#include <iterator>
#include <curses.h>
#include <stdlib.h>

#define ESC 27 //ASCII for escape
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100


#define ROCK 178

using namespace std;

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

vector<pair<int, int>> emptypos;

void tilemove (vector<vector<int>>& board, int n);

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

void consoleinput(vector<vector<int>>& board, int n)
{
    for (auto& row : board)
    {
        for (int& i : row)
            cin >> i;
    }

    emptycell(board, n);
}

void input(vector<vector<int>>& board, int n)
{
    ifstream fin;
    fin.open("inputfile", ios::in);

    for (auto& row : board)
    {
        for (int& i : row)
            fin >> i;
    }

    emptycell(board, n);

    fin.close();
}

void consoleprintboard(vector<vector<int>>& board, int n)
{
    ofstream fout;
    fout.open("outputfile", ios::out);

    for (auto row : board)
    {
        for (int& i : row)
            fout << i << " ";

        fout << endl;
    }

    fout << endl << endl;

    fout.close();
}

void printboard(vector<vector<int>>& board, int n)
{
    ofstream debug;
    debug.open("test", ios::out);

    keypad(initscr(),1);
    curs_set(0);

    clear();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //string s = to_string(board[i][j]);
            //char const *c = s.c_str();


            //mvaddch(i, j, (char)(board[i][j] + 48));
            //mvprintw(6*i, 6*j, c);


            move(4*i, 4*j);

            if (board[i][j])
                printw("%d", board[i][j]);

                       

            debug << board[i][j] << " ";
            
        }
        debug << endl;
    }
    
    debug.close();

    tilemove(board, n);  
}

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

void tilemove (vector<vector<int>>& board, int n)
{
    noecho();
    char dir = getch();

    switch (dir)
    {
        case UP :   up(board, n);
                    addrandom(board);
                    consoleprintboard(board, n);
                    printboard(board, n);
                    break;

        case DOWN : down(board, n);
                    addrandom(board);
                    consoleprintboard(board, n);
                    printboard(board, n);
                    break;

        case LEFT : left(board, n);
                    addrandom(board);
                    consoleprintboard(board, n);
                    printboard(board, n);
                    break;

        case RIGHT: right(board, n);
                    addrandom(board);
                    consoleprintboard(board, n);
                    printboard(board, n);
                    break;


        default:
                    consoleprintboard(board, n);
                    printboard(board, n);
                    break;
    }
}

//represent empty cells with 0;

int main()
{
    int n = 4;

    vector<vector<int>> board(n, vector<int> (n,0));
    
    input(board, n);

    printboard(board, n); 

    return endwin();

}
