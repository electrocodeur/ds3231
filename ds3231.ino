#include <DS3231.h>   //Library for RTC module 

#define DS3231_ADDRESS 0x68
DS3231 Clock;

int annee, date, mois, jour, dow;
int h;              //Variable declared for hour
int m;              //Variable declared for minute
int s;

bool h12;
bool PM;
bool Century = false;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  int h = Clock.getHour(h12, PM); //To get the Hour
  int m = Clock.getMinute();//TO get the minute
  int s = Clock.getSecond();
  annee = Clock.getYear();
  date = Clock.getDate();
  mois = Clock.getMonth(Century);
  dow = Clock.getDoW();

  Serial.print(h);
  Serial.print(":");
  Serial.print(m);
  Serial.print(":");
  Serial.println(s);
  Serial.print(date);
  Serial.print("/");
  Serial.print(mois);
  Serial.print("/");
  Serial.print(annee);
  Serial.print("\t");
  Serial.println(dow);
  delay(1000);
}
