#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED


/************* LES STRUCTURE ***************/

typedef struct
{
    char rue[20];
    char ville[20];
    int code_post;
}adresse;

/****************************/
typedef struct
{
    int jj,mm,aa;
}date_naissance;

/****************************/

typedef struct
{
    long num_tel;
    char nom[20];
    char pren[20];
    adresse ad;
    date_naissance dn;
    char mail[20];
}tel_inf;

/****************************/

struct cellule
{
    tel_inf info;
    struct cellule *suiv;
};
typedef struct cellule * liste;

/*******************************************/

#endif // STRUCTURE_H_INCLUDED
