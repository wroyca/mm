
#ifndef _GTKMM_HEADERBAR_H
#define _GTKMM_HEADERBAR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkHeaderBar = struct _GtkHeaderBar;
using GtkHeaderBarClass = struct _GtkHeaderBarClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API HeaderBar_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API HeaderBar : public Widget
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
    friend GTKMM_API class HeaderBar_Class;
    static CppClassType headerbar_class_;

  protected:
    explicit HeaderBar (const Glib::ConstructParams& construct_params);
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

    void
    set_title_widget (Gtk::Widget& title_widget);

    auto
    get_title_widget () -> Widget*;

    auto
    get_title_widget () const -> const Widget*;

    void
    pack_start (Gtk::Widget& child);

    void
    pack_end (Gtk::Widget& child);

    void
    remove (Gtk::Widget& child);

    void
    set_show_title_buttons (bool setting = true);

    auto
    get_show_title_buttons () const -> bool;

    void
    set_decoration_layout (const Glib::ustring& layout);

    void
    unset_decoration_layout ();

    auto
    get_decoration_layout () const -> Glib::ustring;

    auto
    property_title_widget () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_title_widget () const
        -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_show_title_buttons () -> Glib::PropertyProxy<bool>;

    auto
    property_show_title_buttons () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_decoration_layout () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_decoration_layout () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkHeaderBar* object, bool take_copy = false) -> Gtk::HeaderBar*;
} // namespace Glib

#endif
