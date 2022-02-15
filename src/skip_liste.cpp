#include "skip_liste.hpp"

#include <iostream>

SkipListe::SkipListe() {
  /* la valeur est inutile, mais on met -2147483648 */
  m_sentinelle = new SkipCellule(1<<31) ;
}

SkipListe::~SkipListe() {
  /* destruction recursive via le destructeur de SkipCellule */
  delete m_sentinelle ;
}

void SkipListe::inserer(int v) {
  SkipCellule* nlle = new SkipCellule(v) ;

  /* cette insertion n'est pas triee, c'est votre travail de le faire */
  nlle->suivante[0] = m_sentinelle->suivante[0] ;
  m_sentinelle->suivante[0] = nlle ;

  /* pour trier : avancer dans la liste jusqu'a trouver une valeur plus grande
   * ou la fin de la liste, en gardant le curseur sur la precedente. Une fois arrive
   * sur la celule plus grande ou la fin de la liste, il faut inserer apres le
   * curseur (un peu comme au dessus pour inserer apres la sentinelle).
   *
   * courante <- sentinelle
   * Tant que ( courante->suivante n'est pas la fin de la liste et a une valeur plus petite que v ) {
   *    avancer courante sur sa suivante
   * }
   * inserer apres courante
   *
   * */
}

SkipCellule* chercher(int v) {
  /* cette recherche ne fait rien, c'est votre travail de coder cette fonction */
  return nullptr ;

  /* pour chercher dans une liste triee : avancer dans la liste tant qu'on est
   * sur une valeur strictement plus petite. Si on arrive sur une valeur égale,
   * on a trouve, si on arrive sur la fin de la liste ou une valeur plus grande,
   * on ne trouvera pas plus loin car la liste est (devrait etre) triee.
   *
   * courante <- sentinelle
   * Tant que (courante->suivante n'est pas la fin de la liste et a une valeur plus petite que v ) {
   *   avancer courante sur sa suivante
   * }
   * Si courante n'est pas la sentinelle et a la valeur v
   *   la retourner
   * Sinon
   *   retourner nullptr
   *
   */
}

bool SkipListe::test_tri() {
  //initialisation du curseur
  SkipCellule* courante = m_sentinelle->suivante[0] ;
  while(courante && courante->suivante[0]) {
    //on a deux cellules de suite qui existent
    if(courante->valeur > courante->suivante[0]->valeur) {
      //la premiere a une valeur plus grande que la seconde, ce n'est pas trie
      return false ;
    }
    courante = courante->suivante[0] ;
  }
  return true ;
}

void SkipListe::afficher() {
  std::cout << "[ " ;
  //parcours lineaire du niveau 0
  SkipCellule* courante = m_sentinelle->suivante[0] ;
  while(courante) {
    std::cout << courante->valeur << " " ;
    courante = courante->suivante[0] ;
  }
  std::cout << "]" << std::endl ;
}
