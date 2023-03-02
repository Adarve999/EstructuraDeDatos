#pragma once
#include "Vehiculo.h"
#include "Cola.h"
#include "Pila.h"
#include "Zona.h"
class Gestor {

public:
    Gestor();
    Cola cola_fabrica;

    Zona zonaA;

    Zona zonaB;

    Zona zonaC;
    

    void crear_Vehiculos(int i);
    void crear_VehiculosPorUsuario(string i);
    void operacion_CrearVehiculos(int Nvehiculos);

    void mostrar_cola_fabrica();// estos dos metodos muestran la cola de la fabrica y el de la zona
    void borrar_cola_fabrica();//borra los datos de la cola fabrica
    void mostrar_cola_zonas_Y_pilas();
    void borrar_datos_Pilas();//borra los datos de los camiones
    void borrar_datos_cola_zona();//borra los datos de la cola zona
    
    void cargar_Vehiculos(int i,int tamanoPila, int concesinarios);
    void cargar_VehiculosPorUsuario(string cad, int tamanoPila,int concesinarios);
    void cargaPilas(int i,int x,int concesinarios);//el metodo para cargar los camiones y ir alternando
    

    void LimpiarCamiones(int);//los vehiculos restantes los pasa a la cola zona
    void SimulacionCompleta(int i, int x,int tamanoPila, int concesinarios);
};

