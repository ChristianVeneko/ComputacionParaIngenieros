#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <cstring>
using namespace std;

struct Semana {
    double dias[5];
};

struct Empleado {
    string nombre, telefono, correo, apellido;
    int cedula;
    Semana ventasSemana;
    char categoria[20];
    double promVentas;
};

int main() {
    int opc;
    int cantEmpleados;
    bool empleadosAgregados = false;
    cout<< "=======Bienvenido al sistema de la empresa=======\n";
    cout<< "Por favor ingrese la cantidad de empleados con la que desea trabajar: ";
    cin>> cantEmpleados;
    Empleado empleados[cantEmpleados];
    system("cls");

    do {
        cout<< "\n**** Menu De la Empresa ****\n";
        cout<< "          OPCIONES          \n";
        cout<<"1-Ingresar Empleados\n";
        cout<<"2-Visualizar Empleados\n";
        cout<<"3-Visualizar Empleado De La Semana\n";
        cout<<"4-Salir Del programa\n";
        cout<<"OPCION: ";
        cin >> opc;
        system("cls");

        switch(opc) {
            case 1:
                if(!empleadosAgregados) {
                    cout<< "\n*** AGREGAR EMPLEADOS ***\n";
                    for(int i = 0; i < cantEmpleados; i++) {
                        cout<< "Por favor ingresa los datos del empleado Nro " << i+1<< endl;
                        cout<< "Nombre: ";
                        cin >> empleados[i].nombre;
                        cout<< "Apellido: ";
                        cin >> empleados[i].apellido;
                        cout<< "Cedula: ";
                        cin >> empleados[i].cedula;
                        cout<< "Telefono: ";
                        cin >> empleados[i].telefono;
                        cout<< "Correo: ";
                        cin >> empleados[i].correo;

                        double sumaVentas = 0;  // Inicializar correctamente
                        cout<< "~~Ingresa las ventas de la semana~~\n";
                        for(int j = 0; j < 5; j++) {
                            cout<< "Dia " << j+1 << ": ";
                            cin >> empleados[i].ventasSemana.dias[j];
                            sumaVentas += empleados[i].ventasSemana.dias[j];
                        }
                        empleados[i].promVentas = sumaVentas / 5;
                    }
                    cout<< "Empleados Agregados Correctamente\n";
                    empleadosAgregados = true;
                    cout<< "Presiona cualquier tecla para continuar: \n";
                    getch();
                    system("cls");
                } else {
                    cout<< "Los empleados ya han sido agregados\n";
                    cout<< "Presiona cualquier tecla para continuar: \n";
                    getch();
                    system("cls");
                }
                break;

            case 2:
                if(empleadosAgregados) {
                    // ORDENAR EMPLEADOS POR CEDULA ANTES DE MOSTRAR
                    for(int i = 0; i < cantEmpleados; i++) {
                        for(int j = 0; j < cantEmpleados - 1; j++) {
                            if(empleados[j].cedula > empleados[j+1].cedula) {
                                // Intercambiar empleados
                                Empleado aux = empleados[j];
                                empleados[j] = empleados[j+1];
                                empleados[j+1] = aux;
                            }
                        }
                    }

                    cout<< "\n*** MOSTRAR EMPLEADOS ***\n";
                    for(int i = 0; i < cantEmpleados; i++) {  // Inicializar `i`
                        cout<< "\n===================================\n";
                        cout<< "~~~~ Empleado Nro: " << i+1<< " ~~~~\n";
                        cout<< "Nombre: " << empleados[i].nombre << endl;
                        cout<< "Apellido: " << empleados[i].apellido << endl;
                        cout<< "Cedula: " << empleados[i].cedula << endl;
                        cout<< "Telefono: " << empleados[i].telefono << endl;
                        cout<< "Correo: " << empleados[i].correo << endl;
                        cout<< "~~~~ Ventas del Empleado Nro: "<< i+1<< "~~~~\n";
                        for(int j = 0; j < 5; j++) {  // Inicializar `j`
                            cout<< "Dia "<< j+1 << ": " << empleados[i].ventasSemana.dias[j] << endl;
                        }
                        cout<< "\n===================================\n";
                    }
                    cout<< "Presiona cualquier tecla para continuar: \n";
                    getch();
                    system("cls");
                } else {
                    cout<< "ERROR... NO SE HAN AGREGADO EMPLEADOS AL SISTEMA\n";
                    cout<< "Presiona cualquier tecla para continuar: \n";
                    getch();
                    system("cls");
                }
                break;

            case 3:
                if(empleadosAgregados) {
                    cout<< "\n*** MOSTRAR EMPLEADO DE LA SEMANA ***\n";
                    int iMejorEmpleado = 0;
                    for(int i = 0; i < cantEmpleados; i++) {  // Inicializar `i`
                        if (empleados[i].promVentas > empleados[iMejorEmpleado].promVentas) {
                            iMejorEmpleado = i;
                        }
                    }

                    if(empleados[iMejorEmpleado].promVentas >= 2001 && empleados[iMejorEmpleado].promVentas <= 5000) {
                        strcpy(empleados[iMejorEmpleado].categoria, "Excelente");
                    } else if(empleados[iMejorEmpleado].promVentas >= 501 && empleados[iMejorEmpleado].promVentas <= 2000) {
                        strcpy(empleados[iMejorEmpleado].categoria, "Sobresaliente");
                    } else if(empleados[iMejorEmpleado].promVentas <= 500) {
                        strcpy(empleados[iMejorEmpleado].categoria, "Satisfactorio");
                    }

                    cout << "Empleado del Mes:\n";
                    cout << "Nombre: " << empleados[iMejorEmpleado].nombre << endl;
                    cout << "Apellido: " << empleados[iMejorEmpleado].apellido << endl;
                    cout << "Promedio de Ventas: $" << fixed << setprecision(2) << empleados[iMejorEmpleado].promVentas << endl;
                    cout << "Categoria: " << empleados[iMejorEmpleado].categoria << endl;
                    cout<< "Presiona cualquier tecla para continuar: \n";
                    getch();
                    system("cls");

                } else {
                    cout<< "No se han agregado empleados para determinar cual es el de la semana\n";
                    cout<< "Presiona cualquier tecla para continuar: \n";
                    getch();
                    system("cls");
                }
                break;

            case 4:
                cout<< "GRACIAS POR USAR EL PROGRAMA\n";
                cout<< "Presiona cualquier tecla para salir: \n";
                getch();
                system("cls");
                break;

            default:
                cout<< "ERROR... LA OPCION < " << opc << " > NO EXISTE\n";
                cout<< "Presiona cualquier tecla para continuar: \n";
                getch();
                system("cls");
                break;
        }
    } while(opc != 4);

    return 0;
}
