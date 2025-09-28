#include <iostream>
#include <vector>


int main() {
	int money = 1360;
	std::vector<int> coins = { 500,100,50,10 };
	int count = 0;

	std::cout << "�� �Ž�����:" << money << "��" << std::endl;
	for (int coin : coins) {
		int num_coins = money / coin;
		
		if (num_coins > 0) {
			std::cout << coin << "��¥�� ����" << num_coins << "��" << std::endl;
			count += num_coins;
			money %= coin;
		}
	}
	std::cout << "�ּ� ���� ����:" << count << "��" << std::endl;
			
}
