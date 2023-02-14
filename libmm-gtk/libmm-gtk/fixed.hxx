// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FIXED_H
#define _GTKMM_FIXED_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkFixed = struct _GtkFixed;
using GtkFixedClass = struct _GtkFixedClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Fixed_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Fixed : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Fixed CppObjectType;
    typedef Fixed_Class CppClassType;
    typedef GtkFixed BaseObjectType;
    typedef GtkFixedClass BaseClassType;
#endif

    Fixed (Fixed&& src) noexcept;
    auto
    operator= (Fixed&& src) noexcept -> Fixed&;

    Fixed (const Fixed&) = delete;
    auto
    operator= (const Fixed&) -> Fixed& = delete;

    ~Fixed () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Fixed_Class;
    static CppClassType fixed_class_;

  protected:
    explicit Fixed (const Glib::ConstructParams& construct_params);
    explicit Fixed (GtkFixed* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFixed*
    {
      return reinterpret_cast<GtkFixed*> (gobject_);
    }

    auto
    gobj () const -> const GtkFixed*
    {
      return reinterpret_cast<GtkFixed*> (gobject_);
    }

  private:
  public:
    Fixed ();

    void
    put (Widget& widget, double x, double y);

    void
    remove (Widget& widget);

    void
    move (Widget& widget, double x, double y);

    void
    get_child_position (Widget& widget, double& x, double& y) const;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkFixed* object, bool take_copy = false) -> Gtk::Fixed*;
} // namespace Glib

#endif
