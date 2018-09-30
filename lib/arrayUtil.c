# include <math.h>

void removeElementByIndex(int* nums,int numsSize,int index){
	int i;
	for(i=0;i<numsSize;i++){
		if(i>index){
			nums[i-1]=nums[i];	
		}
	}
}


void swap(int * nums,int firstIndex,int lastIndex){
	int temp;
	temp=nums[firstIndex];
	nums[firstIndex]=nums[lastIndex];
	nums[lastIndex]=temp;
}

void removeDuplicates(int* nums,int* size){
	int i,j,k;

	for(i=0;i<*size;i++){
		for(j=i+1;j<*size;j++){
			if(nums[i]==nums[j]){
				for(k=j+1;k<*size;k++){
					nums[k-1]=nums[k];
				}
			(*size)--;
			j--;

			}
		}
	}
}
void insertSort(int* nums,int size){
	if(size<=0)return;
	int min;
	int index;
	int tmp;
	int i,j;
	for(i=0;i<size;i++){
		min=nums[i];
		index=i;
		for(j=i+1;j<size;j++){
			if(nums[j]<min){
				min=nums[j];
				index=j;
			}
		}	
		if(index!=i){
			tmp=nums[i];
			nums[i]=nums[index];
			nums[index]=tmp;
		}
	}
}

void quicksort(int *array, int n){
    if(n>1){
        int pivot=0,j;
        for(j=1;j<n;j++)
            if(array[j]<array[0])
                swap(array,++pivot,j);
        swap(array,0,pivot);
        quicksort(array,pivot);
        quicksort(array+pivot+1,n-pivot-1);
    }
}

int isSame(int* nums1,int* nums2,int size){
	int i;
	for(i=0;i<size;i++){
		if(nums1[i]!=nums2[i]){
			return 0;
		}
	}
	return 1;	
}

