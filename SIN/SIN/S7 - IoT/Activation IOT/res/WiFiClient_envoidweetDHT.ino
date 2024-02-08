


#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiClientSecureAxTLS.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiServerSecureAxTLS.h>
#include <WiFiUdp.h>


/*
    ce programme doit lire les valeurs de température et d'humidité du capteur DHT11
    et les envoyer sur le service dweet.io par requete HTTP POST

*/


#include <DHT.h>
#include <Wire.h>

#define DHTTYPE   DHT11       // DHT type (DHT11, DHT22)
#define DHTPIN    D4          // Broche du DHT / DHT Pin


/************* donnez un nom à l'objet qui contiendra les données à envoyer dans dweet.io *********/
String monObjet =String("MaMeteoSIN");

/*************compléter cette partie avec l'identifiant et le mot de passe de votre Box*********/
// identifiant de votre box
const char* ssid     = "..................";
// mot de passe
const char* password = "..................";

/*************indiquez le nom de l'hote dweet.io par exemple *********/
// serveur web
const char* host = "dweet.io";

// variables permettant de stocker la température et l'humidité
  float t ;
  float h ;
  
void setup() {
  Serial.begin(115200);
  delay(10);

  
  Serial.print("Connexion au WiFi ");
  Serial.println(ssid);
  
  // connexion au reseau WiFi
 
  WiFi.begin(ssid, password);
  
// attente de connexion

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connecte");
  Serial.println("addresse IP du ESP8266: ");
  Serial.println(WiFi.localIP());
  Serial.println("addresse IP de la BOX: ");
  Serial.println(WiFi.gatewayIP());
}



void loop() {

//***********************************************************************************
//-------------------- 1. mesure de la temperature et de l'humidite------------------
//***********************************************************************************

    float h = dht.readHumidity();
    float t = dht.readTemperature();

    // verification des données, si elles ne sont pas valides on affiche un message d'erreur dans le moniteur série
    // les affichages servent uniquement à verifier le bon fonctionnement du système lors de sa mise au point
    
    if (isnan(t) || isnan(h)) 
    {
        Serial.println("donnees du DHT invalides");
    } 
    else 
    {
        Serial.print("Humidite : "); 
        Serial.print(h);
        Serial.print(" %\t");
        Serial.print("Temperature : "); 
        Serial.print(t);
        Serial.println(" *C");
    }
    
//***********************************************************************************
//-------------------- 2. connexion au serveur web-----------------------------------
//***********************************************************************************

  Serial.print("connexion en cours sur le serveur ");
  Serial.println(host);
  Serial.print("Nom de l'objet : "); 
  Serial.println(monObjet);
  
  // utilisation de la classe WiFiClient pour la creation des connexions TCP
  WiFiClient client;
  
  // le serveur Web attend en général sur le port 80 ou 443 pour HTTPS
  const int httpPort = 80;
  
  // si la connexion ne réussit pas...
  if (!client.connect(host, httpPort)) {
    Serial.println("connection failed");
    return;
  }

  // la connexion fonctionne on cree l'URI pour la requete
  String url = String("/dweet/for/");

  Serial.print("Demande URL : ");
  Serial.println(url);


//***********************************************************************************
//-------------------- 3. envoi des donnees sur le serveur web-----------------------------------
//***********************************************************************************

 
  // on envoie les données
  if (client.connected())
  {
       Serial.print(F("Envoi de la requete..."));
        // On l'envoie au serveur sur plusieurs lignes
         // POST  HTTP/1.1
         // Host: dweet.io
         // Connection: close
         // 
         // La première ligne indique la version du protocole HTTP
         // La deuxième le nom du serveur
         // important car on peut trouver différents serveurs à une même adresse IP
         // La troisième ligne indique que le serveur doit fermer la 
         // connexion apres la réponse et ne pas attendre d'autres requêtes.

         // affichage dans le moniteur serie afin de controler ce qui sera envoyé au serveur web :
         Serial.println(String("POST ")+ url + monObjet +String("?temperature=")+String(t)+String("&humidite=")+String(h)+ " HTTP/1.1\r\n" +
               "Host: "+host + "\r\n" + 
               "Connection: close\r\n\r\n");
    
         // envoi de la requete        
         client.print(String("POST ")+ url + monObjet +String("?temperature=")+String(t)+String("&humidite=")+String(h)+ " HTTP/1.1\r\n" +
               "Host: "+host + "\r\n" + 
               "Connection: close\r\n\r\n");
   
         // On attend 1 seconde
         delay(1000);
  }


  else
  {
          Serial.println(F("Connection failed"));
          return;
  }

   Serial.println(F("Deconnexion..."));
  
    Serial.println(F(""));
  
     delay(10000);
  
 
}
