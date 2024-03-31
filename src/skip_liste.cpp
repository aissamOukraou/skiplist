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


  if(m_sentinelle->suivante.size() >=2 )
  {

    SkipCellule* nouveauElement= new SkipCellule(v);

    int i=m_sentinelle->suivante.size()-1;

    SkipCellule* elementActuel= m_sentinelle->suivante[i];
    SkipCellule* actuelHorizental=nullptr;

    SkipCellule* elementPrecedent=nullptr;

    //SkipCellule* elementPrecedent=nullptr;
    if(elementActuel->valeur == v)
    {
      
    }
    while(elementActuel != nullptr && elementActuel->valeur > v)
    {    
      i--;
      elementActuel=elementActuel->suivante[i];

      actuelHorizental=elementActuel;

    } 
      
    while(actuelHorizental != nullptr && actuelHorizental->valeur < v)
    {
      elementPrecedent=actuelHorizental;

      actuelHorizental=actuelHorizental->suivante[i];

    }

    elementPrecedent->suivante[i]=nouveauElement;
    nouveauElement->suivante[i]=actuelHorizental;

  }

  else 
  {

    if(m_sentinelle->suivante[0] == nullptr)
    {
        SkipCellule* nlle = new SkipCellule(v) ;

        m_sentinelle->suivante[0]=nlle;

    }

    else 
    {
    
      if(v <= m_sentinelle->suivante[0]->valeur )
      {
        SkipCellule* nouveauElement= new SkipCellule(v);

        nouveauElement->suivante[0]=m_sentinelle->suivante[0];
        m_sentinelle->suivante[0]=nouveauElement;
      }
      else if(v > m_sentinelle->suivante[0]->valeur)
      {
        //std::cout <<" Dans le bout ou il y a le while"<<std::endl;
        SkipCellule* nlle = new SkipCellule(v) ;

        SkipCellule* elementActuel= m_sentinelle->suivante[0];
        //elementActuel=elementActuel->suivante[0];
        SkipCellule* elementPrecedent= nullptr;

        while(elementActuel != nullptr && elementActuel->valeur < v )
        {
    
          elementPrecedent=elementActuel;

          elementActuel=elementActuel->suivante[0];

        }
        elementPrecedent->suivante[0]=nlle;
        nlle->suivante[0]=elementActuel;  
      }  
    }
  }  
  
  

  /* pour trier : avancer dans la liste jusqu'a trouver une valeur plus grande
   * ou la fin de la liste, en gardant le curseur sur la precedente. Une fois arrive
   * sur la celule plus grande ou la fin de la liste, il faut inserer apres le
   * curseur (un peu comme au dessus pour inserer apres la sentinelle).
   *
   * initialiser un curseur sur la sentinelle
   * Tant que le curseur a une cellule suivante et que sa valeur est plus petite que v {
   *    avancer le curseur sur sa suivante
   * }
   * inserer apres le curseur
   *
   * */
}

SkipCellule* SkipListe::chercher(int v) {

  SkipCellule* elementActuel=m_sentinelle->suivante[0];

  while(v != elementActuel->valeur && elementActuel != nullptr)
  {

    elementActuel=elementActuel->suivante[0];

  }
  /* cette recherche ne fait rien, c'est votre travail de coder cette fonction */

  return elementActuel ;

  /* pour chercher dans une liste triee : avancer dans la liste tant qu'on est
   * sur une valeur strictement plus petite. Si on arrive sur une valeur égale,
   * on a trouve, si on arrive sur la fin de la liste ou une valeur plus grande,
   * on ne trouvera pas plus loin car la liste est (devrait etre) triee.
   *
   * initialiser un curseur sur la sentinelle
   * Tant que le curseut a uns cellule suivante et que sa valeur est plus petite que v {
   *   avancer le curseur sur sa suivante
   * }
   * Si le curseur n'est pas la sentinelle et a la valeur v
   *   le retourner
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
  std::cout <<std::endl;

  if(m_sentinelle->suivante.size()==2)
  {
    SkipCellule* niveau=m_sentinelle->suivante[1];

    while(niveau != nullptr)
    {
      std::cout <<niveau->valeur<<" ";

      niveau=niveau->suivante[1];

    }

  std::cout << "]" << std::endl ;
  }
}  

bool SkipListe::pile_ou_face() {
  //lancer la piece
  return m_piece(m_random) ;

}
void SkipListe::ajouter_niveau()
{

  m_sentinelle->suivante.push_back(nullptr); //on ajoute un deuxieme niveau

  m_sentinelle->suivante[1]=nullptr; //on met le nouveau niveau a zero

  SkipCellule* elementActuel= m_sentinelle->suivante[0]; 

  SkipCellule* elementPrecedent=m_sentinelle;

  while(elementActuel != nullptr)
  {
    if(pile_ou_face())
    {
      elementActuel->suivante.push_back(nullptr);

      elementPrecedent->suivante[1]=elementActuel;

      elementPrecedent=elementActuel;
    }
    elementActuel=elementActuel->suivante[0];
  } 

}
