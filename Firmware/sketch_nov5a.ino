#include <Wire.h>
#include <EEPROM.h>
#include <Adafruit_MCP4725.h>
#include <Adafruit_INA260.h>

Adafruit_MCP4725 dac;
Adafruit_INA260 ina;

#define ENC_V_A 2
#define ENC_V_B 3

#define ENC_I_A 4
#define ENC_I_B 5

#define EN_PIN 8

float voltageSet = 5.00f;
float currentSet = 1.00f;

float voltageOut = 0.0f;
float currentOut = 0.0f;
float powerOut = 0.0f;

const float MAX_VOLTAGE = 30.0f;
const float MAX_CURRENT = 5.0f;

volatile int16_t vEncoder = 0;
volatile int16_t iEncoder = 0;

bool outputEnabled = true;

void voltageISR()
{
    if (digitalRead(ENC_V_A) == digitalRead(ENC_V_B))
        vEncoder++;
    else
        vEncoder--;
}

uint8_t lastIA = 0;

void readCurrentEncoder()
{
    uint8_t a = digitalRead(ENC_I_A);

    if (a != lastIA)
    {
        if (digitalRead(ENC_I_B) != a)
            iEncoder++;
        else
            iEncoder--;

        lastIA = a;
    }
}

void setOutputVoltage(float volts)
{
    volts = constrain(volts, 0.0f, MAX_VOLTAGE);

    uint16_t dacCode =
        (uint16_t)((volts / MAX_VOLTAGE) * 4095.0f);

    dac.setVoltage(dacCode, false);
}

void updateMeasurements()
{
    voltageOut = ina.readBusVoltage() / 1000.0f;
    currentOut = ina.readCurrent() / 1000.0f;
    powerOut   = ina.readPower() / 1000.0f;
}

void applyProtection()
{
    if (currentOut > currentSet)
    {
        digitalWrite(EN_PIN, LOW);
        outputEnabled = false;
    }
}

void updateSetpoints()
{
    static int16_t prevV = 0;
    static int16_t prevI = 0;

    if (vEncoder != prevV)
    {
        voltageSet += (vEncoder - prevV) * 0.1f;
        voltageSet = constrain(voltageSet, 0.0f, MAX_VOLTAGE);
        prevV = vEncoder;

        setOutputVoltage(voltageSet);
    }

    if (iEncoder != prevI)
    {
        currentSet += (iEncoder - prevI) * 0.05f;
        currentSet = constrain(currentSet, 0.1f, MAX_CURRENT);
        prevI = iEncoder;
    }
}

void saveSettings()
{
    EEPROM.put(0, voltageSet);
    EEPROM.put(sizeof(float), currentSet);
}

void loadSettings()
{
    EEPROM.get(0, voltageSet);
    EEPROM.get(sizeof(float), currentSet);

    if (voltageSet < 0 || voltageSet > 30)
        voltageSet = 5.0;

    if (currentSet < 0.1 || currentSet > 5)
        currentSet = 1.0;
}

void setup()
{
    Wire.begin();

    pinMode(ENC_V_A, INPUT_PULLUP);
    pinMode(ENC_V_B, INPUT_PULLUP);

    pinMode(ENC_I_A, INPUT_PULLUP);
    pinMode(ENC_I_B, INPUT_PULLUP);

    pinMode(EN_PIN, OUTPUT);

    digitalWrite(EN_PIN, HIGH);

    attachInterrupt(
        digitalPinToInterrupt(ENC_V_A),
        voltageISR,
        CHANGE
    );

    dac.begin(0x60);
    ina.begin();

    loadSettings();

    setOutputVoltage(voltageSet);

    Serial.begin(115200);
}

void loop()
{
    readCurrentEncoder();

    updateSetpoints();

    static uint32_t lastSample = 0;

    if (millis() - lastSample > 100)
    {
        updateMeasurements();

        if (outputEnabled)
            applyProtection();

        Serial.print("SV:");
        Serial.print(voltageSet, 2);

        Serial.print(",SI:");
        Serial.print(currentSet, 2);

        Serial.print(",V:");
        Serial.print(voltageOut, 2);

        Serial.print(",I:");
        Serial.print(currentOut, 3);

        Serial.print(",P:");
        Serial.println(powerOut, 2);

        lastSample = millis();
    }

    static uint32_t lastSave = 0;

    if (millis() - lastSave > 5000)
    {
        saveSettings();
        lastSave = millis();
    }
}