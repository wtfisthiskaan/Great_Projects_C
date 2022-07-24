#include<stdio.h>


char decrypt_numbers(int number) {
			char result;
				switch(number) {
		case '0':
			return 32;
			break;
		case '1':
			return 45;
			break;
		case '2':
			return 95;
			break;
		case '3':
			return 124;
			break;
		case '4':
			return 47;
			break;
		case '5':
			return 92;
			break;
		case '6':
			return 79;
			break;	
		default:
			break;
				
		
	}
	
}

void decrypt_and_print(char* file_path) {

	

	int variable;
	variable=atoi(file_path);
	printf("%c",decrypt_numbers(variable));
	
}




int main() {

	FILE *fp;
	
	char a;
	fp=fopen("encrypted_p1.img", "r");
	
	while(!feof(fp)) {
		fscanf(fp,"%c",&a);
		decrypt_and_print(&a);
		
	}	
	
	
	
}
