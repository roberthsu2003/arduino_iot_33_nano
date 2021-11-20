/*
 * *mfrc522_1
 * *讀取卡片UID，從監控視窗查看
 */
#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal_I2C.h>


#define RST_PIN         9          
#define SS_PIN          10  //就是模組上的SDA接腳,可以任意pin腳


MFRC522 mfrc522;   // 建立MFRC522實體
LiquidCrystal_I2C lcd(0x27,20,2);

void setup() {
  while(!Serial);
  Serial.begin(9600); 

  SPI.begin();  // 初始化SPI介面
  

  mfrc522.PCD_Init(SS_PIN, RST_PIN); // 初始化MFRC522卡
  Serial.print("Reader ");
  Serial.print(": ");
  mfrc522.PCD_DumpVersionToSerial(); // 顯示讀卡設備的版本

  lcd.init();
  lcd.backlight();
  lcd.setCursor(5,0);
  lcd.print("CLOSE!!");
  lcd.setCursor(2,1);
  lcd.print("Hollo! Arduino!");  
}



void loop() {
  // 檢查是不是一張新的卡
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      // 顯示卡片內容
      Serial.print("Card UID:");
      dump_byte_array(mfrc522.uid.uidByte, mfrc522.uid.size); // 顯示卡片的UID     
      Serial.println();
      Serial.print("PICC type: ");
      MFRC522::PICC_Type piccType = mfrc522.PICC_GetType(mfrc522.uid.sak);
      Serial.println(mfrc522.PICC_GetTypeName(piccType));  //顯示卡片的類型
      mfrc522.PICC_HaltA();  // 卡片進入停止模式
    }
}

/**
 * 這個副程式把讀取到的UID，用16進位顯示出來
 */
void dump_byte_array(byte buffer[], byte bufferSize) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("CARD_ID:");
  lcd.setCursor(0,1);
  for (byte i = 0; i < bufferSize; i++) {    
    lcd.print(buffer[i] < 0x10 ? " 0" : " ");
    lcd.print(buffer[i],HEX);
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);        
   }
      
}
