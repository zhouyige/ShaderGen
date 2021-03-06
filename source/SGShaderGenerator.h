/************************************************************************
*                                                                       *
*               Copyright (C) 2002-2005  3Dlabs Inc. Ltd.               *
*                                                                       *
*                        All rights reserved.                           *
*                                                                       *
* Redistribution and use in source and binary forms, with or without    *
* modification, are permitted provided that the following conditions    *
* are met:                                                              *
*                                                                       *
*     Redistributions of source code must retain the above copyright    *
*     notice, this list of conditions and the following disclaimer.     *
*                                                                       *
*     Redistributions in binary form must reproduce the above           *
*     copyright notice, this list of conditions and the following       *
*     disclaimer in the documentation and/or other materials provided   *
*     with the distribution.                                            *
*                                                                       *
*     Neither the name of 3Dlabs Inc. Ltd. nor the names of its         *
*     contributors may be used to endorse or promote products derived   *
*     from this software without specific prior written permission.     *
*                                                                       *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS   *
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT     *
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS     *
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE        *
* COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, *
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  *
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;      *
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER      *
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT    *
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN     *
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                           *
*                                                                       *
************************************************************************/

#pragma once

#include <GL/glew.h>

#include <QString>

//#include "Compulsory.h"
#include "globals.h"

class SGShaderGenerator
{
public:
    SGShaderGenerator();
    ~SGShaderGenerator();
    const QString & buildVertexShader();
    const QString & buildFragmentShader();

private:
    typedef struct _currentTextureState{
        GLboolean textureCoordinateGenerationReflection;
        GLboolean textureCoordinateGenerationSphereMap;
        GLboolean textureCoordinateGenerationEye;
        GLboolean textureCoordinateGenerationObject;
        GLboolean textureCoordinateGenerationNormal;
        GLboolean textureEnabled;
        GLboolean textureGenerationEnableArray[NUM_TEXTURE_COORDS];
    } CurrentTextureState;

    QString fragShader;
    QString vertShader;

    bool fLightPoint, fLightSpot, fLightDir, fLightDirSpot;
    bool fMapSphere, fMapReflection, vTexGenEnable;

    GLboolean texturesEnabled;
    
    CurrentTextureState currentTexture[NUM_TEXTURES];

    void initTextures();
    void buildFragFog(QString &str);
    void buildFragTex(QString &str);

    void buildFragSeparateSpecularColor(QString &str);

    void buildLightCode  ( QString &str );
    void buildVertMain   ( QString &str );
    void buildFuncFnormal( QString &str );
    void buildFuncFog    ( QString &str );
    void buildFuncPoint  ( QString &str );
    void buildTexCoord   ( QString &str );

    void addFuncLightDirectional   (QString &str) const;
    void addFuncLightPoint         (QString &str) const;
    void addFuncLightSpot          (QString &str) const;
    void addFuncSphereMap          (QString &str) const;
    void addFuncReflectionMap      (QString &str) const;
    void addFuncLightSpotDirection (QString &str) const;
};
