#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<fcntl.h>
#include<termios.h>
#include<unistd.h>
#define M 20
#define N 70
 
 int i,j,field[M][N],x,y,head,tail,game,a,b,frog,var,dir,score,hs;
 char c;
int main()
{
        system("clear");
         
      snake_init();
      
      
   while(game==0)
{

  fieldplay();
  food();
   
   movement();
 
     
    tailremove();
   
    
      
    points();
  
    gotoxy(0,0);
   
   }
        FILE *fp;
        fp=fopen("hs.txt","r");
         fscanf(fp,"%d",&hs);
          fclose(fp);
         
         if(score>hs)
         {
            hs=score;
           FILE *fp;
           fp=fopen("hs.txt","w");
            fprintf(fp,"%d",hs);
             fclose(fp);
             
             }
           
       
    system("clear");
    printf("Game Over!!!!\n");
    printf("Highscore=%d",hs);
    
   return 0;
   } 

  void fieldplay()
{
for(i=0;i<=M-1;i++)
   {
     for(j=0;j<=N-1;j++)
     {
       if((i>0&&i<M-1)&&(j>0&&j<N-1))
        {
           if(field[i][j]>0&&field[i][j]!=head)
             
             printf("=");
             else if(field[i][j]==head)
              printf("#");
               else if(field[i][j]==-1)
              printf("@");
             else
             printf(" ");
             
        }
        
        
        else
         printf("*");
         
         }
        printf("\n");
        
       }  
   }
   
   void snake_init()
   {
      for(i=1;i<=M-2;i++)
      {
        for(j=1;j<=N-2;j++)
        {
          field[i][j]=0;
          
          }
          
          }
         
         x=M/2;y=N/2;game=0;frog=0,dir='d',score=0 ;
         
         head=5;
         tail=1;
         for(i=0;i<head;i++)
         {
            y++;
            field[x][y]=i+1;
            
            }
            
           
        
        } 
       
   void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
   
}

  void food()
{ 
     srand(time(0));
     a=1+rand()%68;
     b=1+rand()%18;
     
     if(frog==0&&field[b][a]==0)
      {
      field[b][a]=-1;
      frog=1;
          tail-=1;
      
   }
   
  }
  
     void movement()
     {
              if(score<=6)
                usleep(170000);
               else if(score>6&&score<=30)
                usleep(150000);
                else if( score>30&&score<=60)
                 usleep(120000);
                  else if(score>60&&score<=100)
                  usleep(115000);
                  else if(score>100)
                   usleep(100000);
                  
             var= input();
             if(var=='a'||var=='s'||var=='w'||var=='d')
             
              dir=var;
           if(dir=='a')
           {
             y--;
              if(field[x][y]!=0&&field[x][y]!=-1)
                gameover();
             if(y==0)
                gameover();
              
               if(field[x][y]==-1)
                {
               frog=0;
               score+=3;
                system("refresh");
               }
             head++;
             field[x][y]=head;
             
          
          }
             if(dir=='s')
           {
             x++;
              if(field[x][y]!=0&&field[x][y]!=-1)
                gameover();
             if(x==M-1)
               gameover();
               if(field[x][y]==-1)
               {
                 frog=0;
                  score+=3;
                  
                  } 
             head++;
             field[x][y]=head;
          
          }       
          if(dir=='w')
           {
             x--;
              if(field[x][y]!=0&&field[x][y]!=-1)
                gameover();
             if(x==0)
              gameover();
             if(field[x][y]==-1)
               {
                frog=0;
                 score+=3;
                 }
             head++;
             field[x][y]=head;
          
          }
           if(dir=='d')
           {
             y++;
             if(field[x][y]!=0&&field[x][y]!=-1)
                gameover();
             if(y==N-1)
               gameover();
              if(field[x][y]==-1)
              {
               frog=0;
                score+=3;
                }  
             head++;
             field[x][y]=head;
              
          
          }
         
         
       }   
           int input()
          {
             
      int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
 static struct termios old, new;

void initTermios(int echo) 
{
  tcgetattr(0, &old); //grab old terminal i/o settings
  new = old; //make new settings same as old settings
  new.c_lflag &= ~ICANON; //disable buffered i/o
  new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
  tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

char getch(void) 
{
  return getch_(0);
}
 

char getche(void) 
{
  return getch_(1);
}
 


    char c;
    
     
   if(kbhit())
    {
      
        return getch();
      
        
      }
        
       
      
      
      }
         
 
    void tailremove()
    {
         for(i=0;i<=M-1;i++)
         {
           for(j=0;j<=N-1;j++)
           {
               if(field[i][j]==tail)
                   field[i][j]=0;
                   
                   
              }
                
              
                 }        
                 tail++; 
        }  
          
          
          void gameover()
          {
             printf("\a");
             
              game=1;
              
           
            
              }
             
           
        void points()
        {
            gotoxy(80,0);
            printf("score-%d ",score);
            
            
            }
          
          
