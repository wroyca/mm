// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTSSECTION_H
#define _GTKMM_SHORTCUTSSECTION_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/box.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsSection = struct _GtkShortcutsSection;
using GtkShortcutsSectionClass = struct _GtkShortcutsSectionClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ShortcutsSection_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutsSection : public Box
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ShortcutsSection CppObjectType;
    typedef ShortcutsSection_Class CppClassType;
    typedef GtkShortcutsSection BaseObjectType;
    typedef GtkShortcutsSectionClass BaseClassType;
#endif

    ShortcutsSection (ShortcutsSection&& src) noexcept;
    auto
    operator= (ShortcutsSection&& src) noexcept -> ShortcutsSection&;

    ShortcutsSection (const ShortcutsSection&) = delete;
    auto
    operator= (const ShortcutsSection&) -> ShortcutsSection& = delete;

    ~ShortcutsSection () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ShortcutsSection_Class;
    static CppClassType shortcutssection_class_;

  protected:
    explicit ShortcutsSection (const Glib::ConstructParams& construct_params);
    explicit ShortcutsSection (GtkShortcutsSection* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutsSection*
    {
      return reinterpret_cast<GtkShortcutsSection*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutsSection*
    {
      return reinterpret_cast<GtkShortcutsSection*> (gobject_);
    }

  private:
  public:
    ShortcutsSection ();

    auto
    property_section_name () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_section_name () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_max_height () -> Glib::PropertyProxy<unsigned int>;

    auto
    property_max_height () const -> Glib::PropertyProxy_ReadOnly<unsigned int>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcutsSection* object, bool take_copy = false) -> Gtk::ShortcutsSection*;
} // namespace Glib

#endif
