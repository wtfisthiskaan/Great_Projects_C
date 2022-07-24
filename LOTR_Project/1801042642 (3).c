#include<stdio.h>
#include <stdlib.h>
#include <math.h>

char decrypt_numbers (int number) {
	char result;
		switch(number) {
			case 0 :
				result=' ';
				return result;
				break;
			case 1 :
				result='-';
				return result;
				break;
			case 2 :
				result='_';
				return result;
				break;
			case 3 :
				result='|';
				return result;
				break;
			case 4 :
				result='/';
				return result;
				break;	
			case 5 :
				result='\\';
				return result;
				break;
			case 6 :
				result='O';
				return result;
				break;
			default:
			printf("\n");
			return 0;

			 				

	}

}

void decrypt_and_print (char *file_path) {
	FILE *fp=fopen(file_path, "r");
	//char a;
	char number;
	int cakma;

	
	while(!feof(fp)) {
		fscanf(fp,"%c",&number);
		cakma=number-48;

		printf("%c",decrypt_numbers(cakma));



	}


}

void deep_decrypt_and_print (char* file_path) {
	char a,b,c;
	int toplam;
	FILE *fp0=fopen(file_path,"r");
	fscanf(fp0,"%c",&a);
	fscanf(fp0,"%c",&b);
	while(!feof(fp0)) {
		fscanf(fp0,"%c",&c);
				if(c == '\n'){
			printf("\n");
			fscanf(fp0,"%c",&a);
			fscanf(fp0,"%c",&b);
		}
				else {
					toplam = a+b+c-48*3;
			toplam = toplam%7;
			printf("%c",decrypt_numbers(toplam));
			a = b;
			b = c;


				}	
			
		
				


	}

}

void track_machine () {
	char choice;
	int X=0;
	int Y=0;
	double D=8.48;
	double R=0;
	print_coordinate(&X,&Y,&D,&R);
	printf("\nCommand waiting..");
	scanf("%c",&choice);
	while(1) {
		if(choice=='R'){
			refresh_position(&X,&Y,&D,&R);

		}
		else if(choice=='E') {
			break;

		}
		printf("\nCommand waiting..");
		scanf("%c",&choice);


	}
	



}


void refresh_position (int *X, int *Y, double *D, double *R) {
	srand(time(NULL));
	int oldx = *X;
	int oldy = *Y;
	*X = rand()%11;
	*Y = rand()%11;
	*D = sqrt((*X-6)*(*X-6)+(*Y-6)*(*Y-6));
	*R = sqrt((*X-oldx)*(*X-oldx)+(*Y-oldy)*(*Y-oldy));
	print_coordinate(&*X,&*Y,&*D,&*R);

}

void print_coordinate(int *X, int *Y, double *D, double *R) {
		int vertical,horizontal;
		for(horizontal=1;horizontal<12;horizontal++){
		for(vertical=1;vertical<12;vertical++){
			if(*X==vertical && *Y==horizontal){
				printf("E	");
			}else if(vertical==6 && horizontal==6){
				printf("O	");
			}else{
				printf(".	");
			}
		}
		printf("\n");
	}
	printf("Enemies x position: %d, Y position: %d, Displacement %.2lf, Distance to our camp: %.2lf",*X,*Y,*R,*D);



}
void encrypt_messages (char* file_path) {
	FILE *fpread=fopen(file_path,"r");
	FILE *fpwrite=fopen("encrypted_p4.img","w");
	char a,b,c;
	a=48;
	b=48;
	char decrypt_pointer;
	fprintf(fpwrite, "%c",a);
	fprintf(fpwrite, "%c",b);

		while(!feof(fpread)) {
			fscanf(fpread,"%c",&decrypt_pointer);
			switch(decrypt_pointer){
				case ' ':{
					c = 3*48-a-b;
					break;
				}
				case '-':{
					c = 3*48-a-b+1;
					break;
				}
				case '_':{
				c = 3*48-a-b+2;
					break;
				}
				case '|':{
					c = 3*48-a-b+3;
					break;
				}
				case '/':{
					c = 3*48-a-b+4;
					break;
				}
				case '\\':{
					c = 3*48-a-b+5;
					break;
				}
				case 'O':{
					c = 3*48-a-b+6;
					break;
				}
		}
		while(c < 48){
			c+=7;
		}
		if(decrypt_pointer == '\n'){
			fprintf(fpwrite,"%c",'\n');
			a = 48;
			b = 48;
			fprintf(fpwrite,"%c",a);
			fprintf(fpwrite,"%c",b);
		}else{
			fprintf(fpwrite,"%c",c);
			a = b;
			b = c;
		}



	}
	fclose(fpwrite);

}

void menu() {
	int choice;
	while(1) {
		printf("1. Decrypt and print encrypted_p1.img\n");
		printf("2. Decrypt and print encrypted_p2.img\n");
		printf("3. Switch on the tracking machine\n");
		printf("4. Encrypt the message\n");
		printf("5. Switch off\n");
		printf("\nPlease make your choice\n");
		scanf("%d",&choice);
		if(choice==1) {
			decrypt_and_print("encrypted_p1.img");
		}
		else if(choice==2) {
			deep_decrypt_and_print("encrypted_p4.img");
		}
		else if(choice==3) {
			track_machine();
		}
		else if(choice==4) {
			encrypt_messages("decrypted_p4.img");
		}
		else if(choice==5) {
			break;
		}


	}


}






int main() {
menu();



}
