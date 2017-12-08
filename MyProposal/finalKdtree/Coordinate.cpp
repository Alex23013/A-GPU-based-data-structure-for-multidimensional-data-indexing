#include "Coordinate.h"

cCoordinate::cCoordinate(vector<double> coord){
    mCoordinates = coord;
    mcity = " ";
    mcountry = " ";
};

cCoordinate::cCoordinate(vector<double> coord, string city, string country){
    mCoordinates = coord;
    mcity = city;
    mcountry = country;
};


unsigned long cCoordinate::mGetDimension(){
    return mCoordinates.size();
}


cCoordinate cCoordinate::operator=(cCoordinate coord){
    mCoordinates = coord.mCoordinates;
    return *this;
};


bool cCoordinate::operator==(cCoordinate coord) {
    return mCoordinates == coord.mCoordinates;
}

bool cCoordinate::operator!=(cCoordinate coord) {
    return mCoordinates != coord.mCoordinates;
}

void cCoordinate::print()
{
    cout<<"(";
    for (int i=0;i<mCoordinates.size()-1;i++){
        cout<<mCoordinates[i]<<",";
    }
    cout<<mCoordinates[mCoordinates.size()-1]<<")"<<endl;
}


float cCoordinate::operator[](int pos){
    return mCoordinates[pos];
};
