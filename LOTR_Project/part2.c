#include<stdio.h>
char decrypt_numbers (int number) {
	char result;
	number=(char)number;
		switch(number) {
			case '0' :
				result=' ';
				return result;
				break;
			case '1' :
				result='-';
				return result;
				break;
			case '2' :
				result='_';
				return result;
				break;
			case '3' :
				result='|';
				return result;
				break;
			case '4' :
				result='/';
				return result;
				break;	
			case '5' :
				result='\\';
				return result;
				break;
			case '6' :
				result='O';
				return result;
				break;			

	}

}
void deep_decrypt_and_print (char* file_path) {
	char a,b,c;
	char toplam;
	FILE *fp0=fopen(file_path,"r");
	FILE *fp1=fopen(file_path,"r");
	FILE *fp2=fopen(file_path,"r");
	fscanf(fp0,"%c",&a);
	fscanf(fp1,"%c",&b);
	fscanf(fp1,"%c",&b);
	fscanf(fp2,"%c",&c);
	fscanf(fp2,"%c",&c);
	fscanf(fp2,"%c",&c);
//	toplam=a+b+c;
//	toplam=toplam%7;
//	printf("%c",decrypt_numbers(toplam));
	while(!feof(fp0)) {
		if(feof(fp1)) {
			toplam=a;
			toplam=toplam%7;
			printf("%c",decrypt_numbers(toplam));
		}
		else
		{
			if(feof(fp2)){
				toplam=a+b;
				toplam=toplam%7;
				printf("%c",decrypt_numbers(toplam));
			}
			else{
				toplam=a+b+c;
				toplam=toplam%7;
				printf("%c",decrypt_numbers(toplam));
			}
		}
				fscanf(fp0,"%c",&a);
				fscanf(fp1,"%c",&b);
				fscanf(fp2,"%c",&c);


	}

}








int main()
{
	deep_decrypt_and_print ("encrypted_p2.img");
}
