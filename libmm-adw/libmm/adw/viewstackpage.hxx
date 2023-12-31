// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_VIEWSTACKPAGE_H
#define _LIBADWAITAMM_VIEWSTACKPAGE_H

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
  class LIBMM_ADW_SYMEXPORT view_stack_page_class;
}
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT view_stack_page : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = view_stack_page;
    using CppClassType = view_stack_page_class;
    using BaseObjectType = AdwViewStackPage;
    using BaseClassType = AdwViewStackPageClass;

    view_stack_page (const view_stack_page&) = delete;
    auto
    operator= (const view_stack_page&) -> view_stack_page& = delete;

  private:
    friend class view_stack_page_class;
    static CppClassType viewstackpage_class_;

  protected:
    explicit view_stack_page (const glib::ConstructParams& construct_params);
    explicit view_stack_page (AdwViewStackPage* castitem);

#endif

  public:
    view_stack_page (view_stack_page&& src) noexcept;
    auto
    operator= (view_stack_page&& src) noexcept -> view_stack_page&;

    ~view_stack_page () noexcept override;

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
    view_stack_page ();

  public:
    static auto
    create () -> glib::RefPtr<view_stack_page>;

    auto
    get_badge_number () const -> guint;

    auto
    get_child () const -> gtk::Widget*;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    get_name () const -> glib::ustring;

    auto
    get_needs_attention () const -> bool;

    auto
    get_title () const -> glib::ustring;

    auto
    get_use_underline () const -> bool;

    auto
    get_visible () const -> bool;

    auto
    set_badge_number (guint badge_number) -> void;

    auto
    set_icon_name (const glib::ustring& icon_name) -> void;

    auto
    set_name (const glib::ustring& name) -> void;

    auto
    set_needs_attention (bool needs_attention) -> void;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    set_use_underline (bool use_underline) -> void;

    auto
    set_visible (bool visible) -> void;

    auto
    property_badge_number () -> glib::PropertyProxy<guint>;

    auto
    property_badge_number () const -> glib::PropertyProxy_ReadOnly<guint>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_needs_attention () -> glib::PropertyProxy<bool>;

    auto
    property_needs_attention () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible () -> glib::PropertyProxy<bool>;

    auto
    property_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwViewStackPage* object, bool take_copy = false) -> glib::RefPtr<adw::view_stack_page>;
}

#endif
