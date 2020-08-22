#include <fstream>
#include "./global.h"

using namespace std;

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