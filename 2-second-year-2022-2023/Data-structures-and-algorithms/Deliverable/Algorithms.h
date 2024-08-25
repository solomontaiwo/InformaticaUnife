#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum
{
    IS,
    MS,
    HS,
    QS,
    RS,
    M3QS,
    TRQS,
    OPTRQS
} alg;

void CopyFromL(int *i, int array[], int L[], int k);
void CopyFromR(int *j, int array[], int R[], int k);
int MedianOfThreePartition(int array[], int p, int r);
void OptimalTailQuickSort(int array[], int p, int r);
void Merge(int array[], int p, int q, int r);
void MergeSort(int array[], int p, int r);
void AdaptedInsertionSort(int array[], int p, int r);
void HybridSort(int array[], int p, int r);
void GenerateRandomArray(int array[], int length);
void InsertionSort(int array[], int length);
float SingleExperiment(int length, int max_instances, alg option);
int Experiment(int min_length, int max_length);
int Partition(int array[], int p, int r);
int isOrdered(int array[], int length);
void QuickSort(int array[], int p, int r);
void RandomizedQuickSort(int array[], int p, int r);
void MedianOfThreeQuickSort(int array[], int p, int r);
void TailQuickSort(int array[], int p, int r);
