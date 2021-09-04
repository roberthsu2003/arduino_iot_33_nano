// C++ code
//

#define pi 3.14159

int area;
void setup()
{	
    
    Serial.begin(9600);    
    int radius = 10;
    area = radius * radius * pi;	
}

void loop()
{
  Serial.print("area=");
  Serial.println(area);
  delay(1000);
}
