#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<math.h>



int is_sorted(int *arr, int n){

    for(int i = 1; i <n; i++)
		if(arr[i -1] > arr[i])
	  		return 0;

    return 1;
}



void get_randnums(int *arr, int n, int radix){

	register int mod = (int)pow(2, radix);

	for(int i  = 0; i < n; i++){
	    arr[i] = rand() % mod;
	}
}

int bitmask(int n, int bit){
	int mask = ~((int)pow(2,bit));
	return !~(n|mask);
}

void bin_radsort(int **arr, int size, int radix){

	int *start, *end, *ptr;

	for(int i =0; i < radix; i++){
		start = arr[1];
		end = start + size -1;
		ptr = arr[0];

		for(int j = 0; j < size; j++){
			if(bitmask(*ptr, i)){
				*end = *ptr;
				end--; 
				ptr++;
			}
			else{
				*start = *ptr;
				start++;
				ptr++;
			}
		}
		ptr = arr[0];
		start = arr[1];

		while(start <= end){
			*ptr = *start;
			start++;
			ptr++;
		}
		end = arr[1] + size -1;

		while(end >= start){
			*ptr = *end;
			end--;
			ptr++;
		}
	}	
}


int main(void){

    srand(time(NULL));
    int n = 100000;
	int radix = sizeof(int) * 8;
	int **arr = malloc(sizeof(int*) *2);
	arr[0] = malloc(sizeof(int) * n);
	arr[1] = malloc(sizeof(int) * n);

	get_randnums(arr[0], n, radix);
	bin_radsort(arr, n, radix);
	
	if(is_sorted(arr[0], n)){
			printf("sorted");
	}
	else
		printf("oh no, problems");


    return 0;
}

