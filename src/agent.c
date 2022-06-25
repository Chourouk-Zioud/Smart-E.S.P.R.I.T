#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include "agent.h"


enum
{
	ENOM,
	EPRENOM,
	EIDENTIFIANT,
	ECLASSE,
	ECHAMBRE,
	ESEXE,
	EDATE,
	COLUMNS
};
///////////////////////////////////////////////////////////////
void ajouter_edudiant(Etudiant E)
{
   FILE *f;
   f=fopen("etudiant.txt","a+");
   if(f!=NULL)
    {
     fprintf(f,"%s %s %s %s %s %s %d %d %d \n",E.nom,E.prenom,E.identifiant,E.classe,E.chambre,E.sexe,E.date.jour,E.date.mois,E.date.annee);
        fclose(f);
    }

}
//////////////////////////////////////////////////////////////////
void afficher_etudiant(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
    char nom[30];
    char prenom[30];
    char identifiant[30];
    char classe[30];
    char chambre[30];
    char sexe[30];
    char date_naissance[30];
    DATE date;
    Etudiant E;
    store=NULL;

    FILE *f;

    store=gtk_tree_view_get_model(liste);

    if(store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",ENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EPRENOM,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",EIDENTIFIANT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("classe",renderer,"text",ECLASSE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("chambre",renderer,"text",ECHAMBRE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ESEXE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("date",renderer,"text",EDATE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

    store=gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f=fopen("etudiant.txt","r");

    if(f==NULL)
    {return;}
    else
    { f=fopen("etudiant.txt","a+");
		
     while(fscanf(f,"%s %s %s %s %s %s %d %d %d",nom,prenom,identifiant,classe,chambre,sexe,&E.date.jour,&E.date.mois,&E.date.annee)!=EOF)
        {
	   sprintf(date_naissance,"%d/%d/%d",E.date.jour,E.date.mois,E.date.annee);

           gtk_list_store_append(store,&iter);
	           gtk_list_store_set(store,&iter,ENOM,nom,EPRENOM,prenom,EIDENTIFIANT,identifiant,ECLASSE,classe,ECHAMBRE,chambre,ESEXE,sexe,EDATE,date_naissance,-1);
       
	}

	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref (store);
    }   


}
//////////////////////////////////////////////////

int niveau(int calcul[],char txt[])
{
 	FILE *f=NULL;
	DATE date;
	Etudiant E;
    	int s1=0,s2=0,s3=0,s4=0,s5=0,s=0;
    	f=fopen("etudiant.txt","r");
  if(f!=NULL)
  {
        
          
		while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",E.nom,E.prenom,E.identifiant,E.classe,E.chambre,E.sexe,&E.date.jour,&E.date.mois,&E.date.annee)!=EOF)
			
        	{ 		if((calcul[0]==1) &&(strcmp(E.classe,"1")==0))

                                 {
                                  s1++;

                                 }

  				if((calcul[1]==1)&&(strcmp(E.classe,"2")==0))
                                {
                                 s2++;

                                }

 				if((calcul[2]==1)&&(strcmp(E.classe,"3")==0))
                                {
              			 s3++;

            			}

 				if((calcul[3]==1)&&(strcmp(E.classe,"4")==0))
            			{
              			s4++;

            			}

 				if((calcul[4]==1)&&(strcmp(E.classe,"5")==0))
            			{
              			s5++;

            			}
       
       
    		}
s=s1+s2+s3+s4+s5;
 }
    fclose(f);
return s;
}
///////////////////////////////////////////////////////////////////////
void supprimer(char IDENTIFIANT[40]){
FILE* f=NULL;
FILE*f1=NULL;
Etudiant E ;
f=fopen("etudiant.txt","r");
f1=fopen("bmt.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",E.nom,E.prenom,E.identifiant,E.classe,E.chambre,E.sexe,&E.date.jour,&E.date.mois,&E.date.annee)!=EOF){
if (strcmp(IDENTIFIANT,E.identifiant)!=0 )
{fprintf(f1,"%s %s %s %s %s %s %d %d %d\n",E.nom,E.prenom,E.identifiant,E.classe,E.chambre,E.sexe,E.date.jour,E.date.mois,E.date.annee);}
}
fclose(f);
fclose(f1);
remove("etudiant.txt");
rename("bmt.txt","etudiant.txt");
}


//////////////////////////////////////////////////
int  recherche(Etudiant E,char IDENTIFIANT[40])
{

	
       	FILE *f;
	FILE *f1;
        f=fopen("etudiant.txt","r");
        if(f==NULL)
{return;}
else    {

while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",E.nom,E.prenom,E.identifiant,E.classe,E.chambre,E.sexe,&E.date.jour,&E.date.mois,&E.date.annee)!=EOF)
        {
	if (strcmp (IDENTIFIANT, E.identifiant)==0)return 1;

       }
       }
	fclose(f);
   }


/////////////////////////////////////////////
void modifier(Etudiant E1){
FILE* f=NULL;
FILE* f1=NULL;
Etudiant E;
f=fopen("etudiant.txt","r");
f1=fopen("modif.txt","w");
while(fscanf(f,"%s %s %s %s %s %s %d %d %d\n",E.nom,E.prenom,E.identifiant,E.classe,E.chambre,E.sexe,&E.date.jour,&E.date.mois,&E.date.annee)!=EOF){
if (strcmp(E1.identifiant,E.identifiant)!=0)
{
fprintf(f1,"%s %s %s %s %s %s %d %d %d\n",E.nom,E.prenom,E.identifiant,E.classe,E.chambre,E.sexe,E.date.jour,E.date.mois,E.date.annee);
}
else
{
fprintf(f1,"%s %s %s %s %s %s  %d %d %d\n",E1.nom,E1.prenom,E1.identifiant,E1.classe,E1.chambre,E1.sexe,E1.date.jour,E1.date.mois,E1.date.annee);
}

}
fclose(f);
fclose(f1);

remove("etudiant.txt");
rename("modif.txt","etudiant.txt");
}

