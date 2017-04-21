
/**
   Ce modele regroupe les structures et entêtes des fonctions de la liste linéaire chainés
   qui represente chaque mot du texte avec sa position dans la ligne.
    */



//////////////////////////******************Liste de Mot du texte **************///////////////////////////////////////////////


/// LA STRUCTURE :
typedef struct Mot
{
     char mot[255];
     int numligne;
     int pos;
     struct Mot* suivant;
     struct Mot* precedant;
     char ponctu[255];

} Mot;



/// LES ENTETES :
struct Mot* allouer(void);
// Alloue dynamiquement (grace à malloc) l'espace necessaire a la structure Mot.
void Aff_Val(Mot* p, char val[255]);
// Affecte la valeur de la chaine à la structure.
void Aff_Ponct(Mot* p, char val[255]);
// Affecte la valeur de la chaine à la chaine de ponctuation de la structure Mot.
void Aff_pos(Mot* p, int pos);
// Affecte la valeur de pos à p->pos.
void Aff_Nligne(Mot* p, int ligne);
// Affecte la valeur de ligne à pos->numligne.
void Aff_AdrD(Mot *p, Mot * q);
// Affecte l'adresse de q à p->suivant.
void Aff_AdrG(Mot *p, Mot * q);
// Affecte l'adresse de q à p->precedant.
Mot* Suivant(Mot* p);
// Retourne l'adresse du suivant de p.
Mot* Precedant(Mot* p);
// Retourne l'adresse du precedant de p.
char* Valeur(Mot* p);
// Retourne p->mot.
char* Ponct(Mot* p);
// Retourne p->Ponctu.
int Position(Mot* p);
// Retourne p->pos.
int Nligne(Mot* p);
// Retoune p->numligne.



/////////////////////////////////////******************Liste de textes********************///////////////////////////

/// LA STRUCTURE :

typedef struct texte
{
   char nomfich[255];
   Mot* first;
   Mot* last;
   struct texte* suiv;


} texte;


/// LES ENTETES :
struct texte* allouerT(void);
// Alloue dynamiquement (grace à malloc) l'espace necessaire a la structure texte.
void Aff_AdrT(texte *P,texte *Q);
// Affecte l'adresse de Q au suivant de P.
void Aff_Tete(texte *P,Mot *T);
// Affecte l'adresse de la tete de la liste de Mot à P->first.
void Aff_Queu(texte *P,Mot *T);
// Affecte l'adresse de la queue de la liste de Mot à P->last.
void Sauv_Nom(texte *P,char Nom[]);
// Sauvegarde le nom du fichier.
texte *Suivant_T(texte *P);
// Retourne le suivant de P.
char* Nom_fich(texte *P);
// Retourne le nom du fichier.
Mot *TeteMo(texte *P);
// Retourne l'adresse du premier mot.
Mot *QueuMo(texte *P);
// Retourne l'adresse du dernier mot.
