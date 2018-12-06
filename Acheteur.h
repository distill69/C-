#ifndef ACHETEUR_H
#define ACHETEUR_H

#include <iostream>

#include "Perso.h"

#define BUFFERSIZE 55

class Acheteur
{
public:

    Acheteur();//Constructeur par défaut
    Acheteur(const char *nomAcheteur, unsigned int age, const char *localite, unsigned int cp);//Constructeur par parametre
    Acheteur(Acheteur &source);//Constructeur de recopie
    virtual ~Acheteur();//Destructeur

    void allocationMemoire();//Allocation dynamique de la mémoire pour les chaines de caracteres

    Acheteur & operator= (const Acheteur &source);//surcharge de l operateur =


    //Getteurs
    char *getIdAcheteur() const;
    char *getNomAcheteur() const;
    unsigned int getAge() const;
    char *getLocalite() const;
    unsigned int getCp() const;

    //Setteurs
    void setIdAcheteur(const char *idAcheteur);
    void setNomAcheteur(const char *nomAcheteur);
    void setAge(unsigned int age);
    void setLocalite(const char *localite);
    void setCp(unsigned int cp);

    void creationAcheteur(Acheteur &source);//Creation d'un nouvel acheteur



private:

    //Attributs
    static unsigned long compteur;
    char *m_idAcheteur;
    char *m_nomAcheteur;
    unsigned int m_age;
    char *m_localite;
    unsigned int m_cp;
};

std::ostream & operator<< (std::ostream &os, const Acheteur &source);//surcharge de << permettant d afficher un acheteur
#endif // ACHETEUR_H
