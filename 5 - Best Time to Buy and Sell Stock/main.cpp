#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    static int maxProfit(std::vector<int>& prices) {
        int max_profit = 0;
        int min_buy = prices[0];
        int num_prices = static_cast<int>(prices.size());

        for (int i = 1; i < num_prices; ++i) { 
            max_profit = std::max(max_profit, prices.data()[i] - min_buy);
            min_buy = std::min(min_buy, prices.data()[i]);
        }

        return max_profit;
    }
};

int main() {
    std::vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    std::cout << Solution::maxProfit(prices1) << '\n';

    std::vector<int> prices2 = {7, 6, 4, 3, 1};
    std::cout << Solution::maxProfit(prices2) << '\n';

    std::vector<int> prices3 = {7, 1, 5, 3, 6, 4, 0, 6};
    std::cout << Solution::maxProfit(prices3) << '\n';

    std::vector<int> prices4 = {0};
    std::cout << Solution::maxProfit(prices4) << '\n';

    std::vector<int> prices5 = {1, 1, 1};
    std::cout << Solution::maxProfit(prices5) << '\n';
}