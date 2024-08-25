#include <stdio.h>

int main()
{
    for (double y = .1; y <= 1.0; y += .1)
    {
        printf("%.1f\n", y);
    }
}