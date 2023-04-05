// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_CONSTRAINTLAYOUT_H
#define _GTKMM_CONSTRAINTLAYOUT_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gio/listmodel.hxx>
#include <libmm/gtk/buildable.hxx>
#include <libmm/gtk/constraint.hxx>
#include <libmm/gtk/constraintguide.hxx>
#include <libmm/gtk/layoutmanager.hxx>
#include <map>
#include <vector>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ConstraintLayout_Class;
}
#endif

namespace gtk
{
  class ConstraintVflParserError : public glib::Error
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

    LIBMM_GTK_SYMEXPORT
    ConstraintVflParserError (Code error_code,
                              const glib::ustring& error_message);
    LIBMM_GTK_SYMEXPORT explicit ConstraintVflParserError (GError* gobject);
    LIBMM_GTK_SYMEXPORT auto
    code () const -> Code;

#ifndef DOXYGEN_SHOULD_SKIP_THIS
  private:
    LIBMM_GTK_SYMEXPORT static auto
    throw_func (GError* gobject) -> void;

    friend LIBMM_GTK_SYMEXPORT auto
    wrap_init () -> void;

#endif
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::ConstraintVflParserError::Code>
    : public glib::Value_Enum<gtk::ConstraintVflParserError::Code>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ConstraintLayout : public LayoutManager,
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
    explicit ConstraintLayout (const glib::ConstructParams& construct_params);
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
    create () -> glib::RefPtr<ConstraintLayout>;

    auto
    add_constraint (const glib::RefPtr<Constraint>& constraint) -> void;

    auto
    remove_constraint (const glib::RefPtr<Constraint>& constraint) -> void;

    auto
    remove_all_constraints () -> void;

    auto
    add_guide (const glib::RefPtr<ConstraintGuide>& guide) -> void;

    auto
    remove_guide (const glib::RefPtr<ConstraintGuide>& guide) -> void;

    using VFLmap = std::map<glib::ustring, glib::RefPtr<ConstraintTarget>>;

    auto
    add_constraints_from_description (const std::vector<glib::ustring>& lines,
                                      int hspacing,
                                      int vspacing,
                                      const VFLmap& views)
        -> std::vector<glib::RefPtr<Constraint>>;

    auto
    observe_constraints () -> glib::RefPtr<gio::ListModel>;

    auto
    observe_constraints () const -> glib::RefPtr<const gio::ListModel>;

    auto
    observe_guides () -> glib::RefPtr<gio::ListModel>;

    auto
    observe_guides () const -> glib::RefPtr<const gio::ListModel>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkConstraintLayout* object, bool take_copy = false) -> glib::RefPtr<gtk::ConstraintLayout>;
} // namespace glib

#endif
