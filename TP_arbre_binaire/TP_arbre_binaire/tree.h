#pragma once
#include "noeud.h"

class tree
{
	noeud* racine;
	int taille, coteGauche, coteDroit;


public:
	/*tree();*/
	tree(noeud* n);
	~tree();

	//renvoie la racine de l'arbre
	noeud* getRacine();
	//ajoute un noeud dans l'arbre en suivant la logique d'arbre binaire
	void addTree(noeud* n, noeud* elementActuel);
	//affiche toute les valeur de l'arbre
	void recurs(noeud* n);
	//fonction qui renvoi le noeud succeseur (valeur la plus petite apres le noeud donné
	noeud* successeur(noeud* n);
	//supprime un noeud en fonction d'une valeur donné
	void suppression(int x, noeud* elementActuel);
	//verifie si l'arbre est equilibré
	void equilibre();

	//void equilibrage();





};