#include "Panier.h"

#include <string.h>

using namespace std;

unsigned long Panier::compteur = 1L;

//-----------------------------------------------------------------------------------------------------------
Panier::Panier()
{
    m_idPanier = new char [BUFFERSIZE];

    sprintf(m_idPanier, "ID Panier%03lu", compteur++);

    setValeur(0);
    setNbArticlePanier(0);

    articles = new Article [NBSLOTPANIER];


    cout << "\tConstructeur par defaut de panier" << endl;
}

Panier::Panier(const Panier & source)
{
    m_idPanier = new char [BUFFERSIZE];

    sprintf(m_idPanier, "ID Panier%03lu", compteur++);

    setValeur(source.m_valeur);
    setNbArticlePanier(source.m_nbArticlePanier);

    articles = new Article [NBSLOTPANIER];

    cout << "\tConstructeur par recopie de panier" << endl;
}


Panier::~Panier()
{
    compteur--;

    delete [] m_idPanier;
    delete [] articles;

    cout << "\tDestructeur de panier" << endl;
}

//-----------------------------------------------------------------------------------------------------------
char *Panier::getIdPanier() const
{
    if(!m_idPanier)
        return 0;
    else
    {
        char *aid = new char [BUFFERSIZE];
        strncpy(aid, m_idPanier,BUFFERSIZE);
        return aid;
    }
}

unsigned int Panier::getValeur() const
{
    return m_valeur;
}

unsigned int Panier::getNbArticlePanier() const
{
    return m_nbArticlePanier;
}

const Article *Panier::getArticle(int emplacement) const
{
    return &articles[emplacement];
}
//-----------------------------------------------------------------------------------------------------------
void Panier::setIdPanier(const char *idPanier)
{
    if(!idPanier)
        m_idPanier [0] = 0;
    else
    {
        cout << "0" << endl;
        cout << *m_idPanier << endl;
        cout << *idPanier<< endl;
        strncpy(m_idPanier, idPanier, BUFFERSIZE);
        cout << "1";
        m_idPanier [BUFFERSIZE-1] = 0;
        cout << "2";
    }
}

void Panier::setValeur(unsigned int valeur)
{
    m_valeur=valeur;
}

void Panier::setNbArticlePanier(unsigned int nbArticlePanier)
{
    m_nbArticlePanier=nbArticlePanier;
}

//-----------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------
Panier & Panier::operator= (Panier &source)
{
    if(this==&source)
        return(*this);
    else
    {
        setIdPanier(source.m_idPanier);
        setValeur(source.m_valeur);
        setNbArticlePanier(source.m_nbArticlePanier);

        articles = source.articles;
    }
    return(*this);
}
Panier & Panier::operator= (int zero)
{
    if(zero == 0)
    {
        setIdPanier("\0");
        setValeur(0);
        setNbArticlePanier(0);

    }
    return (*this);
}

void Panier::ajoutArticlePanier(Article & source, int emplacement)
{
    if(emplacement>=0 && emplacement < NBSLOTPANIER)
    {
        articles[emplacement] = source;
    }
}

ostream & operator<< (ostream & os, const Panier &panier)
{
    if(panier.getNbArticlePanier()==0)
        cout << "Votre panier est vide" << endl;
    else
    {
        os << "ID du panier : " << panier.getIdPanier() << endl;
        os << "Valeur totale du panier : " << panier.getValeur() << endl;
        os << "Nombre d article present dans le panier : " << panier.getNbArticlePanier();
    }

    return os;
}
