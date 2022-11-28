#include "mergesort.h"
#include <cstdlib>


void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
	// Assume the two ranges are sorted.
	int rangesize = endIndex - startIndex + 1;
	int destination = (int*) calloc(rangesize, sizeof(int));
	int firstIndex = startIndex;
	int secondIndex = midPoint + 1;
	int copyIndex = 0;

	while((firstIndex <= midPoint) && secondIndex <= endIndex){
		if(values[firstIndex] < values[secondIndex]){
			destination[copyIndex] = values[firstIndex];
			++firstIndex;
		}else{
			destination[copyIndex] = values[secondIndex];
			++secondIndex;
		}
	++copyIndex;
	}

	while(firstIndex<=midPoint){
			destination[copyIndex] =  values[firstIndex];
			++firstIndex;
			++copyIndex;
	}

	while(secondIndex<=endIndex){
		destination[copyIndex] = values[secondIndex];
		++secondIndex;
		++copyIndex;
	}

	for (int i=0; i<rangesize; ++i) {
		values[i + startIndex] = destination[i];
	}
	free(destination);
}

void mergesortRange(int values[], int startIndex, int endIndex){
	int rangesize = (endIndex - startIndex) + 1;
	if(rangesize >= 2){
		int midPoint = (startIndex + endIndex)/2;
		mergesortRange(values, startIndex, midPoint);
		mergesortRange(values, midPoint + 1, endIndex);
		mergeRanges(values, startIndex, midPoint, endIndex);
	}
}



void mergesort(int size, int values[]) {
  mergesortRange(values, 0, size-1);
}

  // This obviously doesn't actually do any *sorting*, so there's
  // certainly work still to be done.
  //
  // Remember that a key goal here is to learn to use
  // `malloc/calloc` and `free`, so make sure you explicitly
  // allocate any new arrays that you need, even if you
  // might not strictly need to.


