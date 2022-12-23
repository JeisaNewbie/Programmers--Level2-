#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int check[8] = {0,}; // 다녀간 인덱스는 체크해서, 다시 한번 탐색하는것을 피하기 위함

int back_tracking (int k, int **dungeons, size_t rows, size_t depth, int *answer)
{   
    if (*answer < depth) //depth는 방문한 던전의 수를 의미함.
        *answer = depth;
    
    if (*answer == rows)
        return 0;
    
    for (size_t i = 0; i < rows; i++)
    {
        while (i < rows && check[i])
            i++;
        
        if (i >= rows)
            return 0;
        
        if (k < dungeons[i][0] || k < dungeons[i][1])
            continue ;
        
        k -= dungeons[i][1];
        check[i] = 1;
        back_tracking (k, dungeons, rows, depth + 1, answer);
        k += dungeons[i][1];
        check[i] = 0;
    }
    return 0;
}

int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    int answer = 0;
    
    back_tracking (k, dungeons, dungeons_rows, 0, &answer);
    
    return answer;
    
}
