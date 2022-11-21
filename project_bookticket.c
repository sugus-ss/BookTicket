#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void bookTicket();	
void chaingmai1();
void chaingmai2();
void nakorn1();
void nakorn2();
void display();		
void writeData();

int main()
{
	char input[64];
	int choice = 0;
	while(choice!=3)
	{
		printf("\nHello, what can we help you?\n");
		printf("1. Book Ticket\n");
		printf("2. Display Information\n");
		printf("3. Exit\n");
		printf("Choice: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&choice);
		switch(choice)
		{
			case 1:
				bookTicket();
				break;
			case 2:
				display();
				break;
			case 3:
				printf("Thank you\n");	
				writeData();
				break;
			default:
				printf("Please type 1 to 3\n");		
		}
	}	
}				

void bookTicket()
{
	char input[64];
	int choice = 0;
	int time = 0;
	while(choice!=1 && choice!=2 && choice!=3)
	{
		printf("\nPlease choose your destination\n");
		printf("1. Bangkok-Chiangmai\n");
		printf("2. Bangkok-Nakornsrithammarat\n");
		printf("3. Cancel\n");
		printf("Choice: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\nWhen do you want to travel?\n");
				printf("1. 9.00 AM\n");
				printf("2. 6.00 PM\n");
				printf("3. Cancel\n");
				printf("Choice: ");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%d",&time);
				if(time == 1)
				{
					chaingmai1();					
				}
				else if(time == 2)
				{
					chaingmai2();
				}
				else
				{
					break;
				}
				break;
			case 2:
				printf("\nWhen do you want to travel?\n");
				printf("1. 9.00 AM\n");
				printf("2. 6.00 PM\n");
				printf("3. Cancel\n");
				printf("Choice: ");
				fgets(input,sizeof(input),stdin);
				sscanf(input,"%d",&time);
				if(time == 1)
				{
					nakorn1();					
				}
				else if(time == 2)
				{
					nakorn2();
				}
				else
				{
					break;
				}
				break;
			case 3:
				break;
			default:
				printf("Please type 1 to 3\n");		
		}
	}/*end while loop*/
}
					
