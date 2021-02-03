#include <PubSubClient.h>  //incluir esta biblioteca para poder utilizar o MQTT no Arduino//

#include <UIPEthernet.h>   //inclui esta biblioteca para conseguir fazer a comunicação entre o arduino e o módulo(ENC28J60) para conectar o arduino a internet//

#include <SPI.h>

boolean mensagem;  //variavel para mandar as mensagem para o cliente MQTT//
byte mac[] = {0x1E, 0x97, 0xC3, 0x49, 0xD5, 0xF2}; //define o endereço mac que sera utilizado//
bool estado_sensor; //declarei a variável estado_sensor como o tipo bool pois ela so pode ser verdadeira ou falso(1 ou 0)//
int pino2 = 2; //declarei o pino utlizado do sensor magnético como pino2 para ficar mais organizado//


EthernetClient client; // inicia o cliente Ethernet//
PubSubClient mqttClient (client); //inicia o cliente MQTT//

void setup() {
  Ethernet.begin(mac); //solicita o IP para o servidor DHCP//
  
  Serial.begin(9600);   //inicia o monitor serial//

  pinMode(pino2,INPUT_PULLUP);  //define o pino2 como entrada//
  mqttClient.setServer("54.144.190.205",1883); //define o ip e a porta TCP que vai ser utilizado para o acesso do broker MQTT//
  
  //exibe no monitor serial o IP do arduino//
  Serial.print("O IP do arduino e: "); 
  Serial.println(Ethernet.localIP());

  //exibe no monitor serial a máscara de rede do arduino//
  Serial.print("A mascara de Rede do arduino e: ");
  Serial.println(Ethernet.subnetMask());
  
  //exibe no monitor serial o gateway do arduino//
  Serial.print("O gateway do Arduino e: ");
  Serial.println(Ethernet.gatewayIP());

  
}

void loop() {

  estado_sensor = digitalRead(pino2); //o digitalRead vai ler o pino2 e vai ler se ele esta aberto ou fechado(1 ou 0)// 
  mqttClient.connect("lucaspaz"); //define o nome do cliente MQTT//

 //se esta ação for verdadeira ele irá exibir no aplicativo que o rack esta fechado// 
 if (estado_sensor == 0){
  
  
  mensagem = mqttClient.publish("lucaspaz-t","0"); //variável que envia mensagem ao servidor e depois ao aplicativo//
 }
 
 //se esta ação for verdadeira ele irá exibir no aplicativo que o rack está aberto//
 if (estado_sensor == 1){
   mensagem = mqttClient.publish("lucaspaz-t","1"); //variável que envia mensagem ao servidor e depois ao aplicativo//
 

 }

 mqttClient.loop(); 
 
}
