#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void change (char *arr, char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] == '(')
            arr[i] = 0;
        else if (s[i] == '[')
            arr[i] = 1;
        else if (s[i] == '{')
            arr[i] = 2;
        else if (s[i] == ')')
            arr[i] = 3;
        else if (s[i] == ']')
            arr[i] = 4;
        else
            arr[i] = 5;
        i++;
    }
}

//s의 길이를 구함. len의 길이만큼 반복해서 올바른 문자열의 총 개수를 찾아야함. 스택 사용
int solution(const char* s) {
    char arr[1000] = {0,};
    char tmp[1000] = {-1,};
    int length = strlen (s);
    int checker = 0;// 인덱스의 중간부터 시작할 경우, 중간부터 length - 1까지 탐색한 후에 한바퀴를 돌았다고 체크해야 하기 때문
    int idx = 0;
    int answer = 0;

    change (arr, s);

    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 2)
            continue ;

        for (int j = i; j < length; j++)
        {
            if (j == i && checker == 1) // 한바퀴를 돈 후에 j == i 일시 탐색하지 않은 앞부분도 탐색했다는 의미
            {
                j = length;
                checker = 0;
                idx = 0;
                continue ;
            }
            
            if (arr[j] < 3)
                tmp[idx++] = arr[j];
            else
            {
                idx--;
                if (idx < 0)
                    j = length; // for문 탈출
                else if (tmp[idx] == arr[j] % 3)
                    tmp[idx] = -1;
                else
                    j = length;
            }
            
            if (j == length - 1) // 0부터 중간까지 다시 탐색
            {
                j = -1;
                checker = 1; //length - 1까지 돌았기 때문에 
            }
        }
        
        if (tmp[0] == -1 && idx == 0)
            answer++;
        
        memset (tmp, -1, length);
        checker = 0;
        idx = 0;
    }
    return answer;
}
