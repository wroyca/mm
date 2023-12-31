// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTBASE_H
#define _GTKMM_LISTBASE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/orientable.hxx>
#include <libmm/gtk/scrollable.hxx>
#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListBase = struct _GtkListBase;
using GtkListBaseClass = struct _GtkListBaseClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ListBase_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ListBase : public Widget,
                             public Orientable,
                             public Scrollable
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ListBase CppObjectType;
    typedef ListBase_Class CppClassType;
    typedef GtkListBase BaseObjectType;
    typedef GtkListBaseClass BaseClassType;
#endif

    ListBase (ListBase&& src) noexcept;
    auto
    operator= (ListBase&& src) noexcept -> ListBase&;

    ListBase (const ListBase&) = delete;
    auto
    operator= (const ListBase&) -> ListBase& = delete;

    ~ListBase () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ListBase_Class;
    static CppClassType listbase_class_;

  protected:
    explicit ListBase (const glib::ConstructParams& construct_params);
    explicit ListBase (GtkListBase* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkListBase*
    {
      return reinterpret_cast<GtkListBase*> (gobject_);
    }

    auto
    gobj () const -> const GtkListBase*
    {
      return reinterpret_cast<GtkListBase*> (gobject_);
    }

  private:
  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkListBase* object, bool take_copy = false) -> gtk::ListBase*;
} // namespace glib

#endif
