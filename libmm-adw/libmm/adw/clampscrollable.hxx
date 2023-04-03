// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_CLAMPSCROLLABLE_H
#define _LIBADWAITAMM_CLAMPSCROLLABLE_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class LIBMM_ADW_SYMEXPORT ClampScrollable_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT ClampScrollable : public Gtk::Widget,
                          public Gtk::Orientable,
                          public Gtk::Scrollable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ClampScrollable CppObjectType;
    typedef ClampScrollable_Class CppClassType;
    typedef AdwClampScrollable BaseObjectType;
    typedef AdwClampScrollableClass BaseClassType;
#endif

    ClampScrollable (ClampScrollable&& src) noexcept;
    auto
    operator= (ClampScrollable&& src) noexcept -> ClampScrollable&;

    ClampScrollable (const ClampScrollable&) = delete;
    auto
    operator= (const ClampScrollable&) -> ClampScrollable& = delete;

    ~ClampScrollable () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class ClampScrollable_Class;
    static CppClassType clampscrollable_class_;

  protected:
    explicit ClampScrollable (const Glib::ConstructParams& construct_params);
    explicit ClampScrollable (AdwClampScrollable* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwClampScrollable*
    {
      return reinterpret_cast<AdwClampScrollable*> (gobject_);
    }

    auto
    gobj () const -> const AdwClampScrollable*
    {
      return reinterpret_cast<AdwClampScrollable*> (gobject_);
    }

  private:
  public:
    ClampScrollable ();

    auto
    get_child () const -> Gtk::Widget*;

    auto
    get_maximum_size () const -> int;

    auto
    get_tightening_threshold () const -> int;

    auto
    set_child (Gtk::Widget* child) -> void;

    auto
    get_maximum_size (int maximum_size) -> void;

    auto
    get_tightening_threshold (int tightening_threshold) -> void;

    auto
    property_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_maximum_size () -> Glib::PropertyProxy<int>;

    auto
    property_maximum_size () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tightening_threshold () -> Glib::PropertyProxy<int>;

    auto
    property_tightening_threshold () const -> Glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwClampScrollable* object, bool take_copy = false) -> Adw::ClampScrollable*;
}

#endif
