#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"
#include "menu.h"
#include "stock.h"
#include "agent.h"
#include "rec.h"
#include "capteur.h"

////////////////////////// VARIABLES GENERALES //////////////////////////

int sexe_ajout = 1;
int sexe_modifier = 1;
int choix[6]={0,0,0,0,0,0};
int checked;

int p=1;
char x[20];
char x1[20];
char x2[20];
char x3[20];

int pme=1;

calcul[5]={0,0,0,0,0};
char so[50];
char sup[100],id[10];
Etudiant E;

char idhk[30],idrech[30];
GtkWidget *page_principale;
int m=0;
int a=0;


///////////////////////////////////// PAGE D'ACCEUIL //////////////////////////////////////

void
on_KAIS_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *welcome;
	GtkWidget *authentification;
	
	welcome = lookup_widget(button,"welcome");
	authentification = create_authentification();
	gtk_widget_show (authentification);
}


void
on_AMENI_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *welcome;
	GtkWidget *Acceuil_ab;
	
	welcome = lookup_widget(button,"welcome");
	Acceuil_ab = create_Acceuil_ab();
	gtk_widget_show (Acceuil_ab);
}

void
on_MERIEM_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *welcome;
	GtkWidget *Acceuil;
	
	welcome = lookup_widget(button,"welcome");
	Acceuil = create_Acceuil();
	gtk_widget_show (Acceuil);
}


void
on_BAKARY_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *welcome;
	GtkWidget *Authentification_bt;
	
	welcome = lookup_widget(button,"welcome");
	Authentification_bt = create_Authentification_bt();
	gtk_widget_show (Authentification_bt);
}



void
on_AHMED_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *welcome;
	GtkWidget *menuPrinahmed;
	
	welcome = lookup_widget(button,"welcome");
	menuPrinahmed = create_menuPrinahmed();
	gtk_widget_show (menuPrinahmed);
}


void
on_HAYKEL_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *welcome;
	GtkWidget *page_principale;
	
	welcome = lookup_widget(button,"welcome");
	page_principale = create_page_principale();
	gtk_widget_show (page_principale);
}


///////////////////////////// KAIS ///////////////////////////////////////

////////////////////////// AUTHENTIFICATION //////////////////////////

void
on_bouton_connecter_kais_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *login;
	GtkWidget *password;
	GtkWidget *gestion_des_utilisateurs;
	GtkWidget *authentification;
	char user[20];
	char pass[20];
	int trouve;

	login = lookup_widget (objet, "entry_login_kais");
	strcpy(user, gtk_entry_get_text(GTK_ENTRY(login)));

	password = lookup_widget (objet, "entry_password_kais");
	strcpy(pass, gtk_entry_get_text(GTK_ENTRY(password)));

	trouve=verif_admin(user,pass);

	if(trouve==1)
	{
		authentification = lookup_widget(objet,"authentification");
		gestion_des_utilisateurs = create_gestion_des_utilisateurs();
		gtk_widget_show (gestion_des_utilisateurs);
		gtk_widget_destroy(authentification);
	}
}

////////////////////////// ACCEUIL //////////////////////////

             /**************** appeler l'admin ****************/
void
on_bouton_appeler_kais_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *pInfo;

	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Numero de tel admin : 56181794\n\n\nNumero de tel nutritionniste : 53987174\n\n\nNumero de tel g.stock : 55980158\n\n\nNumero de tel technicien : ********\n\n\nNumero de tel s.reclamations : 53473475\n\n\nNumero de tel agent foyer : ********");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}

             /**************** envoyer sms au admin ****************/
void
on_bouton_envoyer_sms_kais_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *pInfo;

	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Numero de tel: 56181794");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}

             /**************** envoyer mail au admin ****************/
void
on_bouton_envoyer_mail_kais_clicked    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *pInfo;

	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"admin = kais.chalghoumi@esprit.tn\n\n\nnutritionniste = ameni.belhadj@esprit.tn\n\n\nagent foyer= bakarym.traore@esprit.tn\n\n\ng.stock= meriem.elleuch@esprit.tn\n\n\ntechnicien= ahmed.hachani@esprit.tn\n\n\ns.reclamations= haykel.mhadhbi@esprit.tn");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}


             /**************** goto treeview ****************/
void
on_bouton_afficher_kais_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *afficher_utilisateurs;
	GtkWidget *treeview_utilisateurs_kais;

	afficher_utilisateurs = lookup_widget(objet,"afficher_utilisateurs");
	afficher_utilisateurs = create_afficher_utilisateurs();
	gtk_widget_show(afficher_utilisateurs);
	treeview_utilisateurs_kais = lookup_widget(afficher_utilisateurs,"treeview_utilisateurs_kais");
	afficher_utl(treeview_utilisateurs_kais,"BD.txt");

}

             /**************** goto formulaire d'ajout ****************/
void
on_bouton_ajouter_kais_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
	ajouter_utilisateur = lookup_widget(objet,"ajouter_utilisateur");
	ajouter_utilisateur = create_ajouter_utilisateur();
	gtk_widget_show(ajouter_utilisateur);
}

             /**************** goto formulaire de modification ****************/
void
on_bouton_modifier_kais_clicked        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *modifier_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
	modifier_utilisateur = lookup_widget(objet,"modifier_utilisateur");
	modifier_utilisateur = create_modifier_utilisateur();
	gtk_widget_show(modifier_utilisateur);
}

             /**************** goto formulaire de suppression ****************/
void
on_bouton_supprimer_kais_clicked       (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs =lookup_widget(objet,"gestion_des_utilisateurs");
	supprimer_utilisateur = lookup_widget(objet,"supprimer_utilisateur");
	supprimer_utilisateur = create_supprimer_utilisateur();
	gtk_widget_show(supprimer_utilisateur);
}

             /**************** afficher le poste le plus accupé ****************/
void
on_bouton_poste_plus_occupe_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *pInfo;
	char poste[1000],str[1000];

	strcpy(poste,plus_occupe("BD.txt"));
	sprintf(str,"%s",poste);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,str);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
}

////////////////////////// RADIO BUTTON AJOUT SEXE //////////////////////////

void
on_radio_ajouter_homme_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(togglebutton))
		{sexe_ajout=1;}
}


void
on_radio_ajouter_femme_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if ( gtk_toggle_button_get_active(togglebutton))
		{sexe_ajout=2;}
}


////////////////////////// CHECK BUTTON //////////////////////////

             /**************** etudiant ****************/
void
on_check_ajouter_etudiant_kais_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
		{choix[0]=1;}
}

             /**************** nutritionniste ****************/
void
on_check_ajouter_nutritionniste_kais_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
		{choix[1]=1;}
}

             /**************** technicien ****************/
void
on_check_ajouter_technicien_kais_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
		{choix[2]=1;}
}

             /**************** agent_de_stock ****************/
void
on_check_ajouter_stock_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
		{choix[3]=1;}
}

             /**************** agent_de_restaurant ****************/
void
on_check_ajouter_restaurant_kais_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
		{choix[4]=1;}
}

             /**************** agent_de_foyer ****************/
void
on_check_ajouter_foyer_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(togglebutton))
		{choix[5]=1;}
}

////////////////////////// AJOUTER UTILISATEUR //////////////////////////

void
on_bouton_confirmer_ajout_kais_clicked (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *ajouter_utilisateur;
	GtkWidget *gestion_des_utilisateurs;
	GtkWidget *nom;
	GtkWidget *prenom;
	GtkWidget *cin;
	GtkWidget *identifiant;
	GtkWidget *jour;
	GtkWidget *mois;
	GtkWidget *annee;
	GtkWidget *tel;
	GtkWidget *sexe;
	GtkWidget *poste;
	GtkWidget *CALENDAR;
	GtkWidget *pInfo;
	char x[20],y[20],z[20];
	int aa,mm,jj;
	int erreur_cin=1,erreur_id=1,erreur_tel=1,erreur_poste=1;
	UTL u;

	nom = lookup_widget(objet,"entry_ajouter_nom_kais");
	strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

	prenom = lookup_widget(objet,"entry_ajouter_prenom_kais");
	strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

	cin = lookup_widget(objet,"entry_ajouter_cin_kais");
	strcpy(x,gtk_entry_get_text(GTK_ENTRY(cin)));
	u.cin = atoi(x);

	if(u.cin>999999 && u.cin<99999999)
	{
	erreur_cin=0;
	}

	identifiant = lookup_widget(objet,"entry_ajouter_id_kais");
	strcpy(y,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	u.identifiant = atoi(y);

	if(u.identifiant>0 && u.identifiant<9999)
	{
	erreur_id=0;
	}

	tel =lookup_widget(objet,"entry_ajouter_tel_kais");
	strcpy(z,gtk_entry_get_text(GTK_ENTRY(tel)));
	u.tel=atoi(z);

	if(u.tel<100000000 && u.tel>9999999)
	{
	erreur_tel=0;
	}
	
	CALENDAR = lookup_widget(objet,"calendar_ajouter_ddn_kais");
	gtk_calendar_get_date (GTK_CALENDAR(CALENDAR), &aa, &mm, &jj);

	u.date_de_naissance.jour = jj;
	u.date_de_naissance.mois = mm+1;
	u.date_de_naissance.annee = aa;
	
	if(sexe_ajout==1)
	{strcpy(u.sexe,"homme");}
	else
	if(sexe_ajout==2)
	{strcpy(u.sexe,"femme");}
	
	if(choix[0]==1 && choix[1]==0 && choix[2]==0 && choix[3]==0 && choix[4]==0 && choix[5]==0)
	{strcpy(u.poste,"etudiant");
	erreur_poste=0;}

	if(choix[0]==0 && choix[1]==1 && choix[2]==0 && choix[3]==0 && choix[4]==0 && choix[5]==0)
	{strcpy(u.poste,"nutritionniste");
	erreur_poste=0;}

	if(choix[0]==0 && choix[1]==0 && choix[2]==1 && choix[3]==0 && choix[4]==0 && choix[5]==0)
	{strcpy(u.poste,"technicien");
	erreur_poste=0;}

	if(choix[0]==0 && choix[1]==0 && choix[2]==0 && choix[3]==1 && choix[4]==0 && choix[5]==0)
	{strcpy(u.poste,"agent_de_stock");
	erreur_poste=0;}

	if(choix[0]==0 && choix[1]==0 && choix[2]==0 && choix[3]==0 && choix[4]==1 && choix[5]==0)
	{strcpy(u.poste,"agent_de_restaurant");
	erreur_poste=0;}

	if(choix[0]==0 && choix[1]==0 && choix[2]==0 && choix[3]==0 && choix[4]==0 && choix[5]==1)
	{strcpy(u.poste,"agent_de_foyer");
	erreur_poste=0;}

	if(erreur_cin==0 && erreur_id==0 && erreur_tel==0 && erreur_poste==0)
	{
	ajouter_utl(u,"BD.txt");
	}
	else
	if(erreur_cin==0 && erreur_id==0 && erreur_tel==0 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"choix du poste invalide !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==0 && erreur_id==0 && erreur_tel==1 && erreur_poste==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Numero de Tel non valide !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==0 && erreur_id==0 && erreur_tel==1 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Numero de Tel et choix du poste non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==0 && erreur_id==1 && erreur_tel==0 && erreur_poste==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Identifiant non valide(ne doit pas depasser 4 chiffres) !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==0 && erreur_id==1 && erreur_tel==0 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Choix du poste et identifiant non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==0 && erreur_id==1 && erreur_tel==1 && erreur_poste==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Numero de tel et identifiant non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==0 && erreur_id==1 && erreur_tel==1 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Numero de tel, choix du poste et identifiant non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==0 && erreur_tel==0 && erreur_poste==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN non valide !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==0 && erreur_tel==0 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN et choix du poste non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==0 && erreur_tel==1 && erreur_poste==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN et numero de tel non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==0 && erreur_tel==1 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN, choix du poste et numero de tel non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==1 && erreur_tel==0 && erreur_poste==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN et identifiant non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==1 && erreur_tel==0 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN, choix du poste et identifiant non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==1 && erreur_tel==1 && erreur_poste==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN, numero de tel et identifiant non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	if(erreur_cin==1 && erreur_id==1 && erreur_tel==1 && erreur_poste==1)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN, numero de tel,choix du poste et identifiant non valides !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}

}

////////////////////////// ANNULER L'AJOUT //////////////////////////

void
on_bouton_annuler_ajout_kais_clicked   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
	ajouter_utilisateur = lookup_widget(objet,"ajouter_utilisateur");
	gtk_widget_hide(ajouter_utilisateur);
}

////////////////////////// ANNULER LA RECHERCHE //////////////////////////

void
on_bouton_quitter_recherche_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *rechercher_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
	rechercher_utilisateur = lookup_widget(objet,"rechercher_utilisateur");
	gtk_widget_hide(rechercher_utilisateur);
}

