//Game program
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int pos1,pos2,a[25];
int p1[25]={0,1,2,3,4,9,14,19,24,23,22,21,20,15,10,5,6,7,8,13,18,17,16,11,12};	//path of player 1
int p2[25]={20,15,10,5,0,1,2,3,4,9,14,19,24,23,22,21,16,11,6,7,8,13,18,17,12};	//path of player 2

int random() {	//Randomizer
	srand(time(NULL));
	return rand()%(6-1)+1; //generates values from 1 to 6 randomly
}

void init1() {
	for(int k=0;k<25;k++)
	{
		if((k+1)%2!=0)
		a[k]=3;	//even position is safe, marked as 3
		else
		a[k]=0;	//odd position is unsafe, marked as 0
	}
}

int safe(int pos,int p[]) {
	if(a[p[pos]]!=0)
		return 0;
	else
		return 1;
}

void display() {
	int k;
	for(k=0;k<25;k++)
	{
		if(k%5==0)
			printf("\n");
		
		if(pos1==pos2&&pos1==k)
			printf("312\t");
			
		else if(pos1==k) {
			if(a[pos1]==3)
				printf("31\t");
			else
				printf("1\t");
		}
		else if(pos2==k) {
			if(a[pos2]==3)
				printf("32\t");
			else
				printf("2\t");
		}
		else
			printf("%d\t",a[k]);
	}
}

int main() {

	int i=0,j=0; 
	pos1=0; 	//index for player1 positon
	pos2=20;	 //index for player2 positon
	int player=1;	 //variable to choose player
	int x;	 //input-dice
	init1();	 //Initialize the array
	display();	 //Display Board
	x=0;
	
L60:while(true){
		//Player 1 chance
		printf("\nPlayer 1:\n");
		if (player==1) {	
			//x=random();	//dice
			printf("Dice value:");
				scanf("%d",&x);
			if(pos1>8) {
				if(x<=6) {
					i=i+x;
				}
				else {
					printf("Dice value too large! Player2 plays now.\n");
					player=2;
					goto L60;
				}
			}
			else	{
			i=i+x;
		}
			//i+=x;
			
			pos1=p1[i]; //assigning position
			display();
			if(pos1==12){	//check if player1 has won
				printf("\nPlayer 1 Wins!\n");
				display();
				exit(0);
			}
			if(pos1==pos2){	//checking if players are at same position
				if(!safe(pos1,a)){	//if both at unsafe position, reset player2 position
					j=0;
					pos2=20;
					printf("\nPlayer 2 sent back to start!\n");
					display();
				}
				else{	//if at safe position, let player2 play
					display();
					player=2;
				}
			}	
			else
				player=2;
				//display();
		}
		
		//Player 2 chance
		if (player==2) {	
		
		printf("\nPlayer 2:\n");
			//x=random();	//dice
			printf("Dice value: ");
				scanf("%d",&x);
			if(pos2>6) {
				if(x<=6) {
					j=j+x;
				}
				else {
					printf("\nDice value too large! Player1 plays now.\n");
					player=1;
					goto L60;
				}
			}
			else{
			j=j+x; }
			pos2=p2[j]; //assigning position
			display();
			if(pos2==12){	//check if player2 has won
				printf("\nPlayer 2 Wins!\n");
				exit(0);
			}
			if(pos1==pos2){	//checking if players are at same position
				if(!safe(pos2,a)){	//if both at unsafe position, reset player1 position
					i=0;
					pos1=0;
					printf("\nPlayer 1 sent back to start!\n");
					display();
				}
				else{	//if at safe position, let player2 play
				
					player=1;
				}
			}	
			else
				player=1;
				//display();
		}
	}
}


