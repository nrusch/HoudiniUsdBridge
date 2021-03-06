/*
 * Copyright 2019 Side Effects Software Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __GEO_FILE_PROP_H__
#define __GEO_FILE_PROP_H__
 
#include "pxr/pxr.h"
#include "GEO_FileUtils.h"
#include "GEO_FilePropSource.h"
#include <UT/UT_IntrusivePtr.h>
#include <UT/UT_Map.h>
#include <pxr/base/tf/token.h>
#include <pxr/usd/sdf/valueTypeName.h>
#include <map>

class GU_DetailHandle;

PXR_NAMESPACE_OPEN_SCOPE

class GEO_FileFieldValue;

/// \class GEO_FileProp
///
class GEO_FileProp
{
public:
				 GEO_FileProp(const SdfValueTypeName &type_name,
					 GEO_FilePropSource *prop_source);
				~GEO_FileProp();

    const SdfValueTypeName	&getTypeName() const
				 { return myTypeName; }
    void			 setTypeName(const SdfValueTypeName &type_name)
				 { myTypeName = type_name; }

    bool			 getValueIsDefault() const
				 { return myValueIsDefault; }
    void			 setValueIsDefault(bool is_default)
				 { myValueIsDefault = is_default; }

    bool			 getValueIsUniform() const
				 { return myValueIsUniform; }
    void			 setValueIsUniform(bool is_uniform)
				 { myValueIsUniform = is_uniform; }

    bool			 getIsRelationship() const
				 { return myIsRelationship; }
    void			 setIsRelationship(bool is_relationship)
				 {
				     myIsRelationship = is_relationship;
				     myValueIsUniform = true;
				 }

    const GEO_FileMetadata	&getMetadata() const
				 { return myMetadata; }
    const GEO_FileMetadata	&getCustomData() const
				 { return myCustomData; }
    bool			 copyData(const GEO_FileFieldValue &v) const;

    // Add metadata or custom data to a property.
    // The "add" methods use emplace, and so do not replace existing values.
    void			 addMetadata(const TfToken &key,
					const VtValue &value);
    void			 addCustomData(const TfToken &key,
					const VtValue &value);

private:
    SdfValueTypeName		 myTypeName;
    GEO_FilePropSourceHandle	 myPropSource;
    GEO_FileMetadata		 myMetadata;
    GEO_FileMetadata		 myCustomData;
    bool			 myValueIsDefault;
    bool			 myValueIsUniform;
    bool			 myIsRelationship;
};

typedef UT_SortedMap<TfToken, GEO_FileProp> GEO_FilePropMap;

PXR_NAMESPACE_CLOSE_SCOPE

#endif // __GEO_FILE_PROP_H__
