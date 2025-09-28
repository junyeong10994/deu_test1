#include <iostream>
#include <vector>


int main() {
	int money = 1360;
	std::vector<int> coins = { 500,100,50,10 };
	int count = 0;

	std::cout << "총 거스름돈:" << money << "원" << std::endl;
	for (int coin : coins) {
		int num_coins = money / coin;
		
		if (num_coins > 0) {
			std::cout << coin << "원짜리 동전" << num_coins << "개" << std::endl;
			count += num_coins;
			money %= coin;
		}
	}
	std::cout << "최소 동전 개수:" << count << "개" << std::endl;
			
}
