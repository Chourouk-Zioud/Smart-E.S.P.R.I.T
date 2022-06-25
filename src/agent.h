#ifndef AF_H_INCLUDED
#define AF_H_INCLUDED

#include <gtk/gtk.h>
typedef struct
{
  int jour;
  int mois;
  int annee;
}DATE;
typedef struct
{
  char nom[30];
  char prenom[30];
  DATE date;
  char classe[30];
  char chambre[30];
  char identifiant[30];
  char sexe[30];
}Etudiant;

void ajouter_edudiant(Etudiant E);
void afficher_etudiant(GtkWidget *liste);
int niveau(int calcul[],char txt[]);
void supprimer(char IDENTIFIANT[40]);
int recherche(Etudiant E,char IDENTIFIANT[40]);
void modifier(Etudiant E1);

#endif

