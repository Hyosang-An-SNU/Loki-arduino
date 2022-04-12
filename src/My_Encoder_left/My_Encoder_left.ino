#define USE_USBCON // 아두이노 UNO 또는 MEGA 이외의 레오나르도,mk1000 계열의 보드를 사용하는 경우
#include <ros.h>
#include <ros_essentials_cpp/encoder.h>

#define encoderPin_A 2 // A
#define encoderPin_B 3 // B
int32_t angle = 0;

volatile int lastEncoded = 0;
volatile long encoderValue = 0;

int32_t Round = 0;
int MSB;
int LSB;

ros::NodeHandle nh;
ros_essentials_cpp::encoder msg;
ros::Publisher left_angle("left_angle", &msg);

void setup()
{
  nh.initNode();
  nh.advertise(left_angle);

  // Serial.begin(9600);

  pinMode(encoderPin_A, INPUT);
  pinMode(encoderPin_B, INPUT);

  // call updateEncoder() when any high/low changed seen
  // on interrupt 0 (pin 2), or interrupt 1 (pin 3)
  attachInterrupt(digitalPinToInterrupt(encoderPin_A), updateEncoder, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderPin_B), updateEncoder, CHANGE);
}

void loop()
{
  // Do stuff here
  angle = encoderValue * 360 / 1024; //#(1024는 로터리엔코더분해능256*4; 분해능512이면 2048로 수정; 분해능400이면 1600으로 수정)
  msg.Degree = angle;
  msg.Round = Round;
  left_angle.publish(&msg);
  nh.spinOnce();
  // Serial.print(angle);
  // Serial.print("\t");
  // Serial.println(Round);
  delay(50); // just here to slow down the output, and show it will work  even during a delay
}

void updateEncoder()
{
  MSB = digitalRead(encoderPin_A); // MSB = most significant bit
  LSB = digitalRead(encoderPin_B); // LSB = least significant bit

  int encoded = (MSB << 1) | LSB;         // converting the 2 pin value to single number
  int sum = (lastEncoded << 2) | encoded; // adding it to the previous encoded value

  if (sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)
    encoderValue++;
  else
    encoderValue--;

  lastEncoded = encoded; // store this value for next time

  if (encoderValue >= 1024)
  {
    encoderValue = encoderValue - 1024;
    Round++;
  }

  if (encoderValue < 0)
  {
    encoderValue = encoderValue + 1024;
    Round--;
  }
}

// void updateEncoder_A()
// {
//     if (digitalRead(encoderPin_A) == HIGH)
//     {
//         if (digitalRead(encoderPin_B) == HIGH)
//         {
//             encoderPos++; // 정회전
//             Serial.print("정회전 ");
//         }

//         else
//         {
//             encoderPos--;
//             Serial.print("역회전 ");
//         }
//     }

//     else
//     {
//         if (digitalRead(encoderPin_B) == LOW)
//         {
//             encoderPos++; // 정회전
//             Serial.print("정회전 ");
//         }

//         else
//         {
//             encoderPos--;
//             Serial.print("역회전 ");
//         }
//     }

//     Serial.println(encoderPos);
// }

// void updateEncoder_B()
// {
//     if (digitalRead(encoderPin_B) == HIGH)
//     {
//         if (digitalRead(encoderPin_A) == LOW)
//         {
//             encoderPos++; // 정회전
//             Serial.print("정회전 ");
//         }

//         else
//         {
//             encoderPos--;
//             Serial.print("역회전 ");
//         }
//     }

//     else
//     {
//         if (digitalRead(encoderPin_A) == HIGH)
//         {
//             encoderPos++; // 정회전
//             Serial.print("정회전 ");
//         }

//         else
//         {
//             encoderPos--;
//             Serial.print("역회전 ");
//         }
//     }

//     Serial.println(encoderPos);
// }
