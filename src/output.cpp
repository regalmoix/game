#include "./global.h"
#include <curses.h>
#include <fstream>


void printboard(vector<vector<int>>& board, int n)
{
    ofstream debug;
    debug.open("test", ios::out);

    keypad(initscr(),1);
    curs_set(0);

    clear();

    move(5*n, 5*n);

    printw("SCORE : %d", score);

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


void tilemove (vector<vector<int>>& board, int n)
{
    noecho();
    char dir = getch();

    switch (dir)
    {
        case UP :   up(board, n);
                    addrandom(board);
                    printboard(board, n);
                    break;

        case DOWN : down(board, n);
                    addrandom(board);
                    printboard(board, n);
                    break;

        case LEFT : left(board, n);
                    addrandom(board);
                    printboard(board, n);
                    break;

        case RIGHT: right(board, n);
                    addrandom(board);
                    printboard(board, n);
                    break;


        default:
                    printboard(board, n);
                    break;
    }
}
