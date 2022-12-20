#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *itok (int n, int k)
{
    long long digit = k;
    char *arr;
    int remain;
    int i = 2;
    
    while (digit <= n)
    {
        digit *= k;
        i++;
    }
    
    arr = calloc (i--, sizeof (char));
    
    while (n)
    {
        remain = n % k;
        arr[--i] = remain + '0';
        n /= k;
    }
    return arr;
}

long long ktoi (char *tmp)
{
    long long num = 0;
    int i = 0;
    
    while (tmp[i])
    {
        num = num * 10 + (tmp[i] - '0');
        i++;
    }
    return num;
}

int check_prime (long long num)
{
    if (num <= 1)
        return 0;
    if (!(num % 2) && num != 2)
        return 0;
    for (long long i = 3; i * i <= num ; i+=2)
    {
        if (!(num % i))
            return 0;
    }
    return 1;
}

char *cutstr(char *src, size_t dstsize)
{
    char    *dst = (char *) malloc(sizeof (char) * dstsize + 1);
    size_t	i = 0;

	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[dstsize] = '\0';
	return (dst);
}

int solution(int n, int k) {
    char *arr = itok (n, k);
    char *tmp;
    int length = strlen (arr);
    int idx = 0;
    int answer = 0;
    
    for (int i = 0; i < length; i++)
    {
        idx = i;
        while (arr[i + 1] != '0' && arr[i + 1] != '\0')
            i++;
        i++;
        tmp = cutstr (&arr[idx], i - idx);
        if (check_prime (ktoi(tmp)))
            answer++;  
    }
    return answer;
}
