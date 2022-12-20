#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//records의 인덱스 0-4 = time; 6-9 = car_num; 11-12or13 = in or out
void sort (int **rec, int length)
{
    int tmp1;
    int tmp2;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i; j < length; j++)
        {
            if (rec[i][0] > rec[j][0])
            {
                tmp1 = rec[i][0];
                tmp2 = rec[i][1];
                rec[i][0] = rec[j][0];
                rec[i][1] = rec[j][1];
                rec[j][0] = tmp1;
                rec[j][1] = tmp2;
            }
        }
    }
}

int time (const char *time)
{
    return ((time[0] - '0') * 10 + time[1] - '0') * 60 + ((time[3] - '0') * 10 + time[4] - '0');
}

int car (const char *num)
{
    int number = 0;
    int i = 0;
    
    while (i < 4)
        number = number * 10 + (num[i++] - '0');
    return number;
}

int fee (int *fees, int time)
{
    int total = (time - fees[0]) % fees[2] == 0 ? 0 : fees[3];
    if (time <= fees[0])
        return fees[1];
    
    return total + ((time - fees[0]) / fees[2]) * fees[3] + fees[1];
}

int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    int *answer;
    int **rec_in = (int **) malloc (sizeof (int *) * records_len);
    int **rec_out = (int **) malloc (sizeof (int *) * records_len);
    int car_idx = 1;
    int idx = 0;
    int j = 0;
    int k = 0;
    
    for (int i = 0; i < records_len; i++)
    {
        rec_in[i] = (int *)malloc (sizeof (int) * 2);
        rec_out[i] = (int *)malloc (sizeof (int) * 2);
        rec_in[i][0] = rec_in[i][1] = -1;
        rec_out[i][0] = rec_out[i][1] = -1;
    }
    
    for (int i = 0; i < records_len; i++) // In일경우와 Out일경우를 따로 저장
    {
        if (records[i][11] == 'I')
        {
            rec_in[j][0] = car(&records[i][6]);
            rec_in[j++][1] = time (&records[i][0]);
        }
        else if (records[i][11] == 'O')
        {
            rec_out[k][0] = car(&records[i][6]);
            rec_out[k++][1] = time (&records[i][0]);
        }
    }
    
    sort (rec_in, j); //출입기록을 차량번호 오름차순 정렬
    if (k > 0)
        sort (rec_out, k);
    
    
    for (int i = 0; i < j - 1; i++) //총 출입차량수 체크
    {
        car_idx++;
        if (rec_in[i][0] == rec_in[i + 1][0])
            car_idx--;
    }
    
    answer = (int*)malloc(sizeof (int) * car_idx);
    
    for (int i = 0; i < car_idx; i++)
        answer[i] = 0;
    
    for (int i = k = 0; i < j; i++) // 출입차량 비교후 시간을 더해줌
    {
        if (rec_in[i][0] == rec_out[k][0])
            answer[idx] += rec_out[k++][1] - rec_in[i][1];
        else
            answer[idx] += 1439 - rec_in[i][1];
        
        if (i < j - 1 && rec_in[i][0] != rec_in[i + 1][0])//i와 i + 1의 차량번호를 체크하고, 다를시 다음차량
            idx++;
    }
    
    for (int i = 0; i < car_idx; i++)
        answer[i] = fee (fees, answer[i]);
        
    return answer;
}
