// import des bibliothèques
#include <HTTPClient.h>
#include <WiFi.h>


/*************compléter cette partie avec l'identifiant et le mot de passe de votre Box*********/
// identifiant de votre box
  const char* ssid     = ".................";
// mot de passe
  const char* password = ".................";

  String keyword1 = String("\"sol\":"); //chaîne que l'on recherche dans le JSON pour la temperature
  String keyword2 = String("\"2019-"); //chaîne que l'on recherche dans le JSON 
  String keyword3 = String("..............."); //chaîne que l'on recherche dans le JSON pour le vent_moyen
  String keyword4 = String("..............."); //chaîne que l'on recherche dans le JSON pour le vent_rafales
  
  char*  valeur;
  String lignedate;
  String ligne1,ligne3, ligne4;
// la chaine envoyee par infoclimat est du type : 
// {"request_state":200,"request_key":"fd543c77e33d6c8a5e218e948a19e487","message":"OK","model_run":"20","source":"internal:GFS:1","2018-10-22 23:00:00":{"temperature":{"2m":282.7,"sol":285,"500hPa":-0.1,"850hPa":-0.1},"pression":{"niveau_de_la_mer":103080},"pluie":0,"pluie_convective":0,"humidite":{"2m":91.6},"vent_moyen":{"10m":12.7},"vent_rafales":{"10m":40.4},"vent_direction":{"10m":401},"iso_zero":3519,"risque_neige":"non","cape":0,"nebulosite":{"haute":0,"moyenne":0,"basse":5,"totale":5}},


  int pos1 ; // stockage index des positions des mots clés "sol":
  int pos2; // stockage index des positions des mots clés "2019-
  int pos3; // stockage index des positions des mots clés vent moyen
  int pos4; // stockage index des positions des mots clés vent rafales
  float temperature[15];
  /************ Compléter les déclarations de variables pour les vitesses de vent******/
  
  ......................................................
  
  ......................................................
  

  
  int i=0;
  int  longueur;

// index du début des valeurs recherchées mois date heure dans la donnée : "2019-mm-jj 23:00:00" 
  int posmois=6;
  int posjour=9;
  int posheure=12;
// tableau de stokage des numéros de mois
  String mois[15];
//  tableau de stokage des jours
  String jour[15];
  String nommois[]={"Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre"};
//  tableau de stokage des heures
  String heure[15];


void setup() 
{
  
  Serial.begin(115200);
  Serial.print("identifiant de la box : ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("attente de la connexion...");
  }

  Serial.println("connexion reussie...");
}

// certificat de connexion en https

const char* root_ca= \
"-----BEGIN CERTIFICATE-----\n" \
"MIIDSjCCAjKgAwIBAgIQRK+wgNajJ7qJMDmGLvhAazANBgkqhkiG9w0BAQUFADA/\n" \
"MSQwIgYDVQQKExtEaWdpdGFsIFNpZ25hdHVyZSBUcnVzdCBDby4xFzAVBgNVBAMT\n" \
"DkRTVCBSb290IENBIFgzMB4XDTAwMDkzMDIxMTIxOVoXDTIxMDkzMDE0MDExNVow\n" \
"PzEkMCIGA1UEChMbRGlnaXRhbCBTaWduYXR1cmUgVHJ1c3QgQ28uMRcwFQYDVQQD\n" \
"Ew5EU1QgUm9vdCBDQSBYMzCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEB\n" \
"AN+v6ZdQCINXtMxiZfaQguzH0yxrMMpb7NnDfcdAwRgUi+DoM3ZJKuM/IUmTrE4O\n" \
"rz5Iy2Xu/NMhD2XSKtkyj4zl93ewEnu1lcCJo6m67XMuegwGMoOifooUMM0RoOEq\n" \
"OLl5CjH9UL2AZd+3UWODyOKIYepLYYHsUmu5ouJLGiifSKOeDNoJjj4XLh7dIN9b\n" \
"xiqKqy69cK3FCxolkHRyxXtqqzTWMIn/5WgTe1QLyNau7Fqckh49ZLOMxt+/yUFw\n" \
"7BZy1SbsOFU5Q9D8/RhcQPGX69Wam40dutolucbY38EVAjqr2m7xPi71XAicPNaD\n" \
"aeQQmxkqtilX4+U9m5/wAl0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNV\n" \
"HQ8BAf8EBAMCAQYwHQYDVR0OBBYEFMSnsaR7LHH62+FLkHX/xBVghYkQMA0GCSqG\n" \
"SIb3DQEBBQUAA4IBAQCjGiybFwBcqR7uKGY3Or+Dxz9LwwmglSBd49lZRNI+DT69\n" \
"ikugdB/OEIKcdBodfpga3csTS7MgROSR6cz8faXbauX+5v3gTt23ADq1cEmv8uXr\n" \
"AvHRAosZy5Q6XkjEGB5YGV8eAlrwDPGxrancWYaLbumR9YbK+rlmM6pZW87ipxZz\n" \
"R8srzJmwN0jP41ZL9c8PDHIyh8bwRLtTcm1D9SZImlJnt1ir/md2cXjbDaJWFBM5\n" \
"JDGFoqgCWjBH4d1QB7wCCZAA62RjYJsWvIjJEubSfZGL+T0yjWW06XyxV3bqxbYo\n" \
"Ob8VZRzI9neWagqNdwvYkQsEjgfbKbYK7p2CNTUQ\n" \
"-----END CERTIFICATE-----\n";




