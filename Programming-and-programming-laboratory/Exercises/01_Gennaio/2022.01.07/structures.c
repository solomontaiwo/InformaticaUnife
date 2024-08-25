#include <stdio.h>

struct corso
{
    int id;
    char titolo[40];
    float ore;
};

int main(void)
{
    struct corso cs1 = {59746, "Programmazione", 22.5};
    struct corso cs2 = {85214, "Matematica", 18.5};

    printf("Il corso di %s ha il numero di id pari a %d e dura %.1f\n", cs1.titolo, cs1.id, cs1.ore);

    printf("Il corso di %s ha il numero di id pari a %d e dura %.1f\n", cs2.titolo, cs2.id, cs2.ore);
}

/* VALIDO ANCHE NEL SEGUENTE MODO

typedef struct
{
    int id;
    char titolo[40];
    float ore;
} corso;

int main(void)
{
    corso cs1 = {59746, "Programmazione", 22.5};
    corso cs2 = {85214, "Matematica", 18.5};

    printf("Il corso di %s ha il numero di id pari a %d e dura %.1f\n", cs1.titolo, cs1.id, cs1.ore);

    printf("Il corso di %s ha il numero di id pari a %d e dura %.1f\n", cs2.titolo, cs2.id, cs2.ore);
} 
*/