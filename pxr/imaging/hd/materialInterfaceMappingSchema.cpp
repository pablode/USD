//
// Copyright 2023 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdGen/schema.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "pxr/imaging/hd/materialInterfaceMappingSchema.h"
#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
#include "pxr/imaging/hd/materialNetworkSchema.h"
#include "pxr/imaging/hd/materialNodeSchema.h"
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdMaterialInterfaceMappingSchemaTokens,
    HD_MATERIAL_INTERFACE_MAPPING_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--

HdDataSourceLocator
HdMaterialInterfaceMappingSchema::BuildNetworkRelativeLocator()
{
    HdTokenDataSourceHandle nodePathDs = GetNodePath();
    if (!nodePathDs) {
        return HdDataSourceLocator();
    }

    HdTokenDataSourceHandle inputNameDs = GetInputName();
    if (!inputNameDs) {
        return HdDataSourceLocator();
    }

    return HdDataSourceLocator(
        HdMaterialNetworkSchemaTokens->nodes,
        nodePathDs->GetTypedValue(0.0f),
        HdMaterialNodeSchemaTokens->parameters,
        inputNameDs->GetTypedValue(0.0f));
}

// --(END CUSTOM CODE: Schema Methods)--




HdTokenDataSourceHandle
HdMaterialInterfaceMappingSchema::GetNodePath()
{
    return _GetTypedDataSource<HdTokenDataSource>(
        HdMaterialInterfaceMappingSchemaTokens->nodePath);
}

HdTokenDataSourceHandle
HdMaterialInterfaceMappingSchema::GetInputName()
{
    return _GetTypedDataSource<HdTokenDataSource>(
        HdMaterialInterfaceMappingSchemaTokens->inputName);
}

/*static*/
HdContainerDataSourceHandle
HdMaterialInterfaceMappingSchema::BuildRetained(
        const HdTokenDataSourceHandle &nodePath,
        const HdTokenDataSourceHandle &inputName
)
{
    TfToken _names[2];
    HdDataSourceBaseHandle _values[2];

    size_t _count = 0;
    if (nodePath) {
        _names[_count] = HdMaterialInterfaceMappingSchemaTokens->nodePath;
        _values[_count++] = nodePath;
    }

    if (inputName) {
        _names[_count] = HdMaterialInterfaceMappingSchemaTokens->inputName;
        _values[_count++] = inputName;
    }

    return HdRetainedContainerDataSource::New(_count, _names, _values);
}


HdMaterialInterfaceMappingSchema::Builder &
HdMaterialInterfaceMappingSchema::Builder::SetNodePath(
    const HdTokenDataSourceHandle &nodePath)
{
    _nodePath = nodePath;
    return *this;
}

HdMaterialInterfaceMappingSchema::Builder &
HdMaterialInterfaceMappingSchema::Builder::SetInputName(
    const HdTokenDataSourceHandle &inputName)
{
    _inputName = inputName;
    return *this;
}

HdContainerDataSourceHandle
HdMaterialInterfaceMappingSchema::Builder::Build()
{
    return HdMaterialInterfaceMappingSchema::BuildRetained(
        _nodePath,
        _inputName
    );
}


PXR_NAMESPACE_CLOSE_SCOPE