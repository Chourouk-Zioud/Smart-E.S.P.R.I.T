#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "admin.h"

/**********************************************************************************/

enum
{
	ENOM,
	EPRENOM,
	ECIN,
	EID,
	EDDN,
	ESEXE,
	EPOSTE,
	ETEL,
	COLUMNS
};

/********************************************************************************/

int verif_admin(char log[], char pw[])
{
	int trouve=-1;
	FILE *f=NULL;
	char ch1[20],ch2[20];

	f=fopen("admin.txt","r");
	if(f!=NULL)
	{
	while(fscanf(f,"%s %s",ch1,ch2)!=EOF)
	{
	if((strcmp(ch1,log)==0)&&(strcmp(ch2,pw)==0))
	trouve=1;
	}
	fclose(f);
	}
	return (trouve);
}

/*******************************************************************************/

void afficher_utl(GtkWidget *liste,char *fname)
{

	UTL p;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	gchar c[20],id[20],ddn[20],t[20];
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("NOM", renderer,"text",ENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("PRENOM", renderer,"text",EPRENOM, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("CIN", renderer,"text",ECIN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("IDENTIFIANT", renderer,"text",EID, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DATE DE NAISSANCE", renderer,"text",EDDN, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("SEXE", renderer,"text",ESEXE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("POSTE", renderer,"text",EPOSTE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("TELEPHONE", renderer,"text",ETEL, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);


	store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(fname,"r");
	if(f!=NULL)
	{
	f = fopen("BD.txt","a+");
	while(fscanf(f,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,&p.cin,&p.identifiant,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,p.sexe,p.poste,&p.tel)!=EOF)
	{
	sprintf(c,"%d",p.cin);
	sprintf(id,"%d",p.identifiant);
	sprintf(ddn,"%d/%d/%d",p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee);
	sprintf(t,"%d",p.tel);

	gtk_list_store_append(store,&iter);
	gtk_list_store_set (store,&iter,ENOM,p.nom,EPRENOM,p.prenom,ECIN,c,EID,id,EDDN,ddn,ESEXE, p.sexe,EPOSTE,p.poste,ETEL,t,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
	}
	gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}


/*******************************************************************************/

void ajouter_utl(UTL u,char *fname)

{
	FILE*f;
	GtkWidget *pQuestion;
	GtkWidget *pInfo;
	gpointer user_data;
	UTL p;
	int trouve;

	trouve = rechercher_utl(u.identifiant,"BD.txt");

	if(trouve==0)
	{
		f=fopen(fname,"a+");
		if(f != NULL)
		{
		fprintf(f,"%s %s %d %d %d %d %d %s %s %d \n",u.nom,u.prenom,u.cin,u.identifiant,u.date_de_naissance.jour,u.date_de_naissance.mois,u.date_de_naissance.annee,u.sexe,u.poste,u.tel);
		fclose(f);
		}
		pQuestion=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Utilisateur ajouté avec succès !");
		switch(gtk_dialog_run(GTK_DIALOG(pQuestion)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pQuestion);
		break;
		}
	}
	else
	{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Utilisateur déja existant !");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
	}	
}

/*******************************************************************************/

void modifier_utl(UTL u,char *fname)
{

	GtkWidget *pInfo;
	gpointer user_data;
	UTL p;
	int a=0;

	FILE *f;
	FILE *g;
	f=fopen(fname,"r");
	g=fopen("dump.txt","a+");

	if(f==NULL||g==NULL)
	{return;}
	else{
	while(fscanf(f,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,&p.cin,&p.identifiant,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,p.sexe,p.poste,&p.tel)!=EOF)
	{
	if(p.identifiant!=u.identifiant)
	fprintf(g,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,p.cin,p.identifiant,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.sexe,p.poste,p.tel);
	else{
	fprintf(g,"%s %s %d %d %d %d %d %s %s %d \n",u.nom,u.prenom,u.cin,p.identifiant,u.date_de_naissance.jour,u.date_de_naissance.mois,u.date_de_naissance.annee,u.sexe,u.poste,u.tel);
	}
	}

	fclose(f);
	fclose(g);
	remove(fname);
	rename("dump.txt",fname);
	}
}

/*******************************************************************************/

int rechercher_utl(int identifiant,char *fname)
{
	FILE *f=NULL;
	UTL p;
	int trouve=0;

	f=fopen(fname,"r");
	if(f != NULL)
	{
	while(fscanf(f,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,&p.cin,&p.identifiant,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,p.sexe,p.poste,&p.tel)!=EOF)
	{
	if(p.identifiant==identifiant)
	trouve=1;
	}
	}
	fclose(f);
	return (trouve);
}

/*******************************************************************************/

void supprimer_utl(UTL u,char *fname)
{
	UTL p;
	int trouve;
	GtkWidget *pInfo;
	gpointer user_data;
	FILE *f;
	FILE *g;

	f=fopen(fname,"r");
	g=fopen("dump.txt","w");

	if((f!=NULL) && (g!=NULL))
	{
		while(fscanf(f,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,&p.cin,&p.identifiant,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,p.sexe,p.poste,&p.tel)!=EOF)
		{
		if(p.identifiant!=u.identifiant)
		fprintf(g,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,p.cin,p.identifiant,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.sexe,p.poste,p.tel);
		}
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Utilisateur supprimé avec succès");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		fclose(f);
		fclose(g);
		remove(fname);
		rename("dump.txt",fname);
		
	}
}

/*******************************************************************************/

void supprimer_treeview(int identifiant,char *fname)

{
	UTL p;
	GtkWidget *pInfo;
	gpointer user_data;
	FILE *f;
	FILE *g;

	f=fopen(fname,"r");
	g=fopen("dump.txt","w");

	if((f!=NULL) && (g!=NULL))
	{
		while(fscanf(f,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,&p.cin,&p.identifiant,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,p.sexe,p.poste,&p.tel)!=EOF)
		{
		if(p.identifiant!=identifiant)
		fprintf(g,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,p.cin,p.identifiant,p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee,p.sexe,p.poste,p.tel);
		}
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Utilisateur supprimé avec succès");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		fclose(f);
		fclose(g);
		remove(fname);
		rename("dump.txt",fname);
		
	}
}

/*******************************************************************************/

char* plus_occupe(char *fname)
{
	UTL p;
	int etud=0, nutr=0, tech=0, sto=0, rest=0, foy=0;
	char* ch = (char*) malloc(1000);
	char msg[1000];

	FILE *f = fopen(fname,"r");
	if(f != NULL)
	{
	while(fscanf(f,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,&p.cin,&p.identifiant,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,p.sexe,p.poste,&p.tel)!=EOF)
	{
	if(strcmp(p.poste,"etudiant")==0)
	etud++;
	else
	if(strcmp(p.poste,"nutritionniste")==0)
	nutr++;
	else
	if(strcmp(p.poste,"technicien")==0)
	tech++;
	else
	if(strcmp(p.poste,"agent_de_stock")==0)
	sto++;
	else
	if(strcmp(p.poste,"agent_de_restaurant")==0)
	rest++;
	else
	foy++;
	}
        }
        fclose(f);

	if(etud>nutr && etud>tech && etud>sto && etud>rest && etud>foy)
	strcpy(ch,"etudiant");
	else
	if(nutr>etud && nutr>tech && nutr>sto && nutr>rest && nutr>foy)
	strcpy(ch,"nutritionniste");
	else
	if(tech>nutr && tech>etud && tech>sto && tech>rest && tech>foy)
	strcpy(ch,"technicien");
	else
	if(sto>nutr && sto>tech && sto>etud && sto>rest && sto>foy)
	strcpy(ch,"agent de stock");
	else
	if(rest>nutr && rest>tech && rest>sto && rest>etud && rest>foy)
	strcpy(ch,"agent de restaurant");
	else
	if(foy>nutr && foy>tech && foy>sto && foy>rest && foy>etud)
	strcpy(ch,"agent de foyer");
	else
	if(etud==0 && nutr==0 && tech==0 && sto==0 && rest==0 && foy==0)
	strcpy(ch,"Pas de poste occcupé !!!");
	else
	strcpy(ch,"Il existe une egalité entre deux ou plusieurs postes !!!");
	
	return ch;	
}

/*******************************************************************************/

UTL retourner_utl(int identifiant,char *fname)
{
	UTL p;
	UTL u;
	GtkWidget *pInfo;
	gpointer user_data;
	FILE *f;

	f=fopen(fname,"r");
	if(f != NULL)
	{
	while(fscanf(f,"%s %s %d %d %d %d %d %s %s %d \n",p.nom,p.prenom,&p.cin,&p.identifiant,&p.date_de_naissance.jour,&p.date_de_naissance.mois,&p.date_de_naissance.annee,p.sexe,p.poste,&p.tel)!=EOF)
	{
	if(p.identifiant == identifiant)
	u=p;
	}
	}
	return u;
}



/*********************************************************************************************/
/*********************************************************************************************/
/*********************************************************************************************/

/////////////////////////////////////// ETAGE EN PANNE ///////////////////////////////////////

enum
{
	EJOUR,
	EHEURE,
	EETAGE,
	EDEBIT,
	ECOLUMNS
};

void etage_panne(char *fname)

{
	FILE *f=NULL;
	FILE *ft=NULL;
	GtkWidget *pInfo;
	gpointer user_data;
	ETP ep;
	int trouve;

	f=fopen(fname,"r");
	ft=fopen("temp.txt","w");
	if(f!=NULL)
	while(fscanf(f,"%s %s %s %s\n",ep.jour,ep.heure,ep.etage,ep.debit)!=EOF)
	{
		if(atoi(ep.debit)>30)
		{
		fprintf(ft,"%s %s %s %s\n",ep.jour,ep.heure,ep.etage,ep.debit);
		trouve=1;
		}
	}
	if(trouve=0)
	{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"*** Pas de panne detectée *** ");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
	}
	fclose(f);
	fclose(ft);
	remove(fname);
	rename("temp.txt",fname);
}


////////////////////////////////////////////////////////////////////////////////////////////

void supprimer_panne(ETP ep,char *fname)
{
	ETP y;
	GtkWidget *pInfo;
	gpointer user_data;
	FILE *f;
	FILE *g;

	f=fopen(fname,"r");
	g=fopen("temp.txt","w");

	if((f!=NULL) && (g!=NULL))
	{
		while(fscanf(f,"%s %s %s %s\n",y.jour,y.heure,y.etage,y.debit)!=EOF)
		{
			if((strcmp(y.jour,ep.jour)==0) || (strcmp(y.heure,ep.heure)==0) || (strcmp(y.etage,ep.etage)==0) || (strcmp(y.debit,ep.debit)==0))
			{
			fprintf(g,"%s %s %s %s\n",y.jour,y.heure,y.etage,y.debit);
			}
		}

		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"enregistrement supprimé avec succès");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		fclose(f);
		fclose(g);
		remove(fname);
		rename("temp.txt",fname);
	}

}

////////////////////////////////////////////////////////////////////////////////////////////

void afficher_EP(GtkWidget *liste,char *fname)
{

	ETP ep;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	//gchar j[20],h[20],etg[20],d[20];
	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("JOUR", renderer,"text",EJOUR, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("HEURE", renderer,"text",EHEURE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ETAGE", renderer,"text",EETAGE, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("DEBIT", renderer,"text",EDEBIT, NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	gtk_tree_view_column_set_expand(column,TRUE);


	store=gtk_list_store_new (ECOLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen(fname,"r");
	if(f!=NULL)
	{
	f = fopen("debit.txt","a+");
	while(fscanf(f,"%s %s %s %s\n",ep.jour,ep.heure,ep.etage,ep.debit)!=EOF)
	{
	/*sprintf(j,"%d",ep.jour);
	sprintf(h,"%d",ep.heure);
	sprintf(etg,"%d",ep.etage);
	sprintf(d,"%f",ep.debit);*/

	gtk_list_store_append(store,&iter);
	gtk_list_store_set (store,&iter,EJOUR,ep.jour,EHEURE,ep.heure,EETAGE,ep.etage,EDEBIT,ep.debit,-1);
	}
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
	}
	gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
}

//////////////////////////////////////////////////////////////////////////////////

int nbr_pannes_etage(int n,char *fname)
{
	FILE *f;
	ETP y;
	char cmp[10];
	int nbr=0;

	f=fopen(fname,"r");
	if(f!=NULL)
	{
	while(fscanf(f,"%s %s %s %s\n",y.jour,y.heure,y.etage,y.debit)!=EOF)
	{
	if(atoi(y.etage)==n)
	nbr++;
	}
	}
return nbr;

}




