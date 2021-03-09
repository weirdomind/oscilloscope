void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}
float last=0;
int count=0;
void loop()
{
  int val=analogRead(0);
  float percentage = (val/1024.00)*100.10;
  for (int i=0;i<percentage;i++){
    Serial.print("_");
  }
//  Serial.println();
  if(last>percentage+1){
    Serial.print("\/");
  }
  else if(last<percentage-1){
    Serial.print("\\");
  }
  else {
    Serial.print("|");
  }
  Serial.println(int(percentage));
  analogWrite(9,(percentage/100)*255);
  delay(10);
  last=percentage;
}
