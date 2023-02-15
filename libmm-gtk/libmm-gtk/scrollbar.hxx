// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCROLLBAR_H
#define _GTKMM_SCROLLBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScrollbar = struct _GtkScrollbar;
using GtkScrollbarClass = struct _GtkScrollbarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Scrollbar_Class;
}
#endif

namespace Gtk
{
  class GTKMM_API Adjustment;

  class GTKMM_API Scrollbar : public Widget,
                              public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Scrollbar CppObjectType;
    typedef Scrollbar_Class CppClassType;
    typedef GtkScrollbar BaseObjectType;
    typedef GtkScrollbarClass BaseClassType;
#endif

    Scrollbar (Scrollbar&& src) noexcept;
    auto
    operator= (Scrollbar&& src) noexcept -> Scrollbar&;

    Scrollbar (const Scrollbar&) = delete;
    auto
    operator= (const Scrollbar&) -> Scrollbar& = delete;

    ~Scrollbar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Scrollbar_Class;
    static CppClassType scrollbar_class_;

  protected:
    explicit Scrollbar (const Glib::ConstructParams& construct_params);
    explicit Scrollbar (GtkScrollbar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkScrollbar*
    {
      return reinterpret_cast<GtkScrollbar*> (gobject_);
    }

    auto
    gobj () const -> const GtkScrollbar*
    {
      return reinterpret_cast<GtkScrollbar*> (gobject_);
    }

  private:
  public:
    Scrollbar ();

    explicit Scrollbar (const Glib::RefPtr<Adjustment>& adjustment,
                        Orientation orientation = Orientation::HORIZONTAL);

    auto
    set_adjustment (const Glib::RefPtr<Adjustment>& adjustment) -> void;
    auto
    unset_adjustment () -> void;

    auto
    get_adjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_adjustment () const -> Glib::RefPtr<const Adjustment>;

    auto
    property_adjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_adjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkScrollbar* object, bool take_copy = false) -> Gtk::Scrollbar*;
} // namespace Glib

#endif