void loop() 
{
  // si la connexion est etablie
  if (WiFi.status() == WL_CONNECTED) 
  {

       Serial.println("requete https");
    // creation de l'objet http de la classe HTTPClient
       HTTPClient http;
       
    // connexion au site infoclimat
       http.begin("https://www.infoclimat.fr/public-api/gfs/json?_ll=46.16667,1.86667&_auth=Bx0AF1EvACJec1NkAXcHLlE5VWBZL1VyVysEZwliAH0Ja1Q2AWRWMgdvWyYPIAQxVHkCagw1AD5RNAdnDnxVKQdnAGRRMwBmXjJTOQEyByxRfVUoWWdVclcrBGEJegBlCXRUMQFrVj0Hdls4DzkEM1R4An0MMgA9UTYHaQ5nVTEHZwBtUTAAZF4uUy4BNAdgUWdVZ1lnVWVXPARlCTcAMAlvVDkBYlY3B3ZbMQ8%2FBDNUYQJhDDcAMVEzB38OfFVPBxcAeVFyACBeZFN3ASwHZlE8VWE%3D&_c=4aa3671e89f10f8ba182c6c08195fe95", root_ca); //Specify the URL and certificate
       delay(1000); 
    // obtention du code http qui vaut 200 si la requete GET fonctionne       
       int httpCode = http.GET();
       Serial.println(httpCode);
       
    if (httpCode > 0) 
    {
       i=0; // i est le compteur de lecture des données i va de 0 à 14
      
      // lecture des donnees JSON
         String ligne = http.getString();
        
         Serial.print("ligne_json = ");
         Serial.println(ligne);
               
       // PARSER LES DONNEES

        // pos1 est l'index de position du mot clé "sol:"
        // indexOf donne l'index de position du premier caractere du mot clé "sol:",
           pos1 = ligne.indexOf(keyword1);

        // pos2 est l'index de position du mot clé "2019-"
           pos2=ligne.indexOf(keyword2);
        
        // pos3 et pos4 sont les index de position des vitesses de vent
           pos3=ligne.indexOf(keyword3);
           pos4=ligne.indexOf(keyword4);
           
                   
        while(pos1>=0 && i<15)  /* mot "sol" trouvé dans les données reçues */
        {
          
            if(pos2>=0) 
            { /* 2019- trouve dans la ligne reçue*/
                              
            // longueur en nombre de caracteres du JSON
                 longueur=ligne.length();
              
            // extraction de la date jusqu'à la fin de ligne
                 lignedate=ligne.substring(pos2, pos2+20);
                 Serial.print("lignedate = ");
                 Serial.println(lignedate);
                                 
            // compléter les tableaux mois, date et heure
                 heure[i]=&lignedate[posheure];
                 jour[i]=lignedate.substring(posjour,posheure);
                 mois[i]= lignedate.substring(posmois,posjour-1);                 
                               

                 Serial.print("valeur_mois_extraite= ");
                 Serial.println(mois[i]);
                 Serial.print("valeur_jour_extraite= ");
                 Serial.println(jour[i]);
                 Serial.print("valeur_heure_extraite= ");
                 Serial.println(heure[i]);
                           
           // en ajoutant la longueur du mot cle on se place à la fin de celui-ci.
              pos1 += keyword1.length();
       
              Serial.print("pos1 ");  Serial.print(i);Serial.print(" = ");
              Serial.println(pos1);
           
          // extraction de valeur à la fin de ligne
             ligne1=ligne.substring(pos1, longueur);
             Serial.print("extrait = ");
             Serial.println(ligne);

          // extraction de la valeur située jusqu'à la première vigule 
             String valeur_sol=ligne1.substring(0,ligne1.indexOf(","));
          // affichage de la donnée brute extraite
             Serial.print("temperature_sol = ");
             Serial.println(valeur_sol);
     
          
          // conversion de la valeur du format texte au format flottant
             temperature[i] = atof(&valeur_sol[0])-273;
             Serial.print("temperature_sol = ");
             Serial.println(temperature[i]);
             
            /******************VENT MOYEN 10m *******************/
          // en ajoutant la longueur du mot cle on se place à la fin de celui-ci.
              pos3 += keyword3.length();
       
              Serial.print("pos3 ");  Serial.print(i);Serial.print(" = ");
              Serial.println(pos3);
           
          // extraction de valeur à la fin de ligne
             ligne3=ligne.substring(pos3, longueur);
             Serial.print("extrait = ");
             Serial.println(ligne3);

          // extraction de la valeur vent_moyen
             String valeur_ventmoyen=ligne3.substring(...........,............);
          // affichage de la donnée brute extraite
             Serial.print("Vent_moyen = ");
             Serial.println(valeur_ventmoyen);

          // conversion de la valeur du format texte au format flottant
             vent_moyen[i] = atof(&valeur_ventmoyen[0]);
             Serial.print("vent_moyen = ");
             Serial.println(vent_moyen[i]);
             
        /******************VENT RAFALES 10m *******************/
          // en ajoutant la longueur du mot cle on se place à la fin de celui-ci.
              pos4 += keyword4.length();
       
              Serial.print("pos4 ");  Serial.print(i);Serial.print(" = ");
              Serial.println(pos4);
           
          // extraction de valeur à la fin de ligne
             ligne4=ligne.substring(pos4, longueur);
             Serial.print("extrait = ");
             Serial.println(ligne4);

          // extraction de la valeur située jusqu'à la première vigule 
             String valeur_ventrafales=ligne4.substring(0,ligne4.indexOf("}"));
          // affichage de la donnée brute extraite
             Serial.print("Vent_rafales = ");
             Serial.println(valeur_ventrafales);

             // conversion de la valeur du format texte au format flottant
             vent_rafales[i] = atof(&valeur_ventrafales[0]);
             Serial.print("vent_rafales = ");
             Serial.println(vent_rafales[i]);  
                
            
      }
            i=i+1;
            ligne=ligne.substring(pos4, longueur);
            pos1 = ligne.indexOf(keyword1);
            pos2=ligne.indexOf(keyword2);
            pos3=ligne.indexOf(keyword3);
            pos4=ligne.indexOf(keyword4);
            
     } /* fin récupération du flotant */
   
   /* fin data avalaible */

 
    for (int x=0; x < 15; x++){
       Serial.print ("Valeurs mesurees le :"); Serial.print(jour[x]);Serial.print(" "); Serial.println(nommois[mois[x].toInt()-1]); 
       Serial.println();
       Serial.print ("Heure "); Serial.print (heure[x]);Serial.print ("h ");Serial.print ("Temperature au sol = "); Serial.println(temperature[x]); 
       Serial.print ("Vent_moyen = "); Serial.println(vent_moyen[x]);
       Serial.print ("Vent_rafales = "); Serial.println(vent_rafales[x]);
       Serial.println();
    } 
      
    
    }
    http.end(); //fermeture de la connexion
  }
  
  delay(5000);
}
