#ifndef KD_TREE_COORDINATE_H
#define KD_TREE_COORDINATE_H
 
 #include <iostream>
 #include <vector>
 
 using namespace std;
 
 class cCoordinate {
 	public:
 		vector<double> mCoordinates;
 		string mcity;
 		string mcountry;
 	public:
 		cCoordinate(vector<double>);
 		cCoordinate(vector<double>, string city, string country);
        unsigned long mGetDimension();
 		void print();
 		cCoordinate operator=(cCoordinate coord);
 		bool operator==(cCoordinate coord);
 		bool operator!=(cCoordinate coord);
 		float operator[](int pos);
 };
 
 #endif //KDTREE2_COORDINATE_H
