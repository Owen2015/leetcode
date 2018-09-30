typedef struct {
    int *arr;
    int *a_s;
    int size;
} Solution;

Solution* solutionCreate(int* nums, int size) {
    Solution* s=( Solution*)malloc(sizeof( Solution));
    s->arr=(int*)malloc(sizeof(int)*size);
    s->a_s=(int*)malloc(sizeof(int)*size);    
    s->size=size;
    memcpy(s->a_s,nums,(s->size)*sizeof(int));
    memcpy(s->arr,nums,(s->size)*sizeof(int));

    return  s;
}

/** Resets the array to its original configuration and return it. */
int* solutionReset(Solution* obj, int *returnSize) {
 
    *returnSize=obj->size;
    return obj->a_s;
}

/** Returns a random shuffling of the array. */
int* solutionShuffle(Solution* obj, int *returnSize) {
    
    srand(time(0));
    *returnSize=obj->size;

    for(int i=obj->size-1;i>0;--i){
        int tmp;
        int index=rand()%(i+1);
        tmp=obj->arr[index];
        obj->arr[index]=obj->arr[i];
        obj->arr[i]=tmp;
    }
    return obj->arr;
}

void solutionFree(Solution* obj) {
  
    free(obj->arr);
    free(obj->a_s);
    free(obj);
}
