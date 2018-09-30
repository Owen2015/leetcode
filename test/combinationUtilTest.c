#include "combinationUtil.h"
int main (int argc, char *argv[]) {
        int     v[100], n, k;

        if (argc != 3) {
                printf ("Usage: %s n k\n", argv[0]);
                exit (1);
        }
        n = atoi (argv[1]);
        k = atoi (argv[2]);

        /* generate all combinations of n elements taken
 *          * k at a time, starting with combinations containing 1
 *                   * in the first position.
 *                            */
	int size=combinationSize(n,k);
	int result[size][k];
	int* cnt;
	int cntValue=0;
	cnt=&cntValue;
//	combinations2(v,1,n,1,k,&result[0][0],cnt);
	combinations3(&result[0][0],1,n,1,k,cnt);

	//combinations2(v,1,n,1,k,&result[0][0]);

 //       combinations (v, 1, n, 1, k);
//	printf("\n permutationSize : %d.",permutationSize(n,k));
	printf("\n combinationSize : %d. \n",size);
//	printf(" %d, %d ，%d",result[0][0],result[0][1],result[0][2]);
	int i,j;
	for(i=0;i<size;i++){
		for(j=0;j<k;j++){
			printf(" %d ",result[i][j]);
		}
		printf("\n");
	}
        exit (0);

}
