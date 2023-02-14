// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTLABEL_H
#define _GTKMM_SHORTCUTLABEL_H

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutLabel = struct _GtkShortcutLabel;
using GtkShortcutLabelClass = struct _GtkShortcutLabelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class GTKMM_API ShortcutLabel_Class;
}
#endif

namespace Gtk
{

  class GTKMM_API ShortcutLabel : public Widget
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef ShortcutLabel CppObjectType;
    typedef ShortcutLabel_Class CppClassType;
    typedef GtkShortcutLabel BaseObjectType;
    typedef GtkShortcutLabelClass BaseClassType;
#endif

    ShortcutLabel (ShortcutLabel&& src) noexcept;
    auto
    operator= (ShortcutLabel&& src) noexcept -> ShortcutLabel&;

    ShortcutLabel (const ShortcutLabel&) = delete;
    auto
    operator= (const ShortcutLabel&) -> ShortcutLabel& = delete;

    ~ShortcutLabel () noexcept override;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend GTKMM_API class ShortcutLabel_Class;
    static CppClassType shortcutlabel_class_;

  protected:
    explicit ShortcutLabel (const Glib::ConstructParams& construct_params);
    explicit ShortcutLabel (GtkShortcutLabel* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkShortcutLabel*
    {
      return reinterpret_cast<GtkShortcutLabel*> (gobject_);
    }

    auto
    gobj () const -> const GtkShortcutLabel*
    {
      return reinterpret_cast<GtkShortcutLabel*> (gobject_);
    }

  private:
  public:
    ShortcutLabel ();

    explicit ShortcutLabel (const Glib::ustring& accelerator);

    auto
    get_accelerator () const -> Glib::ustring;

    void
    set_accelerator (const Glib::ustring& accelerator);

    auto
    get_disabled_text () const -> Glib::ustring;

    void
    set_disabled_text (const Glib::ustring& disabled_text);

    auto
    property_accelerator () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_accelerator () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_disabled_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_disabled_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{

  GTKMM_API
  auto
  wrap (GtkShortcutLabel* object, bool take_copy = false) -> Gtk::ShortcutLabel*;
} // namespace Glib

#endif
