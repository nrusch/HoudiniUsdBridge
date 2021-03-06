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
 *
 * Produced by:
 *	Side Effects Software Inc
 *	123 Front Street West, Suite 1401
 *	Toronto, Ontario
 *	Canada   M5J 2M2
 *	416-504-9876
 *
 * NAME:	HD_HoudiniRendererPlugin.h
 *
 * COMMENTS:	Render delegate for the native Houdini viewport renderer
 */
#include <pxr/pxr.h>
#include <pxr/imaging/hd/rendererPlugin.h>

#include <HUSD/HUSD_Scene.h>

PXR_NAMESPACE_OPEN_SCOPE

// -------------------------------------------------------------------------
// Render plugin

class HD_HoudiniRendererPlugin final : public HdRendererPlugin
{
public:
	     HD_HoudiniRendererPlugin() = default;
    virtual ~HD_HoudiniRendererPlugin() = default;

    virtual HdRenderDelegate *CreateRenderDelegate() override;
    virtual HdRenderDelegate *CreateRenderDelegate(
	    HdRenderSettingsMap const& settingsMap) override;
    virtual void DeleteRenderDelegate(HdRenderDelegate *delegate) override;

    virtual bool IsSupported() const override
        { return HUSD_Scene::hasScene(); }
   
private:
    // This class does not support copying.
    HD_HoudiniRendererPlugin(const HD_HoudiniRendererPlugin&)=delete;
    HD_HoudiniRendererPlugin &operator=(const HD_HoudiniRendererPlugin&)=delete;
};

PXR_NAMESPACE_CLOSE_SCOPE
