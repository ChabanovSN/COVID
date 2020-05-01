#ifndef HUMAN_H
#define HUMAN_H
#include"COVID_19.h"
class Human{
    int cells; // количесвто восприимчевых клеток
    bool firstContact = true; // первичный контакт с вирусом
    bool life= true; // живой человечек
    int imountVirusInHuman; // количество вирусных клеток в человеке
    COVID_19 virus; // вирус в человеке
    const int DURATION_DISEASE = 12; // продолжительность болезни
    void fightintWithVirus(){
        if(firstContact){
            srand(time(NULL));
            for(int i =0; i <DURATION_DISEASE;i++){

                if(imountVirusInHuman >=2000){ // мксимальнок количество частиц допустимых для живого человека
                    life = false;
                    return;
                }
                imountVirusInHuman +=20+ imountVirusInHuman%30; // имунный ответ
                int newVirus = virus.getAmount()- imountVirusInHuman;
                virus.setAmount( newVirus);// новые вирусы
                cells -=virus.replication(cells); // вирусы поражают новые клетки
                if(cells <0)cells=0;
               // imountVirusInHuman +=virus.getAmount();
                if(cells==0) return; // в легких больше нет жизнеспособных клеток
            }
        }
    }

public:

    Human(bool firstContact):cells(100), imountVirusInHuman(0)
    {
       Human::firstContact=firstContact;
    }
    void contactWithVirus(COVID_19 virus){
        // количесвто восприимчевых клеток (занижено)
                cout<<"Контакт с вирусом"<<endl;
                if(firstContact){
                    Human::virus = virus;
                }

                 fightintWithVirus();
    }
    bool getFirstContact(){
        return firstContact;

    }

    ~Human(){
        cout<<"Количесвто пораженных клеток: "<<100-cells<<endl;
        if(life==false || cells == 0){
            cout<<"Помер человек"<<endl;
        }else{
            cout<<"Вылечился человек"<<endl;
        }
    }
};



#endif // HUMAN_H
