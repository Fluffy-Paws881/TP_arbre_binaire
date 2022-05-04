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

	racine = n;
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


			}
			else {
				addTree(n, elementActuel->fGauche);
			}

		}
		else {
			if (elementActuel->fDroit == NULL)
			{
				elementActuel->fDroit = n;

				

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
				
				delete suppr;
			}
			else {
				suppression(x, elementActuel->fDroit);
			}
		}
	}
}

int tree::equilibre(noeud* n)
{
	

	if (n == NULL || n == racine)
	{
		return 0;
		
	}
	return 1 + equilibre(n->fGauche) + equilibre(n->fDroit);

}

void tree::rotation()
{

	noeud* noeudRemplace;
	int cg = equilibre(racine->fGauche);
	int cd = equilibre(racine->fDroit);
	int x = cg - cd;
	
	if (x > 1 || x < -1)
	{
		if (cg > cd)
		{
			//rotation à droite
			noeudRemplace = racine->fGauche;
			racine->fGauche = noeudRemplace->fDroit;
			noeudRemplace->fDroit = racine;


		}
		else {

			//rotation à gauche
			noeudRemplace = racine->fDroit;
			racine->fDroit = noeudRemplace->fGauche;
			noeudRemplace->fGauche = racine;

		}

		racine = noeudRemplace;
	}




	
}
