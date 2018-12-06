#ifndef ARTICLE_H
#define ARTICLE_H

#include <iostream>

#define BUFFERSIZE 55

class Article
{
public:
    Article();//Constructeur par défaut
    Article(const char *nomArticle, const char *type, unsigned int valeur, unsigned int nombre);//Constructeur par parametre
    Article(const Article &source);//Constructeur de recopie
    virtual ~Article();//Destructeur

    //Getteurs
    char *getIdArticle () const;
    char *getNomArticle() const;
    char *getType() const;
    unsigned int getValeur() const;
    unsigned int getNombre() const;

    //Setters
    void setIdArticle(const char *idArticle);
    void setNomArticle(const char *nomArticle);
    void setType(const char *type);
    void setValeur(unsigned int valeur);
    void setNombre(unsigned int nombre);

    void allocationMemoire();//Allocation dynamique de la mémoire pour les chaines de caracteres

    //Operateurs de surcharge
    Article & operator= (Article &source);//surcharge de l operateur =
    Article & operator= (int zero);//surcharge de l operateur = pour remettre l article a 0


private:

    //Attributs
    static unsigned long m_compteur;
    char *m_idArticle;
    char *m_nomArticle;
    char *m_type;

    unsigned int m_valeur;
    unsigned int m_nombre;
};

std::ostream & operator<< (std::ostream &os, const Article &Art);//surcharge de << permettant d afficher un article

#endif // ARTICLE_H
