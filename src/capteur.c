#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "capteur.h"
#include <gtk/gtk.h>

GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;

enum
{
REFERENCE,
TYPE,
ETAGE,
VALEUR,
JOUR,
HEURE,
COLUMNS
};
void fichierRef(){
FILE*f=NULL;
FILE*f1=NULL;
capt c;
f=fopen("Capteur.txt","r");
f1=fopen("reference.txt","w+");
while (fscanf(f,"%s %s %s %s %s %s\n" ,c.reference,c.type,c.etage,c.valeur,c.jour,c.heure)!=EOF)
{

fprintf(f1,"%s\n",c.reference);

}

fclose(f);
fclose(f1);

}

void ajoutercapteur(capt c) {  
 
    FILE *f ;
    f = fopen("Capteur.txt", "a+");
    if(f!=NULL)
{
    fprintf(f,"%s %s %s %s %s %s\n",c.reference,c.type,c.etage,c.valeur,c.jour,c.heure) ;
fclose(f);
}
}

int exist_capteur(char*id){
FILE*f=NULL;
 capt c;
f=fopen("Capteur.txt","r");
while(fscanf(f,"%s %s %s %s %s %s \n",c.reference,c.type,c.etage,c.valeur,c.jour,c.heure)!=EOF){
if(strcmp(c.reference,id)==0)return 1;
}
fclose(f);
return 0;
}

void afficher_capteur(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char reference[50];
 char type[50];
 char etage[20];
 char valeur[50];
 char jour[50];
char heure[50];
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",REFERENCE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("etage",renderer,"text",ETAGE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VALEUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("heure",renderer,"text",HEURE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("Capteur.txt", "r");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("Capteur.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s %s\n",reference,type,etage,valeur,jour,heure)!=EOF)
    {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,REFERENCE,reference,TYPE,type,ETAGE,etage,VALEUR,valeur,JOUR,jour,HEURE,heure, -1);

    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
   
}
}
int ChercherCapteur(GtkWidget* treeview1,char*l,char*reference)
{
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
capt c;
int nb=0, j;

        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
					G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n",c.reference,c.type,c.etage,c.valeur,c.jour,c.heure)!=EOF)
        {
	if( strcmp(reference,c.reference)==0){ nb++;
	GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.reference,
                            1,c.type,
                            2,c.etage,
                            3,c.valeur,
                            4,c.jour,
				5,c.heure,
                            -1);}
}
        fclose(f);

	/* Creation de la 1ere colonne */
if(j==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("reference",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("type",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("etage",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("valeur",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("jour",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("heure",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	//gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);
	j++;}
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}    

void supprimercapteur(char reference[100]) {
    
    capt c;
    
    FILE *f1=NULL;
    FILE *f2=NULL;
    f1 = fopen("Capteur.txt","r");
    f2 = fopen("dump.txt", "a");
    while(fscanf(f1,"%s %s %s %s %s %s\n",c.reference,c.type,c.etage,c.valeur,c.jour,c.heure)!=EOF){
        if (strcmp(reference,c.reference)!=0) {
           fprintf(f2,"%s %s %s %s %s %s\n",c.reference,c.type,c.etage,c.valeur,c.jour,c.heure);
        }
    
    }
    fclose(f1);
    fclose(f2);
    remove("Capteur.txt");
    rename("dump.txt","Capteur.txt");
   
}

void modifiercapteur(capt c,char reference[30]){
    
    
	supprimercapteur(reference);
	ajoutercapteur(c);
}

void Capteurs_Defect(capt c)
{
    
    FILE *f=NULL;
    FILE *f1=NULL;
    f=fopen("temperature.txt","r");
    f1=fopen("capteur2.txt","w");
     while(fscanf(f,"%s %s %s %s \n" ,c.jour,c.heure,c.reference,c.valeur)!=EOF)
     {
        if (atoi(c.valeur)<10 || atoi(c.valeur)>30)
        fprintf(f1,"%s %s %s %s %s %s \n" ,c.reference,"temperature","--" ,c.valeur,c.jour,c.heure);
     }
     fclose(f);
}

void Liste_Alarmes(capt c)
{
    FILE *f1=NULL;
    FILE *f=NULL;
    FILE *f2=NULL;
    f=fopen("fumee.txt","r");
    f2=fopen("mouvement.txt","r");
    f1=fopen("capteur1.txt","w");
    while(fscanf(f,"%s %s %s %s \n" ,c.jour,c.heure,c.reference,c.valeur)!=EOF)
    {
        if(strcmp(c.valeur,"1")==0)
        fprintf(f1,"%s %s %s %s %s %s \n" ,c.reference,"fumee","--" ,c.valeur,c.jour,c.heure);
    }
    while(fscanf(f2,"%s %s %s %s \n" ,c.jour,c.heure,c.reference,c.valeur)!=EOF)
    {
        if(strcmp(c.valeur,"1")==0)
        fprintf(f1,"%s %s %s %s %s %s \n" ,c.reference,"mouvement","--" ,c.valeur,c.jour,c.heure);
    }
    fclose(f);
    fclose(f2);
    fclose(f1);
}
    
void thetreeview(GtkWidget* treeview1,char*l){
int i;
capt c;


        /* Creation du modele */
        adstore = gtk_list_store_new(6,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s \n" ,c.reference,c.type,c.etage,c.valeur,c.jour,c.heure)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.reference,
                            1,c.type,
                            2,c.etage,
                            3,c.valeur,
                            4,c.jour,
                            5,c.heure,
                            -1);}
        fclose(f);

if(i==0)
	{
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("REFERENCE",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);
	
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ETAGE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VALEUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("JOUR",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("HEURE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	i++;
}
 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );
}
    
    



