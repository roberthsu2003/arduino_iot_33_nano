# 智慧家庭
## 硬體設備
### 主要設備:
Arduino Nano 33 IoT
![aruduon_nano_33_iot_with_header](abx00032_iso.jpg)
### [周邊零件](./周邊零件/README.md)
## 一般操作
0_0. [電腦傳送資料給Arduino](./一般操作/0_0由電腦傳送資料給Arduino/)

1_0. [按鈕](./一般操作/1_0無使用上拉電阻/)

1_1. [上拉電阻](./一般操作/1_1上拉電阻/)

2_0. [bit操控Led](./一般操作/2_0bitLed/)

2_1. [七段顯示器](./一般操作/2_1七段顯示器/)

3. [事件導向](https://github.com/roberthsu2003/smartHome/tree/master/%E4%B8%80%E8%88%AC%E6%93%8D%E4%BD%9C/3%E4%BA%8B%E4%BB%B6%E5%B0%8E%E5%90%91/1%E9%96%93%E9%9A%94%E6%99%82%E9%96%93%E5%9F%B7%E8%A1%8C)

4. [陀螺儀感測](https://github.com/roberthsu2003/smartHome/tree/master/%E4%B8%80%E8%88%AC%E6%93%8D%E4%BD%9C/4%E9%99%80%E8%9E%BA%E5%84%80%E6%84%9F%E6%B8%AC)

5. [xyz軸感測](https://github.com/roberthsu2003/smartHome/tree/master/%E4%B8%80%E8%88%AC%E6%93%8D%E4%BD%9C/5xyz%E8%BB%B8%E6%84%9F%E6%B8%AC)

## Blynk網路服務
### [Blynk說明](./使用Blynk)
1. [手機控制LED動作](https://github.com/roberthsu2003/smartHome/tree/master/%E4%BD%BF%E7%94%A8Blynk/1led_control)

2. [手機顯示可變電阻動作](https://github.com/roberthsu2003/smartHome/tree/master/%E4%BD%BF%E7%94%A8Blynk/2%E5%8F%AF%E8%AE%8A%E9%9B%BB%E9%98%BB)

3. [手機當作門窗防盜器](./使用Blynk/3迷你磁簧開關/)
	- 使用virtual pin 傳送資料 -> WidgetLed class

4. [手機接受Button訊號](./使用Blynk/4Button/)
	- 使用virtual pin 傳送資料 -> Blynk.virtualWrite(V4, HIGH)

## 及時資料庫
1. [網頁顯示LED狀態](https://github.com/roberthsu2003/smartHome/tree/master/%E5%8F%8A%E6%99%82%E8%B3%87%E6%96%99%E5%BA%AB/1led_control)

2. [網頁監控觸控裝置](https://github.com/roberthsu2003/smartHome/tree/master/%E5%8F%8A%E6%99%82%E8%B3%87%E6%96%99%E5%BA%AB/2touch_sensor)

3. [網頁監控環境溫溼度](https://github.com/roberthsu2003/smartHome/tree/master/%E5%8F%8A%E6%99%82%E8%B3%87%E6%96%99%E5%BA%AB/3dht11) 

## LihgtBlue手機藍牙app
1. [手機藍牙控制LED](https://github.com/roberthsu2003/smartHome/tree/master/%E4%BD%BF%E7%94%A8%E8%97%8D%E7%89%99/1led_control)

## IFTTT服務
1. [Arduino發送溫溼度訊息給line群組](https://github.com/roberthsu2003/smartHome/tree/master/%E4%BD%BF%E7%94%A8IFTTT/1dht11)

## ThingSpeak 服務
1. [收集資料，繪制圖表](https://github.com/roberthsu2003/smartHome/tree/master/%E4%BD%BF%E7%94%A8ThingSpeak)


## Arduino當作WebServer
1.[Web Service](https://github.com/roberthsu2003/smartHome/tree/master/%E7%95%B6%E4%BD%9CWebServer)


## arduino nano 33 iot使用說明
![aruduon_nano_33_iot_with_header](abx00032_iso.jpg)


#### 跳線線路圖

![](nanoV33_bb.jpg)

#### 跳線麵包板
![](IMG_0383.jpg)

#### pin腳
![](pin.jpg)

#### 開發板管理員
![](boardManager.png)

#### 程式庫管理員
- wifi  
![](wifinina.png)

- 藍牙   
![](arduinoBLE.png)

- 陀螺儀和加速度計(LSM6DS3)  
![](LSM6DS3.png)

#### arduino naon 33 iot 說明文件
https://content.arduino.cc/assets/Pinout-NANO33IoT_latest.pdf
