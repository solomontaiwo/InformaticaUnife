#define DIMENSIONE 1000

typedef struct
{
    char nome[31];
    float calorie;
} Alimento;

typedef struct
{
    int n_elementi; // dimensione logica
    Alimento dati[];
} Lista;

void caricaCalorie(char nomeFileBinario[], Lista *pl);
float calorieAlimento(char nomeAlimento[], Lista l);