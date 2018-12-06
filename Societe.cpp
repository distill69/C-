#include "Societe.h"

#include <string.h>

using namespace std;

unsigned long Societe::compteur = 1L;

//-----------------------------------------------------------------------------------------------------------
Societe::Societe()
{
    allocationMemoire();

    sprintf(m_idSociete, "ID Societe%03lu", compteur++);

    setNom("\0");
    setLocalite("\0");
    setCp(0);

    cout << "\tConstructeur par defaut de societe" <<endl;
}

Societe::Societe(const char *nom, const char *localite, unsigned int cp)
{
    allocationMemoire();

    sprintf(m_idSociete, "ID Societe%03lu", compteur++);

    setNom(nom);
    setLocalite(localite);
    setCp(cp);

    cout << "\tConstructeur par parametre de societe" <<endl;
}

Societe::Societe(const Societe & source)
{
    allocationMemoire();

    sprintf(m_idSociete, "ID Societe%03lu", compteur++);

    setNom(source.m_nom);
    setLocalite(source.m_localite);
    setCp(source.m_cp);

    cout << "\tConstructeur par recopie de societe" <<endl;
}

Societe::~Societe()
{
    compteur--;

    delete [] m_idSociete;
    delete [] m_nom;
    delete [] m_localite;

    cout << "\tDestructeur de societe" << endl;
}

//-----------------------------------------------------------------------------------------------------------
void Societe::allocationMemoire()
{
    m_idSociete = new char [BUFFERSIZE];
    m_nom = new char [BUFFERSIZE];
    m_localite = new char [BUFFERSIZE];
}

Societe & Societe::operator= (Societe &source)
{
    if(this==&source)
        return(*this);
    else
    {
        setIdSociete(source.m_idSociete);
        setNom(source.m_nom);
        setLocalite(source.m_localite);
        setCp(source.m_cp);
    }
    return(*this);
}

Societe & Societe::operator= (int zero)
{
    if(zero == 0)
    {
        setIdSociete("\0");
        setIdSociete("\0");
        setNom("\0");
        setLocalite("\0");
        setCp(0);
    }
    return (*this);
}
//-----------------------------------------------------------------------------------------------------------
char *Societe::getIdSociete() const
{
    if(!m_idSociete)
        return 0;
    else
    {
        char *aid = new char [BUFFERSIZE];
        strncpy(aid, m_idSociete, BUFFERSIZE);
        return aid;
    }
}

char *Societe::getNom() const
{
    if(!m_nom)
        return 0;
    else
    {
        char *anom = new char [BUFFERSIZE];
        strncpy(anom, m_nom, BUFFERSIZE);
        return anom;
    }
}

char *Societe::getLocalite() const
{
    if(!m_localite)
        return 0;
    else
    {
        char *alocalite = new char [BUFFERSIZE];
        strncpy(alocalite, m_localite, BUFFERSIZE);
        return alocalite;
    }
}

unsigned int Societe::getCp() const
{
    return m_cp;
}

//-----------------------------------------------------------------------------------------------------------
void Societe::setIdSociete(const char *idSociete)
{
    if(!idSociete)
        m_idSociete [0] = 0;
    else
    {
        strncpy(m_idSociete, idSociete, BUFFERSIZE);
        m_idSociete [BUFFERSIZE-1] = 0;
    }
}

void Societe::setNom(const char *nom)
{
    if(!nom)
        m_nom [0] = 0;
    else
    {
        strncpy(m_nom,nom, BUFFERSIZE);
        m_nom [BUFFERSIZE-1] = 0;
    }
}

void Societe::setLocalite(const char *localite)
{
    if(!localite)
        m_localite [0] = 0;
    else
    {
        strncpy(m_localite, localite, BUFFERSIZE);
        m_localite [BUFFERSIZE-1] = 0;
    }
}

void Societe::setCp(unsigned int cp)
{
    m_cp=cp;
}

//-----------------------------------------------------------------------------------------------------------
void Societe::creationSociete(Societe *societe)
{
    char *temp = new char [BUFFERSIZE];
    cout << "Quel est le nom de votre magazin? ";
    cin >> temp;
    cin.ignore();
    cout << endl;
    societe->setNom(temp);

    cout << "Quel est la localite de votre magazin? ";
    cin >> temp;
    cin.ignore();
    cout << endl;
    societe->setLocalite(temp);

    delete [] temp;

    int temp2;
    Perso perso;
    cout << "Quel est le code postal de votre magazin? ";
    temp2 = perso.lireInt();
    cout << endl;
    societe->setCp(temp2);
    perso.viderBuffer();
}
//-----------------------------------------------------------------------------------------------------------
ostream & operator<< (ostream & os, const Societe &source)
{
    os << "ID de la societe : " << source.getIdSociete() <<endl;
    os << "Nom de la societe : " << source.getNom() << endl;
    os << "Localite : " << source.getLocalite() << endl;
    os << "Code postale : " << source.getCp();
    return os;
}
