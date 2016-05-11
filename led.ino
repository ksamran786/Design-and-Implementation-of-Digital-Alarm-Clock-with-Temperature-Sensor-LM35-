#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const byte numRows= 4; //number of rows on the keypad
const byte numCols= 4; //number of columns on the keypad
int sec[2],minn[2],hour[2],Day[2],Month[2],Alarm[4],selc,v,j;
//keymap defines the key pressed according to the row and columns just as appears on the keypad
char keymap[numRows][numCols]= 
{
{'1', '2', '3', 'A'}, 
{'4', '5', '6', 'B'}, 
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};
//Code that shows the the keypad connections to the arduino terminals
byte rowPins[numRows] = {9,8,7,6}; //Rows 0 to 3
byte colPins[numCols]= {5,4,3,2}; //Columns 0 to 3


LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
Keypad myKeypad= Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//************************************************************
void display()
{
  
int rawvoltage= analogRead(0);
float millivolts= (rawvoltage/1024.0) * 5000;
float celsius= millivolts/10;
lcd.setCursor(0,0);
lcd.print(celsius);
lcd.print("C");
lcd.setCursor(0,1);
lcd.print("Bremen");
lcd.setCursor(9,1);
lcd.print("/");
lcd.setCursor(12,1);
lcd.print("/");
lcd.setCursor(9,0);
lcd.print(":");
lcd.setCursor(12,0);
lcd.print(":");
}
int setTime(int value, char keypressed)
{
  switch(keypressed)
  {
    case '1':
    {
      lcd.print(keypressed);
      value=1;
      return value;
      break;
    }
    case '2':
    {
      lcd.print(keypressed);
      value=2;
      return value;
      break;
    }
    case '3':
    {
      lcd.print(keypressed);
      value=3;
      return value;
      break;
    }
    case '4':
    {
      lcd.print(keypressed);
      value=4;
       return value;
       break;
    }
    case '5':
    {
      lcd.print(keypressed);
      value=5;
      return value;
      break;
    }
    case '6':
    {
      lcd.print(keypressed);
      value=6;
      return value;
      break;
    }
    case '7':
    {
      lcd.print(keypressed);
      value=7;
      return value;
      break;
    }
    case '8':
    {
      lcd.print(keypressed);
      value=8;
      return value;
      break;
    }

    case '9':
    {
      lcd.print(keypressed);
      value=9;
      return value;
      break;
    }
    case '0':
    {
      lcd.print(keypressed);
      value=0;
      return value;
      break;
    }
    default:
    break;
    }
  
 }
 //*****************************************************
int setHour(int hour[2])
{
  int i=0;
do{
back11:
  char keypressed = myKeypad.getKey();
  if(keypressed)
  {
    {
      lcd.setCursor(7+i,0);
      int vv= setTime(v,keypressed);
      hour[i]=vv;
      if ((hour[0]<=2) && (hour[1]<4))
      {
        i++;
      }
      else if((hour[0]<=1) && (hour[1]<=9))
      {
        i++;
      }
      else
      {
        lcd.setCursor(7+i,0);
        lcd.print(" ");
        goto back11;
      }
    }
  }
}while( i < 2);
for (i=0;i<2;i++)
return hour[i];
}

 //*****************************************************
int setMin(int minn[2])
{
 int i=0;
do{
back1:
  char keypressed = myKeypad.getKey();
  if(keypressed)
  {
    {
      lcd.setCursor(10+i,0);
      int vv= setTime(v,keypressed);
      minn[i]=vv;
      if (minn[0]<=5)
      {
        i++;
      }
      else
      {
        lcd.setCursor(10+i,0);
        lcd.print(" ");
        goto back1;
      }
    }
  }
}while( i < 2);
for (i=0;i<2;i++)
return minn[i];
}

 //*****************************************************
int setSec(int sec[2])
{
  int i=0;
  do
  {
    back:
    char keypressed = myKeypad.getKey();
    if(keypressed)
    {
      {
        lcd.setCursor(13+i,0);
        int vv= setTime(v,keypressed);
        sec[i]=vv;
        if (sec[0]<=5)
        {
          i++;
        }
        else
        {
          lcd.setCursor(13+i,0);
          lcd.print(" ");
          goto back;
        }
      }
    }
 }while( i < 2);
for (i=0;i<2;i++)
return sec[i];
}

 //*****************************************************
void setDay(int Day[2])
{
  int i=0;
  do
  {
    back11:
    char keypressed = myKeypad.getKey();
    if(keypressed)
    {
      {
        lcd.setCursor(7+i,1);
        int vv= setTime(v,keypressed);
        Day[i]=vv;
        if((Day[0]==3) && (Day[1]<=1))
        {
          i++;
        }
        else if ((Day[0]<=2) && (Day[1]<=9))
        {
          i++;
        }
        else
        {
          lcd.setCursor(7+i,1);
          lcd.print(" ");
          goto back11;
        }
      }
    }
  }while( i < 2);
}
 //*****************************************************
void setMonth(int Month[2])
{
  int i=0;
  do
  {
    back111:
    char keypressed = myKeypad.getKey();
  if(keypressed)
  {
    {
      lcd.setCursor(10+i,1);
      int vv= setTime(v,keypressed);
      Month[i]=vv;
      if ((Month[0]<=1) && (Month[1]<=2))
      {
        i++;
      }
      else
      {
        lcd.setCursor(10+i,1);
        lcd.print(" ");
        goto back111;
      }
    }
  }
 }while( i < 2);
}
 //*****************************************************
