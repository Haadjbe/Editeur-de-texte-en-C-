#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "../BIBLIO/ModeleLLC/LLC_Modele.h"




int main ( int argc, char** argv )
{
    effaceCursor();
    system("mode con LINES=33 COLS=101"); // Agrandit la taille de la console.
    system("color 1F");                   // Met la couleur de texte à blanc, et le fond bleu.

    init();
    NotA();
    menu();

}
