#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *change (int len)
{
    char *arr;
    int remain = 0;
    int two = 2;
    int i = 2; // len이 1이하 일때 '0' 혹은 '1'을 표시할 자리 하나와 널값을 넣을 자리 한개를 할당하기 위함.
    
    while (two <= len)
    {
        two *= 2;
        i++;
    }

    arr = calloc (i--, sizeof (char));
    
    while (len)
    {
        remain = len % 2;
        arr[--i] = remain + '0';
        len /= 2;
    }
    return (arr);
}

int* solution(const char* s) {
    int* answer = calloc (2, sizeof (int));
    char *arr = s;
    int count = 0;
    int len = 0;
    
    for (int i = 0; len != 1; i++)
    {
        len = strlen (arr);
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == '0')
            {
                answer[1]++;
                count++;
            }
        }
        len -= count;
        arr = change (len);
        answer[0]++;
        count = 0;
    }
    
    return answer;
}
