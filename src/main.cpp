

#include <Keypad.h> //Biblioteca para uso de teclados matriciais 

const byte numLinhas = 4; //Quantidade de linhas do teclado
const byte numColunas = 4; //Quantidade de colunas do teclado

//Matriz de caracteres referente aos botões do teclado
char teclasMatriz[numLinhas][numColunas] = {
  {'1', '2', '3', '4'},
  {'5', '6', '7', '8'},
  {'9', '0', '*', '+'},
  {'#', '$', '%', '@'}
};

byte pinosLinhas[numLinhas] = {23, 22, 21, 19}; //Pinos das linhas
byte pinosColunas[numColunas] = {18, 5, 13, 12}; //Pinos das Colunas

//Cria um objeto do tipo Keypad
Keypad meuteclado = Keypad(makeKeymap(teclasMatriz), pinosLinhas, pinosColunas, numLinhas, numColunas);

void setup() {
  Serial.begin(9600); //Inicia a comunicação serial
  Serial.println("Aperte um botão..."); //Imprime mensagem no monitor serial
}

void loop() {
  char pressionado = meuteclado.getKey(); ///Verifica se alguma tecla foi pressionada

  if (pressionado) { //Se alguma tecla foi pressionada
    Serial.print("Botão pressionado: "); //Imprime mensagem no monitor serial
    Serial.println(pressionado); //Imprime tecla pressionada
  }
}