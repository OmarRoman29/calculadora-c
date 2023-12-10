# Calculadora en C

## Indice
1. [Introducción](#introducción)

## Introducción

Este es un proyecto más de un intento de calculadora más en C y usando GTK3, no
pretende ser un proyectodemasiado serio pero en caso que alguien esté buscando 
una referencia para un proyecto de este estilo en C, siéntete libre de mirar y
usar mi código. Seguramente este código esté lleno de mala documentación, malas 
prácticas y código espagueti, lo siento pero aún sigo aprendiendo jeje.

## Compilar el proyecto
Si estás en Windows necesitarás descargar las dependencias necesarias como la 
librería de GTK3 y el compilador en C, para eso visita el sitio oficial y descarga
MSYS2 y una vez instalado descarga en MSYS mingw las dependencias como GTK3 y las
herramientas para compilar indicadas en los pasos (se muestra como opcionales pero
en este caso son necesarias). [GTK3 instalación](https://www.gtk.org/docs/installations/windows/).

### CMAKE
Una vez instalado lo necesario deben clonar el repositorio y crear una carpeta llamada
`build` asegúrese de tener cmake en su sistema (Linux o Windows).

```bash
git clone https://github.com/OmarRoman29/calculadora-c.git
cd calculadora-c/
mkdir build
cd build
cmake ..
```

Y una vez realizado esto utilicen `make` o `ninja` para compilar el proyecto, también
debe estar instalado en su sistema.

### Alternativa
En caso de no poder compilar en cmake (a veces msys hace cosas raras) podemos hacer uso
del comando largo que al final debe ser lo mismo.

```bash
git clone https://github.com/OmarRoman29/calculadora-c.git
cd calculadora-c/
mkdir build
cd build
gcc `pkg-config --cflags gtk+-3.0` -o calc ../src/*.c `pkg-config --libs gtk+-3.0`
```

## TODO
Más de la mitad de ellos seguramente no sepa como hacerlos, pero pues peor es nada

- ~Crear repo xd~ 
- Crear interfaz base
- Sistema de operaciones base
- Verificar paréntesis
- Historial de operaciones anteriores
