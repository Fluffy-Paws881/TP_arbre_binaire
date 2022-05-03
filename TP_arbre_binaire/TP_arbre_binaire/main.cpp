
#include "tree.h"
#include <iostream>
#include <string>

int main()
{
	/*myListe p1;

	p1.addFirst(11);
	p1.addFirst(12);
	p1.addFirst(1);
	p1.addFirst(2);
	p1.addFirst(3);
	p1.addFirst(4);

	//p1.addPosition(8, 2);
	//p1.supprimerPos(3);

	p1.empty();

	p1.affiche();*/

	noeud* x = new noeud;
	x->fDroit = NULL;
	x->fGauche = NULL;
	x->value = 4;

	noeud* y = new noeud;
	y->fDroit = NULL;
	y->fGauche = NULL;
	y->value = 0;

	noeud* a = new noeud;
	a->fDroit = NULL;
	a->fGauche = NULL;
	a->value = 16;

	noeud* b = new noeud;
	b->fDroit = NULL;
	b->fGauche = NULL;
	b->value = 3;

	noeud* c = new noeud;
	c->fDroit = NULL;
	c->fGauche = NULL;
	c->value = 4;

	noeud* d = new noeud;
	d->fDroit = NULL;
	d->fGauche = NULL;
	d->value = 5;

	noeud* e = new noeud;
	e->fDroit = NULL;
	e->fGauche = NULL;
	e->value = 6;

	noeud* f = new noeud;
	f->fDroit = NULL;
	f->fGauche = NULL;
	f->value = 7;

	noeud* g = new noeud;
	g->fDroit = NULL;
	g->fGauche = NULL;
	g->value = 8;

	tree p1(x);



	p1.addTree(g, p1.getRacine());
	p1.addTree(f, p1.getRacine());
	p1.addTree(e, p1.getRacine());
	p1.addTree(y, p1.getRacine());
	p1.addTree(a, p1.getRacine());
	p1.addTree(b, p1.getRacine());
	p1.addTree(c, p1.getRacine());
	p1.addTree(d, p1.getRacine());




	//p1.suppression(7, p1.getRacine());
	//p1.suppression(8, p1.getRacine());
	//p1.suppression(0, p1.getRacine());

	p1.recurs(p1.getRacine());
	//	p1.equilibrage();
	p1.equilibre();








	return 0;
}