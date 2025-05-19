# Challenge-IOT

Simulação de um sistema IoT para monitoramento de vagas de motos usando ESP32, sensor ultrassônico HC-SR04 e LED. Projetado como uma solução para empresas como a **Mottu**, que precisam controlar a ocupação e manutenção das motos em tempo real.

## Objetivo

Detectar automaticamente a ocupação de uma vaga por meio de um sensor de distância e indicar manutenção por LED, enviando os dados via **MQTT** para integração com dashboards.

---

## Tecnologias Utilizadas

- ESP32 DevKit v1
- Sensor Ultrassônico HC-SR04
- LED + resistor de 220Ω
- Wokwi (simulação online)
- Protocolo MQTT (broker: `broker.hivemq.com`)
- Arduino (linguagem C++)
- WiFi.h / PubSubClient.h

---

##  Funcionamento

- Se a distância < 20cm → vaga ocupada → LED vermelho acende → mensagem enviada via MQTT
- Se a distância >= 20cm → vaga livre → LED apaga → outra mensagem via MQTT

### Exemplo da mensagem enviada:
```json
{"vagaA": "ocupada"}
```

## Link da simulação no Wokwi
https://wokwi.com/projects/431339679872230401

## Como rodar o projeto
1. Abra o projeto no Wokwi
2. Clique no botão “Start the simulation”
3. Mude a régua do sensor para simular entrada/saída da moto
4. Observe o LED e o monitor serial (dados MQTT enviados)

## Vídeo Pitch


## Nossos integrantes
- **Gustavo Camargo de Andrade**
- RM555562
- 2TDSPF
-------------------------------------------
- **Rodrigo Souza Mantovanello**
- RM555451
- 2TDSPF
-------------------------------------------
- **Leonardo Cesar Rodrigues Nascimento**
- RM558373
- 2TDSPF
