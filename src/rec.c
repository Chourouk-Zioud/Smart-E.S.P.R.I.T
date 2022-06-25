#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "rec.h"

enum{TYPER,IDENTIFIANTR,NOMR,CINR,PROBLEMR,DATER,DATER2,COLUMNS2};

void affichage(GtkWidget* treeview1)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;//mise a jour de donner 
RECLAMATION r;char Date[100];char Dater[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview1);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();//creation d eligne 
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom et Prenom", renderer, "text",NOMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CINR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("problem", renderer, "text",PROBLEMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date d'ajout", renderer, "text",DATER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de reclamation", renderer, "text",DATER2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("reclamation.bin","rb");//ouvrire un fisihier binaire en lire
if(f==NULL)
{return;}
else
{f=fopen("reclamation.bin","ab+");//ouvrire un fishier binaire en lmecture et ecreture a la fin 
while(fread(&r,sizeof(RECLAMATION),1,f))/*afficher le contenu de fishier reclamation.bin (binaire ) qui contien les information et le nbr n de reclamation*/
{sprintf(Date,"%d/%d/%d",r.datea.jour,r.datea.mois,r.datea.annee);
sprintf(Dater,"%d/%d/%d",r.dater.jour,r.dater.mois,r.dater.annee);

gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPER,r.type,IDENTIFIANTR,r.identifiant,NOMR,r.nom,CINR,r.cin,PROBLEMR,r.problem,DATER,Date,DATER2,Dater,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview1),GTK_TREE_MODEL (store));
g_object_unref(store);}}

/////////////////////////////////////////////////////////////////////////////////////////////////

void ajout (RECLAMATION r)
{
FILE*f=NULL; 
f=fopen("reclamation.bin","ab+");//ouverture un fishier binaire en lecture/ecruture ala fin 
fwrite(&r,sizeof(RECLAMATION),1,f);  
fclose(f);
 
}


void suppression(char id[30],RECLAMATION r){
FILE*f;
FILE*g;
f=fopen("reclamation.bin","rb+");//ouvrire un fioshier binaire en lire et ecreture  takra
g=fopen("tmp.bin","wb+");//ouvrire un fishier binaire.
if(g!=NULL){
while(fread(&r,sizeof(RECLAMATION),1,f))//qui permet de lire de donnée d etype reclamation  et la sauvgarder dans variable r 
{
if (strcmp(r.identifiant,id)!=0){
fwrite(&r,sizeof(RECLAMATION),1,g);// ecrire de donnée d etype reclamation  et la sauvgarder dans variable r 

}
}
}fclose(f);
fclose(g);
remove("reclamation.bin");
rename("tmp.bin","reclamation.bin");
}



void modification(char id[30],RECLAMATION r)
{

	suppression(id,r);
	ajout(r);

}

void recherchehk(GtkWidget* treeview1)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;RECLAMATION r;
 FILE *f2;char Date[100];char Dater[100];
 store=gtk_tree_view_get_model(treeview1);
 if (store==NULL)
{

   renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Nom et Prenom", renderer, "text",NOMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Cin", renderer, "text",CINR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("problem", renderer, "text",PROBLEMR, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date d'ajout", renderer, "text",DATER, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date de reclamation", renderer, "text",DATER2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview1), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&r,sizeof(RECLAMATION),1,f2))
     {sprintf(Date,"%d/%d/%d",r.datea.jour,r.datea.mois,r.datea.annee);
sprintf(Dater,"%d/%d/%d",r.dater.jour,r.dater.mois,r.dater.annee);

gtk_list_store_append (store,&iter);
gtk_list_store_set(store,&iter,TYPER,r.type,IDENTIFIANTR,r.identifiant,NOMR,r.nom,CINR,r.cin,PROBLEMR,r.problem,DATER,Date,DATER2,Dater,-1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview1), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
int nombrer(RECLAMATION r)
{
int k=0;


FILE *f;
f = fopen("reclamation.bin", "rb");
while (fread(&r,sizeof(r),1,f)){
if(strcmp(r.type,"Restauration")==0)
k=k+1;


}fclose(f);

return k;}
int nombreh(RECLAMATION r)
{
int h=0;


FILE *f;
f = fopen("reclamation.bin", "rb");
while (fread(&r,sizeof(r),1,f)){
if(strcmp(r.type,"Hébergement")==0)
h=h+1;


}fclose(f);

return h;
}

int verifid(char id[30])
{
   RECLAMATION r;
   int res = 1;
   FILE *f;
   f = fopen("reclamation.bin", "ab+");
   if (f != NULL)
   {
      while (fread(&r,sizeof(RECLAMATION),1,f))
      {
         if (strcmp(id,r.identifiant) == 0)
         {
            res = 0;
         }
         else
         {
            res = 1;
         }
      }
   }
   fclose(f);
   return res;
}
int veriff(char x[])
{
   int i=0;
   if (strcmp(x, "")==0)
   {
      i=0;
   }
   else
   {
      i=1;
   }
   return i;
}
