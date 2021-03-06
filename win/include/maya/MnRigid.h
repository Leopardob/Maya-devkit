#ifndef _MnRigid
#define _MnRigid
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All
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
// CLASS:    MnRigid
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES



#include <maya/MTypes.h>
#include <maya/MStatus.h>
#include <maya/MnObject.h>

class TnRigid;
class MFloatPointArray;
class MFloatArray;

// ****************************************************************************
// CLASS DECLARATION (MnRigid)

//! \ingroup OpenMayaFX
//! \brief Class for wrapping N cloth objects
/*!
  This class wraps the internal Maya representation of N cloth objects
  suitable for use with the Nucleus solver.
*/
class OPENMAYAFX_EXPORT MnRigid : public MnObject
{

public:
					MnRigid();
    virtual			~MnRigid();

    MStatus         setTopology(const int numFaces, int * numVertsPerFace, int * faces, const int numEdges, int * edges );
    MStatus         createNRigid();
    MStatus         setPositions(const MFloatPointArray & positions,bool startFrame = true);
    MStatus         setVelocities(const MFloatPointArray & velocities);

    MStatus         setThickness(float radius);
    MStatus         setThickness(float * radius);
    MStatus         setBounce(float bounce);
    MStatus         setBounce(float * bounce);
    MStatus         setFriction(float friction);
    MStatus         setFriction(float * friction);

    MStatus         setCollisionFlags(const bool vertToVert,
                                      const bool edgeToEdge = false,
                                      const bool faceToFace= false);

    MStatus         getNumVertices(unsigned int & numVerts) const;
    MStatus         getPositions(MFloatPointArray & positions) const;
    MStatus         getVelocities(MFloatPointArray & velocities) const;
    MStatus         getThickness(MFloatArray & radius) const;
    MStatus         getInverseMass(MFloatArray & inverseMass) const;
    MStatus         getBounce(MFloatArray & bounce) const;
    MStatus         getFriction(MFloatArray & friction) const;


protected:
// No protected members

private:
	MnRigid ( TnRigid * );
    void  setNRigid(TnRigid * nObj,bool own);
    TnRigid * getNRigid() { return (TnRigid *)fNObject; };
    friend class MFnNObjectData;
};

#endif /* __cplusplus */
#endif /* _MnCloth */
