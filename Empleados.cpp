#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
using namespace std;

struct VentaSem
{
    float ventas[5];
};

struct Empleado
{
    string nombre, apellido, correo, telefono;
    double ci;
    float promV;
    VentaSem semanal[5];
    char categoria[20];
};

int main()
{
    int opc;
    int cantEmpleados;
    bool archivoCreado = false;
    string lineaTexto;
    string res;
    string nombreArchivo = "Empleados.txt";
    ofstream archivoCrear;
    ifstream archivoLeer;

    cout<< "===========Binvenido al sistema de Empleados===========\n";
    cout<< "Inserte la cantidad de empleados de que desea trabajar: ";
    cin>> cantEmpleados;
    Empleado empleados[cantEmpleados];
    system("cls");
    do
    {
        cout << "\n*** MENU PRINCIPAL ***\n";
        cout << "1.-Agregar Empleados\n";
        cout << "2.-Visualizar Empleados\n";
        cout << "3.-Visualizar al empleado del Mes\n";
        cout << "4.-Salir\n";
        cout << "Elija su opción: ";
        cin>> opc;
        system("cls");


        switch(opc)
        {
        case 1:
            if(!archivoCreado)
            {
                cout<< "\n*** AGREGAR EMPLEADOS ***\n";
                for(int i = 0; i<cantEmpleados; i++)
                {
                    cout<< "Ingrese los datos del Empleado Nro: " << i+1 << endl;
                    cout<< "Nombre: ";
                    cin>> empleados[i].nombre;
                    cout<< "Apellido: ";
                    cin>> empleados[i].apellido;
                    cout<< "Cedula: ";
                    cin>> empleados[i].ci;
                    cout<< "Telefono: ";
                    cin>> empleados[i].telefono;
                    cout<< "Correo: ";
                    cin>> empleados[i].correo;

                    float sumaTotal = 0;
                    for(int j = 0; j<5; j++)
                    {
                        float sumaSemana = 0;

                        cout<< "Ingrese las ventas de la semana "<< j+1<< endl;
                        for(int k = 0; k<5; k++)
                        {
                            cout<< "Dia " << k+1<< ": ";
                            cin>> empleados[i].semanal[j].ventas[k];
                            sumaSemana += empleados[i].semanal[j].ventas[k];
                        }
                        float promedioSemana = sumaSemana / 5;
                        cout<< promedioSemana << endl;
                        sumaTotal += promedioSemana;
                    }
                    empleados[i].promV = sumaTotal / 5;
                    cout<< empleados[i].promV<< endl;
                }

                for(int i = 0; i < cantEmpleados - 1; i++)
                {
                    for(int j = 0; j < cantEmpleados - i - 1; j++)
                    {
                        if(empleados[j].ci > empleados[j+1].ci)
                        {
                            Empleado temp = empleados[j];
                            empleados[j] = empleados[j+1];
                            empleados[j+1] = temp;
                        }
                    }
                }
                cout<< "Empleados Agregados Sastifactoriamente" << endl;

                //guardar en el archivo
                archivoCrear.open(nombreArchivo.c_str(), ios::out);
                if(archivoCrear.fail())
                {

                    cout<< "No se puede abrir";
                    exit(1);
                }
                archivoCrear<<"=======LISTA DE EMPLEADOS======="<< endl;
                for(int i = 0; i<cantEmpleados; i++)
                {
                    fflush(stdin);
                    archivoCrear<<"Empleado Nro "<< i+1 << endl;
                    archivoCrear<<"Nombre: "<< empleados[i].nombre << endl;
                    archivoCrear<<"Apellido: "<< empleados[i].apellido << endl;
                    archivoCrear<<"Cedula: "<< empleados[i].ci << endl;
                    archivoCrear<<"Telefono: "<< empleados[i].telefono << endl;
                    archivoCrear<<"Correo: "<< empleados[i].correo << endl;
                    archivoCrear<<"~~~~Ventas Del empleado Nro "<< i << " ~~~~"<<  << endl;
                    for(int j = 0; j< 5; j++)
                    {
                        archivoCrear<<"Ventas de la semana: "<<j+1<< endl;
                        for(int k = 0; k< 5; k++)
                        {
                            archivoCrear<<"Ventas del dia: "<< k+1<< empleados[i].semanal[i].ventas[k]<<  endl;
                        }
                        archivoCrear<<"~~~~~~~~~~"<< endl;
                    }
                    archivoCrear<<"Promedio del ventas del mes: "<< empleados[i].promV << endl;
                    archivoCrear<<"======================================="<< endl;
                }
                archivoCrear.clear();
                archivoCreado = true;
                cout<< "Presiona cualquier tecla para continuar: \n";
                getch();
                system("cls");
            }
            else
            {
                cout<< "El archivo ya se creo"<< endl;
                cout<< "Presiona cualquier tecla para continuar: \n";
                getch();
                system("cls");
            }


            break;

        case 2:
            if(archivoCreado)
            {
                cout<< "\n*** VISUALIZAR EMPLEADOS DESDE EL ARCHIVO ***\n";
                archivoLeer.open(nombreArchivo.c_str(), ios::out);
                if(archivoLeer.fail())
                {
                    cout<< "No se puede abrir";
                    exit(1);
                }
                while(!archivoLeer.eof())
                {

                    getline(archivoLeer, lineaTexto);
                    cout<< lineaTexto<< endl;


                }
                archivoLeer.close();
                cout<< "Presiona cualquier tecla para continuar: \n";
                getch();
                system("cls");

            }
            else
            {
                cout<< "No se han agreados empleados"<< endl;
                cout<< "Presiona cualquier tecla para continuar: \n";
                getch();
                system("cls");
            }

            break;

        case 3:
            if(archivoCreado)
            {
                cout << "\n*** VISUALIZAR EMPLEADO DEL MES ***\n";
                int indiceMejorEmpleado = 0;

                for (int i = 1; i < cantEmpleados; i++)
                {
                    if (empleados[i].promV > empleados[indiceMejorEmpleado].promV)
                    {
                        indiceMejorEmpleado = i;
                    }
                }

                if (empleados[indiceMejorEmpleado].promV >= 2001 && empleados[indiceMejorEmpleado].promV <= 5000)
                {
                    strcpy(empleados[indiceMejorEmpleado].categoria, "Excelente");
                }
                else if (empleados[indiceMejorEmpleado].promV >= 501 && empleados[indiceMejorEmpleado].promV <= 2000)
                {
                    strcpy(empleados[indiceMejorEmpleado].categoria, "Sobresaliente");
                }
                else if (empleados[indiceMejorEmpleado].promV <= 500)
                {
                    strcpy(empleados[indiceMejorEmpleado].categoria, "Satisfactorio");
                }

                cout << "Empleado del Mes:\n";
                cout << "Nombre: " << empleados[indiceMejorEmpleado].nombre << endl;
                cout << "Apellido: " << empleados[indiceMejorEmpleado].apellido << endl;
                cout << "Promedio de Ventas: $" << fixed << setprecision(2) << empleados[indiceMejorEmpleado].promV << endl;
                cout << "Categoría: " << empleados[indiceMejorEmpleado].categoria << endl;
                cout<< "Presiona cualquier tecla para continuar: \n";
                getch();
                system("cls");
            }
            else
            {
                cout<< "No se han agreagado empleados" << endl;
                cout<< "Presiona cualquier tecla para continuar: \n";
                getch();
                system("cls");
            }
            break;

        case 4:
            cout<< "Gracias por usar el programa... Hasta luego..."<< endl;
        default:

            cout<<"ERROR!!! OPCION "<<opc << " NO EXISTE, POR FAVOR VUELVELO A INTENTAR" << endl;
        }
    }
    while(opc != 4);
    return 0;
}
