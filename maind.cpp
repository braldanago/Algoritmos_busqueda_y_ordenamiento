//BRAYAN STEVEN ALDANA GOMEZ 20152020042	
//DIEGO DAYAN GUERRA NUÑEZ 20152020024

#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

using namespace std;


class Arreglo{
	int tamanio;
	int *elemento;

	
	public:
	Arreglo();
	void size(int);
	void operator=(Arreglo);
	void cargar();
	int getTamanio();
	int busquedaSecuencial(int,int&);
	int busquedaBinariaIt(int,int&);
	int busquedaBinariaRe(int,int,int,int&);
	int burbuja();
	int insercion();
	int shell();
	int quickSort(int izq, int der,int &op  );
	int mergeSort(int ,int);
	int mergeSort2(int,int ,int );
	void mostrar();
	
};

int Arreglo::getTamanio(){
	return this->tamanio;
}

char menu(){ //MENU PRINCIPAL
	char opcion;
	cout<<"\tMENU \n"<<endl;
	cout<<"Busqueda \n";
	cout<<"(X) Secuencial \n";
	cout<<"(Y) Binario Iterativo\n";
	cout<<"(Z) Binario Recursivo\n"<<endl;
	cout<<"Ordenamiento\n";
	cout<<"(B) Burbuja\n";
	cout<<"(I) Insercion\n";
	cout<<"(H) Shell\n";
	cout<<"(Q) Quick Sort\n";
	cout<<"(M) Merge Sort\n";
	cout<<"(C) Cubetas\n";
	cout<<"(R) Resumen\n";
	cout<<"(E) Salir \n";
	cout<<"Escoja una opcion : ";
	cin>>opcion;
	system("cls");
	return opcion; 

}

char menuPrincipal(){//MENU PRINCIPAL
	char opcion;
	cout<<"Bienvenido, seleccione una opcion: \n"<<endl;
	cout<<"(C)argar"<<endl;
	cout<<"(M)ostrar"<<endl;
	cout<<"(B)uscar"<<endl;
	cout<<"(O)rdenar"<<endl;
	cout<<"(T)erminar"<<endl;
	cin>>opcion;
	return opcion;
}


char menuBuscar(){//MENU BUSQUEDA //////////////////
    char opcion;
	cout<<"Bienvenido, seleccione metodo busqueda: \n"<<endl;
	cout<<"(S)ecuencial"<<endl;
	cout<<"Binaria (I)terativa"<<endl;
	cout<<"(B)inaria Recursiva"<<endl;
	cout<<"(R)egresar"<<endl;
	cin>>opcion;
	return opcion;
}

char menuOrdenar(){//MENU ORDENAMIENTO //////////////////
    char opcion;
	cout<<"Bienvenido, seleccione un metodo para ordenar: \n"<<endl;
	cout<<"(B)urbuja"<<endl;
	cout<<"(I)nsercion"<<endl;
	cout<<"(S)hell"<<endl;
	cout<<"(Q)uicksort"<<endl;
	cout<<"(M)ergesort"<<endl;
	cout<<"(C)ubetas"<<endl;
	cout<<"(T)otales"<<endl;
	cout<<"(R)egresar"<<endl;
	cin>>opcion;
	return opcion;
}

Arreglo::Arreglo(){
	//this->tamanio=tamanio;
	//elemento = new int [tamanio];
	
	
}

void Arreglo::size(int tamnio){//donde se toma el tamaño y se le da el mismo al objeto arreglo
     this->tamanio=tamnio;
     elemento = new int [this->tamanio];
}


void Arreglo::operator=(Arreglo a){
	this -> tamanio = a.tamanio;
	for(int i=0;i<tamanio;i++){
		this -> elemento[i]=a.elemento[i];
	}
	
		
}

//CARGAR ARREGLO ///////////////////////////////////////////
void Arreglo::cargar(){
     //srand (time(NULL));
    if(this->tamanio<30){
        for(int k=0;k<tamanio;k++){
			cout<<"Elemento["<<k+1<<"]= ";
			cin>>elemento[k];
        }
        mostrar();
	}else{// REVISAR
		srand (time(NULL));
	 	int rango = tamanio*2;
        for(int k=0;k<tamanio;k++){
		elemento[k]=rand() % rango;
        }
        mostrar();
    }
		
}

//MOSTRAR

void Arreglo::mostrar(){
	for(int k=0;k<tamanio;k++){
		cout<<elemento[k]<<" ";
	}
	//cargar manual y aleatoriamente
}


/////METODOS DE BUSQUEDA ////////////////////////////////////////////////////////////

