#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// A_len은 배열 A의 길이입니다.
// B_len은 배열 B의 길이입니다.
int solution(int A[], size_t A_len, int B[], size_t B_len) {
    int answer = 0;
    int arr_a[1001] = {0,};
    int arr_b[1001] = {0,};
    int a = 1; //
    int b = 1000;
    int count = 0;
    
    for (size_t i = 0; i < A_len; i++) //A 안의 값에 해당하는 인덱스에 1 증가. 중복된 값일경우를 대비해서 ++ 연산자 사용.
        arr_a[A[i]]++;

    for (size_t i = 0; i < B_len; i++)
        arr_b[B[i]]++;
    
    while (count < A_len)
    {
        if (arr_a[a] || arr_b[b]) //최솟값과 최댓값을 곱하기 위해 a는 1부터, b는 1000부터 시작.
        {
            while (arr_a[a] && !arr_b[b]) //최솟값을 먼저 찾았을때 최댓값을 마저 찾기위함
                arr_b[b--];
            while (arr_b[b] && !arr_a[a]) //위와 반대
                arr_a[a++];
            answer += a * b;
            if (arr_a[a]) //중복일수도 있으니 arr_a-- 해줌. a--의 이유는 중복일 경우 한번더 해당 인덱스를 찾기위함.
                arr_a[a--]--;
            if (arr_b[b])
                arr_b[b++]--;
            count++;
        }
        a++;
        b--;
    }

    return answer;
}
