#include "./global.h"
#include <curses.h>

int score = 0;

using namespace std;
std::vector<std::pair<int, int>> emptypos;

int main()
{
    int n = 4;

    vector<vector<int>> board(n, vector<int> (n,0));
    
    input(board, n);

    printboard(board, n); 

    return endwin();

}
