// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CONSTRAINTGUIDE_H
#define _GTKMM_CONSTRAINTGUIDE_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/glib/object.hxx>
#include <libmm/gtk/constraint.hxx>
#include <libmm/gtk/constrainttarget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ConstraintGuide_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ConstraintGuide : public Glib::Object,
                                    public ConstraintTarget
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ConstraintGuide;
    using CppClassType = ConstraintGuide_Class;
    using BaseObjectType = GtkConstraintGuide;
    using BaseClassType = GtkConstraintGuideClass;

    ConstraintGuide (const ConstraintGuide&) = delete;
    auto
    operator= (const ConstraintGuide&) -> ConstraintGuide& = delete;

  private:
    friend class ConstraintGuide_Class;
    static CppClassType constraintguide_class_;

  protected:
    explicit ConstraintGuide (const Glib::ConstructParams& construct_params);
    explicit ConstraintGuide (GtkConstraintGuide* castitem);

#endif

  public:
    ConstraintGuide (ConstraintGuide&& src) noexcept;
    auto
    operator= (ConstraintGuide&& src) noexcept -> ConstraintGuide&;

    ~ConstraintGuide () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkConstraintGuide*
    {
      return reinterpret_cast<GtkConstraintGuide*> (gobject_);
    }

    auto
    gobj () const -> const GtkConstraintGuide*
    {
      return reinterpret_cast<GtkConstraintGuide*> (gobject_);
    }

    auto
    gobj_copy () -> GtkConstraintGuide*;

  private:
  protected:
    ConstraintGuide ();

  public:
    static auto
    create () -> Glib::RefPtr<ConstraintGuide>;

    auto
    set_min_size (int width, int height) -> void;

    auto
    get_min_size (int& width, int& height) const -> void;

    auto
    set_nat_size (int width, int height) -> void;

    auto
    get_nat_size (int& width, int& height) const -> void;

    auto
    set_max_size (int width, int height) -> void;

    auto
    get_max_size (int& width, int& height) const -> void;

    auto
    set_strength (Constraint::Strength strength) -> void;

    auto
    get_strength () const -> Constraint::Strength;

    auto
    set_name (const Glib::ustring& name) -> void;

    auto
    get_name () const -> Glib::ustring;

    auto
    property_min_width () -> Glib::PropertyProxy<int>;

    auto
    property_min_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_min_height () -> Glib::PropertyProxy<int>;

    auto
    property_min_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_nat_width () -> Glib::PropertyProxy<int>;

    auto
    property_nat_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_nat_height () -> Glib::PropertyProxy<int>;

    auto
    property_nat_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_width () -> Glib::PropertyProxy<int>;

    auto
    property_max_width () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_max_height () -> Glib::PropertyProxy<int>;

    auto
    property_max_height () const -> Glib::PropertyProxy_ReadOnly<int>;

    auto
    property_strength () -> Glib::PropertyProxy<Constraint::Strength>;

    auto
    property_strength () const
        -> Glib::PropertyProxy_ReadOnly<Constraint::Strength>;

    auto
    property_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_name () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkConstraintGuide* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ConstraintGuide>;
} // namespace Glib

#endif
