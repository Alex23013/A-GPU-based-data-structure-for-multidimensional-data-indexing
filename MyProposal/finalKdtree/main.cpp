#include <iostream>
#include "KDTree.h"
//#include "csvLector.h"

#include <chrono>
#include <utility>
#include <algorithm>
using namespace std::chrono;
using namespace std;


string vocabulario ="xyz"; //aqi se modificaria si qisieramos etiquetar mas de una dimension


/*Funcion para insertar elementos Random*/
void addCoordinatesRan(vector<double>* coord, int dim)
{
    for (int i=0;i<dim;i++)
    {
        double coordinateI=rand() % 10000;
        coord->push_back(coordinateI);
    }
}

void menu()
{

    cout<<"1) Insertar Datos Random"<<endl;
    cout<<"3) Insertar Datos por csv "<<endl;
    cout<<"4) Buscar un elemento "<<endl;
    cout<<"5) tomar tiempos busqueda - insercion"<<endl;
    cout<<"6) Salir"<<endl;
    cout<<"Opcion -> ";
}


int main() {
	srand(time(NULL));
    cout<<"-------------------------------------KDTree--------------------------------"<<endl;
    int dimensions;
    cout<<"Ingresa la cantidad de dimensiones: ";
    cin>>dimensions;
    cKDTree tree(dimensions);
    int option;
    int quantity;
    vector<double> cord;
    menu();
    cin>>option;
    while (option<6){
        switch(option){
            case 1: //Insert random
            {
                cout << "Ingrese la cantidad de datos a insertar: ";
                cin >> quantity;
                for (int i = 0; i < quantity; i++) {
                    addCoordinatesRan(&cord, dimensions);
                    cCoordinate cordenadita(cord);
                    cordenadita.print();
                    tree.mInsert(cordenadita);
                    cord.clear();
                }
                cout << "-----------------------------Arbol-------------------------" << endl;
                tree.print();
                cout <<"Inserción terminada"<< endl;
                break;
            }
            case 3: {
            	string archivo;
            	string ext =".csv";
                cout<<"Ingrese el nombre del archivo .csv: ";
                cin>>archivo;
                archivo+=ext;
                cout<<"archivo por abrir: "<<archivo<<endl;
                //vector <cCoordinate> asd = csvLector(archivo);
               /* cout<<"A vector of : 2Dpoints\n";
			    for(int i =0 ; i< asd.size();i++){
					asd[i].print();
				}*/
				//tree.build(asd);
				cout << "-----------------------------Arbol-------------------------" << endl;
                tree.print();
                cout << endl;
                break;
            }
            case 4: {
                vector<double> doubleInput;
                double in;
                cout<<"Ingrese el dato a buscar: \n";
                for(int i = 0;i < 2;i++){
                   cout<<vocabulario[i]<<"-> ";
                   cin>> in;
                   doubleInput.push_back(in);
                }
                cCoordinate x(doubleInput);
                cout << "-----------------------------Arbol-------------------------" << endl;
                
                //if(!tree.myfind(tree.mRoot,x,0)){ //busqueda recursiva
                if(!tree.myfindLog(x, 0, 0)){ //busqueda logaritmica
                cout<<"\n Ans. Nodo no encontrado\n";
                }
                
                cout << endl;
                break;
            }
            case 5:{
                int elementos[8] = {1000,3000,5000,7000,10000,30000,50000,70000};
                int tests = 100;

                for(int i = 0; i < 8; i++){
                    int n = elementos[i];
                    double time = 0;
                    for (int i = 0; i < n; i++) {
                            addCoordinatesRan(&cord, dimensions);
                            cCoordinate cordenadita(cord);
                            tree.mInsert(cordenadita);
                            cord.clear();
                        }
                    for (int i = 0; i < tests ; i++) {      
                        vector<double> doubleInput;
                        double in;
                        for(int i = 0;i < 2;i++){
                           in=rand() % 10000;
                           doubleInput.push_back(in);
                        }
                        cCoordinate x(doubleInput);
                        high_resolution_clock::time_point t1 = high_resolution_clock::now();
                        //tree.myfind(tree.mRoot,x,0);//Busqueda recursiva
		                tree.myfindLog(x, 0, 0);//busqueda logaritmica
		                high_resolution_clock::time_point t2 = high_resolution_clock::now();
		                auto res = duration_cast<microseconds>( t2 - t1 ).count();
                        time += res;
                    }

                    long long  ttime = time/tests;
                    cout << "tiempo busqueda:" << ttime/1000.0<< " milliseconds con " <<elementos[i]<< endl ;          
                }
                
            }
            
			default:
				break;
        }
        menu();
        cin>>option;
    }
    return 0;
}
