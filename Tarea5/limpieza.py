import pandas as pd

# URL de los datos
url = 'https://data.bts.gov/api/views/keg4-3bc2/rows.csv?accessType=DOWNLOAD'
archivo_csv = 'completo.csv'


def obtener_df():
    """
    Función para descargar los datos y convertirlos en un DataFrame.
    """
    # Descarga los datos y los guarda en un CSV
    df_completo = pd.read_csv(url)
    df_completo.to_csv(archivo_csv, index=False)

    # Selecciona las columnas de interés y devuelve las primeras 100 filas
    columnas_seleccionadas = ['Border', 'State', 'Measure']
    df_filtrado = pd.read_csv(archivo_csv,
                              usecols=columnas_seleccionadas).head(100)

    return df_filtrado
