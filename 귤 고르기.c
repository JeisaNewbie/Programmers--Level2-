#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{
    return *(int *)b - *(int *)a;
}

int solution(int k, int tangerine[], size_t tangerine_len) {
    int amount_of_tangerine[10000001] = {0,};
    int bigger = 0;
    
    for (int i = 0; i < tangerine_len; i++)
    {
        amount_of_tangerine[tangerine[i]]++;
        if (bigger < tangerine[i])
            bigger = tangerine[i];
    }
    
    qsort (amount_of_tangerine, bigger + 1, sizeof (int), compare);
    
    for (int i = 0; amount_of_tangerine[i] != 0; i++)
    {
        if (amount_of_tangerine[i] >= k)
            return i + 1;
        k -= amount_of_tangerine[i];
    }

    return 0;
}
