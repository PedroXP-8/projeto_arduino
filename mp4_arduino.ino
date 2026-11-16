#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <avr/pgmspace.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int PIN_UP           = 6;
const int PIN_DOWN         = 7;
const int PIN_PLAY         = 8;
const int PIN_STOP         = 10;
const int PIN_BUZZER       = 9;
const int PIN_LED_AZUL     = 13;
const int PIN_LED_VERMELHO = A0;


const unsigned long TEMPO_DEBOUNCE = 30;  // ms

struct Botao {
  uint8_t pino;
  bool estavel;            
  bool ultimaLeitura;         
  unsigned long ultimaMudanca;
};

Botao botoes[4] = {
  {PIN_UP,   HIGH, HIGH, 0},
  {PIN_DOWN, HIGH, HIGH, 0},
  {PIN_PLAY, HIGH, HIGH, 0},
  {PIN_STOP, HIGH, HIGH, 0}
};
const uint8_t BTN_UP = 0, BTN_DOWN = 1, BTN_PLAY = 2, BTN_STOP = 3;


bool botaoPressionado(uint8_t i) {
  Botao &b = botoes[i];
  bool leitura = digitalRead(b.pino);
  if (leitura != b.ultimaLeitura) {
    b.ultimaLeitura = leitura;
    b.ultimaMudanca = millis();
  }
  if ((millis() - b.ultimaMudanca) > TEMPO_DEBOUNCE && leitura != b.estavel) {
    b.estavel = leitura;
    if (b.estavel == LOW) {
      return true;
    }
  }
  return false;
}


#define PAUSA 0
#define N_C4  262
#define N_D4  294
#define N_DS4 311
#define N_E4  330
#define N_F4  349
#define N_G4  392
#define N_GS4 415
#define N_A4  440
#define N_AS4 466
#define N_B4  494
#define N_C5  523
#define N_CS5 554
#define N_D5  587
#define N_DS5 622
#define N_E5  659
#define N_F5  698
#define N_FS5 740
#define N_G5  784
#define N_GS5 831
#define N_A5  880
#define N_AS5 932
#define N_B5  988
#define N_C6  1047
#define N_CS6 1109
#define N_D6  1175

struct Nota {
  uint16_t freq;
  uint8_t  dur;
};

const Nota melodiaGot[] PROGMEM = {
  {N_G4, 6}, {N_C4, 6}, {N_DS4, 2}, {N_F4, 2}, {N_G4, 6}, {N_C4, 6},
  {N_DS4, 2}, {N_F4, 2}, {N_G4, 6}, {N_C4, 6}, {N_DS4, 2}, {N_F4, 2},
  {N_G4, 6}, {N_C4, 6}, {N_E4, 2}, {N_F4, 2}, {N_G4, 8}, {N_C4, 8},
  {N_DS4, 2}, {N_F4, 2}, {N_G4, 16}, {PAUSA, 4}
};

const Nota melodiaMario[] PROGMEM = {
  {N_E5, 2}, {N_E5, 2}, {PAUSA, 2}, {N_E5, 2}, {PAUSA, 2}, {N_C5, 2},
  {N_E5, 2}, {PAUSA, 2}, {N_G5, 4}, {PAUSA, 4}, {N_G4, 4}, {PAUSA, 4},
  {N_C5, 2}, {PAUSA, 4}, {N_G4, 2}, {PAUSA, 4}, {N_E4, 2}, {PAUSA, 4},
  {N_A4, 2}, {PAUSA, 2}, {N_B4, 2}, {PAUSA, 2}, {N_AS4, 2}, {N_A4, 2},
  {PAUSA, 2}, {N_G4, 3}, {N_E5, 3}, {N_G5, 3}, {N_A5, 4}, {PAUSA, 2},
  {N_F5, 2}, {N_G5, 2}, {PAUSA, 2}, {N_E5, 2}, {PAUSA, 2}, {N_C5, 2},
  {N_D5, 2}, {N_B4, 2}, {PAUSA, 4}, {N_C5, 2}, {PAUSA, 4}, {N_G4, 2},
  {PAUSA, 4}, {N_E4, 2}, {PAUSA, 4}, {N_A4, 2}, {PAUSA, 2}, {N_B4, 2},
  {PAUSA, 2}, {N_AS4, 2}, {N_A4, 2}, {PAUSA, 2}, {N_G4, 3}, {N_E5, 3},
  {N_G5, 3}, {N_A5, 4}, {PAUSA, 2}, {N_F5, 2}, {N_G5, 2}, {PAUSA, 2},
  {N_E5, 2}, {PAUSA, 2}, {N_C5, 2}, {N_D5, 2}, {N_B4, 2}, {PAUSA, 4}
};

