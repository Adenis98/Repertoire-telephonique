#ifndef MAJOUTER_H_INCLUDED
#define MAJOUTER_H_INCLUDED

/***************AJOUTER TETE********************/
void ajout_tete(liste l)
{
    tel_inf t;
    char c;
    do
    {
        clrscr();
        textcolor(15);
        gotoxy(25,3);
        printf("**** AJOUTER LES TELEPHONES ****\n\n\n\n");
        t=saisie_tel(l);
        l=insere_tete_tel(l,t);
        do
        {
            printf("Voulez vous ajouter un autre telephone en tete? O='oui'/N='non' \n");
            c=getch();
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
    }while(c=='o'||c=='O');
    menu_ajouter(l);
}
/***************AJOUTER QUEUE********************/
void ajout_queue(liste l)
{
    tel_inf t;
    char c;
    do
    {
        clrscr();
        textcolor(15);
        gotoxy(25,3);
        printf("**** AJOUTER LES TELEPHONES ****\n\n\n\n");
        t=saisie_tel(l);
        l=insere_queue_tel(l,t);
        do
        {
            printf("Voulez vous ajouter un autre telephone en queue? O='oui'/N='non' \n");
            c=getch();
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
    }while(c=='o'||c=='O');
    menu_ajouter(l);
}
/***************AJOUTER POSITION********************/
void ajout_pos(liste l)
{
    tel_inf t;
    char c;
    int pos;

    do
    {
        clrscr();
        textcolor(15);
        gotoxy(25,3);
        printf("**** AJOUTER LES TELEPHONES ****\n\n\n\n");
        t=saisie_tel(l);
        do
        {
            printf("Donner la position dans la liste :");
            scanf("%d",&pos);
        }while(pos<=1||pos>=taille_liste_rep(l)+1);
        l=insere_pos_tel(l,t,pos);
        do
        {
            printf("Voulez vous ajouter un autre telephone en une position? O='oui'/N='non' \n");
            c=getch();
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
    }while(c=='o'||c=='O');
    menu_ajouter(l);
}
/**********************SUPPRESSION***********************/
void supp_tete(liste l)
{
    char c;
    int y=0;
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(30,20);
        printf("LA LISTE EST VIDE  ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();

    }else{

        textcolor(12);gotoxy(10,20);
        printf("VOULEZ VOUS SUPPRIMER LE PREMIER TELEPHONE DE VOTRE REPERTOIRE ? ");
        textcolor(15);gotoxy(10,25);
        do
        {
            gotoxy(10,25+y);
            printf("Appuyer sur 'O' poure rependre par 'oui' et 'N' pour repondre par 'non'  \n");
            c=getch();
            y++;
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
        if(c=='O'||c=='o')
            l=supprimer_tete_tel(l);
    }
    menu_suppression(l);
}
/*********************************************************/
void supp_queue(liste l)
{
    char c;
    int y=0;
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(30,20);
        printf("LA LISTE EST VIDE  ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();

    }else{

        textcolor(12);gotoxy(10,20);
        printf("VOULEZ VOUS SUPPRIMER LE DERNIER TELEPHONE DE VOTRE REPERTOIRE ? ");
        textcolor(15);gotoxy(10,25);
        do
        {
            gotoxy(10,25+y);
            printf("Appuyer sur 'O' poure rependre par 'oui' et 'N' pour repondre par 'non'  \n");
            c=getch();
            y++;
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
        if(c=='O'||c=='o')
            l=supprimer_queue_tel(l);
    }
    menu_suppression(l);
}
/*********************************************************/
void supp_pos(liste l)
{
    char c;
    int y=0,pos;
    clrscr();
    if(l==NULL||taille_liste_rep(l)<=2)
    {
        textcolor(12);gotoxy(30,20);
        printf("LA LISTE NE CONTIENT PAS LE MINIMUM DES TELEPHONES ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();

    }else{

        textcolor(12);gotoxy(10,20);
        printf("VOULEZ VOUS SUPPRIMER UN TELEPHONE DE VOTRE REPERTOIRE ? ");
        textcolor(15);gotoxy(10,25);
        do
        {
            gotoxy(10,25+y);
            printf("Appuyer sur 'O' poure rependre par 'oui' et 'N' pour repondre par 'non'  \n");
            c=getch();
            y++;
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
        if(c=='O'||c=='o')
        {
            clrscr();
            printf("donner la position du suppression : ");
            scanf("%d",&pos);
            while(pos<=1||pos>=taille_liste_rep(l))
            {
                clrscr();
                textcolor(12);gotoxy(10,20);
                printf("donner la position du suppression qui est different de 1 et de la taille due la liste : ");
                scanf("%d",&pos);
            }
            l=suppression_pos_tel(l,pos);
        }
    }
    menu_suppression(l);
}
/*********************************************************/
void supp_tel_don(liste l)
{
    char c;
    int y=0;
    long tel;
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(30,20);
        printf("LA LISTE EST VIDE  ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();

    }else{

        textcolor(12);gotoxy(10,20);
        printf("VOULEZ VOUS SUPPRIMER UN TELEPHONE DE VOTRE REPERTOIRE ? ");
        textcolor(15);gotoxy(10,25);
        do
        {
            gotoxy(10,25+y);
            printf("Appuyer sur 'O' poure rependre par 'oui' et 'N' pour repondre par 'non'  \n");
            c=getch();
            y++;
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
        if(c=='O'||c=='o')
        {
            clrscr();gotoxy(10,20);
            printf("donner le numero du telephone : ");
            scanf("%ld",&tel);
            while(tel<10000000||tel>99999999||recherche_tel(l,tel)==NULL)
            {
                clrscr();
                textcolor(12);gotoxy(10,20);
                printf("donner le numero du telephone CORRECTEMENT : ");
                scanf("%ld",&tel);
            }
            l=suppression_tel_donne(l,tel);
        }
    }
    menu_suppression(l);
}
/****************************/

liste recherche_ville(liste l,char ville[])
{
    liste p=l;
    if(p==NULL)
        return NULL;
    while(test_chaine_equal(p->info.ad.ville,ville)!=1&&p->suiv)
        p=p->suiv;
    if(test_chaine_equal(p->info.ad.ville,ville)==1)
        return l;
    return NULL;

}
/*********************************************************/
void supp_ville_don(liste l)
{
    char c,ville[20];
    int y=0;
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(30,20);
        printf("LA LISTE EST VIDE  ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();

    }else{

        textcolor(12);gotoxy(10,20);
        printf("VOULEZ VOUS SUPPRIMER UN TELEPHONE DE VOTRE REPERTOIRE ? ");
        textcolor(15);gotoxy(10,25);
        do
        {
            gotoxy(10,25+y);
            printf("Appuyer sur 'O' poure rependre par 'oui' et 'N' pour repondre par 'non'  \n");
            c=getch();
            y++;
        }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
        if(c=='O'||c=='o')
        {
            clrscr();gotoxy(10,20);
            printf("donner le d'une ville : ");
            fflush(stdin);
            gets(ville);
            while(recherche_ville(l,ville)==NULL/*ville nexiste pas*/)
            {
                clrscr();
                textcolor(12);gotoxy(10,20);
                printf("le nom n'existe pas donner un autre nom  : ");
                scanf("%s",ville);
            }
            l=suppression_tel_donne(l,recherche_ville(l,ville)->info.num_tel);
        }
    }
    menu_suppression(l);
}
/*********************************************************/
void mod_adresse(liste l)
{
    tel_inf tel,tel1;
    adresse a,a1;
    liste p=l,p1=NULL;
    clrscr();gotoxy(10,10);
    printf("DONNER L'ADRESSE A MODIFIER : ");gotoxy(10,22);
    printf("RUE :");
    gets(a.rue);gotoxy(10,24);
    printf("VILLE : ");
    gets(a.ville);gotoxy(10,26);
    printf("CODE POSTALE : ");
    scanf("%d",&a.code_post);
    while(p->suiv)
    {
        if(p->info.ad.rue==a.rue&&p->info.ad.ville==a.ville&&p->info.ad.code_post==a.code_post)
            p1=p;
        p=p->suiv;

    }
    if(p1!=NULL)
    {
        textcolor(11);
        printf("La nouvelle adresse : \n");
        textcolor(12);
        printf("Rue : ");textcolor(15);
        fflush(stdin);
        gets(a1.rue);textcolor(12);printf("\n");
        fflush(stdin);
        printf("Ville : ");textcolor(15);
        gets(a1.ville);textcolor(12);printf("\n");
        printf("Code postale : ");textcolor(15);
        fflush(stdin);
        scanf("%d",&a1.code_post);textcolor(11);printf("\n");
        while(ctrl_lettre_espace_chiffre(a1.rue)!=1||ctrl_lettre(a1.ville)!=1)
        {
            textcolor(11);
            printf("L adresse CORRECTEMENT : \n");
            textcolor(12);
            printf("Rue : ");textcolor(15);
            fflush(stdin);
            gets(a1.rue);textcolor(12);printf("\n");
            printf("Ville (seulement des lettres): ");textcolor(15);
            gets(a1.ville);textcolor(12);printf("\n");
            printf("Code postale (seulement des chiffres ): ");textcolor(15);
            fflush(stdin);
            scanf("%d",&a1.code_post);textcolor(11);printf("\n");
        }
        p1->info.ad=a1;
    }else{
        clrscr();
        textcolor(12);gotoxy(30,20);
        printf("LES DONNEE N'EXISTE PAS DANS LA LISTE  ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
    }
    menu_modification(l);
}
/*********************************************************/
void mod_telephone(liste l)
{
    tel_inf tel1;
    long n,n1;
    liste p=l,p1=NULL;
    clrscr();gotoxy(10,10);
    printf("DONNER Le NUM TEL A MODIFIER : ");gotoxy(10,12);
    scanf("%ld",&n);
    while(p)
    {
        if(p->info.num_tel==n)
            p1=p;
        p=p->suiv;

    }
    if(p1!=NULL)
    {
        textcolor(11);gotoxy(10,14);
        printf("Donner un numero de telephone : ");textcolor(15);
        scanf("%ld",&n1);printf("\n");
        while(recherche_tel(l,n1)!=NULL||n1<10000000||n1>99999999)
        {
            textcolor(11);
            printf("Donner un numero de telephone CORRECTE [composee de 8 chiffre] : ");textcolor(15);
            scanf("%ld",&n1);printf("\n");
        }
        p1->info.num_tel=n1;
    }else{
        textcolor(12);gotoxy(30,20);
        printf("LES DONNEE N'EXISTE PAS DANS LA LISTE  ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
    }
    menu_modification(l);
}
#endif // MAJOUTER_H_INCLUDED
