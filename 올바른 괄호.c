#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool solution(const char* s) {
    bool answer = true;
    int check = 0;
    int i = 0;
    
    while (s[i])
    {
        if (s[i] == '(')
            check++;
        else
            check--;
        if (check < 0)
            return (false);
        i++;
    }
    
    return answer = check == 0 ? true : false ;
}
