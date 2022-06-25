#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include <gtk/gtk.h>

void ajouter_ab(Menus menu)
{   
    FILE *f = NULL;
    f = fopen("Nutritionniste.txt", "a");
    fprintf(f,"%d %d %s %s %s \n", menu.jours, menu.type, menu.entree,menu.plat,menu.dessert);
    fclose(f);
}

void supprimer_ab(Menus R)
{
    Menus menu;
    
    FILE *f1=NULL;
    FILE *f2=NULL;

    f1 = fopen("Nutritionniste.txt","r");
    f2 = fopen("Nutriti_tamp.txt", "a");
    while (fscanf(f1,"%d %d %s %s %s \n", &menu.jours, &menu.type, menu.entree,menu.plat,menu.dessert) !=EOF){
        if (menu.jours != R.jours) {
            fprintf(f2,"%d %d %s %s %s \n", menu.jours, menu.type, menu.entree,menu.plat,menu.dessert);
        }
       else if ((menu.type != R.type) && (menu.jours == R.jours))
     {fprintf(f2,"%d %d %s %s %s \n", menu.jours, menu.type, menu.entree,menu.plat,menu.dessert);}
    }
    fclose(f1);
    fclose(f2);
    remove("Nutritionniste.txt");
    rename("Nutriti_tamp.txt", "Nutritionniste.txt");
}

int rechercher_ab(Menus menu)
{
    Menus M;

    FILE *f = NULL;
    f = fopen("Nutritionniste.txt","r");
    while(fscanf(f,"%d %d %s %s %s \n", &menu.jours, &menu.type, menu.entree,menu.plat,menu.dessert)!=EOF) {

        if(M.jours==menu.jours){
            fclose(f);
            return 1;
        }
    }
    fclose(f);
    return 0;
}

void afficher_ab(Menus menu)
{
    FILE *f = NULL;
    f=fopen("Nutritionniste.txt","r");
    
    while (fscanf(f,"%d %d %s %s %s \n", &menu.jours, &menu.type, menu.entree,menu.plat,menu.dessert) !=EOF){
    printf("%d %d %s %s %s \n", menu.jours, menu.type, menu.entree,menu.plat,menu.dessert);
        
    }
    fclose(f);
}


void modifier_ab(Menus new)
{
    Menus menu;
    FILE *f=NULL;
    FILE *f2=NULL;

    f=fopen("Nutritionniste.txt","r");
    f2=fopen("modif_nut.txt","a");
    while(fscanf(f,"%d %d %s %s %s \n", &menu.jours, &menu.type, menu.entree,menu.plat,menu.dessert)!=EOF)
    {
    if ((menu.jours == new.jours)&&(menu.type == new.type)) {
            fprintf(f2,"%d %d %s %s %s \n", new.jours, new.type, new.entree,new.plat,new.dessert);
        }
        else {
        fprintf(f2,"%d %d %s %s %s \n", menu.jours, menu.type, menu.entree,menu.plat,menu.dessert);
        }
    };
    fclose(f);
    fclose(f2);
    remove("Nutritionniste.txt");
    rename("modif_nut.txt","Nutritionniste.txt");

    }


void meilleur_ab(Menus menu)
{
    int jour , plat,s,b,i,r,k;
    float dechet,s1,max;
    float T[50];
    FILE *f2=NULL;

   printf("choisir la semaine:\n");
    scanf("%d",&s);
    if (s==1) 
    {
      b=1;  
    }
    if (s==2) 
    {
      b=8;  
    }
    if (s==3) 
    {
      b=15;  
    }
    if (s==4) 
    {
      b=22;  
    }
    i=b;
    s1=0;
    f2=fopen("dechets.txt","r");
     while (!EOF) {
        
        fscanf(f2,"%d %d %f \n", &jour, &plat , &dechet);
        while (i<7+b){
        if (i == jour)
	 {
            s1=dechet+s1;}
        if (plat==3)
        { 
            T[i]=s1;
            i=i+1;
        }
        }
    }
    fclose(f2);
    max=T[0];
    r=0;
    for (k=1;k<i;i++)
    {
        if (T[k]<max)
        {
            max=T[k];
            r=k;
        }
    }
    printf("%d a le menu qui a le moins de dechets de la semaine avec %f kg de dechets ",r,max);
     }
    
