#include "./global.h"
#include <stdlib.h>
#include <curses.h>



using namespace std;

int main()
{
    int n = 4;

    vector<vector<int>> board(n, vector<int> (n,0));
    
    input(board, n);

   

    printboard(board, n); 

    return endwin();
}
