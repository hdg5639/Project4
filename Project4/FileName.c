#include "stdio.h"

/* 원반이움직이는것을출력한다. */
void Move(int n, int from, int to);

/* 실제재귀함수*/
void Hanoi(int n, int from, int by, int to);

/* 스택관련함수및변수들*/
#define MAX 100
int Stack[MAX];
int sp;
void InitStack();
void Push(int data);
int Pop();
int IsEmpty();


int main()
{
    int i = 0;

    printf("\n0 이하의값을입력하시면게임을끝냅니다.\n");
    while (1)
    {
        printf("\n하노이탑의높이를입력하세요: ");
        scanf_s("%d", &i);

        if (i <= 0)
            break;

        /* i 개의원반을기둥에서기둥으로옮김*/
        Hanoi(i, 1, 2, 3);
    }

    return 0;
}

void Move(int n, int from, int to)
{
    printf("Move %d from %d to %d\n", n, from, to);
}

void Hanoi(int n, int from, int by, int to)
{
    int bContinue = 1;
    InitStack();

    while (bContinue)
    {
        while (n > 1)
        {
            Push(to);
            Push(by);
            Push(from);
            Push(n);
            n--;
            Push(to);
            to = by;
            by = Pop();
        }
        Move(n, from, to);
        if (!IsEmpty())
        {
            n = Pop();
            from = Pop();
            by = Pop();
            to = Pop();
            Move(n, from, to);
            n--;
            Push(from);
            from = by;
            by = Pop();
        }
        else
            bContinue = 0;
    }
}

void InitStack()
{
    sp = -1;
}

void Push(int data)
{
    if (sp >= MAX - 1)
    {
        printf("Stack overflow!!!\n");
        return;
    }

    Stack[++sp] = data;
}

int Pop()
{
    if (sp < 0)
    {
        printf("Stack is already empty!!!\n");
        return 0;
    }

    return Stack[sp--];
}

int IsEmpty()
{
    if (sp < 0)
        return 1;
    else
        return 0;
}