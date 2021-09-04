// C++ code
//

int area;
void setup()
{	
    
    Serial.begin(9600);
    float pi = 3.14159;
    int radius = 10;
    area = radius * radius * pi;	
}

void loop()
{
  Serial.print("area=");
  Serial.println(area);
  delay(1000);
}
