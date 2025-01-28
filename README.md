# SSI-P01
# Práctica 1: Cifrado de Vernam
## Objetivo
Implementar el cifrado de Vernam
## Desarrollo
Implementa en el lenguaje que prefieras el cifrado y descifrado de Vernam según la descripción que se incluye a continuación:
- El cifrado opera bit a bit, mediante la operación XOR entre el mensaje original y la clave aleatoria. 
- El descifrado opera bit a bit, mediante la operación XOR entre el mensaje
cifrado y la clave aleatoria.

Utiliza código ASCII para pasar de letras a bytes y viceversa, cuando se trate de
caracteres imprimibles
## Ejemplos
### Ejemplo 1
__Entrada:__
Mensaje original: SOL

__Salida:__
- __Mensaje original en binario:__ 010100110100111101001100
- __Longitud del mensaje binario:__ 24

__Entrada:__
- __Clave aleatoria:__ 001111000001100001110011

__Salida:__
- __Mensaje cifrado:__ 011011110101011100111111
- __Mensaje cifrado:__ oW?

### Ejemplo 2
__Entrada:__
- __Mensaje original:__ [t

__Salida:__
- __Mensaje original en binario:__ 0101101101110100
- __Longitud del mensaje binario:__ 16

__Entrada:__
Clave aleatoria: 0000111100100001

__Salida:__
- __Mensaje cifrado:__ 0101010001010101
- __Mensaje cifrado:__ TU