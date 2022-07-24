#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD   20
#define NUM_WORDS  10



char random_letter_generator() {
	char letter=(rand()%26)+97;
	return letter;
}


void random_word_generator(char randwords[10][20]) {
	int i,j;
    FILE *fp = fopen("words.txt", "r");

    if (fp == NULL) {
        perror("Unable to locate word list");
        exit(EXIT_FAILURE);
    }
    char word[MAX_WORD];
    long wc = 0;
    while (fgets(word, sizeof word, fp) != NULL) {
        ++wc;
    }
    srand((unsigned) time(NULL));
    for (i = 0; i < 10; i++) {
        rewind(fp);
        int sel = rand() % wc + 1;
        for (j = 0; j < sel; j++) {
            if (fgets(word, sizeof word, fp) == NULL) {
                perror("Error in fgets()");
            }
        }
        strcpy(randwords[i], word);
    }

    if (fclose(fp) != 0) {
        perror("Unable to close file");
    }

   
    
}
int direction() {
	
	
	int direction;
	direction=rand()%8;
	/*
	1 is left up
	2 is directly up
	3 is right  up
	4 is directly right
	5 is right down
	6 is directly down
	7 is left down
	8 is directly left
	
	
	 */
	 direction=direction+1;
	return direction;
	
}

void replace(char wordtable[20][20],char randwords[10][20], int location[10][20]) {
	
	int sira=0;
	int i;
	int length;
	int variable;
	int row,column;
	int direction1;
	for(i=0;i<10;i++) {
		length=strlen(randwords[sira]);
		direction();
		if(direction()==1)
			 {
			 	//printf("1");
			tekrar:
			row=rand()%20;
			column=rand()%20;
			if(row<length) {  
				row=row+length; 
			}
			if(column<length) {
				column=column+length;
			}
			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row-j][column-j]!='0') {
					goto tekrar;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=1;
			
			
			for(j=0;j<length;j++) {
				wordtable[row-j][column-j]=randwords[sira][j];
			}
			
			
	}
	
		else if(direction()==2) {
			//printf("2");
			
			tekrar2:
			row=rand()%20;
			column=rand()%20;
			if(row<length) {  
				row=row+length; 
			}
			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row-j][column]!='0') {
					goto tekrar2;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=2;
			
			for(j=0;j<length;j++) {
				wordtable[row-j][column]=randwords[sira][j];
			}
			
		}
		
			else if(direction()==3) {
			
			//printf("3");
			tekrar3:
			row=rand()%20;
			while(row<length) {
				row=rand()%20;
			}
			column=rand()%(19-length);
		//	if(row<length) {  
		//		row=row+length; 
		//	}
			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row-j][column+j]!='0') {
					goto tekrar3;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=3;
			
			for(j=0;j<length;j++) {
				wordtable[row-j][column+j]=randwords[sira][j];
			}
			
		}
		else if(direction()==4)
			 {
			//printf("4");
			tekrar4:
			row=rand()%(20);
			column=rand()%(20-length);
			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row][column+j]!='0') {
					goto tekrar4;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=4;
			
			for(j=0;j<length;j++) {
				wordtable[row][column+j]=randwords[sira][j];
			}			
			
	}
	
		else if(direction()==5)
			 {
			 	//printf("5");
			
			tekrar5:
			row=rand()%(20-length);
			column=rand()%(20-length);
			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row+j][column+j]!='0') {
					goto tekrar5;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=5;
			
			for(j=0;j<length;j++) {
				wordtable[row+j][column+j]=randwords[sira][j];
			}

			
			
			
	}
	
		else if(direction()==6)
			 {
			//printf("6");
			tekrar6:
			row=rand()%(20-length);
			column=rand()%20;


			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row+j][column]!='0') {
					goto tekrar6;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=6;
			
			for(j=0;j<length;j++) {
				wordtable[row+j][column]=randwords[sira][j];
			}
			
			
			
	}
	
		else if(direction()==7)
			 {
			//printf("7");
			tekrar7:
			row=rand()%(20-length);
			column=rand()%20;
			if(column<length) {
				column=column+length;
			}
			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row+j][column-j]!='0') {
					goto tekrar7;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=7;
			
			for(j=0;j<length;j++) {
				wordtable[row+j][column-j]=randwords[sira][j];
			}

			
			
	}
	
		else //if(direction()==8)
			 {
			//printf("8");
			tekrar8:
			row=rand()%20;
			column=rand()%20;
			if(column<length) {
				column=column+length;
			}
			int j;
			for(j=0;j<length;j++) {
				if(wordtable[row][column-j]!='0') {
					goto tekrar8;
				}
			}
			location[sira][0]=row;
			location[sira][1]=column;
			location[sira][2]=8;
			
			for(j=0;j<length;j++) {
				wordtable[row][column-j]=randwords[sira][j];
			}
			
			
			
	}
	sira++;
	}
		
	}
		
	





