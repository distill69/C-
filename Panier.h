#ifndef PANIER_H
#define PANIER_H

#include "Article.h"
#include "Acheteur.h"

#define NBSLOTPANIER 3


class Panier
{
public:

    Panier();//Constructeur par defaut
    Panier(const Panier & source);//Constructeur de recopie
    virtual ~Panier();//Destructeur

    //Getteurs
    char *getIdPanier() const;
    unsigned int getValeur() const;
    unsigned int getNbArticlePanier() const;
    const Article *getArticle(int emplacement) const;

    //Setteurs
    void setIdPanier(const char *idPanier);
    void setValeur(unsigned int valeur);
    void setNbArticlePanier(unsigned int nbArticlePanier);

    //Surcharge d operateur
    Panier & operator= (Panier &source);//Surcharge de l operateur =
    Panier & operator= (int zero);//Surcharge de l operator= pour une remise a zero

    void ajoutArticlePanier(Article & source, int emplacement);//Permet d ajouter un article a ma liste dans le panier

private:

    //Attributs
    static unsigned long compteur;

    char *m_idPanier;
    unsigned int m_valeur;
    unsigned int m_nbArticlePanier;
    Article *articles;
};

std::ostream & operator<< (std::ostream & os, const Panier &panier);//surcharge de << permettant d afficher un panier

#endif // PANIER_H

