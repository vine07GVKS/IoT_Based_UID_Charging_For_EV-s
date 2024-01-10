/*
Power scheduling
email id:20e908@psgtech.ac.in
blynk password: projectiot2023
*/



/* Fill-in information from Blynk Device Info here */

//#define BLYNK_TEMPLATE_ID "TMPL3IDKA8aYP"
//#define BLYNK_TEMPLATE_NAME "IOT Based EV Charging"
//#define BLYNK_AUTH_TOKEN "e5Vws0b9PWT2CNG7fYEDvCq2L8R_i7-I"


#define BLYNK_TEMPLATE_ID "TMPL3IDKA8aYP"
#define BLYNK_TEMPLATE_NAME "IOT Based EV Charging"
#define BLYNK_AUTH_TOKEN "Btmhaxi4rGb9IeSa1OsqMhCzuvmOn51p"

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "projectiot2023";
char pass[] = "";



//Change the virtual pins according the rooms
#define VPIN_1    V0  // Unit
#define VPIN_2    V1  // cost
#define VPIN_3    V2  // Time
#define VPIN_4    V3  // Amount paid 
#define VPIN_5    V4  // battery voltage
#define VPIN_6    V5  // battery percentage
#define VPIN_7    V6  // Solar Voltage
#define VPIN_8    V7  // solar connect
#define VPIN_9    V8  // grid connect
#define VPIN_10   V9  // peaktime connect




BLYNK_CONNECTED()
{
  Blynk.syncVirtual(VPIN_1);
  Blynk.syncVirtual(VPIN_2);
  Blynk.syncVirtual(VPIN_3);
  Blynk.syncVirtual(VPIN_4);
  Blynk.syncVirtual(VPIN_5);
  Blynk.syncVirtual(VPIN_6);
  Blynk.syncVirtual(VPIN_7);
  Blynk.syncVirtual(VPIN_8);
  Blynk.syncVirtual(VPIN_9);
  Blynk.syncVirtual(VPIN_10);
}


void setup()
{

  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);
  //Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();
  if (Serial.available()>0) 
  {
  char a=Serial.read();
  //Serial.print(a);



/////////////////   UNIT  ////////////////
    if(a=='U')
    {  
      int  u=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_1,u); 
    }

    
////////////////// cost ///////////////////       
  if(a=='C')
    {  
      int  c=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_2,c); 
    }

    
//////////////// minutes ////////////////////
  if(a=='M')
    {  
      int m=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_3,m); 
    }


////////////// amount status /////////////////
if(a=='N')
    {  
      Blynk.virtualWrite(VPIN_4,HIGH); 
    }
       
  if(a=='O')
    {  
      Blynk.virtualWrite(VPIN_4,LOW); 
    }
    
/////////////////////////////////////////////////
    

//////////// battery voltage ////////////////////
if(a=='B')
    {  
      int b=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_5,b); 
    }

///////////// battery percentage ///////////////////
if(a=='P')
    {  
      int p=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_6,p); 
    } 
    

//////////////// solar voltage //////////////////

if(a=='S')
    {  
      int s=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_7,s); 
    } 


////////////// solar connected /////////////////
if(a=='J')
    {  
      int j=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_8,j); 
    } 

 
///////////  off grid connected /////////////   
if(a=='K')
    {  
      int k=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_9,k); 
    }

    
/////////////   peak connected ///////////////
if(a=='E')
    {  
      int e=Serial.parseInt(); 
      Blynk.virtualWrite(VPIN_10,e); 
    } 
    
 }
}