int main(void)
{
	char kontrol[4];
	int y=0;
	int deger;
	int integer;
	int location[10][20];
	srand(time(NULL));
	char wordtable[20][20];
	int i,j;
	for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			wordtable[i][j]='0';
		}
	}
	
	char randwords[10][20];
	
	random_word_generator(randwords);
	replace(wordtable,randwords,location);
	for(i=0;i<20;i++) {//If you delete 323 to 329 line you would see words more seeable.
		for(j=0;j<20;j++) {
			if(wordtable[i][j]=='0') {
				wordtable[i][j]=random_letter_generator();
			}
		}
	}
		for(i=0;i<20;i++) {
		for(j=0;j<20;j++) {
			if(wordtable[i][j]=='\n') {
				wordtable[i][j]=random_letter_generator();
			}
		}
	}
	int a,b;


int count1=0;
int count2=0;
for(i=0;i<10;i++) {
	for(b=0;b<3;b++) {
		printf("%d ",location[i][b]);
	}
	printf("\n");
}

	int yataycounter=0;
	renew:
		if(count2==10) {
			printf("Congrulations! You have done this crossword");
			
			goto bitir;
		}
		   printf("Words:\n");
    for (i = 0; i < 10; i++) {
        printf("%s", randwords[i]);
    }

	yataycounter++;
	//printf("yataykount %d",yataycounter);
	char yatay[15][3];
	int dikey[15][3];
	int variable;
	char word[15][15];
		printf("\n     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19\n");
	printf("    ___________________________________________________________\n");
				for(a=0;a<20;a++){
      						printf(" %c | ",a+65);

    						for(b=0;b<20;b++){

        						printf("%c  ",wordtable[a][b]);

   							 }				

						printf("\n");

}
	count1=0;
	
	
	printf("Please enter your guess:\n");
	scanf(" %c%d %s",&yatay[yataycounter][0],&dikey[yataycounter][0],&word[yataycounter]);
	//integer=(int)yatay;
	variable=(int)(yatay[yataycounter][0]);
	for(i=0;i<10;i++) {
		if((variable-65==location[i][0])&&(dikey[yataycounter][0]==location[i][1])&&(word[yataycounter][0]==randwords[i][0])&&(word[yataycounter][1]==randwords[i][1])&&(word[yataycounter][2]==randwords[i][2])) {
			//printf("brocann");
			count1++;
			//goto renew;
			break;
		}
	}
	//goto renew;
	if(count1==1) {
		printf("guess is true\n");
		int length=strlen(randwords[i]);
		//int yatay=location[i][0];
		//int dikey=location[i][1];
		if(location[i][2]==1){
			
			for(y=0;y<length-1;y++) {
				wordtable[location[i][0]-y][location[i][1]-y]=toupper(wordtable[location[i][0]-y][location[i][1]-y]);
				//printf("giriyo");
			}
			for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}	
		}
		
		else if(location[i][2]==2){
			
			for(y=0;y<length-1;y++) {
				//printf("giriyo");
				wordtable[location[i][0]-y][location[i][1]]=toupper(wordtable[location[i][0]-y][location[i][1]]);
			}	
				for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}
		}
		else if(location[i][2]==3){
			
			for(y=0;y<length-1;y++) {
				//printf("giriyo");
				wordtable[location[i][0]-y][location[i][1]+y]=toupper(wordtable[location[i][0]-y][location[i][1]+y]);
			}	
				for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}
		}
			else if(location[i][2]==4){
				
			for(a=0;a<length-1;a++) {
				//printf("giriyo");
				wordtable[location[i][0]][location[i][1]+a]=toupper(wordtable[location[i][0]][location[i][1]+a]);
			}	
				for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}
		}
			else if(location[i][2]==5){
			
			for(a=0;a<length-1;a++) {
				//printf("giriyo");
				wordtable[location[i][0]+a][location[i][1]+a]=toupper(wordtable[location[i][0]+a][location[i][1]+a]);
			}
				for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}	
		}
			else if(location[i][2]==6){
				
			for(a=0;a<length-1;a++) {
				//printf("giriyo");
				wordtable[location[i][0]+a][location[i][1]]=toupper(wordtable[location[i][0]+a][location[i][1]]);
			}
				for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}	
		}
			else if(location[i][2]==7){
			
			for(a=0;a<length-1;a++) {
				//printf("giriyo");
				wordtable[location[i][0]+a][location[i][1]-a]=toupper(wordtable[location[i][0]+a][location[i][1]-a]);
			}	
				for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}
		}
			else {
				
			for(a=0;a<length-1;a++) {
				//printf("giriyo");
				wordtable[location[i][0]][location[i][1]-a]=toupper(wordtable[location[i][0]][location[i][1]-a]);
			}	
				for(y=0;y<length;y++) {
				randwords[i][y]=toupper(randwords[i][y]);
			}
		}
		count2++;
		printf("If you don't want to continue type Exit, If you want to continue type something except Exit\n ");
		scanf("%s",&kontrol);
		if(kontrol[0]=='E'&&kontrol[1]=='x'&&kontrol[2]=='i'&&kontrol[3]=='t') {
		goto bitir;
	}
		goto renew;
	}
	else {
		printf("guess is wrong");
		printf("If you don't want to continue type Exit, If you want to continue type something except Exit\n ");
		scanf("%s",&kontrol);
		if(kontrol[0]=='E'&&kontrol[1]=='x'&&kontrol[2]=='i'&&kontrol[3]=='t') {
		goto bitir;
	}
		goto renew;
	}

	
	bitir:
	
	
	
	



	
	

    return 0;
}
