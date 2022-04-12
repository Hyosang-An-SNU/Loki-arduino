#ifndef _ROS_ros_essentials_cpp_encoder_h
#define _ROS_ros_essentials_cpp_encoder_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class encoder : public ros::Msg
  {
    public:
      typedef int32_t _Degree_type;
      _Degree_type Degree;
      typedef int32_t _Round_type;
      _Round_type Round;

    encoder():
      Degree(0),
      Round(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_Degree;
      u_Degree.real = this->Degree;
      *(outbuffer + offset + 0) = (u_Degree.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Degree.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Degree.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Degree.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Degree);
      union {
        int32_t real;
        uint32_t base;
      } u_Round;
      u_Round.real = this->Round;
      *(outbuffer + offset + 0) = (u_Round.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_Round.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_Round.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_Round.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->Round);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_Degree;
      u_Degree.base = 0;
      u_Degree.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Degree.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Degree.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Degree.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Degree = u_Degree.real;
      offset += sizeof(this->Degree);
      union {
        int32_t real;
        uint32_t base;
      } u_Round;
      u_Round.base = 0;
      u_Round.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_Round.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_Round.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_Round.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->Round = u_Round.real;
      offset += sizeof(this->Round);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/encoder"; };
    const char * getMD5(){ return "59635337fa98bbe5f357d1940df2a47a"; };

  };

}
#endif
