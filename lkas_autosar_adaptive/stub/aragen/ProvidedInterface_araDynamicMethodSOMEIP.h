#ifndef ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_METHOD_WRAPPER_H
#define ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_METHOD_WRAPPER_H

namespace skeleton_io
{
  class ProvidedInterfaceSkeleton_mthd_dispatcher_t {
   public:
    template <typename T> static void Dispatch(T* /*skelPtr*/
      , std::string& aMethodName, std::string& /*sPayload*/
      , std::string&                   /*sRetVal*/
      , size_t&                        /*nRetValSize*/
      )
    {
      if (aMethodName == std::string("")) {
      } else {
      }                                /* if */
    }

    static std::map<std::string, std::tuple<bool, size_t>> GetMethodConfig()
    {
      std::map<std::string, std::tuple<bool, size_t>> tConfig;
      return tConfig;
    }
  }
    ;
}                                      /* namespace skeleton_io */

#endif                                 //ProvidedInterface_ARA_COM_SOMEIP_DYNAMIC_METHOD_WRAPPER_H
