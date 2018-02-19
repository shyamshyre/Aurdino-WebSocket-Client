#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <stdio.h>
#include <SocketIoClient.h>
#include <ESP8266mDNS.h> 
#include <ESP8266WebServer.h>
#include <PubSubClient.h>

#define USE_SERIAL Serial

ESP8266WiFiMulti WiFiMulti;
PubSubClient client(WiFiMulti);

SocketIoClient webSocket;

#define MAX_WORLD_COUNT 3
#define MIN_WORLD_COUNT 1
char *Words[MAX_WORLD_COUNT];
char *StringToParse ;


char *pind0 ="PIN_DO_1";
char *pind1 ="PIN_DO_2";
char *pind2 ="PIN_DO_3";
char *pind3 ="PIN_DO_4";
char *pind4 ="PIN_DO_5";
char *pind5 ="PIN_DO_6";
char *pind6 ="PIN_DO_7";
char *pind7 ="PIN_DO_8";

char *high="1";
char *low="0";


#define PIN_DO_1         D0  // DO pin1 

#define PIN_DO_2         D1  // DO pin2 


#define PIN_DO_3         D2  // DO pin3 


#define PIN_DO_4         D3  // DO pin4 


#define PIN_DO_5         D4  // DO pin1 


#define PIN_DO_6         D5  // DO pin2 


#define PIN_DO_7         D6  // DO pin3 


#define PIN_DO_8         D7  // DO pin4 

const char *devicename ="/Board001";
const char *ssid = "Board001AP"; 
const char *password = "12345678"; 
const char *mdnsname="board001";

// mqtt server configuration..

const char* mqtt_server = "broker.mqtt-dashboard.com";
int mdnsvalue;
ESP8266WebServer server(80); 

void event(const char * payload, size_t length) {
   byte word_count;
  
  USE_SERIAL.printf("got message: %s\n", payload);
 
  StringToParse= (char*)payload;

  word_count = split_message(StringToParse);
  if (word_count >= MIN_WORLD_COUNT) {
    print_message(word_count);
  }
  String ipaddr= WiFi.localIP().toString();
  Serial.println("ESP8266 Client IP Address :: "+ipaddr);
  const char *ipaddr_c=ipaddr.c_str();
  Serial.println(Words[0]);
  Serial.println(ipaddr_c);
  int compvalue=strcmp( Words[0],ipaddr_c);
  Serial.println("compvalue"+compvalue);

  char* mndnsname= Words[0];
  char subbuff[8];  
  memcpy( subbuff, &mndnsname[0], 8 );
  Serial.println("subbuff..");
  Serial.println(subbuff);
  Serial.println("before..");
  Serial.println(mndnsname);
  Serial.println("after..");
  Serial.println(Words[0]);
  Serial.println(mdnsname);
  
  mdnsvalue=strcmp( subbuff,mdnsname);
  Serial.println("MDNS VALUE");
  Serial.println(mdnsvalue);
  
  if(compvalue ==0 || mdnsvalue==0)
  {
     Serial.println("Entered into if condition");
    writePin0(Words[1],Words[2]);
    writePin1(Words[1],Words[2]);
    writePin2(Words[1],Words[2]);
    writePin3(Words[1],Words[2]);
    writePin4(Words[1],Words[2]);
    writePin5(Words[1],Words[2]);
    writePin6(Words[1],Words[2]);
    writePin7(Words[1],Words[2]);
    
  }
}
/** This is for configuration of pin 0 */
void writePin0(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind0);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_1, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_1, 0);
  }
}
  
/** This is for configuration of pin 1 */

void writePin1(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind1);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_2, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_2, 0);
  }
}


/** This is for configuration of pin 2 */

void writePin2(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind2);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_3, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_3, 0);
  }
}




/** This is for configuration of pin 3 */

void writePin3(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind3);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_4, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_4, 0);
  }
}



/** This is for configuration of pin 4 */

void writePin4(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind4);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_5, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_5, 0);
  }
}

/** This is for configuration of pin 5 */

void writePin5(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind5);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_6, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_6, 0);
  }
}

