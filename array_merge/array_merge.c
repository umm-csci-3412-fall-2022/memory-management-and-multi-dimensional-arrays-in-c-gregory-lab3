#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <cstdlib>
#include <stdio.h>

int totalNumElements(int* sizes, int num_arrays){
        int count = 0;
        for(int i=0; i<num_arrays; ++i){
                count = (count + sizes[i]);
                }
        return count;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
        int size = totalNumElements(sizes, num_arrays);

        if(num_arrays == 0){
                int* emptyArray = (int*) calloc(1, sizeof(int));
                emptyArray[0] = 0;
                return emptyArray;
                }

        int currentArraySize = 0;
        int currentIndex = 0;
        int* temp =(int*)calloc(size, sizeof(int));


        for (int i=0; i<num_arrays; ++i){
                currentArraySize = sizes[i];
                for (int j=0; j<currentArraySize; ++j){
                        temp[currentIndex]= values[i][j];
                        ++currentIndex;
                }
        }
        // Mergesort it, count the number of nonduplicates to know the size of the final array, and then 
        // only add nonduplicates to final array.
        mergesort(currentIndex, temp);

        int nonDuplicates = 1;
        int currentNonDuplicate = temp[0];
        for(int f=0; f<size; ++f){
                if(currentNonDuplicate != temp[f]){
                        currentNonDuplicate = temp[f];
                        nonDuplicates++;
                }
        }


        // To create a slot for k, the total number of elements.

        int* dArray = (int*) calloc(nonDuplicates+1, sizeof(int));
        // Start by adding the number of non duplicates to the array and the first non duplicate element.
        dArray[0] = nonDuplicates;
        dArray[1] = temp[0];
        currentNonDuplicate = temp[0];
        int index = 2;

        for(int f=1; f<size; ++f){
                if(currentNonDuplicate != temp[f]){
                        currentNonDuplicate = temp[f];
			dArray[index] = temp[f];
                        index++;
                }
        }
        free(temp);
        return dArray;
}
