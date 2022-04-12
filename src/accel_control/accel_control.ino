#include <ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Int16.h>
#include "DFRobot_MCP4725.h"

#define  REF_VOLTAGE    4760

#define relay1 4
#define relay2 5

DFRobot_MCP4725 DAC;
uint16_t OUTPUT_VOLTAGE = 0;        // Input DAC output voltage (0~REF_VOLTAGE,unit: mV)

ros::NodeHandle nh;

int accel_val = 0;
bool fwd = true;

void accel_callback(const std_msgs::Int16 &msg)
{
    accel_val = msg.data;
    // accel_val = constrain(accel_val, 0, 255 / 2); // 테스트용으로 풀악셀 방지

    OUTPUT_VOLTAGE = map(accel_val,0,255,0,4760);
}

void fwdrev_callback(const std_msgs::Empty &msg)
{
    fwd = !fwd;
    delay(200);
}

ros::Subscriber<std_msgs::Int16> accel_sub("accel_pid_topic", accel_callback);
ros::Subscriber<std_msgs::Empty> fwdrev_sub("fwdrev_topic", fwdrev_callback);

void setup()
{
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);

    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);

    nh.initNode();
    nh.subscribe(accel_sub);
    nh.subscribe(fwdrev_sub);

    DAC.init(0x60, REF_VOLTAGE);
    DAC.outputVoltage(0);
}

void loop()
{
    nh.spinOnce();
    DAC.outputVoltage(OUTPUT_VOLTAGE);

    if (fwd == true)
    {
        digitalWrite(relay1, HIGH);
        delay(50);
        digitalWrite(relay2, HIGH);
    }

    else
    {
        digitalWrite(relay2, LOW);
        delay(50);
        digitalWrite(relay1, LOW);
    }

    delay(100);


}
