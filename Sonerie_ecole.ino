#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <LiquidCrystal_I2C.h>

#define ssid  "Lynx" // Remplacez par votre SSID
#define password  "Beniiii2" // Remplacez par votre mot de passe
#define RECREATION_HOUR 12 
#define RECREATION_MINUTE 16
 #define RETURN_HOUR 15
  #define RETURN_MINUTE 30 
  #define BUZZER_PIN 13 

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");
// creer une instance pour l'écran LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

//Week Days
String weekDays[7]={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Month names
String months[12]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
// Fonction pour se connecter au réseau Wi-Fi
void connectToWiFi() {
    Serial.print("Connexion à ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password); // Démarrer la connexion au réseau

    while (WiFi.status() != WL_CONNECTED) { // Attendre la connexion
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("Connexion établie !");
    Serial.print("Adresse IP : ");
    Serial.println(WiFi.localIP()); // Afficher l'adresse IP obtenue
}


void setup() {
 lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("connecting...");
  Serial.begin(115200); // Démarrer la communication série
  delay(10);
  
 connectToWiFi();
 pinMode(BUZZER_PIN, OUTPUT);

// Initialize a NTPClient to get time
  timeClient.begin();
  // Set offset time in seconds to adjust for your timezone, for example:
  // GMT +1 = 3600
  // GMT +8 = 28800
  // GMT -1 = -3600
  // GMT 0 = 0
  timeClient.setTimeOffset(3600);
  lcd.clear();
}

void loop() {
  timeClient.update();
  lcd.clear();

  time_t epochTime = timeClient.getEpochTime();
  Serial.print("Epoch Time: ");
  Serial.println(epochTime);
  
  String formattedTime = timeClient.getFormattedTime();
  Serial.print("Formatted Time: ");
  Serial.println(formattedTime); 
  lcd.setCursor(0, 0);
  lcd.print(formattedTime); 
   

  int currentHour = timeClient.getHours();
  Serial.print("Hour: ");
  Serial.println(currentHour);  

  int currentMinute = timeClient.getMinutes();
  Serial.print("Minutes: ");
  Serial.println(currentMinute); 
   
  int currentSecond = timeClient.getSeconds();
  Serial.print("Seconds: ");
  Serial.println(currentSecond);  

  String weekDay = weekDays[timeClient.getDay()];
  Serial.print("Week Day: ");
  Serial.println(weekDay);    

  //Get a time structure
  struct tm *ptm = gmtime ((time_t *)&epochTime); 

  int monthDay = ptm->tm_mday;
  Serial.print("Month day: ");
  Serial.println(monthDay);
  lcd.setCursor(0, 1);
  lcd.print("Date: ");
  lcd.print(monthDay);
  lcd.print("/");

  int currentMonth = ptm->tm_mon+1;
  Serial.print("Month: ");
  Serial.println(currentMonth);
  lcd.print(currentMonth);
  lcd.print("/");

  String currentMonthName = months[currentMonth-1];
  Serial.print("Month name: ");
  Serial.println(currentMonthName);

  int currentYear = ptm->tm_year+1900;
  Serial.print("Year: ");
  Serial.println(currentYear);
  lcd.print(currentYear);

  //Print complete date:
  String currentDate = String(currentYear) + "-" + String(currentMonth) + "-" + String(monthDay);
  Serial.print("Current date: ");
  Serial.println(currentDate);

  Serial.println("");
  if ((currentHour == RECREATION_HOUR && currentMinute == RECREATION_MINUTE) || 
    (currentHour == RETURN_HOUR && currentMinute == RETURN_MINUTE)) { 
    digitalWrite(BUZZER_PIN, HIGH); // Allumez le buzzer 
    delay(1000); // Faites sonner le buzzer pendant 1 seconde 
    digitalWrite(BUZZER_PIN, LOW); // Éteignez le buzzer 
}
 
  delay(2000);
}
