#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int elements[], size_t elements_len) {
    int answer = 0;
    int tmp = 0;
    int bigger = 0;
    int arr[1000001] = {0,};
    for (size_t i = 1; i <= elements_len; i++)
    {
        for (size_t j = 0; j < elements_len; j++)
        {
            tmp = 0;
            for (size_t k = j; k < i + j; k++)
                tmp += elements[k % elements_len];
            if (bigger < tmp)
                bigger = tmp;
            arr[tmp] = 1;
        }
      if (i == elements_len)
        break ;
    }
    
    for (size_t i = 0; i <= bigger; i++)
        if (arr[i]) 
            answer++;
  
    return answer;
}
