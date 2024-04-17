#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Empleado {
    string nombre;
    string apellido;
    int edad;
    float salario;
};

void mostrarInformacionEmpleado(const Empleado& empleado) {
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Apellido: " << empleado.apellido << endl;
    cout << "Edad: " << empleado.edad << endl;
    cout << "Salario: " << empleado.salario << endl;
}

Empleado buscarEmpleado(const string& nombreCompleto, const string& archivo) {
    Empleado empleadoEncontrado;
    ifstream inputFile(archivo);
    string nombre, apellido;
    int edad;
    float salario;

    while (inputFile >> nombre >> apellido >> edad >> salario) {
        if (nombre + " " + apellido == nombreCompleto) {
            empleadoEncontrado.nombre = nombre;
            empleadoEncontrado.apellido = apellido;
            empleadoEncontrado.edad = edad;
            empleadoEncontrado.salario = salario;
            break;
        }
    }

    inputFile.close();
    return empleadoEncontrado;
}

int main() {
    string archivo = "empleados.txt";
    string nombreCompleto;

    while (true) {
        cout << "Ingrese el nombre completo del empleado (o 'salir' para terminar): ";
        getline(cin, nombreCompleto);

        if (nombreCompleto == "salir") {
            cout << "Gracias!" << endl;
            break;
        }

        Empleado empleado = buscarEmpleado(nombreCompleto, archivo);
        if (empleado.nombre.empty()) {
            cout << "El empleado no se encontró en el archivo." << endl;
        } else {
            cout << "Informacion del empleado:" << endl;
            mostrarInformacionEmpleado(empleado);
        }
    }

    return 0;
}
