import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from matplotlib.colors import to_hex

# Obtención de los datos y creación del archivo CSV
url = 'https://data.bts.gov/api/views/keg4-3bc2/rows.csv?accessType=DOWNLOAD'
archivo_csv = 'completo.csv'
df_completo = pd.read_csv(url)
df_completo.to_csv(archivo_csv, index=False)

# Lectura del archivo CSV y filtrado de columnas
columnas_seleccionadas = ['Border', 'State', 'Measure']
df_filtrado = pd.read_csv(archivo_csv,
                          usecols=columnas_seleccionadas).head(100)

# Imprimir DataFrame
print(df_filtrado)

# Análisis de datos y creación de gráficos
conteo_fronteras = df_filtrado['Border'].value_counts()
etiquetas_fronteras = conteo_fronteras.index.tolist()
tamanos_fronteras = conteo_fronteras.values.tolist()

conteo_estados = df_filtrado['State'].value_counts().head(6)
etiquetas_estados = conteo_estados.index.tolist()
tamanos_estados = conteo_estados.values.tolist()

conteo_transportes = df_filtrado['Measure'].value_counts().head(5)
etiquetas_transportes = conteo_transportes.index.tolist()
valores_transportes = conteo_transportes.values.tolist()

# Crear subplots
fig, axs = plt.subplots(1, 3, figsize=(15, 5))

# Gráfico pastel de entradas por frontera (Border)
axs[0].pie(tamanos_fronteras, labels=etiquetas_fronteras,
           autopct='%1.1f%%', startangle=90)
axs[0].set_title('Distribución de entradas por frontera')

# Gráfico de líneas de los 6 estados más comunes
colores = plt.cm.Set3(np.linspace(0, 1, len(etiquetas_estados)))
colores_hex = [to_hex(color) for color in colores]
axs[1].plot(etiquetas_estados, tamanos_estados, color='blue', marker='o')
axs[1].set_title('Distribución de los 6 estados más transitados')
axs[1].set_xlabel('Estado')
axs[1].set_ylabel('Cantidad en las primeras 100 filas')
axs[1].tick_params(axis='x', rotation=45)

# Gráfico de barras de los 5 medios de transporte más comunes
colores = plt.cm.Set3(np.arange(len(etiquetas_transportes)))
axs[2].bar(etiquetas_transportes, valores_transportes, color=colores)
axs[2].set_title('Top 5 Medios de Transporte más comunes')
axs[2].set_xlabel('Medio de Transporte')
axs[2].set_ylabel('Frecuencia en las primeras 100 filas')
axs[2].tick_params(axis='x', rotation=45)

# Ajustar espacio entre subplots
plt.tight_layout()

# Mostrar gráficos
plt.show()

# https://data.bts.gov/api/views/keg4-3bc2/rows.csv?accessType=DOWNLOAD
