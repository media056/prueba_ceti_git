//
// Created by media056 on 28/05/26.
//

#ifndef SUPERHEROES_POO_SUPERHEROE_H
#define SUPERHEROES_POO_SUPERHEROE_H
#include <string>
#include <iostream>
using namespace std;

class Superheroe {

protected:
    string nombre;
    int    nivel_poder;
    string ciudad;

public:
    // ── Constructor ──────────────────────────────────────────
    Superheroe(string nombre, int nivel_poder, string ciudad)
        : nombre(nombre), nivel_poder(nivel_poder), ciudad(ciudad) {}

    // ── Destructor virtual ───────────────────────────────────
    // Obligatorio en toda clase base para evitar memory leaks
    virtual ~Superheroe() {}

    // ── Métodos virtuales puros ──────────────────────────────
    // Cada subclase DEBE implementar estos dos métodos
    virtual void usarPoder()    = 0;
    virtual void presentarse()  = 0;

    // ── Método concreto compartido ───────────────────────────
    // Este sí se hereda igual para todos, no necesita override
    void mostrarInfo() {
        cout << "──────────────────────────────" << endl;
        cout << "Héroe      : " << nombre       << endl;
        cout << "Nivel poder: " << nivel_poder  << endl;
        cout << "Ciudad     : " << ciudad       << endl;
        cout << "──────────────────────────────" << endl;
    }

    // ── Getters ──────────────────────────────────────────────
    string getNombre()     { return nombre;       }
    int    getNivelPoder() { return nivel_poder;  }
    string getCiudad()     { return ciudad;       }
};

#endif //SUPERHEROES_POO_SUPERHEROE_H
