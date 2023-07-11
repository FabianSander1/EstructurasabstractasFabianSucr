def contar_palabras(cadena):
    # Se separa la cadena en palabras basándose en los espacios
    palabras = cadena.split()

    # Se crea un diccionario vacío para almacenar las frecuencias
    frecuencias = {}

    # Se itera sobre cada palabra en la lista de palabras
    for palabra in palabras:
        # Si la palabra ya está en el diccionario, se incrementa su frecuencia
        if palabra in frecuencias:
            frecuencias[palabra] += 1
        # Si la palabra no está en el diccionario, se añade con frecuencia 1
        else:
            frecuencias[palabra] = 1

    # Se retorna el diccionario de frecuencias
    return frecuencias


# Ejemplo de uso de la función
texto = "hola hola como esta fabian fabian esta bien hola mundo"
frecuencias = contar_palabras(texto)
print(frecuencias)
