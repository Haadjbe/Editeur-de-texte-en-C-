#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../BIBLIO/ModeleLLC/LLC_Modele.h"

/*************************************************************************************/
int wherex() /* Rôle : Donne la coordonnée y ou est positionné le curseur. */
  {

  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;

    result.X = csbi.dwCursorPosition.X;
  return result.X;
  }

/**************************************************************************************/
int wherey() /* Rôle : Donne la coordonnée y ou est positionné le curseur. */
  {

  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD result;
  if (!GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ),&csbi))
    return -1;

    result.Y = csbi.dwCursorPosition.Y;

  return result.Y;

  }
/**************************************************************************************/
void effaceCursor() /* Rôle : Efface le cursor de la console. */
{
        HANDLE hConsoleOutput;
        CONSOLE_CURSOR_INFO structCursorInfo;
        hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
        GetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );
        structCursorInfo.bVisible = FALSE;
        SetConsoleCursorInfo( hConsoleOutput, &structCursorInfo );

}
/**************************************************************************************/
void gotoxy (int x, int y) /* Rôle : Deplace le curseur à la position indiquée. */
{
    COORD pos; // COORD est une structure préalable à la bibliothèque windows.h
    pos.X = x; // X et Y sont de type SHORT.
    pos.Y = y;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (!SetConsoleCursorPosition(hConsole, pos))
    {
        printf("Erreur dans le GOTOXY CURSOR POS SET");
    }
}

