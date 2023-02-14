
#ifndef _GTKMM_APPCHOOSER_H
#define _GTKMM_APPCHOOSER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/appinfo.hxx>
#include <libmm-glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkAppChooserIface GtkAppChooserIface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkAppChooser = struct _GtkAppChooser;
using GtkAppChooserClass = struct _GtkAppChooserClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API AppChooser_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API AppChooser : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = AppChooser;
    using CppClassType = AppChooser_Class;
    using BaseObjectType = GtkAppChooser;
    using BaseClassType = GtkAppChooserIface;

    AppChooser (const AppChooser&) = delete;
    auto
    operator= (const AppChooser&) -> AppChooser& = delete;

  private:
    friend class AppChooser_Class;
    static CppClassType appchooser_class_;

#endif
  protected:
    AppChooser ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit AppChooser (const Glib::Interface_Class& interface_class);

  public:
    explicit AppChooser (GtkAppChooser* castitem);

  protected:
#endif

  public:
    AppChooser (AppChooser&& src) noexcept;
    auto
    operator= (AppChooser&& src) noexcept -> AppChooser&;

    ~AppChooser () noexcept override;

    static void
    add_interface (GType gtype_implementer);

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkAppChooser*
    {
      return reinterpret_cast<GtkAppChooser*> (gobject_);
    }

    auto
    gobj () const -> const GtkAppChooser*
    {
      return reinterpret_cast<GtkAppChooser*> (gobject_);
    }

  private:
  public:
    auto
    get_app_info () -> Glib::RefPtr<Gio::AppInfo>;

    auto
    get_app_info () const -> Glib::RefPtr<const Gio::AppInfo>;

    auto
    get_content_type () const -> Glib::ustring;

    void
    refresh ();

    auto
    property_content_type () const
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
  wrap (GtkAppChooser* object, bool take_copy = false) -> Glib::RefPtr<Gtk::AppChooser>;

} // namespace Glib

#endif
