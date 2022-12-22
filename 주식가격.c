#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int prices[], size_t prices_len) {
    int* answer = (int*)malloc(sizeof (int) * prices_len);
    int j = 0;
    for (size_t i = 0; i < prices_len - 1; i++)
    {
        j = i + 1;
        answer[i] = 0;
        while (j < prices_len)
        {
            answer[i]++;
            j++;
            if (prices[i] > prices[j - 1])
                j = prices_len;
        }
    }
    answer[j - 1] = 0; // j - 1 말고 prices_len을 하면 메모리 오류 발생
    
    return answer;
}
