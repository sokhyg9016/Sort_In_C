#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Set Arr's Length*/
#define ARR_RANGE 100

/*Set Random value's range*/
#define MAX_SIZE 200

/*Store Array random value*/
#define MKDAT() {srand((int)time(NULL)); for (i = 0; i < ARR_RANGE; i++){ arr[i] = (rand() % MAX_SIZE)+1; }}

//PRINT
#define PRINT() {for(i = 0; i < ARR_RANGE; i++){printf("%d, ", arr[i]);} puts("");}

//SWAP
#define SWAP(a, b) { int tmp = a; a = b; b = tmp;}

//TIME VARIABLE
static double tstart;

//CALCULATE TIME
void tic();
double toc();

//SORT ALGORITHMS
void bubble_sort(int arr[], int N);
void selection_sort(int arr[], int N);
void insertion_sort(int arr[], int N);
void shell_sort(int arr[], int N);
void heap_sort(int data[], int heap_size);
void quick_sort(int arr[], int left, int right);

int find_min(int arr[], int current, int N);
void downheap(int data[], int cur, int end);
int partition(int arr[], int left, int right);

void Sort(int sort_num);