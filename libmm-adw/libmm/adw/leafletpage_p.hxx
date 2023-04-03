// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_LEAFLETPAGE_P_H
#define _LIBADWAITAMM_LEAFLETPAGE_P_H

#include <libmm/glib/object_p.hxx>

#include <libmm/glib/class.hxx>

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT LeafletPage_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = LeafletPage;
    using BaseObjectType = AdwLeafletPage;
    using CppClassParent = Glib::Object_Class;

    friend class LeafletPage;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
