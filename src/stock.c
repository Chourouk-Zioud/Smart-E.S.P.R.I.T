#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "stock.h"
#include<string.h>

enum
{
EREFERENCE,
ECATEGORIE,
EQUANTITE,
EDATE_EXP,
EFOURNISSEUR,
EPRIX,
COLUMNS
};
void ajouter_stock(stk c)
{
	FILE *f=NULL;
	f=fopen("stocks.txt","a+");
	fprintf(f,"%s %s %d %s %s %s \n",c.ref,c.categorie,c.quantite,c.date,c.fournisseur,c.prix);
	fclose(f);

}

int recherche_stock(char ref[])
{
	FILE*f=NULL;
 	stk c;
	f=fopen("stocks.txt","r");
	while(fscanf(f,"%s %s %d %s %s %s\n",c.ref,c.categorie,&c.quantite,c.date,c.fournisseur,c.prix)!=EOF)
	{
		if(strcmp(c.ref,ref)==0)
			return 1;
	}
	fclose(f);
	return 0;
}

void supprimer_stock(char ref[])
{
	FILE*f=NULL;
	FILE*f1=NULL;
	stk c ;
	f=fopen("stocks.txt","r");

	f1=fopen("ancien.txt","w+");
	while(fscanf(f,"%s %s %d %s %s %s\n",c.ref,c.categorie,&c.quantite,c.date,c.fournisseur,c.prix)!=EOF)
	{
		if(strcmp(ref,c.ref)!=0)
			fprintf(f1,"%s %s %d %s %s %s\n",c.ref,c.categorie,c.quantite,c.date,c.fournisseur,c.prix);
	}
	fclose(f);
	fclose(f1);
	remove("stocks.txt");
	rename("ancien.txt","stocks.txt");
}

void modifier_stock(stk s){


    stk OLD;
   
    FILE *f=NULL;
    FILE *f2=NULL;
   
    f=fopen("stocks.txt","r");
    f2=fopen("modif.txt","a");

    while(fscanf(f,"%s %s %d %s %s %s \n", OLD.ref, OLD.categorie, &OLD.quantite,OLD.date,OLD.fournisseur,OLD.prix)!=EOF)
    {
    if (strcmp(s.ref,OLD.ref)==0) {
            fprintf(f2,"%s %s %d %s %s %s \n", s.ref, s.categorie, s.quantite,s.date,s.fournisseur,s.prix);
        }
        else {
        fprintf(f2,"%s %s %d %s %s %s \n", OLD.ref, OLD.categorie, OLD.quantite,OLD.date,OLD.fournisseur,OLD.prix);
        }
	
    };

   fclose(f);
   fclose(f2);
   remove("stocks.txt");
   rename("modif.txt","stocks.txt");

   }

void afficher_stock(stk c) 
{

    FILE *f = NULL;
    f=fopen("stocks.txt","r");
    
    while (fscanf(f,"%s %s %d %s %s %s\n",c.ref,c.categorie,&c.quantite,c.date,c.fournisseur,c.prix)!=EOF){
    fprintf(f,"%s %s %d %s %s %s\n",c.ref,c.categorie,c.quantite,c.date,c.fournisseur,c.prix);
        
    }
    fclose(f);

}

void rupture_stock(stk c)
{
	FILE *f = NULL;
	FILE *rupt = NULL;

    	f=fopen("stocks.txt","r");
	rupt = fopen("ruptstock.txt","a+");

	while (fscanf(f,"%s %s %d %s %s %s\n",c.ref,c.categorie,&c.quantite,c.date,c.fournisseur,c.prix)!=EOF)
	{
		if (c.quantite==0)
			fprintf(rupt,"%s %s %d %s %s %s\n",c.ref,c.categorie,c.quantite,c.date,c.fournisseur,c.prix);
		
	}
	fclose(f);
	fclose(rupt);


}
void afficher_stock_tv(GtkWidget *liste)
{
	
	char chaine;
	GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkTreeIter iter;
  	GtkListStore *store;	
	char ref[20];
	char categorie[20];
	char quantite[20]; 
	char date[20];
	char fournisseur[20];
	char prix[20];
	store=NULL;

  	FILE *f;
	store=gtk_tree_view_get_model(liste);
 	if (store==NULL)
  	{
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
    		column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
  		column=gtk_tree_view_column_new_with_attributes("categorie",renderer,"text",ECATEGORIE,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",EQUANTITE,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);  		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
		column= gtk_tree_view_column_new_with_attributes("date_exp",renderer,"text",EDATE_EXP,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);    		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("fournisseur",renderer,"text",EFOURNISSEUR,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("prix",renderer,"text",EPRIX,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
  	}
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("stocks.txt", "r");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("stocks.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s %s",ref,categorie,quantite,date,fournisseur,prix)!=EOF)
    {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,EREFERENCE,ref,ECATEGORIE,categorie,EQUANTITE,quantite,EDATE_EXP,date,EFOURNISSEUR,fournisseur,EPRIX,prix, -1);

    }
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref (store);
	gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
   
}


}

void afficher_rupt_stock_tv(GtkWidget *liste)
{
	
	char chaine;
	GtkCellRenderer *renderer;
  	GtkTreeViewColumn *column;
  	GtkTreeIter iter;
  	GtkListStore *store;	
	char ref[20];
	char categorie[20];
	char quantite[20]; 
	char date[20];
	char fournisseur[20];
	char prix[20];
	store=NULL;

  	FILE *f;
	store=gtk_tree_view_get_model(liste);
 	if (store==NULL)
  	{
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
    		column=gtk_tree_view_column_new_with_attributes("reference",renderer,"text",EREFERENCE,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
///////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
  		column=gtk_tree_view_column_new_with_attributes("categorie",renderer,"text",ECATEGORIE,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
////////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",EQUANTITE,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);  		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
		column= gtk_tree_view_column_new_with_attributes("date_exp",renderer,"text",EDATE_EXP,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);    		
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("fournisseur",renderer,"text",EFOURNISSEUR,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
    		renderer= gtk_cell_renderer_text_new();
    		column= gtk_tree_view_column_new_with_attributes("prix",renderer,"text",EPRIX,NULL);
    		gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);



  	}
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("ruptstock.txt", "r");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("ruptstock.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s %s",ref,categorie,quantite,date,fournisseur,prix)!=EOF)
    {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,EREFERENCE,ref,ECATEGORIE,categorie,EQUANTITE,quantite,EDATE_EXP,date,EFOURNISSEUR,fournisseur,EPRIX,prix, -1);

    }
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref (store);
	gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
   
}


}
