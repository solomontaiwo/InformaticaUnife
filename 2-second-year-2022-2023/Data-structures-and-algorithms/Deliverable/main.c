#include "Algorithms.h"

int main()
{
    Experiment(10, 1000);
    return 1;
}

int Experiment(int min_length, int max_length)
{
    char *filename = "algos-experiment.txt";
    FILE *fp = fopen(filename, "w");
    if (fp == NULL)
    {
        printf("Error opening the file %s\n", filename);
        return -1;
    }

    int max_instances = 10;
    int step = 5;
    int length = 0;
    float timeIS = 0;
    float timeMS = 0;
    float timeQS = 0;
    float timeRS = 0;
    float timeHS = 0;
    float timeM3QS = 0;
    float timeTRQS = 0;
    float timeOPTRQS = 0;

    printf("Time\t     timeIS, timeMS,   timeHS, timeQS,   timeRS,  timeM3QS, timeTRQS, timeOPTRQS\n");
    fprintf(fp, "Time\t     timeIS, timeMS,   timeHS, timeQS,   timeRS,  timeM3QS, timeTRQS, timeOPTRQS\n");

    for (length = min_length; length <= max_length; length = length + step)
    {
        srand(13); // reset seed
        timeIS = SingleExperiment(length, max_instances, IS);

        srand(13);
        timeMS = SingleExperiment(length, max_instances, MS);

        srand(13);
        timeHS = SingleExperiment(length, max_instances, HS);

        srand(13);
        timeQS = SingleExperiment(length, max_instances, QS);

        srand(13);
        timeRS = SingleExperiment(length, max_instances, RS);

        srand(13);
        timeM3QS = SingleExperiment(length, max_instances, M3QS);

        srand(13);
        timeTRQS = SingleExperiment(length, max_instances, TRQS);

        srand(13);
        timeOPTRQS = SingleExperiment(length, max_instances, OPTRQS);

        fprintf(fp, "Length: %d : %f ", length, timeIS);
        fprintf(fp, "%f ", timeMS);
        fprintf(fp, "%f ", timeHS);
        fprintf(fp, "%f ", timeQS);
        fprintf(fp, "%f ", timeRS);
        fprintf(fp, "%f ", timeM3QS);
        fprintf(fp, "%f ", timeTRQS);
        fprintf(fp, "%f ", timeOPTRQS);
        fprintf(fp, "\n");
        printf("Length: %d : %f %f %f %f %f %f %f %f\n", length, timeIS, timeMS, timeHS, timeQS, timeRS, timeM3QS, timeTRQS, timeOPTRQS);
    }

    fclose(fp);
    return 1;
}

float SingleExperiment(int length, int max_instances, alg option)
{
    int t_tot = 0;
    long int t_start = 0;
    long int t_end = 0;
    long int t_elapsed = 0;
    int ordered;
    int A[length];

    for (int i = 1; i <= max_instances; i++)
    {
        GenerateRandomArray(A, length);

        switch (option)
        {
        case 0:
            t_start = clock();
            InsertionSort(A, length);
            t_end = clock();
            break;
        case 1:
            t_start = clock();
            MergeSort(A, 0, length);
            t_end = clock();
            break;
        case 2:
            t_start = clock();
            HybridSort(A, 0, length);
            t_end = clock();
            break;
        case 3:
            ordered = isOrdered(A, length);
            t_start = clock();
            QuickSort(A, 0, length);
            t_end = clock();
            ordered = isOrdered(A, length);
            break;
        case 4:
            ordered = isOrdered(A, length);
            t_start = clock();
            RandomizedQuickSort(A, 0, length);
            t_end = clock();
            ordered = isOrdered(A, length);
            break;
        case 5:
            ordered = isOrdered(A, length);
            t_start = clock();
            MedianOfThreeQuickSort(A, 0, length);
            t_end = clock();
            ordered = isOrdered(A, length);
            break;
        case 6:
            ordered = isOrdered(A, length);
            t_start = clock();
            TailQuickSort(A, 0, length);
            t_end = clock();
            ordered = isOrdered(A, length);
            break;
        case 7:
            ordered = isOrdered(A, length);
            t_start = clock();
            OptimalTailQuickSort(A, 0, length);
            t_end = clock();
            ordered = isOrdered(A, length);
            break;
        default:
            printf("Error\n");
            break;
        }

        t_elapsed = (t_end - t_start);
        t_tot = t_tot + t_elapsed;
    }

    return (t_tot / max_instances);
}
