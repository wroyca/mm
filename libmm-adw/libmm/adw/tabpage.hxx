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
  class LIBMM_ADW_SYMEXPORT tab_page_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT tab_page : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = tab_page;
    using CppClassType = tab_page_class;
    using BaseObjectType = AdwTabPage;
    using BaseClassType = AdwTabPageClass;

    tab_page (const tab_page&) = delete;
    auto
    operator= (const tab_page&) -> tab_page& = delete;

  private:
    friend class tab_page_class;
    static CppClassType tabpage_class_;

  protected:
    explicit tab_page (const glib::ConstructParams& construct_params);
    explicit tab_page (AdwTabPage* castitem);

#endif

  public:
    tab_page (tab_page&& src) noexcept;
    auto
    operator= (tab_page&& src) noexcept -> tab_page&;

    ~tab_page () noexcept override;

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
    tab_page ();

  public:
    static auto
    create () -> glib::RefPtr<tab_page>;

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
    get_parent () const -> glib::RefPtr<tab_page>;

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
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<tab_page>>;

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
  wrap (AdwTabPage* object, bool take_copy = false) -> glib::RefPtr<adw::tab_page>;
}

#endif
