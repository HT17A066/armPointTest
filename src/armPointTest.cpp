// -*- C++ -*-
/*!
 * @file  armPointTest.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "armPointTest.h"

using namespace std;
// Module specification
// <rtc-template block="module_spec">
static const char* armpointtest_spec[] =
  {
    "implementation_id", "armPointTest",
    "type_name",         "armPointTest",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "MasutaniLab",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
armPointTest::armPointTest(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_pointOut("point", m_point)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
armPointTest::~armPointTest()
{
}



RTC::ReturnCode_t armPointTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  
  // Set OutPort buffer
  addOutPort("point", m_pointOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t armPointTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t armPointTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t armPointTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t armPointTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t armPointTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t armPointTest::onExecute(RTC::UniqueId ec_id)
{
  double pointx = 0;
  double pointy = 0;
  double pointz = 0;
  printf("x座標(m)↑=");
  cin >> pointx;
  printf("y座標(m)←=");
  cin >> pointy;
  printf("z座標(m)上=");
  cin >> pointz;

  m_point.data.x = pointx;
  m_point.data.y = pointy;
  m_point.data.z = pointz;
  m_pointOut.write();
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t armPointTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t armPointTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t armPointTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t armPointTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t armPointTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void armPointTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(armpointtest_spec);
    manager->registerFactory(profile,
                             RTC::Create<armPointTest>,
                             RTC::Delete<armPointTest>);
  }
  
};


