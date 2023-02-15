// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCROLLABLE_H
#define _GTKMM_SCROLLABLE_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-glib/interface.hxx>
#include <libmm-gtk/adjustment.hxx>
#include <libmm-gtk/border.hxx>
#include <libmm-gtk/enums.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern "C"
{
  typedef struct _GtkScrollableInterface GtkScrollableInterface;
}
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkScrollable = struct _GtkScrollable;
using GtkScrollableClass = struct _GtkScrollableClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Scrollable_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Scrollable : public Glib::Interface
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Scrollable;
    using CppClassType = Scrollable_Class;
    using BaseObjectType = GtkScrollable;
    using BaseClassType = GtkScrollableInterface;

    Scrollable (const Scrollable&) = delete;
    auto
    operator= (const Scrollable&) -> Scrollable& = delete;

  private:
    friend class Scrollable_Class;
    static CppClassType scrollable_class_;

#endif
  protected:
    Scrollable ();

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    explicit Scrollable (const Glib::Interface_Class& interface_class);

  public:
    explicit Scrollable (GtkScrollable* castitem);

  protected:
#endif

  public:
    Scrollable (Scrollable&& src) noexcept;
    auto
    operator= (Scrollable&& src) noexcept -> Scrollable&;

    ~Scrollable () noexcept override;

    static auto
    add_interface (GType gtype_implementer) -> void;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkScrollable*
    {
      return reinterpret_cast<GtkScrollable*> (gobject_);
    }

    auto
    gobj () const -> const GtkScrollable*
    {
      return reinterpret_cast<GtkScrollable*> (gobject_);
    }

  private:
  public:
    enum class Policy
    {
      MINIMUM,
      NATURAL
    };

    auto
    get_hadjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_hadjustment () const -> Glib::RefPtr<const Adjustment>;

    auto
    set_hadjustment (const Glib::RefPtr<Adjustment>& hadjustment) -> void;

    auto
    unset_hadjustment () -> void;

    auto
    get_vadjustment () -> Glib::RefPtr<Adjustment>;

    auto
    get_vadjustment () const -> Glib::RefPtr<const Adjustment>;

    auto
    set_vadjustment (const Glib::RefPtr<Adjustment>& vadjustment) -> void;

    auto
    unset_vadjustment () -> void;

    auto
    get_hscroll_policy () const -> Policy;

    auto
    set_hscroll_policy (Policy policy) -> void;

    auto
    get_vscroll_policy () const -> Policy;

    auto
    set_vscroll_policy (Policy policy) -> void;

    auto
    get_border (Border& border) const -> bool;

    auto
    property_hadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_hadjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_vadjustment () -> Glib::PropertyProxy<Glib::RefPtr<Adjustment>>;

    auto
    property_vadjustment () const
        -> Glib::PropertyProxy_ReadOnly<Glib::RefPtr<Adjustment>>;

    auto
    property_hscroll_policy () -> Glib::PropertyProxy<Policy>;

    auto
    property_hscroll_policy () const -> Glib::PropertyProxy_ReadOnly<Policy>;

    auto
    property_vscroll_policy () -> Glib::PropertyProxy<Policy>;

    auto
    property_vscroll_policy () const -> Glib::PropertyProxy_ReadOnly<Policy>;

  protected:
    virtual auto
    get_border_vfunc (Border& border) const -> bool;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Scrollable::Policy>
    : public Glib::Value_Enum<Gtk::Scrollable::Policy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{
  GTKMM_API auto
  wrap (GtkScrollable* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Scrollable>;

} // namespace Glib

#endif
