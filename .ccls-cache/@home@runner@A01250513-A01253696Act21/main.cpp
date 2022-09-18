/*
Escribe un programa en C++ que reciba el nombre de un archivo de texto, seguido de un
entero n, donde n es un entero múltiplo de 4 y  (16 <= n <=64)
La salida es una cadena que es la representación hexadecimal del resultado de aplicar
una función hash al archivo de texto recibido. La función hash se explica a continuación:
El número entero n determina el número de columnas que contendrá una tabla donde se irán
acomodando los caracteres del archivo de texto (incluyendo los saltos de línea),
utilizando para ello los renglones que sean necesarios.
Si el número de caracteres en el archivo de entrada no es múltiplo de n, el último
renglón se deberá rellenar con tantos caracteres 'a' como sea necesario para completar 
dicho renglón.
Para cada renglón, se deberá aplicar la siguiente función hash:  H(renglón) = (la suma 
de los ASCII de cada caracter en el renglón) % 256.
La salida se genera concatenando la representación hexadecimal (mayúsculas) a dos
dígitos de cada renglón.
Tu programa debe ser llamado main.cpp y debe compilar utilizando el comando g++ en un
ambiente linux.
Tu programa debe poder ejecutarse utilizando entrada y salida redireccionada en un
ambiente linux 
(./main < in.txt > out.txt)
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "hashstring.h"
using namespace std;

/* 
Nuestra funcion ready_file() se encarga de prepara nuestro archivo de texto para poder hashearlo
Su complejidad seriade O(m) donde m es la cantidad de caracteres en el texto.
*/
string ready_file(string f_name, int n){
  string text;
  string line;
  ifstream fl(f_name);
  
  if (!fl.is_open())
      cout << "failed to open file\n";
  
  while(getline (fl,line)){
    text.append(line);
    text.append("\n");
  }
  
  int tmiss = text.length() % n;

  if(tmiss != 0){
    for(long long unsigned int i = 0; i < n - tmiss;i++){
      text.append("a");
    }
  }
  
  return text;
}

/*
Driver Code
*/
int main() {

  string text;
  int n;

  cin>>text>>n;

  text = ready_file(text, n);
  cout<<hashing(text,n);
}