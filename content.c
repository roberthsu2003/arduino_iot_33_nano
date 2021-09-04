// C++ code
//
void setup()
{
	int area;
    Serial.begin(9600);
    float pi = 3.14159;
    int radius = 10;
    area = radius * radius * pi;
	Serial.print("area=");
    Serial.println(area);
}

void loop()
{
  
}
