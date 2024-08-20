#include "rr_arduino_parser.hpp"

char buf[256];
int i = 0;

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    if(Serial.available())
    {
        buf[i] = Serial.read();
        if (buf[i] == 'e') 
        {
            i = 0;

            String get_str(buf);

            rustic_rover::RusticRover get_data = rustic_rover::from_str(get_str);

            // １つ目の数字
            Serial.println(get_data.value_1);
            // ２つ目の数字
            Serial.println(get_data.value_2);
            // ３つ目の数字
            Serial.println(get_data.value_3);
            // ４つ目の数字
            Serial.println(get_data.value_4);
            // ５つ目の数字
            Serial.println(get_data.value_5);
        }
        else
        {
            i++;
        }
    }
}