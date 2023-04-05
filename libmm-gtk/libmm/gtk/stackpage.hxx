// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STACKPAGE_H
#define _GTKMM_STACKPAGE_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>
#include <libmm/glib/refptr.hxx>
#include <libmm/gtk/accessible.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkStackPage = struct _GtkStackPage;
using GtkStackPageClass = struct _GtkStackPageClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StackPage_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Widget;

  class LIBMM_GTK_SYMEXPORT StackPage : public glib::Object,
                              public Accessible
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StackPage;
    using CppClassType = StackPage_Class;
    using BaseObjectType = GtkStackPage;
    using BaseClassType = GtkStackPageClass;

    StackPage (const StackPage&) = delete;
    auto
    operator= (const StackPage&) -> StackPage& = delete;

  private:
    friend class StackPage_Class;
    static CppClassType stackpage_class_;

  protected:
    explicit StackPage (const glib::ConstructParams& construct_params);
    explicit StackPage (GtkStackPage* castitem);

#endif

  public:
    StackPage (StackPage&& src) noexcept;
    auto
    operator= (StackPage&& src) noexcept -> StackPage&;

    ~StackPage () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStackPage*
    {
      return reinterpret_cast<GtkStackPage*> (gobject_);
    }

    auto
    gobj () const -> const GtkStackPage*
    {
      return reinterpret_cast<GtkStackPage*> (gobject_);
    }

    auto
    gobj_copy () -> GtkStackPage*;

  private:
  public:
    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    get_visible () const -> bool;

    auto
    set_visible (bool visible = true) -> void;

    auto
    get_needs_attention () const -> bool;

    auto
    set_needs_attention (bool setting = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_use_underline (bool setting = true) -> void;

    auto
    get_name () const -> glib::ustring;

    auto
    set_name (const glib::ustring& setting) -> void;

    auto
    get_title () const -> glib::ustring;

    auto
    set_title (const glib::ustring& setting) -> void;

    auto
    get_icon_name () const -> glib::ustring;

    auto
    set_icon_name (const glib::ustring& setting) -> void;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_icon_name () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_icon_name () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_needs_attention () -> glib::PropertyProxy<bool>;

    auto
    property_needs_attention () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible () -> glib::PropertyProxy<bool>;

    auto
    property_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStackPage* object, bool take_copy = false) -> glib::RefPtr<gtk::StackPage>;
} // namespace glib

#endif
