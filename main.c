#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <myconio.h>
#include <windows.h>
#include "structure.h"
#include "fonction_generale.h"
#include "controle_saisie.h"
#include "grafics.h"
#include "maj.h"
/*************1-CREATION (MG)****************/
void creation(liste l)
{
    tel_inf t;
    char c;
    int pos;
    if(l!=NULL)
    {
        clrscr();
        textcolor(12);gotoxy(30,20);
        printf("LA LISTE N'EST PAS VIDE  ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
    }else
        do
        {
            clrscr();
            textcolor(15);
            gotoxy(25,3);
            printf("**** AJOUTER LES TELEPHONES ****\n\n\n\n");
            t=saisie_tel(l);
            if(taille_liste_rep(l)==0)
                l=insere_tete_tel(l,t);
            else if(taille_liste_rep(l)==1)
                    l=insere_queue_tel(l,t);
            else
            {
                do
                {
                    printf("Donner la position dans la liste :");
                    scanf("%d",&pos);
                }while(pos<=1||pos>=taille_liste_rep(l)+1);
                l=insere_pos_tel(l,t,pos);
            }
            do
            {
                printf("Voulez vous ajouter un autre telephone ? O='oui'/N='non' \n");
                c=getch();
            }while(c!='o'&&c!='n'&&c!='O'&&c!='N');
        }while(c=='o'||c=='O');
    menu_gen(l);
}
/******************END***********************/


/**********MENU ENREGISTREMENT***************/
void chargement(liste l)
{
    liste p;
    char chaine[130] = "",chaine1[130] = "",c[0],*ch,*ch1,*ch2,ch3[10];
    tel_inf tel;
    FILE *fichier;
    int i=0,j;
    c[0]='|';
    fichier = fopen("test.txt","r");
    if (fichier != NULL)
    {
            while (fgets(chaine, 130, fichier) != NULL)
            {
               for(i=0;i<strlen(chaine);i++)
                   chaine1[i]=chaine[i];
               i=0;
               do
               {
                   if(i==0)
                       ch=strchr(chaine1,'|');
                    else
                        ch=strchr(ch1,'|');
                    *ch='\0';
                    if(i==0)
                    {
                        switch (i)
                        {
                            case 0:tel.num_tel=atol(chaine1);break;
                            case 1:strcpy(tel.nom,chaine1);break;
                            case 2:strcpy(tel.pren,chaine1);break;
                            case 3:strcpy(tel.ad.ville,chaine1);break;
                            case 4:tel.dn.jj=atoi(chaine1);break;
                            case 5:tel.dn.mm=atoi(chaine1);break;
                            case 6:tel.dn.aa=atoi(chaine1);break;
                            case 7:strcpy(tel.mail,chaine1);break;
                        }
                    }
                    else
                    {
                        switch (i)
                        {
                            case 0:tel.num_tel=atol(ch1);break;
                            case 1:strcpy(tel.nom,ch1);break;
                            case 2:strcpy(tel.pren,ch1);break;
                            case 3:strcpy(tel.ad.ville,ch1);break;
                            case 4:tel.dn.jj=atoi(ch1);break;
                            case 5:tel.dn.mm=atoi(ch1);break;
                            case 6:tel.dn.aa=atoi(ch1);break;
                            case 7:strcpy(tel.mail,ch1);break;
                        }
                    }

                    ch1=ch+1;
                    i++;
               }while(i<=7);
               l=insere_queue_tel(l,tel);
            }
            fclose(fichier);
    }else
    {
        textcolor(12);gotoxy(30,20);
        puts("ERREUR DE CHARGEMENT");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
    }
    menu_enregistrement(l);
}
/********************************************/
void enregistrer(liste l)
{
    liste p=l;
    FILE* fichier = NULL;
    fichier = fopen("test.txt", "w");
    if(l!=NULL)
    {
        if (fichier != NULL)
        {
            // Ecriture
            while(p)
            {
                fprintf(fichier,"%ld|%s|%s|%s|%d|%d|%d|%s|\n", p->info.num_tel,
                                                p->info.nom,
                                                p->info.pren,
                                                p->info.ad.ville,
                                                p->info.dn.jj,
                                                p->info.dn.mm,
                                                p->info.dn.aa,
                                                p->info.mail );
                p=p->suiv;

            }
            // Fermeture du fichier
            fclose(fichier);
        }else

            {
                textcolor(12);gotoxy(30,20);
                puts(" ERREUR D'ENREGISTREMENT ");
                textcolor(15);gotoxy(20,25);
                printf("Appuyer sur une touche pour continuer");
                getch();
            }
    }else
    {
        puts("LA LISTE EST VIDE ");
    }
    menu_enregistrement(l);
}
/********************************************/
void menu_enregistrement(liste l)
{
        char ch_menu_gen[]="  MENU ENREGISTREMENT  ";
    char fle[]=" ->",q[0];
    int y=12,ch1,ch2;
    clrscr();
    cadre('*',1);
    translation(ch_menu_gen+1,14);
    textcolor(13);
    gotoxy(26,12);
    printf("1- Enregistrement \n");gotoxy(26,14);
    printf("2- Chargement \n");gotoxy(26,16);
    printf("3- Retour au menu generale  \n");
    textcolor(15);
    gotoxy(50,38);
    printf("Donner votre choix SVP ");
    gotoxy(23,40);
    printf("fleche haut=up , fleche bas=down , le caractere 'O'=ENTER");
    q[0]='0';
    ch2=0;
    do
    {
        if(ch2==80)
        {
            gotoxy(23,y);
            printf("  ");
            y+=2;
            if(y>16)
                y=12;
        }
        else
            if(ch2==72)
            {
                gotoxy(23,y);
                printf("  ");
                y-=2;
                if(y<=10)
                    y=16;
            }
        gotoxy(23,y);
        printf("%s",fle+1);
        ch2=0;
        ch1=getch();
        q[0]=ch1;
        if (ch1 == 0xE0)
            ch2 = getch();
    }while(q[0]!='o');
    switch (y)
    {
        case 12:enregistrer(l);/* enregistrement */
        case 14:chargement(l);/* chargement */
        case 16:menu_gen(l);/* retour au menu gen */
    }
}

/********************************************/
void tri_2(liste l)
{
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(10,20);printf("LA LISTE EST VIDE ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
        menu_rech_affichage();
    }
    else
    {

    }
}
/********************************************/
void tri_1(liste l)
{
    liste p1=l,p2=l->suiv,p3=l;
    tel_inf aux,min;
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(10,20);printf("LA LISTE EST VIDE ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
        menu_rech_affichage();
    }
    else
    {
        while(p3)
        {
            while(p2!=NULL)
            {
                if(p2->info.num_tel>p1->info.num_tel)
                {
                    aux=p2->info;
                    p2->info=p1->info;
                    p1->info=aux;
                }
                p2=p2->suiv;
                p1=p1->suiv;
            }
            p3=p3->suiv;
        }
    }
    menu_rech_affichage(l);
}
/********************************************/
void affiche_ville(liste l)
{
    char ville[20];
    liste p=l;
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(10,20);printf("LA LISTE EST VIDE ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
        menu_rech_affichage();
    }else
    {
        textcolor(12);gotoxy(10,10);
        printf("DONNER UNE VILLE : ");
        fflush(stdin);
        gets(ville);
        while(p&&test_chaine_equal(p->info.ad.ville,ville)!=1)
            p=p->suiv;
        if(p!=NULL)
        {
            affiche_perso(l,p->info.num_tel);
        }
        else
        {
            textcolor(12);gotoxy(10,20);printf("VILLE N'AIXISTE PAS DANS LA LISTE  ");
            textcolor(15);gotoxy(20,25);
            printf("Appuyer sur une touche pour continuer");
            getch();
            menu_rech_affichage(l);
        }

    }

}

/********************************************/
void affiche_nom(liste l)
{
    char nom[20];
    liste p=l;
    clrscr();
    if(l==NULL)
    {
        textcolor(12);gotoxy(10,20);printf("LA LISTE EST VIDE ");
        textcolor(15);gotoxy(20,25);
        printf("Appuyer sur une touche pour continuer");
        getch();
        menu_rech_affichage();
    }else
    {
        textcolor(12);gotoxy(10,10);
        printf("DONNER UN NOM : ");
        fflush(stdin);
        gets(nom);
        while(p&&test_chaine_equal(p->info.nom,nom)!=1)
            p=p->suiv;
        if(p!=NULL)
        {
            affiche_perso(l,p->info.num_tel);
        }
        else
        {
            textcolor(12);gotoxy(10,20);printf("LE NOM N'AIXISTE PAS DANS LA LISTE  ");
            textcolor(15);gotoxy(20,25);
            printf("Appuyer sur une touche pour continuer");
            getch();
            menu_rech_affichage(l);
        }

    }

}

/********MENU RECHERCHE ET AFFICHAGE*********/
void menu_rech_affichage(liste l)
{

    char ch_menu_gen[]="  MENU RECHERCHE ET AFFICHAGE ";
    char fle[]=" ->",q[0];
    int y=12,ch1,ch2;
    clrscr();
    cadre('*',1);
    translation(ch_menu_gen+1,27);
    textcolor(13);
    gotoxy(20,12);
    printf("1- Contenu de la liste des telephones \n");gotoxy(20,14);
    printf("2- Recherche par numero telephone  \n");gotoxy(20,16);
    printf("3- Recherche par nom  \n");gotoxy(20,18);
    printf("4- Recherche par indicatif telephone \n");gotoxy(20,20);
    printf("5- Recherche par ville \n");gotoxy(20,22);
    printf("6- Tri 1 \n");gotoxy(20,24);
    printf("7- Tri 2 \n");gotoxy(20,26);
    printf("8- Retour au menu general ");
    textcolor(15);
    gotoxy(50,38);
    printf("Donner votre choix SVP ");
    gotoxy(23,40);
    printf("fleche haut=up , fleche bas=down , le caractere 'O'=ENTER");
    q[0]='0';
    ch2=0;
    do
    {
        if(ch2==80)
        {
            gotoxy(17,y);
            printf("  ");
            y+=2;
            if(y>26)
                y=12;
        }
        else
            if(ch2==72)
            {
                gotoxy(17,y);
                printf("  ");
                y-=2;
                if(y<=10)
                    y=26;
            }
        gotoxy(17,y);
        printf("%s",fle+1);
        ch2=0;
        ch1=getch();
        q[0]=ch1;
        if (ch1 == 0xE0)
            ch2 = getch();
    }while(q[0]!='o');
    long n;
    switch (y)
    {
        case 12:affiche_liste(l);/* Contenu de la liste des telephones*/
        case 14:clrscr();printf("DONNER UN NUM TEL : ");
                scanf("%ld",&n);
            affiche_perso(l,n);/* Recherche par numero telephone */
        case 16:clrscr();
            affiche_nom(l);/* Recherche par nom */
        case 18:;/* Recherche par indicatif telephone */
        case 20:clrscr();
            affiche_ville(l);/* Recherche par ville */
        case 22:tri_1(l);/* Tri 1  */
        case 24:;/* Tri 2 */
        case 26:menu_gen(l);/*retour au menu generale*/
    }
}


/***********MENU MODIFICATION****************/
void menu_modification(liste l)
{
       char ch_menu_gen[]="  MENU MODIFICATION  ";
    char fle[]=" ->",q[0];
    int y=12,ch1,ch2;
    clrscr();
    cadre('*',1);
    translation(ch_menu_gen+1,10);
    textcolor(13);
    gotoxy(29,12);
    printf("1- Adresse \n");gotoxy(29,14);
    printf("2- Telephone \n");gotoxy(29,16);
    printf("3- Retour au menu MiseAJour  \n");
    textcolor(15);
    gotoxy(50,38);
    printf("Donner votre choix SVP ");
    gotoxy(23,40);
    printf("fleche haut=up , fleche bas=down , le caractere 'O'=ENTER");
    q[0]='0';
    ch2=0;
    do
    {
        if(ch2==80)
        {
            gotoxy(26,y);
            printf("  ");
            y+=2;
            if(y>16)
                y=12;
        }
        else
            if(ch2==72)
            {
                gotoxy(26,y);
                printf("  ");
                y-=2;
                if(y<=10)
                    y=16;
            }
        gotoxy(26,y);
        printf("%s",fle+1);
        ch2=0;
        ch1=getch();
        q[0]=ch1;
        if (ch1 == 0xE0)
            ch2 = getch();
    }while(q[0]!='o');
    switch (y)
    {
        case 12:mod_adresse(l);/* adresse */
        case 14:mod_telephone(l);/* telephone */
        case 16:menu_maj(l);/* retour au menu MAJ */
    }
}
/************MENU SUPPRESSION****************/
void menu_suppression(liste l)
{
    char ch_menu_gen[]="  MENU SUPPRESSION ";
    char fle[]=" ->",q[0];
    int y=12,ch1,ch2;
    clrscr();
    cadre('*',1);
    translation(ch_menu_gen+1,6);
    textcolor(13);
    gotoxy(20,12);
    printf("1- Suppression en tete \n");gotoxy(20,14);
    printf("2- Suppression en queue \n");gotoxy(20,16);
    printf("3- Suppression a partir d'une position  \n");gotoxy(20,18);
    printf("4- Suppression d'un telephone donne \n");gotoxy(20,20);
    printf("5- Suppression des telephones d'une ville donnee \n");gotoxy(20,22);
    printf("6- Suppression des telephones d'un indicatif donne \n");gotoxy(20,24);
    printf("7- Retour au menu MISE A JOUR \n");
    textcolor(15);
    gotoxy(50,38);
    printf("Donner votre choix SVP ");
    gotoxy(23,40);
    printf("fleche haut=up , fleche bas=down , le caractere 'O'=ENTER");
    q[0]='0';
    ch2=0;
    do
    {
        if(ch2==80)
        {
            gotoxy(17,y);
            printf("  ");
            y+=2;
            if(y>24)
                y=12;
        }
        else
            if(ch2==72)
            {
                gotoxy(17,y);
                printf("  ");
                y-=2;
                if(y<=10)
                    y=24;
            }
        gotoxy(17,y);
        printf("%s",fle+1);
        ch2=0;
        ch1=getch();
        q[0]=ch1;
        if (ch1 == 0xE0)
            ch2 = getch();
    }while(q[0]!='o');
    switch (y)
    {
        case 12:supp_tete(l)/* supp tete */;
        case 14:supp_queue(l)/* supp sueue */;
        case 16:supp_pos(l)/* supp pos */;
        case 18:supp_tel_don(l)/* supp tel donnee */;
        case 20:supp_ville_don(l)/*supp d une ville donnee */;
        case 22:clrscr();affiche_liste(l);getch();break;/****************** supp d un indicatif donne  */;
        case 24:menu_maj(l)/* retour MiseAJour */;
    }
}
/**************MENU AJOUTER******************/
void menu_ajouter(liste l)
{
    char ch_menu_gen[]="  MENU AJOUTER  ";
    char fle[]=" ->",q[0];
    int y=12,ch1,ch2;
    clrscr();
    cadre('*',1);
    translation(ch_menu_gen+1,0);
    textcolor(13);
    gotoxy(26,12);
    printf("1- Ajout en tete  \n");gotoxy(26,14);
    printf("2- Ajout en queue \n");gotoxy(26,16);
    printf("3- Ajout dans une position \n");gotoxy(26,18);
    printf("4- Retour Menu Mise a jour \n");
    textcolor(15);
    gotoxy(50,38);
    printf("Donner votre choix SVP ");
    gotoxy(23,40);
    printf("fleche haut=up , fleche bas=down , le caractere 'O'=ENTER");
    q[0]='0';
    ch2=0;
    do
    {
        if(ch2==80)
        {
            gotoxy(23,y);
            printf("  ");
            y+=2;
            if(y>18)
                y=12;
        }
        else
            if(ch2==72)
            {
                gotoxy(23,y);
                printf("  ");
                y-=2;
                if(y<=10)
                    y=18;
            }
        gotoxy(23,y);
        printf("%s",fle+1);
        ch2=0;
        ch1=getch();
        q[0]=ch1;
        if (ch1 == 0xE0)
            ch2 = getch();
    }while(q[0]!='o');
    switch (y)
    {
        case 12:ajout_tete(l)/* ajoute tete */;
        case 14:ajout_queue(l)/* ajoute queue */;
        case 16:if(taille_liste_rep(l)>=2)
                    ajout_pos(l);
                else
                {
                    clrscr();
                    textcolor(12);gotoxy(10,20);
                    printf("LA TAILLE DE LA LISTE NE DOIT PAS ETRE <= 2 ");
                    textcolor(15);gotoxy(33,40);
                    printf("Appuyer sur une touche pour continuer");
                    getch();
                    menu_ajouter(l);
                }
                    /* ajout dans une position */;
        case 18: menu_maj(l) /* Retour menu MAJ*/;
    }
}
/****************MENU MISE A JOUR************/
void menu_maj(liste l)
{
    char ch_menu_gen[]="  MENU MISE A JOUR ";
    char fle[]=" ->",q[0];
    int y=12,ch1,ch2;
    clrscr();
    cadre('*',1);
    translation(ch_menu_gen+1,6);
    textcolor(13);
    gotoxy(22,12);
    printf("1- Ajouter un nouvel telephone  \n");gotoxy(22,14);
    printf("2- Supprimer un telephone \n");gotoxy(22,16);
    printf("3- Modifier les donnees d un telephone \n");gotoxy(22,18);
    printf("4- Retour Menu generale \n");gotoxy(22,20);
    textcolor(15);
    gotoxy(50,38);
    printf("Donner votre choix SVP ");
    gotoxy(23,40);
    printf("fleche haut=up , fleche bas=down , le caractere 'O'=ENTER");
    q[0]='0';
    ch2=0;
    do
    {
        if(ch2==80)
        {
            gotoxy(19,y);
            printf("  ");
            y+=2;
            if(y>18)
                y=12;
        }
        else
            if(ch2==72)
            {
                gotoxy(19,y);
                printf("  ");
                y-=2;
                if(y<=10)
                    y=18;
            }
        gotoxy(19,y);
        printf("%s",fle+1);
        ch2=0;
        ch1=getch();
        q[0]=ch1;
        if (ch1 == 0xE0)
            ch2 = getch();
    }while(q[0]!='o');
    switch (y)
    {
        case 12:menu_ajouter(l)/* menu ajouter */;
        case 14:menu_suppression(l)/* menu suppression */;
        case 16:menu_modification(l)/* MENU modification*/;
        case 18:menu_gen(l) /* Retour menu generale*/;
    }
}




/************** MENU GENERALE **************/
void menu_gen(liste l)
{
    char ch_menu_gen[]="  MENU GENERALE ";
    char fle[]=" ->",q[0];
    int y=12,ch1,ch2;
    clrscr();
    cadre('*',1);
    translation(ch_menu_gen+1,0);
    textcolor(13);
    gotoxy(20,12);
    printf("1- Creation du repertoire telephonique \n");gotoxy(20,14);
    printf("2- Mise ajour des telephones \n");gotoxy(20,16);
    printf("3- Recherche , affichage et Tri \n");gotoxy(20,18);
    printf("4- Enregistrement et chargement dans un fichier \n");gotoxy(20,20);
    printf("5- Quitter");
    textcolor(15);
    gotoxy(50,38);
    printf("Donner votre choix SVP ");
    gotoxy(23,40);
    printf("fleche haut=up , fleche bas=down , le caractere 'O'=ENTER");
    q[0]='0';
    ch2=0;
    do
    {
        if(ch2==80)
        {
            gotoxy(17,y);
            printf("  ");
            y+=2;
            if(y>20)
                y=12;
        }
        else
            if(ch2==72)
            {
                gotoxy(17,y);
                printf("  ");
                y-=2;
                if(y<=10)
                    y=20;
            }
        gotoxy(17,y);
        printf("%s",fle+1);
        ch2=0;
        ch1=getch();
        q[0]=ch1;
        if (ch1 == 0xE0)
            ch2 = getch();
    }while(q[0]!='o');
    switch (y)
    {
        case 12:creation(l);/* MENU creation du repertoire */
        case 14:menu_maj(l);/* MENU mise ajour */
        case 16:menu_rech_affichage(l)/* MENU recherche , affichage */;
        case 18:menu_enregistrement(l)/* MENU enregistrement*/;
        case 20:clrscr();system("exit");/*EXIT*/
    }
}
/*******************************************/
int main()
{
    liste l=NULL;
    chargement(l);
    //full_screen();
    //menu_gen(l);
}
