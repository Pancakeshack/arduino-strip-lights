#include <Adafruit_NeoPixel.h>

// Define the pin and number of LEDs
#define LED_PIN 6
#define LED_COUNT 30
#define MAX_BRIGHTNESS 20

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if (WheelPos < 85)
    {
        return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    else if (WheelPos < 170)
    {
        WheelPos -= 85;
        return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    else
    {
        WheelPos -= 170;
        return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
}

void setup()
{
    strip.begin();
    strip.show(); // Turn off all LEDs
    strip.setBrightness(MAX_BRIGHTNESS);
}

void loop()
{
    for (int j = 0; j < 256; j++)
    {
        for (int i = 0; i < strip.numPixels(); i++)
        {
            strip.setPixelColor(i, Wheel((i + j) & 255));
        }
        strip.show();
        delay(50);
    }
}