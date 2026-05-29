# 🦸 Sistema de Superhéroes — Ejemplo de POO en C++

Guía práctica de Programación Orientada a Objetos con C++17.  
Este repositorio es un **ejemplo de referencia** para aprender herencia, polimorfismo y clases abstractas trabajando en equipo con Git.

---

## 👥 Equipo y Roles

| Integrante | Rol | Responsabilidad |
|---|---|---|
| **Ángel** | 🏆 Líder / Integrador | Clase base abstracta `Superhéroe` + `main.cpp` + merge final |
| **Andrea** | ⚡ Módulo de Héroe 1 | Subclase `Flash` — velocidad y movimiento |
| **Julián** | 🦇 Módulo de Héroe 2 | Subclase `Batman` — gadgets e inteligencia |
| **Samantha** | 🕷️ Módulo de Héroe 3 | Subclase `SpiderMan` — trepar y sentido arácnido |
| **Daniel** | 🔨 Módulo de Héroe 4 | Subclase `Thor` — fuerza y relámpagos |
| **Ismael** | 🧪 Tester / Reportes | Pruebas del sistema, reporte de errores y documentación |

---

## 🧠 Arquitectura del Programa

El sistema sigue una jerarquía de herencia clásica:

```
         [ Superheroe ]        ← Clase abstracta (Ángel)
         /     |     \  \
      Flash  Batman  SpiderMan  Thor    ← Subclases concretas
   (Andrea) (Julián)(Samantha)(Daniel)

        main.cpp + pruebas     ← Integración (Ángel + Ismael)
```

### ¿Por qué abstracta la clase base?

Porque ningún objeto debe ser solo un "Superhéroe genérico". Siempre será Flash, Batman, etc.  
La clase abstracta obliga a que cada subclase implemente sus propios métodos.

---

## 📂 Estructura del Repositorio

```
/proyecto-superheroes-poo
├── /include
│   ├── Superheroe.h       # Clase abstracta base (Ángel)
│   ├── Flash.h            # Declaración Flash (Andrea)
│   ├── Batman.h           # Declaración Batman (Julián)
│   ├── SpiderMan.h        # Declaración SpiderMan (Samantha)
│   └── Thor.h             # Declaración Thor (Daniel)
├── /src
│   ├── main.cpp           # Punto de entrada (Ángel)
│   ├── Flash.cpp          # Implementación Flash (Andrea)
│   ├── Batman.cpp         # Implementación Batman (Julián)
│   ├── SpiderMan.cpp      # Implementación SpiderMan (Samantha)
│   └── Thor.cpp           # Implementación Thor (Daniel)
├── CMakeLists.txt
└── README.md
```

---

## 💻 Código de Ejemplo

### `Superheroe.h` — Clase Abstracta Base (Ángel)

```cpp
#pragma once
#include <string>
using namespace std;

// Clase abstracta: no se puede instanciar directamente
class Superheroe {
protected:
    string nombre;
    int nivel_poder;
    string ciudad;

public:
    // Constructor
    Superheroe(string nombre, int nivel_poder, string ciudad)
        : nombre(nombre), nivel_poder(nivel_poder), ciudad(ciudad) {}

    // Destructor virtual — obligatorio en clases base
    virtual ~Superheroe() {}

    // Métodos virtuales puros — cada subclase DEBE implementarlos
    virtual void usarPoder() = 0;
    virtual void presentarse() = 0;

    // Método concreto compartido por todos
    void mostrarInfo() {
        cout << "Héroe: " << nombre
             << " | Poder: " << nivel_poder
             << " | Ciudad: " << ciudad << endl;
    }

    // Getters
    string getNombre() { return nombre; }
    int getNivelPoder() { return nivel_poder; }
};
```

---

### `Flash.h` — Declaración (Andrea)

```cpp
#pragma once
#include "Superheroe.h"

class Flash : public Superheroe {
private:
    int velocidad_max; // en km/h

public:
    Flash(string nombre, int nivel_poder, string ciudad, int velocidad_max);

    void usarPoder() override;
    void presentarse() override;
    void correrEnElTiempo(); // Método exclusivo de Flash
};
```

### `Flash.cpp` — Implementación (Andrea)

```cpp
#include "../include/Flash.h"
#include <iostream>
using namespace std;

Flash::Flash(string nombre, int nivel_poder, string ciudad, int velocidad_max)
    : Superheroe(nombre, nivel_poder, ciudad), velocidad_max(velocidad_max) {}

void Flash::usarPoder() {
    cout << nombre << " corre a " << velocidad_max << " km/h!" << endl;
}

void Flash::presentarse() {
    cout << "Soy " << nombre << ", el hombre más rápido del mundo." << endl;
}

void Flash::correrEnElTiempo() {
    cout << nombre << " usa la Fuerza de la Velocidad para viajar en el tiempo!" << endl;
}
```

---

