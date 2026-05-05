# cP2- 🌱 Monitoramento de Estufa com IoT

## 📌 Descrição do Projeto

Este projeto tem como objetivo desenvolver uma solução de monitoramento em tempo real de uma estufa utilizando conceitos de Internet das Coisas (IoT).

A solução realiza a coleta de dados de sensores físicos conectados a um ESP32, envia essas informações via protocolo MQTT, processa os dados no Node-RED, armazena em banco de dados e exibe tudo em um dashboard interativo.

---

## 🧠 Arquitetura da Solução

Fluxo de dados:

```
Sensores → ESP32 → MQTT → Node-RED → Dashboard + Banco de Dados
                                   ↘ API externa (clima)
```

---

## 🔧 Tecnologias Utilizadas

* ESP32 (microcontrolador)
* Protocolo MQTT
* Node-RED
* Banco de dados (MySQL ou SQLite)
* API externa (clima)
* Sensores:

  * DHT11 (temperatura e umidade)
  * Sensor ultrassônico (nível de água)

---

## 📡 Aquisição de Dados

O ESP32 realiza leituras dos sensores:

* 🌡 Temperatura
* 💧 Umidade do ar
* 📏 Nível de água (distância)

Os dados são enviados via MQTT nos tópicos:

```
estufa/temperatura
estufa/umidade
estufa/nivel_agua
```

---

## 🔗 Comunicação MQTT

* Broker MQTT utilizado: HiveMQ
* Feita pelo ESP32
* Feita pelo Node-RED

---

## ⚙️ Processamento no Node-RED

O fluxo desenvolvido realiza:

### 🔹 Recebimento dos dados

* Nodes MQTT recebem os dados dos sensores

### 🔹 Processamento

* Funções para tratamento dos dados
* Geração de alertas:

  * 🚨 Temperatura fora do ideal
  * 🚨 Umidade inadequada
  * 🚨 Nível de água crítico

### 🔹 Integração com API externa

* Requisição HTTP para obter temperatura externa
* Tratamento da resposta da API

---

## 📊 Dashboard

O dashboard apresenta:

* 🌡 Temperatura interna
* 💧 Umidade
* 📏 Nível de água
* 🌍 Temperatura externa (API)
* 📈 Indicadores em tempo real
* 🚨 Alertas visuais

Interface organizada e atualizada em tempo real.

---

## 💾 Armazenamento de Dados

Os dados são armazenados no banco:

* Tabela de temperatura
* Tabela de umidade
* Tabela de nível de água

Também há:

* Consulta de dados
* Exibição em tabela no dashboard

---

## 🧪 Funcionalidades Implementadas

✔ Leitura de sensores
✔ Envio via MQTT
✔ Processamento no Node-RED
✔ Geração de alertas
✔ Integração com API externa
✔ Dashboard interativo
✔ Persistência em banco de dados

---

## ▶️ Como Executar


---

## 📁 Estrutura do Repositório

```
/esp32
  └── codigo.ino

/node-red
  └── fluxo.json

/database
  └── script.sql

/README.md
```

---

## 🎯 Aplicação

O sistema simula uma **estufa inteligente**, permitindo monitoramento contínuo das condições ambientais e auxiliando na tomada de decisões.

---

## 🎥 Demonstração

Link:

---

## 👨‍💻 Integrantes

* Amandha Yumi — RM: 563549
* Giovanna Bardella — RM: 561439
* Erick Takeshi — RM: 566059

---

## ✅ Conclusão

O projeto demonstra a integração completa de um sistema IoT, desde a coleta de dados até a visualização e armazenamento, utilizando boas práticas de arquitetura e comunicação entre sistemas.

---
