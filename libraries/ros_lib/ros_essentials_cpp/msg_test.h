#ifndef _ROS_ros_essentials_cpp_msg_test_h
#define _ROS_ros_essentials_cpp_msg_test_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

  class msg_test : public ros::Msg
  {
    public:
      typedef int32_t _id_num_type;
      _id_num_type id_num;
      typedef const char* _nickname_type;
      _nickname_type nickname;
      typedef float _temp_type;
      _temp_type temp;
      typedef float _humi_type;
      _humi_type humi;

    msg_test():
      id_num(0),
      nickname(""),
      temp(0),
      humi(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id_num;
      u_id_num.real = this->id_num;
      *(outbuffer + offset + 0) = (u_id_num.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_id_num.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_id_num.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_id_num.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->id_num);
      uint32_t length_nickname = strlen(this->nickname);
      varToArr(outbuffer + offset, length_nickname);
      offset += 4;
      memcpy(outbuffer + offset, this->nickname, length_nickname);
      offset += length_nickname;
      union {
        float real;
        uint32_t base;
      } u_temp;
      u_temp.real = this->temp;
      *(outbuffer + offset + 0) = (u_temp.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_temp.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_temp.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_temp.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->temp);
      union {
        float real;
        uint32_t base;
      } u_humi;
      u_humi.real = this->humi;
      *(outbuffer + offset + 0) = (u_humi.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_humi.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_humi.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_humi.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->humi);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_id_num;
      u_id_num.base = 0;
      u_id_num.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_id_num.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_id_num.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_id_num.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->id_num = u_id_num.real;
      offset += sizeof(this->id_num);
      uint32_t length_nickname;
      arrToVar(length_nickname, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_nickname; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_nickname-1]=0;
      this->nickname = (char *)(inbuffer + offset-1);
      offset += length_nickname;
      union {
        float real;
        uint32_t base;
      } u_temp;
      u_temp.base = 0;
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_temp.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->temp = u_temp.real;
      offset += sizeof(this->temp);
      union {
        float real;
        uint32_t base;
      } u_humi;
      u_humi.base = 0;
      u_humi.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_humi.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_humi.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_humi.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->humi = u_humi.real;
      offset += sizeof(this->humi);
     return offset;
    }

    const char * getType(){ return "ros_essentials_cpp/msg_test"; };
    const char * getMD5(){ return "fa11f8297aa450a02523c897d7174b64"; };

  };

}
#endif
