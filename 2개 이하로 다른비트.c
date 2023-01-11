#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long check (long long a) //a가 0으로 나누어 떨어지는 가장 큰 수를 탐색
{
    int i = 2;
    while (1)
    {
        if (a % (long long)pow (2, i) != 0) //a는 기본적으로 4의 배수로 나누어 떨어짐, 즉 2의 제곱으로도 
            return (long long)pow (2, i - 1);
        i++;
    }
}

long long* solution(long long numbers[], size_t numbers_len) {
    long long   *answer = (long long*)malloc(sizeof (long long) * numbers_len);
    long long   a;

    for (size_t i = 0; i < numbers_len; i++)
    {
        a = numbers[i];

        if ((a + 1) % 4 == 0) //4의 배수를 찾는 이유는 4의 배수부터 3자리 이상 비트자리가 바뀌기 때문 (8의 배수는 4자리, 16의 배수는 5자리 등등)
            answer[i] = a + check (a + 1) / 2; // (a + 1)을 나누어 떨어지게 하는 가장 큰 수가 4 라면 두자리를 바꿔주면됨 (8은 3자리, 16은 4자리 등등) 
        else
            answer[i] = a + 1;
    }

    return answer;
}
