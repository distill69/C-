#ifndef SOCIETE_H
#define SOCIETE_H

#include "Panier.h"

class Societe
{
public:

    Societe();//Constructeur par defaut
    Societe(const char *nom, const char *localite, unsigned int cp);//Constructeur par parametre
    Societe(const Societe & source);//Constructeur de recopie
    virtual ~Societe();//Destructeur

    void allocationMemoire();//Allocation dynamique de la mémoire pour les chaines de caracteres

    //Getteurs
    char *getIdSociete() const;
    char *getNom() const;
    char *getLocalite() const;
    unsigned int getCp() const;

    //Setteurs
    void setIdSociete(const char *idSociete);
    void setNom(const char *nom);
    void setLocalite(const char *localite);
    void setCp(unsigned int cp);

    //Surcharge d operateur
    Societe & operator= (Societe &source);//Surcharge de l operateur =
    Societe & operator= (int zero);//Surcharge de l operator= pour une remise a zero


    void creationSociete(Societe *societe);//Creation d une nouvelle societe

private:

    //Attributs
    static unsigned long compteur;

    char*m_idSociete;
    char *m_nom;
    char *m_localite;
    unsigned int m_cp;
};

std::ostream & operator<< (std::ostream & os, const Societe &source);//surcharge de << permettant d afficher une Societe

#endif // PANIER_H

