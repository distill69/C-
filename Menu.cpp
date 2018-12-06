#include "Menu.h"


using namespace std;

Societe Menu::choixSociete()
{
    int choix(0);
    Societe societe3;
    Perso perso;

    do
    {
        cout << "Que voulez vous?" << endl;
        cout << "\t1. Choisir un magasin existant" << endl;
        cout << "\t2. Encoder un nouveau magasin" << endl;

        choix = perso.lireInt();

        switch(choix)
        {
        case 1:
            {
                int choix2(0);
                Societe societe1("Makkro", "Liege", 4000);
                Societe societe2("SHS", "Huy", 4100);

                do
                {
                    cout << "\t1. Makkro" << endl;
                    cout << "\t2. SHS" << endl;
                    choix2 = perso.lireInt();
                    if(choix2==1)
                        return societe1;
                    else if(choix2==2)
                        return societe2;

                }while(choix2!=1 && choix!=2);

            }
            break;
        case 2:
            {
                societe3.creationSociete(&societe3);
                return societe3;
            }
            break;

        default:
            cout << "Mauvaix choix...";
        }

    }while(choix!=1 || choix!=2);

}

Panier Menu::menuPanier()
{
    system("cls");
    Panier panier;
    Perso perso;

    int choix(0);

    Article art1("Playstation", "Console", 400, 1);
    Article art2("Alienware", "PC", 1400, 1);
    Article art3("Ipad", "Tablette", 1000, 1);

    panier.ajoutArticlePanier(art1, 0);
    panier.ajoutArticlePanier(art2, 1);
    panier.ajoutArticlePanier(art3, 2);


    do
    {

        cout << endl << endl << "\t\tMenu Panier" << endl << endl;
        cout << "Nombre d'objet dans votre panier : " << panier.getNbArticlePanier() << endl;
        cout << "Valeur totale de votre panier : " << panier.getValeur() << endl << endl;

        cout << "\t1. Acheter les articles " << endl;
        cout << "\t2. Remettre le panier a 0" << endl;
        cout << "\t3. Calculer le prix avec TVA" << endl;
        cout << "\t9. Quitter" << endl;

        choix = perso.lireInt();


        switch(choix)
        {
        case 1:
            {
                system("cls");
                for(int i=0; i<NBSLOTPANIER; i++)
                {
                    cout << "Voici les aticles selectionnes : " << endl << endl;
                    cout << *panier.getArticle(i) << endl;
                    panier.setValeur(panier.getArticle(0)->getValeur() + panier.getArticle(1)->getValeur() + panier.getArticle(2)->getValeur());
                    panier.setNbArticlePanier(NBSLOTPANIER);

                }
                cin.get();
                cin.ignore(10000, '\n');
            }
            break;
        case 2:
                panier = 0;
            break;
        case 3:
            {
                system("cls");
                cout << "\t\t\tTOTAL de vos achats" << endl << endl;
                cout << "Vous avez achete pour " << panier.getValeur() << " euros" << endl;
                cout << "Ce qui vous fait un total de " << panier.getValeur() * 1.21 << " euros TVAC" << endl << endl;
                cin.get();
                cin.ignore(10000, '\n');
            }
            break;
        case 9:
            break;
        default:
            cout << "Mauvaix choix...";
        }

    }while(choix!=9);

    return panier;
}

void Menu::menuPrincipal()
{
    cout << "\t\tBienvenue" << endl;

    int choix(0);
    Perso perso;

    do
    {
        cout << endl << "1. Choisir ou creer un magasin" << endl;
        cout << "9. Quitter..." << endl;

        choix = perso.lireInt();

        switch(choix)
        {
        case 1:
            {
                Societe societe = choixSociete();
                cout << endl << "Vous avez choisi la societe : " << endl << societe << endl;
                cin.get();
                cin.ignore(10000, '\n');

                system("cls");

                Acheteur acheteur;
                acheteur.creationAcheteur(acheteur);

                system("cls");
                perso.viderBuffer();
                cout << "Vous etes : " << endl << endl;
                cout << acheteur;
                cin.get();
                cin.ignore(10000, '\n');

                Panier panier = menuPanier();

                system("cls");
                cout << "L acheteur : " << acheteur.getNomAcheteur() << " a achete dans le magasin : " << societe.getNom() << " les articles suivants :" << endl << endl;
                for(int i=0; i<NBSLOTPANIER; i++)
                {
                    cout << *panier.getArticle(i) << endl;
                }

            }
            break;
        case 9:
            cout << "Au revoir..." << endl;
            break;

        default:
            cout << "Mauvaix choix..." << endl;
        }
    }while(choix!=9);

}
