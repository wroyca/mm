// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_TABPAGE_H
#define _LIBADWAITAMM_TABPAGE_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/mm-glib.hxx>
#include <libmm/gtk/mm-gtk.hxx>

#include <adwaita.h>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT TabPage_Class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT TabPage : public glib::Object
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
    explicit TabPage (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<TabPage>;

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_icon () const -> glib::RefPtr<gio::Icon>;

    auto
    get_indicator_activatable () const -> bool;

    auto
    get_indicator_icon () const -> glib::RefPtr<gio::Icon>;

    auto
    get_indicator_tooltip () const -> glib::ustring;

    auto
    get_loading () const -> bool;

    auto
    get_needs_attention () const -> bool;

    auto
    get_parent () const -> glib::RefPtr<TabPage>;

    auto
    get_pinned () const -> bool;

    auto
    get_selected () const -> bool;

    auto
    get_title () const -> glib::ustring;

    auto
    get_tooltip () const -> glib::ustring;

    auto
    set_icon (const glib::RefPtr<gio::Icon>& icon) -> void;

    auto
    set_indicator_activatable (bool activatable) -> void;

    auto
    set_indicator_icon (const glib::RefPtr<gio::Icon>& indicator_icon) -> void;

    auto
    set_indicator_tooltip (const glib::ustring& indicator_tooltip) -> void;

    auto
    set_loading (bool loading) -> void;

    auto
    set_needs_attention (bool needs_attention) -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    set_tooltip (const glib::ustring& tooltip) -> void;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>;

    auto
    property_icon () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>;

    auto
    property_indicator_activatable () -> glib::PropertyProxy<bool>;

    auto
    property_indicator_activatable () const
        -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_indicator_icon () -> glib::PropertyProxy<glib::RefPtr<gio::Icon>>;

    auto
    property_indicator_icon () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gio::Icon>>;

    auto
    property_indicator_tooltip () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_indicator_tooltip () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_loading () -> glib::PropertyProxy<bool>;

    auto
    property_loading () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_needs_attention () -> glib::PropertyProxy<bool>;

    auto
    property_needs_attention () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_parent () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<TabPage>>;

    auto
    property_pinned () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_selected () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_tooltip () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_tooltip () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwTabPage* object, bool take_copy = false) -> glib::RefPtr<adw::TabPage>;
}

#endif
