// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GLIBMM_INTERFACE_H
#define _GLIBMM_INTERFACE_H

#include <libmm-glib/object.hxx>

namespace Glib
{

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  class GLIBMM_API Interface_Class;
#endif

  class GLIBMM_API Interface : virtual public Glib::ObjectBase
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = Interface;
    using CppClassType = Interface_Class;
    using BaseClassType = GTypeInterface;
#endif

    Interface ();

    Interface (Interface&& src) noexcept;
    auto
    operator= (Interface&& src) noexcept -> Interface&;

    explicit Interface (const Glib::Interface_Class& interface_class);

    explicit Interface (GObject* castitem);
    ~Interface () noexcept override;

    Interface (const Interface&) = delete;
    auto
    operator= (const Interface&) -> Interface& = delete;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_type () -> GType G_GNUC_CONST;
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    inline auto
    gobj () -> GObject*
    {
      return gobject_;
    }

    inline auto
    gobj () const -> const GObject*
    {
      return gobject_;
    }
  };

  auto
  wrap_interface (GObject* object, bool take_copy = false) -> RefPtr<ObjectBase>;

} // namespace Glib

#endif
