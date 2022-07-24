#include<stdio.h>
#include<math.h>
#include<string.h>

int find_power(char buffer[100]) { /*this function takes char buffer from main and returns the number taken power of x */
	int i;
	int countx=0;
	char number[100];
	int powerofx;
	int j=0;
	memset(number,'\0',100);
	for(i=0;i<strlen(buffer);i++) {
		if(buffer[i]=='x') {
			countx++;
			break;
		}
	}
	if(countx==0)
	return 0;
	else{
		if(buffer[i+1]=='^') {
			i=i+2;
			for(;i<strlen(buffer);i++) {
				number[j]=buffer[i];
				j++;
			}
			sscanf(number, "%d", &powerofx);
			return powerofx;
		}
		else
		return 1;
	}
	
}


double find_coefficient(char buffer[100]) {/*finding coefficient of monomials */
	int i=1;
	char number[100];
	memset(number,'\0',100);
	int j=0;
	double coefficient;
	if(buffer[1]=='x')
	return 1;
	if(find_power(buffer)==0) { /* If it is constant number */
		for(;i<strlen(buffer);i++) {
			number[j]=buffer[i];
			j++;
		}
	}
	else {
		while(buffer[i]!='x') {
			number[j]=buffer[i];
			i++;
			j++;
		}
	}
	sscanf(number,"%lf",&coefficient);
	return coefficient;
}

int main() {
	/* defining variables and file pointers which is going to be used */ 
	FILE *fevaluationsptr=fopen("evaluations.txt","w");
	FILE *fvaluesptr=fopen("values.txt","r");
	FILE *fpolyptr=fopen("polynomial.txt","r");
	FILE *fcheckptr=fopen("values.txt","r");
	double numbers[100];
	char polynom[1000];
	char buffer[100];
	memset(buffer,'\0',100);
	memset(polynom,'\0',1000);
	int numbercount;
	int polycount;
	int i,j,k;
	char b;
	i=0;
	int ncount=0;
	while(!feof(fcheckptr)) { /*loop for checking whether file includes '\n' or not. If includes, fscanf takes one more input somehow. */ 
		fscanf(fcheckptr,"%c",&b);
		if(b=='\n')
		ncount++;
	}
	
	
	i=0;
	/* placing double numbers in values.txt to double array */
	while(!feof(fvaluesptr)) {
		fscanf(fvaluesptr,"%lf",&numbers[i]);
		i++;
	}
	numbercount=i;
	if(ncount!=0) {/* If file includes '\n' deleting last result number. */
		numbercount--;
	}
	/* if there are x numbers, there will be x results of those parameters */
	double results[numbercount];
	for(i=0;i<numbercount;i++)
	results[i]=0;
	i=0;
	/* placing polynomial.txt to char array */
	char a;
	int checknewline=0;
	while(!feof(fpolyptr)) {
		fscanf(fpolyptr,"%c",&a);
		if(a!=' ' && a!='\n') {
			polynom[i]=a;
			i++;
		}
		if(a=='\n')
		checknewline++;
	}
	if(checknewline==0)
	polynom[i-1]='\0';
	polycount=strlen(polynom);
    if(polynom[polycount-1]=='.') { /* Some of the examples have '.' at the end. This if condition blocks last '.' being included in array */
		polynom[polycount-1]='\0';
		polycount=strlen(polynom);
	}
	i=0; 
	/* counting plusses and minuses in order to use after */
	int plusminuscount=0;
	for(i=0;i<polycount;i++) {
		if(polynom[i]=='+'||polynom[i]=='-')
		plusminuscount++;
	}
	
	i=0;
	if(polynom[0]=='-') { /* if first character is '-', assigning buffer[0] as '-' */
		buffer[0]='-';
		plusminuscount--;
		k=1;
	}
	else{/* if it is not, it is '+' */
		buffer[0]='+';
		k=0;
	}
	j=1;
	i=0;
	int d;
	/*dividing polynomial string to monomial char buffers(for example '+5x^2' format) to apply operations */
	while(i<plusminuscount+1) {
		while(polynom[k]!='+' && polynom[k]!='-' && k!=polycount) {
			buffer[j]=polynom[k];
			k++;
			j++;
		}
		if(buffer[0]=='+'){
			for(d=0;d<numbercount;d++){
				results[d]+=(find_coefficient(buffer))*(pow(numbers[d],find_power(buffer)));
			}
		}
		
		else if(buffer[0]=='-'){
			for(d=0;d<numbercount;d++){
				results[d]-=(find_coefficient(buffer))*(pow(numbers[d],find_power(buffer)));
			}
		}
		
		
		memset(buffer,'\0',100);
		j=0;
		buffer[j]=polynom[k];
		k++; j++;
		i++;
	}
	for(i=0;i<numbercount;i++)
	fprintf(fevaluationsptr,"%.2lf\n",results[i]); 
	fclose(fevaluationsptr);
	fclose(fvaluesptr);
	fclose(fpolyptr);
	fclose(fcheckptr);
	
	
}
