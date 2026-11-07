
#include <LiquidCrystal.h>
#include <avr/pgmspace.h>

// ---------------- PINOS ----------------

#define BTN_UP     2
#define BTN_DOWN   3
#define BTN_PLAY   4
#define BTN_STOP   5

#define LED_VERDE  6
#define LED_VERMELHO 7

#define BUZZER     8

// LCD: RS, E, D4, D5, D6, D7
LiquidCrystal lcd(9, 10, 11, 12, 13, A0);

void loop() {

  // Selecionar musica anterior
  if (!reproduzindo && botaoPressionado(BTN_UP)) {

    musicaSelecionada--;

    if (musicaSelecionada < 0) {
      musicaSelecionada = 4;
    }

    mostrarMenu();
  }

  // Selecionar proxima musica
  if (!reproduzindo && botaoPressionado(BTN_DOWN)) {

    musicaSelecionada++;

    if (musicaSelecionada > 4) {
      musicaSelecionada = 0;
    }

    mostrarMenu();
  }

  // Play e Pause
  if (botaoPressionado(BTN_PLAY)) {

    if (!reproduzindo) {
      iniciarMusica();
    }
    else if (!pausado) {
      pausarMusica();
    }
    else {
      continuarMusica();
    }
  }

  // Stop e retorno ao menu
  if (botaoPressionado(BTN_STOP)) {

    pararMusica();
  }

  // Avancar automaticamente para a proxima nota
  if (reproduzindo && !pausado) {

    if ((long)(millis() - tempoFinal) >= 0) {

      notaAtual++;

      if (notaAtual >= quantidadeNotas(musicaSelecionada)) {
        pararMusica();
      }
      else {
        tocarNota();
      }
    }
  }
}
