#include<iostream>
#include<windows.h>
#include <conio.h>
#include <clocale>
#include <string>


using namespace std;


//Creando la estructura de los gallos con diferentes datos
struct Gallo{
	string Nombre;
	float Peso;
	float Altura;
	string Raza;
	int Edad;
	int Victorias;
	int Derrotas;
};
struct Nodo{
	Gallo Datos;
	Nodo *siguiente;
	Nodo *Anterior;
};

//Creando la clase de gallos en donde se creara la lista circular doble
class Gallos{
	//Creando el primer gallo de la lista
	Nodo *Ptr=NULL;
	//Creando el ultimo gallo de la lista
	Nodo *Ult=NULL;
	//Variable que guardara la cantidad de gallos en la lista
	int Cantidad=0;
	public:
		//creando las funciones de nuestra lista circular doblemente enlazada
		void Agregar_inicio(Gallo x)
		{
			Nodo *p=new Nodo;
			p->Datos=x;
			if (listavacia())
			{
				Ptr=Ult=p;
			}
			else{
				p->siguiente=Ptr;
				Ptr->Anterior=p;
				Ptr=p;
			}
			Ult->siguiente=Ptr;
			Ptr->Anterior=Ult;
			Cantidad++;	
		}
		
		
        void mostrar(){
            if(!listavacia()){
            	Nodo *p=Ptr;
            	if(Ptr==Ult)
				{
					cout<<"\nNombre del gallo: "<<p->Datos.Nombre<<"\n Altura: "<<p->Datos.Altura<<"\n Edad: "<<p->Datos.Edad<<"\n Peso: "<<p->Datos.Peso<<"\n Raza: "<<p->Datos.Raza<<"\n Victorias: "<<p->Datos.Victorias<<"\n Derrotas: "<<p->Datos.Derrotas;
				}
				else
				{
            		int c=0;
            		while(c<Cantidad){
            		//Se muestran los datos del gallo
            		cout<<"\nNombre del gallo: "<<p->Datos.Nombre<<"\n Altura: "<<p->Datos.Altura<<"\n Edad: "<<p->Datos.Edad<<"\n Peso: "<<p->Datos.Peso<<"\n Raza: "<<p->Datos.Raza<<"\n Victorias: "<<p->Datos.Victorias<<"\n Derrotas: "<<p->Datos.Derrotas;
            		p=p->siguiente;
					c++;
					}
				}
            }
            else{
            	cout<<"\nNo hay gallos en la lista";
			}
        }
		
		void Buscar(string nombre_buscado){
			if(!listavacia()){
				Nodo *p;
				p=Ptr;
				int C=0;
				while(p->Datos.Nombre.compare(nombre_buscado)!=0)
				{
					p=p->siguiente;
					C++;
					if(C==100){
						break;
					}
				}
				cout<<"\nNombre del gallo: "<<p->Datos.Nombre<<"\n Altura: "<<p->Datos.Altura<<"\n Edad: "<<p->Datos.Edad<<"\n Peso: "<<p->Datos.Peso<<"\n Raza: "<<p->Datos.Raza<<"\n Victorias: "<<p->Datos.Victorias<<"\n Derrotas: "<<p->Datos.Derrotas;
			}
			else{
				cout<<"\nLista Vacia";
			}
		}
		
		void eliminarx(string nombre_buscado){
			if(!listavacia()){
				Nodo *p;
				Nodo *q;
				Nodo *z;
				p=Ult;
				q=Ptr;
				z=Ptr->siguiente;
				int C=0;
				while(q->Datos.Nombre.compare(nombre_buscado)!=0)
				{
					q=q->siguiente;
					p=p->siguiente;
					z=z->siguiente;
					C++;
					if(C==100){
						break;
					}
				}
				p->siguiente=q->siguiente;
				z->Anterior=p;
				if(q==Ptr and q==Ult)
				{
					Ptr=NULL;
					Ult=NULL;
					delete z,q,p;
				}
				else if(q==Ptr)
				{
					Ptr=z;	
				}
				else if(q==Ult)
				{
					Ult=p;
				}
				delete q;
				Cantidad--;
			}
			else{
				cout<<"\nLista Vacia";
			}
		}
		
		bool listavacia(){
			if(Ptr==NULL){
				return true;
			}
			else{
				return false;
			}
		}
        
		void modificar();
		
        void cantidad(){
        	cout<<"\n Cantidad de gallos: "<<Cantidad;
        	}
    };
int main(){
	Gallo Gallito;
    Gallos Gallod;
    Gallito.Nombre="Andres";
    Gallito.Altura=15;
    Gallito.Derrotas=2;
    Gallito.Edad=5;
    Gallito.Peso=5;
    Gallito.Raza="Chandita";
    Gallito.Victorias=1;
    Gallod.Agregar_inicio(Gallito);
    Gallod.mostrar();
    Gallod.Buscar("Andres");
    Gallod.eliminarx("Andres");
    Gallod.mostrar();
    
    
	return 1;
    
}
