#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

/*
Nuestra funcion hashing() cumple 3 diferentes funciones:
1.- Creata una tabla donde las columans son vectores del largo de nuestro valor n y renglones el numero
de caracteres del texto. Se acomodan en la tabla.
2.- Hashea los valores de cada renglon con la funcion hash: H(renglón) = (la suma de los ASCII de cada caracter en el renglón) % 256.
3.- Crea un string con la representación hexadecimal (mayúsculas) a dos dígitos de cada renglón.
Su complejidad es de O(n) ya que pasa por cada caracter del texto. 
*/
string hashing(string inputtext, int n){
  int renglon, columna = 0;
  vector<char> columnas(n, '\0');
  vector<vector<char>> tabla(inputtext.length() / n, columnas);
  string texto = "";
  unsigned int linea = 0;
  char htexto[20];

  // O(n)
  for(long long unsigned i = 0; i < inputtext.length(); i++){

        tabla[renglon][columna] = inputtext[i];
        columna++;
        if(columna == n){

            columna = 0;
            renglon++;
        }
    }

  for(long long unsigned i = 0; i < tabla.size(); i++){    
      for(long long unsigned j = 0; j < tabla[i].size(); j++)
          linea += (int)tabla[i][j];

      linea = linea % 256;

      sprintf(htexto, "%02X", linea);

      texto.append(htexto);

      linea = 0;
  }
  return texto;
}