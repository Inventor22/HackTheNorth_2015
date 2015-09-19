uint32_t tNow = 0;
uint32_t tPrev = 0;

void setup()
{
    Serial.begin(115200);
    Serial1.begin(9600);

    pinMode(13, OUTPUT);

    tPrev = millis();
}

void loop()
{


    tNow = millis();
    if (tNow - tPrev > 100) {
        Serial.print("1: ");
        Serial.print(analogRead(0));
        Serial.print("\t2: ");
        Serial.print(analogRead(2));
        Serial.print("\t3: ");
        Serial.println(analogRead(4));
    }
}
