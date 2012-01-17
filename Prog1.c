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


-------------------------------------------------------------------------------------------------------------------

PROG 2/question1 part b


package stack;

import java.util.Scanner;

class Stack
{
	int num[];
	int tos;
	
	public Stack()
	{
		num = new int[50];
		tos=-1;
	}
	public void push(int i)
	{
		tos++;
		try
		{
			num[tos] = i;
		}catch(ArrayIndexOutOfBoundsException ae)
		{
			System.out.println(ae);
		}catch(Exception e)
		{
			System.out.println(e);
		}
	}
	@SuppressWarnings("finally")
	public int pop()
	{
		int i = -1;
		try
		{
			i = num[tos];
			tos--;
		}catch(ArrayIndexOutOfBoundsException ae)
		{
			System.out.println(ae);
		}catch(Exception e)
		{
			System.out.println(e);
		}finally
		{
			return i;
		}
	}
	public int getTos()
	{
		return tos;
	}
}

public class Prog1 {
	public static void main(String a[])
	{
		Stack s = new Stack();
		Scanner sd = new Scanner(System.in);
		int c;
		int pattern[] = new int[0];
		int length;
		while(true)
		{
			System.out.println("1.Enter Pattern-");
			System.out.println("2.Check Pattern-");
			System.out.println("3.Print Pattern-");
			System.out.println("4.Exit");
			
			System.out.println("Enter Your Choice-");
			try{
				c = Integer.parseInt(sd.nextLine());
			}catch(Exception e)
			{
				c=5;
			}
			
			switch(c)
			{
				case 1:
					System.out.println("Enter length of your pattern-");
					length = sd.nextInt();
					pattern = new int[length];
					for(int i = 0; i < length; i++)
					{
						pattern[i] = sd.nextInt();
					}
					break;
				case 2:
					if(s.getTos() == -1 && pattern.length != 0)
					{
						int dummy = 1;
						boolean flag = false;
						int counter = 1;
						int temp = pattern[0];
						
						while(true)
						{
							System.out.println(counter + " " + temp + " " + pattern[counter]);
							flag = false;
							while(temp - pattern[counter] == 1 )
							{
								temp = pattern[counter];
								System.out.println(counter + " " + temp + " " + pattern[counter]);
								counter++;
								if(counter == pattern.length || counter == (pattern.length-1))
								{
									System.out.println("Its Achievable");
									dummy = 3;
									break;
								}
								flag = true;
								dummy = 1;
							}
							temp = pattern[counter];
							counter++;
							if(dummy == 2)
							{
								System.out.println("Its not Achievable");
								break;
							}
							if(dummy == 3)
							{
								break;
							}
							if(flag == false)
							{
								dummy++;
							}
							else
							{
								dummy = 1;
							}
						}
					}
					break;
				case 3:
					try
					{
						for(int i = 0; i < pattern.length; i++)
						{
							System.out.println(" " + pattern[i]);
						}
					}catch(Exception e)
					{
						System.out.println(e);
					}
					break;
				case 4:
					System.exit(0);
				case 5:
					break;
				default:
					System.out.println("Invalid Input");
			}
		}
	}
}

		}
		
		--------------------------------------------------------------------------------------------
		
		
Program 3 - Game Program

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>	


typedef struct node {
    int data;
    struct node *next;
}Link;

Link *first, *last;


int startGame(int gap){
        Link *temp=first;
        Link *back;
	int i;
        while(temp->next!=temp){
            for(i=2;i<=gap;i++){
                back=temp;
                temp=temp->next;
            }
            back->next=temp->next;
            temp=temp->next;
        }
        return temp->data;
    }

void insert(int data){
        Link *temp= (Link *)malloc(sizeof(Link));
	temp->data=data;
        if(first==NULL&&last==NULL){
            temp->next=last;
            last=temp;
            first=temp;
        }
        else{

            temp->next=first;
            first=temp;
        }
    }

void makeCricular(){
        last->next=first;
}


void main() 
	{
	int p,g,k;
        printf("Enter no. of players\t");
        scanf("%d",&p);
        printf("Enter gap\t");
        scanf("%d",&g);
                for (k = p; k >= 1; k--) {
                    insert(k);
                }
                makeCricular();
                printf("Winner will be Player %d\n",startGame(g));

}


		
		