#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "../Utils/utils.h"

int partition (int *arr, int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot) 
		{ 
			i++;
            swap(&arr[i], &arr[j]);
        }
	} 
	swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int *arr, int low, int high)
{
    if (low <= high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int partition_three_ways (int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        } else if(arr[j] == pivot){
            i++;
            swap(&arr[j], &arr[i + 1]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort_optimized(int *arr, int low, int high)
{
    if (low <= high)
    {
        int pi = partition_three_ways(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}