/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    wrapUtils.h
  Language:  C++
  Date:      $Date$
  Version:   $Revision$


  Copyright (c) 2000 National Library of Medicine
  All rights reserved.

  See COPYRIGHT.txt for copyright details.

=========================================================================*/
#ifndef _wrapUtils_h
#define _wrapUtils_h

// Include the C++ type representation classes.
// This also includes cxxUtils.h which does some work for us.
#include "cxxTypes.h"

// Get the DLL export definition from the CxxTypes package.
#define _wrap_EXPORT _cxx_EXPORT

// Include Tcl headers.
#include <tcl.h>

namespace _wrap_
{
// Some functions to make Tcl type checking easy.
_wrap_EXPORT bool TclObjectTypeIsNULL(Tcl_Obj*);
_wrap_EXPORT bool TclObjectTypeIsBoolean(Tcl_Obj*);
_wrap_EXPORT bool TclObjectTypeIsInt(Tcl_Obj*);
_wrap_EXPORT bool TclObjectTypeIsDouble(Tcl_Obj*);
_wrap_EXPORT bool TclObjectTypeIsString(Tcl_Obj*);
_wrap_EXPORT bool TclObjectTypeIsCmdName(Tcl_Obj*);

/**
 * The String type defined in the _cxx_ namespace.
 */
typedef ::_cxx_::String String;

/*@{
 * Pull this representation type out of _cxx_ namespace into _wrap_ namespace.
 */
typedef ::_cxx_::Type                 Type;
  
typedef ::_cxx_::ArrayType            ArrayType;
typedef ::_cxx_::ClassType            ClassType;
typedef ::_cxx_::FunctionType         FunctionType;
typedef ::_cxx_::FundamentalType      FundamentalType;
typedef ::_cxx_::PointerType          PointerType;
typedef ::_cxx_::PointerToMemberType  PointerToMemberType;
typedef ::_cxx_::ReferenceType        ReferenceType;

typedef ::_cxx_::CvQualifiedType      CvQualifiedType;
typedef ::_cxx_::TypeSystem           TypeSystem;
//@}

  
/**
 * Comparison function object for sorting based on pointer type.
 */
template <typename T>
struct PointerCompare
{
  bool operator()(T* l, T* r) const
    {
    return (reinterpret_cast<unsigned long>(l)
            < reinterpret_cast<unsigned long>(r));
    }
};

} // namespace _wrap_


#endif
