#ifndef OURDATA_H
#define OURDATA_H

#include <QObject>

template<typename T>
class OurData
{

  private:

    T* qData;

public:

    //constructor
    OurData();

};


template<typename T>
OurData<T>::OurData(){

     qData = new T;

};


#endif // OURDATA_H
