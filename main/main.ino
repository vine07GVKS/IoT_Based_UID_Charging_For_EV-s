#include<LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

String s;

bool condition;

String b="4D0078662E7D";

int U,M,C;

int z,j,k,e;

//////////////////////////////battery voltage1////////////////

float correctionfactor1 = 0; 
int analogInput1 = A1; 
float vout1 = 0.0; 
float vin1 = 0.0; 
 
// two resistors 30K and 7.5k ohm
float R1_1 = 30000;  //   
float R2_1 = 7500; //  
int value1 = 0;
///////////////////////////////////////////////////////


//////////////////////////////solar voltage2////////////////

float correctionfactor2 = 0; 
int analogInput2 = A3; 
float vout2 = 0.0; 
float vin2 = 0.0; 
 
// two resistors 30K and 7.5k ohm
float R1_2 = 30000;  //   
float R2_2 = 7500; //  
int value2 = 0;
///////////////////////////////////////////////////////

int vin1_1;




void setup() 
{
Serial.begin(9600);
lcd.begin(16,2);

pinMode(2,INPUT);

pinMode(3,OUTPUT);/// EV 
pinMode(4,OUTPUT);/// EV 

pinMode(A4,OUTPUT);//solar connect
pinMode(A5,OUTPUT);//grid connected

 pinMode(A0,INPUT); ///pot

 pinMode(A3,INPUT); ///solar voltage

  pinMode(A1,INPUT); //battery voltage

  pinMode(5,INPUT);///peak button
 
lcd.setCursor(0,0);
lcd.print("SMART CHARGING ");
lcd.setCursor(0,1);
lcd.print("STATION EV SYSTEM         ");
digitalWrite(3,LOW);
delay(2000);
lcd.clear();

}


void loop() 

{
delay(100);
Serial.print('U');
Serial.print(U);
delay(100);
Serial.print('C');
Serial.print(C);
delay(100);
Serial.print('M');
Serial.print(M);
delay(100);
Serial.print('B'); //battery
Serial.print(vin1);
delay(100);
Serial.print('P'); //battery percentage
Serial.print(vin1_1);
delay(100);
Serial.print('S'); ///solar
Serial.print(vin2);
delay(100);

Serial.print('J'); ///solar connect
Serial.print(j);
delay(100);

Serial.print('K'); ///grid connect
Serial.print(k);
delay(100);

Serial.print('E'); ///peak time connect
Serial.print(e);
delay(100);
voltage1();

voltage2();


int a=analogRead(A0);////unit cost

if(vin2>1)
{

  
 digitalWrite(A4,HIGH); 
  digitalWrite(A5,LOW); 

  
  lcd.setCursor(14,0);
  lcd.print("Sc");
  j=1;
  k=0;
  e=0;

///////////////////////////////////////////  solar connection code ///////////////////////////////////////////

 if(a==0)
{
  
 digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:0 ");
  lcd.setCursor(5,0);
  lcd.print("         ");

  U=0;
  C=0;
  M=0;

    lcd.setCursor(14,1);
  lcd.print("  ");

     digitalWrite(3,LOW); 
}
else if(a>100 && a<200)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:5 ");

  lcd.setCursor(5,0);
  lcd.print("C-25 ");


 lcd.setCursor(11,0);
  lcd.print("10m");

  U=5;
  C=25;
  M=10;
 

    lcd.setCursor(14,1);
  lcd.print("  ");
}
  
else if(a>200 && a<300)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:8 ");

  lcd.setCursor(5,0);
  lcd.print("C-42 ");

 
  lcd.setCursor(11,0);
    lcd.print("15m");

  U=8;
  C=42;
  M=15;
 

    lcd.setCursor(14,1);
  lcd.print("  ");
}

else if(a>300 && a<400)
{
  
     digitalWrite(3,LOW); 
     
 lcd.setCursor(0,0);
  lcd.print("U:13");

  lcd.setCursor(5,0);
  lcd.print("C-67 ");


lcd.setCursor(11,0);
lcd.print("20m");

   U=13;
  C=67;
  M=20;


     lcd.setCursor(14,1);
  lcd.print("  ");
   
}
else if(a>400 && a<500)
{
  
     digitalWrite(3,LOW); 
     
   lcd.setCursor(0,0);
  lcd.print("U:17");

  lcd.setCursor(5,0);
  lcd.print("C-105");
  lcd.setCursor(11,0);
  lcd.print("25m");

    U=17;
  C=105;
  M=25;

     lcd.setCursor(14,1);
  lcd.print("  ");
  
}
else if(a>500 && a<600)
{
  
     digitalWrite(3,LOW); 

  lcd.setCursor(0,0);
  lcd.print("U:25");

  lcd.setCursor(5,0);
  lcd.print("C-140");
lcd.setCursor(11,0);
    lcd.print("30m");


    U=25;
  C=140;
  M=30;

    lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>600 && a<700)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:29");

  lcd.setCursor(5,0);
  lcd.print("C-180");
  lcd.setCursor(11,0);
  lcd.print("35m");


    U=29;
  C=180;
  M=35;
  

     lcd.setCursor(14,1);
  lcd.print("  ");
  }
