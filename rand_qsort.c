#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>


void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


void uqsort(int *start, int *end, int *ops){
    //increment counter for number of recursive calls
	*ops += 1;
    if(end - start < 2)
	return;

    if(end - start == 2){
	if(*start > *(end-1)){
		swap(start, end-1);
	}
	return;
    }


    int *pivot_idx = rand() % (end - start) + start;
    int pivot = *pivot_idx;
    int *i = start + 1;
    int	*j = end - 1;

    swap(start, pivot_idx);

    while(j >= i){
	if(*j < pivot){
	    swap(i, j);
	    i++;
	}
	else{
		j--;
	}
    }

    swap(i-1, start);
    uqsort(start, i, ops);
    uqsort(i, end, ops);
}

void get_randnums(int *arr, int n){

	for(int i  = 0; i < n; i++){
	    arr[i] = rand() % n;
	}
}

int is_sorted(int *arr, int n){

    for(int i = 1; i <n; i++)
	if(arr[i -1] > arr[i])
	    return 0;

    return 1;
}

int sort_main(int n, int *ops){

	int arr[n];
	get_randnums(arr, n);

	uqsort(arr, arr + n, ops);

	if(is_sorted(arr, n))
		printf("The array was sorted in %d calls\n", *ops);
	
	else
	    printf("Array is not sorted... the fuck...\n");

	return 0;
}

int main(void){

    srand(time(NULL));
    int n = 100000;
    int reps = 10;
    int *ops_arr = malloc(sizeof(int) * reps);
	
    for(int i = 0; i < reps; i++){
		ops_arr[i] = 0;
    }

    for(int i = 0; i < reps; i++){
		sort_main(n, ops_arr + i);
    }

    for(int i = 0; i < reps; i++){
		printf("%d ", ops_arr[i]);
    }

    return 0;
}

