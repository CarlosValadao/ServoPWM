# ServoPWM 🎮 -> [Assista ao vídeo de apresentação](https://youtu.be/yOBFRAaiK4M)

**ServoPWM** é um controlador de servo motor via PWM desenvolvido para a **Raspberry Pi Pico W** utilizando a placa **BitDogLab**. O programa movimenta o servo motor entre os ângulos de 0 a 180 graus, com a movimentação suave, ajustando o ciclo ativo de acordo com a posição desejada do servo.

## 🚀 Requisitos

- **Raspberry Pi Pico W** 🛒
- **BitDogLab** versão 6.3 🔧
- Linguagem: **C** (Versão 11) 💻
- Pico SDK (Versão 2.1.0) 🛠️
- Utiliza **pico-sdk**, **extensões do CMake** e **VS Code** para desenvolvimento 🛠️
- Compilador: **GNU ARM Embedded Toolchain** (`gcc-arm-eabi`) ⚙️

## 🧑‍💻 Funcionalidades

1. O servo motor começa na posição **0 graus** e se move para **180 graus** 🔄.
2. O servo se move para a posição **90 graus** após 5 segundos ⏱️.
3. O servo retorna para **0 graus** após 5 segundos ⏱️.
4. Após as movimentações, o servo **oscila indefinidamente** entre 0 e 180 graus 🔁.
5. O ciclo ativo (duty cycle) do PWM é ajustado para controlar a posição do servo com precisão.
6. O código foi projetado para **movimentação suave** com incremento de **±5µs** a cada 10ms 🕑.

## 🧩 Componentes

- **Raspberry Pi Pico W** 🖥️
- **Servo Motor** conectado à **GPIO 22** ⚙️
- **Fonte de alimentação** adequada para o servo motor 💡

## ⚙️ Como Funciona

1. **Movimentação do Servo**: O código ajusta o duty cycle do PWM, controlando a posição do servo de 0 a 180 graus e de volta para 0 graus.
2. **Ciclo ativo (Duty Cycle)**: O ciclo ativo é ajustado para 2.400 µs (para 180 graus), 1.470 µs (para 90 graus) e 500 µs (para 0 graus).
3. **Oscilação contínua**: Após a movimentação inicial, o servo oscila entre 0 e 180 graus com um incremento de ±5µs no ciclo ativo.


## 🛠️ Instalação

1. Clone o repositório em sua máquina local:

    ```bash
    git clone https://github.com/CarlosValadao/ServoPWM.git
    ```

2. Navegue até o diretório do projeto:

    ```bash
    cd ServoPWM
    ```

3. Abra o projeto no **VS Code** com a **extensão Raspberry Pi Pico** instalada.
4. Compile e execute o arquivo **diagram.json**

## 📜 Licença

Este projeto está licenciado sob a **MIT License**.

## 💬 Contribuição

Sinta-se à vontade para abrir *issues* e *pull requests* para melhorias ou correções.

---

**Carlos Valadão**  
Data: 11/02/2025