////////////////////////// RECHERCHER //////////////////////////

void
on_bouton_verifier_recherche_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	int trouve;
	char x[20],msg[1000],ddn[20];
	GtkWidget *rechercher_utilisateur;
	GtkWidget *modifier_utilisateur;
	GtkWidget *identifiant;
	GtkWidget *pInfo;
	UTL u;
	UTL p;

	identifiant = lookup_widget(objet,"entry_recherche_kais");
	strcpy(x,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	u.identifiant=atoi(x);

	p = retourner_utl(u.identifiant,"BD.txt");

	sprintf(ddn,"%d/%d/%d",p.date_de_naissance.jour,p.date_de_naissance.mois,p.date_de_naissance.annee);

	trouve = rechercher_utl(u.identifiant,"BD.txt");
	if(trouve==0)
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_WARNING,GTK_BUTTONS_OK,"Identifiant introuvable");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else
	{


	sprintf(msg,"nom: %s\n\n\nprenom: %s\n\n\ncin: %d\n\n\nid: %d\n\n\nné(e) le: %s\n\n\nsexe: %s\n\n\nposte: %s\n\n\nN°tel: %d",p.nom,p.prenom,p.cin,p.identifiant,ddn,p.sexe,p.poste,p.tel);

	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,msg);
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
}

////////////////////////// RADIO BUTTON MODIFIER SEXE //////////////////////////

void
on_radio_modifier_femme_kais_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
		{sexe_modifier=1;}
}


void
on_radio_modifier_homme_kais_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if ( gtk_toggle_button_get_active(togglebutton))
		{sexe_modifier=2;}
}

////////////////////////// MODIFIER UTILISATEUR //////////////////////////

void
on_bouton_confirmer_modification_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ajouter_utilisateur;
	GtkWidget *gestion_des_utilisateurs;
	GtkWidget *nom;
	GtkWidget *prenom;
	GtkWidget *cin;
	GtkWidget *identifiant;
	GtkWidget *sexe_h;
	GtkWidget *sexe_f;
	GtkWidget *ddn_jour;
	GtkWidget *ddn_mois;
	GtkWidget *ddn_annee;
	GtkWidget *poste;
	GtkWidget *tel;
	GtkWidget *combobox_modifier_poste_kais;
	GtkWidget *pInfo;
	int trouve,aa,mm,jj;
	int aux=-1;
	int erreur_cin=1,erreur_id=1,erreur_tel=1,erreur_poste=1;
	bool bh,bf;
	char x[20],y[20],z[20],id[20],c[20],t[20];
	UTL u;

	if(checked=1)
	{
		nom = lookup_widget(objet,"entry_modifier_nom_kais");
		strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));

		prenom = lookup_widget(objet,"entry_modifier_prenom_kais");
		strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));

		cin = lookup_widget(objet,"entry_modifier_cin_kais");
		strcpy(x,gtk_entry_get_text(GTK_ENTRY(cin)));
		u.cin = atoi(x);

		if(u.cin>999999 && u.cin<99999999)
		{
		erreur_cin=0;
		}

		identifiant = lookup_widget(objet,"entry_modifier_id_kais");
		strcpy(y,gtk_entry_get_text(GTK_ENTRY(identifiant)));
		u.identifiant = atoi(y);

		if(u.identifiant>0 && u.identifiant<9999)
		{
		erreur_id=0;
		}

		ddn_jour = lookup_widget(objet,"spin_modifier_jour_kais");
		u.date_de_naissance.jour = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (ddn_jour));

		ddn_mois = lookup_widget(objet,"spin_modifier_mois_kais");
		u.date_de_naissance.mois = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (ddn_mois));

		ddn_annee = lookup_widget(objet,"spin_modifier_annee_kais");
		u.date_de_naissance.annee = gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (ddn_annee));

		if(sexe_modifier==1)
		{strcpy(u.sexe,"homme");}
		else
		if(sexe_modifier==2)
		{strcpy(u.sexe,"femme");}

		poste = lookup_widget(objet,"combobox_modifier_poste_kais");
		strcpy(u.poste,gtk_combo_box_get_active_text(GTK_COMBO_BOX(poste)));

		tel = lookup_widget(objet,"entry_modifier_tel_kais");
		strcpy(z,gtk_entry_get_text(GTK_ENTRY(tel)));
		u.tel=atoi(z);
		if(u.tel<100000000 && u.tel>9999999)
		{
		erreur_tel=0;
		}

		if(erreur_cin==0 && erreur_id==0 && erreur_tel==0)
		{
		modifier_utl(u,"BD.txt");
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Utilisateur modifié avec succès");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
		else
		if(erreur_cin==0 && erreur_id==0 && erreur_tel==1)
		{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Numero de telephone non valide !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
		else
		if(erreur_cin==0 && erreur_id==1 && erreur_tel==0)
		{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Identifiant non valide(ne doit pas depasser 4 chiffres) !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
		else
		if(erreur_cin==0 && erreur_id==1 && erreur_tel==1)
		{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Numero de telephone et identifiant non valides !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
		else
		if(erreur_cin==1 && erreur_id==0 && erreur_tel==0)
		{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN non valide !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
		else
		if(erreur_cin==1 && erreur_id==0 && erreur_tel==1)
		{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Numero de telephone et CIN non valides !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
		else
		if(erreur_cin==1 && erreur_id==1 && erreur_tel==0)
		{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN et identifiant non valides !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
		else
		if(erreur_cin==1 && erreur_id==1 && erreur_tel==1)
		{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"CIN , identifiant et Numero de telephone non valides !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
		}
	}
	else
	{
		pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Attention !!! Utilisateur n'existe pas !!!");
		switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
		{
		case GTK_RESPONSE_OK:
		gtk_widget_destroy(pInfo);
		break;
		}
	}
	checked=0;

}

////////////////////////// ANNULER MODIFICATION //////////////////////////

void
on_bouton_annuler_modification_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *modifier_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
	modifier_utilisateur = lookup_widget(objet,"modifier_utilisateur");
	gtk_widget_hide(modifier_utilisateur);
}

//////////////////////////  TREEVIEW  //////////////////////////

void
on_treeview_utilisateurs_kais_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *nom;
	gchar *prenom;
	gchar *cin;
	gchar *identifiant;
	gchar *date ;
	gchar *sexe;
	gchar *poste;
	gchar *tel;
	GtkWidget *pInfo;
	int id;
	UTL u;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,3,&identifiant,4,&date,5,&sexe,6,&poste,7,&tel,-1);
	//afficher_utl(treeview,"BD.txt");

	id=atoi(identifiant);

	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet utilisateur ?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	{gtk_widget_destroy(pInfo);
	supprimer_treeview(id,"BD.txt");
	break;}
	case GTK_RESPONSE_NO:
	{gtk_widget_destroy(pInfo);
	break;}
	}
	}
}

//////////////////////////  ACTUALISER  //////////////////////////

void
on_bouton_actualiser_utilisateurs_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *treeview_utilisateurs_kais;
	GtkWidget *afficher_utilisateurs;

	afficher_utilisateurs = lookup_widget(objet,"afficher_utilisateurs");
	gtk_widget_destroy(afficher_utilisateurs);
	afficher_utilisateurs = lookup_widget(objet,"afficher_utilisateurs");
	afficher_utilisateurs = create_afficher_utilisateurs();
	gtk_widget_show(afficher_utilisateurs);
	treeview_utilisateurs_kais = lookup_widget(afficher_utilisateurs,"treeview_utilisateurs_kais");
	afficher_utl(treeview_utilisateurs_kais,"BD.txt");

}

//////////////////////////  QUITTER TREEVIEW  //////////////////////////

