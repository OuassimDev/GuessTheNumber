#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

typedef struct node {
	int data;
	struct node *next;
}node;

typedef struct {
	node *top;
}stack;

void init(stack *s){
	s->top=NULL;
}

void push(stack *s,int x){
	node *n=malloc(sizeof(node));
	n->data=x;
	n->next=s->top;
	s->top=n;
}

void pop (stack *s){
	if(s->top==NULL){
		printf("\nStack Is Empty\n");
		return;
	}
	else{
		node *temp=s->top;
		s->top=s->top->next;
		free(temp);
	}
}

void show(stack *s){
	if(s->top == NULL){
		printf("\nNo Fails !\n");
	}
	else{
		system("cls");
		node *temp = s->top;
		int i=1;
		printf("===========================\n");
		printf("    YOUR FAILED GUESSES    \n");
		printf("===========================\n");
		while(temp!=NULL){
			printf("Attempt %d -> %d\n",i,temp->data);
			temp=temp->next;
			i++;
		}
		printf("===========================\n");
		
	}
}



void modes(int triesnum,int mod){
	
	stack s;
	init(&s);
	
	srand(time(NULL));
	int random = (rand() % mod) + 1 ;
	
	int n,tries=0,Wincase=0;
	do{
		printf("Guess The Number :");
		scanf("%d",&n);
		if(n==random){
			int l;
			system("cls");
			system("color 2");
			printf("======================================\n");
			printf("You Won ! The Number Was %d\n",random);
			printf("======================================\n");
			printf("[0] Back to Main Menu\n");
			printf("======================================\n");
			printf("Play Again ? :");
			scanf("%d",&l);
			if(l==0){
				main();
			}
			Wincase=1;
			break;
		}
		else if(n>random){
			printf("\nToo High !\n");
			push(&s,n);
		}
		else {
			printf("\nToo Low !\n");
			push(&s,n);
		}
	
		tries++;
	}while(tries<triesnum);
	if(!Wincase){
		int y;
		system("cls");
		system("color 4");
		printf("======================================\n");
		printf("Game Over ! The Number Was %d\n",random);
		printf("======================================\n");
		printf("  [1] Your Fails !\n");
		printf("  [0] Back to Main Menu\n");
		printf("======================================\n");
		do{
			printf("Choose :");
			scanf("%d",&y);
		}while(y<0 || y>1);
		
		switch(y){
			case 1:
				show(&s);
				break;
			
			case 0:
				main();
				break;	
		}
		
	}
}

int main(){
	
	int mod;

    system("cls");
    system("color F");
    printf("=====================================\n");
    printf("        GuessTheNumber GAME MODS        \n");
    printf("=====================================\n");
    printf("  [1] Easy Mode   (1-20)(5 tries)\n");
    printf("  [2] Medium Mode (1-50)(7 tries)\n");
    printf("  [3] Hard Mode   (1-100)(10 tries)\n");
    printf("  [0] Back to Main Menu\n");
    printf("=====================================\n");

    do {
        printf("Choose a mode: ");
        scanf("%d", &mod);
    } while (mod < 0 || mod > 3);
    
    system("cls");
    
    switch(mod){
    	case 1 : 
			modes(5,20);
			break;
		
		case 2 :
			modes(7,50);
			break;
			
		case 3 : 
			modes (10,100);
			break;
			
		case 0 :
			exit(0);
			break;			
	}
	
	

	
	


}
