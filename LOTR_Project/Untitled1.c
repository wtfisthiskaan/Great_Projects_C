#include<stdio.h>
void decrypt_and_print(char *file_path) {
	int variable;
	variable=file_path;
	decrypt_numbers(variable);
	
}

char decrypt_numbers(int number) {
			char result;
				switch(number) {
		case '0':
			result:' ';
			return result;
			break;
		case '1':
			result='-';
			return result;
			break;
		case '2':
			result='_';
			return result;
			break;
		case '3':
			result='|';
			return result;
			break;
		case '4':
			result='/';
			return result;
			break;
		case '5':
			result='\\';
			return result;
			break;
		case '6':
			result='O';
			return result;
			break;	
		default:
			break;
				
		
	}
	
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
