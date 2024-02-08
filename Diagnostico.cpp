#include <string>
#include <cstdio>
#include <iostream>

using namespace std;

class transporte{
    private:
    string nombre;
    int cant_ruedas;
    int asientos;
    float velocidad;

    public:
    transporte(string _nombre ,int _cant_ruedas, int _asientos,float _velocidad)
    : nombre(_nombre),cant_ruedas(_cant_ruedas),asientos(_asientos),velocidad(_velocidad) {}

    void mostrar(){
        printf("%s  %d ruedas, %d asientos, con una velocidad de %f km/h\n",nombre.c_str(),cant_ruedas,asientos,velocidad);
    }
};

class terrestre : public transporte{
    private:
    string tipo_conduccion;
    public:
    terrestre(string _nombre,int _cant_ruedas, int _asientos, float _velocidad, string _tipo_conduccion)
    : transporte(_nombre,_cant_ruedas, _asientos, _velocidad), tipo_conduccion(_tipo_conduccion){}

    void mostrar(){
        transporte::mostrar();
        printf("... con conduccion %s\n\n",tipo_conduccion.c_str());
    }
};
class acuatico : public transporte{
    private:
    bool velas;
    public:
    acuatico(string _nombre,int _cant_ruedas, int _asientos, float _velocidad, bool _velas)
    : transporte(_nombre,_cant_ruedas, _asientos, _velocidad), velas(_velas) {}

    void mostrar(){
        transporte::mostrar();
        if (velas)
        {
            printf("un hermoso barco velero\n\n");
        }else{
            printf("un gran barco motorizado\n\n");
        }
        
    }
};
class aereo : public transporte{
    private:
    float peso_max;
    string proposito;
    public:
    aereo(string _nombre,int _cant_ruedas, int _asientos, float _velocidad, float _peso_max, string _proposito)
    : transporte(_nombre,_cant_ruedas, _asientos, _velocidad), peso_max(_peso_max), proposito(_proposito) {}

    void mostrar(){
        transporte::mostrar();
        printf("cuidado que este %s tiene una carga maxima de %f\n\n",proposito.c_str(),peso_max);
    }
};
int main(){
    terrestre miAuto("chevrolet",4, 5, 100, "Estandar");
    acuatico miBarco("titanic",0, 2225, 30, true);
    aereo miAvion("buitre",3, 100, 500, 100000, "Transporte de pasajeros");

    miAuto.mostrar();
    miBarco.mostrar();
    miAvion.mostrar();

    return 0;
}