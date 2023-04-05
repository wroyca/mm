// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_STRINGSORTER_H
#define _GTKMM_STRINGSORTER_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/expression.hxx>
#include <libmm/gtk/sorter.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT StringSorter_Class;
}
#endif

namespace gtk
{

  enum class Collation
  {
    NONE,
    UNICODE,
    FILENAME
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Collation>
    : public glib::Value_Enum<gtk::Collation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT StringSorter : public Sorter
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = StringSorter;
    using CppClassType = StringSorter_Class;
    using BaseObjectType = GtkStringSorter;
    using BaseClassType = GtkStringSorterClass;

    StringSorter (const StringSorter&) = delete;
    auto
    operator= (const StringSorter&) -> StringSorter& = delete;

  private:
    friend class StringSorter_Class;
    static CppClassType stringsorter_class_;

  protected:
    explicit StringSorter (const glib::ConstructParams& construct_params);
    explicit StringSorter (GtkStringSorter* castitem);

#endif

  public:
    StringSorter (StringSorter&& src) noexcept;
    auto
    operator= (StringSorter&& src) noexcept -> StringSorter&;

    ~StringSorter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkStringSorter*
    {
      return reinterpret_cast<GtkStringSorter*> (gobject_);
    }

    auto
    gobj () const -> const GtkStringSorter*
    {
      return reinterpret_cast<GtkStringSorter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkStringSorter*;

  private:
  protected:
    explicit StringSorter (
        const glib::RefPtr<Expression<glib::ustring>>& expression);

  public:
    static auto
    create (const glib::RefPtr<Expression<glib::ustring>>& expression)
        -> glib::RefPtr<StringSorter>;

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
    set_collation (Collation collation) -> void;

    auto
    get_collation () const -> Collation;

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
    property_collation () -> glib::PropertyProxy<Collation>;

    auto
    property_collation () const -> glib::PropertyProxy_ReadOnly<Collation>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStringSorter* object, bool take_copy = false) -> glib::RefPtr<gtk::StringSorter>;
} // namespace glib

#endif