void
on_bouton_quitter_utilisateurs_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *afficher_utilisateurs;
	GtkWidget *gestion_des_utilisateurs;

	afficher_utilisateurs = lookup_widget(objet,"afficher_utilisateurs");
	gtk_widget_destroy(afficher_utilisateurs);

}

////////////////////////// ANNULER SUPPRESSION //////////////////////////

void
on_bouton_annuler_suppression_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *supprimer_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
	supprimer_utilisateur = lookup_widget(objet,"supprimer_utilisateur");
	gtk_widget_hide(supprimer_utilisateur);
}

////////////////////////// SUPPRESSION //////////////////////////

void
on_bouton_confirmer_suppression_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *gestion_des_utilisateurs;
	GtkWidget *supprimer_utilisateur;
	GtkWidget *identifiant;
	GtkWidget *pInfo;
	UTL u;
	int trouve,id;
	char ident[20];

	identifiant = lookup_widget(objet,"entry_supprimer_id_kais");
	strcpy(ident,gtk_entry_get_text(GTK_ENTRY(identifiant)));
	id = atoi(ident);
	trouve = rechercher_utl(id,"BD.txt");

	if(trouve==1)
	{
		u = retourner_utl(id,"BD.txt");
		supprimer_utl(u,"BD.txt");
		gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
		supprimer_utilisateur = lookup_widget(objet,"supprimer_utilisateur");
		gtk_widget_hide(supprimer_utilisateur);
	}
	else
	{
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Utilisateur n'existe pas !!!\nentrer un autre identifiant");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
}

////////////////////////// CHECK //////////////////////////

void
on_button_modifier_check_kais_clicked  (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ID;
	GtkWidget *nom;
	GtkWidget *prenom;
	GtkWidget *cin;
	GtkWidget *identifiant;
	GtkWidget *sexe_h;
	GtkWidget *sexe_f;
	GtkWidget *ddn_jour;
	GtkWidget *ddn_mois;
	GtkWidget *ddn_annee;
	GtkWidget *poste;
	GtkWidget *tel;
	GtkWidget *pInfo;
	int aux,aa,mm,jj,i;
	int trouve=0;
	bool bh,bf;
	char ident[20],x[20],y[20],z[20],id[20],c[20],t[20];
	UTL p;


	ID = lookup_widget(objet,"entry_modifier_check_kais");
	strcpy(ident,gtk_entry_get_text(GTK_ENTRY(ID)));
	i = atoi(ident);

	trouve = rechercher_utl(i,"BD.txt");
	p = retourner_utl(i,"BD.txt");

	if(trouve==1){
	checked=1;
	nom = lookup_widget(objet,"entry_modifier_nom_kais");
	gtk_entry_set_text(GTK_ENTRY(nom),p.nom);

	prenom = lookup_widget(objet,"entry_modifier_prenom_kais");
	gtk_entry_set_text(GTK_ENTRY(prenom),p.prenom);

	cin = lookup_widget(objet,"entry_modifier_cin_kais");
	sprintf(c,"%d",p.cin);
	gtk_entry_set_text(GTK_ENTRY(cin),c);

	identifiant = lookup_widget(objet,"entry_modifier_id_kais");
	sprintf(id,"%d",p.identifiant);
	gtk_entry_set_text(GTK_ENTRY(identifiant),id);

	sexe_h = lookup_widget(objet,"radio_modifier_homme_kais");
	if(strcmp(p.sexe,"homme")==0)
	bh=TRUE;
	else
	bh=FALSE;
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (sexe_h),bh);

	sexe_f = lookup_widget(objet,"radio_modifier_femme_kais");
	if(strcmp(p.sexe,"femme")==0)
	bf=TRUE;
	else
	bf=FALSE;
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON (sexe_f),bf);



	ddn_jour = lookup_widget(objet,"spin_modifier_jour_kais");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON (ddn_jour),p.date_de_naissance.jour);

	ddn_mois = lookup_widget(objet,"spin_modifier_mois_kais");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON (ddn_mois),p.date_de_naissance.mois-1);

	ddn_annee = lookup_widget(objet,"spin_modifier_annee_kais");
	gtk_spin_button_set_value(GTK_SPIN_BUTTON (ddn_mois),p.date_de_naissance.annee);

	poste = lookup_widget(objet,"combobox_modifier_poste_kais");
	if(strcmp(p.poste,"etudiant")==0)
	aux=0;
	if(strcmp(p.poste,"nutritionniste")==0)
	aux=1;
	if(strcmp(p.poste,"technicien")==0)
	aux=2;
	if(strcmp(p.poste,"agent_de_stock")==0)
	aux=3;
	if(strcmp(p.poste,"agent_de_restaurant")==0)
	aux=4;
	if(strcmp(p.poste,"agent_de_foyer")==0)
	aux=5;
	gtk_combo_box_set_active(GTK_COMBO_BOX(poste),aux);

	tel = lookup_widget(objet,"entry_modifier_tel_kais");
	sprintf(t,"%d",p.tel);
	gtk_entry_set_text(GTK_ENTRY(tel),t);
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Utilisateur trouvé !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
	else{
	checked=0;
	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,GTK_BUTTONS_OK,"Utilisateur non trouvé !!!");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_OK:
	gtk_widget_destroy(pInfo);
	break;
	}
	}
}

////////////////////////// INFOS //////////////////////////

void
on_bouton_about_kais_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *rechercher_utilisateur;
	GtkWidget *gestion_des_utilisateurs;

	gestion_des_utilisateurs = lookup_widget(objet,"gestion_des_utilisateurs");
	rechercher_utilisateur = lookup_widget(objet,"rechercher_utilisateur");
	rechercher_utilisateur = create_rechercher_utilisateur();
	gtk_widget_show(rechercher_utilisateur);
}

/////////////////////////////// AMENI //////////////////////////////////////////////////

void
on_button1_gestion_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *treeview1_ab;
Gestion_ab=lookup_widget(button,"Gestion_ab");
Gestion_ab=create_Gestion_ab();
gtk_widget_show(Gestion_ab);
treeview1_ab=lookup_widget(Gestion_ab,"treeview1_ab");
afficher_menu(treeview1_ab);
}


void
on_button2_meilleur_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Meilleur1_ab;
Meilleur1_ab=lookup_widget(button,"Meilleur1_ab");
Meilleur1_ab=create_Meilleur1_ab();
gtk_widget_show(Meilleur1_ab);
}


void
on_button7_home_ab_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_ab;
GtkWidget *Gestion_ab;
Gestion_ab=lookup_widget(button,"Gestion_ab");
gtk_widget_destroy(Gestion_ab);
Acceuil_ab=lookup_widget(button,"Acceuil_ab");
Acceuil_ab=create_Acceuil_ab();
gtk_widget_show(Acceuil_ab);
}


void
on_button3_ajouter_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Ajouter_ab;
GtkWidget *Gestion_ab;
Gestion_ab=lookup_widget(button,"Gestion_ab");
gtk_widget_destroy(Gestion_ab);
Ajouter_ab=lookup_widget(button,"Ajouter_ab");
Ajouter_ab=create_Ajouter_ab();
gtk_widget_show(Ajouter_ab);
}


void
on_button4_modifier_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Modifier_ab;
GtkWidget *Gestion_ab;
Gestion_ab=lookup_widget(button,"Gestion_ab");
gtk_widget_destroy(Gestion_ab);
Modifier_ab=lookup_widget(button,"Modifier_ab");
Modifier_ab=create_Modifier_ab();
gtk_widget_show(Modifier_ab);
}


void
on_button5_supprimer_ab_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Supprimer_ab;
GtkWidget *Gestion_ab;
GtkWidget *treeview3_ab;
Gestion_ab=lookup_widget(button,"Gestion_ab");
gtk_widget_destroy(Gestion_ab);
Supprimer_ab=lookup_widget(button,"Supprimer_ab");
Supprimer_ab=create_Supprimer_ab();
gtk_widget_show(Supprimer_ab);
treeview3_ab=lookup_widget(Supprimer_ab,"treeview3_ab");
afficher_menu(treeview3_ab);
}


void
on_button6_afficher_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *Afficher_ab;
GtkWidget *treeview2_ab;
Gestion_ab=lookup_widget(button,"Gestion_ab");
gtk_widget_destroy(Gestion_ab);
Afficher_ab=lookup_widget(button,"Afficher_ab");
Afficher_ab=create_Afficher_ab();
gtk_widget_show(Afficher_ab);
treeview2_ab=lookup_widget(Afficher_ab,"treeview2_ab");
afficher_menu(treeview2_ab);
}


void
on_button8_home_ab_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_ab;
GtkWidget *Ajouter_ab;
Ajouter_ab=lookup_widget(button,"Ajouter_ab");
gtk_widget_destroy(Ajouter_ab);
Acceuil_ab=lookup_widget(button,"Acceuil_ab");
Acceuil_ab=create_Acceuil_ab();
gtk_widget_show(Acceuil_ab);
}


void
on_button10_ajouter_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entree,*plat, *combobox,*dessert;
Menus menu;
entree = lookup_widget (button, "entry1_entree_ab");
plat= lookup_widget (button, "entry2_plat_ab"); 
dessert= lookup_widget (button, "entry3_dessert_ab");
combobox = lookup_widget (button, "comboboxentry1_ab");
 
