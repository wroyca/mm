// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_INFOBAR_H
#define _GTKMM_INFOBAR_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/button.hxx>
  #include <libmm/gtk/enums.hxx>
  #include <libmm/gtk/widget.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkInfoBar = struct _GtkInfoBar;
using GtkInfoBarClass = struct _GtkInfoBarClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace gtk
{
  class LIBMM_GTK_SYMEXPORT InfoBar_Class;
}
  #endif

namespace gtk
{

  class LIBMM_GTK_SYMEXPORT InfoBar : public Widget
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef InfoBar CppObjectType;
    typedef InfoBar_Class CppClassType;
    typedef GtkInfoBar BaseObjectType;
    typedef GtkInfoBarClass BaseClassType;
  #endif

    InfoBar (InfoBar&& src) noexcept;
    auto
    operator= (InfoBar&& src) noexcept -> InfoBar&;

    InfoBar (const InfoBar&) = delete;
    auto
    operator= (const InfoBar&) -> InfoBar& = delete;

    ~InfoBar () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class InfoBar_Class;
    static CppClassType infobar_class_;

  protected:
    explicit InfoBar (const glib::ConstructParams& construct_params);
    explicit InfoBar (GtkInfoBar* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkInfoBar*
    {
      return reinterpret_cast<GtkInfoBar*> (gobject_);
    }

    auto
    gobj () const -> const GtkInfoBar*
    {
      return reinterpret_cast<GtkInfoBar*> (gobject_);
    }

  private:
  public:
    InfoBar ();

    auto
    add_action_widget (Widget& child, int response_id) -> void;

    auto
    remove_action_widget (Widget& widget) -> void;

    auto
    add_button (const glib::ustring& button_text, int response_id) -> Button*;

    auto
    add_child (Widget& widget) -> void;

    auto
    remove_child (Widget& widget) -> void;

    auto
    set_response_sensitive (int response_id, bool setting = true) -> void;

    auto
    set_default_response (int response_id) -> void;

    auto
    response (int response_id) -> void;

    auto
    set_message_type (MessageType message_type) -> void;

    auto
    get_message_type () const -> MessageType;

    auto
    set_show_close_button (bool setting = true) -> void;

    auto
    get_show_close_button () const -> bool;

    auto
    set_revealed (bool revealed = true) -> void;

    auto
    get_revealed () const -> bool;

    auto
    signal_response () -> glib::SignalProxy<void (int)>;

    auto
    property_message_type () -> glib::PropertyProxy<MessageType>;

    auto
    property_message_type () const -> glib::PropertyProxy_ReadOnly<MessageType>;

    auto
    property_show_close_button () -> glib::PropertyProxy<bool>;

    auto
    property_show_close_button () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_revealed () -> glib::PropertyProxy<bool>;

    auto
    property_revealed () const -> glib::PropertyProxy_ReadOnly<bool>;

  public:
  public:
  protected:
  };

} // namespace gtk

namespace glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkInfoBar* object, bool take_copy = false) -> gtk::InfoBar*;
} // namespace glib

#endif

#endif
