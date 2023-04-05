// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SEPARATOR_H
#define _GTKMM_SEPARATOR_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSeparator = struct _GtkSeparator;
using GtkSeparatorClass = struct _GtkSeparatorClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Separator_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Separator : public Widget,
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
    friend LIBMM_GTK_SYMEXPORT class Separator_Class;
    static CppClassType separator_class_;

  protected:
    explicit Separator (const glib::ConstructParams& construct_params);
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

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSeparator* object, bool take_copy = false) -> gtk::Separator*;
} // namespace glib

#endif
