
#ifndef _GTKMM_EXPANDER_H
#define _GTKMM_EXPANDER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkExpander = struct _GtkExpander;
using GtkExpanderClass = struct _GtkExpanderClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Expander_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Expander : public Widget
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
    friend GTKMM_API class Expander_Class;
    static CppClassType expander_class_;

  protected:
    explicit Expander (const Glib::ConstructParams& construct_params);
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

    explicit Expander (const Glib::ustring& label, bool mnemonic = false);

    void
    set_expanded (bool expanded = true);

    auto
    get_expanded () const -> bool;

    void
    set_label (const Glib::ustring& label);

    auto
    get_label () const -> Glib::ustring;

    void
    set_use_underline (bool use_underline = true);

    auto
    get_use_underline () const -> bool;

    void
    set_use_markup (bool use_markup = true);

    auto
    get_use_markup () const -> bool;

    void
    set_label_widget (Widget& label_widget);

    auto
    get_label_widget () -> Widget*;

    auto
    get_label_widget () const -> const Widget*;

    void
    set_resize_toplevel (bool resize_toplevel = true);

    auto
    get_resize_toplevel () const -> bool;

    void
    set_child (Widget& child);
    void
    unset_child ();

    auto
    get_child () -> Widget*;

    auto
    get_child () const -> const Widget*;

    auto
    property_expanded () -> Glib::PropertyProxy<bool>;

    auto
    property_expanded () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_label () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_label () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_use_underline () -> Glib::PropertyProxy<bool>;

    auto
    property_use_underline () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_use_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_label_widget () -> Glib::PropertyProxy<Widget*>;

    auto
    property_label_widget () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

    auto
    property_resize_toplevel () -> Glib::PropertyProxy<bool>;

    auto
    property_resize_toplevel () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_child () -> Glib::PropertyProxy<Widget*>;

    auto
    property_child () const -> Glib::PropertyProxy_ReadOnly<Widget*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkExpander* object, bool take_copy = false) -> Gtk::Expander*;
} // namespace Glib

#endif
