#ifndef __stir_IO_GESignaListmodeInputFileFormat_h__
#define __stir_IO_GESignaListmodeInputFileFormat_h__
/*
    Copyright (C) 2013 University College London
    This file is part of STIR.

    This file is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2.1 of the License, or
    (at your option) any later version.

    This file is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    See STIR/LICENSE.txt for details
*/
/*!

  \file
  \ingroup ECAT
  \brief Declaration of class stir::ecat::GESignaListmodeInputFileFormat

  \author Kris Thielemans
*/
#include "stir/IO/InputFileFormat.h"
#include "stir/listmode/CListModeDataGESigna.h"
//#include "stir/listmode/CListRecordGESigna.h"

#include "stir/utilities.h"
#include <string>

START_NAMESPACE_STIR

//! Class for being able to read list mode data from the GE Signa PET/MR scanner via the listmode-data registry.
/*! 
  \ingroup listmode
*/
class GESignaListmodeInputFileFormat :
public InputFileFormat<CListModeData >
{
 public:
  virtual const std::string
    get_name() const
  {  return "GESigna"; }

 protected:
  virtual 
    bool 
    actual_can_read(const FileSignature& signature,
		    std::istream& input) const
  {
    // TODO need to do check that it's a GE HDF5 list file etc
    return true;
  }
 public:
  virtual std::auto_ptr<data_type>
    read_from_file(std::istream& input) const
  {
    warning("read_from_file for GESigna listmode data with istream not implemented %s:%s. Sorry",
	  __FILE__, __LINE__);
    return
      std::auto_ptr<data_type>
      (0);
  }
  virtual std::auto_ptr<data_type>
    read_from_file(const std::string& filename) const
  {	
    return std::auto_ptr<data_type>(new CListModeDataGESigna(filename)); 
  }
};


END_NAMESPACE_STIR

#endif