strcpy(menu.entree , gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(menu.plat , gtk_entry_get_text(GTK_ENTRY(plat)));
strcpy(menu.dessert, gtk_entry_get_text(GTK_ENTRY(dessert)));
if (strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=1;
if (strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=2;
if (strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=3;
if (strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=4;
if (strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=5;
if (strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=6;
if (strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
menu.jours=7;
menu.type=p;
ajouter_ab(menu);
}


void
on_radiobutton1_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=1;
}


void
on_radiobutton2_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=2;
}


void
on_radiobutton3_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=3;
}


void
on_button9_return_ab_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *Ajouter_ab;
GtkWidget *treeview1_ab;
Ajouter_ab=lookup_widget(button,"Ajouter_ab");
gtk_widget_destroy(Ajouter_ab);
Gestion_ab=lookup_widget(button,"Gestion_ab");
Gestion_ab=create_Gestion_ab();
gtk_widget_show(Gestion_ab);
treeview1_ab=lookup_widget(Gestion_ab,"treeview1_ab");
afficher_menu(treeview1_ab);
}


void
on_button11_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_ab;
GtkWidget *Modifier_ab;
Modifier_ab=lookup_widget(button,"Modifier_ab");
gtk_widget_destroy(Modifier_ab);
Acceuil_ab=lookup_widget(button,"Acceuil_ab");
Acceuil_ab=create_Acceuil_ab();
gtk_widget_show(Acceuil_ab);
}


void
on_button13_modifier_ab_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entree,*plat, *combobox,*dessert;
Menus new;
entree = lookup_widget (button, "entry4_entree_ab");
plat = lookup_widget (button, "entry5_plat_ab"); 
dessert= lookup_widget (button, "entry6_dessert_ab");
combobox = lookup_widget (button, "comboboxentry2_ab");
 
strcpy(new.entree , gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(new.plat, gtk_entry_get_text(GTK_ENTRY(plat)));
strcpy(new.dessert , gtk_entry_get_text(GTK_ENTRY(dessert)));
if (strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=1;
if (strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=2;
if (strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=3;
if (strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=4;
if (strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=5;
if (strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=6;
if (strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
new.jours=7;
new.type=p;
modifier_ab(new);
}


void
on_button12_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *Modifier_ab;
GtkWidget *treeview1_ab;
Modifier_ab=lookup_widget(button,"Modifier_ab");
gtk_widget_destroy(Modifier_ab);
Gestion_ab=lookup_widget(button,"Gestion_ab");
Gestion_ab=create_Gestion_ab();
gtk_widget_show(Gestion_ab);
treeview1_ab=lookup_widget(Gestion_ab,"treeview1_ab");
afficher_menu(treeview1_ab);
}


void
on_button15_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_ab;
GtkWidget *Afficher_ab;
Afficher_ab=lookup_widget(button,"Afficher_ab");
gtk_widget_destroy(Afficher_ab);
Acceuil_ab=lookup_widget(button,"Acceuil_ab");
Acceuil_ab=create_Acceuil_ab();
gtk_widget_show(Acceuil_ab);
}


void
on_checkbutton1_semaine1_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
x[0]="1";
}


void
on_checkbutton2_semaine2_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
x[1]="2";
}


void
on_checkbutton4_semaine4_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
x[3]="4";
}


void
on_checkbutton3_semaine3_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
x[2]="3";
}


void
on_button14_rechercher_ab_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *c;
GtkWidget *Recherche_ab,*w1;
GtkWidget *treeview5_ab;
char ce[20];
char xe1[20];
char xe2[20];
char xe3[20];
strcpy(xe1,x1);
strcpy(xe2,x2);
strcpy(xe3,x3);
c = lookup_widget (button, "entry1_ab");
Recherche_ab=lookup_widget(button,"button14_rechercher_ab");
Recherche_ab=create_Recherche_ab();
gtk_widget_show(Recherche_ab);
strcpy(ce , gtk_entry_get_text(GTK_ENTRY(c)));

treeview5_ab=lookup_widget(Recherche_ab,"treeview5_ab");

rechercher_menu(treeview5_ab,xe1,xe2,xe3,ce);
}


void
on_button16_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *Afficher_ab;
GtkWidget *treeview1_ab;
Afficher_ab=lookup_widget(button,"Afficher_ab");
gtk_widget_destroy(Afficher_ab);
Gestion_ab=lookup_widget(button,"Gestion_ab");
Gestion_ab=create_Gestion_ab();
gtk_widget_show(Gestion_ab);
treeview1_ab=lookup_widget(Gestion_ab,"treeview1_ab");
afficher_menu(treeview1_ab);
}


void
on_checkbutton1_petitdej_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
p=1;
}


void
on_checkbutton2_dejeuner_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
p=2;
}


void
on_checkbutton3_diner_ab_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_CHECK_BUTTON (togglebutton)))
p=3;
}


void
on_button18_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_ab;
GtkWidget *Supprimer_ab;
Supprimer_ab=lookup_widget(button,"Supprimer_ab");
gtk_widget_destroy(Supprimer_ab);
Acceuil_ab=lookup_widget(button,"Acceuil_ab");
Acceuil_ab=create_Acceuil_ab();
gtk_widget_show(Acceuil_ab);
}


void
on_button17_supprimer_ab_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *combobox;
Menus R;

combobox = lookup_widget (button, "comboboxentry3_ab");
 

if (strcmp("Lundi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=1;
if (strcmp("Mardi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=2;
if (strcmp("Mercredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=3;
if (strcmp("Jeudi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=4;
if (strcmp("Vendredi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=5;
if (strcmp("Samedi",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=6;
if (strcmp("Dimanche",gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)))==0)
R.jours=7;
R.type=p;
supprimer_ab(R);

}


void
on_button19_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *Supprimer_ab;
GtkWidget *treeview1_ab;
Supprimer_ab=lookup_widget(button,"Supprimer_ab");
gtk_widget_destroy(Supprimer_ab);
Gestion_ab=lookup_widget(button,"Gestion_ab");
Gestion_ab=create_Gestion_ab();
gtk_widget_show(Gestion_ab);
treeview1_ab=lookup_widget(Gestion_ab,"treeview1_ab");
afficher_menu(treeview1_ab);
}


void
on_button21_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Acceuil_ab;
GtkWidget *Meilleur_ab;
Meilleur_ab=lookup_widget(button,"Meilleur_ab");
gtk_widget_destroy(Meilleur_ab);
Acceuil_ab=lookup_widget(button,"Acceuil_ab");
Acceuil_ab=create_Acceuil_ab();
gtk_widget_show(Acceuil_ab);
}


void
on_button20_meilleur_ab_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Meilleur2_ab,*w1,*spinbutton1_ab;
GtkWidget *treeview4_ab;

int c;

Meilleur2_ab=lookup_widget(button,"Meilleur2_ab");
Meilleur2_ab=create_Meilleur2_ab();
gtk_widget_show(Meilleur2_ab);
spinbutton1_ab=lookup_widget(button,"spinbutton1_ab");
c=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton1_ab));
treeview4_ab=lookup_widget(Meilleur2_ab,"treeview4_ab");

afficher_Dash(treeview4_ab,c);
}


void
on_button22_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *Meilleur_ab;
GtkWidget *treeview1_ab;
Meilleur_ab=lookup_widget(button,"Meilleur_ab");
gtk_widget_destroy(Meilleur_ab);
Gestion_ab=lookup_widget(button,"Gestion_ab");
Gestion_ab=create_Gestion_ab();
gtk_widget_show(Gestion_ab);
treeview1_ab=lookup_widget(Gestion_ab,"treeview1_ab");
afficher_menu(treeview1_ab);
}


void
on_button23_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestion_ab;
GtkWidget *Recherche_ab;
GtkWidget *treeview1_ab;
Recherche_ab=lookup_widget(button,"Recherche_ab");
gtk_widget_destroy(Recherche_ab);
Gestion_ab=lookup_widget(button,"Gestion_ab");
Gestion_ab=create_Gestion_ab();
gtk_widget_show(Gestion_ab);
treeview1_ab=lookup_widget(Gestion_ab,"treeview1_ab");
afficher_menu(treeview1_ab);
}


void
on_radiobutton4_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=1;
}


void
on_radiobutton5_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=2;
}


void
on_radiobutton6_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
p=3;
}

/////////////////////////////// MERIEM //////////////////////////////////////////////////


void
on_button1_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_ajout,*fenetre_home;

	fenetre_home = create_Home_ME();
	fenetre_ajout = lookup_widget(objet, "AJOUTER");
	fenetre_home = lookup_widget(objet, "Home_ME");
	fenetre_ajout = create_AJOUTER();
	gtk_widget_show(fenetre_ajout);
	gtk_widget_destroy(fenetre_home);
	
}
/////////////////////////////////////////////////////////

void
on_button2_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_modifier,*fenetre_home;
	fenetre_home = create_Home_ME();
	fenetre_home = lookup_widget(objet, "Home_ME");
	fenetre_modifier = lookup_widget(objet, "MODIFIER");
	fenetre_modifier = create_MODIFIER();
	gtk_widget_show(fenetre_modifier);
	gtk_widget_destroy(fenetre_home);
}
/////////////////////////////////////////////////////////

void
on_button3_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_supprimer,*fenetre_home;
	fenetre_home = create_Home_ME();
	fenetre_supprimer = lookup_widget(objet, "SUPPRIMER");
	fenetre_home = lookup_widget(objet, "Home_ME");
	fenetre_supprimer = create_SUPPRIMER();
	gtk_widget_show(fenetre_supprimer);
	gtk_widget_destroy(fenetre_home);
}
/////////////////////////////////////////////////////////?????


void
on_button7_AJ_home_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_home,*fenetre_ajouter;
	GtkWidget *treeview1;
	
	fenetre_home = create_Home_ME();
	gtk_widget_show(fenetre_home);
	
	treeview1=lookup_widget(fenetre_home,"treeview1_ME");
	afficher_stock_tv(treeview1);	
	fenetre_ajouter = lookup_widget(objet, "AJOUTER");
	gtk_widget_hide(fenetre_ajouter);
}


void
on_button8_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *entryref, *entryfour, *entryprix ,*labelsuccess, *quant , *entrydate;
	GtkWidget *combobox1;
	
	char chaine[50];
	
        stk c;
	entryref = lookup_widget(objet, "entry3_reference");
	strcpy(c.ref, gtk_entry_get_text(GTK_ENTRY(entryref)));

	combobox1 = lookup_widget(objet, "combobox1_categorie");
	if (strcmp("Boissons", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))) == 0){
		strcpy(chaine , "Boissons");
	}
	else if (strcmp("Fruits", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))) == 0) {
		strcpy(chaine , "Fruits");
	}
	else if (strcmp("Legumes", gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1))) == 0){
		strcpy(chaine ,"Legumes");
	}
	strcpy(c.categorie, chaine);

	quant = lookup_widget(objet, "spinbutton3");
	c.quantite =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(objet,"spinbutton3")));

	entrydate = lookup_widget(objet, "entry2_date");
	strcpy(c.date ,gtk_entry_get_text(GTK_ENTRY(entrydate)));


	entryfour = lookup_widget(objet, "entry4_fournisseur");
	strcpy(c.fournisseur ,gtk_entry_get_text(GTK_ENTRY(entryfour)));

	entryprix = lookup_widget(objet, "entry5_prix");
	strcpy(c.prix ,gtk_entry_get_text(GTK_ENTRY(entryprix)));

        

	labelsuccess=lookup_widget(objet,"msg_succes");


	ajouter_stock(c);
		gtk_widget_show (labelsuccess);

	
}

