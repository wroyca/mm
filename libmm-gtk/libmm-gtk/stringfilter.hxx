
#ifndef _GTKMM_STRINGFILTER_H
#define _GTKMM_STRINGFILTER_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/expression.hxx>
#include <libmm-gtk/filter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API StringFilter_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API StringFilter : public Filter
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
    explicit StringFilter (const Glib::ConstructParams& construct_params);
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
        const Glib::RefPtr<Expression<Glib::ustring>>& expression);

  public:
    enum class MatchMode
    {
      EXACT,
      SUBSTRING,
      PREFIX
    };

    static auto
    create (const Glib::RefPtr<Expression<Glib::ustring>>& expression)
        -> Glib::RefPtr<StringFilter>;

    auto
    get_search () const -> Glib::ustring;

    void
    set_search (const Glib::ustring& search);

    auto
    get_expression () -> Glib::RefPtr<Expression<Glib::ustring>>;

    auto
    get_expression () const -> Glib::RefPtr<const Expression<Glib::ustring>>;

    void
    set_expression (const Glib::RefPtr<Expression<Glib::ustring>>& expression);

    auto
    get_ignore_case () const -> bool;

    void
    set_ignore_case (bool ignore_case = true);

    auto
    get_match_mode () const -> MatchMode;

    void
    set_match_mode (MatchMode mode);

    auto
    property_expression ()
        -> Glib::PropertyProxy<Glib::RefPtr<Expression<Glib::ustring>>>;

    auto
    property_expression () const -> Glib::PropertyProxy_ReadOnly<
        Glib::RefPtr<Expression<Glib::ustring>>>;

    auto
    property_ignore_case () -> Glib::PropertyProxy<bool>;

    auto
    property_ignore_case () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_match_mode () -> Glib::PropertyProxy<MatchMode>;

    auto
    property_match_mode () const -> Glib::PropertyProxy_ReadOnly<MatchMode>;

    auto
    property_search () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_search () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::StringFilter::MatchMode>
    : public Glib::Value_Enum<Gtk::StringFilter::MatchMode>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkStringFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StringFilter>;
} // namespace Glib

#endif
