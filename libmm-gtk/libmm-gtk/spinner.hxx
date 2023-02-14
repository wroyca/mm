
#ifndef _GTKMM_SPINNER_H
#define _GTKMM_SPINNER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSpinner = struct _GtkSpinner;
using GtkSpinnerClass = struct _GtkSpinnerClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Spinner_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Spinner : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Spinner CppObjectType;
    typedef Spinner_Class CppClassType;
    typedef GtkSpinner BaseObjectType;
    typedef GtkSpinnerClass BaseClassType;
#endif

    Spinner (Spinner&& src) noexcept;
    auto
    operator= (Spinner&& src) noexcept -> Spinner&;

    Spinner (const Spinner&) = delete;
    auto
    operator= (const Spinner&) -> Spinner& = delete;

    ~Spinner () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Spinner_Class;
    static CppClassType spinner_class_;

  protected:
    explicit Spinner (const Glib::ConstructParams& construct_params);
    explicit Spinner (GtkSpinner* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSpinner*
    {
      return reinterpret_cast<GtkSpinner*> (gobject_);
    }

    auto
    gobj () const -> const GtkSpinner*
    {
      return reinterpret_cast<GtkSpinner*> (gobject_);
    }

  private:
  public:
    Spinner ();

    void
    start ();

    void
    stop ();

    void
    set_spinning (bool spinning = true);

    auto
    get_spinning () const -> bool;

    auto
    property_spinning () -> Glib::PropertyProxy<bool>;

    auto
    property_spinning () const -> Glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkSpinner* object, bool take_copy = false) -> Gtk::Spinner*;
} // namespace Glib

#endif
