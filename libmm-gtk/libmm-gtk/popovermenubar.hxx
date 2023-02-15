// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_POPOVERMENUBAR_H
#define _GTKMM_POPOVERMENUBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/menumodel.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkPopoverMenuBar = struct _GtkPopoverMenuBar;
using GtkPopoverMenuBarClass = struct _GtkPopoverMenuBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT PopoverMenuBar_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT PopoverMenuBar : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef PopoverMenuBar CppObjectType;
    typedef PopoverMenuBar_Class CppClassType;
    typedef GtkPopoverMenuBar BaseObjectType;
    typedef GtkPopoverMenuBarClass BaseClassType;
#endif

    PopoverMenuBar (PopoverMenuBar&& src) noexcept;
    auto
    operator= (PopoverMenuBar&& src) noexcept -> PopoverMenuBar&;

    PopoverMenuBar (const PopoverMenuBar&) = delete;
    auto
    operator= (const PopoverMenuBar&) -> PopoverMenuBar& = delete;

    ~PopoverMenuBar () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class PopoverMenuBar_Class;
    static CppClassType popovermenubar_class_;

  protected:
    explicit PopoverMenuBar (const Glib::ConstructParams& construct_params);
    explicit PopoverMenuBar (GtkPopoverMenuBar* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkPopoverMenuBar*
    {
      return reinterpret_cast<GtkPopoverMenuBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkPopoverMenuBar*
    {
      return reinterpret_cast<GtkPopoverMenuBar*> (gobject_);
    }

  private:
  public:
    explicit PopoverMenuBar (
        const Glib::RefPtr<Gio::MenuModel>& menu_model = {});

    auto
    set_menu_model (const Glib::RefPtr<Gio::MenuModel>& model) -> void;

    auto
    get_menu_model () -> Glib::RefPtr<Gio::MenuModel>;

    auto
    get_menu_model () const -> Glib::RefPtr<const Gio::MenuModel>;

    auto
    add_child (Widget& child, const Glib::ustring& id) -> bool;

    auto
    remove_child (Widget& child) -> bool;

    auto
    property_menu_model () -> Glib::PropertyProxy<Glib::RefPtr<Gio::MenuModel>>;

    auto
    property_menu_model () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Gio::MenuModel>>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkPopoverMenuBar* object, bool take_copy = false) -> Gtk::PopoverMenuBar*;
} // namespace Glib

#endif
