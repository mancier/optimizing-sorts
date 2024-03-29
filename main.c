//
// Created by victor on 19/10/2019.
//
#include <stdio.h>
#include <stdbool.h>
#include "BubbleSort/bubbleSort.h"
#include "QuickSort/quickSort.h"
#include "InsertionSort/insertionSort.h"
#include "SelectionSort/selectionSort.h"
#include "MergeSort/mergeSort.h"
#include "Utils/utils.h"

int main () {
    int option = 0;
    double time_consumed[2] = {0,0}; //[0] - Normal Algorithm; [1] - Optimized Algorithm
    bool suicide = false;
    int original_array[ARRAY_LENGTH];
    int vector[ARRAY_LENGTH];

    printf("Selecione uma opcao valida, logo abaixo: \n");
    printf("\t1 - Bubble Sort\n");
    printf("\t2 - Insertion Sort\n");
    printf("\t3 - Selection Sort\n");
    printf("\t4 - Merge Sort\n");
    printf("\t5 - Quick Sort\n");
    printf("\t6 - Run all (Suicide Mode)\n");

    //Creating the array and calculating his length
    creating_random_number_vector(original_array);
    recover_array(original_array, vector);

    printf("Entre com uma opcao: ");
    scanf("%d", &option);

    do {
        switch (option){
            case 1:
                //run bubbleSort
                time_consumed[0] = time_consuming(bubble_sort, vector);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming(bubble_sort_optimized, vector);
                recover_array(original_array, vector);
                results("Bubble Sort", time_consumed);
                break;
            case 2:
                print_array(vector);
                time_consumed[0] = time_consuming(insertion_sort, vector);
                print_array(vector);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming(insertion_sort_optimized, vector);
                recover_array(original_array, vector);
                results("Insertion Sort", time_consumed);
                break;
            case 3:
                time_consumed[0] = time_consuming(selection_sort, vector);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming(selection_sort_optimized, vector);
                recover_array(original_array, vector);
                results("Selection Sort", time_consumed);
                break;
            case 4:
                time_consumed[0] = time_consuming_with_three_params(merge_sort, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming_with_three_params(merge_sort_optimized, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                results("Merge Sort", time_consumed);
                //run mergeSort
                break;
            case 5:
                time_consumed[0] = time_consuming_with_three_params(quick_sort, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming_with_three_params(quick_sort_optimized, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                results("Quick Sort", time_consumed);
                break;
            case 6:
                //run bubbleSort
                time_consumed[0] = time_consuming(bubble_sort, vector);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming(bubble_sort_optimized, vector);
                recover_array(original_array, vector);
                results("Bubble Sort", time_consumed);

                //run insertSort
                time_consumed[0] = time_consuming(insertion_sort, vector);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming(insertion_sort_optimized, vector);
                recover_array(original_array, vector);
                results("Insertion Sort", time_consumed);

                //run selectionSort
                time_consumed[0] = time_consuming(selection_sort, vector);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming(selection_sort_optimized, vector);
                recover_array(original_array, vector);
                results("Selection Sort", time_consumed);

                //run mergeSort
                time_consumed[0] = time_consuming_with_three_params(merge_sort, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming_with_three_params(merge_sort_optimized, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                results("Merge Sort", time_consumed);

                //run quickSort
                time_consumed[0] = time_consuming_with_three_params(quick_sort, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                time_consumed[1] = time_consuming_with_three_params(quick_sort_optimized, vector, 0, ARRAY_LENGTH - 1);
                recover_array(original_array, vector);
                results("Quick Sort", time_consumed);
                break;
            default:
                printf("Opcao invalida, tente novamente");
                option = 0;
                break;
        }

        do{
            printf("\nDeseja repetir a ação? (1/0): ");
            scanf("%d", &option);
        } while(option == 0 || option == 1)
    } while (!option);
    return 0;
}