void chaingmai1()
{
	char seat[34][3] = {"1A","1B","1C","1D","2A","2B","2C","2D",
					    "3A","3B","3C","3D","4A","4B","4C","4D",
					    "5C","5D","6A","6B","6C","6D",
						"7A","7B","7C","7D","8A","8B","8C","8D",
						"9A","9B","9C","9D"};
	FILE *pIn = NULL;
	FILE *pOut = NULL;
	char filename[64] = "chaingmai1.txt";
	char userSeat[64];
	char input[64];
	char name[64];
	int bookedSeat[5] = {-1,-1,-1,-1,-1};
	int result = 0;					
	int capacity = 34;
	int count = 0;	
	int price = 0;	
	int i = 0;
	int j = 0;
	
	pIn = fopen(filename,"r");
	while(fgets(input,sizeof(input),pIn) != NULL)/*check booked seat*/
	{
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		for(j=0;j<5;j++)
		{
			for(i=0;i<34;i++)
			{
				if(bookedSeat[j] == i)
				{
					capacity--;
					strcpy(seat[i],"--");	
				}
			}
			bookedSeat[j] = -1;
		}
		fgets(input,sizeof(input),pIn);
	}
	j = 0;
	fclose(pIn);
	printf("Enter your name: ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%[^\n]",name);		
	while(strncmp(userSeat,"-",1) != 0)/*Enter - to stop*/
	{
		printf("\nSeat mapping of Bangkok-Chiangmai tour bus\n");
		printf("Time to leave : 9.00 AM\n");
		printf("Capacity : 34\n");
		printf("Available : %d\n",capacity);
		printf("Price : 450 THB per seat\n");
		printf("_________________________________________\n");
		printf("|                                       |\n");
		printf("|   %s      %s             %s      %s   |\n",seat[0],seat[1],seat[2],seat[3]);	
		printf("|   %s      %s             %s      %s   |\n",seat[4],seat[5],seat[6],seat[7]);
		printf("|   %s      %s             %s      %s   |\n",seat[8],seat[9],seat[10],seat[11]);
		printf("|   %s      %s             %s      %s   |\n",seat[12],seat[13],seat[14],seat[15]);
		printf("|                          %s      %s   |\n",seat[16],seat[17]);
		printf("|   %s      %s             %s      %s   |\n",seat[18],seat[19],seat[20],seat[21]);
		printf("|   %s      %s             %s      %s   |\n",seat[22],seat[23],seat[24],seat[25]);
		printf("|   %s      %s             %s      %s   |\n",seat[26],seat[27],seat[28],seat[29]);
		printf("|   %s      %s             %s      %s   |\n",seat[30],seat[31],seat[32],seat[33]);				
		printf("|_______________________________________|\n\n");
		printf("Enter '-' to stop\n");
		printf("Enter seat number: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%[^\n]",userSeat);
		if(strncmp(userSeat,"-",1) != 0)/*compare seat that - to stop, !=0 not -*/
		{
			for(i=0;i<34;i++)
			{
				if(strncmp(userSeat,seat[i],2) == 0)/*bookable*/
				{			
					price = price + 450;
					bookedSeat[j] = i;
					j++;
					capacity--;
					strcpy(seat[i],"--");
					result = 1;	
				}
			}
			if(result == 0)
			{
				printf("\n**ERROR - %s is not available**\n\n",userSeat);
			}
			result = 0;
		}	
	}
	printf("Booking Completed\n");
	pOut = fopen(filename,"a");
	fprintf(pOut,"%s\n",name);
	fprintf(pOut,"%d %d %d %d %d\n",bookedSeat[0],bookedSeat[1],bookedSeat[2],bookedSeat[3],bookedSeat[4]);
	fprintf(pOut,"%d\n",price);
	fclose(pOut);
}

void chaingmai2()
{
	char seat[34][3] = {"1A","1B","1C","1D","2A","2B","2C","2D",
					    "3A","3B","3C","3D","4A","4B","4C","4D",
					    "5C","5D","6A","6B","6C","6D",
						"7A","7B","7C","7D","8A","8B","8C","8D",
						"9A","9B","9C","9D"};
	FILE *pIn = NULL;
	FILE *pOut = NULL;
	char filename[64] = "chaingmai2.txt";
	char userSeat[64];
	char input[64];
	char name[64];
	int bookedSeat[5] = {-1,-1,-1,-1,-1};
	int result = 0;					
	int capacity = 34;
	int count = 0;	
	int price = 0;	
	int i = 0;
	int j = 0;
	
	pIn = fopen(filename,"r");/*read file chaingmai2.txt*/
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		for(j=0;j<5;j++)
		{
			for(i=0;i<34;i++)
			{
				if(bookedSeat[j] == i)
				{
					capacity--;
					strcpy(seat[i],"--");	
				}
			}
			bookedSeat[j] = -1;
		}
		fgets(input,sizeof(input),pIn);
	}
	j = 0;
	fclose(pIn);/*close file*/
	printf("Enter your name: ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%[^\n]",name);		
	while(strncmp(userSeat,"-",1) != 0)
	{
		printf("\nSeat mapping of Bangkok-Chiangmai tour bus\n");
		printf("Time to leave : 6.00 PM\n");
		printf("Capacity : 34\n");
		printf("Available : %d\n",capacity);
		printf("Price : 450 THB per seat\n");
		printf("_________________________________________\n");
		printf("|                                       |\n");
		printf("|   %s      %s             %s      %s   |\n",seat[0],seat[1],seat[2],seat[3]);	
		printf("|   %s      %s             %s      %s   |\n",seat[4],seat[5],seat[6],seat[7]);
		printf("|   %s      %s             %s      %s   |\n",seat[8],seat[9],seat[10],seat[11]);
		printf("|   %s      %s             %s      %s   |\n",seat[12],seat[13],seat[14],seat[15]);
		printf("|                          %s      %s   |\n",seat[16],seat[17]);
		printf("|   %s      %s             %s      %s   |\n",seat[18],seat[19],seat[20],seat[21]);
		printf("|   %s      %s             %s      %s   |\n",seat[22],seat[23],seat[24],seat[25]);
		printf("|   %s      %s             %s      %s   |\n",seat[26],seat[27],seat[28],seat[29]);
		printf("|   %s      %s             %s      %s   |\n",seat[30],seat[31],seat[32],seat[33]);				
		printf("|_______________________________________|\n\n");
		printf("Enter '-' to stop\n");
		printf("Enter seat number: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%[^\n]",userSeat);
		if(strncmp(userSeat,"-",1) != 0)
		{
			for(i=0;i<34;i++)
			{
				if(strncmp(userSeat,seat[i],3) == 0)/*bookable*/
				{			
					price = price + 450;
					bookedSeat[j] = i;
					j++;
					capacity--;
					strcpy(seat[i],"--");
					result = 1;	
				}
			}
			if(result == 0)
			{
				printf("\n**ERROR - %s is not available**\n\n",userSeat);
			}
			result = 0;
		}	
	}
	printf("Booking Completed\n");
	pOut = fopen(filename,"a");
	fprintf(pOut,"%s\n",name);
	fprintf(pOut,"%d %d %d %d %d\n",bookedSeat[0],bookedSeat[1],bookedSeat[2],bookedSeat[3],bookedSeat[4]);
	fprintf(pOut,"%d\n",price);
	fclose(pOut);
}

