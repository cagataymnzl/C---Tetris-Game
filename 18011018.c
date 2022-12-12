#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int row,column,i,j,k,n,m,select,rotate,x,y,control;
	int counter=0;
	int score=0;
	int exit=1;
	int place;
	char table[3][3];
	printf("*************TETRIS*************\n");
	printf("Information!\n--->When you want to enter the x and y coordinates of shape,you must think the most left bottom corner!\n");
	printf("--->You must enter the row and the column number of gameboard for x and y to place the shape where you want!\n\n");
	printf("********************************\n");
	printf("Enter row and column numbers of game board!\n");
	printf("Row Number:");scanf("%d",&row);
	printf("Column Number:");scanf("%d",&column);
	printf("\nGame Board is: %d X %d",row,column);
	printf("\n\nGame is starting...\n");
	char gameboard[row][column];
	char single[1][1]={'x'};//tek
	char straight[1][3]={'x','x','x'};//düz
	char l[3][2]={'x','\0','x','\0','x','x'};//l
	char z[2][3]={'x','x','\0','\0','x','x'};//z
	char square[2][2]={'x','x','x','x'};//kare
	char two[1][2]={'x','x'};//iki
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			gameboard[i][j]='0';
		}
	}
	for(i=0;i<row;i++){
		for(j=0;j<column;j++){
			printf("%c ",gameboard[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	do{
		rotate=0;
		control=0;
		srand(time(NULL));
		select=rand()%6;
		switch(select){
			case 0: 
				for(i=0;i<1;i++){
					for(j=0;j<1;j++){
						table[i][j]=single[i][j];
					}
				}
				break;//tek
			case 1: 
				for(i=0;i<1;i++){
					for(j=0;j<3;j++){
						table[i][j]=straight[i][j];
					}
				}
				break;//düz
			case 2: 
				for(i=0;i<3;i++){
					for(j=0;j<2;j++){
						table[i][j]=l[i][j];
					}
				}
				break;//l
			case 3:
				for(i=0;i<2;i++){
					for(j=0;j<3;j++){
						table[i][j]=z[i][j];
					}
				}
				break; //z
			case 4: 
				for(i=0;i<2;i++){
					for(j=0;j<2;j++){
						table[i][j]=square[i][j];
					}
				}//kare
				break; 
			case 5: 
				for(i=0;i<1;i++){
					for(j=0;j<2;j++){
						table[i][j]=two[i][j];
					}
				}
				break;//two
		}
		
		if(select==0){//tek dönme yok sonsuz döngü
			printf("Next Shape is:\n");
			for(i=0;i<1;i++){
				for(j=0;j<1;j++){
					printf("%c ",table[i][j]);
				}
				printf("\n");
			}
			printf("Enter the x and y coordinates of the place where you want to place:");
			printf("\nX:");scanf("%d",&x);
			printf("Y:");scanf("%d",&y);
			while(gameboard[control+1][y-1]=='0' && control<row-1){
				control++;
			}
			gameboard[control][y-1]='x';		
		}
		
		else if(select==1){//düzüç
			printf("Next Shape is:\n");
			for(i=0;i<1;i++){
				for(j=0;j<3;j++){
					printf("%c ",table[i][j]);
				}
				printf("\n");
			}
			
			printf("How many times do you want to rotate the shape?");
			scanf("%d",&rotate);
			rotate = rotate % 2;
			if(rotate == 1){
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						table[i][j]='\0';
					}
				}
				table[0][0]=table[1][0]=table[2][0]='x';
				printf("Rotated Shape:\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%c ",table[i][j]);
					}
					printf("\n");
				}
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				
				while(gameboard[control+3][y-1]=='0'&&control+3<row){
					control++;
				}
				gameboard[control+2][y-1]=gameboard[control+1][y-1]=gameboard[control][y-1]='x';
			}	
			else{
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+1][y-1]=='0' && gameboard[control+1][y]=='0' && gameboard[control+1][y+1]=='0' && control<row-1){
					control++;
				}
				gameboard[control][y-1]=gameboard[control][y]=gameboard[control][y+1]='x';
			}
		}
		else if(select==2){//l  
			printf("Next Shape is:\n");
			for(i=0;i<3;i++){
				for(j=0;j<2;j++){
					printf("%c",table[i][j]);
				}
				printf("\n");
			}
			
			printf("How many times do you want to rotate the shape?");
			scanf("%d",&rotate);
			rotate = rotate % 4;
			for(i=0;i<3;i++){
				for(j=0;j<3;j++){
					table[i][j]='\0';
				}
			}
			if(rotate==1){
				table[1][0]=table[1][1]=table[1][2]=table[2][0]='x';
				printf("\nRotated Shape:\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%c ",table[i][j]);
					}
					printf("\n");
				}
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+2][y-1]=='0' && gameboard[control+1][y]=='0' && gameboard[control+1][y+1]=='0' && control<row-2){
					control++;
				}
				gameboard[control][y-1]=gameboard[control][y]=gameboard[control][y+1]=gameboard[control+1][y-1]='x';
			}
			else if(rotate==2){
				table[0][0]=table[0][1]=table[1][1]=table[2][1]='x';
				printf("\nRotated Shape:\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%c ",table[i][j]);
					}
					printf("\n");
				}
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+1][y-1]=='0' && gameboard[control+3][y]=='0' && control<row-3){
					control++;
				}
				gameboard[control][y-1]=gameboard[control][y]=gameboard[control+1][y]=gameboard[control+2][y]='x';
			}
			else if(rotate==3){
				table[1][2]=table[2][0]=table[2][1]=table[2][2]='x';
				printf("\nRotated Shape:\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%c ",table[i][j]);
					}
					printf("\n");
				}
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+2][y-1]=='0' && gameboard[control+2][y]=='0' && gameboard[control+2][y+1]=='0' && control<row-2){
					control++;
				}
				gameboard[control+1][y-1]=gameboard[control+1][y]=gameboard[control+1][y+1]=gameboard[control][y+1]='x';		
			}
			else{
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+3][y-1]=='0' && gameboard[control+3][y]=='0' && control<row-3){
					control++;
				}
				gameboard[control][y-1]=gameboard[control+1][y-1]=gameboard[control+2][y-1]=gameboard[control+2][y]='x';			
			}
		}
		else if(select==3){//z
			printf("Next Shape is:\n");
			for(i=0;i<2;i++){
				for(j=0;j<3;j++){
					printf("%c ",table[i][j]);
				}
				printf("\n");
			}
			
			printf("How many times do you want to rotate the shape?");
			scanf("%d",&rotate);
			rotate = rotate % 2;
			if(rotate==1){
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						table[i][j]='\0';
					}
				}
				table[0][1]=table[1][0]=table[1][1]=table[2][0]='x';
				printf("Rotated Shape:\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%c ",table[i][j]);
					}
				printf("\n");
				}
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+3][y-1]=='0' && gameboard[control+2][y]=='0' && control<row-3){
					control++;
				}
				gameboard[control+2][y-1]=gameboard[control+1][y-1]=gameboard[control+1][y]=gameboard[control][y]='x';
			}
			else{
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+1][y-1]=='0' && gameboard[control+2][y]=='0' && gameboard[control+2][y+1]=='0' && control<row-2){
					control++;
				}
				gameboard[control][y-1]=gameboard[control][y]=gameboard[control+1][y]=gameboard[control+1][y+1]='x';				
			}	
		}
		else if(select==4){//kare dönme yok sonsuz döngü
			printf("Next Shape is:\n");
			for(i=0;i<2;i++){
				for(j=0;j<2;j++){
					printf("%c ",table[i][j]);
				}
				printf("\n");
			}
			printf("Enter the x and y coordinates of the place where you want to place:");
			printf("\nX:");scanf("%d",&x);
			printf("Y:");scanf("%d",&y);
			while(gameboard[control+2][y-1]=='0' && gameboard[control+2][y]=='0' && control<row-2){
				control++;
			}
			gameboard[control][y-1]=gameboard[control][y]=gameboard[control+1][y-1]=gameboard[control+1][y]='x';
		}
		
		else{//two
			printf("Next Shape is:\n");
			for(i=0;i<1;i++){
				for(j=0;j<2;j++){
					printf("%c ",table[i][j]);
				}
				printf("\n");
			}
			printf("How many times do you want to rotate the shape?");
			scanf("%d",&rotate);
			rotate = rotate % 2;
			if(rotate==1){
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						table[i][j]='\0';
					}
				}
				table[2][0]=table[1][0]='x';
				printf("\nRotated Shape:\n");
				for(i=0;i<3;i++){
					for(j=0;j<3;j++){
						printf("%c ",table[i][j]);
					}
					printf("\n");
				}
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+2][y-1]=='0' && control<row-2){
					control++;
				}
				gameboard[control+1][y-1]=gameboard[control][y-1]='x';
			}
			else{
				printf("Enter the x and y coordinates of the place where you want to place:");
				printf("\nX:");scanf("%d",&x);
				printf("Y:");scanf("%d",&y);
				while(gameboard[control+1][y-1]=='0' && gameboard[control+1][y]=='0' && control<row-1){
					control++;
				}
				gameboard[control][y-1]=gameboard[control][y]='x';
			}
		}
		
		printf("\n");
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				table[i][j]='\0';
			}
		}
		
		
		for(i=row-1;i>=0;i--){
			counter=0;
			for(j=0;j<column;j++){
				if(gameboard[i][j]=='x' && counter<column){
					counter++;
					if(counter==column){
						place=i;
					}
				}
			}
			if(counter==column){
				for(n=place-1;n>=0;n--){
					for(m=0;m<column;m++){
						gameboard[n+1][m]=gameboard[n][m];
					}
				}
				for(k=0;k<column;k++){
					gameboard[0][k]='0';
				}
				score=score+100;
				printf("\n*************SCORE:%d*************\n",score);	
			}
					
		}
		
		for(j=0;j<column;j++){
			if(gameboard[0][j]=='x'){
				exit=0;
			}
		}
		
		for(i=0;i<row;i++){
			for(j=0;j<column;j++){
				printf("%c ",gameboard[i][j]);
			}
			printf("\n");
		}
	}while(exit);
	printf("*************GAME OVER*************");
	printf("\nYOUR LAST SCORE : %d",score);
		
		
	
	
	
	return 0;
	
}
