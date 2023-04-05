// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_COMBOROW_P_H
#define _LIBADWAITAMM_COMBOROW_P_H

#include <libmm/adw/actionrow_p.hxx>

#include <libmm/glib/class.hxx>

namespace adw
{

  class LIBMM_ADW_SYMEXPORT ComboRow_Class : public glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ComboRow;
    using BaseObjectType = AdwComboRow;
    using BaseClassType = AdwComboRowClass;
    using CppClassParent = adw::ActionRow_Class;
    using BaseClassParent = AdwActionRowClass;

    friend class ComboRow;
#endif

    auto
    init () -> const glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> glib::ObjectBase*;

  protected:
  };

} // namespace adw

#endif
