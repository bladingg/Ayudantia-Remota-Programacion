import time

texto = input("Digite el texto: ")
#Fuerza Bruta
def fuerza_bruta(texto, patron):
    n = len(texto)
    m = len(patron)
    
    
    for i in range(n-m+1):
        j = 0
        while j< m and texto [i+j] == patron [j]:
            j +=1
        if j == m:
            return i
    return -1


#KMP

def kmp_preprocesamiento(patrón):
    m = len(patrón)
    lps = [0] * m  # LPS: Longest Proper Prefix that is also Suffix
    largo = 0  # longitud del prefijo más largo
    i = 1

    while i < m:
        if patrón[i] == patrón[largo]:
            largo += 1
            lps[i] = largo
            i += 1
        else:
            if largo != 0:
                largo = lps[largo - 1]
            else:
                lps[i] = 0
                i += 1
    return lps
def kmp_buscar(texto, patron):
    n = len(texto)
    m = len(patron)
    lps = kmp_preprocesamiento(patron)
    i = 0  # índice para texto
    j = 0  # índice para patrón

    while i < n:
        if patron[j] == texto[i]:
            i += 1
            j += 1

        if j == m:
            return i - j  # se encontró el patrón
        elif i < n and patron[j] != texto[i]:
            if j != 0:
                j = lps[j - 1]
            else:
                i += 1

    return -1  # No se encontró


def boyer_moore_buscar(texto, patron):
    m = len(patron)
    n = len(texto)
    if m == 0:
        return 0
    bad_char = [-1] * 256  # Asumimos un alfabeto ASCII

    for i in range(m):
        bad_char[ord(patron[i])] = i

    s = 0  # s es el desplazamiento del patrón en relación al texto
    while s <= n - m:
        j = m - 1

        while j >= 0 and patron[j] == texto[s + j]:
            j -= 1

        if j < 0:
            return s  # Se encontró el patrón
        else:
            s += max(1, j - bad_char[ord(texto[s + j])])

    return -1  # No se encontró

patron = input("Texto a buscar: ")
inicio1 = time.perf_counter()
fuerza_bruta(texto, patron)
print (fuerza_bruta(texto, patron), "Fuerza bruta")
fin1= time.perf_counter()
print("Tiempo Fuerza Bruta:", fin1-inicio1)
inicio2 = time.perf_counter()
kmp_buscar(texto, patron)
print (kmp_buscar(texto, patron) , "KMP")
fin2 = time.perf_counter()
print("Tiempo KMP: ", (fin2-inicio2))
inicio3 = time.perf_counter()
boyer_moore_buscar(texto, patron)
print(boyer_moore_buscar(texto, patron), "Boyer Moore")
fin3 = time.perf_counter()
print("Tiempo Boyer Moore: ", fin3-inicio3)

