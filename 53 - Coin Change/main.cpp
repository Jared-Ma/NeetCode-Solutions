#include <algorithm>
#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>

class Solution {
public:
	static int dfs(std::vector<int>& coins, int amount, std::unordered_map<int, int>& min_coins_map) {
		if (amount == 0) {
			return 0;
		}

		if (min_coins_map.contains(amount)) {
			return min_coins_map[amount];
		}

		int min_coins = INT_MAX;
		for (int coin : coins) {
			if (amount - coin >= 0) {
				int result = dfs(coins, amount - coin, min_coins_map);
				if (result != INT_MAX) {
					min_coins = std::min(min_coins, 1 + result);
				}
			}
		}
		min_coins_map[amount] = min_coins;

		return min_coins;
	}

	static int coinChange(std::vector<int>& coins, int amount) {
		std::unordered_map<int, int> min_coins_map {};
		int min_coins = dfs(coins, amount, min_coins_map);
		return (min_coins != INT_MAX) ? min_coins : -1;
	}
};

int main() {
	std::vector<int> coins1 {1, 5, 10};
	std::cout << Solution::coinChange(coins1, 12) << '\n';
	std::vector<int> coins2 {2};
	std::cout << Solution::coinChange(coins2, 3) << '\n';
	std::vector<int> coins3 {1};
	std::cout << Solution::coinChange(coins3, 0) << '\n';
}
