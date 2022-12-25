#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int check_tracing (int *trace_x, int *trace_y, int current_idx)
{
    for (int i = 1; i < current_idx; i++)
    {
        if ((trace_x[i] == trace_x[current_idx]) && (trace_y[i] == trace_y[current_idx])) i를 기준으로 앞과 뒤에서 i를 방문했는지 체크
        {
            if (trace_x[i - 1] == trace_x[current_idx - 1]) && (trace_y[i - 1] == trace_y[current_idx - 1]) // 
                return 0;
            else if (trace_x[i + 1] == trace_x[current_idx - 1] && trace_y[i + 1] == trace_y[current_idx - 1])
                return 0;
        }
    }
    return 1;
}

int solution(const char* dirs) {
    int answer = 0;
    int trace_x[502] = {0,};
    int trace_y[502] = {0,};
    int x, y;
    trace_x[0] = trace_y[0] = -1;// 5, 5를 방문했을때, 전에도 방문했는지 비교하기 위해서 -1을 초기화
    trace_x[1] = trace_y[1] = x = y = 5;

    for (int i = 0; dirs[i] != 0; i++)
    {
        if (dirs[i] == 'U' && y < 10)
            y++;
        else if (dirs[i] == 'D' && y > 0)
            y--;
        else if (dirs[i] == 'R' && x < 10)
            x++;
        else if (dirs[i] == 'L' && x > 0)
            x--;
        else
            i = i;
        trace_x[i + 2] = x;
        trace_y[i + 2] = y;
        if(check_tracing(trace_x, trace_y, i + 2))
            answer++;
    }
    
    return answer;
}
