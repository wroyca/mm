// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_EXPANDER_H
#define _GTKMM_EXPANDER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkExpander = struct _GtkExpander;
using GtkExpanderClass = struct _GtkExpanderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Expander_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Expander : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Expander CppObjectType;
    typedef Expander_Class CppClassType;
    typedef GtkExpander BaseObjectType;
    typedef GtkExpanderClass BaseClassType;
#endif

    Expander (Expander&& src) noexcept;
    auto
    operator= (Expander&& src) noexcept -> Expander&;

    Expander (const Expander&) = delete;
    auto
    operator= (const Expander&) -> Expander& = delete;

    ~Expander () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class Expander_Class;
    static CppClassType expander_class_;

  protected:
    explicit Expander (const glib::ConstructParams& construct_params);
    explicit Expander (GtkExpander* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkExpander*
    {
      return reinterpret_cast<GtkExpander*> (gobject_);
    }

    auto
    gobj () const -> const GtkExpander*
    {
      return reinterpret_cast<GtkExpander*> (gobject_);
    }

  private:
  public:
    Expander ();

    explicit Expander (const glib::ustring& label, bool mnemonic = false);

    auto
    set_expanded (bool expanded = true) -> void;

    auto
    get_expanded () const -> bool;

    auto
    set_label (const glib::ustring& label) -> void;

    auto
    get_label () const -> glib::ustring;

    auto
    set_use_underline (bool use_underline = true) -> void;

    auto
    get_use_underline () const -> bool;

    auto
    set_use_markup (bool use_markup = true) -> void;

    auto
    get_use_markup () const -> bool;

    auto
    set_label_widget (Widget& label_widget) -> void;

    auto
    get_label_widget () -> Widget*;

    auto
    get_label_widget () const -> const Widget*;

    auto
    set_resize_toplevel (bool resize_toplevel = true) -> void;

    auto
    get_resize_toplevel () const -> bool;

    auto
    set_child (Widget& child) -> void;
    auto
    unset_child () -> void;

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_expanded () -> glib::PropertyProxy<bool>;

    auto
    property_expanded () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_label () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_label () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_use_underline () -> glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_markup () -> glib::PropertyProxy<bool>;

    auto
    property_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_label_widget () -> glib::PropertyProxy<Widget*>;

    auto
    property_label_widget () const -> glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_resize_toplevel () -> glib::PropertyProxy<bool>;

    auto
    property_resize_toplevel () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkExpander* object, bool take_copy = false) -> gtk::Expander*;
} // namespace glib

#endif
