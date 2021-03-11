#ifndef CONTROLE_SAISIE_H_INCLUDED
#define CONTROLE_SAISIE_H_INCLUDED

/************** CONTROLE DE SAISIE **************/
int ctrl_lettre_espace(char *ch)
{
    char *p;
    for(p=ch;*p;p++)
        if(isspace(*p)!=0&&(*p<65||*p>90))
            return 0;
    return 1;
}
/****************************/
int ctrl_lettre(char *ch)
{
    char *p;
    for(p=ch;*p;p++)
        if((*p<'a'||*p>'z'))
            return 0;
    return 1;
}
/****************************/
int ctrl_lettre_espace_chiffre(char *ch)
{
    char *p;
    for(p=ch;*p;p++)
        if(isspace(*p)==0&&(toupper(*p)<65||toupper(*p)>90)&&*p<48&&*p>57)
            return 0;
    return 1;
}
/****************************/
int ctrl_mail(char *ch)
{
    char *p=NULL,*p1=NULL,ch1[20],c1[]="@",c2[]=".";

    p1=strstr(ch,c1);
    if(p1==NULL||(p1!=NULL&&strstr(p1+1,c1)!=NULL))
        return 1;
    p=strstr(ch,c2);
    if(p==NULL)
        return 1;
    return 0;
}
/****************************/
int verifdate(date_naissance d)
{
    int jmax;
    switch (d.mm)
    {
        case 1:jmax=31;break;
        case 2:if(d.aa%2==0)
                  jmax=29 ;
                  else
                    jmax=28;
                  break;
        case 3:jmax=31;break;
        case 4:jmax=31;break;
        case 5:jmax=30;break;
        case 6:jmax=31;break;
        case 7:jmax=30;break;
        case 8:jmax=31;break;
        case 9:jmax=30;break;
        case 10:jmax=31;break;
        case 11:jmax=30;break;
        case 12:jmax=31;break;
    }
     return d.aa>2019||d.aa<1500||d.jj>jmax||d.jj<1||d.mm>12||d.mm<1;//0->true !=0->false
}
/****************************/
int test_chaine_equal(char ch[],char ch1[])
{
    int i,j;
    if(strlen(ch)==strlen(ch1))
    {
        for(i=0;i<strlen(ch);i++)
        if(ch[i]!=ch1[i])
            return 0;
        return 1;
    }
    return 0;

}
/****************************/


#endif // CONTROLE_SAISIE_H_INCLUDED
