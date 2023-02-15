// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSTACKPAGE_H
#define _LIBADWAITAMM_VIEWSTACKPAGE_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/mm-glib.hxx>
#include <libmm-gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class ViewStackPage_Class;
}
#endif

namespace Adw
{

  class ViewStackPage : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ViewStackPage;
    using CppClassType = ViewStackPage_Class;
    using BaseObjectType = AdwViewStackPage;
    using BaseClassType = AdwViewStackPageClass;

    ViewStackPage (const ViewStackPage&) = delete;
    auto
    operator= (const ViewStackPage&) -> ViewStackPage& = delete;

  private:
    friend class ViewStackPage_Class;
    static CppClassType viewstackpage_class_;

  protected:
    explicit ViewStackPage (const Glib::ConstructParams& construct_params);
    explicit ViewStackPage (AdwViewStackPage* castitem);

#endif

  public:
    ViewStackPage (ViewStackPage&& src) noexcept;
    auto
    operator= (ViewStackPage&& src) noexcept -> ViewStackPage&;

    ~ViewStackPage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwViewStackPage*
    {
      return reinterpret_cast<AdwViewStackPage*> (gobject_);
    }

    auto
    gobj () const -> const AdwViewStackPage*
    {
      return reinterpret_cast<AdwViewStackPage*> (gobject_);
    }

    auto
    gobj_copy () -> AdwViewStackPage*;

  private:
  protected:
    ViewStackPage ();

  public:
    static auto
    create () -> Glib::RefPtr<ViewStackPage>;

    auto
    get_badge_number () const -> guint;

    auto
    get_child () const -> Gtk::Widget*;

    auto
    get_icon_name () const -> Glib::ustring;

    auto
    get_name () const -> Glib::ustring;

    auto
    get_needs_attention () const -> bool;

    auto
    get_title () const -> Glib::ustring;

    auto
    get_use_underline () const -> bool;

    auto
    get_visible () const -> bool;

    auto
    set_badge_number (guint badge_number) -> void;

    auto
    set_icon_name (const Glib::ustring& icon_name) -> void;

    auto
    set_name (const Glib::ustring& name) -> void;

    auto
    set_needs_attention (bool needs_attention) -> void;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    set_visible (bool visible) -> void;

    auto
    property_badge_number () -> Glib::PropertyProxy<guint>;

    auto
    property_badge_number () const -> Glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_icon_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_icon_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_needs_attention () -> Glib::PropertyProxy<bool>;

    auto
    property_needs_attention () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible () -> Glib::PropertyProxy<bool>;

    auto
    property_visible () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwViewStackPage* object, bool take_copy = false) -> Glib::RefPtr<Adw::ViewStackPage>;
}

#endif
