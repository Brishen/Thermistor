// Takes a Thermistor reading and converts it to Fahrenheit. Needs the resistance of the added resistors. Currently valid for 0 to 95 F
// To get better accuracy outside that range, split the resistance ranges of the thermistor and perform a logarthmic regression upon each
// interval.

int ThermistorPin = A0; //analog pin 0
int RRestistor = 49.3;  //Value of the resistors between thermistor and ground in KiloOhms

void setup(){
  Serial.begin(9600);
}

void loop(){
  float ThermistorReading = analogRead(ThermistorPin); 
  float ScaledReading=(ThermistorReading * 1/1023)*5;
  float Current=ScaledReading*1/RRestistor;        
  float RThermistor=(5-ScaledReading)/Current;
  float TempC=-21.62*log(RThermistor)+109.75;    //Logarithmic regression for 503AT-2 Thermistor. R^2=0.9992 for 0 to 35 C (0 to 95 F)
  int   TempF=TempC*1.8+32;
  
// Serial.println(thermistorReading);
//  Serial.println(ScaledReading);
//  Serial.println(Current); 
  Serial.println(TempF);

  delay(1000); //just here to slow down the output for easier reading
}
