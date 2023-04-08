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
namespace adw
{
  class LIBMM_ADW_SYMEXPORT clamp_scrollable_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT clamp_scrollable : public gtk::Widget,
                          public gtk::Orientable,
                          public gtk::Scrollable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    using CppObjectType = clamp_scrollable;
    using CppClassType = clamp_scrollable_class;
    using BaseObjectType = AdwClampScrollable;
    using BaseClassType = AdwClampScrollableClass;
#endif

    clamp_scrollable (clamp_scrollable&& src) noexcept;
    auto
    operator= (clamp_scrollable&& src) noexcept -> clamp_scrollable&;

    clamp_scrollable (const clamp_scrollable&) = delete;
    auto
    operator= (const clamp_scrollable&) -> clamp_scrollable& = delete;

    ~clamp_scrollable () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend class clamp_scrollable_class;
    static CppClassType clampscrollable_class_;

  protected:
    explicit clamp_scrollable (const glib::ConstructParams& construct_params);
    explicit clamp_scrollable (AdwClampScrollable* castitem);

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
    clamp_scrollable ();

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_maximum_size () const -> int;

    auto
    get_tightening_threshold () const -> int;

    auto
    set_child (gtk::Widget* child) -> void;

    auto
    get_maximum_size (int maximum_size) -> void;

    auto
    get_tightening_threshold (int tightening_threshold) -> void;

    auto
    property_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_maximum_size () -> glib::PropertyProxy<int>;

    auto
    property_maximum_size () const -> glib::PropertyProxy_ReadOnly<int>;

    auto
    property_tightening_threshold () -> glib::PropertyProxy<int>;

    auto
    property_tightening_threshold () const -> glib::PropertyProxy_ReadOnly<int>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwClampScrollable* object, bool take_copy = false) -> adw::clamp_scrollable*;
}

#endif
