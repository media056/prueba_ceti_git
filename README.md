# 📘 Asesoría de Git — Control de Versiones para Estudiantes

Guía práctica para trabajar en equipo con Git sin perder el código de nadie.  
Sigue los pasos en orden y consulta la sección de errores si algo sale mal.

---

## 🧠 Conceptos Clave Antes de Empezar

| Término | Qué significa en simple |
|---|---|
| **Repositorio** | La carpeta del proyecto guardada en la nube (GitHub) |
| **Rama (branch)** | Tu espacio personal de trabajo, no afecta a los demás |
| **Commit** | Una foto del estado de tu código en un momento |
| **Push** | Subir tus commits a GitHub |
| **Pull** | Bajar los cambios que subieron tus compañeros |
| **Merge** | Unir dos ramas en una sola |
| **Conflicto** | Cuando dos personas editaron el mismo archivo y Git no sabe cuál versión usar |

---

## 🚀 Flujo Completo Paso a Paso

### Paso 1 · Clonar el proyecto (solo la primera vez)

Trae el repositorio de GitHub a tu computadora:

```bash
git clone https://github.com/usuario/nombre-del-repo.git
cd nombre-del-repo
```

---

### Paso 2 · Antes de escribir código — sincronízate

Siempre descarga los cambios más recientes antes de empezar:

```bash
git checkout dev
git pull origin dev
```

> ⚠️ Si salteas este paso, es muy probable que tengas conflictos al final.

---

### Paso 3 · Crea tu propia rama

Nunca trabajes directo en `dev` o `main`. Crea tu espacio personal:

```bash
git checkout -b feat/tu-nombre-modulo
```

**Ejemplos reales:**
```bash
git checkout -b feat/julian-empleados
git checkout -b feat/alizzeth-menu
git checkout -b feat/angel-repositorio
```

> Una rama por módulo o funcionalidad. Nombres en minúsculas, sin espacios.

---

### Paso 4 · Revisa en qué rama estás

Antes de escribir código, confirma que estás en tu rama y no en `dev`:

```bash
git branch
```

La rama activa aparece con un `*` al lado. Si no estás en la correcta:

```bash
git checkout feat/tu-nombre-modulo
```

---

### Paso 5 · Guarda tus cambios (Commit)

Cuando tu código compile sin errores, guarda un punto de control:

```bash
git add .
git commit -m "feat: descripción breve de lo que hiciste"
```

**Ejemplos de buenos mensajes:**
```bash
git commit -m "feat: agrega clase Empleado con herencia"
git commit -m "fix: corrige cálculo de comisión en Administrador"
git commit -m "docs: agrega comentarios al módulo de rentas"
```

> Haz commits frecuentes, no esperes a terminar todo para guardar.

---

### Paso 6 · Sube tu código a GitHub (Push)

```bash
git push origin HEAD
```

Si es la primera vez que subes esa rama:

```bash
git push --set-upstream origin feat/tu-nombre-modulo
```

---

### Paso 7 · Pide que integren tu código (Pull Request)