const Nota melodiaImperial[] PROGMEM = {
  {N_A4, 4}, {N_A4, 4}, {N_A4, 4}, {N_F4, 3}, {N_C5, 1}, {N_A4, 4},
  {N_F4, 3}, {N_C5, 1}, {N_A4, 8}, {PAUSA, 2}, {N_E5, 4}, {N_E5, 4},
  {N_E5, 4}, {N_F5, 3}, {N_C5, 1}, {N_GS4, 4}, {N_F4, 3}, {N_C5, 1},
  {N_A4, 8}, {PAUSA, 2}, {N_A5, 4}, {N_A4, 3}, {N_A4, 1}, {N_A5, 4},
  {N_GS5, 3}, {N_G5, 1}, {N_FS5, 1}, {N_F5, 1}, {N_FS5, 2}, {PAUSA, 2},
  {N_AS4, 2}, {N_DS5, 4}, {N_D5, 3}, {N_CS5, 1}, {N_C5, 1}, {N_B4, 1},
  {N_C5, 2}, {PAUSA, 2}, {N_F4, 2}, {N_GS4, 4}, {N_F4, 3}, {N_A4, 1},
  {N_C5, 4}, {N_A4, 3}, {N_C5, 1}, {N_E5, 8}, {PAUSA, 4}
};

const Nota melodiaHarry[] PROGMEM = {
  {PAUSA, 4}, {N_B4, 4}, {N_E5, 6}, {N_G5, 2}, {N_FS5, 4}, {N_E5, 8},
  {N_B5, 4}, {N_A5, 12}, {N_FS5, 12}, {N_E5, 6}, {N_G5, 2}, {N_FS5, 4},
  {N_DS5, 8}, {N_F5, 4}, {N_B4, 12}, {PAUSA, 4}, {N_B4, 4}, {N_E5, 6},
  {N_G5, 2}, {N_FS5, 4}, {N_E5, 8}, {N_B5, 4}, {N_D6, 8}, {N_CS6, 4},
  {N_C6, 8}, {N_GS5, 4}, {N_C6, 6}, {N_B5, 2}, {N_AS5, 4}, {N_AS4, 8},
  {N_G5, 4}, {N_E5, 12}, {PAUSA, 4}
};

const Nota melodiaTetris[] PROGMEM = {
  {N_E5, 4}, {N_B4, 2}, {N_C5, 2}, {N_D5, 4}, {N_C5, 2}, {N_B4, 2},
  {N_A4, 4}, {N_A4, 2}, {N_C5, 2}, {N_E5, 4}, {N_D5, 2}, {N_C5, 2},
  {N_B4, 6}, {N_C5, 2}, {N_D5, 4}, {N_E5, 4}, {N_C5, 4}, {N_A4, 4},
  {N_A4, 8}, {PAUSA, 2}, {N_D5, 6}, {N_F5, 2}, {N_A5, 4}, {N_G5, 2},
  {N_F5, 2}, {N_E5, 6}, {N_C5, 2}, {N_E5, 4}, {N_D5, 2}, {N_C5, 2},
  {N_B4, 4}, {N_B4, 2}, {N_C5, 2}, {N_D5, 4}, {N_E5, 4}, {N_C5, 4},
  {N_A4, 4}, {N_A4, 8}, {PAUSA, 4}
};


