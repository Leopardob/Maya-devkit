#ifndef _MRenderPassDef
#define _MRenderPassDef

//-
// ==========================================================================
// Copyright (C) 1995 - 2008 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MRenderPassDef
//
// ****************************************************************************

#if defined __cplusplus


#include <maya/MString.h>
#include <maya/MStatus.h>
#include <maya/MPxRenderPassImpl.h>

// ****************************************************************************
// CLASS DECLARATION (MRenderPassRegistry)

//! \ingroup OpenMayaRender
//! \brief Render pass information
/*!
  This class provides a means to access information about a specific render
  pass. Initialize by passing to
  MRenderPassRegistry::getRenderPassDefinition(), or by calling create()
  to generate and register a new pass.
*/

class OPENMAYA_EXPORT MRenderPassDef {
public:
	virtual ~MRenderPassDef();

	MPxRenderPassImpl* getImplementation(
				const MString& renderer,
				MPxRenderPassImpl::PassTypeBit fbType, 
				unsigned int numChannels,
				MStatus* ReturnStatus=NULL);

	MPxRenderPassImpl* getImplementation(
				const MString& renderer,
				MStatus* ReturnStatus=NULL);

	MString getID(MStatus* ReturnStatus=NULL) const;
	MString getName(MStatus* ReturnStatus=NULL) const;
	MString getGroup(MStatus* ReturnStatus=NULL) const;
	MString getDescription(MStatus* ReturnStatus=NULL) const;
    MString getAttributeType(const MString &attributeName, MStatus* ReturnStatus = NULL) const;

	MStatus addFloatParameter(
		const MString &longName,
		const MString &shortName,
        const MString &UIName,
		const float &minValue,
		const float &maxValue,
		const float &defaultValue
		);

	MStatus addDoubleParameter(
		const MString &longName,
		const MString &shortName,
        const MString &UIName,
		const double &minValue,
		const double &maxValue,
		const double &defaultValue
		);

	MStatus addIntParameter(
		const MString &longName,
		const MString &shortName,
        const MString &UIName,
		const int &minValue,
		const int &maxValue,
		const int &defaultValue
		);

	static const char* className();

private:
	friend class MRenderPassRegistry;
	friend class MFnPlugin;

	// can only get instances by querying or creating
	MRenderPassDef();

	void*		instance;
};

// ****************************************************************************

#endif /* __cplusplus */
#endif /* _MRenderPassDef */

