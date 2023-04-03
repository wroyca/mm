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
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT StringSorter_Class;
}
#endif

namespace Gtk
{

  enum class Collation
  {
    NONE,
    UNICODE,
    FILENAME
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::Collation>
    : public Glib::Value_Enum<Gtk::Collation>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Gtk
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
    explicit StringSorter (const Glib::ConstructParams& construct_params);
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
        const Glib::RefPtr<Expression<Glib::ustring>>& expression);

  public:
    static auto
    create (const Glib::RefPtr<Expression<Glib::ustring>>& expression)
        -> Glib::RefPtr<StringSorter>;

    auto
    get_expression () -> Glib::RefPtr<Expression<Glib::ustring>>;

    auto
    get_expression () const -> Glib::RefPtr<const Expression<Glib::ustring>>;

    auto
    set_expression (const Glib::RefPtr<Expression<Glib::ustring>>& expression)
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
        -> Glib::PropertyProxy<Glib::RefPtr<Expression<Glib::ustring>>>;

    auto
    property_expression () const -> Glib::PropertyProxy_ReadOnly<
        Glib::RefPtr<Expression<Glib::ustring>>>;

    auto
    property_ignore_case () -> Glib::PropertyProxy<bool>;

    auto
    property_ignore_case () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_collation () -> Glib::PropertyProxy<Collation>;

    auto
    property_collation () const -> Glib::PropertyProxy_ReadOnly<Collation>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkStringSorter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::StringSorter>;
} // namespace Glib

#endif