/**************************************************************************************/
void ClearScreen() /* Rôle : efface la zone d'interaction avec l'utilisateur (n'efface pas le menu). */
{

    gotoxy(0,7);

    int i,j;
    for (j=6 ; j<31; j++ )
    {
    for (i=0; i< 101; i++)
    {
         printf("%c", ' ');

    }
    //printf("\n");
    }
      color(15,1);

}
/**************************************************************************************/
void supprdepuis(COORD posdebut, COORD posfin) /* Rôle : Efface une zone comprise entre les coords de debut et de fin. */
{
    gotoxy(posfin.X, posfin.Y);
    int i, diff=0;

//----------------------------------------------- On calcule la difference entre les deux coords -----------------------------
    if (posdebut.Y == posfin.Y) { diff = posfin.X - posdebut.X;  /*printf("%d", diff);*/ } // Si les coordonnées sont sur la même ligne.
    else{
    while (posfin.X != posdebut.X || posfin.Y != posdebut.Y)
    {
        if(posfin.X == 0){ posfin.Y--; posfin.X = 100; } // A chaque fois qu'on remonte à une ligne précedante.
        posfin.X--;
        diff++;
    }}
//------------------------------------------------------------------------------------------------------------------------------


    COORD Current;
    for (i = 0; i <diff; i++ ){
        color(1,1);
        printf("%c", 8); /*printf("ssssss"); */
        printf("%c", ' ');
        printf("%c", 8);
        Current.X = wherex();
        Current.Y = wherey();

        if ( Current.X == 0 && Current.Y != posdebut.Y) { gotoxy(100, Current.Y-1); }

    }
    color(15,1);

}
/*****************************************************************************************/
void init(void) /* Rôle : Affiche la fênetre d'initialisation du programme. */
{
        system ("color 1F");
        printf("                                                                                                   \n");
        printf(" **************************************************************************************************\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                     EEEEEEEEEEEEEEEEEEEEEE   SSSSSSSSSSSSSSS IIIIIIIIII                        *\n");
        printf(" *                     E::::::::::::::::::::E SS:::::::::::::::SI::::::::I                        *\n");
        printf(" *                     E::::::::::::::::::::ES:::::SSSSSS::::::SI::::::::I                        *\n");
        printf(" *                     EE::::::EEEEEEEEE::::ES:::::S     SSSSSSSII::::::II                        *\n");
        printf(" *                       E:::::E       EEEEEES:::::S              I::::I                          *\n");
        printf(" *                       E:::::E             S:::::S              I::::I                          *\n");
        printf(" *                       E::::::EEEEEEEEEE    S::::SSSS           I::::I                          *\n");
        printf(" *                       E:::::::::::::::E     SS::::::SSSSS      I::::I                          *\n");
        printf(" *                       E:::::::::::::::E       SSS::::::::SS    I::::I                          *\n");
        printf(" *                       E::::::EEEEEEEEEE          SSSSSS::::S   I::::I                          *\n");
        printf(" *                       E:::::E                         S:::::S  I::::I                          *\n");
        printf(" *                       E:::::E       EEEEEE            S:::::S  I::::I                          *\n");
        printf(" *                     EE::::::EEEEEEEE:::::ESSSSSSS     S:::::SII::::::II                        *\n");
        printf(" *                     E::::::::::::::::::::ES::::::SSSSSS:::::SI::::::::I                        *\n");
        printf(" *                     E::::::::::::::::::::ES:::::::::::::::SS I::::::::I                        *\n");
        printf(" *                     EEEEEEEEEEEEEEEEEEEEEE SSSSSSSSSSSSSSS   IIIIIIIIII                        *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                   TP1 : EDITEUR DE TEXTE                                       *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                          APPUYEZ SUR LA TOUCHE ENTREE POUR COMMENCER                           *\n");
        printf(" **************************************************************************************************\n");


        getchar() ;
        system("cls"); // efface l'eran en entier.
}
/**************************************************************************************************/
void NotA() /* Rôle : Affiche quelques informations sur l'utilisation du programme. */
{
        printf("                                                                                                   \n");
        printf(" **************************************************************************************************\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                NOTE : Ce programme a ete realise dans le cadre du TP1                          *\n");
        printf(" *                       du semestre 2 dans le module d'ALSDD.                                    *\n");
        printf(" *                                                                                                *\n");
        printf(" *                Durant le programme vous utiliserez les touches :                               *\n");
        printf(" *                  -Les fleches bidirectionnelles, pour s'orienter dans les menus                *\n");
        printf(" *                  -'O' pour oui.                                                                *\n");
        printf(" *                  -'N' pour non.                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                En mode console, il n'ai pas necessaire d'ecrire un \\n                          *\n");
        printf(" *                a la fin de chaque ligne, la touche entree suffit.                              *\n");
         printf(" *                                                                                                *\n");

        printf(" *");
        color(4,1);
        printf("             IMPORTANT : ");
         color(15,1);
        printf("A la fin du texte, ecrire un slash /                                   *\n");

        printf(" *                    Apres la fin de chaque fonction, appuyez sur entree                         *\n");
        printf(" *                              pour revenir au menu.                                             *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                                                                                                *\n");
        printf(" *                          APPUYEZ SUR LA TOUCHE ENTREE POUR COMMENCER                           *\n");
        printf(" **************************************************************************************************\n");


        getchar() ;
        system("cls");

}

/**************************************************************************************************/
void help() /* Rôle : Affiche quelques informations sur l'utilisation du programme. */
{
       color(15,1);
       gotoxy(0,7);
       int y;

            printf("  ************************************** BESOIN D'AIDE ? **************************************\n\n");
            printf("          1. Pour naviguer dans le menu horizontal, utiliser les fleches droite et gauche.     \n\n");
            printf("          2. Pour naviguer dans les menus verticaux, utiliser les fleches haut et bas.         \n\n");
            printf("          3. Les fonctions du menu \"EDITER\" n'affichent pas le texte,\n ");
            printf("            l'affichage du texte est une fonction dans le menu \"AFFICHAGE\".    \n\n");
            printf("          4. A chaque fin de fonction, ou attente de resultat, appuyez sur la touche entree.     \n\n");
            printf("          5. La fonction \"CONFIGURATION\", sert a definir le chemin du repertoire contenant\n             les textes.  \n\n");
            printf("          6. A tout moment, pour enregistrer votre texte dans un fichier,\n");
            printf("             utiliser les fonctions \"ENREGISTRER\" ou \"ENREGISTRER SOUS\" du menu \"FICHIER\".    \n\n");
            printf("          7. Attention : la fonction \"ENREGISTRER\" ecrase le fichier contenant le texte original. \n\n ");
            printf("         8. IMPORTANT: le symbole de fin de texte est le / \n\n");
            printf("          9. Pour repondre aux questions, 'O' pour oui et 'N' pour non. \n\n");
            if (y > 20){  getchar();  ClearScreen(); gotoxy(0,7); }
            printf("          10. Il n'est pas necessaire d'ecrire \\n a la fin de la ligne, une entree suffit.  \n\n");
            printf("          11. La fonction \"RECHERCHER UNE CHAINE\" sert a rechercher une chaine donnee\n");
            printf("              dans les mots du texte.     \n\n");
            printf("          12. Appeler les fonctions autant de fois que necessaire. \n\n");
            printf("          13. Ouvrir un autre texte a n'importe quel moment grace a la fonction \"OUVRIR\". \n\n");
            printf(" ************************************************************************************************\n\n");

        fflush(stdin);
        getchar();
        ClearScreen();


}
/***************************************************************************************************************************/

