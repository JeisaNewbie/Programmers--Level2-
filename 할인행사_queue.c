#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

int arr_of_data[10000000] = {0,};
int front = 0;
int rear = 0;

void init_arr (const char* want[], size_t want_len, const char* discount[], size_t discount_len, int * cp_discount)
{
    for (size_t i = 0; i < want_len; i++)
    {
        for (size_t j = 0; j < discount_len; j++)
            if (strcmp (want[i], discount[j]) == 0)
                cp_discount[j] = i + 1;
    }
}

int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[], size_t discount_len) {
    int *cp_discount = calloc (discount_len + 10, sizeof(int));
    int *cp_want = calloc (want_len + 10, sizeof(int));
    int *cp_num = calloc (want_len + 10, sizeof(int));
    int answer = 0;
    
    for (size_t i = 1; i <= want_len; i++)
        cp_want[i] = i;
    
    init_arr (want, want_len, discount, discount_len, cp_discount);
  
    for (size_t i = 0; i < discount_len; i++)
    {
        if (cp_discount[i])
        {
            arr_of_data[front++] = cp_discount[i];
            cp_num[cp_discount[i]]++;
        }
        else
        {
            memset (cp_num, 0, want_len + 1);
            front++;
            rear = front;
            if (discount_len - i < 10)
                return answer;
        }
        
        if (rear == front)
            continue ;
        
        if (cp_num[cp_discount[i]] > number[cp_discount[i] - 1])
        {
            while (cp_num[cp_discount[i]] > number[cp_discount[i] - 1])
            {
                cp_num[arr_of_data[rear]]--;
                rear++;
            }
        }
        if ((front - rear) >= 10)
            answer++;
    }
    return answer;
}
