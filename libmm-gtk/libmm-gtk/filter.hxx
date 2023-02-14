
#ifndef _GTKMM_FILTER_H
#define _GTKMM_FILTER_H

#include <libmm-gtk/mm-gtkconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <gtk/gtk.h>
#include <libmm-glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API Filter_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API Filter : public Glib::Object
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
    explicit Filter (const Glib::ConstructParams& construct_params);
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
    match (const Glib::RefPtr<Glib::ObjectBase>& item) -> bool;

    auto
    get_strictness () -> Match;

    auto
    signal_changed () -> Glib::SignalProxy<void (Change)>;

  protected:
    void
    changed (Change change = Change::DIFFERENT);

    virtual auto
    match_vfunc (const Glib::RefPtr<Glib::ObjectBase>& item) -> bool;

    virtual auto
    get_strictness_vfunc () -> Match;

  public:
  public:
  protected:
  };

} // namespace Gtk

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Filter::Match>
    : public Glib::Value_Enum<Gtk::Filter::Match>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class GTKMM_API Value<Gtk::Filter::Change>
    : public Glib::Value_Enum<Gtk::Filter::Change>
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
  wrap (GtkFilter* object, bool take_copy = false) -> Glib::RefPtr<Gtk::Filter>;
} // namespace Glib

#endif
