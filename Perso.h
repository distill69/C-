#ifndef PERSO_H
#define PERSO_H


class Perso
{
public:

    void viderBuffer();//Vide le buffeur

    char lireCaractere();//Lis un char

    int lire(char *chaine, int longueur);//Lis une chaine de caractere

    long lireLong();//Lis un long

    float lireFloat();//Lis un float

    int lireInt();//Lis un integer

    int lireInt09();//Lis un integer entre 0 et 9

    int continuer();//Demande a l utilisateur si il veut continuer O/N

    void initString(char *string, int sizeString);//Initialise une chaine de caractere


};

#endif // PERSO_H
