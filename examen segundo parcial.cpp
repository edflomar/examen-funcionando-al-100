#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *i;
	Nodo *d;
};

Nodo *nuevoNodo(int);
void insertarArbol(Nodo *&,int);
void arbolBase(Nodo *&);
void imprimirArbol(Nodo *,int);
void imprimirArbol2(Nodo *,int);
void recorrido(Nodo *&,int [],int&);

int main(){
	/*sol es igual a 1
	aguila es igual a 2*/
	int contador=0, contador2=0;
	Nodo *arbol=NULL;
	int num;//auxiliar para enviar el dato a la funcion
	int arreglo[]={67,43,80,11,55,70,92,5,13,50,56,68,74,90,95};//numeros para generar los nodos que se requieren en el arbol
	int *monedas;//variable tipo puntero para crear arreglo dinamico
	int cantidad=0;//variable para almacenar la cantidad de numeros que almacenara el arreglo
	for(int i=0; i<15; i++){
		num=arreglo[i];
		insertarArbol(arbol,num);
	}
	arbolBase(arbol);
	srand(time(NULL));
	cout<<"\nCuantos numeros desea generar: "; cin>>cantidad;
	monedas = new int[cantidad];
	cout<<"\nNumeros generados: ";
	for(int i=0; i<cantidad; i++){
		monedas[i]=1+rand()%(3-1);//genera numeros aleatorios de 1 y 2 y los inserta en el arreglo
		cout<<monedas[i]<<" ";
	}
	int z=0;
	while(z<cantidad-2){
		recorrido(arbol,monedas,z);
	}
	cout<<"\nImprime el arbol con el numero de veces que cayo en cada estado sol a la izquierda y aguila a la derecha."<<endl;
	imprimirArbol(arbol,contador);
	cout<<"\nImprime el arbol que pidio el profe :v"<<endl;
	imprimirArbol2(arbol,contador);
	getch();
	return 0;
}

Nodo *nuevoNodo(int dato){
	Nodo *nNodo = new Nodo();
	nNodo->dato=dato;
	nNodo->d=NULL;
	nNodo->i=NULL;
	
	return nNodo;
}
//funcion para generar el arbol con los nodos necesarios
void insertarArbol(Nodo *&arbol,int dato){
	if(arbol==NULL){
		Nodo *nuevoNodo2 = nuevoNodo(dato);
		arbol = nuevoNodo2;
	}else if(dato < arbol->dato){
		insertarArbol(arbol->i,dato);
	}else{
		insertarArbol(arbol->d,dato);
	}
}
//iguala todos los datos de los nodos a 0 para despues poder ir sumando las veces que la moneda cae aguila o sol en nodo izquierdo y derecho
void arbolBase(Nodo *&arbol){
	if(arbol == NULL){
		return;
	}else{
		arbolBase(arbol->d);
		arbol->dato=0;
		arbolBase(arbol->i);
	}
	
}
//imprime el arbol y en cada nodo imprime el numero de veces que cayo aguila o sol en el nivel que representa tirada 1, 2 y 3
void imprimirArbol(Nodo *arbol,int contador){
	if(arbol == NULL){
		return;
	}else{
		imprimirArbol(arbol->d,contador+1);
		for(int i=0; i<contador; i++){
			cout<<"       ";
		}
		cout<<arbol->dato*3<<endl<<endl;
		imprimirArbol(arbol->i,contador+1);
	}
	
}
//imprime el arbol que pidio el profesor 
void imprimirArbol2(Nodo *arbol,int contador){
	if(arbol == NULL){
		return;
	}else{
		imprimirArbol(arbol->d,contador+1);
		for(int i=0; i<contador; i++){
			cout<<"       ";
		}
		cout<<arbol->dato*3<<endl<<endl;
		imprimirArbol(arbol->i,contador+1);
	}
	
}
//recorre al arboll y va hacia un nodo dependiendo de el dato y va sumando 1 a cada dato donde cae 
void recorrido(Nodo *&arbol,int monedas[],int &z){
	if(monedas[z]==1){
		if(arbol==NULL){
			z=z-1;
			return;
		}else{
			z +=1;
			recorrido(arbol->i,monedas,z);
			arbol->dato +=1;
		}
		
	}else if(monedas[z]==2){
		if(arbol==NULL){
			z=z-1;
			return;
		}else{
			z +=1;
			recorrido(arbol->d,monedas,z);
			arbol->dato +=1;
		}
	}
	
}


