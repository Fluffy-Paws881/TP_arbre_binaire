#include "tree.h"
#include <stdio.h>
#include <string.h>
/*tree::tree()
{
	taille = 0;
	racine = NULL;
}*/

tree::tree(noeud* n)
{
	taille = 1;
	racine = n;
	coteDroit = 0;
	coteGauche = 0;
}

tree::~tree()
{
}

noeud* tree::getRacine()
{
	return racine;
}

void tree::addTree(noeud* n, noeud* elementActuel)
{
	if (racine != NULL)
	{

		if (n->value <= elementActuel->value)
		{
			if (elementActuel->fGauche == NULL)
			{
				elementActuel->fGauche = n;

				if (n->value <= racine->value)
				{
					coteGauche += 1;
				}
				else
				{
					coteDroit += 1;
				}

			}
			else {
				addTree(n, elementActuel->fGauche);
			}

		}
		else {
			if (elementActuel->fDroit == NULL)
			{
				elementActuel->fDroit = n;

				if (n->value <= racine->value)
				{
					coteGauche += 1;
				}
				else
				{
					coteDroit += 1;
				}

			}
			else {
				addTree(n, elementActuel->fDroit);
			}
		}
	}

}

void tree::recurs(noeud* n)
{
	if (n != NULL)
	{
		printf("%d \n", n->value);

		recurs(n->fGauche);
		recurs(n->fDroit);
	}


}

noeud* tree::successeur(noeud* n)
{
	noeud* courant = n;
	noeud* prede;
	while (courant->fGauche != NULL)
	{
		prede = courant;
		courant = courant->fGauche;
		if (courant->fGauche == NULL)
		{
			prede->fGauche = NULL;
		}
	}
	return courant;
}



void tree::suppression(int x, noeud* elementActuel)
{
	if (racine != NULL)
	{
		noeud* succ = new noeud;
		noeud* suppr = new noeud;
		if (x <= elementActuel->value)
		{
			if (elementActuel->fGauche->value == x)
			{
				suppr = elementActuel->fGauche;
				if (suppr->fDroit != NULL)
				{
					succ = successeur(suppr->fDroit);
				}
				else if (suppr->fGauche != NULL)
				{
					succ = successeur(suppr->fGauche);
				}
				else {
					delete suppr;
					elementActuel->fGauche = NULL;
					coteGauche -= 1;
					return;
				}

				if (suppr->fDroit != NULL && suppr->fDroit != succ)
				{
					succ->fDroit = suppr->fDroit;
				}
				if (suppr->fGauche != NULL && suppr->fGauche != succ)
				{
					succ->fGauche = suppr->fGauche;
				}

				elementActuel->fGauche = succ;

				if (suppr->value <= racine->value)
				{
					coteGauche -= 1;
				}
				else
				{
					coteDroit -= 1;
				}
				delete suppr;
			}
			else {
				suppression(x, elementActuel->fGauche);
			}

		}
		else {
			if (elementActuel->fDroit->value == x)
			{
				suppr = elementActuel->fDroit;
				if (suppr->fDroit != NULL)
				{
					succ = successeur(suppr->fDroit);
				}
				else if (suppr->fGauche != NULL)
				{
					succ = successeur(suppr->fGauche);
				}
				else {
					delete suppr;
					elementActuel->fDroit = NULL;
					coteDroit -= 1;
					return;
				}

				if (suppr->fDroit != NULL && suppr->fDroit != succ)
				{
					succ->fDroit = suppr->fDroit;
				}
				if (suppr->fGauche != NULL && suppr->fGauche != succ)
				{
					succ->fGauche = suppr->fGauche;
				}

				elementActuel->fDroit = succ;
				if (suppr->value <= racine->value)
				{
					coteGauche -= 1;
				}
				else
				{
					coteDroit -= 1;
				}
				delete suppr;
			}
			else {
				suppression(x, elementActuel->fDroit);
			}
		}
	}
}

void tree::equilibre()
{
	int x = coteGauche - coteDroit;

	if (x >= -1 && x <= 1)
	{
		printf(" l'arbre est equilibre : cote gauche %d noeud, cote droit %d noeud \n", coteGauche, coteDroit);
	}
	else {
		printf(" l'arbre est desequilibre : cote gauche %d noeud, cote droit %d noeud \n", coteGauche, coteDroit);
	}
}

/*void tree::equilibrage()
{

	int x = coteGauche - coteDroit;
	noeud* actuel;
	noeud* prede;

	while (x < -1 || x > 1)
	{
		if (coteGauche > coteDroit)
		{
			actuel = racine->fGauche;
			prede = actuel;

			while (actuel->fGauche != NULL && actuel->fDroit != NULL)
			{
				if (actuel->fDroit != NULL)
				{
					actuel = actuel->fDroit;

					if (actuel->fDroit != NULL)
					{
						prede->fDroit = NULL;
					}
				}
				else {
					actuel = actuel->fGauche;

					if (actuel->fGauche != NULL )
					{
						prede->fGauche = NULL;
					}
				}


			}


			addTree(actuel, racine->fDroit);

			coteGauche--;
			coteDroit++;

		}else {

			actuel = racine->fDroit;
			prede = actuel;

			while (actuel->fGauche != NULL && actuel->fDroit != NULL)
			{
				if (actuel->fGauche != NULL)
				{
					actuel = actuel->fGauche;

					if (actuel->fGauche != NULL && actuel->fDroit != NULL)
					{
						prede->fGauche = NULL;
					}
				}
				else {
					actuel = actuel->fDroit;

					if (actuel->fGauche != NULL && actuel->fDroit != NULL)
					{
						prede->fDroit = NULL;
					}
				}


			}

			addTree(actuel, racine->fGauche);
			coteGauche++;
			coteDroit--;
		}
		x = coteGauche - coteDroit;

	}
}*/
