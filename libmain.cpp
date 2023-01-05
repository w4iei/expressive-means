/* -*- c-basic-offset: 4 indent-tabs-mode: nil -*-  vi:set ts=8 sts=4 sw=4: */

/*
    Expressive Means Vamp Plugins

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of the
    License, or (at your option) any later version.  See the file
    COPYING included with this distribution for more information.
*/

#include <vamp/vamp.h>
#include <vamp-sdk/PluginAdapter.h>

#include "articulation/Articulation.h"

static Vamp::PluginAdapter<Articulation> articulationPluginAdapter;

const VampPluginDescriptor *
vampGetPluginDescriptor(unsigned int version, unsigned int index)
{
    if (version < 1) return 0;

    switch (index) {
    case  0: return articulationPluginAdapter.getDescriptor();
    default: return 0;
    }
}


