#include "stdio.h"

/* �����̿����̴°�������Ѵ�. */
void Move(int n, int from, int to);

/* ��������Լ�*/
void Hanoi(int n, int from, int by, int to);

/* ���ð����Լ��׺�����*/
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

    printf("\n0 �����ǰ����Է��Ͻø�����������ϴ�.\n");
    while (1)
    {
        printf("\n�ϳ���ž�ǳ��̸��Է��ϼ���: ");
        scanf_s("%d", &i);

        if (i <= 0)
            break;

        /* i ���ǿ�������տ���������οű�*/
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