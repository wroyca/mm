// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SIGNALLISTITEMFACTORY_H
#define _GTKMM_SIGNALLISTITEMFACTORY_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/listitem.hxx>
#include <libmm/gtk/listitemfactory.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkSignalListItemFactory = struct _GtkSignalListItemFactory;
using GtkSignalListItemFactoryClass = struct _GtkSignalListItemFactoryClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT SignalListItemFactory_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT SignalListItemFactory : public ListItemFactory
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = SignalListItemFactory;
    using CppClassType = SignalListItemFactory_Class;
    using BaseObjectType = GtkSignalListItemFactory;
    using BaseClassType = GtkSignalListItemFactoryClass;

    SignalListItemFactory (const SignalListItemFactory&) = delete;
    auto
    operator= (const SignalListItemFactory&) -> SignalListItemFactory& = delete;

  private:
    friend class SignalListItemFactory_Class;
    static CppClassType signallistitemfactory_class_;

  protected:
    explicit SignalListItemFactory (
        const glib::ConstructParams& construct_params);
    explicit SignalListItemFactory (GtkSignalListItemFactory* castitem);

#endif

  public:
    SignalListItemFactory (SignalListItemFactory&& src) noexcept;
    auto
    operator= (SignalListItemFactory&& src) noexcept -> SignalListItemFactory&;

    ~SignalListItemFactory () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkSignalListItemFactory*
    {
      return reinterpret_cast<GtkSignalListItemFactory*> (gobject_);
    }

    auto
    gobj () const -> const GtkSignalListItemFactory*
    {
      return reinterpret_cast<GtkSignalListItemFactory*> (gobject_);
    }

    auto
    gobj_copy () -> GtkSignalListItemFactory*;

  private:
  protected:
    SignalListItemFactory ();

  public:
    static auto
    create () -> glib::RefPtr<SignalListItemFactory>;

    auto
    signal_setup () -> glib::SignalProxy<void (const glib::RefPtr<ListItem>&)>;

    auto
    signal_bind () -> glib::SignalProxy<void (const glib::RefPtr<ListItem>&)>;

    auto
    signal_unbind () -> glib::SignalProxy<void (const glib::RefPtr<ListItem>&)>;

    auto
    signal_teardown ()
        -> glib::SignalProxy<void (const glib::RefPtr<ListItem>&)>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkSignalListItemFactory* object, bool take_copy = false) -> glib::RefPtr<gtk::SignalListItemFactory>;
} // namespace glib

#endif