void nakorn1()
{
	char seat[34][3] = {"1A","1B","1C","1D","2A","2B","2C","2D",
					    "3A","3B","3C","3D","4A","4B","4C","4D",
					    "5C","5D","6A","6B","6C","6D",
						"7A","7B","7C","7D","8A","8B","8C","8D",
						"9A","9B","9C","9D"};
	FILE *pIn = NULL;
	FILE *pOut = NULL;
	char filename[64] = "nakhon1.txt";
	char userSeat[64];
	char input[64];
	char name[64];
	int bookedSeat[5] = {-1,-1,-1,-1,-1};
	int result = 0;					
	int capacity = 34;
	int count = 0;	
	int price = 0;	
	int i = 0;
	int j = 0;
	
	pIn = fopen(filename,"r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		for(j=0;j<5;j++)
		{
			for(i=0;i<34;i++)
			{
				if(bookedSeat[j] == i)
				{
					capacity--;
					strcpy(seat[i],"--");	
				}
			}
			bookedSeat[j] = -1;
		}
		fgets(input,sizeof(input),pIn);
	}
	j = 0;
	fclose(pIn);
	printf("Enter your name: ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%[^\n]",name);		
	while(strncmp(userSeat,"-",1) != 0)
	{
		printf("\nSeat mapping of Bangkok-Nakornsrithammarat tour bus\n");
		printf("Time to leave : 9.00 AM\n");
		printf("Capacity : 34\n");
		printf("Available : %d\n",capacity);
		printf("Price : 500 THB per seat\n");
		printf("_________________________________________\n");
		printf("|                                       |\n");
		printf("|   %s      %s             %s      %s   |\n",seat[0],seat[1],seat[2],seat[3]);	
		printf("|   %s      %s             %s      %s   |\n",seat[4],seat[5],seat[6],seat[7]);
		printf("|   %s      %s             %s      %s   |\n",seat[8],seat[9],seat[10],seat[11]);
		printf("|   %s      %s             %s      %s   |\n",seat[12],seat[13],seat[14],seat[15]);
		printf("|                          %s      %s   |\n",seat[16],seat[17]);
		printf("|   %s      %s             %s      %s   |\n",seat[18],seat[19],seat[20],seat[21]);
		printf("|   %s      %s             %s      %s   |\n",seat[22],seat[23],seat[24],seat[25]);
		printf("|   %s      %s             %s      %s   |\n",seat[26],seat[27],seat[28],seat[29]);
		printf("|   %s      %s             %s      %s   |\n",seat[30],seat[31],seat[32],seat[33]);				
		printf("|_______________________________________|\n\n");
		printf("Enter '-' to stop\n");
		printf("Enter seat number: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%[^\n]",userSeat);
		if(strncmp(userSeat,"-",1) != 0)
		{
			for(i=0;i<34;i++)
			{
				if(strncmp(userSeat,seat[i],3) == 0)/*bookable*/
				{			
					price = price + 500;
					bookedSeat[j] = i;
					j++;
					capacity--;
					strcpy(seat[i],"--");
					result = 1;	
				}
			}
			if(result == 0)
			{
				printf("\n**ERROR - %s is not available**\n\n",userSeat);
			}
			result = 0;
		}	
	}
	printf("Booking Completed\n");
	pOut = fopen(filename,"a");
	fprintf(pOut,"%s\n",name);
	fprintf(pOut,"%d %d %d %d %d\n",bookedSeat[0],bookedSeat[1],bookedSeat[2],bookedSeat[3],bookedSeat[4]);
	fprintf(pOut,"%d\n",price);
	fclose(pOut);
	
}

