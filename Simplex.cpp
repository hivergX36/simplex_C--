#include <iostream>
#include "Simplex.hpp"


int main(){
    std::string file = "data.txt";

   Simplexe simplex = Simplexe(file);
   simplex.display_simplex();
   simplex.fill_dictionnary();
   simplex.display_dictionnary();
   simplex.resolve_simplexe();
  simplex.display_dictionnary();



}