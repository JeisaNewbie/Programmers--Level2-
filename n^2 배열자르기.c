#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right) {
    int *answer = (int *)malloc (sizeof (int) * (right - left));
    int times = (left % n) + 1;
    int start = 0;
    int idx = 0;
    int k = 0;
    
    if ((left % n) > (left / n))
        k = (left % n) - (left / n);
    
    for (; left <= right; left++)
    {
        start = (left / n) + k + 1;
        answer[idx++] = start;
        if (start <= times)
            k++;
        times++;
        if (times > n)
        {
            times = 1;
            k = 0;
        }
    }
  
    return answer;
}