void setYear()
{
  int i=0;
  do
  {
    char keypressed = myKeypad.getKey();
    if(keypressed)
    {
      lcd.setCursor(13+i,1);
      setTime(0,keypressed);
      i++;
    }
  }while( i < 2);
}
 //*****************************************************
void alarmvalue()
{
setagain:
int set;
int i=0;
do
{
  char keypressed = myKeypad.getKey();
  if(keypressed)
  {
    lcd.setCursor(3+i,1);
    Alarm[i]=setTime(v,keypressed);
    i++;
  }
}while( i < 4);
lcd.setCursor(13,1);
lcd.print("OK?");
do
{ 
  char keypressed = myKeypad.getKey();
  if(keypressed)
  {
    set=setTime(v,keypressed);
    if(set==1)
    {
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("Alarm Set");
      delay(1000);
      j++;
    }
    else
    {
      lcd.clear();
      lcd.setCursor(3,0);
      lcd.print("HH:MM");
      goto setagain;
    }
  }
}while (j<1);
}
//************************************************************
void setAlarm(){
  int ii=0;
 lcd.setCursor(0,0);
lcd.print("Do You Want To");
lcd.setCursor(0,1);
lcd.print("Set Alarm y/n?");
do{
  char keypressed = myKeypad.getKey();
if(keypressed)
{
int vv =setTime(v,keypressed);
if (vv==1)
{
  lcd.clear();
lcd.setCursor(3,0);
lcd.print("HH:MM");
alarmvalue();
selc++;
}
else{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("No Alarm Set");
  delay(1000);
  selc=4;}
}

  }while( selc < 1);
}
void Beep()
{ 
  digitalWrite(10,HIGH);
}
//**************************************************************  
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
pinMode(10,OUTPUT);
setAlarm();
lcd.clear();
lcd.setCursor(7,0);
lcd.print("Set Time");
lcd.setCursor(7,1);
lcd.print("And Date ");
delay(2000);
lcd.clear();
display();
setHour(hour);
setMin(minn);
setSec(sec);
setDay(Day);
setMonth(Month);
setYear();
}

//**************************************************************
void loop()
{
  display();
  do
  {
    do
    {
      if ((Alarm[0]==hour[0]) && (Alarm[1]==hour[1]) && (Alarm[2]==minn[0]) && (Alarm[3]==minn[1]))
      {
        Beep();
      }
      lcd.setCursor(14,0);
      lcd.print(sec[1]);
      delay(100);
      digitalWrite(10,LOW);
      sec[1]++;
    }while (sec[1]<10);
    sec[1]=0;
    lcd.setCursor(13,0);
    if(j<1)
    {
      Serial.print("Hello");
      if (sec[0]<5)
      {
        Serial.print("sec[0] > 5");
        sec[0]++;
        j++;
        lcd.print(sec[0]);
      }
      else
      {
        sec[0]=0;
        j++;
        lcd.print(sec[0]);
        Serial.print("sec[0] < 5");
        {
          if((minn[1] < 9))
          {
            minn[1]++;
          }
          else if ((minn[1] == 9) && (minn[0] == 5)){minn[0]=0; minn[1]=0;}
          else {minn[1]=0;minn[0]++;}
         }
         {
          if(hour[1] < 3){hour[1]++;}
          else if ((hour[1] == 3) && (hour[0] == 2)){hour[0]=0; hour[1]=0;}
          else {hour[1]=0;hour[0]++;}}
          Serial.print("minn[0] == 5");
          Serial.print(minn[0]);
          lcd.setCursor(10,0);
          lcd.print(minn[0],DEC);
          lcd.setCursor(11,0);
          lcd.print(minn[1],DEC);
          lcd.print(":");
          lcd.setCursor(7,0);
          lcd.print(hour[0],DEC);
          lcd.setCursor(8,0);
          lcd.print(hour[1],DEC);
          lcd.print(":");
          j++;
        }
      }
      else 
      {
        Serial.print(minn[0]);
        sec[0]++;
        if (sec[0]>=6)
        {
          sec[0]=0;
          lcd.setCursor(13,0);
          lcd.print(sec[0],DEC);
          lcd.print(":");
          if ((minn[1] < 9))
          {
            minn[1]++;
            lcd.setCursor(11,0);
            lcd.print(minn[1],DEC);
            lcd.print(":");
           }
           else
           {
            minn[1]=0;
            lcd.setCursor(11,0);
            lcd.print(minn[1],DEC);
            lcd.print(":");
            if ( (minn[0]<5) )
            {
              minn[0]++;
              lcd.setCursor(10,0);
              lcd.print(minn[0],DEC);
            }
            else
            {
              minn[0]=0;
              lcd.setCursor(10,0);
              lcd.print(minn[0]);
              if((hour[0]<=2) && (hour[1]<3))
              {
                hour[1]++;
                lcd.setCursor(8,0);
                lcd.print(hour[1],DEC);
                lcd.print(":");
              }
              else if((hour[0]<=1) && (hour[1]<9))
              {
                hour[1]++;
                lcd.setCursor(8,0);
                lcd.print(hour[1],DEC);
                lcd.print(":");
              }
              else 
              {
                hour[1]=0;
                lcd.setCursor(8,0);
                lcd.print(hour[1],DEC);
                lcd.print(":");
                if (hour[0] <2)
                {
                  hour[0]++;
                  lcd.setCursor(7,0);
                  lcd.print(hour[0],DEC);
                }
                else
                {
                  hour[0]=0;
                  lcd.setCursor(7,0);
                  lcd.print(hour[0]);
                }
              }
            }
          }
        }
      }
      lcd.print(sec[0]);
   }while(sec[0]<6);
   sec[0]=0;
}
