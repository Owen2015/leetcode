long factorial(int n){
        if(n<=1) return 1;
        else return factorial(n-1)*n;
}
long factorialIterate(int n){
        int i;
        long result=1;
        if(n==0) return 1;
        for(i=n;i>=1;i--)
                result=result*i;
        return result;
}
long factorial(int n,int m){
        long result=1;
        int i;
        if(m<1) m=1;
        for(i=n;i>m;i--)
                result=result*i;
        return result;
}

long permutationSize(int n,int m){
        return factorial(n,n-m);
}

int combinationSize(int n,int m){
        return permutationSize(n,m)/permutationSize(m,m);
}
void combinations2 (int v[], int start, int n, int k, int maxk,int * result,int* cnt) {
        int     i;
        /* k here counts through positions in the maxk-element v.
            * if k > maxk, then the v is complete and we can use it.
                               */
        if (k > maxk) {
                /* insert code here to use combinations as you please */
                for (i=1; i<=maxk; i++) {
                        *(result+maxk*(*cnt)+(i-1))=v[i];
                }
                *cnt=*cnt+1;
                return;
        }
        /* for this k'th element of the v, try all start..n
            * elements in that position
                               */
        for (i=start; i<=n; i++) {
                v[k] = i;
                /* recursively generate combinations of integers
                    * from i+1..n
                                                       */
                combinations2 (v, i+1, n, k+1, maxk,result,cnt);
        }
}

void combinations (int v[], int start, int n, int k, int maxk) {
        int     i;

        /* k here counts through positions in the maxk-element v.
 *           * if k > maxk, then the v is complete and we can use it.
 *                              */
        if (k > maxk) {
                /* insert code here to use combinations as you please */
                for (i=1; i<=maxk; i++) printf ("%i ", v[i]);
                printf ("\n");
                return;
        }

        /* for this k'th element of the v, try all start..n
 *           * elements in that position
 *                              */
        for (i=start; i<=n; i++) {

                v[k] = i;

                /* recursively generate combinations of integers
 *                   * from i+1..n
 *                                                      */
                combinations (v, i+1, n, k+1, maxk);
        }
}

/* Given a collection of distinct integers, return all possible permutations.
 * Input: [1,2,3]
 * Output:
 * [[],[],...]
 */
int ** permute(int* nums, int numsSize, int* returnSize){

}
