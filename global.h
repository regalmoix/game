#define ESC 27 //ASCII for escape
#define UP 119
#define DOWN 115
#define LEFT 97
#define RIGHT 100
#define ROCK 178

#include <vector>
#include <algorithm>

using namespace std;

int score = 0;
std::vector<std::pair<int, int>> emptypos;

template<typename Iter, typename RandomGenerator> Iter select_randomly(Iter start, Iter end, RandomGenerator& g);
template<typename Iter> Iter select_randomly(Iter start, Iter end);

void input(vector<vector<int>>& board, int n);

void addrandom(vector<vector<int>>& board);
void rotateMatrix (vector<vector<int>>& mat, int N);
void left (vector<vector<int>>& board, int n);
void right (vector<vector<int>>& board, int n);
void down (vector<vector<int>>& board, int n);
void up (vector<vector<int>>& board, int n);
void emptycell(vector<vector<int>>& board, int n);

void printboard(vector<vector<int>>& board, int n);
void tilemove (vector<vector<int>>& board, int n);