////////////////////////////////////////////////////////////////
void
on_button9_MOD_home_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_home,*fenetre_modifier;
	GtkWidget *treeview2;
	
	
	fenetre_home = lookup_widget(objet, "Home_ME");
	fenetre_home = create_Home_ME();
	gtk_widget_show(fenetre_home);
	treeview2=lookup_widget(fenetre_home,"treeview1_ME");
	afficher_stock_tv(treeview2);
	fenetre_modifier = lookup_widget(objet, "MODIFIER");
	gtk_widget_hide(fenetre_modifier);
}


void
on_button10_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *entry_ref, *entryfour, *entryprix, *lab, *entrydate;
	GtkWidget *cal;
	GtkWidget *SB;
	char chaine[50],chaine2[50];
	int jj,mm,aa;
	stk new;
	
	entry_ref = lookup_widget(objet, "entry6_reference");
	strcpy(new.ref, gtk_entry_get_text(GTK_ENTRY(entry_ref)));
	
	if (recherche_stock(new.ref)==0)
		{lab=lookup_widget(objet,"label_msg_erreur");
		gtk_label_set_text(GTK_LABEL(lab), "cette reference n'existe pas");}
	else {
	if (pme==1) {strcpy (chaine, "Boissons");  }
	else if(pme==2) {strcpy (chaine, "Fruits"); }
	else if(pme==3){strcpy (chaine, "Legumes"); }
	strcpy(new.categorie, chaine);	
	SB = lookup_widget(objet,"spinbutton2_ME");
	new.quantite =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(objet,"spinbutton2_ME")));


	entrydate = lookup_widget(objet, "entry1_dateexp");
	strcpy(new.date , gtk_entry_get_text(GTK_ENTRY(entrydate)));


	entryfour = lookup_widget(objet, "entry7_fournisseur");
	strcpy(new.fournisseur , gtk_entry_get_text(GTK_ENTRY(entryfour)));
	

	entryprix = lookup_widget(objet, "entry8_prix");
	strcpy(new.prix , gtk_entry_get_text(GTK_ENTRY(entryprix)));
	
	
	modifier_stock(new);
	
	}
}


void
on_button12_supprimer_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *E;
	stk s;
	E=lookup_widget (objet,"entry9_reference");
	strcpy(s.ref, gtk_entry_get_text(GTK_ENTRY(E)));
	supprimer_stock(s.ref);
}


void
on_button13_SUPP_home_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_home,*fenetre_supprimer;
	GtkWidget *treeview3;
	
	fenetre_home = lookup_widget(objet, "Home_ME");
	fenetre_home = create_Home_ME();
	gtk_widget_show(fenetre_home);
	treeview3=lookup_widget(fenetre_home,"treeview1_ME");
	afficher_stock_tv(treeview3);
	fenetre_supprimer = lookup_widget(objet, "SUPPRIMER");
	gtk_widget_hide(fenetre_supprimer);
}


void
on_button6_rupstock_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{

}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		pme=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		pme=2;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
		pme=3;
}


void
on_button14_RUPST_Khome_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_home,*fenetre,*treeview6;
	
	fenetre = lookup_widget(objet, "rupture_stock");
	gtk_widget_hide(fenetre);
	fenetre_home = lookup_widget(objet, "Home_ME");
	fenetre_home = create_Home_ME();
	gtk_widget_show(fenetre_home);
	treeview6=lookup_widget(fenetre_home,"treeview1_ME");
	afficher_stock_tv(treeview6);
}


void
on_button3_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_affiche,*fenetre_home;
	GtkWidget *treeview;

	fenetre_affiche = lookup_widget(button, "AFFICHER");
	fenetre_home = lookup_widget(button, "Home_ME");
	fenetre_affiche = create_AFFICHER();
	gtk_widget_show(fenetre_affiche);
	treeview=lookup_widget(fenetre_affiche,"treeview5_ME");
	afficher_stock_tv(treeview);
	gtk_widget_destroy(fenetre_home);
}


void
on_button1_gestion_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_home;
	GtkWidget *treeview1;
	GtkWidget *fenetre_acceuil;
	fenetre_acceuil = lookup_widget(button, "Acceuil");
	fenetre_home = lookup_widget(button, "Home_ME");
	fenetre_home = create_Home_ME();
	gtk_widget_show(fenetre_home);
	treeview1=lookup_widget(fenetre_home,"treeview1_ME");
	afficher_stock_tv(treeview1);
	gtk_widget_destroy(fenetre_acceuil);
}



void
on_button4_home_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_home;
	GtkWidget *fenetre_affiche;
	GtkWidget *treeview4;
	
	fenetre_home = lookup_widget(objet, "Home_ME");
	fenetre_affiche = lookup_widget(objet, "AFFICHER");
	gtk_widget_destroy(fenetre_affiche);
	fenetre_home = create_Home_ME();
	gtk_widget_show(fenetre_home);
	treeview4=lookup_widget(fenetre_home,"treeview1_ME");
	afficher_stock_tv(treeview4);

}


void
on_button2_rupture_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *rupture;
	GtkWidget *treeview2;
	GtkWidget *fenetre_acceuil;
	stk c;

	fenetre_acceuil = lookup_widget(objet, "Acceuil");
	rupture = lookup_widget(objet, "rupture_stock");
	rupture = create_rupture_stock();
	gtk_widget_show(rupture);

	rupture_stock(c);

	treeview2=lookup_widget(rupture,"treeview2_ME");
	afficher_rupt_stock_tv(treeview2);
	gtk_widget_destroy(fenetre_acceuil);


}


void
on_button12_retourME_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_acceuil;
	GtkWidget *fenetre_home;

	fenetre_acceuil = lookup_widget(button, "Acceuil");
	fenetre_home = lookup_widget(button, "Home_ME");
	fenetre_acceuil = create_Acceuil();
	gtk_widget_show(fenetre_acceuil);
	gtk_widget_destroy(fenetre_home);
}

void
on_button122_retourME_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *fenetre_acceuil;
	GtkWidget *fenetre_rupture_stock;

	fenetre_acceuil = lookup_widget(button, "Acceuil");
	fenetre_rupture_stock = lookup_widget(button, "rupture_stock");
	fenetre_acceuil = create_Acceuil();
	gtk_widget_show(fenetre_acceuil);
	gtk_widget_destroy(fenetre_rupture_stock);
}

/////////////////////////////// BAKARY //////////////////////////////////////////////////


void
on_Valider_auth_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principale_bt, *Authentification_bt;
Authentification_bt=lookup_widget(objet,"Authentification_bt");
gtk_widget_destroy(Authentification_bt);
principale_bt=lookup_widget(objet,"principale_bt");
principale_bt=create_principale_bt();
gtk_widget_show (principale_bt);
}


void
on_treeview_bt_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* nom;
gchar* prenom;
gchar* identifiant;
gchar* classe;
gchar* chambre;
gchar* sexe;
gchar* date;
Etudiant E;

GtkTreeModel *model = gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model,&iter,path));
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&identifiant,3,&classe,4,&chambre,5,&sexe,6,&date,-1);
strcpy(E.nom,nom);
strcpy(E.prenom,prenom);
strcpy(E.identifiant,identifiant);
strcpy(E.classe,classe);
strcpy(E.chambre,chambre);
strcpy(E.sexe,sexe);
strcpy(E.date.jour,date);
strcpy(E.date.mois,date);
strcpy(E.date.annee,date);
supprimer(identifiant);

afficher_etudiant(treeview);
}

}


void
on_button_recherche_bt_clicked            (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *principale_bt, *Recherche_bt;
principale_bt=lookup_widget(objet,"principale_bt");
gtk_widget_destroy(principale_bt);
Recherche_bt=lookup_widget(objet,"Recherche_bt");
Recherche_bt=create_Recherche_bt();
gtk_widget_show (Recherche_bt);
}


void
on_button_calcul_bt_clicked               (GtkWidget      *objet,
                                        gpointer         user_data)
{
GtkWidget *principale_bt, *Calcul_bt;
principale_bt=lookup_widget(objet,"principale_bt");
gtk_widget_destroy(principale_bt);
Calcul_bt=lookup_widget(objet,"Calcul_bt");
Calcul_bt=create_Calcul_bt();
gtk_widget_show (Calcul_bt);
}


void
on_button_Affichage_bt_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview_bt,*principale_bt;
principale_bt=lookup_widget(button,"principale_bt");
treeview_bt=lookup_widget(button,"treeview_bt");
principale_bt = create_principale_bt();
gtk_widget_show (principale_bt);
gtk_widget_destroy(principale_bt);
afficher_etudiant(treeview_bt);
}

void
on_button_modification_bt_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principale_bt, *Modification_bt;
principale_bt=lookup_widget(objet,"principale_bt");
gtk_widget_destroy(principale_bt);
Modification_bt=lookup_widget(objet,"Modification_bt");
Modification_bt=create_Modification_bt();
gtk_widget_show (Modification_bt);
}


void
on_button_Ajout_bt_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principale_bt, *Ajout_bt;
principale_bt=lookup_widget(objet,"principale_bt");
gtk_widget_destroy(principale_bt);
Ajout_bt=lookup_widget(objet,"Ajout_bt");
Ajout_bt=create_Ajout_bt();
gtk_widget_show (Ajout_bt);
}


void
on_Suppress_bt_clicked                    (GtkWidget      *objet,
                                        gpointer         user_data)
{
	char IDENTIFIANT[40];
	GtkWidget *entry_idsuppression;
	entry_idsuppression=lookup_widget(objet,"entry_idsuppression");
	strcpy(IDENTIFIANT,gtk_entry_get_text(GTK_ENTRY(entry_idsuppression)));
	supprimer(IDENTIFIANT);
}



void
on_radiobutton_m_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 Etudiant E;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E.sexe,"M");
}


void
on_radiobutton_f_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
 Etudiant E;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E.sexe,"F");
}

