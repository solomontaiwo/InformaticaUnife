#include <stdio.h>

int main()
{
    char s1[] = "voltare";
    char s2[] = "sterzare";
    int i;

    for (i = 0; s1[i]; i++)
    {
        s2[i + 1] = s1[i];
    }
    printf("%s\n", s2);
}