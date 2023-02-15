// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CONSTRAINTLAYOUT_H
#define _GTKMM_CONSTRAINTLAYOUT_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gio/listmodel.hxx>
#include <libmm-gtk/buildable.hxx>
#include <libmm-gtk/constraint.hxx>
#include <libmm-gtk/constraintguide.hxx>
#include <libmm-gtk/layoutmanager.hxx>
#include <map>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ConstraintLayout_Class;
}
#endif

namespace Gtk
{
  class ConstraintVflParserError : public Glib::Error
  {
  public:
    enum Code
    {
      INVALID_SYMBOL,
      INVALID_ATTRIBUTE,
      INVALID_VIEW,
      INVALID_METRIC,
      INVALID_PRIORITY,
      INVALID_RELATION
    };

    GTKMM_API
    ConstraintVflParserError (Code error_code,
                              const Glib::ustring& error_message);
    GTKMM_API explicit ConstraintVflParserError (GError* gobject);
    GTKMM_API auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    GTKMM_API static auto
    throw_func (GError* gobject) -> void;

    friend GTKMM_API auto
    wrap_init () -> void;

#endif
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::ConstraintVflParserError::Code>
    : public Glib::Value_Enum<Gtk::ConstraintVflParserError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
{

  class GTKMM_API ConstraintLayout : public LayoutManager,
                                     public Buildable
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = ConstraintLayout;
    using CppClassType = ConstraintLayout_Class;
    using BaseObjectType = GtkConstraintLayout;
    using BaseClassType = GtkConstraintLayoutClass;

    ConstraintLayout (const ConstraintLayout&) = delete;
    auto
    operator= (const ConstraintLayout&) -> ConstraintLayout& = delete;

  private:
    friend class ConstraintLayout_Class;
    static CppClassType constraintlayout_class_;

  protected:
    explicit ConstraintLayout (const Glib::ConstructParams& construct_params);
    explicit ConstraintLayout (GtkConstraintLayout* castitem);

#endif

  public:
    ConstraintLayout (ConstraintLayout&& src) noexcept;
    auto
    operator= (ConstraintLayout&& src) noexcept -> ConstraintLayout&;

    ~ConstraintLayout () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkConstraintLayout*
    {
      return reinterpret_cast<GtkConstraintLayout*> (gobject_);
    }

    auto
    gobj () const -> const GtkConstraintLayout*
    {
      return reinterpret_cast<GtkConstraintLayout*> (gobject_);
    }

    auto
    gobj_copy () -> GtkConstraintLayout*;

  private:
  protected:
    ConstraintLayout ();

  public:
    static auto
    create () -> Glib::RefPtr<ConstraintLayout>;

    auto
    add_constraint (const Glib::RefPtr<Constraint>& constraint) -> void;

    auto
    remove_constraint (const Glib::RefPtr<Constraint>& constraint) -> void;

    auto
    remove_all_constraints () -> void;

    auto
    add_guide (const Glib::RefPtr<ConstraintGuide>& guide) -> void;

    auto
    remove_guide (const Glib::RefPtr<ConstraintGuide>& guide) -> void;

    using VFLmap = std::map<Glib::ustring, Glib::RefPtr<ConstraintTarget>>;

    auto
    add_constraints_from_description (const std::vector<Glib::ustring>& lines,
                                      int hspacing,
                                      int vspacing,
                                      const VFLmap& views)
        -> std::vector<Glib::RefPtr<Constraint>>;

    auto
    observe_constraints () -> Glib::RefPtr<Gio::ListModel>;

    auto
    observe_constraints () const -> Glib::RefPtr<const Gio::ListModel>;

    auto
    observe_guides () -> Glib::RefPtr<Gio::ListModel>;

    auto
    observe_guides () const -> Glib::RefPtr<const Gio::ListModel>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  GTKMM_API auto
  wrap (GtkConstraintLayout* object, bool take_copy = false) -> Glib::RefPtr<Gtk::ConstraintLayout>;
} // namespace Glib

#endif
