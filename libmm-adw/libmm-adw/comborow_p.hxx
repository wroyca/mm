// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_COMBOROW_P_H
#define _LIBADWAITAMM_COMBOROW_P_H

#include <libmm-adw/actionrow_p.hxx>

#include <libmm-glib/class.hxx>

namespace Adw
{

  class ComboRow_Class : public Glib::Class
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = ComboRow;
    using BaseObjectType = AdwComboRow;
    using BaseClassType = AdwComboRowClass;
    using CppClassParent = Adw::ActionRow_Class;
    using BaseClassParent = AdwActionRowClass;

    friend class ComboRow;
#endif

    auto
    init () -> const Glib::Class&;

    static auto
    class_init_function (void* g_class, void* class_data) -> void;

    static auto
    wrap_new (GObject*) -> Glib::ObjectBase*;

  protected:
  };

} // namespace Adw

#endif
