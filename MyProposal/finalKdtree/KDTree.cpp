#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include "KDTree.h"
#include <iostream>
using namespace std;
cKDTree::cKDTree(int dimensions){
    mRoot = NULL;
    mDimensions = dimensions;
}


cKDTree::~cKDTree(){
    mRoot = NULL;
}

void cKDTree::print() {
    print2(mRoot,0);
}

void cKDTree::print2(cNode* t, int level) {
    if (t!=NULL)
    {
        print2(t->mGetChild(1), level+1);
        for (int k = 0; k < mDimensions*level; k++)
        {
            cout<< "  ";
        }
        cout <<vocabulary[t->mGetCutCoordinateVal()]<<endl;
       /* string sCity = (t->mGetCoordinate()).mcity;
        cout <<" "<<sCity.c_str();
        string sCountry =(t->mGetCoordinate()).mcountry;
        cout <<"-"<<sCountry.c_str()<<"\n";*/
        for (int k = 0; k < mDimensions*level; k++)
        {
            cout<< "  ";
        }
        t->mPrintCoordinates();
        print2(t->mGetChild(0), level+1);
    }
}

bool cKDTree::mInsertAux(cCoordinate coord, cNode** t,int cd){
    if (*t==NULL)
    {
        cNode* aux = new cNode(coord,cd);
        *t = aux;
        return 1;
    }
    if (coord == (*t)->mGetCoordinate())
    {
        return 0;
    }
    bool c=(coord[cd] >= (*t)->mGetCoordinate(cd));
    cNode** p=(*t)->mGetChildDir(c);
    return mInsertAux(coord,p,(cd+1) % mDimensions);
}


void cKDTree::mInsert(cCoordinate coord){
    if ( mDimensions != coord.mGetDimension() ) {
        cout << "Dimension invalida. Asigne coordenadas de la dimension: "<< mDimensions << endl;
        return;
    }
    if(mInsertAux(coord,&mRoot,0)){
        //cout<<"Insertado correctamente"<<endl;
    }
    else{
        //cout<<"La coordenada ya esta en el arbol"<<endl;
    }
}
/*
void cKDTree:: build(vector<cCoordinate> x){ //construye el arbol cuadratico XD
	int actualDim = 0;
	int cont =0;
	int tamX = x.size();
	while(!x.empty()){
		//sortPoints(&x,actualDim% mDimensions); //solo con un dataSet , numeros>0
	  	BubbleSort(&x,actualDim% mDimensions);
		//cout<<"\nsort ";	for(int i = 0; i< x.size();i++){       cout<<"(";	x[i].print();       cout<<") ";    }
		int median = x.size()/2;
        mInsert(x[median]);
        x.erase(x.begin()+median);
		actualDim++;
		}
}*/

struct FunctorX
{
    inline bool operator() (const cCoordinate& coord1, const cCoordinate& coord2)
    {
        return (coord1.mCoordinates[0] < coord2.mCoordinates[0]);
    }
};

struct FunctorY
{
    inline bool operator() (const cCoordinate& coord1, const cCoordinate& coord2)
    {
        return (coord1.mCoordinates[1] < coord2.mCoordinates[1]);
    }
};

void cKDTree:: build(vector<cCoordinate> x){ //construye el arbol
	int actualDim = 0;
    int cont =0;
    vector<cCoordinate> y(x);
    cout<<"Mdimension"<<mDimensions;

    std::vector<cCoordinate>::iterator it;
    while(!x.empty()){
		if(actualDim% mDimensions == 0){
            sort(x.begin(), x.end(), FunctorX());
            int median = x.size()/2;
            mInsert(x[median]);
            it = find (y.begin(), y.end(), x[median]);
            x.erase(x.begin()+median);
            y.erase(it);
        }else{
            sort(y.begin(), y.end(), FunctorY());
            int median = y.size()/2;
            mInsert(y[median]);
            it = find (x.begin(), x.end(), y[median]);
            y.erase(y.begin()+median);
            x.erase(it);
        }
        cont+=1;
        if(cont%10==0) cout<<cont<<endl;
        actualDim++;
    }
}


bool cKDTree:: myfind(cNode* p, cCoordinate x, int level){
    if (!p){return false;}
    if(myfind(p->mGetChild(1), x,level+1)){
        return true;
    }
    if (p->mGetCoordinate() == x){
    cout<<"\nAns.  Nodo encontrado en level:"<<level<<endl;
    return true;}
    if(myfind(p->mGetChild(0), x,level+1)){
        return true;
    }
    return false;
}

bool cKDTree:: myfindLog(cCoordinate x, int level, int mDim){
    cNode* p=mRoot;
    //cout<<"root: ["<<p->mGetCoordinate(0)<<";"<<p->mGetCoordinate(1)<<"]\n";
    while(p){
	    if((p)->mGetCoordinate() == x){
	        //cout<<"l:"<<level<<endl; //para saber en que nivel lo encontro
	        return true;}
	    
	    bool dir=mDim%mDimensions;
	    //cout<<"# "<<dir<<" #";
	    if(p->mChild[p->mGetCoordinate(dir) < x[dir]]){
	        //cout<<	p->mGetCoordinate(dir)<<"__"<<x[dir]<<"   ";
	        p=p->mChild[p->mGetCoordinate(dir) < x[dir]];	
	        
	        //cout<<"["<<p->mGetCoordinate(0)<<";"<<p->mGetCoordinate(1)<<"]\n";
	        mDim++;
	        level++;
	    }else{
	    return false;
	    }	    
	}
}
