
#ifndef _GTKMM_SEPARATOR_H
#define _GTKMM_SEPARATOR_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/orientable.hxx>
#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSeparator = struct _GtkSeparator;
using GtkSeparatorClass = struct _GtkSeparatorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Separator_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Separator : public Widget,
                              public Orientable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef Separator CppObjectType;
    typedef Separator_Class CppClassType;
    typedef GtkSeparator BaseObjectType;
    typedef GtkSeparatorClass BaseClassType;
#endif

    Separator (Separator&& src) noexcept;
    auto
    operator= (Separator&& src) noexcept -> Separator&;

    Separator (const Separator&) = delete;
    auto
    operator= (const Separator&) -> Separator& = delete;

    ~Separator () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class Separator_Class;
    static CppClassType separator_class_;

  protected:
    explicit Separator (const Glib::ConstructParams& construct_params);
    explicit Separator (GtkSeparator* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSeparator*
    {
      return reinterpret_cast<GtkSeparator*> (gobject_);
    }

    auto
    gobj () const -> const GtkSeparator*
    {
      return reinterpret_cast<GtkSeparator*> (gobject_);
    }

  private:
  public:
    explicit Separator (Orientation orientation = Orientation::HORIZONTAL);

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkSeparator* object, bool take_copy = false) -> Gtk::Separator*;
} // namespace Glib

#endif
