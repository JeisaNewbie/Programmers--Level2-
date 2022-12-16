#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long arr[10000][20000] = {0, }; // dp사용. 배열을 1001, 2001의 크기 만큼만 선언하면 segfault가 발생함.

long long sum (long long a, long long b)
{
    long long A = a;
    long long B = b;
    long long tmp = 0;
    
    if (a == 0 || b == 0)
        return arr[a][b] = 1;
    
    if (a == 1 || b == 1)
        return arr[a][b] = a + b;
    
    if (arr[a][b] > 0)
        return arr[a][b];
    
    if (arr[b][a] > 0)
        return arr[b][a];
        
    for (long long i = 0; 0 <= A; A--)
    {
        arr[i][A] = sum (i, A);
        arr[i][B] = sum (i, B);
        tmp += (arr[i][A] % 1234567) * (arr[i][B] % 1234567);
        i++;
        B--;
        if (B < 0)
            break ;
    }
    return tmp;
}

long long solution(int n) {
    long long answer = 0;
    long long a = 0;
    long long b = n;
    
    for (a = 0; 0 <= b; b -= 2)
    {
        answer += sum (a, b);
        a++;
    }
    return answer % 1234567;
}
