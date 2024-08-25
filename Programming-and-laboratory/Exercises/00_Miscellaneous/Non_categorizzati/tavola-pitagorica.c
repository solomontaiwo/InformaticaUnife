#include  <stdio.h>
main() {
int i, j;

for (i = 1; i <= 10; i++) {
    for (j = 1; j <= 10; j++) {
        printf("%3d", i * j);
        if (i * j > 50)
break
        ;
    }
    printf("\n");
}
printf("Finito\n");
}