void
on_button_retour_ajout_clicked         (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *Ajout_bt,*principale_bt;
 GtkWidget*treeview_bt;

Ajout_bt=lookup_widget(objet,"Ajout_bt");
gtk_widget_destroy(Ajout_bt);

principale_bt = create_principale_bt ();
gtk_widget_show (principale_bt);


treeview_bt=lookup_widget(principale_bt,"treeview_bt");

afficher_etudiant(treeview_bt);
}

void
on_button_ajouter_bt_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
Etudiant E;
DATE date;
GtkWidget *input1,*input2,*input3,*input4,*input5,*jour,*mois,*annee,*input6,*input7;
GtkWidget *Ajout_bt;GtkWidget *output;
char text1[100]="Etudiant ajouté";
char text2[40]="Identifiant Incorrecte";
char text3[40]=" Champ Vide!";

Ajout_bt=lookup_widget(objet, "Ajout_bt");

input1 = lookup_widget(objet, "entry_nomajout") ;
input2= lookup_widget(objet, "entry_prenomajout") ;
input3= lookup_widget(objet, "entry_chambreajout");
input4=lookup_widget(objet, "entry_id");
input5= lookup_widget(objet, "combobox_classe");
input6=	lookup_widget(objet, "radiobutton_f");
input7=	lookup_widget(objet, "radiobutton_m");
jour=lookup_widget(objet, "spinbutton_ajout");
mois=lookup_widget(objet, "spinbutton_mois");
annee= lookup_widget(objet, "spinbutton_annee");

strcpy(E.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(E.identifiant,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(E.chambre,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(E.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input6)))
strcpy(E.sexe,"F");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input7)))
strcpy(E.sexe,"M");
 
E.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
E.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
E.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
output=lookup_widget(objet,"labelajout");
if (strlen(E.identifiant)==10 && strlen(E.nom)!=0 && strlen(E.prenom)!=0 && strlen(E.chambre)!=0 && strlen(E.classe)!=0 && strlen(E.sexe)!=0){
ajouter_edudiant(E);
gtk_label_set_text(GTK_LABEL(output),text1);}
else if (strlen(E.identifiant)!=10){
gtk_label_set_text(GTK_LABEL(output),text2);}
else if (strlen(E.nom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.prenom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.chambre)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.classe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E.sexe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);


}


void
on_radiobutton_mm_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
Etudiant E1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E1.sexe,"M");
}


void
on_radiobuttonfm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
Etudiant E1;
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) strcpy(E1.sexe,"F");
}


void
on_button_modif_bt_clicked                (GtkWidget      *objet,
                                        gpointer         user_data)
{

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*jour,*mois,*annee;
GtkWidget *Modification_bt,*output;
Etudiant E1;char text2[100]="Identifiant Incorrecte";char text1[100]="Modifié avec succès";char text3[100]="champ vide !";
DATE date;
Modification_bt=lookup_widget(objet,"Modification_bt");

input1 = lookup_widget(objet, "entrynomodif") ;
input2= lookup_widget(objet, "entryprenmodif") ;
input3= lookup_widget(objet, "entry_chambremodif");
input4=lookup_widget(objet, "entry_idmodif");
input5= lookup_widget(objet, "combobox_classemodif");
input6=	lookup_widget(objet, "radiobuttonfm");
input7=	lookup_widget(objet, "radiobutton_mm");
jour=lookup_widget(objet, "spinbuttonj");
mois=lookup_widget(objet, "spinbuttonm");
annee= lookup_widget(objet, "spinbuttona");

strcpy(E1.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(E1.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(E1.identifiant,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(E1.chambre,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(E1.classe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input5)));
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input6)))
strcpy(E1.sexe,"F");
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(input7)))
strcpy(E1.sexe,"M");
 
E1.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
E1.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
E1.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
output=lookup_widget(objet,"labelmodif");
if(strlen(E1.identifiant)==10 && strlen(E1.nom)!=0 && strlen(E1.prenom)!=0 && strlen(E1.chambre)!=0 && strlen(E1.classe)!=0 && strlen(E1.sexe)!=0){
gtk_label_set_text(GTK_LABEL(output),text1);
modifier(E1);
}
else if (strlen(E1.identifiant)!=10){
gtk_label_set_text(GTK_LABEL(output),text2);}
else if (strlen(E1.nom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.prenom)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.chambre)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.classe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);
else if (strlen(E1.sexe)==0)
gtk_label_set_text(GTK_LABEL(output),text3);


}

void
on_button_retourmodif_clicked          (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *principale_bt,*Modification_bt,*treeview;
principale_bt = create_principale_bt ();
gtk_widget_show (principale_bt);
Modification_bt=lookup_widget(button,"Modification_bt");
gtk_widget_destroy(Modification_bt);
}

void
on_checkbutton_d_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[1]=1;
}
else
{calcul[1]=0;}
}


void
on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[2]=1;
}
else
{calcul[2]=0;
}
}


void
on_checkbutton_q_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[3]=1;}
else
{calcul[3]=0;}
}


void
on_checkbutton_c_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[4]=1;}
else
{calcul[4]=0;}

}


void
on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{calcul[0]=1;
}
else
{calcul[0]=0;}
}


void
on_button_retourcalcul_clicked         (GtkWidget      *button,
                                        gpointer         user_data)
{
GtkWidget *principale_bt,*Calcul_bt,*treeview;
principale_bt = create_principale_bt ();
gtk_widget_show (principale_bt);
Calcul_bt=lookup_widget(button,"Calcul_bt");
gtk_widget_destroy(Calcul_bt);
}



void
on_button_calculer_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *somme;
int sum;
somme = lookup_widget(button, "label_calcul_s") ;
sum=niveau(calcul,"etudiant.txt");
sprintf(so,"%d",sum);
gtk_label_set_text(GTK_LABEL(somme),so);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	int x;
	GtkWidget *entry_idrecherche,*output,*principale_bt,*treeview1;
	char IDENTIFIANT[40];char txt[100]="Etudiant trouvé !";char txt2[100]="Etudiant non trouvé !";char txt3[100]="Identifiant incorrecte";
	entry_idrecherche=lookup_widget(button,"entry_idrecherche");
	strcpy(IDENTIFIANT,gtk_entry_get_text(GTK_ENTRY(entry_idrecherche)));
	output=lookup_widget(button,"labeltrouve");
	x=recherche(E,IDENTIFIANT);
	if(x==1 && strlen(IDENTIFIANT)==10){
	gtk_label_set_text(GTK_LABEL(output),txt);}
	else if(strlen(IDENTIFIANT)!=10)
	gtk_label_set_text(GTK_LABEL(output),txt3);
	else
	gtk_label_set_text(GTK_LABEL(output),txt2);
	
}


void
on_button_retourrecherche_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *principale_bt,*Recherche_bt,*treeview;
principale_bt = create_principale_bt ();
gtk_widget_show (principale_bt);
Recherche_bt=lookup_widget(button,"Recherche_bt");
gtk_widget_destroy(Recherche_bt);
}


////////////////////////////////////////////////////////////////////////////////////////////



void
on_checkbuttonvm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
m=1;}
}


void
on_checkbuttonva_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
a=1;}
}



void
on_buttonsupprimerhk_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;
	    GtkWidget *treeviewhk;
	    page_principale=lookup_widget(button,"page_principale");
	    treeviewhk=lookup_widget(page_principale,"treeviewhk");
	
	    suppression(idhk,r);
            affichage(treeviewhk);


}



void
on_buttonajouterhk_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
		GtkWidget *windowskipo;

windowskipo=create_ajout_de_la_reclamation();
gtk_widget_show (windowskipo);
}


void
on_buttonactualiserhk_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewhk;
page_principale=lookup_widget(button,"page_principale");
treeviewhk=lookup_widget(page_principale,"treeviewhk");
affichage(treeviewhk);
}


void
on_buttonmodifierhk_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskipoo;

windowskipoo=create_modification_de_la_reclamation();
gtk_widget_show (windowskipoo);

}


void
on_buttonboardhk_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *windowskipooo;

windowskipooo=create_statistique();
gtk_widget_show (windowskipooo);

}


void
on_buttonrecherchehk_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;
GtkWidget *entryrech;
GtkWidget *treeviewhk;
FILE*f;
FILE*f2;


page_principale=lookup_widget(button,"page_principale");
entryrech=lookup_widget(button,"entryrech");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(entryrech)));
f=fopen("reclamation.bin","rb");

 if(f!=NULL)
 {
  while(fread(&r,sizeof(RECLAMATION),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (strcmp(r.identifiant,idrech)==0)
     { 
     fwrite(&r,sizeof(RECLAMATION),1,f2);
     }
   
     treeviewhk=lookup_widget(page_principale,"treeviewhk");
     recherchehk(treeviewhk);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");

}


void
on_buttonajouthk_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;char Type[30];
char x[30];
char d[30];
char o[30];
char ll[30];
int lll;
GtkWidget *comboboxajout;
GtkWidget *entryid;
GtkWidget *entryprob;

GtkWidget *spinbuttonjj;
GtkWidget *spinbuttonmm;
GtkWidget *spinbuttonaa;

GtkWidget *spinbuttonjour;
GtkWidget *spinbuttonmois;
GtkWidget *spinbuttonanne;

GtkWidget *entry1;
GtkWidget *entry2;
GtkWidget *label49;

 

spinbuttonjour=lookup_widget(button, "spinbuttonjour");
spinbuttonmois=lookup_widget(button, "spinbuttonmois");
spinbuttonanne=lookup_widget(button, "spinbuttonanne");
spinbuttonjj=lookup_widget(button, "spinbuttonjj");
spinbuttonmm=lookup_widget(button, "spinbuttonmm");
spinbuttonaa=lookup_widget(button, "spinbuttonaa");

comboboxajout=lookup_widget(button, "comboboxajout");
entryid=lookup_widget(button,"entryid");
entryprob=lookup_widget(button,"entryprob");
entry1=lookup_widget(button,"entry1");
entry2=lookup_widget(button,"entry2");
label49=lookup_widget(button, "label49");

strcpy(ll,gtk_entry_get_text(GTK_ENTRY(entry2)));
lll=strlen(ll);
strcpy(d,gtk_entry_get_text(GTK_ENTRY(entryprob)));
strcpy(x,gtk_entry_get_text(GTK_ENTRY(entryid)));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajout)));
strcpy(o,Type);

if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(label49),"il faut ajouter une idee!");}