void nakorn2()
{
	char seat[34][3] = {"1A","1B","1C","1D","2A","2B","2C","2D",
					    "3A","3B","3C","3D","4A","4B","4C","4D",
					    "5C","5D","6A","6B","6C","6D",
						"7A","7B","7C","7D","8A","8B","8C","8D",
						"9A","9B","9C","9D"};
	FILE *pIn = NULL;
	FILE *pOut = NULL;
	char filename[64] = "nakhon2.txt";
	char userSeat[64];
	char input[64];
	char name[64];
	int bookedSeat[5] = {-1,-1,-1,-1,-1};
	int result = 0;					
	int capacity = 34;
	int count = 0;	
	int price = 0;	
	int i = 0;
	int j = 0;
	
	pIn = fopen(filename,"r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		for(j=0;j<5;j++)
		{
			for(i=0;i<34;i++)
			{
				if(bookedSeat[j] == i)
				{
					capacity--;
					strcpy(seat[i],"--");	
				}
			}
			bookedSeat[j] = -1;
		}
		fgets(input,sizeof(input),pIn);
	}
	j = 0;
	fclose(pIn);
	printf("Enter your name: ");
	fgets(input,sizeof(input),stdin);
	sscanf(input,"%[^\n]",name);		
	while(strncmp(userSeat,"-",1) != 0)
	{
		printf("\nSeat mapping of Bangkok-Nakornsrithammarat tour bus\n");
		printf("Time to leave : 6.00 PM\n");
		printf("Capacity : 34\n");
		printf("Available : %d\n",capacity);
		printf("Price : 500 THB per seat\n");
		printf("_________________________________________\n");
		printf("|                                       |\n");
		printf("|   %s      %s             %s      %s   |\n",seat[0],seat[1],seat[2],seat[3]);	
		printf("|   %s      %s             %s      %s   |\n",seat[4],seat[5],seat[6],seat[7]);
		printf("|   %s      %s             %s      %s   |\n",seat[8],seat[9],seat[10],seat[11]);
		printf("|   %s      %s             %s      %s   |\n",seat[12],seat[13],seat[14],seat[15]);
		printf("|                          %s      %s   |\n",seat[16],seat[17]);
		printf("|   %s      %s             %s      %s   |\n",seat[18],seat[19],seat[20],seat[21]);
		printf("|   %s      %s             %s      %s   |\n",seat[22],seat[23],seat[24],seat[25]);
		printf("|   %s      %s             %s      %s   |\n",seat[26],seat[27],seat[28],seat[29]);
		printf("|   %s      %s             %s      %s   |\n",seat[30],seat[31],seat[32],seat[33]);				
		printf("|_______________________________________|\n\n");
		printf("Enter '-' to stop\n");
		printf("Enter seat number: ");
		fgets(input,sizeof(input),stdin);
		sscanf(input,"%[^\n]",userSeat);
		if(strncmp(userSeat,"-",1) != 0)
		{
			for(i=0;i<34;i++)
			{
				if(strncmp(userSeat,seat[i],3) == 0)/*bookable*/
				{			
					price = price + 500;
					bookedSeat[j] = i;
					j++;
					capacity--;
					strcpy(seat[i],"--");
					result = 1;	
				}
			}
			if(result == 0)
			{
				printf("\n**ERROR - %s is not available**\n\n",userSeat);
			}
			result = 0;
		}	
	}
	printf("Booking Completed\n");
	pOut = fopen(filename,"a");
	fprintf(pOut,"%s\n",name);
	fprintf(pOut,"%d %d %d %d %d\n",bookedSeat[0],bookedSeat[1],bookedSeat[2],bookedSeat[3],bookedSeat[4]);
	fprintf(pOut,"%d\n",price);
	fclose(pOut);
}
void display()
{	
	char seat[34][3] = {"1A","1B","1C","1D","2A","2B","2C","2D",
					"3A","3B","3C","3D","4A","4B","4C","4D",
					"5C","5D","6A","6B","6C","6D",
					"7A","7B","7C","7D","8A","8B","8C","8D",
					"9A","9B","9C","9D"};
	FILE *pIn = NULL;
	
	char input[64];
	char name[64];
	int bookedSeat[5] = {-1,-1,-1,-1,-1};
	int price = 0;
	int i = 0;
	int j = 0;	
	pIn = fopen("chaingmai1.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		printf("\n********************************\n");
		printf("  %s\n",name);
		printf("  Bangkok-Chaingmai\n");
		printf("  09.00 AM\n");
		for(j=0;j<5;j++)/*,*/
		{
			if(bookedSeat[j] != -1 && j == 0)/*first*/
			{
				printf("  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				printf(",%s",seat[bookedSeat[j]]);	
			}
		}
		printf("\n");
		printf("  Price : %d THB\n",price);
	}
	fclose(pIn);
	
	pIn = fopen("chaingmai2.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		printf("\n********************************\n");
		printf("  %s\n",name);
		printf("  Bangkok-Chaingmai\n");
		printf("  6.00 PM\n");
		for(j=0;j<5;j++)
		{
			if(bookedSeat[j] != -1 && j == 0)
			{
				printf("  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				printf(",%s",seat[bookedSeat[j]]);	
			}
		}
		printf("\n");
		printf("  Price : %d THB\n",price);
	}
	fclose(pIn);
	
	pIn = fopen("nakhon1.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		printf("\n********************************\n");
		printf("  %s\n",name);
		printf("  Bangkok-Nakornsrithammarat\n");
		printf("  9.00 AM\n");
		for(j=0;j<5;j++)
		{
			if(bookedSeat[j] != -1 && j == 0)
			{
				printf("  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				printf(",%s",seat[bookedSeat[j]]);	
			}
		}
		printf("\n");
		printf("  Price : %d THB\n",price);
	}
	fclose(pIn);
	
	pIn = fopen("nakhon2.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		printf("\n********************************\n");
		printf("  %s\n",name);
		printf("  Bangkok-Nakornsrithammarat\n");
		printf("  6.00 PM\n");
		for(j=0;j<5;j++)
		{
			if(bookedSeat[j] != -1 && j == 0)
			{
				printf("  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				printf(",%s",seat[bookedSeat[j]]);	
			}
		}
		printf("\n");
		printf("  Price : %d THB\n",price);
	}
	fclose(pIn);
	printf("\n********************************\n");
}

void writeData()
{
	char seat[34][3] = {"1A","1B","1C","1D","2A","2B","2C","2D",
					"3A","3B","3C","3D","4A","4B","4C","4D",
					"5C","5D","6A","6B","6C","6D",
					"7A","7B","7C","7D","8A","8B","8C","8D",
					"9A","9B","9C","9D"};
	FILE *pIn = NULL;
	FILE *pOut = NULL;
	char input[64];
	char name[64];
	int bookedSeat[5] = {-1,-1,-1,-1,-1};
	int price = 0;
	int i = 0;
	int j = 0;	
	pIn = fopen("chaingmai1.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		pOut = fopen("CustomerDatabase.txt","a");
		fprintf(pOut,"\n********************************\n");
		fprintf(pOut,"  %s\n",name);
		fprintf(pOut,"  Bangkok-Chaingmai\n");
		fprintf(pOut,"  9.00 AM\n");
		for(j=0;j<5;j++)
		{
			if(bookedSeat[j] != -1 && j == 0)
			{
				fprintf(pOut,"  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				fprintf(pOut,",%s",seat[bookedSeat[j]]);	
			}
		}
		fprintf(pOut,"\n");
		fprintf(pOut,"  Price : %d THB\n",price);
	}
	fclose(pIn);
	
	pIn = fopen("chaingmai2.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		fprintf(pOut,"\n********************************\n");
		fprintf(pOut,"  %s\n",name);
		fprintf(pOut,"  Bangkok-Chaingmai\n");
		fprintf(pOut,"  6.00 PM\n");
		for(j=0;j<5;j++)
		{
			if(bookedSeat[j] != -1 && j == 0)
			{
				fprintf(pOut,"  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				fprintf(pOut,",%s",seat[bookedSeat[j]]);	
			}
		}
		fprintf(pOut,"\n");
		fprintf(pOut,"  Price : %d THB\n",price);
	}
	fclose(pIn);
	
	pIn = fopen("nakhon1.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		fprintf(pOut,"\n********************************\n");
		fprintf(pOut,"  %s\n",name);
		fprintf(pOut,"  Bangkok-Nakornsrithammarat\n");
		fprintf(pOut,"  9.00 AM\n");
		for(j=0;j<5;j++)
		{
			if(bookedSeat[j] != -1 && j == 0)
			{
				fprintf(pOut,"  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				fprintf(pOut,",%s",seat[bookedSeat[j]]);	
			}
		}
		fprintf(pOut,"\n");
		fprintf(pOut,"  Price : %d THB\n",price);
	}
	fclose(pIn);
	
	pIn = fopen("nakhon2.txt","r");
	while(fgets(input,sizeof(input),pIn) != NULL)
	{
		sscanf(input,"%[^\n]",name);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d %d %d %d %d",&bookedSeat[0],&bookedSeat[1],&bookedSeat[2],&bookedSeat[3],&bookedSeat[4]);
		fgets(input,sizeof(input),pIn);
		sscanf(input,"%d",&price);
		fprintf(pOut,"\n********************************\n");
		fprintf(pOut,"  %s\n",name);
		fprintf(pOut,"  Bangkok-Nakornsrithammarat\n");
		fprintf(pOut,"  6.00 PM\n");
		for(j=0;j<5;j++)
		{
			if(bookedSeat[j] != -1 && j == 0)
			{
				fprintf(pOut,"  %s",seat[bookedSeat[j]]);	
			}
			else if(bookedSeat[j] != -1)
			{
				fprintf(pOut,",%s",seat[bookedSeat[j]]);	
			}
		}
		fprintf(pOut,"\n");
		fprintf(pOut,"  Price : %d THB\n",price);
	}
	fclose(pIn);
	fprintf(pOut,"\n********************************\n");
	fclose(pOut);
}


