#include<stdio.h>

int main() {

	FILE *fp;
	
	char a;
	fp=fopen("encrypted_p1.img", "r");
	
	while(!feof(fp)) {
		fscanf(fp,"%c",&a);
		decrypt_and_print(&a);
		
				switch(a) {
		case '0':
			printf("%c",32);
			break;
		case '1':
			printf("%c",45);
			break;
		case '2':
			printf("%c",95);
			break;
		case '3':
			printf("%c",124);
			break;
		case '4':
			printf("%c",47);
			break;
		case '5':
			printf("%c",92);
			break;
		case '6':
			printf("%c",79);
			break;	
		default:
			break;
				
		
	}
		
		
		
	}	
	
	
	
}
