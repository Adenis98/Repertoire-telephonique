#ifndef GRAFICS_H_INCLUDED
#define GRAFICS_H_INCLUDED

/**************** FULLSCREEN ************/
void fullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}
/*************** CADRE *************/
void cadre(char c,int vitesse)
{
    int i;
    textcolor(10);
    for(i=1;i<80;i++)
    {
        Sleep(vitesse);
        if(i%2==0)
        {
            gotoxy(i,1);
            printf("%c",c);
        }
    }
    for(i=0;i<45;i++)
    {
        Sleep(vitesse);
        if(i%2==0)
        {
            gotoxy(80,i);
            printf("%c",c);
        }
    }
    for(i=80;i>0;i--)
    {
        Sleep(vitesse);
        if(i%2==0)
        {
            gotoxy(i,45);
            printf("%c",c);
        }

    }
    for(i=45;i>0;i--)
    {
        Sleep(vitesse);
        if(i%2==0)
        {
            gotoxy(1,i);
            printf("%c",c);
        }
    }
}
/***************TRANSLATION TITRE*************/
void makeit(char ch[])
{
    int i;
    for(i=strlen(ch)-1;i>0;i--)
        ch[i]=ch[i-1];
    ch[0]=' ';
}
/****************************/
void make(char ch[],int j,char ch1[])
{
    int i,k;
    for(i=strlen(ch1)-j,k=0;k<j;k++,i++)
        ch[k]=ch1[i];
}
/****************************/
void chaine(char ch1[],char ch2[])
{
    int i;
    for(i=0;i<strlen(ch1);i++)
        ch2[i]=ch1[i];
    ch2[i]='\0';
}
/****************************/
void space(char ch[])
{
    int i;
    for(i=0;ch[i];i++)
        ch[i]=' ';
}
/****************************/
void translation(char *ch,int s)
{
    textcolor(15);
    int i,j=0,k,t=0,m=0,p=23;
    char /*ch[]=" MENU GENERALE ",*/ch2[strlen(ch)];
    chaine(ch,ch2);

        for(k=5+p;k<strlen(ch)+8+4+p;k++)
        {
            Sleep(10);
            gotoxy(k,2);
            printf("*");
        }
        for(k=5+p;k<4+4+p;k++)
        {
            Sleep(10);
            gotoxy(k,3);
            printf("*");
        }
        for(k=strlen(ch)+7+p;k<strlen(ch)+p+8+4;k++)
        {
            Sleep(10);
            gotoxy(k,3);
            printf("*");
        }
        for(k=5+p;k<strlen(ch)+8+4+p;k++)
        {
            Sleep(10);
            gotoxy(k,4);
            printf("*");
        }
        textcolor(13);
        for(i=0,j=0;i<30+s;i+=1)
        {
            //getchar();
            Sleep(90);
            if(t==1)
            {
                j++;
                make(ch,j,ch2);
                gotoxy(9+p,3);
                printf("%s",ch);
                m=0;
                if(j==strlen(ch))
                    t=0;
            }
            else if(t==0)
            {
                m++;
                makeit(ch);
                gotoxy(9+p,3);
                if(m==strlen(ch))
                    t=1;
                printf("%s",ch);
                j=0;
            }

        }
        for(i=0;i<6;i++)
        {
            Sleep(90);
            if(i%2==0)
            {
                space(ch2);
            }else{
                chaine(ch,ch2);
            }
            gotoxy(9+p,3);
            printf("%s",ch2);
        }
}
/********************************************************/
void full_screen()
{
    //DO YOU WANT FULL SCREEN ??
    char q[0];
    highvideo();
    textcolor(10);
    gotoxy(15,2);
    printf("Do you want to run the program in fullscreen ? Y/N \n");
    do{
        q[0]=getch();
        if(q[0]=='y')
            fullscreen();
        else
            if(q[0]!='n')
            {
                textcolor(12);
                printf("please reply , Do you want to run the program in fullscreen ? Y/N \n\n ");
            }

    }while(q[0]!='y'&&q[0]!='n');
    clrscr();
    // FULL SCREEN END HERE
}
/****************************/
void space_char(char *ch,int t)
{
    char p[20];
    int i;
    for(i=strlen(ch);i<(t-strlen(ch));i++)
        ch[i]=' ';
    ch[i]='\0';
}
/****************************/

/****************************/
#endif // GRAFICS_H_INCLUDED