enum
{
JOURS,
TYPE,
ENTREE,
PLAT,
DESSERT,
COLUMNS
};
   
 void afficher_menu(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jours[50];
 char type[50];
 char entree[100];
 char plat[50];
 char dessert[50];
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Plat",renderer,"text",PLAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("Nutritionniste.txt", "r");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("Nutritionniste.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s \n",jours,type,entree,plat,dessert)!=EOF)
    {
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT,plat,DESSERT,dessert, -1);

    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
   
}
}
 void vider_ab(GtkWidget *liste)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jours[50];
 char type[50];
 char entree[50];
 char plat[50];
 char dessert[50];
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Plat",renderer,"text",PLAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  gtk_list_store_append(store,&iter);
 gtk_tree_view_set_model (GTK_TREE_VIEW (liste) , GTK_TREE_MODEL(store));
}
void rechercher_menu(GtkWidget *liste, char x1[],char x2[],char x3[],char ce[])
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jours[50];
 char type[50];
 char entree[100];
 char plat[50];
 char dessert[50];
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOURS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Entrée",renderer,"text",ENTREE,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Plat",renderer,"text",PLAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dessert",renderer,"text",DESSERT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

  }
  store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("Nutritionniste.txt", "r");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("Nutritionniste.txt", "a+");
    while(fscanf(f,"%s %s %s %s %s \n",jours,type,entree,plat,dessert)!=EOF)
    {
   if ((strcmp(jours,ce)==0) && (strcmp(x1,type)==0)){
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT,plat,DESSERT,dessert, -1);
}
   if ((strcmp(jours,ce)==0) && (strcmp(x2,type)==0)){
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT,plat,DESSERT,dessert, -1);
}
   if ((strcmp(jours,ce)==0) && (strcmp(x3,type)==0)){
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOURS,jours,TYPE,type,ENTREE,entree,PLAT,plat,DESSERT,dessert, -1);
}
    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
   
}
}
enum{
JOUR,
DECHETS,
NB_COLUMNS
};
 void afficher_Dash(GtkWidget *liste,int c)
{
  GtkCellRenderer *renderer;
  GtkTreeViewColumn *column;
  GtkTreeIter iter;
  GtkListStore *store;
 char jour[50];
 char plat[50];
 char dechets[100];

   
    int jours , platt,i;
    char dechet[50],s1[50],s2[50],s3[50],s4[50];
    char T[100][100];
    FILE *f2=NULL;

    strcpy(s1,"99.99");
    strcpy(s2,"99.99");
    strcpy(s3,"99.99");
    strcpy(s4,"99.99");
   
    f2=fopen("dechets.txt","r");
     
         while(fscanf(f2,"%d %d %s \n",&jours, &platt , dechet )!=EOF)
    {
        if (jours<8){
        
        if (strcmp(dechet,s1)==-1){
            strcpy(s1,dechet);}}
     if ((jours<15)&&(jours>7)){
       
        if (strcmp(dechet,s2)==-1){
            strcpy(s2,dechet);}}
  if ((jours<22)&&(jours>14)){
        
        if (strcmp(dechet,s3)==-1){
           strcpy( s3,dechet);}}
     if ((jours<31)&&(jours>21)){

          if (strcmp(dechet,s4)==-1){
            strcpy(s4,dechet);}}
    }
    fclose(f2);
   strcpy(T[0],s1);
   strcpy(T[1],s2);
   strcpy(T[2],s3);
   strcpy(T[3],s4);
  store=NULL;

  FILE *f;
  store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {

    renderer= gtk_cell_renderer_text_new();
    column=gtk_tree_view_column_new_with_attributes("Numero du jour",renderer,"text",JOUR,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
  column=gtk_tree_view_column_new_with_attributes("plat",renderer,"text",PLAT,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    renderer= gtk_cell_renderer_text_new();
    column= gtk_tree_view_column_new_with_attributes("Dechets",renderer,"text",DECHETS,NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
   
  }
  store=gtk_list_store_new(NB_COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("dechets.txt", "a");
  if (f==NULL)
  {
    return;
  }
  else
  {
    f= fopen("dechets.txt", "a+");
   while(fscanf(f,"%s %s %s \n",jour, plat , dechets )!=EOF)
    {
    if (( c==1)&& (strcmp(dechets,T[0])==0)){
  
  
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS,dechets, -1);}
   if (( c==2)&&(strcmp(dechets,T[1])==0)) {

   
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS,dechets, -1);}
   if (( c==3) && (strcmp(dechets,T[2])==0)){
     gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS,dechets, -1);}
   if (( c==4)&&(strcmp(dechets,T[3])==0)) {

  
      gtk_list_store_append(store, &iter);
      gtk_list_store_set(store, &iter,JOUR,jour,PLAT,plat,DECHETS,dechets, -1);}

    }
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref (store);
gtk_tree_view_set_enable_search(GTK_TREE_VIEW(liste),TRUE);
   
}
}


