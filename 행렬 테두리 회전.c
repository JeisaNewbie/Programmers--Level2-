#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int queue[396] = {0,};
int front = 1;
int rear = 0;
int x1, x2, y1, y2;

void reinit_arr(int **arr, int **queries, size_t i)
{
    for (int y_t = y1; y_t <= y2; y_t++)
         arr[x1][y_t] = queue[rear++];
    
    for (int x_t = x1 + 1; x_t <= x2; x_t++)
         arr[x_t][y2] = queue[rear++];
    
    for (int y_t = y2 - 1; y_t >= y1; y_t--)
         arr[x2][y_t] = queue[rear++];
    
    for (int x_t = x2 - 1; x_t >= x1 + 1; x_t--)
         arr[x_t][y1] = queue[rear++];
}

void init_queue(int **arr, int **queries, int *arr_s, size_t i)
{
    int smallest = queue[0] = arr[x1 + 1][y1];
    printf ("\nsmallest: %d\n", smallest);
    
    for (int y_t = y1; y_t <= y2; y_t++)
    {
        queue[front++] = arr[x1][y_t];
        if (smallest > queue[front - 1])
            smallest = queue[front - 1];
    }
    
    for (int x_t = x1 + 1; x_t <= x2; x_t++)
    {
        queue[front++] = arr[x_t][y2];
        if (smallest > queue[front - 1])
            smallest = queue[front - 1];
    }
    
    for (int y_t = y2 - 1; y_t >= y1; y_t--)
    {
        queue[front++] = arr[x2][y_t];
        if (smallest > queue[front - 1])
            smallest = queue[front - 1];
    }
    
    for (int x_t = x2 - 1; x_t > x1 + 1; x_t--)
    {
        queue[front++] = arr[x_t][y1];
        if (smallest > queue[front - 1])
            smallest = queue[front - 1];
    }
    arr_s[i] = smallest;
}

void init_xy (int **queries, size_t i)
{
    x1 = queries[i][0] - 1;
    x2 = queries[i][2] - 1;
    y1 = queries[i][1] - 1;
    y2 = queries[i][3] - 1;
}

int* solution(int rows, int columns, int **queries, size_t queries_row_len, size_t queries_col_len) {
    int *answer = (int*) calloc (queries_row_len, sizeof (int));
    int **arr = (int **) calloc (rows, sizeof (int *));

    for (int i = 0; i < rows; i++)
    {
        arr[i] = (int *)calloc (columns, sizeof (int));
        for (int j = 0; j < columns; j++)
            arr[i][j] = j + (columns * i) + 1;
    }
    
    for (size_t i = 0; i < queries_row_len; i++)
    {
        init_xy (queries, i);
        init_queue (arr, queries, answer, i);
        reinit_arr (arr, queries, i);
        front = 1;
        rear = 0;
    }

    return answer;
}
