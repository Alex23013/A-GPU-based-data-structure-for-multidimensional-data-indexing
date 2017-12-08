#ifndef NODE_H
#define NODE_H
#include "Coordinate.h"

 class cNode{
 	private:
 		cCoordinate mCoord;
 		int mCutCoordinate;
 	public:
 		cNode* mChild[2];
        cNode(cCoordinate, int);
        int mGetCutCoordinateVal();
        double mGetCoordinate(int);
        cCoordinate mGetCoordinate();
 		cNode** mGetChildDir(bool);
 		cNode* mGetChild(bool);
 		void mPrintCoordinates();
 		virtual ~cNode ();
 };
 
 #endif //KD_TREE_NODE_H 
