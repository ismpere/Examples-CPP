//Ismael Perez Martin
#include<iostream>
using namespace std;

//Declaro las funciones
void pide_numeros(int&, int&);
int menu(void);
void busca_pares(int, int);
int suma_intervalo(int, int);
double media_intervalo(int, int);

int main(){
  int n1, n2, op; //Definimos las variables que almacenan los numeros y la opcion

  pide_numeros(n1, n2);
  if(n2<n1){
    cout << "El segundo numero debe ser mayor que el primero";
    return 0;
  }
  //Ejecutamos el bucle hasta que elija la opcion 0
  while(true){
    op = menu();
    cout << "\n";
    switch(op){
      case 0:
        cout << "Finaliza el programa.\n";
        return 0;
      case 1:
        cout << "La suma de todos los numeros en el intervalo [" << n1 << ", " << n2 << "] es: "
        << suma_intervalo(n1,n2) << "\n";
        break;
      case 2:
        busca_pares(n1,n2);
        break;
      case 3:
        cout << "La media del intervalo [" << n1 << ", " << n2 << "] es: "
        << media_intervalo(n1,n2) << "\n";
        break;
      case -1:
        cout << "La opcion introducida no es valida.\n";
    }
  }
  return 0;
}
int menu(){
  char opcion;
  cout << "Introduzca el numero de opcion que desee:\n";
  cout << "- 0 => Finalizar\n";
  cout << "- 1 => Sumar todos los numeros en el intervalo introducido, ambos incluidos.\n";
  cout << "- 2 => Mostrar los pares en el intervalo introducido.\n";
  cout << "- 3 => Calcular la media de los numeros en el intervalo introducido.\n";

  cin >> opcion;
  int op = opcion - 48; //Saco el valor en ascii del caracter y le resto 48 para que tome su valor en entero,
  if(op > 3 || op < 0){ //por lo que si no es un numero entero, o no esta entre [0,3], se sale del rango y
    op = -1;            //devuelve -1 como codigo de error
  }
  return op;
}
void pide_numeros(int& a, int& b){
  int c,d;
  cout << "Introduzca el primer numero entero: ";
  cin >> a;
  cout << "Introduzca el segundo numero entero: ";
  cin >> b;
}
int suma_intervalo(int a, int b){
   int suma=a;
   for(int i=a+1; i<=b; i++){
     suma=(suma+i);
   }
   return suma;
}
void busca_pares(int a, int b){
  cout << "Los numeros pares en el intervalo [" << a << ", " << b << "] son: ";
  if(a%2!=0){
    a++;
  }
  cout << a;
  for(int i=a+1; i<=b; i++){
    if(i%2==0){
      cout << ", " << i;
    }
  }
  cout << ".\n";
}
double media_intervalo(int a, int b){
  return (double(suma_intervalo(a,b))/double((b-(a-1))));
}
