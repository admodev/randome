#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

/**
 * Funcion para adivinar un numero
 * @param numero = El numero elegido por el usuario
 * @param numero_random = El numero a adivinar
 * @param cantidad_intentos = La cantidad de intentos
 * @return = true si el numero es correcto, false si el numero es incorrecto
 **/
bool adivinar_numero(int numero, int numero_random, int cantidad_intentos) {
  int intento = 0;
  bool ganador = false;

  while (intento < cantidad_intentos) {
    if (numero == numero_random) {
      printf("Adivinaste! El numero era %d\n", numero_random);
      printf("Muchas gracias por jugar!\n");
      ganador = true;
      break;
    } else {
      printf("El numero es incorrecto. Intenta de nuevo.\n");
      printf("Introduzca el numero: ");
      scanf("%d", &numero); // Prompt user for new guess
      intento++;
    }
  }

  if (!ganador) {
    printf("Perdiste. El numero era %d\n", numero_random);
  }

  return ganador;
}

/**
*  Main function
*  @param argc = Cantidad de argumentos
*  @param argv = Array de argumentos
*  @return = Codigo de salida del programa (0 sin errores, 1 con errores)
**/
int main(int argc, char *argv[])
{
  int cantidad_intentos = argv[1] != NULL ? strtol(argv[1], NULL, 10) : 3;
  char *rango_numeros_inicio = malloc(sizeof(char) * 20);
  char *rango_numeros_fin = malloc(sizeof(char) * 20);
  int numero_elegido;

  if (rango_numeros_inicio == NULL || rango_numeros_fin == NULL) {
    printf("Error: Memory allocation failed.\n");
    return 1;
  }

  printf("Bienvenido al juego!\nPor favor, ingrese un rango de numeros para comenzar.\n");

  printf("Inicio del rango: ");
  scanf("%s", rango_numeros_inicio);

  printf("\nFin del rango: ");
  scanf("%s", rango_numeros_fin);

  int numero_inicio = strtol(rango_numeros_inicio, NULL, 10);
  int numero_fin = strtol(rango_numeros_fin, NULL, 10);

  srand(time(NULL));

  int numero_random = rand() % (numero_fin - numero_inicio + 1) + numero_inicio; 

  printf("Adivine el numero (entre %d y %d): ", numero_inicio, numero_fin);
  printf("Usted tiene %d intentos.\n", cantidad_intentos);
  printf("Introduzca el numero: ");

  if (scanf("%d", &numero_elegido) != 1)
  {
    printf("Error: El valor introducido no es un numero.\n");
    return 1;
  }

  if (numero_elegido < numero_inicio || numero_elegido > numero_fin) {
    printf("Error: El numero ingresado no esta en el rango especificado.\n");
    return 1;
  }

  adivinar_numero(numero_elegido, numero_random, cantidad_intentos);

  bool resultado = adivinar_numero(numero_elegido, numero_random, cantidad_intentos);

  free(rango_numeros_inicio);
  free(rango_numeros_fin);

  return resultado ? 0 : 1;
}

