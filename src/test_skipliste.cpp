#include "skip_liste.hpp"

#include <cassert>
#include <random>

int main() { 

  { //insertion en s'assurant du tri
    SkipListe sl ;

    for(int i = 20; i >= 0; --i) {
      sl.inserer(i) ;
    }

    /*for(int j=0; j<=20 ; j++)
    {
      sl.inserer(j);
    }*/
    //sl.afficher() ;
    //sl.inserer(50);
    //assert(sl.test_tri()) ;
    //sl.ajouter_niveau();
    sl.inserer(50);
    sl.inserer(100);
    sl.inserer(89);
    sl.afficher();
    sl.ajouter_niveau();
    sl.afficher();
  }

  { //insertion en n'assurant plus le tri
    SkipListe sl ;

    //generateurs aleatoires
    std::default_random_engine rd ;
    std::uniform_int_distribution<int> rand_int(0,99) ;

    for(int i = 20; i >= 0; --i) {
      sl.inserer(rand_int(rd)) ;
    }
    sl.afficher() ;

    assert(sl.test_tri()) ;
  }
  
}
