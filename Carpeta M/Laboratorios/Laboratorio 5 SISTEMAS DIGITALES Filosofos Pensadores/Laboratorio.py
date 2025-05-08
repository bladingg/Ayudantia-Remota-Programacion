import threading
import time
import random

# Definimos la cantidad de filósofos y tenedores
numFilosofos = 5
numTenedores = 5

# Creamos una lista de locks(mutex), uno por cada tenedor
tenedores = [threading.Lock() for _ in range(numTenedores)]

# Esta función representa el comportamiento de cada filósofo
def filosofo(i):
    for _ in range(3):  # Cada filósofo repite el ciclo 3 veces
        print("Filósofo", i, "está pensando.")
        time.sleep(random.uniform(2, 3))  # Simula el tiempo de pensar
        print("Filósofo", i, "tiene hambre.")
        
        # Para evitar interbloqueo, el último filósofo toma los tenedores en orden inverso
        if i == numTenedores - 1:
            primero, segundo = tenedores[(i + 1) % numTenedores], tenedores[i]
        else:
            primero, segundo = tenedores[i], tenedores[(i + 1) % numTenedores]
        
        # Toma ambos tenedores (locks) antes de comer
        with primero:
            with segundo:
                print("Filósofo", i, "está comiendo.")
                time.sleep(random.uniform(2, 3))  # Simula el tiempo de comer
        # Al salir del bloque 'with', suelta los tenedores
        print("Filósofo", i, "terminó de comer.")

# Creamos y ejecutamos un hilo por cada filosofo correspondiente
hilos = []
for i in range(numFilosofos):
    cadaHilo = threading.Thread(target=filosofo, args=(i,))
    hilos.append(cadaHilo)
    cadaHilo.start()

# Esperamos a que todos los hilos finalicen
for cadaHilo in hilos:
    cadaHilo.join()
print("Todos los filósofos han terminado.")
