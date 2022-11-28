#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdlib>

int adduparray(int* sizes){
	int count = 0;
	for(int i=1; i<=num_arrays; ++i){
		count = (count + sizes[i]);
				}

int* array_merge(int num_arrays, int* sizes, int** values) {
  	int resultsize = adduparray(sizes);

	int* result = (int*) calloc(resultsize, sizeof(int));

	int currentarraysize = 0;
	result[0] =  num_arrays;

	for (int i=1; i<num_arrays; ++i){
		currentarraysize = sizes[i];
		for(int j=1; j<=num_arrays; ++j){
			if(isDuplicate())

  return result;
}

bool isDuplicate(int num, int* mergingarray){
	if(num == mergingarray[i]){
		return true;
	}
