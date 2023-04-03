// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_ACTIONABLE_H
#define _GTKMM_ACTIONABLE_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkActionableInterface GtkActionableInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkActionable = struct _GtkActionable;
using GtkActionableClass = struct _GtkActionableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT Actionable_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT Actionable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Actionable;
    using CppClassType = Actionable_Class;
    using BaseObjectType = GtkActionable;
    using BaseClassType = GtkActionableInterface;

    Actionable (const Actionable&) = delete;
    auto
    operator= (const Actionable&) -> Actionable& = delete;

  private:
    friend class Actionable_Class;
    static CppClassType actionable_class_;

#endif
  protected:
    Actionable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Actionable (const Glib::Interface_Class& interface_class);

  public:
    explicit Actionable (GtkActionable* castitem);

  protected:
#endif

  public:
    Actionable (Actionable&& src) noexcept;
    auto
    operator= (Actionable&& src) noexcept -> Actionable&;

    ~Actionable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkActionable*
    {
      return reinterpret_cast<GtkActionable*> (gobject_);
    }

    auto
    gobj () const -> const GtkActionable*
    {
      return reinterpret_cast<GtkActionable*> (gobject_);
    }

  private:
  public:
    auto
    get_action_name () const -> Glib::ustring;

    auto
    set_action_name (const Glib::ustring& action_name) -> void;

    auto
    get_action_target_value () -> Glib::VariantBase;

    auto
    get_action_target_value () const -> const Glib::VariantBase;

    auto
    set_action_target_value (const Glib::VariantBase& target_value) -> void;

    auto
    set_detailed_action_name (const Glib::ustring& detailed_action_name)
        -> void;

    auto
    property_action_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_action_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_action_target () -> Glib::PropertyProxy<Glib::VariantBase>;

    auto
    property_action_target () const
        -> Glib::PropertyProxy_ReadOnly<Glib::VariantBase>;

  protected:
    virtual auto
    get_action_name_vfunc () const -> Glib::ustring;

    virtual auto
    set_action_name_vfunc (const Glib::ustring& action_name) -> void;

    virtual auto
    get_action_target_value_vfunc () const -> Glib::VariantBase;

    virtual auto
    set_action_target_value_vfunc (
        const Glib::VariantBase& action_target_value) -> void;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkActionable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Actionable>;

} // namespace Glib

#endif
