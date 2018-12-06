#include "Article.h"
#include <string.h>


using namespace std;

unsigned long Article::m_compteur = 1L;

//-----------------------------------------------------------------------------------------------------------
Article::Article()
{
    allocationMemoire();

    setNomArticle("\0");
    setType("\0");
    setValeur(0);
    setNombre(0);
    sprintf(m_idArticle, "id article%03lu", m_compteur++);

    cout << "Constructeur par defaut de l article" << m_idArticle << endl;
}

Article::Article(const char *nomArticle, const char *type, unsigned int valeur, unsigned int nombre)
{
    allocationMemoire();

    setNomArticle(nomArticle);
    setType(type);
    setValeur(valeur);
    setNombre(nombre);
    sprintf(m_idArticle, "id article%03lu", m_compteur++);

    cout << "Constructeur par parametre de l article " << m_idArticle << endl;
}

Article::Article(const Article &source)
{
    allocationMemoire();

    setNomArticle(source.m_nomArticle);
    setType(source.m_type);
    setValeur(source.m_valeur);
    setNombre(source.m_nombre);
    sprintf(m_idArticle, "id article%03lu", m_compteur++);

    cout << "Constructeur par recopie de l article" << m_idArticle << endl;
}

Article::~Article()
{
    m_compteur--;

    delete [] m_idArticle;
    delete [] m_nomArticle;
    delete [] m_type;

    cout << "Destructeur de l article " << m_compteur << endl;
}
//--------------------------------------------------------------------------------------------------
char *Article::getIdArticle () const
{
    if(!m_idArticle)
        return 0;
    else
    {
        char *aidArticle = new char  [BUFFERSIZE];
        strncpy(aidArticle, m_idArticle, BUFFERSIZE);
        return aidArticle;
    }
}

char *Article::getNomArticle() const
{
    if(!m_nomArticle)
        return 0;
    else
    {
        char *anomArticle= new char [BUFFERSIZE];
        strncpy(anomArticle, m_nomArticle, BUFFERSIZE);
        return anomArticle;
    }
}

char *Article::getType() const
{
    if(!m_type)
        return 0;
    else
    {
        char *atype= new char [BUFFERSIZE];
        strncpy(atype, m_type, BUFFERSIZE);
        return atype;
    }
}

unsigned int Article::getValeur() const
{
    return m_valeur;
}

unsigned int Article::getNombre() const
{
    return m_nombre;
}

//---------------------------------------------------------------------------------------------------
void Article::setIdArticle(const char *idArticle)
{
    if(!idArticle)
        m_idArticle [0] = 0;
    else
    {
        strncpy(m_idArticle, idArticle, BUFFERSIZE);
        m_idArticle [BUFFERSIZE-1] = 0;
    }
}

void Article::setNomArticle(const char *nomArticle)
{
    if(!nomArticle)
        m_nomArticle [0] = 0;
    else
    {
        strncpy(m_nomArticle, nomArticle, BUFFERSIZE);
        m_nomArticle [BUFFERSIZE-1] = 0;
    }
}

void Article::setType(const char *type)
{
    if(!type)
        m_type [0] = 0;
    else
    {
        strncpy(m_type, type, BUFFERSIZE);
        m_type [BUFFERSIZE-1] = 0;
    }
}

void Article::setValeur(unsigned int valeur)
{
    m_valeur=valeur;
}

void Article::setNombre(unsigned int nombre)
{
    m_nombre=nombre;
}

//--------------------------------------------------------------------------------------------------------
void Article::allocationMemoire()
{
    m_idArticle = new char [BUFFERSIZE];
    m_nomArticle = new char [BUFFERSIZE];
    m_type = new char [BUFFERSIZE];
}

//-----------------------------------------------------------------------------------------------------------
ostream & operator<< (ostream &os, const Article &art)
{
    os << "Article : " << art.getNomArticle() << endl;
    os << "Type d article : " << art.getType() << endl;
    os << "Valeur : " << art.getValeur() << endl;
    os << "Nombre : " << art.getNombre();

    return os;
}

//-----------------------------------------------------------------------------------------------------------
Article & Article::operator= (Article &source)
{
    if(this==&source)
        return(*this);
    else
    {
        setIdArticle(source.m_idArticle);
        setNomArticle(source.m_nomArticle);
        setType(source.m_type);
        setValeur(source.m_valeur);
        setNombre(source.m_nombre);
    }
    return (*this);
}

Article & Article::operator= (int zero)
{
    if(zero == 0)
    {
        setIdArticle("\0");
        setNomArticle("\0");
        setType("\0");
        setNombre(0);
        setValeur(0);
    }
    return (*this);
}
