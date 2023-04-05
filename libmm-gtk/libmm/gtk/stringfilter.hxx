// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STRINGFILTER_H
#define _GTKMM_STRINGFILTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/expression.hxx>
#include <libmm/gtk/filter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StringFilter_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StringFilter : public Filter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StringFilter;
    using CppClassType = StringFilter_Class;
    using BaseObjectType = GtkStringFilter;
    using BaseClassType = GtkStringFilterClass;

    StringFilter (const StringFilter&) = delete;
    auto
    operator= (const StringFilter&) -> StringFilter& = delete;

  private:
    friend class StringFilter_Class;
    static CppClassType stringfilter_class_;

  protected:
    explicit StringFilter (const glib::ConstructParams& construct_params);
    explicit StringFilter (GtkStringFilter* castitem);

#endif

  public:
    StringFilter (StringFilter&& src) noexcept;
    auto
    operator= (StringFilter&& src) noexcept -> StringFilter&;

    ~StringFilter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStringFilter*
    {
      return reinterpret_cast<GtkStringFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkStringFilter*
    {
      return reinterpret_cast<GtkStringFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkStringFilter*;

  private:
  protected:
    explicit StringFilter (
        const glib::RefPtr<Expression<glib::ustring>>& expression);

  public:
    enum class MatchMode
    {
      EXACT,
      SUBSTRING,
      PREFIX
    };

    static auto
    create (const glib::RefPtr<Expression<glib::ustring>>& expression)
        -> glib::RefPtr<StringFilter>;

    auto
    get_search () const -> glib::ustring;

    auto
    set_search (const glib::ustring& search) -> void;

    auto
    get_expression () -> glib::RefPtr<Expression<glib::ustring>>;

    auto
    get_expression () const -> glib::RefPtr<const Expression<glib::ustring>>;

    auto
    set_expression (const glib::RefPtr<Expression<glib::ustring>>& expression)
        -> void;

    auto
    get_ignore_case () const -> bool;

    auto
    set_ignore_case (bool ignore_case = true) -> void;

    auto
    get_match_mode () const -> MatchMode;

    auto
    set_match_mode (MatchMode mode) -> void;

    auto
    property_expression ()
        -> glib::PropertyProxy<glib::RefPtr<Expression<glib::ustring>>>;

    auto
    property_expression () const -> glib::PropertyProxy_ReadOnly<
        glib::RefPtr<Expression<glib::ustring>>>;

    auto
    property_ignore_case () -> glib::PropertyProxy<bool>;

    auto
    property_ignore_case () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_match_mode () -> glib::PropertyProxy<MatchMode>;

    auto
    property_match_mode () const -> glib::PropertyProxy_ReadOnly<MatchMode>;

    auto
    property_search () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_search () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::StringFilter::MatchMode>
    : public glib::Value_Enum<gtk::StringFilter::MatchMode>
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
  wrap (GtkStringFilter* object, bool take_copy = false) -> glib::RefPtr<gtk::StringFilter>;
} // namespace glib

#endif
