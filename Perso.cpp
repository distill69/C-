#include "Perso.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;


void Perso::viderBuffer()
{
	int c = 0;
	while (c != '\n' && c != EOF)
	{
		c = getchar();
	}
}

char Perso::lireCaractere()
{
	char c;
	cin >> c;
	cin.ignore();
	return c;
}


int Perso::lire(char *chaine, int longueur)
{
	char *positionEntree = NULL;
	if (fgets(chaine, longueur, stdin) != NULL)
	{
		positionEntree = strchr(chaine, '\n');
		if (positionEntree != NULL)
		{
			*positionEntree = '\0';
		}
		else
		{
			viderBuffer();
		}
		return 1;
	}
	else
	{
		viderBuffer();
		return 0;
	}
}

long Perso::lireLong()
{
	char nombreTexte[100] = {0}; // 100 cases devraient suffire

	if (lire(nombreTexte, 100))
	{
		// Si lecture du texte ok, convertir le nombre en long et le retourner
		return strtol(nombreTexte, NULL, 10);
	}
	else
	{
		// Si probl�me de lecture, renvoyer 0
		return 0;
	}
}


int Perso::lireInt()
{
	char nombreTexte[100] = {0}; // 100 cases devraient suffire

	if (lire(nombreTexte, 100))
	{
		// Si lecture du texte ok, convertir le nombre en long et le retourner
		return atoi(nombreTexte);
	}
	else
	{
		// Si probl�me de lecture, renvoyer 0
		return 0;
	}

}

int Perso::lireInt09()
{
    int i;
    do
    {
        i=lireInt();
        if(i!=0 && i!=1 && i!=2 && i!=3 && i!=4 && i!=5 && i!=6 && i!=7 && i!=8 && i!=9)
            printf("\nNombre negatif, trop eleve ou mauvaix caractere... Reessayer svp");

    }while(i!=0 && i!=1 && i!=2 && i!=3 && i!=4 && i!=5 && i!=6 && i!=7 && i!=8 && i!=9);

    return i;

}


int Perso::continuer()
{
	char c;

	do
	{
		printf("\n Voulez-vous continuer ? (O/N)");
		c=lireCaractere();
	}while( c!='o' && c!='n' && c!='O' && c!='N');

	if ( c=='o' || c=='O')
		return 1;
	else
		return 0;
}

float Perso::lireFloat()
{
  	char nombreTexte[100] = {0}; // 100 cases devraient suffire

	if (lire(nombreTexte, 100))
	{
		// Si lecture du texte ok, convertir le nombre en long et le retourner
		return strtof(nombreTexte, NULL);
	}
	else
	{
		// Si probl�me de lecture, renvoyer 0
		return 0;
	}

}

void Perso::initString(char *string, int sizeString)
{
    int i=0;
    for(i=0;i<sizeString;i++)
        string[i]=0;
    string[sizeString-1]='\0';
}
