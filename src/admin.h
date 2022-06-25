
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>

/////////////////////////// STRUCT DDN ///////////////////////////

typedef struct naissance{
	int jour;
	int mois;
	int annee;
}DDN;

/////////////////////////// STRUCT UTL ///////////////////////////

typedef struct utilisateur{
	char nom[50];
	char prenom[50];
	int cin;
	int identifiant;
	DDN date_de_naissance;
	char sexe[50];
	char poste[50];
	int tel;
}UTL;

/////////////////////////// STRUCT EP ///////////////////////////

typedef struct etage_panne{
	char jour[10];
	char heure[10];
	char etage[10];
	char debit[10];
}ETP;

/////////////////////////// FONCTIONS ///////////////////////////

int verif_admin(char log[10], char pw[10]);

void afficher_utl(GtkWidget *liste,char *fname);

void ajouter_utl(UTL u,char *fname);

void modifier_utl(UTL u,char *fname);

int rechercher_utl(int identifiant,char *fname);

void supprimer_utl(UTL u,char *fname);

void supprimer_treeview(int identifiant,char *fname);

char* plus_occupe(char *fname);

UTL retourner_utl(int identifiant,char *fname);


/***************************************************************/

void etage_panne(char *fname);

void supprimer_panne(ETP ep,char *fname);

void afficher_EP(GtkWidget *liste,char *fname);

int nbr_pannes_etage(int n,char *fname);