int Arreglo::busquedaSecuencial(int elemento, int& op){
	int k=0;
	while(k<tamanio){
		op++;
		if(this->elemento[k]==elemento){
			return k;
			
		}
		k++;
	}
	return -1;
}

int Arreglo::busquedaBinariaIt(int elemento,int& op){
	int ini=0,fin=tamanio-1,mitad;
	while(ini<=fin){
		mitad=(ini+fin)/2;
		op++;
		if(this->elemento[mitad]==elemento){
			return mitad;
		}
		if(this->elemento[mitad]>elemento){
			fin=mitad-1;
		}else{
			ini=mitad+1;
		}
	}
	return -1;
}


///METODOS DE ORDENAMIENTO
int Arreglo::burbuja(){
	int aux,operaciones=0;
	for(int i=0;i<tamanio-1;i++){
		for(int j=i+1;j<tamanio;j++){
			operaciones++;
			if(elemento[i]>elemento[j]){
				aux=elemento[i];
				elemento[i]=elemento[j];
				elemento[j]=aux;	
			}
		}
	}
	return operaciones;
}

int Arreglo::insercion(){

    int j=1,k,aux,op;

	while(j<tamanio){
		k=j-1;
		aux=elemento[j];
		op++;
		while(k>=0 && elemento[k]>aux){
			op++;
			elemento[k+1]=elemento[k];
			k--;
		}
		elemento[k+1]=aux;
		j++;
	}
	return op;
}

int Arreglo::shell(){
    
   int salto=0, auxi=0, i=0,comp=0;
   bool cambios;
   for(salto=tamanio/2; salto!=0; salto/=2){
        cambios=true;
        while(cambios){ 
            cambios=false;
                      
            for(i=salto; i< tamanio; i++){ 
                comp++;
                if(elemento[i-salto]>elemento[i]){ 
                    auxi=elemento[i]; 
                    elemento[i]=elemento[i-salto];
                    elemento[i-salto]=auxi;
                    cambios=true; 
                }
            }
        }
   } 
 return comp;
} 

int Arreglo::quickSort(int izq, int der,int &op){//QUICK SORT //////
    int i, j, x , aux; 
	i = izq; 
	j = der; 
	x = elemento[ (izq + der) /2 ]; 
    do{ 
        while( (elemento[i] < x) && (j <= der) ){ 
            i++;
        }  
        
        while( (x < elemento[j]) && (j > izq) ){ 
            j--;
        }  
		op++;
        if( i <= j ){   	
            aux = elemento[i]; elemento[i] = elemento[j]; elemento[j] = aux; 
            i++;  j--; 
        }         
	}while( i <= j ); 
 	op++;
    if( izq < j ) {    	
    	quickSort(izq, j ,op); 
	}
 	op++;
    if( i < der ){    	
    	quickSort(i, der ,op); 
	}     
    return op;
}