else if (veriff(x)==1){
	if(verifid(x)==0){gtk_label_set_text(GTK_LABEL(label49),"cette idee n est pas valable!");}
        else if (veriff(o)==0){gtk_label_set_text(GTK_LABEL(label49),"il faut mentionner le service a reclamer!");}
        else if (lll!=8){gtk_label_set_text(GTK_LABEL(label49),"il faut entrer une vrai carte d identite !");}
        else if (veriff(d)==0){gtk_label_set_text(GTK_LABEL(label49),"il faut mentionner le probleme!");}
        else if (a==0){gtk_label_set_text(GTK_LABEL(label49),"il faut valider le check button!");}
	else {
strcpy(r.identifiant,gtk_entry_get_text(GTK_ENTRY(entryid)));
strcpy(r.problem,gtk_entry_get_text(GTK_ENTRY(entryprob)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(entry2)));

r.dater.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonjour));
r.dater.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmois));
r.dater.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonanne));
r.datea.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonjj));
r.datea.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmm));
r.datea.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonaa));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajout)));
strcpy(r.type,Type);

ajout(r);
gtk_label_set_text(GTK_LABEL(label49),"Ajout effectué avec succès!");}}
a=0;}


void
on_buttonmodifhk_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
RECLAMATION r;char Type[30];

char d[30];
char o[30];
char ll[30];
int lll;
GtkWidget *comboboxmodif;
GtkWidget *entrymodifid;
GtkWidget *entrymodifprob;
GtkWidget *spinbuttonmodifjj;
GtkWidget *spinbuttonmodifmm;
GtkWidget *spinbuttonmodifaa;

GtkWidget *spinbuttonmodifjour;
GtkWidget *spinbuttonmodifmois;
GtkWidget *spinbuttonmodifanne;
GtkWidget *entry3;
GtkWidget *entry4;
GtkWidget *label53;


    
	
spinbuttonmodifjour=lookup_widget(button, "spinbuttonmodifjour");
spinbuttonmodifmois=lookup_widget(button, "spinbuttonmodifmois");
spinbuttonmodifanne=lookup_widget(button, "spinbuttonmodifanne");
spinbuttonmodifjj=lookup_widget(button, "spinbuttonmodifjj");
spinbuttonmodifmm=lookup_widget(button, "spinbuttonmodifmm");
spinbuttonmodifaa=lookup_widget(button, "spinbuttonmodifaa");
comboboxmodif=lookup_widget(button, "comboboxmodif");
label53=lookup_widget(button, "label53");
entrymodifprob=lookup_widget(button,"entrymodifprob");
entry3=lookup_widget(button,"entry3");
entry4=lookup_widget(button,"entry4");
strcpy(ll,gtk_entry_get_text(GTK_ENTRY(entry4)));
lll=strlen(ll);
strcpy(d,gtk_entry_get_text(GTK_ENTRY(entrymodifprob)));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodif)));
strcpy(o,Type);


	
         if (veriff(o)==0){gtk_label_set_text(GTK_LABEL(label53),"il faut mentionner le service a reclamer!");}
        else if (lll!=8){gtk_label_set_text(GTK_LABEL(label53),"il faut entrer une vrai carte d identite !");}
        else if (veriff(d)==0){gtk_label_set_text(GTK_LABEL(label53),"il faut mentionner le probleme!");}
 	else if (m==0){gtk_label_set_text(GTK_LABEL(label53),"il faut valider le check button!");}      
else{
strcpy(r.identifiant,idhk);
strcpy(r.problem,gtk_entry_get_text(GTK_ENTRY(entrymodifprob)));
strcpy(r.nom,gtk_entry_get_text(GTK_ENTRY(entry3)));
strcpy(r.cin,gtk_entry_get_text(GTK_ENTRY(entry4)));
r.dater.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjour));
r.dater.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmois));
r.dater.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifanne));
r.datea.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjj));
r.datea.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmm));
r.datea.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifaa));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodif)));
strcpy(r.type,Type);


modification(idhk,r);
gtk_label_set_text(GTK_LABEL(label53),"modification effectué avec succès!");}
m=0;

}


void
on_buttonafficherhk_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
char chr[30];char chh[30];
int k,h;
RECLAMATION r;
GtkWidget *labelrest;
GtkWidget *labelheb;
GtkWidget *labelstat;
k=nombrer(r);
h=nombreh(r);
labelrest=lookup_widget(button,"labelrest");
labelheb=lookup_widget(button,"labelheb");
labelstat=lookup_widget(button,"labelstat");
sprintf(chr,"%d",k);
sprintf(chh,"%d",h);
gtk_label_set_text(labelrest,chr);
gtk_label_set_text(labelheb,chh);
if (k>h)
{gtk_label_set_text(labelstat,"service Restauration");}
else 
{gtk_label_set_text(labelstat,"service Hébergement");}

}


void
on_treeviewhk_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(treeview);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(idhk,identifiant);}
}



////////////////////////////////////////////// AHMED ////////////////////////////////////////////

void
on_buttonAjout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
capt c;
GtkWidget * c_ref;
GtkWidget * c_val;
GtkWidget * c_type;
GtkWidget * c_etage;
GtkWidget * c_jour;
GtkWidget * c_heure;
GtkWidget *labelType;
GtkWidget *labelRef;
GtkWidget *labelEtage;
GtkWidget *labelValeur;
GtkWidget *labelJour;
GtkWidget *labelHeure;
GtkWidget *existe;
GtkWidget *success;
int b=1;

c_ref=lookup_widget(button, "entryRef");
c_val=lookup_widget(button, "entryVal");
c_type=lookup_widget(button, "comboboxTypeCapt");
c_etage=lookup_widget(button, "entryetage");
c_jour=lookup_widget(button, "entryjour");
c_heure=lookup_widget(button, "entryheure");

labelRef=lookup_widget(button,"label36");
labelValeur=lookup_widget(button,"label37");
labelType=lookup_widget(button,"label38");
labelEtage=lookup_widget(button,"label39");
labelJour=lookup_widget(button,"label40");
labelHeure=lookup_widget(button,"label41");
existe=lookup_widget(button,"label34");
success=lookup_widget(button,"label35");

strcpy(c.reference,gtk_entry_get_text(GTK_ENTRY(c_ref)));
strcpy(c.etage,gtk_entry_get_text(GTK_ENTRY(c_etage)));
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(c_type)));
strcpy(c.valeur,gtk_entry_get_text(GTK_ENTRY(c_val)));
strcpy(c.jour,gtk_entry_get_text(GTK_ENTRY(c_jour)));
strcpy(c.heure,gtk_entry_get_text(GTK_ENTRY(c_heure)));

 gtk_widget_hide (success);

if(strcmp(c.type,"")==0){
		  gtk_widget_show (labelType);
b=0;
}
else {
		  gtk_widget_hide(labelType);
}

if(strcmp(c.reference,"")==0){
		  gtk_widget_show (labelRef);
b=0;
}
else {
		  gtk_widget_hide(labelRef);
}
if(strcmp(c.etage,"")==0){
		  gtk_widget_show (labelEtage);
b=0;
}
else {
		  gtk_widget_hide(labelEtage);
}
if(strcmp(c.valeur,"")==0){
		  gtk_widget_show (labelValeur);
b=0;
}
else {
		  gtk_widget_hide(labelValeur);
}
if(strcmp(c.jour,"")==0){
		  gtk_widget_show (labelJour);
b=0;
}
else {
		  gtk_widget_hide(labelJour);
}
if(strcmp(c.heure,"")==0){
		  gtk_widget_show (labelHeure);
b=0;
}
else {
		  gtk_widget_hide(labelHeure);
}


if(b==1){

       if(exist_capteur(c.reference)==1)
        {
	gtk_widget_show (existe);
        }
        else
	{
	gtk_widget_hide (existe);
	ajoutercapteur(c);
	gtk_widget_show (success);
        }
}
}


void
on_buttonhomeajouter_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * home;
home = create_menuPrinahmed ();
gtk_widget_show (home);
GtkWidget *captHome;
captHome = lookup_widget(button, "ajtCapt");
gtk_widget_destroy(captHome);
}


void
on_gestCapt_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *menu;
	GtkWidget *gerer;
	int i;

	menu=lookup_widget(button,"menuPrinahmed");
	gtk_widget_destroy(menu);
	gerer=lookup_widget(button,"gestCapt");
	gerer = create_gestCapt ();

	gtk_widget_show(gerer);
}


void
on_captDefect_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	capt c;	
	GtkWidget * Cap_def;
	GtkWidget * treeview4;
	Cap_def=lookup_widget(button,"captDefect");
	Cap_def=create_captDefect();
	gtk_widget_show(Cap_def);
	Capteurs_Defect(c);
	treeview4=lookup_widget(Cap_def,"treeview6");
	thetreeview(treeview4,"capteur2.txt");
GtkWidget *menuPrinahmed;
menuPrinahmed = lookup_widget(button, "menuPrinahmed");
gtk_widget_destroy(menuPrinahmed);
}


void
on_alarmes_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	capt c;
	GtkWidget * Listealarmes;
	GtkWidget * treeview;
	Listealarmes=lookup_widget(button,"alarmes");
	Listealarmes=create_listeAlarmes();
	gtk_widget_show(Listealarmes);
	Liste_Alarmes(c);
	treeview=lookup_widget(Listealarmes,"treeview2");
	thetreeview(treeview,"capteur1.txt");
GtkWidget *menuPrinahmed;
menuPrinahmed = lookup_widget(button, "menuPrinahmed");
gtk_widget_destroy(menuPrinahmed);
}



void
on_quit_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * home;
	home = create_menuPrinahmed ();
    gtk_widget_show (home);
    GtkWidget *captHome;
    captHome = lookup_widget(button, "gestCapt");
    gtk_widget_destroy(captHome);
}


void
on_homelistealarm_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * home;
	home = create_menuPrinahmed ();
	gtk_widget_show (home);
	GtkWidget *captHome;
	captHome = lookup_widget(button, "listeAlarmes");
	gtk_widget_destroy(captHome);
}


void
on_buttonhomeDEFECT_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * home;
	home = create_menuPrinahmed ();
	gtk_widget_show (home);
	GtkWidget *captHome;
	captHome = lookup_widget(button, "captDefect");
	gtk_widget_destroy(captHome);
}


