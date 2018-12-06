#include "Acheteur.h"

#include <string.h>

using namespace std;

unsigned long Acheteur::compteur = 1L;

//-----------------------------------------------------------------------------------------------------------
Acheteur::Acheteur()
{
    allocationMemoire();

    sprintf(m_idAcheteur, "ID acheteur%03lu", compteur++);

    setNomAcheteur("\0");
    setAge(0);
    setLocalite("\0");
    setCp(0);

    cout << "\tConstructeur par defaut de acheteur" << endl;
}

Acheteur::Acheteur(const char *nomAcheteur, unsigned int age, const char *localite, unsigned int cp)
{
    allocationMemoire();

    sprintf(m_idAcheteur, "ID acheteur%03lu", compteur++);

    setNomAcheteur(nomAcheteur);
    setAge(age);
    setLocalite(localite);
    setCp(cp);

    cout << "\tConstructeur par parametre de acheteur" << endl;
}

Acheteur::Acheteur(Acheteur &source)
{
    allocationMemoire();

    sprintf(m_idAcheteur, "ID acheteur%03lu", compteur++);

    setNomAcheteur(source.m_nomAcheteur);
    setAge(source.m_age);
    setLocalite(source.m_localite);
    setCp(source.m_cp);

    cout << "\tConstructeur par recopie de acheteur" << endl;
}

Acheteur::~Acheteur()
{
    compteur--;

    delete [] m_idAcheteur;
    delete [] m_nomAcheteur;
    delete [] m_localite;

    cout << "\tDestructeur de acheteur" << endl;
}

//-----------------------------------------------------------------------------------------------------------
void Acheteur::allocationMemoire()
{
    m_idAcheteur = new char [BUFFERSIZE];
    m_nomAcheteur = new char [BUFFERSIZE];
    m_localite = new char [BUFFERSIZE];
}

//-----------------------------------------------------------------------------------------------------------
Acheteur & Acheteur::operator= (const Acheteur &source)
{
    if(this==&source)
        return(*this);
    else
    {
        setIdAcheteur(source.m_idAcheteur);
        setNomAcheteur(source.m_nomAcheteur);
        setAge(source.m_age);
        setLocalite(source.m_localite);
        setCp(source.m_cp);
    }
    return (*this);
}

//-----------------------------------------------------------------------------------------------------------
char *Acheteur::getIdAcheteur() const
{
    if(!m_idAcheteur)
        return 0;
    else
    {
        char *aid = new char [BUFFERSIZE];
        strncpy(aid, m_idAcheteur, BUFFERSIZE);
        return aid;
    }
}

char *Acheteur::getNomAcheteur() const
{
    if(!m_nomAcheteur)
        return 0;
    else
    {
        char *anom = new char [BUFFERSIZE];
        strncpy(anom, m_nomAcheteur, BUFFERSIZE);
        return anom;
    }
}

unsigned int Acheteur::getAge() const
{
    return m_age;
}

char *Acheteur::getLocalite() const
{
    if(!m_localite)
        return 0;
    else
    {
        char *aloca = new char [BUFFERSIZE];
        strncpy(aloca, m_localite, BUFFERSIZE);
        return aloca;
    }
}

unsigned int Acheteur::getCp() const
{
    return m_cp;
}

//-----------------------------------------------------------------------------------------------------------
void Acheteur::setIdAcheteur(const char *idAcheteur)
{
    if(!idAcheteur)
        m_idAcheteur [0] = 0;
    else
    {
        strncpy(m_idAcheteur, idAcheteur, BUFFERSIZE);
        m_idAcheteur [BUFFERSIZE-1] = 0;
    }
}

void Acheteur::setNomAcheteur(const char *nomAcheteur)
{
    if(!nomAcheteur)
        m_nomAcheteur [0] = 0;
    else
    {
        strncpy(m_nomAcheteur, nomAcheteur, BUFFERSIZE);
        m_nomAcheteur [BUFFERSIZE-1] = 0;
    }
}

void Acheteur::setAge(unsigned int age)
{
    m_age=age;
}

void Acheteur::setLocalite(const char *localite)
{
    if(!localite)
        m_localite [0] = 0;
    else
    {
        strncpy(m_localite, localite, BUFFERSIZE);
        m_localite [BUFFERSIZE-1] = 0;
    }
}

void Acheteur::setCp(unsigned int cp)
{
    m_cp=cp;
}

void Acheteur::creationAcheteur(Acheteur &source)
{
    Perso perso;
    char *temp = new char [BUFFERSIZE];
    cout << "Nom de l acheteur : ";
    cin >> temp;
    cin.ignore();
    setNomAcheteur(temp);

    cout << endl << "Localite de l acheteur : ";
    cin >> temp;
    cin.ignore();
    setLocalite(temp);

    delete [] temp;

    int temp2;

    cout << endl<< "Code postal : ";
    temp2 = perso.lireInt();

    cout << endl << "Age de l acheteur : ";
    temp2 = perso.lireInt();
    cout << endl;
}
//-----------------------------------------------------------------------------------------------------------
ostream & operator<< (ostream &os, const Acheteur &source)
{
    os << "ID acheteur : " << source.getIdAcheteur() << endl;
    os << "Nom de l acheteur : " << source.getNomAcheteur() << endl;
    os << "Age : " << source.getAge() << endl;
    os << "Loacalite : " << source.getLocalite() << endl;
    os << "Code postal : " << source.getCp();
    return os;
}
