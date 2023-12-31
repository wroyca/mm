// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_BOOLFILTER_H
#define _GTKMM_BOOLFILTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/expression.hxx>
#include <libmm/gtk/filter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT BoolFilter_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT BoolFilter : public Filter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = BoolFilter;
    using CppClassType = BoolFilter_Class;
    using BaseObjectType = GtkBoolFilter;
    using BaseClassType = GtkBoolFilterClass;

    BoolFilter (const BoolFilter&) = delete;
    auto
    operator= (const BoolFilter&) -> BoolFilter& = delete;

  private:
    friend class BoolFilter_Class;
    static CppClassType boolfilter_class_;

  protected:
    explicit BoolFilter (const glib::ConstructParams& construct_params);
    explicit BoolFilter (GtkBoolFilter* castitem);

#endif

  public:
    BoolFilter (BoolFilter&& src) noexcept;
    auto
    operator= (BoolFilter&& src) noexcept -> BoolFilter&;

    ~BoolFilter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkBoolFilter*
    {
      return reinterpret_cast<GtkBoolFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkBoolFilter*
    {
      return reinterpret_cast<GtkBoolFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkBoolFilter*;

  private:
  protected:
    explicit BoolFilter (const glib::RefPtr<Expression<bool>>& expression);

  public:
    static auto
    create (const glib::RefPtr<Expression<bool>>& expression)
        -> glib::RefPtr<BoolFilter>;

    auto
    get_expression () -> glib::RefPtr<Expression<bool>>;

    auto
    get_expression () const -> glib::RefPtr<const Expression<bool>>;

    auto
    set_expression (const glib::RefPtr<Expression<bool>>& expression) -> void;

    auto
    get_invert () const -> bool;

    auto
    set_invert (bool invert = true) -> void;

    auto
    property_expression ()
        -> glib::PropertyProxy<glib::RefPtr<Expression<bool>>>;

    auto
    property_expression () const
        -> glib::PropertyProxy_ReadOnly<glib::RefPtr<Expression<bool>>>;

    auto
    property_invert () -> glib::PropertyProxy<bool>;

    auto
    property_invert () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkBoolFilter* object, bool take_copy = false) -> glib::RefPtr<gtk::BoolFilter>;
} // namespace glib

#endif