/** This is for configuration of pin 6 */

void writePin6(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind6);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_7, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_7, 0);
  }
}



/** This is for configuration of pin 7 */

void writePin7(char *port, char *value){
  Serial.println(port);
  Serial.println(value);
  Serial.println("Entered into write pin");

  int portsuccess=  strcmp(port,pind7);
  int valuehigh =strcmp(value,high);
  int valuelow =strcmp(value,low);
  
  Serial.println("portsuccess"+portsuccess);
  Serial.println("valuehigh"+valuehigh);
  Serial.println("valuelow"+valuelow);

  
  if(portsuccess==0 && valuehigh==0){
    Serial.println("inside if");
      digitalWrite(PIN_DO_8, 1);
  }
  else if(portsuccess==0 && valuelow==0){
    Serial.println("inside elseif");
     digitalWrite(PIN_DO_8, 0);
  }
}



////////// ////////// ////////// ////////// ////////// ////////// //////////
// Split string into individual words and store each word into an array
// this function return word_count (number of words)
////////// ////////// ////////// ////////// ////////// ////////// //////////
byte split_message(char* str) {
  byte word_count = 0; //number of words
  char * item = strtok (str, "/"); //getting first word (uses space & comma as delimeter)

  while (item != NULL) {
    if (word_count >= MAX_WORLD_COUNT) {
      break;
    }
    Words[word_count] = item;
    item = strtok (NULL, "/"); //getting subsequence word
    word_count++;
  }
  return  word_count;


  
}

void print_message(byte word_count) {
  //if (word_count >= MIN_WORLD_COUNT) {
  //Serial.print("Word count : ");  Serial.println(word_count);
  for (byte sms_block = 0; sms_block < word_count; sms_block++) {
    Serial.print("Word "); Serial.print(sms_block + 1);  Serial.print(" : ");
    Serial.println(Words[sms_block]);
  }
  Serial.println("--------------------");
  //}
}

void connecthandler(){
  Serial.println("ESP 8266 Connected to WebSocket");
}

void setup(){
    USE_SERIAL.begin(115200);

    USE_SERIAL.setDebugOutput(true);

    USE_SERIAL.println();
    USE_SERIAL.println();
    USE_SERIAL.println();

    
   pinMode(PIN_DO_1, OUTPUT); 
   pinMode(PIN_DO_2, OUTPUT); 
   pinMode(PIN_DO_3, OUTPUT); 
   pinMode(PIN_DO_4, OUTPUT); 
   pinMode(PIN_DO_5, OUTPUT); 
   pinMode(PIN_DO_6, OUTPUT); 
   pinMode(PIN_DO_7, OUTPUT); 
   pinMode(PIN_DO_8, OUTPUT); 
  

      for(uint8_t t = 4; t > 0; t--) {
          USE_SERIAL.printf("[SETUP] BOOT WAIT %d...\n", t);
          USE_SERIAL.flush();
          delay(1000);
      }
  // Enabling it as the access point.
    WiFi.softAP(ssid, password);  
    
    WiFi.hostname("Board001");
    WiFiMulti.addAP("iconma_ODC", "Iconma_14102017");
    WiFiMulti.addAP("Shyam", "shyamshyre");
    WiFiMulti.addAP("shyamshyre", "12345678");
    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

  if (!MDNS.begin(mdnsname)) {             // Start the mDNS responder for esp8266.local
      Serial.println("Error setting up MDNS responder!");
  }
  Serial.println("mDNS responder started");
   
    webSocket.begin("192.168.0.18",3100,"/socket.io/?transport=websocket");
    webSocket.on("event", event);
    
    Serial.println("MAC ADDRESS"+WiFi.macAddress());
    String deviceip=WiFi.localIP().toString()+devicename;
    
    //USE_SERIAL.printf("Device Name && IP ADDRESS::", deviceip.c_str());
    
    
    //webSocket.emit("ipaddress","\"+\deviceip.c_str()\"");
    //webSocket.emit("event","Message Sent from Esp 8266");
   
}

void loop() {
    webSocket.loop();
}