1. Entra a tu repositorio en [github.com](https://github.com)
2. Verás un botón amarillo que dice **"Compare & pull request"** — haz clic
3. Asegúrate de que la rama destino sea `dev`, no `main`
4. Escribe un título claro y describe brevemente qué hiciste
5. Haz clic en **"Create pull request"**

> El responsable de integración revisará tu código antes de unirlo al proyecto.

---

## 📋 Comandos de Consulta Útiles

```bash
# Ver el estado de tus archivos (modificados, nuevos, sin guardar)
git status

# Ver el historial de commits
git log --oneline

# Ver todas las ramas (locales y remotas)
git branch -a

# Ver qué cambios hiciste antes de hacer commit
git diff

# Ver en qué rama estás actualmente
git branch
```

---

## ⚠️ Errores Comunes y Cómo Solucionarlos

---

### ❌ Error: CONFLICT — Conflicto al hacer pull

**Mensaje típico:**
```
CONFLICT (content): Merge conflict in src/models/Empleado.cpp
Automatic merge failed; fix conflicts and then commit the result.
```

**Qué pasó:** Tú y un compañero editaron el mismo archivo al mismo tiempo.

**Solución paso a paso:**

1. Abre el archivo con conflicto en tu editor. Verás esto:
```
<<<<<<< HEAD
// Tu código local
=======
// El código de tu compañero
>>>>>>> dev
```

2. Borra las tres líneas de marcas (`<<<<<<<`, `=======`, `>>>>>>>`)
3. Deja el código correcto, combinando ambas versiones si es necesario
4. Guarda el archivo y ejecuta:
```bash
git add .
git commit -m "fix: resolviendo conflicto en Empleado.cpp"
git push origin HEAD
```

---

### ❌ Error: "Your local changes would be overwritten by merge"

**Mensaje típico:**
```
error: Your local changes to the following files would be overwritten by merge
```

**Qué pasó:** Tienes cambios sin guardar y estás intentando hacer pull.

**Solución — Opción A (guardar primero):**
```bash
git add .
git commit -m "wip: guardando avance antes de sincronizar"
git pull origin dev
```

**Solución — Opción B (guardar temporalmente con stash):**
```bash
git stash          # Guarda tus cambios temporalmente
git pull origin dev
git stash pop      # Recupera tus cambios
```

---

### ❌ Error: "fatal: not a git repository"

**Mensaje típico:**
```
fatal: not a git repository (or any of the parent directories): .git
```

**Qué pasó:** Estás ejecutando comandos de Git en una carpeta que no es el proyecto.

**Solución:**
```bash
# Navega a la carpeta correcta del proyecto
cd ruta/al/proyecto-hotel-poo

# Verifica que ahora sí estás dentro
git status
```

---

### ❌ Error: "rejected — non-fast-forward"

**Mensaje típico:**
```
! [rejected] feat/mi-rama -> feat/mi-rama (non-fast-forward)
error: failed to push some refs
```

**Qué pasó:** Alguien más subió cambios a esa rama y tu versión local está desactualizada.

**Solución:**
```bash
git pull origin feat/tu-nombre-modulo
# Si hay conflictos, resuélvelos (ver sección de conflictos arriba)
git push origin HEAD
```

---

### ❌ Error: "Author identity unknown" — sin nombre configurado

**Mensaje típico:**
```
Author identity unknown
Please tell me who you are.
```

**Qué pasó:** Git no sabe quién eres en esta computadora. Solo pasa la primera vez.

**Solución:**
```bash
git config --global user.name "Tu Nombre"
git config --global user.email "tu@correo.com"
```

---

### ❌ Hice commit en la rama equivocada

**Situación:** Hiciste commit en `dev` en lugar de tu rama personal.

**Solución:**
```bash
# Crea tu rama desde donde estás (lleva el commit contigo)
git checkout -b feat/tu-nombre-modulo

# Vuelve a dev y quítale ese commit
git checkout dev
git reset --hard origin/dev
```

---

### ❌ Quiero deshacer mi último commit (sin perder el código)

```bash
git reset --soft HEAD~1
```

> Esto deshace el commit pero conserva tus archivos editados. Puedes volver a hacer commit cuando estés listo.

---

## 📌 Convención de Commits

Usar un prefijo estándar ayuda a entender el historial del proyecto de un vistazo:

| Prefijo | Cuándo usarlo |
|---|---|
| `feat:` | Agregas funcionalidad nueva |
| `fix:` | Corriges un error |
| `refactor:` | Reorganizas código sin cambiar su comportamiento |
| `docs:` | Cambios solo en documentación o comentarios |
| `wip:` | Trabajo en progreso, aún no terminado |

---

## 🔁 Resumen Visual del Flujo

```
[GitHub - rama dev]
       │
       │  git pull origin dev
       ▼
[Tu compu - rama dev actualizada]
       │
       │  git checkout -b feat/tu-modulo
       ▼
[Tu rama personal]
       │
       │  escribes código → git add . → git commit
       │  (repite las veces que necesites)
       ▼
[Tu rama con commits]
       │
       │  git push origin HEAD
       ▼
[GitHub - tu rama]
       │
       │  Pull Request → revisión → merge
       ▼
[GitHub - rama dev actualizada para todos]
```

---

*Asesoría de Git · CETI Plantel Colomos · Ingeniería en Desarrollo de Software*
