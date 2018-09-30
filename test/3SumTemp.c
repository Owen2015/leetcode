long  factorial2(int n,int m){

    long result=1;
    if(n<=1) return 1;
    int i;
    if(m<1) m=1;
    for(i=n;i>m;i--)
        result=result*i;
    return result;
}
long permutationSize(int n,int m){
        return factorial2(n,n-m);
}

int combinationSize(int n,int m){
        return permutationSize(n,m)/permutationSize(m,m);
}

void combinations2 (int v[], int start, int n, int k, int maxk,int * result,int* cnt) {
        int     i;
        if (k > maxk) {
                for (i=1; i<=maxk; i++) {

                        *(result+maxk*(*cnt)+(i-1))=v[i];
                }
                *cnt=*cnt+1;

                return;
        }
        for (i=start; i<=n; i++) {
                v[k] = i;
                combinations2 (v, i+1, n, k+1, maxk,result,cnt);
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

int isSame(int* nums1,int* nums2,int size){
        int i;
        for(i=0;i<size;i++){
                if(nums1[i]!=nums2[i]){
                        return 0;
                }
        }
        return 1;
}


void removeDuplicateArrays(int** nums,int* size){
        int i,j,k;

        for(i=0;i<*size;i++){
                for(j=i+1;j<*size;j++){
                        if(isSame(nums[i],nums[j],3)){
                                for(k=j+1;k<*size;k++){
                                        nums[k-1]=nums[k];
                                }
                        (*size)--;
                        j--;

                        }
                }
        }
}

int** threeSum(int* nums, int numsSize, int* returnSize) {

        if(numsSize<=2) return 0;
    int i;
    int l=0;
        l=combinationSize(numsSize,3);

    int index[l][3];
    int v[3];
    int cnt=0;
    int *cntp=&cnt;
    *returnSize=0;
    int num=0;
   int** p;
        p=(int**)malloc(sizeof(int*)*l);
        for(i=0;i<l;i++)
                p[i]=(int*)malloc(sizeof(int)*3);
    combinations2(v,1,numsSize,1,3,&index[0][0],cntp);

    for(i=0;i<l;i++){
        if((nums[index[i][0]-1]+nums[index[i][1]-1]+nums[index[i][2]-1])==0){
            p[num][0]=nums[index[i][0]-1];
            p[num][1]=nums[index[i][1]-1];
            p[num][2]=nums[index[i][2]-1];     
            insertSort(p[num],3);
            num=num+1;
        }
    }
    removeDuplicateArrays(p,&num);
    *returnSize=num;
    return p;

}
