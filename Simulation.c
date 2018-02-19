#include <stdio.h>
#include <stdlib.h>
int masks[10] = {252, 24, 364, 316, 408, 436, 500, 28, 508, 444};
void Print_H()
{
    int i;

    for (i = 0; i < 3; i++)
        printf(" -");
    printf("\n");
}
void Print_V(char *s)
{
    int i;
    for (i = 0; i < 3; i++)
        printf("%s\n", s);
}
void draw(int mask)
{
    if (mask & (1 << 2))
        Print_H();
    if ((mask & (1 << 3)) && (mask & (1 << 7)))
        Print_V("|     |");
    else if (mask & (1 << 7))
        Print_V("|");
    else if (mask & (1 << 3))
        Print_V("      |");
    if (mask & (1 << 8))
        Print_H();
    if ((mask & (1 << 6)) && (mask & (1 << 4)))
        Print_V("|     |");
    else if (mask & (1 << 6))
        Print_V("|");
    else if (mask & (1 << 4))
        Print_V("      |");
    if (mask & (1 << 5))
        Print_H();
}
int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n%d\n", i, masks[i]);
        int j;
        for (j = 0; j < 9; j++)
            if (masks[i] & (1 << j))
                printf("1 ");
            else
                printf("0 ");
        printf("\n");
        draw(masks[i]);
    }
    return 0;
}
