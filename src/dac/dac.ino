#include "DFRobot_MCP4725.h"
#define  REF_VOLTAGE    5000

DFRobot_MCP4725 DAC;

uint16_t OUTPUT_VOLTAGE = 0;        // Input DAC output voltage (0~REF_VOLTAGE,unit: mV)

void setup(void) {

  Serial.begin(115200);
  /* MCP4725A0_address is 0x60 or 0x61
   * MCP4725A0_IIC_Address0 -->0x60
   * MCP4725A0_IIC_Address1 -->0x61
   */
  DAC.init(0x60, REF_VOLTAGE);
  DAC.outputVoltage(OUTPUT_VOLTAGE);

}

void loop(void) {

  while(Serial.available() == 0) {}
  OUTPUT_VOLTAGE = Serial.parseInt();
  OUTPUT_VOLTAGE = map(OUTPUT_VOLTAGE,0,255,0,5000);
  
  Serial.print("DFRobot_MCP4725 output: ");
  Serial.print(OUTPUT_VOLTAGE);
  Serial.println(" mV");

  DAC.outputVoltage(OUTPUT_VOLTAGE);
  int dummy = Serial.parseInt();

  delay(500);
}
