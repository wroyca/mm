// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_SHORTCUTLABEL_H
#define _GTKMM_SHORTCUTLABEL_H

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/widget.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkShortcutLabel = struct _GtkShortcutLabel;
using GtkShortcutLabelClass = struct _GtkShortcutLabelClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT ShortcutLabel_Class;
}
#endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT ShortcutLabel : public Widget
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
    friend LIBMM_GTK_SYMEXPORT class ShortcutLabel_Class;
    static CppClassType shortcutlabel_class_;

  protected:
    explicit ShortcutLabel (const glib::ConstructParams& construct_params);
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

    explicit ShortcutLabel (const glib::ustring& accelerator);

    auto
    get_accelerator () const -> glib::ustring;

    auto
    set_accelerator (const glib::ustring& accelerator) -> void;

    auto
    get_disabled_text () const -> glib::ustring;

    auto
    set_disabled_text (const glib::ustring& disabled_text) -> void;

    auto
    property_accelerator () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_accelerator () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_disabled_text () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_disabled_text () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkShortcutLabel* object, bool take_copy = false) -> gtk::ShortcutLabel*;
} // namespace glib

#endif
