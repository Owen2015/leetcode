
void main(int argc, char* argv[]){
	int ** p, i,m,n;
	p = (int **)malloc( sizeof(int*) * 5 );    //也可以为p=(int **)malloc(sizeof(int)*5);
	for( i=0; i<5; i++ )
	{
		p[i] = (int *)malloc( sizeof(int) * 6 );
	}


	for( m=0; m<5;m++){
		for( n=0; n<6; n++){
			p[m][n] = 1;
		}
	}


	for( m=0; m<5;m++){
		for(n=0; n<6; n++){
			printf("%d ", p[m][n]);
		}
		printf("%\n");
	}
}
