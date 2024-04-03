#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define TRUE 1

void input(int*, int);
void display(int*, int, const char*);
void quicksort(int*, int ,int);
int partition(int*a, int ,int); 



void main()
{
    int* arr = NULL; 
    int N; 
    time_t start_time, end_time, delta_time;

    puts("Enter Array Size : ");
    scanf("%d", &N);

    if(N < 0)
    {
        puts("Invalid Array Size...");
        exit(EXIT_FAILURE);
    }

    arr = (int*)malloc(N * sizeof(int));

    if(arr == NULL)
    {
        puts("Memory Allocation Error...");
        exit(EXIT_FAILURE);
    }

    input(arr, N);

    display(arr, N, "Before quicksort...");

    start_time = time(0);

    quicksort(arr, 0, (N-1));

    end_time = time(0);

    delta_time = end_time - start_time;

    printf("Total Time Elapsed : %ld\n", delta_time);

    display(arr, N, "After quicksort...");

    free(arr);
    arr = NULL;

    exit(EXIT_FAILURE);

}

void input(int* arr, int N)
{
    int i;
    srand(time(0));

    for(i = 0 ; i < N ; i++)
    {
        arr[i] = rand();
    }
}

void display(int* arr, int N, const char* msg)
{
    int i;

    if(msg != NULL)
        puts(msg);

    for(i = 0 ; i < N ; i++)
        printf("%d  ", arr[i]);

    puts("");
}

void quicksort(int*a,int p,int r)
{
    int q;
    if (p<r)
    {
        q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }

}

int partition(int* a, int p,int r)
{
    int i=p-1;
    int pivot=a[r];
    int j,temp;

    for(j=p; j<r; j++)
    {
        if(a[i]<pivot)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;

    return (i+1);
}