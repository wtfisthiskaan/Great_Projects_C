#include<stdio.h>
#define MAX_NUMBER 512

int find_islands(int terrain[MAX_NUMBER][MAX_NUMBER],int row,int column) {
	if(row<0||column<0||row>=MAX_NUMBER||column>=MAX_NUMBER)
	return 0;
	if(terrain[row][column]==-2)
	return 0;
	if(terrain[row][column]==-1) {
		terrain[row][column]=-2;
		find_islands(terrain,row,column+1); //right
		find_islands(terrain,row+1,column); //down
		find_islands(terrain,row,column-1); //left
		find_islands(terrain,row-1,column); //up
    return 1;
	}
}

int main() {
	FILE *finptr=fopen("input.txt","r");
	FILE *foutptr=fopen("output.txt","w");
	int level,i,j;
	int terrain[MAX_NUMBER][MAX_NUMBER];
	int a;
	int coordinates[100][2];
	int count=0;
	fscanf(finptr,"%d",&level);
	/* meaning of element being -1 is land.  -2 is underwater. */
	for(i=0;i<MAX_NUMBER;i++) {
		for(j=0;j<MAX_NUMBER;j++){
		fscanf(finptr,"%d",&a);
		if(a>level)
		terrain[i][j]=-1;
		else 
		terrain[i][j]=-2;
		}	
	}
	
	for(i=0;i<MAX_NUMBER;i++) {
		for(j=0;j<MAX_NUMBER;j++){
			if(find_islands(terrain,i,j)==1) {
				coordinates[count][0]=i;
				coordinates[count][1]=j;
				count++;
			}
		}	
	}
	
	fprintf(foutptr,"%d\n",count);
	for(i=0;i<count;i++)
	fprintf(foutptr,"x_coordinate%d y_coordinate%d\n",coordinates[i][0],coordinates[i][1]);
	fclose(finptr);
	fclose(foutptr);
}
	
	
	
	

