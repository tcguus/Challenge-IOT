# Challenge-IOT

Simulação de um sistema IoT para monitoramento de vagas de motos usando ESP32, sensor ultrassônico HC-SR04 e LED. Projetado como uma solução para empresas como a **Mottu**, que precisam controlar a ocupação e manutenção das motos em tempo real.

---

## Objetivo

Detectar automaticamente a ocupação de uma vaga por meio de um sensor de distância e indicar manutenção por LED, enviando os dados via **MQTT** para integração com dashboards em tempo real.

---

## Tecnologias Utilizadas

- ESP32 DevKit v1
- Sensor Ultrassônico HC-SR04
- LED + resistor de 220Ω
- Wokwi (simulação online)
- Node-RED (dashboard)
- Protocolo MQTT (broker: `broker.hivemq.com`)
- Arduino (linguagem C++)
- Bibliotecas: `WiFi.h`, `PubSubClient.h`

---

## Funcionamento

- Se a distância < 20cm → vaga **ocupada** → LED vermelho acende → mensagem `{"vagaA": "ocupada"}` enviada via MQTT
- Se a distância ≥ 20cm → vaga **livre** → LED apaga → mensagem `{"vagaA": "livre"}` enviada

---

## Simulação no Wokwi

🔗 [Clique aqui para abrir a simulação](https://wokwi.com/projects/431339679872230401)

### Como testar:

1. Acesse o link acima
2. Clique em **"Start the simulation"**
3. Mova a régua do sensor com o mouse
4. Observe o LED acendendo/apagando
5. Veja os dados no **Monitor Serial**

---

## Dashboard Node-RED

Criamos um painel para exibir em tempo real o status da vaga com base nas mensagens MQTT.

### Requisitos:
- Node-RED instalado
- Paleta: `node-red-dashboard` (instale via "Manage Palette")

### Como importar o fluxo:
1. Acesse: `http://localhost:1880`
2. Clique no menu (☰) > **Import**
3. Cole [este JSON do fluxo](./flow-node-red.json) 
4. Clique em **Deploy**
5. Acesse o painel em: `http://localhost:1880/ui`

Você verá:
- Status da Vaga: livre / ocupada

---

## Vídeo Pitch
[Assitir no YouTube](https://youtu.be/WvZojYpMwJ4)

---

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
