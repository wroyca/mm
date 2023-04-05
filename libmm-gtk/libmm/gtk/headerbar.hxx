// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_HEADERBAR_H
#define _GTKMM_HEADERBAR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkHeaderBar = struct _GtkHeaderBar;
using GtkHeaderBarClass = struct _GtkHeaderBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT HeaderBar_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT HeaderBar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef HeaderBar CppObjectType;
    typedef HeaderBar_Class CppClassType;
    typedef GtkHeaderBar BaseObjectType;
    typedef GtkHeaderBarClass BaseClassType;
#endif

    HeaderBar (HeaderBar&& src) noexcept;
    auto
    operator= (HeaderBar&& src) noexcept -> HeaderBar&;

    HeaderBar (const HeaderBar&) = delete;
    auto
    operator= (const HeaderBar&) -> HeaderBar& = delete;

    ~HeaderBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class HeaderBar_Class;
    static CppClassType headerbar_class_;

  protected:
    explicit HeaderBar (const glib::ConstructParams& construct_params);
    explicit HeaderBar (GtkHeaderBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkHeaderBar*
    {
      return reinterpret_cast<GtkHeaderBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkHeaderBar*
    {
      return reinterpret_cast<GtkHeaderBar*> (gobject_);
    }

  private:
  public:
    HeaderBar ();

    auto
    set_title_widget (gtk::Widget& title_widget) -> void;

    auto
    get_title_widget () -> Widget*;

    auto
    get_title_widget () const -> const Widget*;

    auto
    pack_start (gtk::Widget& child) -> void;

    auto
    pack_end (gtk::Widget& child) -> void;

    auto
    remove (gtk::Widget& child) -> void;

    auto
    set_show_title_buttons (bool setting = true) -> void;

    auto
    get_show_title_buttons () const -> bool;

    auto
    set_decoration_layout (const glib::ustring& layout) -> void;

    auto
    unset_decoration_layout () -> void;

    auto
    get_decoration_layout () const -> glib::ustring;

    auto
    property_title_widget () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_title_widget () const
        -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_show_title_buttons () -> glib::PropertyProxy<bool>;

    auto
    property_show_title_buttons () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_decoration_layout () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_decoration_layout () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkHeaderBar* object, bool take_copy = false) -> gtk::HeaderBar*;
} // namespace glib

#endif
