#include <stdio.h>
#include <stdlib.h>


int main(int argc,char *argv[]){
	int i,j,age1,age2,cmp,r,c,kena,winner,cnt,size;
	char m[8][8],pl1[20],pl2[20],first[20],second[20],current[20],csym,fsym,ssym,ans;
	
	// Task 1
	//Εμφανιση μακετας
	printf("Welcome to Score-4 Game for 2\n\n");
    for(i=0;i<7;i++)
    {
    	for(j=0;j<7;j++)
    	{
    		m[i][j]='_';
		}
	}
	printf("  ");
	for(j=0;j<7;j++)
	{
		printf("%d ",j);
	}
	printf("\n");
	for(i=0;i<7;i++)
	{
		printf("%d",i);
		for(j=0;j<7;j++)
		{
			printf(" %c",m[i][j]);
		}
		printf("\n");
	}
	printf("\n"); 
	printf("Enter name of PLAYER 1: "); 
	scanf("%s",pl1);
	//Ελεγχος εισαγωμενων ηλικιων
	do
	{	
	    printf("Enter age of PLAYER 1: ");
	    scanf("%d",&age1);
	   if(age1<=0 || age1>120)
	   {
	   	    printf("Error, age must be between 0-120\n");
	   }
    }while(age1<=0 || age1>120);
	printf("Enter name of PLAYER 2: ");
	scanf("%s",pl2);
	do
	{	
	    printf("Enter age of PLAYER 2: ");
	    scanf("%d",&age2);
	    if(age2<=0 || age2>120)
	    {
	   	    printf("Error, age must be between 0-120\n");
	    }
    }while(age2<=0 || age2>120);
	i=0;
	cmp=1;
	// Σε περιπτωση που τα ονοματα ειναι ιδα τοτε, ονομα του παικτη 2 καταχωρειται Ονομα2 
	while(pl1[i]!='\0' || pl2[i]!='\0')
	{
		if(pl1[i]!=pl2[i])
		{
			cmp=0;
		}
		i++;
	}
	
	if(cmp)
	{
		j=0;
		while(pl2[j]!='\0')
		{
			j++;
		}
		pl2[j]='2';
		pl2[j+1]='\0';
	}
	//Ελεγχοι για το ποιος θα ξεκινησει πρωτος
	if(age1<age2)
	{
		for(i=0;pl1[i]!='\0';i++)
		{
			first[i]=pl1[i];
		}
		first[i]='\0';
		for(i=0;pl2[i]!='\0';i++)
		{
			second[i]=pl2[i];
		}
		second[i]='\0';
	}
	else if(age1>age2)
	{
		for(i=0;pl2[i]!='\0';i++)
		{
			first[i]=pl2[i];
		}
		first[i]='\0';
		for(i=0;pl1[i]!='\0';i++)
		{
			second[i]=pl1[i];
		}
		second[i]='\0';
	}
	else
	{
		for(i=0;pl1[i]!='\0';i++)
		{
			first[i]=pl1[i];
		}
		first[i]='\0';
		for(i=0;pl2[i]!='\0';i++)
		{
			second[i]=pl2[i];
		}
		second[i]='\0';
	}
   //Task 2
   // Ελεγχος εισαγωγης συμβολου
	do
	{
        printf("%s, select your symbol(X or O): ",first);
        scanf(" %c",&fsym);
		if(fsym!='X' && fsym!='O' )
		{
			printf("Error, only 'X'and 'Y' allowed\n");
		}
	}while(fsym!='X' && fsym!='O');
	if(fsym=='X')
	{
		ssym='O';
	}
	else
	{
		ssym='X';
	}
	//Το size αλλαζει ειναι το μεγεθος τις τριλιζας και αλλαζει αν βγει ισοπαλια και αποφασιστει να συνεχιστει το παιχνιδι
	size=7;
    do{
   	    for(i=0;i<size;i++)
   	    {
   	    	for(j=0;j<size;j++)
   	    	{
   	    		m[i][j]='_';
			}
		}
   	winner=0;
	kena=size*size;
	csym=fsym;
	//Ευρεση τωρινου παικτη
	for(i=0;first[i]!='\0';i++)
	{
		current[i]=first[i];
	}
	current[i]='\0';
	//Task 3
	//Παιχνιδι
	while(kena>0 && winner==0)
	{
		//Ελεγχος θεσης εισαγωγης του συμβολου
	do{
		printf("%s: ",current);
		scanf("%d %d",&r,&c);
		if(r<0 || c<0 || r>size-1 || c>size-1)
		{
		    printf("Out of bonds, enter again: \n");
	    }
	    else if( m[r][c]!='_')
	    {
	    	printf("Position taken, enter again: \n");
		}
		else
		{
			break;
		}
	}while(1);
	m[r][c]=csym;
	kena--;
	//Εμφανιση τριλιζες με τις εισαγωγεσ
	printf("\n");
	printf("  ");
	for(j=0;j<size;j++)
	{
		printf("%d ",j);
	}
	printf("\n");
	for(i=0;i<size;i++)
	{
		printf("%d",i);
		for(j=0;j<size;j++)
		{
			printf(" %c",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	if(kena==0)
	{
		break;
	}
    //Ελεγχος νικητη
    // Για καθε γραμμη
    for(i=0;i<size;i++)
    {
       	for(j=0;j<size-3;j++)
		{  //Τα size-3 ειναι για να μην βγουμε εκτος πινακα στους παρακατω ελεγχους
       		if(m[i][j]==csym && m[i][j+1]==csym && m[i][j+2]==csym && m[i][j+3]==csym)//
       		{
       			winner=1;
       			
			}
       		
		}
	}
	   
	   //Eλεγχος για καθε στηλη
	   for(j=0;j<size;j++)
       {
       	    for(i=0;i<size-3;i++)
       	    {
       		    if(m[i][j]==csym && m[i+1][j]==csym && m[i+2][j]==csym && m[i+3][j]==csym)
       		    {
       			    winner=1;
       			
			    }
       		
		    }
	   }
	   
	   //Ελεγχος για διαγωνιo
	   for(i=0;i<size-3;i++)
	   {
	   	    for(j=0;j<size-3;j++)
	   	    {
	   		    if(m[i][j]==csym && m[i+1][j+1]==csym && m[i+2][j+2]==csym && m[i+3][j+3]==csym)
	   		    {
	   			winner=1;
	   			
		  	    }
	   		
		    }
	   }
	   //Ελεγχος για ανιστροφη διαγωνιo
	   for(i=0;i<size-3;i++)
	   {
	   	    for(j=3;j<size;j++)
	   	    {
	   		    if(m[i][j]==csym && m[i+1][j-1]==csym && m[i+2][j-2]==csym && m[i+3][j-3]==csym)
	   		    { 
	   			winner=1;
			    }
		    }
	   }
	   if(winner==1)
	   {
	   	    printf("%s won!\n",current);
	   	    break;
	   }
	
	//Αλλαγη παικτη
	if(csym==fsym)
	{
		csym=ssym;
		for(i=0;second[i]!='\0';i++)
		{
		    current[i]=second[i];
		}
	current[i]='\0';
		
	}
	else
	{
		csym=fsym;
		for(i=0;first[i]!='\0';i++)
		{
			current[i]=first[i];
		}
	    current[i]='\0';
	}
    }
	if(winner==0)
	{
		printf("Draw\n");
		// Task 4
		if(size==8)
		{
			printf("Game over\n");
			break;
		}
		do
		{
		
		    printf("Do you want to continue the game, enter Y(Yes) to continue or N(No) to stop: ");
		    scanf(" %c",&ans);
		    if(ans!='Y' && ans!='N')
		    {
		    	printf("Error only 'Y' and 'N' allowed\n");
			}
        }while(ans!='Y' && ans!='N');
		if(ans=='Y')
		{
			size=8;
			
		}
		else if(ans=='N')
		{
			break;
		}
	}	
    }while(size==8);
	return 0;
}
