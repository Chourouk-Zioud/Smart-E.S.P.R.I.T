#include <gtk/gtk.h>


void
on_bouton_connecter_kais_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_calendar_aujourdhui_kais_day_selected
                                        (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_bouton_appeler_kais_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_envoyer_sms_kais_clicked     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_envoyer_mail_kais_clicked    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_afficher_kais_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_ajouter_kais_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_modifier_kais_clicked        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_supprimer_kais_clicked       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_poste_plus_occupe_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radio_ajouter_homme_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_ajouter_femme_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_calendar_ajouter_ddn_kais_day_selected
                                        (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_check_ajouter_etudiant_kais_toggled (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_ajouter_stock_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_ajouter_restaurant_kais_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_ajouter_nutritionniste_kais_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_ajouter_foyer_kais_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_check_ajouter_technicien_kais_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bouton_confirmer_ajout_kais_clicked (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_annuler_ajout_kais_clicked   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_quitter_recherche_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_verifier_recherche_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radio_modifier_femme_kais_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radio_modifier_homme_kais_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bouton_confirmer_modification_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_annuler_modification_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_utilisateurs_kais_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bouton_actualiser_utilisateurs_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_annuler_suppression_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_confirmer_suppression_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_button_modifier_check_kais_clicked  (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_bouton_about_kais_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_bouton_quitter_utilisateurs_kais_clicked
                                        (GtkWidget       *objet,
                                        gpointer         user_data);


/////////////////////////////////////////////////////////////////////////////

void
on_button1_gestion_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2_meilleur_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button7_home_ab_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_ajouter_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_modifier_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_supprimer_ab_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_afficher_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button8_home_ab_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_ajouter_ab_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button9_return_ab_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13_modifier_ab_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button15_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_semaine1_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_semaine2_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_semaine4_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_semaine3_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button14_rechercher_ab_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_petitdej_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_dejeuner_ab_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_diner_ab_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button18_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button17_supprimer_ab_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button19_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button21_home_ab_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button20_meilleur_ab_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button22_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button23_return_ab_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton4_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_ab_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

////////////////////////////////////////////////////////////////////////////




void
on_KAIS_clicked                        (GtkButton       *button,
                                        gpointer         user_data);
void

on_AMENI_clicked                       (GtkButton       *button,
                                        gpointer         user_data);

void
on_MERIEM_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_BAKARY_clicked                      (GtkButton       *button,
                                        gpointer         user_data);


void
on_AHMED_clicked                       (GtkButton       *button,
                                        gpointer         user_data);


void
on_HAYKEL_clicked                      (GtkButton       *button,
                                        gpointer         user_data);


/////////////////////////////// MERIEM //////////////////////////////////////////////////


void
on_button1_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_modifier_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_supprimer_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_home_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_chercher_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_AJ_home_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button8_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button9_MOD_home_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button10_modifier_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_supprimer_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button13_SUPP_home_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_rupstock_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button14_RUPST_Khome_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_afficher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_gestion_clicked             (GtkButton       *button,
                                        gpointer         user_data);


void
on_button4_home_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_rupture_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_retourME_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button122_retourME_clicked          (GtkButton       *button,
                                        gpointer         user_data);

/////////////////////////////// BAKARY //////////////////////////////////////////////////

void
on_Valider_auth_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_bt_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_recherche_bt_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_calcul_bt_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_Affichage_bt_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_Ajout_bt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_modification_bt_clicked      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Suppress_bt_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_f_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_m_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_retour_ajout_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ajouter_bt_clicked           (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton_mm_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonfm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_modif_bt_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_retourmodif_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton_d_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_q_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_c_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_retourcalcul_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_calculer_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_retourrecherche_clicked      (GtkWidget       *button,
                                        gpointer         user_data);


///////////////////////////////////////////////////////////////////////////////////////


void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonboard_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonafficher_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrecherche_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_checkbuttonvm_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbuttonva_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonsupprimerhk_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouterhk_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonactualiserhk_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifierhk_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonboardhk_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrecherchehk_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouthk_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifhk_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonafficherhk_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewhk_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


///////////////////////////// AHMED //////////////////////////////////////////////::



void
on_buttonAjout_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonhomeajouter_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_gestCapt_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_captDefect_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_alarmes_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_goto_etage_panne_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_quit_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_togglebuttonfumee_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_togglebuttonmovsus_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_togglebuttonfuite_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonprotcivil_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonconcierge_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonadministration_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_homelistealarm_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonhomeDEFECT_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_validermodification_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonhomemodifier_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonrechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonhomeconsult_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonquitterconsult_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonajouterconsult_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonmodifierconsult_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_supprimer_afficher_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeviewconsult_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimercapteur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_HOME_clicked                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_clicked                    (GtkButton       *button,
                                        gpointer         user_data);


//////////////////////////////////////////////////////////////////////////////////////

void
on_button13_ep_kais_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeviewep_kais_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_resume_ep_clicked            (GtkWidget       *objet,
                                        gpointer         user_data);
