# presentatacion

print("Hola,")
print("Bienvenido a mi juego de preguntas!")
name = input("Como te llamas? ")
name = name.capitalize()
print("Hola ", name )
playing = input("quieres jugar? ")

if playing.lower() != "si":
    quit()

print("juguemos!")
score = 0

#pregunta 1

answer = input("Que significa CPU? ")
if answer.lower() == "unidad de procesamiento central":
    print("correcto!")
    score += 1
else:
    print("incorrecto")

    #pregunta 2   

answer = input("Que significa Ram? ")
if answer.lower() == "memoria de acceso aleatorio":
    print("correcto!")
    score += 1
else:
    print("incorrecto!") 

    #pregunta 3

answer = input("Que significa GPU? ")
if answer.lower() == "unidad de procesamiento grafico":
    print("correcto!")
    score += 1
else:
    print("incorrecto")

print(name, "obtuviste "  + str(score)  + " respuestas correctas")
print("calificación " + str((score / 3) * 100) + " %.")
