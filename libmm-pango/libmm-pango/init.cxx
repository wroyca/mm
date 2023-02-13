// -*- c++ -*-
/* $Id: init.cc 89 2003-12-08 04:46:54Z murrayc $ */

/* Copyright (C) 2003 The pangomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free
 * Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <libmm-glib/init.hxx>
#include <libmm-pango/wrap_init.hxx>

namespace Pango
{

auto init () -> void
{
  Glib::init();
  wrap_init();
}

} // namespace Pango
