# projeto-mqtt-lucaspaz
**OBJETIVO**

Objetivo deste projeto, é fazer com que o arduino possa mandar a informação que está o Rack para ver se ele está **ABERTO** ou **FECHADO**, para mandar pro Servidor Broker MQTT(*Message Queuing Telemetry Transport*) hospedado na *Amazon Web Service*(AWS) e partir da ai conseguimos receber a informação que está o Rack através do aplicativo MQTT Dash instalado no smartphone.

![projeto do arduino](https://github.com/Nogueirinha1961/projeto-mqtt-lucaspaz/blob/main/projeto%20do%20arduino.PNG)

**Atribui duas bibliotecas para executar o projeto, são elas:**

[UIPEthernet](https://github.com/UIPEthernet/UIPEthernet/archive/v2.0.9.zip&ust=1612376100000000&usg=AOvVaw1CHCYcbTZoY5fZ6OHF_K2b&hl=pt-BR) (que possibilitará a comunicação do arduino e ENC28J60, que fará se conectar a internet)

[PubSubClient](https://github.com/knolleary/pubsubclient/archive/v2.8.zip) (Para fazer a ponte entre o arduino e o server Broker MQTT e consequentemente o cliente MQTT)

**Materiais:**
- Arduino Uno
- Módulo de Ethernet (ENC28J60)
- Sensor Magnético (MC-38)
- Jumpers

![circuito](https://github.com/Nogueirinha1961/projeto-mqtt-lucaspaz/blob/main/circuito%20do%20arduino.PNG)

**Autor:Lucas Paz**
