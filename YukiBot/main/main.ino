
// Antes de fazer o upload do código numa ESP32, verifique as bibliotecas
// Instale a DabbleESP32 e verifique a versão da placa esp32 na aba de 'Boards Manager', a versão deve ser a 2.0.17

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include "motor.h"
#include "robo.h"

// Motor direito
#define PIN_IN1  26
#define PIN_IN2 25
#define CANAL1 0
#define CANAL2 1
#define FREQUENCIA 5000 // 5 kHz
#define RESOLUCAO 8 // 8 bits

// Motor esquerdo
#define E_PIN_IN1  33//36
#define E_PIN_IN2 32//35
#define E_CANAL1 2
#define E_CANAL2 3

Motor motorDireito(PIN_IN1, PIN_IN2, CANAL1, CANAL2, FREQUENCIA, RESOLUCAO);
Motor motorEsquerdo(E_PIN_IN1, E_PIN_IN2, E_CANAL1, E_CANAL2, FREQUENCIA, RESOLUCAO);

Robo Robo_Sumo(&motorDireito, &motorEsquerdo);

void setup() {
    Serial.begin(115200);
    Dabble.begin("YukiBot");

}
void loop() {
    Dabble.processInput();

    if (GamePad.isUpPressed()) {
        // movendo para frente
        Robo_Sumo.moveForward(170, 170); //ajustar a velocidade conforme necessário, mas acho que 255 é a velocidade maxima, então ele já vai andando rapidão
        Serial.println("Frente");
    } 
    else if (GamePad.isDownPressed()) {
        // movendo para trás
        Robo_Sumo.moveForward(-170, -170); // as duas negativas para ir para tras
        Serial.println("Trás");
    } 
    else if (GamePad.isLeftPressed()) {
        // movendo para a esquerda
        Robo_Sumo.moveForward(-170, 170); // o motor direito para tras e o esquerdo para frente
        Serial.println("Esquerda");
    } 
    else if (GamePad.isRightPressed()) {
        // movendo para a direita
        Robo_Sumo.moveForward(170, -170); // o motor direito para frente e o esquerdo para tras
        Serial.println("Direita");
    } 
    else {
        // parado
        Robo_Sumo.Stop();
        Serial.println("Parado");
    }
}