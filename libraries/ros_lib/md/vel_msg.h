#ifndef _ROS_md_vel_msg_h
#define _ROS_md_vel_msg_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace md
{

  class vel_msg : public ros::Msg
  {
    public:
      typedef int32_t _nLinear_type;
      _nLinear_type nLinear;
      typedef int32_t _nAngular_type;
      _nAngular_type nAngular;
      typedef int8_t _byResetOdometry_type;
      _byResetOdometry_type byResetOdometry;
      typedef int8_t _byResetAngle_type;
      _byResetAngle_type byResetAngle;
      typedef int8_t _byResetAlarm_type;
      _byResetAlarm_type byResetAlarm;
      typedef int32_t _nPosition_type;
      _nPosition_type nPosition;

    vel_msg():
      nLinear(0),
      nAngular(0),
      byResetOdometry(0),
      byResetAngle(0),
      byResetAlarm(0),
      nPosition(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nLinear;
      u_nLinear.real = this->nLinear;
      *(outbuffer + offset + 0) = (u_nLinear.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nLinear.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nLinear.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nLinear.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nLinear);
      union {
        int32_t real;
        uint32_t base;
      } u_nAngular;
      u_nAngular.real = this->nAngular;
      *(outbuffer + offset + 0) = (u_nAngular.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nAngular.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nAngular.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nAngular.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nAngular);
      union {
        int8_t real;
        uint8_t base;
      } u_byResetOdometry;
      u_byResetOdometry.real = this->byResetOdometry;
      *(outbuffer + offset + 0) = (u_byResetOdometry.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->byResetOdometry);
      union {
        int8_t real;
        uint8_t base;
      } u_byResetAngle;
      u_byResetAngle.real = this->byResetAngle;
      *(outbuffer + offset + 0) = (u_byResetAngle.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->byResetAngle);
      union {
        int8_t real;
        uint8_t base;
      } u_byResetAlarm;
      u_byResetAlarm.real = this->byResetAlarm;
      *(outbuffer + offset + 0) = (u_byResetAlarm.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->byResetAlarm);
      union {
        int32_t real;
        uint32_t base;
      } u_nPosition;
      u_nPosition.real = this->nPosition;
      *(outbuffer + offset + 0) = (u_nPosition.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_nPosition.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_nPosition.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_nPosition.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->nPosition);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        int32_t real;
        uint32_t base;
      } u_nLinear;
      u_nLinear.base = 0;
      u_nLinear.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nLinear.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nLinear.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nLinear.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nLinear = u_nLinear.real;
      offset += sizeof(this->nLinear);
      union {
        int32_t real;
        uint32_t base;
      } u_nAngular;
      u_nAngular.base = 0;
      u_nAngular.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nAngular.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nAngular.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nAngular.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nAngular = u_nAngular.real;
      offset += sizeof(this->nAngular);
      union {
        int8_t real;
        uint8_t base;
      } u_byResetOdometry;
      u_byResetOdometry.base = 0;
      u_byResetOdometry.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->byResetOdometry = u_byResetOdometry.real;
      offset += sizeof(this->byResetOdometry);
      union {
        int8_t real;
        uint8_t base;
      } u_byResetAngle;
      u_byResetAngle.base = 0;
      u_byResetAngle.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->byResetAngle = u_byResetAngle.real;
      offset += sizeof(this->byResetAngle);
      union {
        int8_t real;
        uint8_t base;
      } u_byResetAlarm;
      u_byResetAlarm.base = 0;
      u_byResetAlarm.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->byResetAlarm = u_byResetAlarm.real;
      offset += sizeof(this->byResetAlarm);
      union {
        int32_t real;
        uint32_t base;
      } u_nPosition;
      u_nPosition.base = 0;
      u_nPosition.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_nPosition.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_nPosition.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_nPosition.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->nPosition = u_nPosition.real;
      offset += sizeof(this->nPosition);
     return offset;
    }

    const char * getType(){ return "md/vel_msg"; };
    const char * getMD5(){ return "55a52a955bd990cd7c623bf91bae1a91"; };

  };

}
#endif
