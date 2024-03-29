#include <stdio.h>
#include <stdlib.h>

int x[10][10];

void ghinhan(){
	int r,c;
	for(r=1;r<10;r++){
		for(c=1;c<10;c++){
			printf("%d ",x[r][c]);
		}
		printf("\n");
	}
	
	printf("------------------------\n");
	exit(1);
}

int check(int ucv,int r, int c){
	for(int i = 1; i <= r-1; i++)
		if(x[i][c] == ucv) return 0;
	for(int j = 1; j <= c-1; j++)
		if(x[r][j] == ucv) return 0;

	int I = (r-1)/3;
	int J = (c-1)/3;
	int i = r - 1 - 3*I;
	int j = c - 1 - 3*J;
	
	for(int i1 = 0; i1 <= i-1; i1++)
		for(int j1 = 0; j1 <= 2; j1++)
			if(x[3*I+i1+1][3*J+j1+1] == ucv)
				return 0;
	
	for(int j1 = 0; j1 <= j-1; j1++)
		if(x[3*I+i+1][3*J+j1+1] == ucv)
			return 0;
			
	return 1;
}

void Try(int r, int c){//loi giai cap k = r*c
	for(int ucv = 1; ucv <= 9; ucv++){
		if(check(ucv,r,c)==1){
			x[r][c]=ucv;
			
			if((r==9)&&(c==9)) ghinhan();
			
			if(c == 9) Try(r+1,1);
			else Try(r,c+1);
		}
	}
}


int main(){
	
	Try(1,1);

	return 1;
}
