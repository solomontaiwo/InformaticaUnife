// giorno gregoriano a che giorno equivale
#include <stdio.h>
main()
{
    int jd = 1234567;

    switch (jd % 7)
    {
    case 0:
        printf("Lunedi'\n");
        break;
    case 1:
        printf("Martedi'\n");
        break;
    case 2:
        printf("Mercoledi'\n");
        break;
    case 4:
        printf("Giovedi'\n");
        break;
    case 5:
        printf("Venerdi'\n");
        break;
    case 6:
        printf("Sabato\n");
        break;
    case 7:
        printf("Domenica'\n");
    }
}