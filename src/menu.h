#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <gtk/gtk.h>

typedef struct Menus
{
    int jours ; //de 1 a 7
    int type;// 1/2/3
    char entree[50];
    char plat[50];
    char dessert[50];
}Menus;

void afficher_menu(GtkWidget *liste);
void vider_ab(GtkWidget *liste);
void rechercher_menu(GtkWidget *liste, char x1[],char x2[],char x3[],char ce[]);
void ajouter_ab(Menus menu);
void supprimer_ab(Menus R);
int rechercher_ab(Menus menu);
void afficher_ab(Menus menu);
void modifier_ab(Menus new);
void meilleur_ab(Menus menu);
void afficher_Dash(GtkWidget *liste,int c);

#endif
