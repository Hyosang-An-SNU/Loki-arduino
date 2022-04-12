#ifndef _ROS_SERVICE_srv_test_h
#define _ROS_SERVICE_srv_test_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace ros_essentials_cpp
{

static const char SRV_TEST[] = "ros_essentials_cpp/srv_test";

  class srv_testRequest : public ros::Msg
  {
    public:
      typedef const char* _s1_type;
      _s1_type s1;
      typedef const char* _s2_type;
      _s2_type s2;

    srv_testRequest():
      s1(""),
      s2("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_s1 = strlen(this->s1);
      varToArr(outbuffer + offset, length_s1);
      offset += 4;
      memcpy(outbuffer + offset, this->s1, length_s1);
      offset += length_s1;
      uint32_t length_s2 = strlen(this->s2);
      varToArr(outbuffer + offset, length_s2);
      offset += 4;
      memcpy(outbuffer + offset, this->s2, length_s2);
      offset += length_s2;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_s1;
      arrToVar(length_s1, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_s1; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_s1-1]=0;
      this->s1 = (char *)(inbuffer + offset-1);
      offset += length_s1;
      uint32_t length_s2;
      arrToVar(length_s2, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_s2; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_s2-1]=0;
      this->s2 = (char *)(inbuffer + offset-1);
      offset += length_s2;
     return offset;
    }

    const char * getType(){ return SRV_TEST; };
    const char * getMD5(){ return "365c3f866389e83181467f2ccc1cec54"; };

  };

  class srv_testResponse : public ros::Msg
  {
    public:
      typedef const char* _S_type;
      _S_type S;

    srv_testResponse():
      S("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_S = strlen(this->S);
      varToArr(outbuffer + offset, length_S);
      offset += 4;
      memcpy(outbuffer + offset, this->S, length_S);
      offset += length_S;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_S;
      arrToVar(length_S, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_S; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_S-1]=0;
      this->S = (char *)(inbuffer + offset-1);
      offset += length_S;
     return offset;
    }

    const char * getType(){ return SRV_TEST; };
    const char * getMD5(){ return "9a02b60232a02550a09ec79f096c5dc9"; };

  };

  class srv_test {
    public:
    typedef srv_testRequest Request;
    typedef srv_testResponse Response;
  };

}
#endif
