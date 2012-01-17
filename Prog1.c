// The program has been written in C
//Compiler used is GCC
// Programmed by - TUSHAR RAJPAL (201012055)- M.Sc(IT)- DAIICT
#include<stdio.h>
#include<conio.h>
# define MAXSIZE 10


int stack[MAXSIZE];
int top;
  void main()
		{
			void push(int);
			int pop();
			void display(int);
			int choice=1;
			int  i, num;
		
			while(choice==1)
			{
					printf("		****MAIN MENU****\n");
					printf("		1.Add element to stack\n");	
					printf("		2.Delete element from the stack\n");
					printf("		3.Show stack\n");
	
	
					scanf("%d",&choice);
						switch(choice)
							{
								case 1:printf("Enter the data... ");
								scanf("%d",&num);
								push(num);
								break;
								case 2: i=pop();
								printf("Value returned from pop function is  %d ",i);
								break;
								case 3: display(top);
								break;
								default: printf("Invalid Choice . ");
							}
								printf(" \nDo you want to do more operations on Stack ( 1 for yes, any letter key to exit) ");
								scanf("%d" , &choice);
			}
		}



	void push(int y)
	{
		
		if(top>MAXSIZE)
		{
			printf("STACK FULL");
			return;
		}
		else
		{
			if(stack[top]==y-1)
			{
				top++;
				stack[top]=y;
				printf("\n Value Sucessfully Inserted into the stack. Press any key to continue\n");
				getch();
			}
			else
			printf("You entered wrong data, only next immediate number can be inserted\n");
		}
	}

	int pop()
		{
			int a;
			if(top<=0)
			{
				printf("STACK EMPTY\n");
				return 0;
			}
			else
			{
				a=stack[top];
				top--;
			}
			return(a);
		}
		
	void display(int m)
		{
		int counter;
		printf("YOUR STACK\n");
		for(counter=top;counter>=0;counter--)
		{
		printf("%d",stack[counter]);
		printf("\n");
		}
		}
		