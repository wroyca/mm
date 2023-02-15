// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTSGROUP_H
#define _GTKMM_SHORTCUTSGROUP_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/box.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutsGroup = struct _GtkShortcutsGroup;
using GtkShortcutsGroupClass = struct _GtkShortcutsGroupClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT ShortcutsGroup_Class;
}
#endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutsGroup : public Box
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ShortcutsGroup CppObjectType;
    typedef ShortcutsGroup_Class CppClassType;
    typedef GtkShortcutsGroup BaseObjectType;
    typedef GtkShortcutsGroupClass BaseClassType;
#endif

    ShortcutsGroup (ShortcutsGroup&& src) noexcept;
    auto
    operator= (ShortcutsGroup&& src) noexcept -> ShortcutsGroup&;

    ShortcutsGroup (const ShortcutsGroup&) = delete;
    auto
    operator= (const ShortcutsGroup&) -> ShortcutsGroup& = delete;

    ~ShortcutsGroup () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class ShortcutsGroup_Class;
    static CppClassType shortcutsgroup_class_;

  protected:
    explicit ShortcutsGroup (const Glib::ConstructParams& construct_params);
    explicit ShortcutsGroup (GtkShortcutsGroup* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutsGroup*
    {
      return reinterpret_cast<GtkShortcutsGroup*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutsGroup*
    {
      return reinterpret_cast<GtkShortcutsGroup*> (gobject_);
    }

  private:
  public:
    ShortcutsGroup ();

    auto
    unset_view () -> void;

    auto
    property_title () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_title () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_view () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_view () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcutsGroup* object, bool take_copy = false) -> Gtk::ShortcutsGroup*;
} // namespace Glib

#endif
