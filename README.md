# Reprodutor de Músicas com Arduino UNO

**CCP020 – Digital Experience Ultimate**

---

## Introdução

Esse é um projeto da matéria de digital experience ultimate (CCP020) que consiste na criação de um sistema reprodutor de músicas utilizando peças simples, como botões, resistores, buzzer e leds. O intuito desse projeto é reforçar o aprendizado da matéria por meio de um desafio prático e interessante.

---

## Metodologia

### Descrição dos Materiais utilizados

Os materiais utilizados, conforme os requisitos, foram: 4 botões, 2 leds (1 vermelho e 1 azul), 2 resistores de 220 ohms, um buzzer, um arduino UNO, uma protoboard (modelo maior), um LCD I2C e 22 fios. A criação do dispositivo também pelo aplicativo tinkercad ajudou na visualização do projeto antes de sua montagem.

### Métodos

De início, o sistema seria montado com o LCD 16x2 padrão, conforme mostrado em aula pelo professor. Entretanto, quando obtivemos o kit para a montagem, o LCD que estava disponível era o I2C. A partir disso, tivemos de alterar um pouco a estrutura do código e o projeto em si, pelo fato desse LCD requerer bem menos fios (16 para 4).

O projeto foi desenvolvido utilizando a assistência parcial de IAs, onde sua ajuda foi mais utilizada no começo do projeto, explicando arquiteturas de código eficientes, padrões de funcionamento e resolução dos problemas. Somado a isso, também utilizamos IA para responder perguntas técnicas e outras dúvidas relacionadas ao projeto.


### Principais problemas enfrentados

1 – entendimento inicial do projeto: Pelo fato de ser nosso primeiro projeto prático, tivemos uma dificuldade em organizar as informações e saber como iríamos progredir no trabalho.

2 - Compilação do código: Quando já tínhamos todo o circuito montado e o código pronto, muitas vezes o arduino IDE não executava a compilação, principalmente pela falta de instalação das bibliotecas necessárias, como a LiquidCrystal_I2C.

3 - Organização do código: quando já sabíamos o que precisaria ser feito no código, como as funções necessárias, estados do projeto, estruturação e utilização das músicas, a junção de todas essas informações foi um problema principal na programação.

---

## Tecnologias utilizadas

- Arduino UNO
- Arduino IDE
- Biblioteca LiquidCrystal_I2C
- Tinkercad
- GitHub
- IAs (assistência parcial)

---

## Conclusão

### Como resolvemos

Assistência da IA para problemas específicos: Em situações onde precisávamos de respostas rápidas e detalhadas sobre um determinado assunto, utilizamos vários modelos de IA com vários níveis de esforço para que a resposta fosse completa. Nós nos certificamos de que, em sua assistência, não fosse dada toda a resolução do projeto, fazendo com que ela se tornasse uma ajuda muito útil.

Ajuda de colegas de turma: Antes de jogarmos nossa dúvida no google ou em uma IA, perguntávamos primeiro para colegas de turma que também estavam produzindo seu projeto e que talvez tivessem passado pelo mesmo problema, sem que copiássemos algo de sua montagem ou código.

### Considerações finais

O projeto ajudou bastante na consolidação dos conhecimentos da matéria, bem como a resolução/pesquisa de problemas nunca enfrentados antes. A cooperação entre os integrantes ajudou bastante no desenvolvimento do projeto, facilitando a coordenação e execução das atividades.
