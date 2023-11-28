const int led_green = 2;
const int led_yellow = 7;
const int led_red = 8;

const int btn = 4;

int flow = 0;
int flow_two = 0;
int startTimer;
int currentTimer;

void alternateFlow();

void setup()
{
    // led
    pinMode(led_green, OUTPUT);
    pinMode(led_yellow, OUTPUT);
    pinMode(led_red, OUTPUT);

    // btn
    pinMode(btn, INPUT_PULLUP);

    // timer
    startTimer = millis();
}

void loop()
{
    currentTimer = millis();
    byte btn_state = digitalRead(btn);
  
  	if (btn_state == LOW) {
      	if (flow == 0) {
          	delay(10000);
      	}
      	else if (flow == 1) {
        	digitalWrite(led_yellow, LOW);
          	digitalWrite(led_red, HIGH);
          	flow = 0;
          	delay(10000);
        }
      	else if (flow == 2) {
      		digitalWrite(led_green, LOW);
          	digitalWrite(led_red, HIGH);
          	flow = 0;
          	delay(10000);
        }
    }
  
    alternateFlow();
}

void alternateFlow()
{
    if (flow == 0)
    {
        digitalWrite(led_red, HIGH);
        if ((currentTimer - startTimer) >= 5000)
        {
            digitalWrite(led_red, LOW);
            flow = 1;
          	startTimer = currentTimer;
        }
    }
    else if (flow == 1)
    {
      	digitalWrite(led_yellow, HIGH);
        if ((currentTimer - startTimer) >= 5000)
        {
           if (flow_two == 1) {
             	flow = 0;
             	digitalWrite(led_yellow, LOW);
             	startTimer = currentTimer;
             	flow_two = 0;
           } else {
            	digitalWrite(led_yellow, LOW);
          		flow = 2;
          		startTimer = currentTimer;
           }
        }
    }
    else if (flow == 2)
    {
      	digitalWrite(led_green, HIGH);
        if ((currentTimer - startTimer) >= 5000)
        {
            digitalWrite(led_green, LOW);
          	flow = 1;
          	flow_two = 1;
          	startTimer = currentTimer;
        }
    }
}