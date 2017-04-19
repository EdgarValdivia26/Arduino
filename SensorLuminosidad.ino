/*SENSOR DE LUZ Y CONTROL DE LUCES PARA EL PROYESTO DE HOME SWEET HOME*/

int PinSensor = A0; 
int PinSalida = 3;
int LecturaSensor = 0;
/*PUERTOS PARA LAS LUCES DE LA CASA*/
int LedSalaComedor = 13;
int LedCocina = 12;
int LedCochera = 11;
int LedPlantaAlta = 10;
int LedCuartos = 9;
int LedExterior = 8;
int estado = 0;
/*ABRIR COCHERA Y PONER SEGURO QUEDARÁN PENDIENTE HASTA VER COMO HACERLE AHI*/

void setup() {
  pinMode(PinSalida,OUTPUT); 
  pinMode(PinSensor,INPUT);

  Serial.begin(9600);
  pinMode(LedSalaComedor,OUTPUT);
  pinMode(LedCocina,OUTPUT);
  pinMode(LedCochera,OUTPUT);
  pinMode(LedPlantaAlta,OUTPUT);
  pinMode(LedCuartos,OUTPUT);
  pinMode(LedExterior,OUTPUT);
}

void loop() {
/*AQUI ESTA LA PARTE DE LAS LUCES EXTERNAS QUE SON AUTOMÁTICAS*/  
  LecturaSensor = analogRead (PinSensor);
    if(LecturaSensor < 200)
        {
        digitalWrite(PinSalida,HIGH);
        delay(800);
        }
        else
          {
          digitalWrite(PinSalida,LOW);
          delay(200);
          }
/*AQUI COMIENZA LA PARTE DEL DISPOSITIVO MÓVIL CONTROLANDO LOS LEDS DE LA CASA*/
  if(Serial.available()>0){
    estado = Serial.read();
  }          


  
  if(estado == '1'){
    digitalWrite(LedSalaComedor,HIGH);    
    }
  if(estado == 'a'){
    digitalWrite(LedSalaComedor,LOW);    
    }
  if(estado == '2'){
    digitalWrite(LedCocina,HIGH);    
    }
  if(estado ==  'b'){
    digitalWrite(LedCocina,LOW);    
    }
  if(estado == '3'){
    digitalWrite(LedCochera,HIGH);    
    }
  if(estado ==  'c'){
    digitalWrite(LedCochera,LOW);    
    }  
  if(estado == '4'){
    digitalWrite(LedPlantaAlta,HIGH);    
    }
  if(estado == 'd'){
    digitalWrite(LedPlantaAlta,LOW);    
    }
  if(estado == '5'){
    digitalWrite(LedCuartos,HIGH);    
    }
  if(estado == 'e'){
    digitalWrite(LedCuartos,LOW);    
    }
  if(estado == '6'){
    digitalWrite(LedExterior,HIGH);    
    }
  if(estado == 'f'){
    digitalWrite(LedExterior,LOW);    
    }
}
