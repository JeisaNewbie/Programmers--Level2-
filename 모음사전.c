#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int total = 0;

int recursion (const char *word, int high)
{
    int idx = 0;
    int num = 0;
    if (word[0] == '\0')
        return (0);
    if (word[0] == 'A')
        idx = 0;
    else if (word[0] == 'E')
        idx = 1;
    else if (word[0] == 'I')
        idx = 2;
    else if (word[0] == 'O')
        idx = 3;
    else
        idx = 4;
    
    for (int i = high - 1; i >= 0; i--)
        num += pow (5, i);
    total += num * idx + 1; // num * 5 * (idx / 5) 의 줄인코드
    total += recursion (&word[1], high - 1);
}

int solution(const char* word) {
    
    recursion (word, 5);
    
    return total;
}
