
/** Ce modele regroupe les fonctions de manipulation de la liste linéaire chainés
    qui represente chaque mot du texte avec sa position dans la ligne, ainsi que
    celle qui represente la liste de texte.
    BENMEZIANE/AIOUEZ.  */

#include "LLC_modele.h"



//////////////////////////******************Liste de Mot du texte **************///////////////////////////////////////////////

struct Mot* allouer(void)
{
    return ((struct Mot*) malloc(sizeof(Mot)));

}

void Aff_Val(Mot* p, char val[255])
{

   strcpy(p->mot, val);
}

void Aff_Ponct(Mot* p, char val[255])
{

   strcpy(p->ponctu, val);
}


void Aff_pos(Mot* p, int pos)
{
    p->pos = pos;
}

void Aff_Nligne(Mot* p, int ligne)
{
    p->numligne = ligne;
}

void Aff_AdrD(Mot *p, Mot * q)
{
    p->suivant = q;

}
void Aff_AdrG(Mot *p, Mot * q)
{
    p->precedant = q;

}

Mot* Suivant(Mot* p)
{
    return (p->suivant);

}

Mot* Precedant(Mot* p)
{
    return (p->precedant);
}

char* Valeur(Mot* p)
{
    return(p->mot);
}

char* Ponct(Mot* p)
{
    return (p->ponctu);
}

int Position(Mot* p)
{
    return (p->pos);
}

int Nligne(Mot* p)
{
    return(p->numligne);
}




/////////////////////////////////////******************Liste de texte********************///////////////////////////

struct texte* allouerT(void)
{
    return ((struct texte*) malloc(sizeof(texte)));

}

void Aff_AdrT(texte *P,texte *Q)
  {
      P->suiv=Q;
  }

void Aff_Tete(texte *P,Mot *T)
  {
      P->first=T;
  }

void Aff_Queu(texte *P,Mot *T)
  {
      P->last=T;
  }

void Sauv_Nom(texte *P,char Nom[])
   {
       strcpy(P->nomfich,Nom);
   }

texte *Suivant_T(texte *P)
  {
      return (P->suiv);
  }

char* Nom_fich(texte *P)
   {
       return (P->nomfich);
   }

Mot *TeteMo(texte *P)
    {
        return (P->first);
    }

Mot *QueuMo(texte *P)
    {
        return (P->last);
    }

