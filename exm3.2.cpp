#include <iostream>
#include <vector>

using namespace std;

void backtrack(vector < vector < int>>& coins, int i, int j, int sum, int& max_sum, int& count) {
	if (i == 9 && j == 9) { // если мы достигли правой нижней ячейки, то сохраняем сумму денежных сумм на этом пути
		if (sum > max_sum) {
			max_sum = sum;
			count = 1; // если мы нашли большую сумму, то количество маршрутов, дающих эту сумму, будет равно 1
		}
		else if (sum == max_sum) {
			count++; // если мы нашли еще один маршрут, дающий максимальную сумму, то увеличиваем количество маршрутов
		}
		return;
	}

	if (i < 9) { // движение вниз
		backtrack(coins, i + 1, j, sum + coins[i][j], max_sum, count);
	}

	if (j < 9) { // движение вправо
		backtrack(coins, i, j + 1, sum + coins[i][j], max_sum, count);
	}
}

int main() {
	vector < vector < int>> coins = {
	{2, 9, 1, 3, 5, 0, 4, 8, 7, 7},
	{6, 0, 7, 8, 3, 6, 9, 0, 9, 6},
	{1, 1, 5, 0, 5, 6, 1, 2, 8, 8},
	{9, 9, 1, 4, 3, 4, 1, 4, 3, 8},
	{2, 0, 4, 1, 7, 7, 6, 4, 2, 3},
	{9, 0, 9, 2, 0, 6, 3, 8, 6, 0},
	{1, 3, 1, 4, 4, 5, 9, 2, 7, 7},
	{9, 9, 2, 2, 1, 5, 9, 3, 0, 9},
	{7, 4, 4, 7, 7, 3, 3, 9, 2, 6},
	{9, 5, 5, 8, 2, 1, 3, 0, 4, 0}
	};

	int max_sum = 0;
	int count = 0;

	backtrack(coins, 0, 0, coins[0][0], max_sum, count);

	cout <<"max sum: " <<max_sum <<endl;
	cout <<"dif roots,max sum: " <<count <<endl;

	return 0;
}