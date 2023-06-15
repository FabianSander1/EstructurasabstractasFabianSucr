# Nombre

Análisis de tráfico fronterizo entre Estados Unidos y sus vecinos


## Descripción

Este proyecto analiza datos sobre el tráfico fronterizo entre los Estados Unidos y sus países vecinos, Canadá y México. El objetivo es entender mejor los patrones de tráfico y las tendencias relacionadas con las diferentes fronteras, estados y medios de transporte.

Los datos utilizados en este proyecto están disponibles en [https://data.bts.gov/api/views/keg4-3bc2/rows.csv?accessType=DOWNLOAD].

## Autor

FabianSander1 (Fabián Sander Hangen).

## Cómo correr el programa

Para correr el programa, simplemente ejecuta el acomendo `mingw32-make`. Si eso no funciona, se puede escribir `py main.py` en la consola.

## Cómo funciona

El programa consta de tres archivos:

1. `limpieza.py`: Este archivo se encarga de descargar los datos, seleccionar las columnas de interés y preparar el DataFrame para el análisis.

2. `graficar.py`: Este archivo utiliza el DataFrame creado en `limpieza.py` para realizar un análisis de los datos y crear gráficos basados en este análisis.

3. `main.py`: Este archivo se encarga de llamar a la función `graficar` y mostrar los gráficos resultantes.

## Resultados e interpretación

Los resultados del análisis proporcionan información detallada sobre los patrones de tráfico fronterizo. Estos patrones se representan a través de tres gráficos: distribución de entradas por frontera, los seis estados más transitados y los cinco medios de transporte más comunes.

### Distribución de entradas por frontera

El primer gráfico muestra la distribución de entradas por frontera. Esto puede ayudar a entender qué fronteras son las más transitadas y podrían requerir más recursos y personal.

### Los seis estados más transitados

El segundo gráfico muestra los seis estados más transitados. Esta información puede ser útil para determinar qué estados pueden necesitar más apoyo en términos de infraestructura y recursos de seguridad.

### Los cinco medios de transporte más comunes

El tercer gráfico muestra los cinco medios de transporte más comunes utilizados para cruzar la frontera. Este análisis puede proporcionar información sobre los modos de transporte que podrían requerir mayor atención en términos de mantenimiento de infraestructuras y medidas de seguridad.

## Conclusiones y observaciones

A través del análisis y la interpretación de estos datos, podemos obtener una mejor comprensión de los patrones y tendencias del tráfico fronterizo entre Estados Unidos y sus vecinos. Esta información puede ser útil para la planificación y asignación de recursos, tanto a nivel de los estados individuales como de la nación en su conjunto.

Es importante tener en cuenta que estos resultados se basan en una muestra de los datos disponibles. Para una visión más completa, se recomienda llevar a cabo un análisis más detallado utilizando el conjunto de datos completo.

## Posibles aplicaciones

Los hallazgos de este análisis pueden tener varias aplicaciones, como ayudar a las agencias gubernamentales a planificar mejor la asignación de recursos y personal, informar las políticas de infraestructura y seguridad, y proporcionar a los investigadores datos valiosos sobre los patrones de tráfico fronterizo.

## Resultados

![Gráficos](Tarea5/imagen.png)
