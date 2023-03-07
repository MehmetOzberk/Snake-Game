#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int Harita_bastir(int harita[21][21],int Score);
int getch_noblock();
int randomx(int k,int kuyruk,int Kuyrukx[1000],int Kafax);
int randomy(int k,int kuyruk,int Kuyruky[1000], int Kafay);
int main() 
{
	int harita[21][21],i,j,kafax,kafay,meyvex,meyvey,game,kuyruk=0,k,score=0,Game;
	unsigned char yon;
	char yon2=0;
	kafax=11;
	kafay=11;
	for(Game=1;Game==1;)
	{int  kuyrukx[10000],kuyruky[10000];
		char yon2=0,restart;
	meyvex=randomx(k,kuyruk,kuyrukx,kafax);
	meyvey=randomy(k,kuyruk,kuyruky,kafay);	
		for(game=1;game==1;)
		{
			for(j=0;j<21;j++)	
			{ 	for(i=0;i<21;i++)
		 		{
					if((i==0 && j!=0 && j!=21) || (i==20 && j!=0 && j!=21))
					{
						harita[j][i]=1;
					}
					else if(j==0  || j==21)
					{
						harita[j][i]=2;		
					}
					else 
					{
						harita[j][i]=0;
					}
				}		
			}
			
			harita[kafay][kafax]=3;
			if(kuyruk>0)
			{
				for(k=0;k<kuyruk;k++)
				{harita[kuyruky[k+1]][kuyrukx[k+1]]=4;}
			}
			harita[meyvey][meyvex]=5;
					
			Harita_bastir(harita,score);
			yon=getch_noblock();
		        if(yon==0 ||yon ==0xE0)
		        {
				yon=getch_noblock();
		         switch(yon)
		         {
				 
		         case 72:
					for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}		
		         	kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
					 kafay--;
		         	yon2=72;
		         	break;
		         case 80:
		         	for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}
		         	kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
		         	kafay++;
		         	yon2=80;
		         	break;
		         case 75:
		         	for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}
				 	kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
					kafax--;
				 	yon2=75;
				 	break;
				 case 77:
				 	for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}
				    kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
					kafax++;
				    yon2=77;
					break;	
		    	 }
		    	 
			    }
			    else if(yon=-1)
			    {switch(yon2)
		         {
				 
		         case 72:
		         	for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}
		         	kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
					kafay--;
		         	break;
		         case 80:
		         	for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}
		         	kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
					kafay++;
		         	break;
		         case 75:
		         	for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}
				 	kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
					kafax--;
				 	break;
				 case 77:
				 	for(k=kuyruk;k>=2;k--)
					{
	 				kuyrukx[k]=kuyrukx[k-1];
   					kuyruky[k]=kuyruky[k-1];
   					}
				    kuyrukx[1]=kafax;
		    		kuyruky[1]=kafay;
					kafax++;
					break;	
		    	 }
			    	
				}
			if(kafax == meyvex && kafay == meyvey)
			{meyvex=randomx(k,kuyruk,kuyrukx,kafax);
			 meyvey=randomy(k,kuyruk,kuyruky,kafay);
			 kuyruk++;
			 score++;	
			}
			if((kafax==19||kafax==0||kafay==19||kafay==0) )
			{game=0;}				
		
		usleep(100000);
		system("cls");		
			for(k=0;k<kuyruk;k++)
			{
				if(kafax==kuyrukx[k+1] && kafay==kuyruky[k+1])
				{printf("Game Over\t Score:%d\n",score);
				printf("Restart Y/N\t");
				restart=getch();
					if(restart=='Y'||restart=='y')
					{game=1;i=1;kafax=11;kafay=11;kuyruk=0;score=0;}
					else
					{i=0; game=0; Game=0; break;}
				}		
			}
		}//game
printf("Game Over\t Score:%d\n",score);
sleep(2);
printf("Restart Y/N\t");
restart=getch();
	if(restart=='Y'||restart=='y')
	{game=1;i=1;kafax=11;kafay=11;kuyruk=0;}
	else
	{i=0; game=0; break; Game=0;}
}//Game
return 0;		
}
int Harita_bastir(int harita[21][21], int score)
{int j,i,z;
printf("X------------------X");
printf("Score:%d\n",score);
	for(j=1;j<19;j++)	
	{z=0; 
	printf("|");
   		for (i=1;i<19;i++)
   		{	if(harita[j][i] == 0)
		  	{z++;} 
			if(z==19)
			{printf("                   ");}
			else
			{
				for(i=1;i<19;i++)
				{ 	if(harita[j][i]==0)
					{printf(" ");}			
					else if (harita[j][i]==3)
					{printf("O");}
					else if (harita[j][i]==4)
					{printf("*");}
					else if (harita[j][i]==5)
					{printf("G");}
				}
			}
		}
	printf("|\n");	
	}
printf("X------------------X");	
return 0;	
}	
int getch_noblock() 
{
    if (_kbhit())
        return _getch();
    else
        return -1 ;
}	
int randomx(int k, int kuyruk,int Kuyrukx[k],int Kafax)
{ int returnx,c,p;
 returnx = rand()%18 + 1;
 	for(c=0;c==0;)
	{
	  	if(returnx == Kafax)
		{returnx = rand()%18 + 1;}
		else 
		{break;}
	}
	for(c=0;c==0;)
	{
		for(p=0;p<=kuyruk;p++)
		{
			if(returnx==Kuyrukx[p])
			{returnx = rand()%18 + 1;}
			else
			{break;}
		}
	break;	
	}
return returnx;	
}
int randomy(int k ,int kuyruk, int Kuyruky[k], int Kafay)
{ int returny,c,p;
 returny = rand()%18 + 1;
 	for(c=0;c==0;)
	{
	  	if(returny == Kafay)
		{returny = rand()%18 + 1;}
		else 
		{
		break;
		}
	}
	for(c=0;c==0;)
	{
		for(p=0;p<=kuyruk;p++)
		{
			if(returny==Kuyruky[p])
			{returny = rand()%18 + 1;}
			else
			{
				break;
			}
		}
	break;	
	}
	return returny;
}	
