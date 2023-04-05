// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_NATIVEDIALOG_H
#define _GTKMM_NATIVEDIALOG_H

#include <libmm/gtk/mm-gtkconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/glib/object.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkNativeDialog = struct _GtkNativeDialog;
using GtkNativeDialogClass = struct _GtkNativeDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT NativeDialog_Class;
}
#endif

namespace gtk
{
  class LIBMM_GTK_SYMEXPORT Window;

  class LIBMM_GTK_SYMEXPORT NativeDialog : public glib::Object
  {
#ifndef DOXYGEN_SHOULD_SKIP_THIS

  public:
    using CppObjectType = NativeDialog;
    using CppClassType = NativeDialog_Class;
    using BaseObjectType = GtkNativeDialog;
    using BaseClassType = GtkNativeDialogClass;

    NativeDialog (const NativeDialog&) = delete;
    auto
    operator= (const NativeDialog&) -> NativeDialog& = delete;

  private:
    friend class NativeDialog_Class;
    static CppClassType nativedialog_class_;

  protected:
    explicit NativeDialog (const glib::ConstructParams& construct_params);
    explicit NativeDialog (GtkNativeDialog* castitem);

#endif

  public:
    NativeDialog (NativeDialog&& src) noexcept;
    auto
    operator= (NativeDialog&& src) noexcept -> NativeDialog&;

    ~NativeDialog () noexcept override;

    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> GtkNativeDialog*
    {
      return reinterpret_cast<GtkNativeDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkNativeDialog*
    {
      return reinterpret_cast<GtkNativeDialog*> (gobject_);
    }

    auto
    gobj_copy () -> GtkNativeDialog*;

  private:
  protected:
    NativeDialog ();

  public:
    auto
    show () -> void;

    auto
    hide () -> void;

    auto
    get_visible () const -> bool;

    auto
    set_modal (bool modal = true) -> void;

    auto
    get_modal () const -> bool;

    auto
    set_title (const glib::ustring& title) -> void;

    auto
    get_title () const -> glib::ustring;

    auto
    set_transient_for (Window& parent) -> void;

    auto
    unset_transient_for () -> void;

    auto
    get_transient_for () -> Window*;

    auto
    get_transient_for () const -> const Window*;

    auto
    property_title () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_title () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_modal () -> glib::PropertyProxy<bool>;

    auto
    property_modal () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_visible () -> glib::PropertyProxy<bool>;

    auto
    property_visible () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_transient_for () -> glib::PropertyProxy<Window*>;

    auto
    property_transient_for () const -> glib::PropertyProxy_ReadOnly<Window*>;

    auto
    signal_response () -> glib::SignalProxy<void (int)>;

  public:
  public:
  protected:
    virtual auto
    on_response (int response_id) -> void;
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkNativeDialog* object, bool take_copy = false) -> glib::RefPtr<gtk::NativeDialog>;
} // namespace glib

#endif
