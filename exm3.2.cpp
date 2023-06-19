#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(vector < vector <int»& cost, int i, int j, int sum, vector<int>& sums) {
if (i == 9 && j == 9)
{
// если мы достигли правой нижней ячейки, то сохраняем сумму платы за посещение ячеек на этом пути
sums.push_back(sum + cost[i][j]);
return;
}

if (i < 9) // движение вниз
backtrack(cost, i + 1, j, sum + cost[i][j], sums);


if (j < 9) // движение вправо
backtrack(cost, i, j + 1, sum + cost[i][j], sums);
}

int main() {
vector < vector < int» cost = {
{10, 21, 30, 40, 50, 60, 70, 80, 90, 99},
{20, 30, 40, 50, 60, 70, 80, 90, 99, 10},
{30, 40, 50, 60, 70, 80, 90, 99, 10, 20},
{40, 50, 60, 70, 80, 90, 99, 10, 20, 30},
{50, 60, 70, 80, 90, 99, 10, 20, 30, 40},
{60, 70, 80, 90, 99, 10, 20, 30, 40, 50},
{70, 80, 90, 99, 10, 20, 30, 40, 50, 60},
{80, 90, 99, 10, 20, 30, 40, 50, 60, 70},
{90, 99, 10, 20, 30, 40, 50, 60, 70, 80},
{99, 10, 20, 30, 40, 50, 60, 70, 80, 90}
};

vector<int> sums;

backtrack(cost, 0, 0, 0, sums);

sort(sums.begin(), sums.end());

cout « *(sums.end()-1)« *sums.begin();

return 0;
}
