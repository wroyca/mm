// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TABPAGE_H
#define _LIBADWAITAMM_TABPAGE_H

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
  class LIBMM_ADW_SYMEXPORT TabPage_Class;
}
#endif

namespace Adw
{

  class LIBMM_ADW_SYMEXPORT TabPage : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = TabPage;
    using CppClassType = TabPage_Class;
    using BaseObjectType = AdwTabPage;
    using BaseClassType = AdwTabPageClass;

    TabPage (const TabPage&) = delete;
    auto
    operator= (const TabPage&) -> TabPage& = delete;

  private:
    friend class TabPage_Class;
    static CppClassType tabpage_class_;

  protected:
    explicit TabPage (const Glib::ConstructParams& construct_params);
    explicit TabPage (AdwTabPage* castitem);

#endif

  public:
    TabPage (TabPage&& src) noexcept;
    auto
    operator= (TabPage&& src) noexcept -> TabPage&;

    ~TabPage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwTabPage*
    {
      return reinterpret_cast<AdwTabPage*> (gobject_);
    }

    auto
    gobj () const -> const AdwTabPage*
    {
      return reinterpret_cast<AdwTabPage*> (gobject_);
    }

    auto
    gobj_copy () -> AdwTabPage*;

  private:
  protected:
    TabPage ();

  public:
    static auto
    create () -> Glib::RefPtr<TabPage>;

    auto
    get_child () const -> Gtk::Widget*;

    auto
    get_icon () const -> Glib::RefPtr<Gio::Icon>;

    auto
    get_indicator_activatable () const -> bool;

    auto
    get_indicator_icon () const -> Glib::RefPtr<Gio::Icon>;

    auto
    get_indicator_tooltip () const -> Glib::ustring;

    auto
    get_loading () const -> bool;

    auto
    get_needs_attention () const -> bool;

    auto
    get_parent () const -> Glib::RefPtr<TabPage>;

    auto
    get_pinned () const -> bool;

    auto
    get_selected () const -> bool;

    auto
    get_title () const -> Glib::ustring;

    auto
    get_tooltip () const -> Glib::ustring;

    auto
    set_icon (const Glib::RefPtr<Gio::Icon>& icon) -> void;

    auto
    set_indicator_activatable (bool activatable) -> void;

    auto
    set_indicator_icon (const Glib::RefPtr<Gio::Icon>& indicator_icon) -> void;

    auto
    set_indicator_tooltip (const Glib::ustring& indicator_tooltip) -> void;

    auto
    set_loading (bool loading) -> void;

    auto
    set_needs_attention (bool needs_attention) -> void;

    auto
    set_title (const Glib::ustring& title) -> void;

    auto
    set_tooltip (const Glib::ustring& tooltip) -> void;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_icon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_indicator_activatable () -> Glib::PropertyProxy<bool>;

    auto
    property_indicator_activatable () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_indicator_icon () -> Glib::PropertyProxy<Glib::RefPtr<Gio::Icon>>;

    auto
    property_indicator_icon () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::Icon>>;

    auto
    property_indicator_tooltip () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_indicator_tooltip () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_loading () -> Glib::PropertyProxy<bool>;

    auto
    property_loading () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_needs_attention () -> Glib::PropertyProxy<bool>;

    auto
    property_needs_attention () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_parent () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<TabPage>>;

    auto
    property_pinned () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_selected () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_tooltip () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_tooltip () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwTabPage* object, bool take_copy = false) -> Glib::RefPtr<Adw::TabPage>;
}

#endif
