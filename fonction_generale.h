#ifndef FONCTION_GENERALE_H_INCLUDED
#define FONCTION_GENERALE_H_INCLUDED

/************* FONCTION GENERALE ***************/
int taille_liste_rep(liste l)
{
    liste p=l;
    int t=0;
    while(p!=NULL)
    {
        p=p->suiv;
        t++;
    }
    return t;
}
/****************************/
liste recherche_tel(liste l,long nm_tel)
{
    liste p=l;
    if(p==NULL)
        return NULL;
    while(p->info.num_tel!=nm_tel&&p->suiv)
        p=p->suiv;
    if(p->info.num_tel==nm_tel)
        return p;
    return NULL;

}
/****************************/
liste insere_tete_tel(liste l,tel_inf info)
{
    liste c;
    c=(liste)malloc(sizeof(struct cellule));
    c->info=info;
    c->suiv=l;
    return c;
}
/****************************/
liste insere_queue_tel(liste l,tel_inf info)
{
    liste p=l,c;
    c=(liste)malloc(sizeof(struct cellule));
    c->info=info;
    c->suiv=NULL;
    if(l==NULL)
        return c;
    else
    {
        while(p->suiv!=NULL)
            p=p->suiv;
        p->suiv=c;
        return l;
    }
}
/****************************/
liste insere_pos_tel(liste l,tel_inf inf,int pos) //pos <> 1 et pos <> taille(liste)+1
{
    liste p=l,p1;
    int x;
    p1=(liste)malloc(sizeof(struct cellule));
    p1->info=inf;
    if(l==NULL)
    {
        p1->suiv=NULL;
        return p1;
    }else
    {
        x=2;
        while(pos!=x&&p)
        {
            p=p->suiv;
            x++;
        }
        p1->suiv=p->suiv;
        p->suiv=p1;
        return l;
    }
}
/****************************/
liste supprimer_tete_tel(liste l)
{
    liste p=l;
    if(l==NULL||l->suiv==NULL)
        return NULL;
    else
    {
        l=l->suiv;
        free(p);
        return l;
    }
}
/****************************/
liste supprimer_queue_tel(liste l)
{
    liste p=l,p1=NULL;
    if(l==NULL||l->suiv==NULL)
        return NULL;
    else
    {
        while(p->suiv)
        {
            p1=p;
            p=p->suiv;
        }
        p1->suiv=NULL;
        free(p);
        return l;
    }
}
/****************************/
liste suppression_pos_tel(liste l,int pos)//pos<> 1 et pos <> taille(liste)
{
    liste p=l,p1,p2;
    int x;
    if(l==NULL)
        return NULL;
    else
    {
        x=1;
        while(pos!=x&&p->suiv)
        {
            p2=p;
            p=p->suiv;
            x++;
        }
        p1=p;
        p2->suiv=p->suiv;
        free(p);
        return l;
    }
}
/****************************/
liste suppression_tel_donne(liste l,long num)
{
    liste p=l,p1=NULL;
    int x;
    if(l==NULL)
        return l;
    else
    {
        x=0;
        while(p&&p->info.num_tel!=num)
        {
            p1=p;
            p=p->suiv;
            x++;
        }
        if(p!=NULL)
        {
            if(x==0)//premiere position
                l=l->suiv;
            else//les reste position
                p1->suiv=p->suiv;
            free(p);
        }
        return l;
    }
}
/****************************/
void affiche_perso(liste l,long num_tel)
{
    clrscr();
    int x=0,y=10;
    liste p=l;

    if(l==NULL)
    {
        printf("\n** LA LISTE DU REPERTOIRE EST VIDE **\n");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
    }
    else
    {
                gotoxy(22,3);textcolor(12);
        printf("** LES INNFORMATION DE LA LISTE **\n\n");
        textcolor(10);

        x=1;
        y++;
        gotoxy(x,y);
        printf(" NUM TEL ");x+=10;gotoxy(x,y);
        printf("| NOM ");x+=10;gotoxy(x,y);
        printf("| PREN ");x+=10;gotoxy(x,y);
        printf("| VILLE ");x+=10;gotoxy(x,y);
        printf("| Date N. ");x+=13;gotoxy(x,y);
        printf("| MAIL ",p->info.mail);
        y++;
        x=1;
        gotoxy(x,y);
        printf("_____________________________________________________________");
        y++;

        textcolor(15);
        while(p->info.num_tel!=num_tel&&p)
            p=p->suiv;
        if(p!=NULL)
        {
            textcolor(15);
            x=1;
            y++;
            gotoxy(x,y);
            printf(" %ld ", p->info.num_tel);x+=10;gotoxy(x,y);
            printf("| %s ",p->info.nom);x+=10;gotoxy(x,y);
            printf("| %s ", p->info.pren);x+=10;gotoxy(x,y);
            printf("| %s ",p->info.ad.ville);x+=10;gotoxy(x,y);
            printf("| %d/%d/%d ", p->info.dn.jj,p->info.dn.mm, p->info.dn.aa);x+=13;gotoxy(x,y);
            printf("| %s ",p->info.mail);
        }
    }
     gotoxy(20,25);
    printf("Appuyer sur une touche pour continuer");
    getch();
    menu_rech_affichage(l);
}
/****************************/
void affiche_liste(liste l)
{
    clrscr();
    liste p=l;
    int x=0,y=10;

    if(l==NULL)
        printf("\n** LA LISTE DU REPERTOIRE EST VIDE **\n");
    else
    {
        gotoxy(22,3);textcolor(12);
        printf("** LES INNFORMATION DE LA LISTE **\n\n");
        textcolor(10);

        x=1;
        y++;
        gotoxy(x,y);
        printf(" NUM TEL ");x+=10;gotoxy(x,y);
        printf("| NOM ");x+=10;gotoxy(x,y);
        printf("| PREN ");x+=10;gotoxy(x,y);
        printf("| VILLE ");x+=10;gotoxy(x,y);
        printf("| Date N. ");x+=13;gotoxy(x,y);
        printf("| MAIL ",p->info.mail);
        y++;
        x=1;
        gotoxy(x,y);
        printf("_____________________________________________________________");
        y++;
        textcolor(15);
        while(p)
        {
            x=1;
            y++;
            gotoxy(x,y);
            printf(" %ld ", p->info.num_tel);x+=10;gotoxy(x,y);
            printf("| %s ",p->info.nom);x+=10;gotoxy(x,y);
            printf("| %s ", p->info.pren);x+=10;gotoxy(x,y);
            printf("| %s ",p->info.ad.ville);x+=10;gotoxy(x,y);
            printf("| %d/%d/%d ", p->info.dn.jj,p->info.dn.mm, p->info.dn.aa);x+=13;gotoxy(x,y);
            printf("| %s ",p->info.mail);

            p=p->suiv;
        }

    }
    gotoxy(20,40);
    printf("Appuyer sur une touche pour continuer");
    getch();
    menu_rech_affichage(l);
}
/*******************saisie dun telephone************************/
tel_inf saisie_tel(liste l)
{
    tel_inf T;
    textcolor(11);
    printf("Donner un numero de telephone : ");textcolor(15);
    scanf("%ld",&T.num_tel);printf("\n");
    while(recherche_tel(l,T.num_tel)!=NULL||T.num_tel<10000000||T.num_tel>99999999)
    {
        textcolor(11);
        printf("Donner un numero de telephone CORRECTE [composee de 8 chiffre] : ");textcolor(15);
        scanf("%ld",&T.num_tel);printf("\n");
    }

printf("\n\n");

    textcolor(11);
    printf("Donner le nom : ");textcolor(15);
    fflush(stdin);
    gets(T.nom);printf("\n");
    while(ctrl_lettre(T.nom)!=1)
    {textcolor(11);
        printf("Donner le nom CORRECTEMENT [seulement des lettres]: ");textcolor(15);
        fflush(stdin);
        gets(T.nom);printf("\n");
    }
printf("\n\n");textcolor(11);

    printf("Donner le prenom : ");textcolor(15);
    gets(T.pren);textcolor(11);printf("\n");
    while(ctrl_lettre(T.pren)!=1)
    {   textcolor(11);
        printf("Donner le prenom CORRECTEMENT [seulement des lettres]: ");textcolor(15);
        gets(T.pren);textcolor(11);printf("\n");
    }
printf("\n\n");

    printf("Donner la date de naissance : \n");
    textcolor(12);
    printf("jour : ");textcolor(15);
    fflush(stdin);
    scanf("%d",&T.dn.jj);textcolor(12);printf("\n");
    printf("mois : ");textcolor(15);
    scanf("%d",&T.dn.mm);textcolor(12);printf("\n");
    printf("ans : ");textcolor(15);
    scanf("%d",&T.dn.aa);printf("\n");
    while(verifdate(T.dn))
    {
        textcolor(11);
        printf("Donner la date de naissance CORRECTEMENT : \n");
        textcolor(12);
        printf("jour [0<jour<31] : ");textcolor(15);
        fflush(stdin);
        scanf("%d",&T.dn.jj);textcolor(12);printf("\n");
        printf("mois [0<mois<13] : ");textcolor(15);
        scanf("%d",&T.dn.mm);textcolor(12);printf("\n");
        printf("ans [ans<2019] : ");textcolor(15);
        scanf("%d",&T.dn.aa);printf("\n");
    }
printf("\n\n");

    textcolor(11);
    printf("Donner l email : ");textcolor(15);
    fflush(stdin);
    gets(T.mail);printf("\n");
    while(ctrl_mail(T.mail)==1)
    {
        textcolor(11);
        printf("Donner l email CORRECTMENT [exemple@exemple1.exemple2]: ");textcolor(15);
        fflush(stdin);
        gets(T.mail);printf("\n");
    }

printf("\n\n");textcolor(11);


    printf("L adresse : \n");
    textcolor(12);
    printf("Rue : ");textcolor(15);
    fflush(stdin);
    gets(T.ad.rue);textcolor(12);printf("\n");
    printf("Ville : ");textcolor(15);
    gets(T.ad.ville);textcolor(12);printf("\n");
    printf("Code postale : ");textcolor(15);
    fflush(stdin);
    scanf("%d",&T.ad.code_post);textcolor(11);printf("\n");
    while(ctrl_lettre_espace_chiffre(T.ad.rue)!=1||ctrl_lettre(T.ad.ville)!=1)
    {
        textcolor(11);
        printf("L adresse CORRECTEMENT : \n");
        textcolor(12);
        printf("Rue : ");textcolor(15);
        fflush(stdin);
        gets(T.ad.rue);textcolor(12);printf("\n");
        printf("Ville (seulement des lettres): ");textcolor(15);
        gets(T.ad.ville);textcolor(12);printf("\n");
        printf("Code postale (seulement des chiffres ): ");textcolor(15);
        fflush(stdin);
        scanf("%d",&T.ad.code_post);textcolor(11);printf("\n");
    }
    return T;
}
/***************************************************************/
#endif // FONCTION_GENERALE_H_INCLUDED
