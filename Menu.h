#ifndef MENU_H
#define MENU_H


#include <iostream>

#include "Article.h"
#include "Societe.h"
#include "Panier.h"
#include "Perso.h"


class Menu
{
public:

    Societe choixSociete();//Methode permettant de choisir sa societe

    Panier menuPanier();//Menu concernant le panier

    void menuPrincipal();//Menu principal
};

#endif // MENU_H
