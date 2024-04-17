//Diseña una clase llamada Empleado con los siguientes atributos: nombre, apellido, edad y salario.
//Implementa métodos para establecer y obtener los valores de los atributos.
//Crea un programa principal que permita al usuario ingresar los datos de varios empleados y los
//almacene en un archivo de texto llamado empleados.txt;.
//Asegúrate de que el programa pueda manejar la escritura y la lectura de los datos del archivo de
//manera adecuada.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Empleado {
private:
    string nombre;
    string apellido;
    int edad;
    float salario;

public:
 
    Empleado() {}


    void establecerNombre(const string& nombre) {
        this->nombre = nombre;
    }

    void establecerApellido(const string& apellido) {
        this->apellido = apellido;
    }

    void establecerEdad(int edad) {
        this->edad = edad;
    }

    void establecerSalario(float salario) {
        this->salario = salario;
    }


    string obtenerNombre() const {
        return nombre;
    }

    string obtenerApellido() const {
        return apellido;
    }

    int obtenerEdad() const {
        return edad;
    }

    float obtenerSalario() const {
        return salario;
    }
};

int main() {

    Empleado empleado;


    ofstream archivo("empleados.txt");

 
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }


    char continuar;
    do {
        string nombre, apellido;
        int edad;
        float salario;


        cout << "Ingrese nombre: ";
        cin >> nombre;
        empleado.establecerNombre(nombre);

        cout << "Ingrese apellido: ";
        cin >> apellido;
        empleado.establecerApellido(apellido);

        cout << "Ingrese edad: ";
        cin >> edad;
        empleado.establecerEdad(edad);

        cout << "Ingrese salario: ";
        cin >> salario;
        empleado.establecerSalario(salario);

   
        archivo << empleado.obtenerNombre() << " "
                << empleado.obtenerApellido() << " "
                << empleado.obtenerEdad() << " "
                << empleado.obtenerSalario() << endl;

        cout << "¿Desea ingresar otro empleado? (s/n): ";
        cin >> continuar;
    } while (continuar == 's' || continuar == 'S');


    archivo.close();

    cout << "Datos de empleados almacenados en el archivo empleados.txt" << endl;

    return 0;
}
