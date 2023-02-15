// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_LISTITEMFACTORY_H
#define _GTKMM_LISTITEMFACTORY_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkListItemFactory = struct _GtkListItemFactory;
using GtkListItemFactoryClass = struct _GtkListItemFactoryClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ListItemFactory_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ListItemFactory : public Glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ListItemFactory;
    using CppClassType = ListItemFactory_Class;
    using BaseObjectType = GtkListItemFactory;
    using BaseClassType = GtkListItemFactoryClass;

    ListItemFactory (const ListItemFactory&) = delete;
    auto
    operator= (const ListItemFactory&) -> ListItemFactory& = delete;

  private:
    friend class ListItemFactory_Class;
    static CppClassType listitemfactory_class_;

  protected:
    explicit ListItemFactory (const Glib::ConstructParams& construct_params);
    explicit ListItemFactory (GtkListItemFactory* castitem);

#endif

  public:
    ListItemFactory (ListItemFactory&& src) noexcept;
    auto
    operator= (ListItemFactory&& src) noexcept -> ListItemFactory&;

    ~ListItemFactory () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkListItemFactory*
    {
      return reinterpret_cast<GtkListItemFactory*> (gobject_);
    }

    auto
    gobj () const -> const GtkListItemFactory*
    {
      return reinterpret_cast<GtkListItemFactory*> (gobject_);
    }

    auto
    gobj_copy () -> GtkListItemFactory*;

  private:
  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkListItemFactory* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ListItemFactory>;
} // namespace Glib

#endif
