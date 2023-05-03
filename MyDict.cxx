// Do NOT change. Changes will be lost next time file is generated

#define R__DICTIONARY_FILENAME MyDict
#define R__NO_DEPRECATION

/*******************************************************************/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define G__DICTIONARY
#include "RConfig.h"
#include "TClass.h"
#include "TDictAttributeMap.h"
#include "TInterpreter.h"
#include "TROOT.h"
#include "TBuffer.h"
#include "TMemberInspector.h"
#include "TInterpreter.h"
#include "TVirtualMutex.h"
#include "TError.h"

#ifndef G__ROOT
#define G__ROOT
#endif

#include "RtypesImp.h"
#include "TIsAProxy.h"
#include "TFileMergeInfo.h"
#include <algorithm>
#include "TCollectionProxyInfo.h"
/*******************************************************************/

#include "TDataMember.h"

// The generated code does not explicitly qualifies STL entities
namespace std {} using namespace std;

// Header files passed as explicit arguments
#include "Vector3D.hh"

// Header files passed via #pragma extra_include

namespace ROOT {
   static TClass *Vector3D_Dictionary();
   static void Vector3D_TClassManip(TClass*);
   static void *new_Vector3D(void *p = 0);
   static void *newArray_Vector3D(Long_t size, void *p);
   static void delete_Vector3D(void *p);
   static void deleteArray_Vector3D(void *p);
   static void destruct_Vector3D(void *p);

   // Function generating the singleton type initializer
   static TGenericClassInfo *GenerateInitInstanceLocal(const ::Vector3D*)
   {
      ::Vector3D *ptr = 0;
      static ::TVirtualIsAProxy* isa_proxy = new ::TIsAProxy(typeid(::Vector3D));
      static ::ROOT::TGenericClassInfo 
         instance("Vector3D", "Vector3D.hh", 7,
                  typeid(::Vector3D), ::ROOT::Internal::DefineBehavior(ptr, ptr),
                  &Vector3D_Dictionary, isa_proxy, 0,
                  sizeof(::Vector3D) );
      instance.SetNew(&new_Vector3D);
      instance.SetNewArray(&newArray_Vector3D);
      instance.SetDelete(&delete_Vector3D);
      instance.SetDeleteArray(&deleteArray_Vector3D);
      instance.SetDestructor(&destruct_Vector3D);
      return &instance;
   }
   TGenericClassInfo *GenerateInitInstance(const ::Vector3D*)
   {
      return GenerateInitInstanceLocal((::Vector3D*)0);
   }
   // Static variable to force the class initialization
   static ::ROOT::TGenericClassInfo *_R__UNIQUE_DICT_(Init) = GenerateInitInstanceLocal((const ::Vector3D*)0x0); R__UseDummy(_R__UNIQUE_DICT_(Init));

   // Dictionary for non-ClassDef classes
   static TClass *Vector3D_Dictionary() {
      TClass* theClass =::ROOT::GenerateInitInstanceLocal((const ::Vector3D*)0x0)->GetClass();
      Vector3D_TClassManip(theClass);
   return theClass;
   }

   static void Vector3D_TClassManip(TClass* ){
   }

} // end of namespace ROOT

namespace ROOT {
   // Wrappers around operator new
   static void *new_Vector3D(void *p) {
      return  p ? new(p) ::Vector3D : new ::Vector3D;
   }
   static void *newArray_Vector3D(Long_t nElements, void *p) {
      return p ? new(p) ::Vector3D[nElements] : new ::Vector3D[nElements];
   }
   // Wrapper around operator delete
   static void delete_Vector3D(void *p) {
      delete ((::Vector3D*)p);
   }
   static void deleteArray_Vector3D(void *p) {
      delete [] ((::Vector3D*)p);
   }
   static void destruct_Vector3D(void *p) {
      typedef ::Vector3D current_t;
      ((current_t*)p)->~current_t();
   }
} // end of namespace ROOT for class ::Vector3D

namespace {
  void TriggerDictionaryInitialization_MyDict_Impl() {
    static const char* headers[] = {
"Vector3D.hh",
0
    };
    static const char* includePaths[] = {
"/Users/fabio/root_v6.22.02/include/",
"/Users/fabio/computing_methods/",
0
    };
    static const char* fwdDeclCode = R"DICTFWDDCLS(
#line 1 "MyDict dictionary forward declarations' payload"
#pragma clang diagnostic ignored "-Wkeyword-compat"
#pragma clang diagnostic ignored "-Wignored-attributes"
#pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
extern int __Cling_AutoLoading_Map;
class __attribute__((annotate("$clingAutoload$Vector3D.hh")))  Vector3D;
)DICTFWDDCLS";
    static const char* payloadCode = R"DICTPAYLOAD(
#line 1 "MyDict dictionary payload"


#define _BACKWARD_BACKWARD_WARNING_H
// Inline headers
#include "Vector3D.hh"

#undef  _BACKWARD_BACKWARD_WARNING_H
)DICTPAYLOAD";
    static const char* classesHeaders[] = {
"Vector3D", payloadCode, "@",
nullptr
};
    static bool isInitialized = false;
    if (!isInitialized) {
      TROOT::RegisterModule("MyDict",
        headers, includePaths, payloadCode, fwdDeclCode,
        TriggerDictionaryInitialization_MyDict_Impl, {}, classesHeaders, /*hasCxxModule*/false);
      isInitialized = true;
    }
  }
  static struct DictInit {
    DictInit() {
      TriggerDictionaryInitialization_MyDict_Impl();
    }
  } __TheDictionaryInitializer;
}
void TriggerDictionaryInitialization_MyDict() {
  TriggerDictionaryInitialization_MyDict_Impl();
}
