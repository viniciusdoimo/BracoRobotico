String strGeral, dispositivo, valorRecebido;
int rotacao;
int a;

#include <Servo.h> 
int servo_1= 3; 
int servo_2= 5; 
int servo_3= 6; 
int servo_4= 9; 


void setup()
{
  Serial.begin(9600);

  pinMode(servo_1,OUTPUT);
  pinMode(servo_2,OUTPUT);
  pinMode(servo_3,OUTPUT);
  pinMode(servo_4,OUTPUT);
}


void divideDados() 
{
  if (strGeral.indexOf(" ") >=0){                                    //verifica se os dados recebidos possuem "espaços"
      dispositivo = strGeral.substring(0,(strGeral.indexOf(" ")));    //retira a string "Dimmer 1 e 2". Pega desde o primeiro caractere até o espaço em branco.
      valorRecebido = strGeral.substring(strGeral.indexOf(" ")+1);  //pega o valor do dispositivo, se é o dimmer "1" ou o dimmer "2". A partir do "espaço" até o proximo valor
  }
}


void loop()
{
   
 if (Serial.available()) 
 {
    strGeral = String("");
    while (Serial.available()) 
    {
      strGeral = strGeral + char(Serial.read());
      delay(1);
    }
   }

   //delay(10);


   divideDados();

      rotacao = valorRecebido.toInt();

 /* 
      Serial.println("\nString Geral: " + strGeral);
      Serial.println("Dispositivo: " + dispositivo);
      Serial.println("Valor recebido: " + valorRecebido); 
      Serial.println(rotacao); 
  */      
 
//---------------------------------------------------------
    
  
    if(dispositivo== "Z")  //ok
    {
    //  Serial.println(rotacao);

    rotacao = map(rotacao, 0, -70, 0, 255); 
    
    if((rotacao >= 0) && (rotacao <= 255))
    {
     analogWrite(servo_1,rotacao);
    }

   
    if(rotacao == 255)
    {
     digitalWrite(servo_1,255);
    }

    if(rotacao <= 0)
    {
    digitalWrite(servo_1,0);
    }
    }


//---------------------------------------------------------


    if(dispositivo== "Y")   //ok
    {
    //   Serial.println(rotacao);

    rotacao = map(rotacao, 130, 250, 0, 255); 
    
    if((rotacao >= 0) && (rotacao <= 255))
    { 
     analogWrite(servo_2,rotacao);
    }


    if(rotacao == 255)
    {        
     digitalWrite(servo_2,HIGH);
    }

    if(rotacao <= 0)
    {    
    digitalWrite(servo_2,LOW); 
    }
    }


//---------------------------------------------------------


   if(dispositivo== "G")  // ok
   {
   //   Serial.println(rotacao);
    
   if(rotacao ==3)
   {
   analogWrite(servo_3,90);
   }

   else
   {
   digitalWrite(servo_3,LOW);
   }
   }



//---------------------------------------------------------


if(dispositivo== "rolagem")  // ok
   {

   rotacao = map(rotacao, 0, 90, 0, 255); 
    
    if(rotacao >0)
    {
     analogWrite(servo_3,rotacao);
   }

   if(rotacao <=0)
   {
   digitalWrite(servo_3,0);
   }
   }


//---------------------------------------------------------


if(dispositivo== "angulo")
   {
    
    a=rotacao;

     rotacao = map(rotacao, -100, -45, 0, 255);

     Serial.println(rotacao);

    if((rotacao <=255) && (rotacao >=0)) 
    { 
     analogWrite(servo_3,rotacao);
    }


   if(rotacao <=0)
   {
   digitalWrite(servo_3,0);
   } 
   }
}
