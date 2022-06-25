#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Datee;

typedef struct

{
char type[30];
char identifiant[30];
char nom[30];
char cin[30];
char problem[30];
Datee datea;
Datee dater;
}RECLAMATION;

void ajout(RECLAMATION r);
void recherchehk(GtkWidget* treeview1);
void suppression(char id[30], RECLAMATION r);
void affichage(GtkWidget* treeview1);
void modification(char id[30],RECLAMATION r);
int nombrer(RECLAMATION r);
int nombreh(RECLAMATION r);
int verifid(char id[30]);
int veriff(char x[]);

