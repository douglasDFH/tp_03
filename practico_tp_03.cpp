#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string nombre;
// Funci�n para sumar los n�meros de una cadena
int suma_cadena(string cadena) {
	int suma = 0;
	stringstream ss(cadena); // Crear un flujo de entrada con la cadena
	string token; // Variable para almacenar cada n�mero
	while (getline(ss, token, '+')) { // Separar la cadena por el signo +
		suma += stoi(token); // Convertir el n�mero a entero y sumarlo
	}
	return suma; // Devolver la suma
}

// Funci�n para invertir el orden de las palabras de un nombre completo
string nombre_completo(string nombre) {
	
	int espacio = nombre.find (" ");
	string apellido = nombre.substr (0, espacio);
	string resto = nombre.substr (espacio + 1);
	return resto + " " + apellido;
}
// Funci�n para ofuscar una cadena seg�n la tabla dada
string string_ofuscar(string cadena) {
	string ofuscado = " "; // Variable para almacenar la cadena ofuscada
	for (char c : cadena) { // Recorrer cada caracter de la cadena
		switch (c) { // Seg�n el caracter, aplicar la ofuscaci�n correspondiente
		case 'A': case 'a': ofuscado += '4'; break;
		case 'E': case 'e': ofuscado += '3'; break;
		case 'I': case 'i': ofuscado += '1'; break;
		case 'O': case 'o': ofuscado += '0'; break;
		case 'S': case 's': ofuscado += '5'; break;
		case 'T': case 't': ofuscado += '7'; break;
		default: ofuscado += c; // Si no es ninguno de los anteriores, mantener el mismo caracter
		}
	}
	return ofuscado; // Devolver la cadena ofuscada
}

// Funci�n para mostrar el men� principal y leer la opci�n elegida
int menu_principal() {
	int opcion = 0; // Variable para almacenar la opci�n elegida
	cout << "*BIENVENIDO AL MENU PRINCIPAL*\n";
	cout << "------------------------------"<<endl;
	cout << "--  1) SUMA DE CADENA      ---\n";
	cout << "--  2) NOMBRE COMPLETO     ---\n";
	cout << "--  3) PALABRA PARA OFUSCAR---\n";
	cout << "--  4) SALIR DEL MENU    ---\n";
	cout << "------------------------------"<<endl;
	cout << "  Elija una opci�n: ";
	cin >> opcion; // Leer la opci�n del teclado
	return opcion; // Devolver la opci�n
}

// Funci�n para mostrar el submen� de la opci�n 1 y leer la cadena a sumar
string submenu_1() {
	string cadena = ""; // Variable para almacenar la cadena a sumar
	cout <<endl;
	cout << "------------------------------------------------------\n";
	cout << "---     Submen� de la opci�n 1 suma de cadenas   ----- \n";
	cout << "--Ingrese una cadena de n�meros separados por el signo +:";         
	
	cin >> cadena; // Leer la cadena del teclado
	return cadena; // Devolver la cadena
}

// Funci�n para mostrar el submen� de la opci�n 2 y leer el nombre completo
string submenu_2() {
	string nombre = ""; // Variable para almacenar el nombre completo
	cout <<endl;
	cout << "-------------------------------------------------------\n";
	cout << "---      Submen� de la opci�n 2 Nombre Completo     ---\n";
	cout << "- Ingrese un nombre completo para cambiar de posicion : ";
	cin.ignore(); // Ignorar el salto de l�nea anterior
	getline(cin, nombre); // Leer el nombre completo del teclado
	return nombre; // Devolver el nombre
}

// Funci�n para mostrar el submen� de la opci�n 3 y leer la cadena a ofuscar
string submenu_3() {
	string cadena = ""; // Variable para almacenar la cadena a ofuscar
	cout <<endl;
	cout << "-------------------------------------------------------\n";
	cout << "---   Submen� de la opci�n 3 palabra para Ofuscar   ---\n";
	cout << "-------------------------------------------------------\n";
	cout << "-------------|   CARACTER   |  OFUSCADO   |------------\n";
	cout << "-------------|----------------------------|------------\n";
	cout << "-------------|     A/a      |     4       |------------\n";
	cout << "-------------|--------------|-------------|------------\n";
	cout << "-------------|     E/e      |     3       |------------\n";
	cout << "-------------|--------------|-------------|------------\n";
	cout << "-------------|     I/i      |     1       |------------\n";
	cout << "-------------|--------------|-------------|------------\n";
	cout << "-------------|     O/O      |     0       |------------\n";
	cout << "-------------|--------------|-------------|------------\n";
	cout << "-------------|     S/s      |     5       |------------\n";
	cout << "-------------|--------------|-------------|------------\n";
	cout << "-------------|     T/t      |     7       |------------\n";
	cout << "-------------|--------------|-------------|------------\n";
	cout << "Ingrese una cadena a ofuscar: ";
	cin >> cadena; // Leer la cadena del teclado
	return cadena; // Devolver la cadena
}

// Programa principal
int main() {
	int opcion = 0; // Variable para almacenar la opci�n del men� principal
	string cadena = ""; // Variable para almacenar la cadena del submen�
	int resultado = 0; // Variable para almacenar el resultado de la suma de cadena
	string invertido = ""; // Variable para almacenar el nombre completo invertido
	string ofuscado = ""; // Variable para almacenar la cadena ofuscada
	bool salir = false; // Variable para controlar el bucle del men� principal
	while (!salir) { // Mientras no se elija salir
		opcion = menu_principal(); // Mostrar el men� principal y leer la opci�n
		switch (opcion) { // Seg�n la opci�n elegida
		case 1: // Si es la opci�n 1
			cadena = submenu_1(); // Mostrar el submen� de la opci�n 1 y leer la cadena
			resultado = suma_cadena(cadena); // Calcular la suma de la cadena
			cout << endl;
			cout << "   *** La suma de la cadena " << cadena << " es " << resultado <<"\n"; // Mostrar el resultado
			cout << endl ;
			break;
		case 2: // Si es la opci�n 2
			nombre = submenu_2(); // Mostrar el submen� de la opci�n 2 y leer el nombre
			invertido = nombre_completo(nombre); // Invertir el orden de las palabras del nombre
			cout <<endl;
			cout << "*** El nombre completo " << nombre << " invertido es " << invertido << "\n"; // Mostrar el nombre invertido
			cout <<endl;
			break;
		case 3: // Si es la opci�n 3
			cadena = submenu_3(); // Mostrar el submen� de la opci�n 3 y leer la cadena
			ofuscado = string_ofuscar(cadena); // Ofuscar la cadena seg�n la tabla
			cout << endl;
			cout << "La cadena " << cadena << " ofuscada es " << ofuscado << "\n"; // Mostrar la cadena ofuscada
			cout << endl;
			break;
		case 4: // Si es la opci�n 4
			salir = true; // Cambiar la variable salir a verdadero
			cout << "Gracias por usar el programa. Adi�s.\n"; // Mostrar un mensaje de despedida
			break;
		default: // Si no es ninguna de las anteriores
			cout << "Opci�n inv�lida. Intente de nuevo.\n"; // Mostrar un mensaje de error
		}
	}
	return 0; // Terminar�el�programa
 }