### `Batman.h` — Declaración (Julián)

```cpp
#pragma once
#include "Superheroe.h"

class Batman : public Superheroe {
private:
    int cantidad_gadgets;
    int inteligencia; // IQ

public:
    Batman(string nombre, int nivel_poder, string ciudad,
           int cantidad_gadgets, int inteligencia);

    void usarPoder() override;
    void presentarse() override;
    void usarBatarang(); // Método exclusivo de Batman
};
```

### `Batman.cpp` — Implementación (Julián)

```cpp
#include "../include/Batman.h"
#include <iostream>
using namespace std;

Batman::Batman(string nombre, int nivel_poder, string ciudad,
               int cantidad_gadgets, int inteligencia)
    : Superheroe(nombre, nivel_poder, ciudad),
      cantidad_gadgets(cantidad_gadgets), inteligencia(inteligencia) {}

void Batman::usarPoder() {
    cout << nombre << " usa su inteligencia (IQ: " << inteligencia
         << ") y " << cantidad_gadgets << " gadgets!" << endl;
}

void Batman::presentarse() {
    cout << "Soy " << nombre << ". Soy Batman." << endl;
}

void Batman::usarBatarang() {
    cout << nombre << " lanza un batarang con precisión perfecta!" << endl;
}
```

---

### `SpiderMan.h` — Declaración (Samantha)

```cpp
#pragma once
#include "Superheroe.h"

class SpiderMan : public Superheroe {
private:
    bool sentido_aracnido;
    int resistencia_tela; // kg que aguanta la tela

public:
    SpiderMan(string nombre, int nivel_poder, string ciudad,
              bool sentido_aracnido, int resistencia_tela);

    void usarPoder() override;
    void presentarse() override;
    void lanzarTela(); // Método exclusivo de SpiderMan
};
```

### `SpiderMan.cpp` — Implementación (Samantha)

```cpp
#include "../include/SpiderMan.h"
#include <iostream>
using namespace std;

SpiderMan::SpiderMan(string nombre, int nivel_poder, string ciudad,
                     bool sentido_aracnido, int resistencia_tela)
    : Superheroe(nombre, nivel_poder, ciudad),
      sentido_aracnido(sentido_aracnido), resistencia_tela(resistencia_tela) {}

void SpiderMan::usarPoder() {
    cout << nombre << " trepa edificios y lanza tela de "
         << resistencia_tela << " kg de resistencia!" << endl;
}

void SpiderMan::presentarse() {
    cout << "¡Soy " << nombre << ", tu amigable vecino Hombre Araña!" << endl;
}

void SpiderMan::lanzarTela() {
    cout << nombre << " lanza tela y se columpia entre rascacielos!" << endl;
}
```

---

### `Thor.h` — Declaración (Daniel)

```cpp
#pragma once
#include "Superheroe.h"

class Thor : public Superheroe {
private:
    string nombre_martillo;
    int fuerza; // toneladas

public:
    Thor(string nombre, int nivel_poder, string ciudad,
         string nombre_martillo, int fuerza);

    void usarPoder() override;
    void presentarse() override;
    void invocarRelampago(); // Método exclusivo de Thor
};
```

### `Thor.cpp` — Implementación (Daniel)

```cpp
#include "../include/Thor.h"
#include <iostream>
using namespace std;

Thor::Thor(string nombre, int nivel_poder, string ciudad,
           string nombre_martillo, int fuerza)
    : Superheroe(nombre, nivel_poder, ciudad),
      nombre_martillo(nombre_martillo), fuerza(fuerza) {}

void Thor::usarPoder() {
    cout << nombre << " levanta " << nombre_martillo
         << " con " << fuerza << " toneladas de fuerza!" << endl;
}

void Thor::presentarse() {
    cout << "Soy " << nombre << ", dios del trueno de Asgard!" << endl;
}

void Thor::invocarRelampago() {
    cout << nombre << " invoca un rayo desde los cielos!" << endl;
}
```

---

### `main.cpp` — Integración y Polimorfismo (Ángel)

```cpp
#include <iostream>
#include <vector>
#include "include/Superheroe.h"
#include "include/Flash.h"
#include "include/Batman.h"
#include "include/SpiderMan.h"
#include "include/Thor.h"
using namespace std;

int main() {
    // Polimorfismo: vector de punteros a la clase base
    vector<Superheroe*> equipo;

    equipo.push_back(new Flash("Barry Allen", 85, "Central City", 1200000));
    equipo.push_back(new Batman("Bruce Wayne", 90, "Gotham", 127, 190));
    equipo.push_back(new SpiderMan("Peter Parker", 80, "Nueva York", true, 500));
    equipo.push_back(new Thor("Thor Odinson", 95, "Asgard", "Mjolnir", 800));

    cout << "=== EQUIPO DE SUPERHEROES ===" << endl << endl;

    // Polimorfismo en acción: mismo llamado, distinto comportamiento
    for (Superheroe* heroe : equipo) {
        heroe->presentarse();
        heroe->usarPoder();
        heroe->mostrarInfo();
        cout << "-----------------------------" << endl;
    }

    // Liberar memoria
    for (Superheroe* heroe : equipo) {
        delete heroe;
    }

    return 0;
}
```