const char menu0[] PROGMEM = "Game of Thrones";
const char menu1[] PROGMEM = "Super Mario";
const char menu2[] PROGMEM = "Imperial March";
const char menu3[] PROGMEM = "Harry Potter";
const char menu4[] PROGMEM = "Tetris";

const char full0[] PROGMEM = "Game of Thrones - Main Theme";
const char full1[] PROGMEM = "Super Mario Bros - Overworld";
const char full2[] PROGMEM = "Star Wars - Imperial March";
const char full3[] PROGMEM = "Harry Potter - Hedwig's Theme";
const char full4[] PROGMEM = "Tetris - Korobeiniki";


struct Musica {
  const char *nomeMenu;
  const char *nomeCompleto;
  const Nota *notas;
  uint16_t tamanho;
  uint16_t bpm;
};

const Musica musicas[] = {
  { menu0, full0, melodiaGot,      sizeof(melodiaGot)      / sizeof(Nota), 120 },
  { menu1, full1, melodiaMario,    sizeof(melodiaMario)    / sizeof(Nota), 200 },
  { menu2, full2, melodiaImperial, sizeof(melodiaImperial) / sizeof(Nota), 104 },
  { menu3, full3, melodiaHarry,    sizeof(melodiaHarry)    / sizeof(Nota), 144 },
  { menu4, full4, melodiaTetris,   sizeof(melodiaTetris)   / sizeof(Nota), 144 }
};
const uint8_t NUM_MUSICAS = sizeof(musicas) / sizeof(musicas[0]);


enum Estado { MENU, TOCANDO, PAUSADO };
Estado estado = MENU;


void atualizarLeds() {
  digitalWrite(PIN_LED_AZUL,     estado == TOCANDO ? HIGH : LOW);
  digitalWrite(PIN_LED_VERMELHO, estado == PAUSADO ? HIGH : LOW);
}


void testeLeds() {
  digitalWrite(PIN_LED_AZUL, HIGH);
  delay(400);
  digitalWrite(PIN_LED_AZUL, LOW);
  digitalWrite(PIN_LED_VERMELHO, HIGH);
  delay(400);
  digitalWrite(PIN_LED_VERMELHO, LOW);
}

uint8_t selecionada = 0;  
uint8_t topo = 0;         

void desenharMenu() {
  char buf[17];
  for (uint8_t linha = 0; linha < 2; linha++) {
    uint8_t i = topo + linha;
    lcd.setCursor(0, linha);
    if (i < NUM_MUSICAS) {
      lcd.print(i == selecionada ? '>' : ' ');
      strcpy_P(buf, musicas[i].nomeMenu);
      lcd.print(buf);
      for (uint8_t k = strlen(buf); k < 15; k++) lcd.print(' ');
    } else {
      lcd.print("                ");
    }
  }
}

void navegarMenu() {
  bool up   = botaoPressionado(BTN_UP);
  bool down = botaoPressionado(BTN_DOWN);
  if (up && selecionada > 0) {
    selecionada--;
    if (selecionada < topo) topo = selecionada;
    desenharMenu();
  }
  if (down && selecionada < NUM_MUSICAS - 1) {
    selecionada++;
    if (selecionada > topo + 1) topo = selecionada - 1;
    desenharMenu();
  }
}


const unsigned long INTERVALO_ROLAGEM = 500;  

char nomeRolagem[48];
uint8_t tamanhoRolagem = 0;
uint8_t posRolagem = 0;
bool precisaRolar = false;
unsigned long ultimaRolagem = 0;

