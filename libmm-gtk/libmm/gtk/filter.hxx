// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_FILTER_H
#define _GTKMM_FILTER_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Filter_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT Filter : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = Filter;
    using CppClassType = Filter_Class;
    using BaseObjectType = GtkFilter;
    using BaseClassType = GtkFilterClass;

    Filter (const Filter&) = delete;
    auto
    operator= (const Filter&) -> Filter& = delete;

  private:
    friend class Filter_Class;
    static CppClassType filter_class_;

  protected:
    explicit Filter (const glib::ConstructParams& construct_params);
    explicit Filter (GtkFilter* castitem);

#endif

  public:
    Filter (Filter&& src) noexcept;
    auto
    operator= (Filter&& src) noexcept -> Filter&;

    ~Filter () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkFilter*
    {
      return reinterpret_cast<GtkFilter*> (gobject_);
    }

    auto
    gobj () const -> const GtkFilter*
    {
      return reinterpret_cast<GtkFilter*> (gobject_);
    }

    auto
    gobj_copy () -> GtkFilter*;

  private:
  protected:
    Filter ();

  public:
    enum class Match
    {
      SOME,
      NONE,
      ALL
    };

    enum class Change
    {
      DIFFERENT,
      LESS_STRICT,
      MORE_STRICT
    };

    auto
    match (const glib::RefPtr<glib::ObjectBase>& item) -> bool;

    auto
    get_strictness () -> Match;

    auto
    signal_changed () -> glib::SignalProxy<void (Change)>;

  protected:
    auto
    changed (Change change = Change::DIFFERENT) -> void;

    virtual auto
    match_vfunc (const glib::RefPtr<glib::ObjectBase>& item) -> bool;

    virtual auto
    get_strictness_vfunc () -> Match;

  public:
  public:
  protected:
  };

} // namespace gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Filter::Match>
    : public glib::Value_Enum<gtk::Filter::Match>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<gtk::Filter::Change>
    : public glib::Value_Enum<gtk::Filter::Change>
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
  wrap (GtkFilter* object, bool take_copy = false) -> glib::RefPtr<gtk::Filter>;
} // namespace glib

#endif
