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
		
		Nodo* Buscar(string nombre_buscado){
			if(!listavacia()){
				Nodo *p;
				p=Ptr;
				Nodo *C=Ptr;
				bool encontrado=true;
				while(p->Datos.Nombre.compare(nombre_buscado)!=0)
				{
					p=p->siguiente;
					if(C==p){
						cout<<"\nEl gallo buscado no se encuentra";
						encontrado=false;
						break;
					}
				}
				
				if(encontrado)
				{
					return p; 
				}
				
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
					p=NULL;
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
		
		
		void modificar(string nombre){
			if(!listavacia()){
				
				Nodo *p=Buscar(nombre);
				cout<<"\n ¿Que datos desea modificar? (1.Nombre, 2.Altura, 3.Edad, 4.Peso, 5.Raza, 6.Victorias, 7.Derrotas): ";
				int modify;
				cin>>modify;
				
				switch(modify){
					
					case 1:{
						cout<<"\n Ingrese el nuevo nombre: ";
						string Nombre_nuevo;
						cin>>Nombre_nuevo;
						p->Datos.Nombre=Nombre_nuevo;
						break;
					}
		    
		    		case 2:{
		    			cout<<"\n Ingrese la nueva altura: ";
		    			float Altura_nueva;
		    			cin>>Altura_nueva;
		    			p->Datos.Altura=Altura_nueva;
						break;
					}

		    		case 3:{
		    			cout<<"\n Ingrese la nueva edad: ";
		    			int Edad_nueva;
		    			cin>>Edad_nueva;
		    			p->Datos.Edad=Edad_nueva;
						break;
					}
		    
		    		case 4:{
		    			cout<<"\n Ingrese el nuevo peso: ";
		    			float peso_nuevo;
		    			cin>>peso_nuevo;
		    			p->Datos.Peso=peso_nuevo;
						break;
					}

		    		case 5:{
		    			cout<<"\n Ingrese la nueva raza: ";
		    			string raza_nueva;
		    			cin>>raza_nueva;
		    			p->Datos.Raza=raza_nueva;
						break;
					}
	    
		   	 		case 6:{
		   	 			cout<<"\n Ingrese las nuevas victorias: ";
		   	 			int victorias_nueva;
		   	 			cin>>victorias_nueva;
		   	 			p->Datos.Victorias=victorias_nueva;
							break;
						}
						
					case 7:{
						cout<<"\n Ingrese las nuevas derrotas: ";
						int derrotas_nueva;
						cin>>derrotas_nueva;
						p->Datos.Derrotas=derrotas_nueva;
						break;
					}	

							}
							cout<<"\n Informacion cambiada correctamente ";		
			}
		}
		
		
        void cantidad(){
        	cout<<"\n Cantidad de gallos: "<<Cantidad;
        	}
    };
int main(){
	Gallo Gallito;
    Gallos Gallod;
	int opc=0;
    int c=1;
    while (c==1){
		cout<<"====================\n";
		cout<<"===Menu Principal===\n";
		cout<<"====================\n";
		cout<<"1. Agregar gallo al inicio: \n";
		cout<<"2. Mostrar lista de gallos \n";
		cout<<"3. Eliminar gallo \n";
		cout<<"4. Modificar datos \n";
		cout<<"5. Buscar gallo \n";
		cout<<"6. Cantidad de gallos \n";
		cout<<"7. Salir \n";
		cout<<"Seleccione una opcion: ";
		cin>>opc;

		switch(opc)
		{

		    case 1:
			{
			    cout<<"Ingrese el nombre del gallo: ";
			    string Nombre_nuevo;
			    cin>>Nombre_nuevo;
			    cout<<"Ingrese la altura del gallo (cm): ";
			    float Altura_nueva;
			    cin>>Altura_nueva;
			    cout<<"Ingrese la edad del gallo (Meses): ";
			    int Edad_nueva;
			    cin>>Edad_nueva;
			    cout<<"Ingrese el peso del gallo (Kg): ";
			    float peso_nuevo;
			    cin>>peso_nuevo;
			    cout<<"Ingrese la raza del gallo: ";
			    string raza_nueva;
			    cin>>raza_nueva;
			    cout<<"Ingrese las victorias del gallo: ";
			    int victorias_nueva;
			    cin>>victorias_nueva;
			    cout<<"Ingrese las derrotas del gallo: ";
			    int derrotas_nueva;
			    cin>>derrotas_nueva;
				Gallito.Victorias=victorias_nueva;
			    Gallito.Derrotas=derrotas_nueva;
			    Gallito.Raza=raza_nueva;
			    Gallito.Peso=peso_nuevo;
			    Gallito.Altura=Altura_nueva;
			    Gallito.Nombre=Nombre_nuevo;
			    Gallito.Edad=Edad_nueva;
			    Gallod.Agregar_inicio(Gallito);
			}
		    break;
		    case 2:
				Gallod.mostrar();
		    break;
		    case 3:{
		    	
				if(!Gallod.listavacia())
				{
					cout<<"Ingrese el nombre del gallo que desea buscar: ";
		    		string nombre;
		    		cin>>nombre;
					Gallod.eliminarx(nombre);
					cout<<"\n Eliminado con exito";
					Gallod.mostrar();
				}
				else{
					cout<<"Lista Vacia";
				}
				

			}
		    break;
		    case 4:{
		    	cout<<"\n Introduzca el nombre del gallo que desea modificar: ";
		    	string New;
		    	cin>>New;
		    	Gallod.modificar(New);
				break;
			}
		    break;
		    case 5:{
			
		    	cout<<"Ingrese el nombre del gallo que desea buscar: ";
		    	string nombre;
		    	cin>>nombre;
		    	Nodo *gallo=Gallod.Buscar(nombre);
		    	cout<<"\nNombre del gallo: "<<gallo->Datos.Nombre<<"\n Altura: "<<gallo->Datos.Altura<<"\n Edad: "<<gallo->Datos.Edad<<"\n Peso: "<<gallo->Datos.Peso<<"\n Raza: "<<gallo->Datos.Raza<<"\n Victorias: "<<gallo->Datos.Victorias<<"\n Derrotas: "<<gallo->Datos.Derrotas;}
		    break;
		    
		    case 6:{
		    	Gallod.cantidad();
				break;
			}
			
		    case 7:
			cout<<"Fin del programa";
			c+=1;
		    break;
		}
		cout<<"\n continuar en el programa...? (1=si 2=no): \n";
		cin>>c;
		cout<<"\n+++++++++++++++ En 5 segundos se limpiara la pantalla +++++++++++++++";

		Sleep(1000);
		cout<<"\n+++++++++++++++ En 4 segundos se limpiara la pantalla +++++++++++++++";

		Sleep(1000);
		cout<<"\n+++++++++++++++ En 3 segundos se limpiara la pantalla +++++++++++++++";

		Sleep(1000);
		cout<<"\n+++++++++++++++ En 2 segundos se limpiara la pantalla +++++++++++++++";

		Sleep(1000);
		cout<<"\n+++++++++++++++ En 1 segundos se limpiara la pantalla +++++++++++++++";
		cout<<"\n======================================================================";
		Sleep(1000);
		system("cls");

	    }


		return 1;

}
