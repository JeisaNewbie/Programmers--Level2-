#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int dp[100000] = {0}; //dp (다이나믹 프로그래밍(또는 동적 계획법)) 사용

int Fibonacci (int n)
{
    if (n < 2)
    {
        dp[n] = n;
        return dp[n];
    }
    if (dp[n] > 0)
        return (dp[n]);

    dp[n] = Fibonacci (n - 1) % 1234567 + Fibonacci (n - 2) % 1234567;
    return dp[n] % 1234567;
}

int solution(int n) {
    return Fibonacci (n);
}
