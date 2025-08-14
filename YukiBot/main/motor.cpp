#include "motor.h"
#include <Arduino.h>

Motor::Motor(int _pinIN1, int _pinIN2, int _canal1, int _canal2, int _frequencia, int _resolucao)
    : pinIN1(_pinIN1), pinIN2(_pinIN2), canal1(_canal1), canal2(_canal2), frequencia(_frequencia), resolucao(_resolucao) {
    config();
}

void Motor::config() {

    ledcSetup(canal1, frequencia, resolucao);
    ledcSetup(canal2, frequencia, resolucao);
    
    ledcAttachPin(pinIN1, canal1);
    ledcAttachPin(pinIN2, canal2);
  
    /*ledcAttachChannel(pinIN1, frequencia, resolucao, canal1);
    ledcAttachChannel(pinIN2, frequencia, resolucao, canal2);*/

} 
void Motor::setPWM(int velocidade) {
    if (velocidade > 0) {
        ledcWrite(canal1, velocidade); //frente
        ledcWrite(canal2, 0); //parado
    } 
    else if (velocidade < 0) {
        ledcWrite(canal2, -velocidade); //tras
        ledcWrite(canal1, 0); //parado
    } 
    else {
        ledcWrite(canal1, 0); //os dois parado
        ledcWrite(canal2, 0);
    }
}