/*
Ordenamiento con el algoritmo MergeSort
*/
int Arreglo::mergeSort(int p,int r){
	int q,op=0;
    if(p<r){
        q=(p+r)/2;
        mergeSort(p,q);
        mergeSort(q+1,r);
        op=op+mergeSort2(p,q,r);
    }
	return op;
}
int Arreglo::mergeSort2(int p,int q,int r){
	int n1=q-p+1;
    int n2=r-q;
    int op;
    int L[n1+1];
    int R[n2+1];
    
    for(int i=1;i<=n1;i++){
        L[i]=elemento[p+i-1];
    }
    
    for(int j=1;j<=n2;j++){
        R[j]=elemento[q+j];
    }
    
    L[n1+1]=999;
    R[n2+1]=999;
    int i=1, j=1;
    
    op++;
    for(int k=p;k<=r;k++){
    	op++;
        if(L[i]<=R[j]){
            elemento[k]=L[i];
            i=i+1;
        }else{
            elemento[k]=R[j];
            j=j+1;
        }
    }
    return op;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    char opcion;
    int numero,op,posicion;
    Arreglo A,B;
    
    //system("color f0");
 
	do{     
		op=0;      
        system("cls");
        opcion=menuPrincipal();
    	switch (opcion){
               case 'c':
               case 'C':{//CARGAR
                    system("cls");
                    cout<<"Se cargara el arreglo"<<endl;
                    cout<<"Ingrese numero de datos: "<<endl;
                    cin>>numero;
                    
                    Arreglo C;
                    C.size(numero);
                    C.cargar();
                    A.size(numero);
                    B.size(numero);
                    A=C;
                    

                    cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    A.mostrar();
                    getch();
                    
                    break;
               }     
               case 'm':
               case 'M':{//MOSTRAR
                    system("cls");
                    A.mostrar();
                    cout<<""<<endl;
                    cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    getch();
                    
                    break;
               }
               case 'b':
               case 'B':{//BUSCAR
                    char opc,num;
                    system("cls");
                    opc=menuBuscar();
                    cout<<""<<endl;
                    
                    if(opc=='s' || opc=='S'){

                        cout<<"Ingrese el elemento a buscar: ";
        				cin>>numero;
        				posicion=A.busquedaSecuencial(numero,op);
        				if(posicion!=-1){
        					cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
        				}else{
        					cout<<"El elemento no se encontro en el arreglo \n";
        				}
        				A.mostrar();
        				cout<<"\nRealizo "<<op<<" comparaciones \n"<<endl;
        				
        				cout<<"Presione una tecla para volver al menu"<<endl;
        				getch();
        				system("CLS");
                       
                    }else if(opc=='i' || opc=='I'){
						
						cout<<"Ingrese el elemento a buscar: ";
						cin>>numero;
						B=A;
						
						B.burbuja();
						posicion=B.busquedaBinariaIt(numero,op);
						A.mostrar();
						cout<<"..";
						if(posicion!=-1){
							cout<<"El elemento se encuentra en la posicion: "<<posicion<<endl;
						}else{
							cout<<"El elemento no se encontro en el arreglo \n";
						}
						B.mostrar();
						cout<<"Realizo "<<op<<" comparaciones \n"<<endl;	
						    
						cout<<"Presione una tecla para volver al menu"<<endl;
						getch();
						system("CLS");	
							
						break;    
						    	
					
                    }
                    else if(opc=='b' || opc=='B'){
                    	
                    	
                    	
                    	
                    	
					}
					
					else if(opc=='r' || opc=='R'){
						break;
					}
					
                                      
               }
               case 'o':
               case 'O':{//ORDENAR
               		op=0;
               		char opc,num;
                    system("cls");
                    opc=menuOrdenar();
                    cout<<""<<endl;
                    
			        if(opc =='b' || opc=='B'){
			        	system("cls");
			        	B=A;
			        
						op=B.burbuja();
						cout<<"\n El arreglo ordenado por Burbuja \n";
						B.mostrar();
						cout<<"\nRealizo "<<op<<" comparaciones\n\n";
						cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    	getch();
						break;
					}	
					else if(opc =='i' || opc=='I'){
						system("cls");
						B=A;
						op=B.insercion();
						cout<<"\n El arreglo ordenado por Insercion \n";
						B.mostrar();
						cout<<"\nRealizo "<<op<<" comparaciones\n\n";
						cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    	getch();
						break;	
					}	        
					else if(opc =='s' || opc=='S'){
						system("cls");
						B=A;
						op=B.shell();
						cout<<"\n El arreglo ordenado por Shell \n";
						B.mostrar();
						cout<<"\nRealizo "<<op<<" comparaciones\n\n";
						cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    	getch();
						break;	
					}	
					else if(opc =='q' || opc=='Q'){
						system("cls");
						B=A;
						op=B.quickSort(0,(B.getTamanio()-1),op);
						cout<<"\n El arreglo ordenado por QuickSort \n";
						B.mostrar();
						cout<<"\nRealizo "<<op<<" comparaciones\n\n";
						cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    	getch();
						break;
					}	
					else if(opc =='m' || opc=='M'){
						system("cls");
						B=A;
						op=B.mergeSort(0,B.getTamanio()-1);
						cout<<"\n El arreglo ordenado por MergeSort \n";
						B.mostrar();
						cout<<"\nRealizo "<<op<<" comparaciones\n\n";
						cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    	getch();
						break;
						
					}	
					else if(opc =='c' || opc=='C'){
						
					}	
					else if(opc =='t' || opc=='T'){
						system("cls");
						cout<<"\tEl resumen de los Algoritmos de Busqueda es\n"<<endl;
						cout<<"\tAlgoritmo\t\t Operaciones\n";	
						B=A;			
						cout<<"\tBurbuja\t\t\t "<<B.burbuja()<<endl;
						B=A;
						cout<<"\tInsercion\t\t "<<B.insercion()<<endl;
						B=A;
						cout<<"\tShell\t\t\t "<<B.shell()<<endl;				
						cout<<"Presione cualquier tecla para regresar al menu inicial"<<endl;
                    	getch();
						break;
						
					}	
					else if(opc =='r' || opc=='R'){
						
					}
               }
			   default:{
			   	cout<<"Opcion no existe, volver a menu principal."<<endl;
			   	getch();
				break;
			   }               
        }
    }while(opcion != 'S' && opcion != 's');   
}
