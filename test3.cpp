//�Ǻ���ġ ����
#include <iostream>

int fibo(int n);

int main()
{
    int n;
    std::cout << "�� ��° ���� ���ұ��?: ";
    std::cin >> n;

    std::cout << fibo(n) << std::endl;

    return 0;
}

int fibo(int n)
{
    if (n < 2)
    {
        return n;
    }

    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}

//�޸������̼�
#include <iostream>

long long memo[101];

long long fibo_memo(int n) {
    
    if (n < 2) {
        return n;
    }
    
    if (memo[n] != -1) {
        return memo[n];
    }
    
    memo[n] = fibo_memo(n - 1) + fibo_memo(n - 2);

    return memo[n];
}

int main() {
    
    for (int i = 0; i < 101; ++i) {
        memo[i] = -1;
    }

    int n;
    std::cout << "�� ��° ���� ���ұ��?: ";
    std::cin >> n;

    std::cout << fibo_memo(n) << std::endl;

    return 0;
}

//Ÿ�淹�̼�

#include <iostream>

long long dp[101];

long long fibo_tab(int n) {
    
    dp[0] = 0;
    dp[1] = 1;
   
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    std::cout << "�� ��° ���� ���ұ��?: ";
    std::cin >> n;

    std::cout << fibo_tab(n) << std::endl;

    return 0;
}






