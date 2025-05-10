#Ejercicio para refrescar la memoria de Python
#CODIGO CON AYUDA DE COPILOT


def pedir_estudiantes(num_estudiantes):
    estudiantes = []
    for i in range(num_estudiantes):
        nombre = input(f"Introduce el nombre del estudiante {i+1}: ")
        estudiantes.append(nombre)
    return estudiantes

def pedir_notas(estudiantes, num_notas):
    datos = []
    for estudiante in estudiantes:
        notas = []
        for j in range(num_notas):
            nota = float(input(f"Digite la nota {j+1} de {estudiante}: "))
            notas.append(nota)
        datos.append({"nombre": estudiante, "notas": notas})
    return datos

def mostrar_promedios(datos):
    print("Promedios de los estudiantes:")
    for estudiante in datos:
        promedio = sum(estudiante["notas"]) / len(estudiante["notas"])
        print(f"El promedio de {estudiante['nombre']} es {promedio:.2f}")

# Código principal
num_estudiantes = 3
estudiantes = pedir_estudiantes(num_estudiantes)
num_notas = int(input("¿Cuántas notas quiere ingresar para cada estudiante? "))
datos = pedir_notas(estudiantes, num_notas)
mostrar_promedios(datos)