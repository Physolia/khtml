/*
    Copyright (C) 2004, 2005 Nikolas Zimmermann <wildfox@kde.org>
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

#ifndef SVGTitleElement_h
#define SVGTitleElement_h
#if ENABLE(SVG)

#include "SVGLangSpace.h"
#include "SVGStyledElement.h"

namespace WebCore
{
class SVGTitleElement : public SVGStyledElement,
    public SVGLangSpace
{
public:
    SVGTitleElement(const QualifiedName &, Document *);

    void insertedIntoDocument() Q_DECL_OVERRIDE;
    void removedFromDocument() Q_DECL_OVERRIDE;
    using DOM::NodeImpl::childrenChanged;
    void childrenChanged(bool changedByParser = false, Node *beforeChange = 0, Node *afterChange = 0, int childCountDelta = 0) Q_DECL_OVERRIDE;

    bool rendererIsNeeded(RenderStyle *) Q_DECL_OVERRIDE
    {
        return false;
    }

    // KHTML ElementImpl pure virtual method
    quint32 id() const Q_DECL_OVERRIDE
    {
        return SVGNames::titleTag.id();
    }
};

} // namespace WebCore

#endif // ENABLE(SVG)
#endif

