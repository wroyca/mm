// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SCROLLABLE_H
#define _GTKMM_SCROLLABLE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/interface.hxx>
#include <libmm/gtk/adjustment.hxx>
#include <libmm/gtk/border.hxx>
#include <libmm/gtk/enums.hxx>

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
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Scrollable_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Scrollable : public glib::Interface
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

    explicit Scrollable (const glib::Interface_Class& interface_class);

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
    get_hadjustment () -> glib::RefPtr<Adjustment>;

    auto
    get_hadjustment () const -> glib::RefPtr<const Adjustment>;

    auto
    set_hadjustment (const glib::RefPtr<Adjustment>& hadjustment) -> void;

    auto
    unset_hadjustment () -> void;

    auto
    get_vadjustment () -> glib::RefPtr<Adjustment>;

    auto
    get_vadjustment () const -> glib::RefPtr<const Adjustment>;

    auto
    set_vadjustment (const glib::RefPtr<Adjustment>& vadjustment) -> void;

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
    property_hadjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>;

    auto
    property_hadjustment () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>;

    auto
    property_vadjustment () -> glib::PropertyProxy<glib::RefPtr<Adjustment>>;

    auto
    property_vadjustment () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Adjustment>>;

    auto
    property_hscroll_policy () -> glib::PropertyProxy<Policy>;

    auto
    property_hscroll_policy () const -> glib::PropertyProxy_ReadOnly<Policy>;

    auto
    property_vscroll_policy () -> glib::PropertyProxy<Policy>;

    auto
    property_vscroll_policy () const -> glib::PropertyProxy_ReadOnly<Policy>;

  protected:
    virtual auto
    get_border_vfunc (Border& border) const -> bool;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Scrollable::Policy>
    : public glib::Value_Enum<gtk::Scrollable::Policy>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkScrollable* object, bool take_copy = false) -> glib::RefPtr<gtk::Scrollable>;

} // namespace glib

#endif