void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	capt p;
	GtkWidget *reference,*type,*etage,*valeur,*jour, *heure, *annee, *fonction,*jour1, *mois1, *annee1 ;
	char ver[30];
	GtkWidget *labelType;
	GtkWidget *labelRef;
	GtkWidget *labelEtage;
	GtkWidget *labelValeur;
	GtkWidget *labelJour;
	GtkWidget *labelHeure;
	GtkWidget *existe;
	GtkWidget *success;
	int b=1;

	reference=lookup_widget(button,"refm");
	type=lookup_widget(button,"comboboxm");
	etage=lookup_widget(button,"etagem");
	valeur=lookup_widget(button, "valm");
	jour=lookup_widget(button, "jourm");
	heure=lookup_widget(button, "heurem");

	labelRef=lookup_widget(button,"label66");
	labelValeur=lookup_widget(button,"label67");
	labelType=lookup_widget(button,"label68");
	labelEtage=lookup_widget(button,"label69");
	labelJour=lookup_widget(button,"label70");
	labelHeure=lookup_widget(button,"label71");
//////////////////////////////////
	existe=lookup_widget(button,"label73");
	success=lookup_widget(button,"label72");
////////////////////////////////////	
	strcpy(ver,gtk_entry_get_text(GTK_ENTRY(reference)));
	
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
	strcpy(p.etage,gtk_entry_get_text(GTK_ENTRY(etage)));
	strcpy(p.valeur,gtk_entry_get_text(GTK_ENTRY(valeur)));
	strcpy(p.jour,gtk_entry_get_text(GTK_ENTRY(jour)));
	strcpy(p.heure,gtk_entry_get_text(GTK_ENTRY(heure)));

	strcpy(p.reference,gtk_entry_get_text(GTK_ENTRY(reference)));
gtk_widget_hide (success);
	
// controle saisie
if(strcmp(p.type,"")==0){
		  gtk_widget_show (labelType);
b=0;
}
else {
		  gtk_widget_hide(labelType);
}

if(strcmp(p.reference,"")==0){
		  gtk_widget_show (labelRef);
b=0;
}
else {
		  gtk_widget_hide(labelRef);
}
if(strcmp(p.etage,"")==0){
		  gtk_widget_show (labelEtage);
b=0;
}
else {
		  gtk_widget_hide(labelEtage);
}
if(strcmp(p.valeur,"")==0){
		  gtk_widget_show (labelValeur);
b=0;
}
else {
		  gtk_widget_hide(labelValeur);
}
if(strcmp(p.jour,"")==0){
		  gtk_widget_show (labelJour);
b=0;
}
else {
		  gtk_widget_hide(labelJour);
}
if(strcmp(p.heure,"")==0){
		  gtk_widget_show (labelHeure);
b=0;
}
else {
		  gtk_widget_hide(labelHeure);
}


if(b==1){  
	if(exist_capteur(p.reference)==1)
        {
	modifiercapteur(p,ver);
	gtk_widget_show (success);
	gtk_widget_hide (existe);
        }
        else
	{
	gtk_widget_hide (success);
	gtk_widget_show (existe);
        }
        }
}


void
on_validermodification_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonhomemodifier_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * home;
	 
   	home = create_menuPrinahmed ();
    gtk_widget_show (home);
    GtkWidget *captHome;
    captHome = lookup_widget(button, "modfCapt");
    gtk_widget_destroy(captHome);
}


void
on_buttonhomeconsult_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * home;
	home = create_menuPrinahmed ();
    gtk_widget_show (home);
    GtkWidget *captHome;
    captHome = lookup_widget(button, "gestCapt");
    gtk_widget_destroy(captHome);

}


void
on_buttonquitterconsult_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

    GtkWidget *captHome;
    captHome = lookup_widget(button, "gestCapt");
    gtk_widget_destroy(captHome);
}


void
on_buttonajouterconsult_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * ajout;
	 
   	ajout = create_ajtCapt ();
    gtk_widget_show (ajout);
    GtkWidget *captHome;
    captHome = lookup_widget(button, "gestCapt");
    gtk_widget_destroy(captHome);
}


void
on_buttonmodifierconsult_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * modf;
	 
   	modf = create_modfCapt ();
    gtk_widget_show (modf);
    GtkWidget *captHome;
    captHome = lookup_widget(button, "gestCapt");
    gtk_widget_destroy(captHome);
}


void
on_supprimer_afficher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget* treeview;
	GtkWidget* afficher;
	GtkWidget* gerer;
	gerer=lookup_widget(objet,"gestCapt");
	gtk_widget_destroy(gerer);
	afficher=lookup_widget(objet,"affichageahmed");
	afficher=create_affichageahmed();
	gtk_widget_show(afficher);
	treeview=lookup_widget(afficher,"treeviewconsult");
	afficher_capteur(treeview);
	
}


void
on_treeviewconsult_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar *reference;
        gchar *type;
        gchar *etage;
        gchar *valeur;
	gchar *jour;
	gchar *heure;
	capt k;
	
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model, &iter, path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &reference, 1, &type, 2, &etage, 3, &valeur, 4, &jour, 5, &heure, -1);
		strcpy(k.reference,reference);
		strcpy(k.type,type);
		strcpy(k.etage,etage);
		strcpy(k.valeur,valeur);
		strcpy(k.jour,jour);
		strcpy(k.heure,heure);
		
		afficher_capteur(treeview);
}
}


void
on_supprimercapteur_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkTreeModel     *model;
        GtkTreeSelection *selection;
        GtkTreeIter iter;
        GtkWidget* p;
        gchar *reference;
	gchar*type;
gchar*valeur;
gchar*etage ;
gchar*jour;
gchar*heure;//gchar* type gtk ==> chaine en c car la fonction gtk_tree_model_get naccepte que gchar*
     
        p=lookup_widget(button,"treeviewconsult");




        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
         if(gtk_tree_selection_get_selected(selection, &model, &iter))//test sur la ligne selectionnée
         {gtk_tree_model_get (model,&iter,0,&reference,1,&type,2,&etage,3,&valeur,4,&jour,5,&heure,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimercapteur(reference);// supprimer la ligne du fichier
}
}

void
on_HOME_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * home;
		 
	home = create_menuPrinahmed ();
	gtk_widget_show (home);
	GtkWidget *captHome;
	captHome = lookup_widget(button, "affichageahmed");
	gtk_widget_destroy(captHome);
}


void
on_chercher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p1;
GtkWidget *entry;
GtkWidget *labelid;
GtkWidget *nbResultat;
GtkWidget *message;
char id[30];
char chnb[30];
int b=0,nb;
entry=lookup_widget(button,"entry10ah");
labelid=lookup_widget(button,"label47");
p1=lookup_widget(button,"treeviewconsult");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entry)));

if(strcmp(id,"")==0){
  gtk_widget_show (labelid);b=0;
}else{
b=1;
gtk_widget_hide (labelid);}

if(b==0){return;}else{

nb=ChercherCapteur(p1,"Capteur.txt",id);
/* afficher le nombre de resultats obtenue par la recherche */
sprintf(chnb,"%d",nb);//conversion int==> chaine car la fonction gtk_label_set_text naccepte que chaine
nbResultat=lookup_widget(button,"label50ah");
message=lookup_widget(button,"label49");
gtk_label_set_text(GTK_LABEL(nbResultat),chnb);

gtk_widget_show (nbResultat);
gtk_widget_show (message);



}
}

///////////////////////////////// BONUS KAIS ///////////////////////////////////////////

void
on_goto_etage_panne_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *ep_kais;
	GtkWidget *menuPrinahmed;
	GtkWidget *treeviewep_kais;

	etage_panne("debit.txt");
	ep_kais = lookup_widget(objet,"ep_kais");
	menuPrinahmed = lookup_widget(objet,"menuPrinahmed");
	ep_kais = create_ep_kais();
	gtk_widget_show(ep_kais);
	gtk_widget_destroy(menuPrinahmed);
	treeviewep_kais = lookup_widget(ep_kais,"treeviewep_kais");
	afficher_EP(treeviewep_kais,"debit.txt");

}


void
on_button13_ep_kais_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *ep_kais;
	GtkWidget *menuPrinahmed;

	ep_kais = lookup_widget(button,"ep_kais");
	menuPrinahmed = lookup_widget(button,"menuPrinahmed");
	menuPrinahmed = create_menuPrinahmed ();
	gtk_widget_show(menuPrinahmed);
	gtk_widget_destroy(ep_kais);
}


void
on_treeviewep_kais_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter;
	gchar *jour;
	gchar *heure;
	gchar *etage;
	gchar *debit;
	GtkWidget *pInfo;
	ETP ep;
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);

	if(gtk_tree_model_get_iter(model, &iter, path))
	{
	gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&jour,1,&heure,2,&etage,3,&debit,-1);

	strcpy(ep.jour,jour);
	strcpy(ep.heure,heure);
	strcpy(ep.etage,etage);
	strcpy(ep.debit,debit);

	pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,GTK_BUTTONS_YES_NO,"Voulez-vous vraiment\nsupprimer cet utilisateur ?");
	switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
	{
	case GTK_RESPONSE_YES:
	{gtk_widget_destroy(pInfo);
	supprimer_panne(ep,"debit.txt");
	break;}
	case GTK_RESPONSE_NO:
	{gtk_widget_destroy(pInfo);
	break;}
	}
	}
}


void
on_button_resume_ep_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *one;
	GtkWidget *two;
	GtkWidget *three;
	int nb1,nb2,nb3;
	char etage1[10],etage2[10],etage3[10];

	one = lookup_widget(objet,"entryet1");
	two = lookup_widget(objet,"entryet2");
	three = lookup_widget(objet,"entryet3");

	nb1 = nbr_pannes_etage(1,"debit.txt");
	nb2 = nbr_pannes_etage(2,"debit.txt");
	nb3 = nbr_pannes_etage(3,"debit.txt");

	sprintf(etage1,"%d",nb1);
	sprintf(etage2,"%d",nb2);
	sprintf(etage3,"%d",nb3);

	gtk_entry_set_text(GTK_ENTRY(one),etage1);
	gtk_entry_set_text(GTK_ENTRY(two),etage2);
	gtk_entry_set_text(GTK_ENTRY(three),etage3);
}






