// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ATCONTEXT_H
#define _GTKMM_ATCONTEXT_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gdk/display.hxx>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/accessible.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkATContext = struct _GtkATContext;
using GtkATContextClass = struct _GtkATContextClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ATContext_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ATContext : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ATContext;
    using CppClassType = ATContext_Class;
    using BaseObjectType = GtkATContext;
    using BaseClassType = GtkATContextClass;

    ATContext (const ATContext&) = delete;
    auto
    operator= (const ATContext&) -> ATContext& = delete;

  private:
    friend class ATContext_Class;
    static CppClassType atcontext_class_;

  protected:
    explicit ATContext (const glib::ConstructParams& construct_params);
    explicit ATContext (GtkATContext* castitem);

#endif

  public:
    ATContext (ATContext&& src) noexcept;
    auto
    operator= (ATContext&& src) noexcept -> ATContext&;

    ~ATContext () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkATContext*
    {
      return reinterpret_cast<GtkATContext*> (gobject_);
    }

    auto
    gobj () const -> const GtkATContext*
    {
      return reinterpret_cast<GtkATContext*> (gobject_);
    }

    auto
    gobj_copy () -> GtkATContext*;

  private:
  protected:
    ATContext ();

  public:
    static auto
    create (Accessible::Role accessible_role,
            const glib::RefPtr<Accessible>& accessible,
            const glib::RefPtr<gdk::Display>& display)
        -> glib::RefPtr<ATContext>;

    auto
    get_accessible () -> glib::RefPtr<Accessible>;

    auto
    get_accessible () const -> glib::RefPtr<const Accessible>;

    auto
    get_accessible_role () const -> Accessible::Role;

    auto
    property_accessible_role () -> glib::PropertyProxy<Accessible::Role>;

    auto
    property_accessible_role () const
        -> glib::PropertyProxy_ReadOnly<Accessible::Role>;

    auto
    property_accessible () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Accessible>>;

    auto
    property_display () -> glib::PropertyProxy<glib::RefPtr<gdk::Display>>;

    auto
    property_display () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<gdk::Display>>;

    auto
    signal_state_change () -> glib::SignalProxy<void ()>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkATContext* object, bool take_copy = false) -> glib::RefPtr<gtk::ATContext>;
} // namespace glib

#endif
