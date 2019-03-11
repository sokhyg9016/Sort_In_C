#pragma once
#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*Swap Array's element*/
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

/*Define Array Size*/
#define MAX_SIZE 10

// Pauses for a specified number of milliseconds.
void do_sleep(clock_t wait);

/*Selection Sort*/
void selection_sort(int arr[], int n);
void selection_sort_recursive(int arr[], int start, int n);

/*Bubble Sort*/
void bubble_sort(int arr[], int n);

/*Insertion Sort*/
void insertion_sort(int arr[], int n);

/*Quick Sort*/
int partition(int arr[], int start, int end);
void quick_sort(int arr[], int start, int end);

/*Merge Sort*/
void merge(int arr[], int temp[], int start, int mid, int end);
void merge_sort_implement(int arr[], int temp[], int start, int end);
void merge_sort(int arr[], int start, int end);

/*Merge Sort for Practice*/
void merge_u(int arr[], int temp[], int start, int mid, int end);
void merge_sort_u(int arr[], int temp[], int start, int end);

/*Heap Sort*/

/*Radix Sort*/


/*Test Sort Function.*/
void Test(const char* sort_type);
