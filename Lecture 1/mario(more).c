#include <cs50.h>
#include <stdio.h>

int h;
void print_bow(int spaces, int bricks);
int main(void)
{
    do
    {
        h = get_int("金字塔高度: ");
    }
    while (h < 1 || h > 8);

    for (int i = 0; i < h; i += 1)
    {
        print_bow(h - i, i + 1);
    }
}

void print_bow(int spaces, int bricks)
{
    for (int i = 1; i < spaces; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("  ");
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