void prepararRolagem(uint8_t indice) {
  strcpy_P(nomeRolagem, musicas[indice].nomeCompleto);
  uint8_t len = strlen(nomeRolagem);
  precisaRolar = (len > 16);
  if (precisaRolar) {
    strcat(nomeRolagem, "   "); 
  } else {
    while (len < 16) nomeRolagem[len++] = ' ';
    nomeRolagem[len] = '\0';
  }
  tamanhoRolagem = strlen(nomeRolagem);
  posRolagem = 0;
  ultimaRolagem = millis();
}

void desenharNome() {
  char janela[17];
  for (uint8_t i = 0; i < 16; i++) {
    janela[i] = nomeRolagem[(posRolagem + i) % tamanhoRolagem];
  }
  janela[16] = '\0';
  lcd.setCursor(0, 1);
  lcd.print(janela);
}

void atualizarRolagem() {
  if (!precisaRolar) return;
  if (millis() - ultimaRolagem < INTERVALO_ROLAGEM) return;
  ultimaRolagem = millis();
  posRolagem = (posRolagem + 1) % tamanhoRolagem;
  desenharNome();
}

const Musica *atual = &musicas[0];
uint16_t indiceNota = 0;
unsigned long inicioNota = 0;
unsigned long duracaoNota = 0;
unsigned long msPorTick = 0;

void desenharTela() {
  lcd.setCursor(0, 0);
  lcd.print(estado == TOCANDO ? "Reproduzindo    " : "Pausado         ");
  desenharNome();
}

void tocarNotaAtual() {
  uint16_t freq = pgm_read_word(&atual->notas[indiceNota].freq);
  uint8_t  dur  = pgm_read_byte(&atual->notas[indiceNota].dur);
  duracaoNota = (unsigned long)dur * msPorTick;
  if (freq > 0) {
    tone(PIN_BUZZER, freq, duracaoNota * 9 / 10);
  } else {
    noTone(PIN_BUZZER);
  }
  inicioNota = millis();
}

void iniciarMusica() {
  atual = &musicas[selecionada];
  indiceNota = 0;
  msPorTick = 60000UL / ((unsigned long)atual->bpm * 4);
  prepararRolagem(selecionada);
  estado = TOCANDO;
  atualizarLeds();
  desenharTela();
  tocarNotaAtual();
}

void pausar() {
  noTone(PIN_BUZZER);
  estado = PAUSADO;
  atualizarLeds();
  desenharTela();
}

void retomar() {
  estado = TOCANDO;
  atualizarLeds();
  desenharTela();
  tocarNotaAtual();  
}

void parar() {
  noTone(PIN_BUZZER);
  estado = MENU;
  atualizarLeds();
  desenharMenu();
}

void atualizarMusica() {
  if (estado != TOCANDO) return;
  if (millis() - inicioNota >= duracaoNota) {
    indiceNota++;
    if (indiceNota >= atual->tamanho) {
      parar();  
      return;
    }
    tocarNotaAtual();
  }
}

void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_LED_AZUL, OUTPUT);
  pinMode(PIN_LED_VERMELHO, OUTPUT);
  pinMode(PIN_UP,   INPUT_PULLUP);
  pinMode(PIN_DOWN, INPUT_PULLUP);
  pinMode(PIN_PLAY, INPUT_PULLUP);
  pinMode(PIN_STOP, INPUT_PULLUP);

  testeLeds();
  lcd.init();
  lcd.backlight();
  desenharMenu();
}

void loop() {
  switch (estado) {
    case MENU:
      navegarMenu();
      if (botaoPressionado(BTN_PLAY)) iniciarMusica();
      break;

    case TOCANDO:
      if (botaoPressionado(BTN_PLAY)) pausar();
      if (botaoPressionado(BTN_STOP)) parar();
      atualizarMusica();
      atualizarRolagem();
      break;

    case PAUSADO:
      if (botaoPressionado(BTN_PLAY)) retomar();
      if (botaoPressionado(BTN_STOP)) parar();
      atualizarRolagem();
      break;
  }
}
