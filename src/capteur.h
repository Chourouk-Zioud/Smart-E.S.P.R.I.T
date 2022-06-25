
#include <gtk/gtk.h> 

typedef struct capteur{
char reference[50];
char type[50];
char etage[50];
char valeur[50];
char jour[50];
char heure[50];
}capt;

void fichierRef();
void ajoutercapteur(capt c);
void afficher_capteur(GtkWidget *liste);
int ChercherCapteur(GtkWidget* treeview1,char*l,char*type);
int exist_capteur(char*id);
void thetreeview(GtkWidget* treeview1,char*l);

/*void afficher(char Capteur[]);*/




void modifiercapteur(capt c,char reference[100]);
void supprimercapteur(char reference[100]);


//dashboard//

void Liste_Alarmes(capt c);
void Capteurs_Defect(capt c);


