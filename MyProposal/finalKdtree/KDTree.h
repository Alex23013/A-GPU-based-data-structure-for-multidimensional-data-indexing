#ifndef KD_TREE_KDTREE_H
 #define KD_TREE_KDTREE_H
 #include <math.h>
 #include<time.h>
 #include "Node.h"
 #include "radix.h"
 
 class cKDTree {
 	public:
 		cNode* mRoot;
 		int mDimensions;
        vector<cCoordinate> inputPoints;
 		cKDTree(int);
 		void mInsert(cCoordinate);
 		bool mInsertAux(cCoordinate,cNode**,int);
 		virtual ~cKDTree ();
 		void print();
 		void print2(cNode* t, int nivel);
        float distance(cCoordinate , cCoordinate );
        string vocabulary="xyz";
        void build(vector<cCoordinate> x);
        bool myfind(cNode* p, cCoordinate x, int level);
        bool myfindLog(cCoordinate x, int level, int mDim);
 };
  #endif
