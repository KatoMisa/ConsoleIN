// -*- C++ -*-
// <rtc-template block="description">
/*!
 * @file  ConsoleIN.cpp
 * @brief ModuleDescription
 *
 */
// </rtc-template>

#include "ConsoleIN.h"

// Module specification
// <rtc-template block="module_spec">
#if RTM_MAJOR_VERSION >= 2
static const char* const consolein_spec[] =
#else
static const char* consolein_spec[] =
#endif
  {
    "implementation_id", "ConsoleIN",
    "type_name",         "ConsoleIN",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Test",
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
ConsoleIN::ConsoleIN(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_str_inIn("str_in", m_str_in),
    m_num_inIn("num_in", m_num_in),
    m_str_outOut("str_out", m_str_out),
    m_num_outOut("num_out", m_num_out)
    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ConsoleIN::~ConsoleIN()
{
}



RTC::ReturnCode_t ConsoleIN::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("str_in", m_str_inIn);
  addInPort("num_in", m_num_inIn);
  
  // Set OutPort buffer
  addOutPort("str_out", m_str_outOut);
  addOutPort("num_out", m_num_outOut);

  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>

  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ConsoleIN::onFinalize()
{
  return RTC::RTC_OK;
}
*/


//RTC::ReturnCode_t ConsoleIN::onStartup(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleIN::onShutdown(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


RTC::ReturnCode_t ConsoleIN::onActivated(RTC::UniqueId /*ec_id*/)
{
  std::cout << "Activate "<< std::endl;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleIN::onDeactivated(RTC::UniqueId /*ec_id*/)
{
  std::cout << "Deactivate "<< std::endl;
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ConsoleIN::onExecute(RTC::UniqueId /*ec_id*/)
{
  int num;
  std::cout << "Please input number: ";
  std::cin >> num;
  m_num_out.data = num;
  std::cout << "Sending to subscriber: " << m_num_out.data << std::endl;
  m_num_outOut.write(); 

  std::string str;
  std::cout << "Please input string: ";
  std::cin >> str;
  m_str_out.data = CORBA::string_dup(str.c_str());
  std::cout << "Sending to subscriber: " << m_str_out.data << std::endl;
  m_str_outOut.write(); 

  return RTC::RTC_OK;
}


//RTC::ReturnCode_t ConsoleIN::onAborting(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleIN::onError(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleIN::onReset(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleIN::onStateUpdate(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}


//RTC::ReturnCode_t ConsoleIN::onRateChanged(RTC::UniqueId /*ec_id*/)
//{
//  return RTC::RTC_OK;
//}



extern "C"
{
 
  void ConsoleINInit(RTC::Manager* manager)
  {
    coil::Properties profile(consolein_spec);
    manager->registerFactory(profile,
                             RTC::Create<ConsoleIN>,
                             RTC::Delete<ConsoleIN>);
  }
  
}