else if(a>700 && a<800)
{
  
     digitalWrite(3,LOW); 
     
lcd.setCursor(0,0);
  lcd.print("U:35");

  lcd.setCursor(5,0);
  lcd.print("C-250");

lcd.setCursor(11,0);
  
  lcd.print("40m");

 
  U=35;
  C=250;
  M=40;

    lcd.setCursor(14,1);
  lcd.print("  ");

  
}
else if(a>800 && a<900)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:43");

  lcd.setCursor(5,0);
  lcd.print("C-346");
lcd.setCursor(11,0);
  lcd.print("45m");


    U=43;
  C=346;
  M=45;

    lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>900)
{
  
     digitalWrite(3,LOW); 
     
 lcd.setCursor(0,0);
  lcd.print("U:50");

  lcd.setCursor(5,0);
  lcd.print("C-500");
 lcd.setCursor(11,0);
  lcd.print("50m");

  U=50;
  C=500;
  M=50;

 
  lcd.setCursor(14,1);
  lcd.print("BF");
  

   

  
  
    // lcd.clear();

 }


}


//////////////////////////////////////   off grid contion code  /////////////////////////////////////////////

else
{

 digitalWrite(A4,LOW); 
  digitalWrite(A5,HIGH); 
  
  lcd.setCursor(14,0);
  lcd.print("Gc");

    j=0;
  k=1;
  e=0;
  

if(a==0)
{
  
  digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:0 ");
  lcd.setCursor(5,0);
  lcd.print("         ");

  U=0;
  C=0;
  M=0;
 

  
  lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>100 && a<200)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:5 ");

  lcd.setCursor(5,0);
  lcd.print("C-35 ");


 lcd.setCursor(11,0);
  lcd.print("10m");

  U=5;
  C=35;
  M=10;


  lcd.setCursor(14,1);
  lcd.print("  ");
}
  
else if(a>200 && a<300)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:8 ");

  lcd.setCursor(5,0);
  lcd.print("C-52 ");

 
  lcd.setCursor(11,0);
    lcd.print("15m");

  U=8;
  C=52;
  M=15;
   

 
  lcd.setCursor(14,1);
  lcd.print("  ");
}

else if(a>300 && a<400)
{
  
     digitalWrite(3,LOW); 
     
 lcd.setCursor(0,0);
  lcd.print("U:13");

  lcd.setCursor(5,0);
  lcd.print("C-77 ");


lcd.setCursor(11,0);
lcd.print("20m");

   U=13;
  C=77;
  M=20;

 

   lcd.setCursor(14,1);
  lcd.print("  ");
   
}
else if(a>400 && a<500)
{
  
     digitalWrite(3,LOW); 
     
   lcd.setCursor(0,0);
  lcd.print("U:17");

  lcd.setCursor(5,0);
  lcd.print("C-115");
  lcd.setCursor(11,0);
  lcd.print("25m");

  U=17;
  C=115;
  M=25;



  lcd.setCursor(14,1);
  lcd.print("  ");
  
}
else if(a>500 && a<600)
{

     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:25");

  lcd.setCursor(5,0);
  lcd.print("C-150");
lcd.setCursor(11,0);
lcd.print("30m");
  U=25;
  C=150;
  M=30;




  lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>600 && a<700)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:29");

  lcd.setCursor(5,0);
  lcd.print("C-190");
  lcd.setCursor(11,0);
  lcd.print("35m");


    U=29;
  C=190;
  M=35;


   
  lcd.setCursor(14,1);
  lcd.print("  ");
  }
else if(a>700 && a<800)
{
  
    digitalWrite(3,LOW); 
     
lcd.setCursor(0,0);
  lcd.print("U:35");

  lcd.setCursor(5,0);
  lcd.print("C-260");

lcd.setCursor(11,0);
  
  lcd.print("40m");

 
  U=35;
  C=260;
  M=40;

  lcd.setCursor(14,1);
  lcd.print("  ");
  
}
else if(a>800 && a<900)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:43");

  lcd.setCursor(5,0);
  lcd.print("C-356");
lcd.setCursor(11,0);
  lcd.print("45m");


    U=43;
  C=356;
  M=45;

  lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>900)
{
  
     digitalWrite(3,LOW); 
     
 lcd.setCursor(0,0);
  lcd.print("U:50");

  lcd.setCursor(5,0);
  lcd.print("C-510");
 lcd.setCursor(11,0);
  lcd.print("50m");

  U=50;
  C=510;
  M=50;

 lcd.setCursor(14,1);
 lcd.print("BF");


    
 }
 
}

////////////////////////////////////    Grid peak condition code  ////////////////////////////////////

z = digitalRead(2);
if(z==1)
{


  lcd.setCursor(14,0);
  lcd.print("PT");

   j=0;
  k=0;
  e=1;
  


if(a==0)
{
 
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:0 ");
  lcd.setCursor(5,0);
  lcd.print("         ");

  U=0;
  C=0;
  M=0;
 

  
  lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>100 && a<200)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:5 ");

  lcd.setCursor(5,0);
  lcd.print("C-45 ");


 lcd.setCursor(11,0);
  lcd.print("10m");

  U=5;
  C=45;
  M=10;


  lcd.setCursor(14,1);
  lcd.print("  ");
}
  
