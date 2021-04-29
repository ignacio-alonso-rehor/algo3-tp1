# algo3-tp1
TP1 de la materia Algoritmos y Estructuras de Datos III. Primer cuatrimestre
2021.

## Integrantes

| Nombre                  | LU     | Mail                     |
| ----------------------- | ------ | ------------------------ |
| Dacunda Ratti, Jerónimo | 710/18 | jero.d.r22@gmail.com     |
| Alonso Rehor, Ignacio   | 195/18 | arehor.ignacio@gmail.com |

## Implementación

En `tp1/src/main.cpp` se encuentra toda la implementación en C++ del TP,
siguendo la especificación de IO del enunciado (resultado por stdout y tiempo de
ejecución por stderr). Para compilar basta con hacer `make` en la carpeta
`tp1/`.

Uso:

```sh
$ ./tp1/jt <algorithm> <filename>
```

Ejemplo:

```sh
$ ./tp1/jt DP tp1/ejemplo.txt
0.008342
3
```

## Experimentación

La experimentación se realizó con python, usando las bibliotecas `pandas` y
`seaborn`. Los notebooks hay que correrlos en el siguiente orden:

1. `exp/instancias.ipynb`: Genera las instancias para luego correr los
   algoritmos. Estas se almacenan en `exp/instancias`.
2. `exp/correr_experimentos.ipynb`: Corre los experimentos y guarda los
   resultados en `exp/resultados.csv`
3. `exp/analisis.ipynb`: Analiza los resultados obtenidos, genera las
   imagenes luego usadas en el informe.

Para correrlos se recomienda instalar primero los *requirements* (`pip3 install
-r requirements.txt`) dentro de un virtual env.

## Informe

El pdf se encuentra en [`informe/informe.pdf`](informe/informe.pdf), junto con
sus sources.