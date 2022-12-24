#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char queue[27] = {0,};

void init_queue (const char* skills)
{
    for (int i = 0; skills[i] != 0; i++)
        queue[i] = skills[i];
}

bool is_in (char skill) //스킬트리중 해당 스킬이 있는지 확인하는 함수
{
    for (int i = 0; queue[i] != 0; i++)
    {
        if (queue[i] == skill)
            return true;
    }
    return false;
}

bool dequeue (char skill) //큐의 첫번째 인덱스에 스킬이 있으면 빼고 없으면 리턴
{
    if (queue[0] == skill)
    {
        for (int i = 0; queue[i] != 0; i++)
            queue[i] = queue[i + 1];
        return true;
    }
    return false;
}

void is_possible (const char* skill_trees, int *answer)
{
    int check = 0;
    for (int i = 0; skill_trees[i] != 0; i++)
    {
        if (is_in (skill_trees[i])) //스킬트리 안에 해당 스킬이 존재하는지 확인
        {
            if (!dequeue(skill_trees[i])) // 첫번째 인덱스에 스킬이 없으면 리턴
                return ;
        }
    }
    (*answer)++;
}

int solution(const char* skill, const char* skill_trees[], size_t skill_trees_len) {
    int answer = 0;
    int skill_idx = 0;
    init_queue(skill);
    
    for (size_t i = 0; i < skill_trees_len; i++)
    {
        is_possible (skill_trees[i], &answer);
        init_queue(skill);
    }
    
    return answer;
}