else if(a>200 && a<300)
{
  
     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:8 ");

  lcd.setCursor(5,0);
  lcd.print("C-62 ");

 
  lcd.setCursor(11,0);
    lcd.print("15m");

  U=8;
  C=62;
  M=15;
 

 
  lcd.setCursor(14,1);
  lcd.print("  ");
}

else if(a>300 && a<400)
{
  
     digitalWrite(3,LOW); 
     
 lcd.setCursor(0,0);
  lcd.print("U:13");

  lcd.setCursor(5,0);
  lcd.print("C-87 ");


lcd.setCursor(11,0);
lcd.print("20m");

   U=13;
  C=87;
  M=20;



   lcd.setCursor(14,1);
  lcd.print("  ");
   
}
else if(a>400 && a<500)
{
  
     digitalWrite(3,LOW); 
     
   lcd.setCursor(0,0);
  lcd.print("U:17");

  lcd.setCursor(5,0);
  lcd.print("C-125");
  lcd.setCursor(11,0);
  lcd.print("25m");

  U=17;
  C=125;
  M=25;

 

  lcd.setCursor(14,1);
  lcd.print("  ");
  
}
else if(a>500 && a<600)
{


     digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:25");

  lcd.setCursor(5,0);
  lcd.print("C-160");
lcd.setCursor(11,0);
lcd.print("30m");
  U=25;
  C=160;
  M=30;



  lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>600 && a<700)
{
  
     digitalWrite(3,LOW);  
     
  lcd.setCursor(0,0);
  lcd.print("U:29");

  lcd.setCursor(5,0);
  lcd.print("C-200");
  lcd.setCursor(11,0);
  lcd.print("35m");


    U=29;
  C=200;
  M=35;
 

   
  lcd.setCursor(14,1);
  lcd.print("  ");
  }
else if(a>700 && a<800)
{

     digitalWrite(3,LOW); 
  
lcd.setCursor(0,0);
  lcd.print("U:35");

  lcd.setCursor(5,0);
  lcd.print("C-270");

lcd.setCursor(11,0);
  
  lcd.print("40m");

 
  U=35;
  C=270;
  M=40;

  lcd.setCursor(14,1);
  lcd.print("  ");
  
}
else if(a>800 && a<900)
{
  
 digitalWrite(3,LOW); 
     
  lcd.setCursor(0,0);
  lcd.print("U:43");

  lcd.setCursor(5,0);
  lcd.print("C-366");
lcd.setCursor(11,0);
  lcd.print("45m");

    U=43;
  C=366;
  M=45;

  lcd.setCursor(14,1);
  lcd.print("  ");
}
else if(a>900)
{

   digitalWrite(3,LOW); 
      
 lcd.setCursor(0,0);
  lcd.print("U:50");

  lcd.setCursor(5,0);
  lcd.print("C-520");
 lcd.setCursor(11,0);
  lcd.print("50m");

  U=50;
  C=520;
  M=50;

 lcd.setCursor(14,1);
 lcd.print("BF");


    
 }
 


  
}


///////////////////////////////////  amount checking code /////////////////////////////////
       
  
if(Serial.available()>0)
{
  s=Serial.readString();
// 
// Serial.println(s);
// delay(1000);

  if(s==b)
  {
 lcd.setCursor(0,1);
 lcd.print("Amount Paid Sucuss");  
 Serial.print('N');
 delay(2000);    
 //  lcd.clear();

//////////////////////////////////////////////////// motor control logic conditon /////////////////////////////////////
    
   Serial.print('O');  
   digitalWrite(3,HIGH);  
   digitalWrite(4,LOW);  
   delay(10000);
   
    digitalWrite(3,LOW);  
    digitalWrite(4,LOW); 
  }
}

}



                                     //////////////////////////////////////////////////  
                            //       voltage sensor output voltage calculation contion 
                                     //////////////////////////////////////////////////


void voltage1()
{

    value1 = analogRead(analogInput1); 
    vout1 = (value1 * 5) / 1023.0; // see text 
    vin1 = vout1 / (R2_1/(R1_1+R2_1));
 
    vin1 = vin1+1 - correctionfactor1; 
    
    lcd.setCursor(0,1);
    lcd.print("B:");
    lcd.setCursor(2,1);
    lcd.print(vin1);
     //delay(1000);
     
     vin1_1=((vin1/12)*100);


//    lcd.setCursor(12,0);
//
//    lcd.print(vin1_1);
//
//    lcd.print("% ");    
  
}



void voltage2()
{

    value2 = analogRead(analogInput2); 
    vout2 = (value2 * 5) / 1023.0; // see text 
    vin2 = vout2 / (R2_2/(R1_2+R2_2));
 
    vin2 = vin2 - correctionfactor2; 
    
    lcd.setCursor(7,1);
    lcd.print("S:");
    lcd.setCursor(9,1);
    lcd.print(vin2);
    
     
}
