/*
    Copyright (C) 2004, 2005, 2006, 2008 Nikolas Zimmermann <zimmermann@kde.org>
                  2004, 2005, 2006 Rob Buis <buis@kde.org>

    This file is part of the KDE project

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef SVGRectElement_h
#define SVGRectElement_h

#if ENABLE(SVG)
#include "SVGExternalResourcesRequired.h"
#include "SVGLangSpace.h"
#include "SVGStyledTransformableElement.h"
#include "SVGTests.h"

namespace WebCore
{

class SVGRectElement : public SVGStyledTransformableElement,
    public SVGTests,
    public SVGLangSpace,
    public SVGExternalResourcesRequired
{
public:
    SVGRectElement(const QualifiedName &, Document *);
    virtual ~SVGRectElement();

    bool isValid() const Q_DECL_OVERRIDE
    {
        return SVGTests::isValid();
    }

    void parseMappedAttribute(MappedAttribute *) Q_DECL_OVERRIDE;
    void svgAttributeChanged(const QualifiedName &) Q_DECL_OVERRIDE;

    Path toPathData() const Q_DECL_OVERRIDE;

    // KHTML ElementImpl pure virtual method
    quint32 id() const Q_DECL_OVERRIDE;
protected:
    const SVGElement *contextElement() const Q_DECL_OVERRIDE
    {
        return this;
    }
    bool hasRelativeValues() const Q_DECL_OVERRIDE;

private:
    ANIMATED_PROPERTY_FORWARD_DECLARATIONS(SVGExternalResourcesRequired, bool, ExternalResourcesRequired, externalResourcesRequired)

    ANIMATED_PROPERTY_DECLARATIONS(SVGRectElement, SVGLength, SVGLength, X, x)
    ANIMATED_PROPERTY_DECLARATIONS(SVGRectElement, SVGLength, SVGLength, Y, y)
    ANIMATED_PROPERTY_DECLARATIONS(SVGRectElement, SVGLength, SVGLength, Width, width)
    ANIMATED_PROPERTY_DECLARATIONS(SVGRectElement, SVGLength, SVGLength, Height, height)
    ANIMATED_PROPERTY_DECLARATIONS(SVGRectElement, SVGLength, SVGLength, Rx, rx)
    ANIMATED_PROPERTY_DECLARATIONS(SVGRectElement, SVGLength, SVGLength, Ry, ry)
};

} // namespace WebCore

#endif // ENABLE(SVG)
#endif
