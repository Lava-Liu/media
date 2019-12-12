#ifndef CARCULATER_H
#define CARCULATER_H
#include <QString>
#include <QVector>

class Carculater
{


public:
    Carculater(){}
    ~Carculater(){}
    int returnNum(QString );
private:
    QVector *vector;



};


int Carculater::returnNum(QString str )
{
    vector = new QVector;

    for(int i=0;i<str.size();i++)
    {
       if(str.at(i)=="0"
          ||str.at(i)=="1"
          ||str.at(i)=="2"
          ||str.at(i)=="3"
          ||str.at(i)=="4"
          ||str.at(i)=="5"
          ||str.at(i)=="6"
          ||str.at(i)=="7"
          ||str.at(i)=="8"
          ||str.at(i)=="9")
      {
           vector->push_front(str.at());
      }else{

       }

    }
}




#endif // CARCULATER_H