void menu()
{
        int k;
    Mot *t=NULL;
    texte *tete=NULL;

// -------------------------------------- Menu Horizontal ---------------------------------------------------
    COORD debut, fin;
    char *menu_list[6] = { "FICHIER", "EDITER","AFFICHAGE", "STATISTIQUES","HELP",   "QUITTER" };
    int i,a,
         xpos[6] = {5, 20, 37, 58, 78, 90},     // les coordonnées x (colonne) à laquel on ecrit chaque colonne du menu.
         ypos = 0;                         // la coordonnée y (ligne) à laquel on ecrit chaque colonne du menu.

	// list the menu
	for (i=0; i< 6; i++)
	{
		gotoxy(xpos[i], ypos );
		printf("%s",menu_list[i] );
	}

	i=0;
	while(1)
	{
		gotoxy(xpos[i], ypos);
		color(1,15 );
		printf("%s",menu_list[i] );                                // On ecrit la colonne qui doit être coloré.

		/* ASCII note : 72 -> UP button
			            75 -> RIGHT button
                        77 -> LEFT button
                        80 -> DOWN button
		*/

	switch( _getch() )
    {
		case 75: if(i>0) {                           // Si l'utilisateur appuie sur le bouton droit et on est pas dans la premiere colonne du menu.
       		gotoxy(xpos[i],ypos );
            color(15,1);
            printf("%s", menu_list[i] );             // On décolore ce qui a été coloré.
            --i;                                    // On decremente le i (avancer a droite dans le menu).
            }
            break;

		case 77: if(i< 5)                          // Si l'utilisateur appuie sur le bouton gauche et on est pas dans la dernière colonne du menu.
			{
       			gotoxy(xpos[i],ypos );
                color(15,1);
                printf("%s", menu_list[i] );      // On décolore ce qui a été coloré.
                ++i;                              // On incremente le i (avancer à gauche dans le menu).
                }
        break;

		case 13:   //----------------------- Si l'utilisateur appuie sur entrée un menu vertical va s'afficher --------------------------------

		    /* Pour la création des menus verticaux on fait de même que le menu horizontal, sauf que là on change la coordonnée y et non x.
		       Car pour chaque ligne on change de y et on ecrit à la même colonne.
		       De plus, on enregistre la COORD de debut et de fin du menu pour supprimer le menu si l'utilisateur appuie sur le bouton droit ou gauche
		       ou lorsqu'il choisit une fonction dans la liste.
		       (SAUF BIEN SUR POUR LE MENU QUITTER)  */

		          if(i==0) {   // Menu FICHIER selectionné.

                          char *menu_listV1[5] = { "OUVRIR", "ENREGISTER", "ENREGISTRER SOUS","IMPRIMER",  "CONFIGURATIONS" };
                          int j,
                              xpos1 = xpos[i],
                              ypos1[5] = {1,2,3,4,5};


                           color(15,1);

                           debut.X = xpos1;
                           debut.Y = ypos1[0];

                            for (j=0; j< 5; j++)
                            {
                                gotoxy(xpos1, ypos1[j] );
                                printf("%s",menu_listV1[j] );
                            }

                          fin.X = wherex();
                          fin.Y = wherey();

                            j=0;


                            int continu = 1;
                            while(continu)
                            {


                                gotoxy(xpos1, ypos1[j]);
                                color(1,15 );
                                printf("%s",menu_listV1[j] );

                            switch( _getch() )
                            {
                                case 72: if(j>0) {
                                    gotoxy(xpos1,ypos1[j] );
                                    color(15,1);
                                    printf("%s", menu_listV1[j] );
                                    --j;
                                    }
                                    break;

                                case 80: if(j< 4)
                                    {
                                        gotoxy(xpos1,ypos1[j] );
                                        color(15,1);
                                        printf("%s", menu_listV1[j] );
                                        ++j;
                                        }
                                   break;

                                case 75 : continu = 0; supprdepuis(debut, fin);  break;
                                case 77 : continu = 0; supprdepuis( debut, fin ); break;

                                case 13: if(j==0) {  supprdepuis(debut, fin);
                                                     gotoxy(0,7);
                                                     CreateListText(&tete);

                                                     for (k=0; k< 5; k++)
                                                    {
                                                      gotoxy(xpos1, ypos1[k] );
                                                      printf("%s",menu_listV1[k] );
                                                    }

                                                   }
                                         if(j==1) { supprdepuis(debut, fin);
                                                    gotoxy(0,7);
                                                    Sauv_Fich(tete);

                                                     for (k=0; k< 5; k++)
                                                    {
                                                      gotoxy(xpos1, ypos1[k] );
                                                      printf("%s",menu_listV1[k] );
                                                    }

                                                    }
                                         if(j==2) { supprdepuis(debut, fin);
                                                    gotoxy(0,7);
                                                    Sauv_FichS(tete);
                                                     for (k=0; k< 5; k++)
                                                    {
                                                      gotoxy(xpos1, ypos1[k] );
                                                      printf("%s",menu_listV1[k] );
                                                    }
                                                  }
                                         if(j==3) { supprdepuis(debut, fin);
                                                    gotoxy(0,7);
                                                    imprim(tete);
                                                     for (k=0; k< 5; k++)
                                                    {
                                                      gotoxy(xpos1, ypos1[k] );
                                                      printf("%s",menu_listV1[k] );
                                                    } }

                                        if(j==4) { supprdepuis(debut, fin);
                                                    gotoxy(0,7);
                                                    Configuration();
                                                     for (k=0; k< 5; k++)
                                                    {
                                                      gotoxy(xpos1, ypos1[k] );
                                                      printf("%s",menu_listV1[k] );
                                                    } }

                                    break;
                            }
                            }

                         }

		      	if(i==1) {

                                char *menu_listV1[8] = { "Rechercher mots","Rechercher une chaine", "Rechercher/Remplacer",
                                 "Insertion mot", "Insertion ligne", "Suppression mot", "Suppression occurence de mot", "Suppression ligne"  };
                              int j,
                                  xpos1 = xpos[i],
                                  ypos1[8] = {1,2,3,4,5,6,7,8};
                                  color(15,1);

                               debut.X = xpos1;
                               debut.Y = ypos1[0];

                                for (j=0; j< 8; j++)
                                {
                                    gotoxy(xpos1, ypos1[j] );
                                    printf("%s",menu_listV1[j] );
                                }
                                fin.X = wherex();
                                fin.Y = wherey();

                                j=0;


                                int continu = 1;
                                while(continu)
                                {


                                    gotoxy(xpos1, ypos1[j]);
                                    color(1,15 );
                                    printf("%s",menu_listV1[j] );


                                switch( _getch() )
                                {
                                    case 72: if(j>0) {
                                        gotoxy(xpos1,ypos1[j] );
                                        color(15,1);
                                        printf("%s", menu_listV1[j] );
                                        --j;
                                        }
                                        break;

                                    case 80: if(j< 7)
                                        {
                                            gotoxy(xpos1,ypos1[j] );
                                            color(15,1);
                                            printf("%s", menu_listV1[j] );
                                            ++j;
                                            }
                                    break;
                                    case 75 : continu = 0; supprdepuis(debut, fin);  break;
                                    case 77 : continu = 0; supprdepuis( debut, fin ); break;

                                    case 13: if(j==0) {  supprdepuis(debut, fin);
                                                         gotoxy(0,7);
                                                         Rech_Color(tete);

                                                          for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                       }
                                             if(j==1) {  supprdepuis(debut, fin);
                                                         gotoxy(0,7);
                                                         Rech_lettr(tete);

                                                          for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                         }
                                             if(j==2) {  supprdepuis(debut, fin);
                                                         gotoxy(0,7);
                                                         Rech_Remp(tete);

                                                         for (k=0; k< 8; k++)
                                                           {
                                                            gotoxy(xpos1, ypos1[k] );
                                                            printf("%s",menu_listV1[k] );
                                                            }

                                                         }
                                             if(j==3) {  supprdepuis(debut, fin);
                                                         gotoxy(0,7);
                                                         Insertion_Mots(tete);

                                                         for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                         }
                                             if(j==4) { supprdepuis(debut, fin);
                                                        gotoxy(0,7);
                                                        Insertion_Lignes(tete);

                                                        for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                         }
                                             if(j==5) {  supprdepuis(debut, fin);
                                                         gotoxy(0,7);
                                                        Supp_Pos(tete);

                                                       for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                         }
                                             if(j==6) {  supprdepuis(debut, fin);
                                                         gotoxy(0,7);
                                                        Supp_Mot(tete);

                                                      for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                         }
                                             if(j==7) { supprdepuis(debut, fin);
                                                        gotoxy(0,7);
                                                        Supp_lignes(tete);

                                                        for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                          }

                                        break;
                                }
                                }


                    }

            if(i==2)
                {            char *menu_listV1[8] = {"Afficher texte",  "Afficher lignes","Affiche a partir",  "Taille du texte", "Afficher mots de taille x",
                             "Inverser texte", "Inverser ligne du texte" , "Tri par ordre alphabetique" };
                          int j,
                              xpos1 = xpos[i],
                              ypos1[8] = {1,2,3,4,5,6,7,8};
                              color(15,1);

                           debut.X = xpos1;
                           debut.Y = ypos1[0];

                            for (j=0; j< 8; j++)
                            {
                                gotoxy(xpos1, ypos1[j] );
                                printf("%s",menu_listV1[j] );
                            }

                            fin.X = wherex();
                            fin.Y = wherey();

                            j=0;


                            int continu = 1;
                            while(continu)
                            {


                                gotoxy(xpos1, ypos1[j]);
                                color(1,15 );
                                printf("%s",menu_listV1[j] );

                            switch( _getch() )
                            {
                                case 72: if(j>0) {
                                    gotoxy(xpos1,ypos1[j] );
                                    color(15,1);
                                    printf("%s", menu_listV1[j] );
                                    --j;
                                    }
                                    break;

                                case 80: if(j< 7)
                                    {
                                        gotoxy(xpos1,ypos1[j] );
                                        color(15,1);
                                        printf("%s", menu_listV1[j] );
                                        ++j;
                                        }
                                break;
                                case 75 : continu = 0; supprdepuis(debut, fin);  break;
                                case 77 : continu = 0; supprdepuis( debut, fin ); break;

                                case 13: if(j==0) {  supprdepuis(debut, fin);
                                                     gotoxy(0,7);
                                                     Affichtext(tete);

                                                            for (k=0; k< 8; k++)
                                                              {
                                                              gotoxy(xpos1, ypos1[k] );
                                                              printf("%s",menu_listV1[k] );
                                                             }
                                                  }

                                    if(j==1) {  supprdepuis(debut, fin);
                                                gotoxy(0,7);
                                                Affich_lignes(tete);

                                                            for (k=0; k< 8; k++)
                                                              {
                                                              gotoxy(xpos1, ypos1[k] );
                                                              printf("%s",menu_listV1[k] );
                                                             }
                                             }

                                      if(j==2) {  supprdepuis(debut, fin);
                                                  gotoxy(0,7);
                                                  AffichageApartir(tete);

                                                       for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }

                                               }
                                      if(j==3) {  supprdepuis(debut, fin);
                                                  gotoxy(0,7);
                                                  TaillFich(tete);

                                                        for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }

                                                }
                                    if(j==4) {  supprdepuis(debut, fin);
                                                gotoxy(0,7);
                                                Rech_nbrlet(tete);

                                                        for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                }

                                    if(j==5) {  supprdepuis(debut, fin);
                                                gotoxy(0,7);
                                                inverstexte(tete);

                                                        for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                            }

                                     if(j==6) {   supprdepuis(debut, fin);
                                                  gotoxy(0,7);
                                                  Inverse_Lignes(tete);

                                                    for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                         }
                                                }

                                    if(j==7) {  supprdepuis(debut, fin);
                                                gotoxy(0,7);
                                                TriAlpha(tete);

                                          for (k=0; k< 8; k++)
                                                          {
                                                          gotoxy(xpos1, ypos1[k] );
                                                          printf("%s",menu_listV1[k] );
                                                          }
                                        }
                                    break;
                            }
                            }


		      	}

            if (i == 3){
                         char *menu_listV1[4] = { "Frequence", "Histogramme","Mot les plus frequents"};
                          int j,
                              xpos1 = xpos[i],
                              ypos1[3] = {1,2,3};

                              color(15,1);

                           debut.X = xpos1;
                           debut.Y = ypos1[0];

                            for (j=0; j< 3; j++)
                            {
                                gotoxy(xpos1, ypos1[j] );
                                printf("%s",menu_listV1[j] );
                            }

                            fin.X = wherex();
                            fin.Y = wherey();



                            j=0;


                            int continu = 1;
                            while(continu)
                            {


                                gotoxy(xpos1, ypos1[j]);
                                color(1,15 );
                                printf("%s",menu_listV1[j] );

                            switch( _getch() )
                            {
                                case 72: if(j>0) {
                                    gotoxy(xpos1,ypos1[j] );
                                    color(15,1);
                                    printf("%s", menu_listV1[j] );
                                    --j;
                                    }
                                    break;

                                case 80: if(j< 2)
                                    {
                                        gotoxy(xpos1,ypos1[j] );
                                        color(15,1);
                                        printf("%s", menu_listV1[j] );
                                        ++j;
                                        }
                                break;
                                case 75 : continu = 0; supprdepuis(debut, fin);  break;
                                case 77 : continu = 0; supprdepuis( debut, fin ); break;

                                case 13: if(j==0) { supprdepuis(debut, fin);
                                                    gotoxy(0,7);
                                                    Frequence(tete);

                                                            for (k=0; k< 3; k++)
                                                            {
                                                                gotoxy(xpos1, ypos1[k] );
                                                                printf("%s",menu_listV1[k] );
                                                            }
                                                    }
                                         if(j==1) { supprdepuis(debut, fin);
                                                    gotoxy(0,7);
                                                    histo(tete);

                                                            for (k=0; k< 3; k++)
                                                            {
                                                                gotoxy(xpos1, ypos1[k] );
                                                                printf("%s",menu_listV1[k] );
                                                            }
                                                    }

                                         if(j==2) {  supprdepuis(debut, fin);
                                                     gotoxy(0,7);
                                                     Npremierfreq(tete);


                                                              for (k=0; k< 3; k++)
                                                                {
                                                                    gotoxy(xpos1, ypos1[k] );
                                                                    printf("%s",menu_listV1[k] );
                                                                }
                                                    }
                                    break;
                            }
                            }

		      	}
               if (i ==4) { help();
                            for (a=0; a< 6; a++)
	{
		gotoxy(xpos[a], ypos );
		printf("%s",menu_list[a] );
	}  }
               if (i == 5) { color(1,15);  return 0; }
               break;
            }

	}
}
