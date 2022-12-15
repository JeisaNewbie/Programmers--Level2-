#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr[], size_t arr_len) {
    int times = arr[arr_len - 1];
    
    for (size_t i = 0; i < arr_len; i++)
    {
        if (arr[arr_len - 1] % arr[i])
        {
            arr[arr_len - 1] += times;
            i = -1;
        }
    }
    return arr[arr_len - 1];
}
