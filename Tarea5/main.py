import pandas as pd
import matplotlib.pyplot as plt


# Obtención de los datos y creación del archivo CSV
url = 'https://data.bts.gov/api/views/keg4-3bc2/rows.csv?accessType=DOWNLOAD'
archivo_csv = 'completo.csv'
df_completo = pd.read_csv(url)
df_completo.to_csv(archivo_csv, index=False)

# Lectura del archivo CSV y filtrado de columnas
columnas_seleccionadas = ['Border', 'State', 'Measure']
df_filtrado = pd.read_csv(archivo_csv,
                          usecols=columnas_seleccionadas).head(100)

# Limpieza y preparación de datos
columnas_existentes = df_filtrado.columns.tolist()
columnas_a_eliminar = ['Latitude', 'Longitude', 'Point']
columnas_a_eliminar = [col for col in columnas_a_eliminar if
                       col in columnas_existentes]
df_filtrado = df_filtrado.drop(columnas_a_eliminar, axis=1)

conteo_fronteras = df_filtrado['Border'].value_counts()

fig, axs = plt.subplots(1, 3, figsize=(15, 5))

# Imprimir DataFrame
print(df_filtrado)
