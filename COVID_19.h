#ifndef COVID_19_H
#define COVID_19_H
#include<iostream>
#include"Human.h"
using namespace std;
class COVID_19{
    int  amount; // количество частиц вируса

public:
    COVID_19(): amount(50){}
    COVID_19(int quntity): amount(quntity){}
    int getAmount(){
        return  amount; //  количесвто вируса
    }
    void setAmount(int immunitet){
        if(amount - immunitet >= 0) amount =immunitet;
        else amount = 0;
    }
    int replication(int cells){ // количество восприимчивых клеток
        srand(time(NULL));
        if(cells && amount > 0){ //}
            amount +=((1 + rand()%2) * cells);   // количество вновь образованных клеток (число занижено в миллион раз)
       cout<<"Вирусных частиц:" <<amount<<endl;
            for(int i = 0; i<amount; i++)
            cout<<"*"; // визуальное отображение количесвто вируса
        cout<<endl;

        return  amount/20;//  максимум количесвто частиц вируса в клетке 20 ( если их будет больше клетка погибнет)
   }else
            return  0;
        }
    ~COVID_19(){
        if(amount==0)
            cout<<" Вирус уничтожен"<<endl;
    }
};

#endif // COVID_19_H