---

### `CMakeLists.txt`

```cmake
cmake_minimum_required(VERSION 3.20)
project(superheroes_poo)

set(CMAKE_CXX_STANDARD 17)

add_executable(superheroes_poo
    src/main.cpp
    src/Flash.cpp
    src/Batman.cpp
    src/SpiderMan.cpp
    src/Thor.cpp
)
```

---

## 🔄 Flujo de Trabajo Git por Integrante

### Ángel — Líder e Integrador

```bash
# Configura el repositorio inicial
git init
git remote add origin https://github.com/usuario/proyecto-superheroes.git

# Crea y sube la rama dev
git checkout -b dev
git add .
git commit -m "feat: estructura base del proyecto y clase abstracta Superheroe"
git push origin dev
```

### Andrea, Julián, Samantha, Daniel — Cada uno en su rama

```bash
# 1. Traer lo más reciente de dev
git checkout dev
git pull origin dev

# 2. Crear su rama personal
git checkout -b feat/andrea-flash      # Andrea
git checkout -b feat/julian-batman     # Julián
git checkout -b feat/samantha-spiderman # Samantha
git checkout -b feat/daniel-thor       # Daniel

# 3. Programar su módulo, luego guardar avances
git add .
git commit -m "feat: implementa clase Flash con método correrEnElTiempo"

# 4. Subir su rama
git push origin HEAD

# 5. Abrir Pull Request en GitHub hacia la rama dev
```

### Ismael — Tester

```bash
# Trabaja sobre dev para probar la integración final
git checkout dev
git pull origin dev
git checkout -b test/ismael-pruebas

# Documenta errores encontrados
git add .
git commit -m "fix: corrige error en constructor de SpiderMan"
git push origin HEAD
```

---

## 🧪 Responsabilidades de Ismael — Tester

Ismael no programa las clases, pero su rol es igual de importante:

- ✅ Verificar que el proyecto **compila sin errores** después de cada merge
- ✅ Probar que el **polimorfismo funciona** correctamente en `main.cpp`
- ✅ Revisar que **no haya memory leaks** (todos los `new` tienen su `delete`)
- ✅ Documentar en GitHub Issues cualquier error encontrado
- ✅ Escribir el reporte final del proyecto

---

## ⚠️ Errores Frecuentes en C++ POO

### ❌ Olvidar implementar un método virtual puro

```
error: cannot declare variable 'f' to be of abstract type 'Flash'
note: because the following virtual functions are pure within 'Flash'
note: virtual void Superheroe::usarPoder()
```

**Solución:** Revisa que Flash (o la subclase que marque error) tenga implementados **todos** los métodos marcados como `= 0` en la clase base.

---

### ❌ Olvidar el destructor virtual

Si la clase base no tiene `virtual ~Superheroe()`, al hacer `delete` sobre un puntero base no se llamará el destructor correcto de la subclase → **memory leak**.

```cpp
// ✅ Siempre en la clase base:
virtual ~Superheroe() {}
```

---

### ❌ No hacer `delete` después de `new`

```cpp
// ❌ Mal — memory leak
Superheroe* h = new Flash(...);
// ... nunca se libera

// ✅ Bien
Superheroe* h = new Flash(...);
// ... uso
delete h;
```

---

### ❌ Include circular entre headers

Si `Flash.h` incluye `Batman.h` y `Batman.h` incluye `Flash.h` → el compilador entra en bucle.

**Solución:** Usa `#pragma once` al inicio de cada `.h` y solo incluye lo que realmente necesitas.

---

## 📌 Convención de Commits

| Prefijo | Cuándo usarlo |
|---|---|
| `feat:` | Nueva clase o funcionalidad |
| `fix:` | Corrección de error |
| `refactor:` | Reorganización sin cambiar comportamiento |
| `test:` | Pruebas o correcciones del tester |
| `docs:` | Cambios en documentación |

---

## 🔁 Resumen del Flujo

```
[Ángel crea repo + clase base Superheroe]
              │
    ┌─────────┼──────────┐──────────┐
    ▼         ▼          ▼          ▼
 Andrea    Julián    Samantha    Daniel
 (Flash)  (Batman) (SpiderMan)  (Thor)
    │         │          │          │
    └─────────┴──────────┴──────────┘
              │  Pull Requests → dev
              ▼
        [Ismael prueba la integración]
              │
              ▼
        [Ángel hace merge final a main]
```

---

*Asesoría de C++ y POO · Ejemplo con Superhéroes · Control de versiones con Git*
