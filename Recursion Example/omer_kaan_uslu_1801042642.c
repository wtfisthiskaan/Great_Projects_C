#include<stdio.h>
#include<string.h>

void create_trees(char input[250],int count,int minuscount,int minuscontrol,char output[250][250],int row,int column) {
	/*ending condition of recursion function */
	if(count==strlen(input)) {
		output[row+1][0]='(';
    return ;
	}
	char a;
	int i;
	a=input[count];
	
	/*if '(' character comes, minuscount increases by one. Because every '(' comes, number of '-' s at the beggining increases one. */
	if(a=='(') {
		create_trees(input,count+1,minuscount+1,0,output,row,column);
	}
	/* if ')' character comes, then minuscount decreases one. */
	else if(a==')') {
		create_trees(input,count+1,minuscount-1,0,output,row,column);
	}
	else if(a==',') {
		//fprintf(fptr,"\n");
		create_trees(input,count+1,minuscount,0,output,row+1,0);
	}
	/* minuscontrol checks whether is first character of node's string going to be written. if it is, then writes '-' characters before. */
	else{
		if(minuscontrol==0) {
			for(column=0;column<minuscount;column++)
			output[row][column]='-';
		}
		output[row][column]=a;
		create_trees(input,count+1,minuscount,1,output,row,column+1);
	}
}



int main() {
	/* defining variables which is going to be used */
	int j;
	char input[250];
	char output[250][250];
	for(j=0;j<250;j++)
	memset(output[j],'\0',250);
	FILE *fptr=fopen("input.txt","r");
	FILE *foutptr=fopen("output.txt","w");
	int i;
	char a;
	int row=0;
	/*getting string from input file */
	fgets(input,250,fptr);
	/* checking input file's beggining and end whether those are ' ' character. */
	if(input[0]==' ') {
		for(i=0;i<strlen(input);i++) 
			input[i]=input[i+1];
	}
	if(input[strlen(input)-1]=='\n')
	input[strlen(input)-1]='\0';
	if(input[strlen(input)-1]==' ')
	input[strlen(input)-1]='\0';
	/* calling recursion function */
	create_trees(input,0,0,0,output,row,0);
  	/* writing array in to file */
	for(i=0;i<250;i++) {
    fputs(output[i],foutptr);
     if(output[i+1][0]=='(')
    	break;
    fputc('\n',foutptr);
  }
	fclose(fptr);
	fclose(foutptr);
	
}
