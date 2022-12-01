#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdlib>

int totalNumElements(int* sizes, int num_arrays){
	int count = 0;
	for(int i=0; i<num_arrays; ++i){
		count = (count + sizes[i]);
		}
}

bool notDuplicate(int num, int* resultArray, currentResultIndex){
	bool boole = true
	for(int i=0; i<=currentResultIndex; ++i){
		if(num == mergingarray[i]){
		boole = false
		}
	}
	return boole;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  	int resultSize = totalNumElements(sizes, num_arrays);

	int* result = (int*) calloc(resultSize, sizeof(int));

	int currentArraySize = 0;
	int currentResultIndex = 0;

	for (int i=0; i<num_arrays; ++i){
		currentArraySize = sizes[i];
		for (int j=0; j<currentArraySize; ++j){
			if(notDuplicate(values[i][j], result, currentResultIndex)){
				result[currentResultIndex]= values[i][j];
				currentResultIndex++
				}
		}
	}
	// Resize according to how many nonduplicates were added +1 slot for the num of non duplicate elements.
	int* finalResult = (int*) calloc(currentResultIndex+1, sizeof(int));
	finalResult[0] = currentResultIndex+1;

	for(int i=0, i<=currentResultIndex; ++i){
		finalResult[i+1] = result[i];
	}
	return finalResult;
}
