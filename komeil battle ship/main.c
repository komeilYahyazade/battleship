#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#define sizeOfTable 10
#define tedade_keshti 2
int tedade_baghimande_1,tedade_baghimande_2 ;
void gameinformation()
{
    printf("***** ship type(size) : A(1) , B(2) *****");
    printf(" directions : 'up' 'down' 'left' 'right' \n\n");
    printf("mokhtasat ra be soorate roo be roo vared konid : ship type @ (a,b) from direction \n");
    printf("** mesal : B @ (2,3) from up **\n\n");
    printf("****** tavajoh konid ke az har type keshti 5 ta darid :)) ******** \n\n");
    printf("Mode ra entekhab konid:\n1.player vs player\n2.player vs AI\n");
}
void meghdardehi_avalie1(char str[][sizeOfTable])
{
    int i;
    for(i=0; i<sizeOfTable; i++)
    {
        int j;
        for( j=0; j<sizeOfTable; j++)
        {
            str[i][j]='0';
        }
    }
}
void meghdardehi_avalie2(char str[][sizeOfTable])
{
    int i;
    for( i=0; i<sizeOfTable; i++)
    {
        int j;
        for( j=0; j<sizeOfTable; j++)
            str[i][j]='?';
    }
}
void show_array(char str[][sizeOfTable])
{
    int i;
    for ( i =0 ; i < sizeOfTable ; i++)
    {
        int j;
        for( j=0 ; j<sizeOfTable ; j++)
        {
            printf("%c ",str[i][j]);
        }
        printf("\n");
    }
}
void estekhraj_va_jagozari(char table[][sizeOfTable],char mokhtasat[][20])
{
    int counter=0;
    int CounterForA=0;
    int CounterForB=0;
    while (counter<tedade_keshti)
    {
        gets(mokhtasat[counter]);
        int sizeOfX=0;
        int x=0;
        int j;
        for ( j=5 ; mokhtasat[counter][j] != ',' ; j++)
        {
            x = x * 10 + (mokhtasat[counter][j]-48);
            sizeOfX++;
        }
        int y=0 ;
        for ( j=6+sizeOfX ; mokhtasat[counter][j] != ')' ; j++)
        {
            y = y * 10 + (mokhtasat[counter][j]-48);
        }
        if(x>sizeOfTable || y>sizeOfTable)
        {
            printf("*********** invalid data for %d omin input ***********\n",counter+1);
            continue ;
        }
        if (table[x][y] != '0')
        {
            printf("dadeye tekrari\n mokhtasate digari vared konid\n");
            continue ;
        }
        if (mokhtasat[counter][0]== 'A' )
        {
            if (CounterForA < (tedade_keshti)/2) //ye eror ine ke age sizeoftsblr fard bashe kharab mishe
            {
                table[x][y]='1';
                CounterForA++ ;
            }
            else
            {
                printf("keshti haye A tamam shode \n az keshtie B estefade konid:\n");
                continue ;
            }
        }
        if (mokhtasat[counter][0]== 'B')
        {
            if ((strstr(mokhtasat[counter],"right") == 0 )&&(strstr(mokhtasat[counter],"left") == 0 )&&(strstr(mokhtasat[counter],"down")== 0)&&(strstr(mokhtasat[counter],"up") == 0)){
                printf("eshtebah dar vared kardane mokhtasat,dobare emtehan konid:\n");
                continue;
            }

            if (CounterForB < (tedade_keshti/2))  //********************
            {
                if(strstr(mokhtasat[counter],"right") != 0 )
                {
                    if((table[x][y-1] != '0') || ((y-1)<0))
                    {
                        printf("%d omin dade tadakhol darad\ndadeye digari vared konid:\n",counter+1);
                        continue ;
                    }
                    table[x][y-1]=CounterForB+50;
                    table[x][y]=CounterForB+50;
                }
                else  if(strstr(mokhtasat[counter],"left") != 0 )
                {

                    if ((table[x][y+1] != '0') || ((y+1)>sizeOfTable))
                    {
                        printf("%d omin dade tadakhol darad\ndadeye digari vared konid:\n",counter+1);
                        continue;
                    }
                    table[x][y]=CounterForB+50;
                    table[x][y+1]=CounterForB+50;
                }
                else  if(strstr(mokhtasat[counter],"up") != 0)
                {
                    if ((table[x+1][y] != '0') || ((x+1)>sizeOfTable))
                    {
                        printf("%d omin dade tadakhol darad\ndadeye digari vared konid:\n",counter+1);
                        continue ;
                    }
                    table[x][y]=CounterForB+50;
                    table[x+1][y]=CounterForB+50;
                }
                else if(strstr(mokhtasat[counter],"down")!= 0)
                {
                    if((table[x-1][y] != '0') || ((x-1)<0))
                    {
                        printf("%d omin dade tadakhol darad\ndadeye digari vared konid:\n",counter+1);
                        continue ;
                    }
                    table[x-1][y]=CounterForB+50;
                    table[x][y]=CounterForB+50;
                }
                CounterForB ++ ;
            }
            else
            {
                printf("keshtihaye B tamam shode\n az keshtihaye A estefade konid:\n");
                continue ;
            }
        }
        counter++ ;
        printf("\n***%d***\n",counter);
        show_array(table);
    }


}
void estekhraj_va_jagozari_AI(char table[][sizeOfTable])
{
    int x,y,direction;
    int CounterForA=0;
    int CounterForB=0;
    srand(time(0));
    while (CounterForA < (tedade_keshti/2))
    {
        x=rand()% sizeOfTable ;
        y=rand() % sizeOfTable ;
        printf("\nfor A :%d,%d",x,y);
        if (table[x][y] != '0')
        {

            continue ;
        }
        else
        {
            table[x][y]='1';
            CounterForA++ ;
        }
    }
    int counterkoskosi=0 ;
    while (CounterForB< (tedade_keshti/2))
    {
        if (counterkoskosi>5)
            break;
        x=rand()% sizeOfTable ;
        y=rand() % sizeOfTable ;
        direction=rand() % 4 ; // 0 for up , 1 for down , 2 for right , 3 for left
        printf("\n%d,%d,%d",x,y,direction);
        if (table[x][y] != '0')
        {
            counterkoskosi++ ;
            continue ;
        }
        else
        {
            printf("salam");
            if (direction==0)
            {
                if (((x+1)> sizeOfTable) || (table[x+1][y] != 0) )
                {
                    continue;
                }
                else
                {
                    table[x][y]=1;
                    table[x+1][y]=1 ;
                    CounterForB++ ;
                }
            }
            else  if (direction==1)
            {
                if (((x-1) < 0 ) || (table[x-1][y] != 0) )
                {
                    continue;
                }
                else
                {
                    table[x][y]=1;
                    table[x-1][y]=1 ;
                    CounterForB++ ;
                }
            }
            else if (direction==2)
            {
                if (((y-1)<0) || (table[x][y-1] != 0) )
                {
                    continue;
                }
                else
                {
                    table[x][y]=1;
                    table[x][y-1]=1 ;
                    CounterForB++ ;
                }
            }
          else  if (direction==3)
            {
                if (((y+1)> sizeOfTable) || (table[x][y+1] != 0))
                {
                    printf("salamidobare");
                    continue;
                }
                else
                {

                    table[x][y]=1;
                    table[x][y+1]=1 ;
                    CounterForB++ ;
                }
            }
        }
    }
    show_array(table);

    printf("\nAI keshti haye khodesh ro chid\n");

}
void attack(char table[][sizeOfTable],char table_unknown [][sizeOfTable],int* tedade_baghimande)//inja bayad int* begiram tedade baqimande ro,byd beram syntaxesho yad begirm albate mitoonm global ham tarif konm
{
    int x,y ;
    printf("mokhtasate hamle ra vared konid: \nX(shomareye satr):");
    scanf("%d",&x);
    printf("Y(shomareye sotoon):");
    scanf("%d",&y);
    if (table[x][y]!= '0')
    {
        if (table[x][y]== '1')
        {
            (*tedade_baghimande) -- ;
            table[x][y]='0';
        }
        else
        {
            int counter_bomb=0;
            int i,j ;
            for(i=0; i<sizeOfTable; i++)
            {
                for( j=0; j<sizeOfTable; j++)
                {
                    if (table[i][j]==table[x][y])
                        counter_bomb++ ;

                }
            }
            if (counter_bomb==1)
                (*tedade_baghimande)-- ;
            table[x][y]='0';

        }
        printf("eyval :),jaii ke keshti bood ro hadaf qarar dadi!\n");

        table_unknown[x][y]='*';
    }
    else if (table[x][y]=='0')
    {
        printf("gand zadi :| , mooshak raft too ab\n") ;
        table_unknown[x][y]= ' ' ;
    }
}
void attack_AI(char table[][sizeOfTable],int* tedade_baghimande)//inja bayad int* begiram tedade baqimande ro,byd beram syntaxesho yad begirm albate mitoonm global ham tarif konm
{
    int x,y ;
    srand(time(0));
    x=rand()%sizeOfTable;
    y=rand()%sizeOfTable;
    if (table[x][y]=='1')
    {
        table[x][y]='0';
        printf("\nAI jaii ke keshti gharar dasht ro hadaf qarar dad :)!\n");
        *tedade_baghimande -- ;

    }
    else if (table[x][y]=='0')
    {
        printf("\nAI gand zad :| , mooshakesh raft too ab\n") ;
    }
}
int main()
{
    gameinformation();
    char n[1] ;
    char  table1[sizeOfTable][sizeOfTable],table2[sizeOfTable][sizeOfTable];
    char table1for2[sizeOfTable][sizeOfTable],table2for1[sizeOfTable][sizeOfTable] ;
    meghdardehi_avalie1(table1);
    meghdardehi_avalie1(table2);
    meghdardehi_avalie2(table1for2);
    meghdardehi_avalie2(table2for1);
    gets(n);
    if (n[0]=='1')
    {

        printf("\n***Player1 enter inputs***\n");
        char mokhtasat_1[tedade_keshti][20],mokhtasat_2[tedade_keshti][20];
        estekhraj_va_jagozari(table1,mokhtasat_1);
        printf("\n**Player2 enter inputs***\n");
        estekhraj_va_jagozari(table2,mokhtasat_2);
        tedade_baghimande_1 = tedade_keshti ;
        tedade_baghimande_2 = tedade_keshti ;
        while (1)
        {
            printf("nobate player 1 e");
            attack(table2,table2for1,&tedade_baghimande_2);
            show_array(table2for1);
            if (tedade_baghimande_2==0)
            {
                printf("\ntabrik,player 1 bord :)");
                break ;
            }
            printf("\ntedad keshtie baghimande baraye player 2: %d",tedade_baghimande_2);
            printf("\n************************************\n");
            printf("nobate player 2 e");
            attack(table1,table1for2,&tedade_baghimande_1);
            show_array(table1for2);
            if (tedade_baghimande_1==0)
            {
                printf("\ntabrik,player 2 bord :)");
                break ;
            }
            printf("\ntedad keshtie baghimande baraye player 1: %d",tedade_baghimande_1);
            printf("\n************************************\n");
        }
    }
    else if (n[0]=='2')
    {
        char mokhtasat_1[tedade_keshti][20];
        printf("\n**Player enter inputs***\n");
        estekhraj_va_jagozari(table1,mokhtasat_1);
        estekhraj_va_jagozari_AI(table2);
        return 0 ;
        int tedade_baghimande_1,tedade_baghimande_2 ;
        tedade_baghimande_1 = tedade_keshti ;
        tedade_baghimande_2 = tedade_keshti ;
        while (1)
        {
            printf("nobate player e");
            attack(table2,table2for1,&tedade_baghimande_2);
            show_array(table2for1);
            if (tedade_baghimande_2==0)
            {
                printf("\ntabrik,player 1 bord :)");
                break ;
            }
            printf("\ntedad keshtie baghimande baraye AI: %d",tedade_baghimande_2);
            printf("\n************************************\n");
            printf("nobate AI e");
            attack_AI(table1,&tedade_baghimande_1);
            if (tedade_baghimande_1==0)
            {
                printf("\ntabrik,AI bord :)");
                break ;
            }
            printf("\ntedad keshtie baghimande baraye player : %d",tedade_baghimande_1);
            printf("\n************************************\n");
        }
    }
    return 0 ;
}
