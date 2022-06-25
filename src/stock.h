#ifndef STOCK_H_INCLUDED
#define STOCK_H_INCLUDED

#include <gtk/gtk.h>
typedef struct stock
{
	char ref[20];
	char categorie[20];//1:Boissons 2:Fruits 3:Legumes
	int quantite; 
	char date[20];
	char fournisseur[20];
	char prix[20];
}stk;

void afficher_stock_tv(GtkWidget *liste);
void ajouter_stock(stk c);
void supprimer_stock(char ref[]);
void modifier_stock(stk s);
void afficher_stock(stk c);
void afficher_rupt_stock_tv(GtkWidget *liste);
int recherche_stock(char ref[]);
void rupture_stock(stk c);
#endif
