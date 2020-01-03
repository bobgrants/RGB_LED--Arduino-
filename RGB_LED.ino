//www.elegoo.com
//2016.12.8


// define variables
int redValue;
int greenValue;
int blueValue;
int maxValue;
String UpDown;

void setup()
{
  
// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);

pinMode(LED_BUILTIN, OUTPUT);  //Used to check Up or Down


redValue = 0; // choose a value between 1 and 255 to change the color.
greenValue = 0;
blueValue = 0;
maxValue = 10;
UpDown = "Up";

analogWrite(RED, redValue);
analogWrite(GREEN, greenValue);
analogWrite(BLUE, blueValue);
digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
}



// main loop
void loop()
{
  loopThroughColors();
  checkDirection();
}

void loopThroughColors()
{

if (UpDown == "Up")
{
  if(redValue < 10)
  {
    redValue++;
    analogWrite(RED, redValue);
    delay(500);
  }
  else if (greenValue < 10)
  {
    greenValue++;
    analogWrite(GREEN, greenValue);
    delay(500);
  }
  else if (blueValue < 10)
  {
    blueValue++;
    analogWrite(BLUE, blueValue);
    delay(500);
  }
}
else if (UpDown == "Down")
{
  if(redValue > 0)
  {
    redValue--;
    analogWrite(RED, redValue);
    delay(500);
  }
  else if (greenValue > 0)
  {
    greenValue--;
    analogWrite(GREEN, greenValue);
    delay(500);
  }
  else if (blueValue > 0)
  {
    blueValue--;
    analogWrite(BLUE, blueValue);
    delay(500);
  }
}
}

void checkDirection()
{
  if (redValue == 10 && greenValue == 10 && blueValue == 10)
{
    UpDown = "Down";  
}
  else if (redValue == 0 && greenValue == 0 && blueValue == 0)
{
    UpDown = "Up";  
}

if (UpDown == "Up"){digitalWrite(LED_BUILTIN, HIGH);}
else if (UpDown == "Down"){digitalWrite(LED_BUILTIN, LOW);}
}
