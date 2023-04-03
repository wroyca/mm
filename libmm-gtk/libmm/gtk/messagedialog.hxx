// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _GTKMM_MESSAGEDIALOG_H
#define _GTKMM_MESSAGEDIALOG_H

#ifndef GTKMM_DISABLE_DEPRECATED

  #include <libmm/glib/ustring.hxx>
  #include <sigc++/sigc++.h>

  #include <libmm/gtk/dialog.hxx>
  #include <libmm/gtk/enums.hxx>

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
using GtkMessageDialog = struct _GtkMessageDialog;
using GtkMessageDialogClass = struct _GtkMessageDialogClass;
  #endif

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Gtk
{
  class LIBMM_GTK_SYMEXPORT MessageDialog_Class;
}
  #endif

namespace Gtk
{

  enum class ButtonsType
  {
    NONE,
    OK,
    CLOSE,
    CANCEL,
    YES_NO,
    OK_CANCEL
  };

} // namespace Gtk

  #ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class LIBMM_GTK_SYMEXPORT Value<Gtk::ButtonsType>
    : public Glib::Value_Enum<Gtk::ButtonsType>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
  #endif

namespace Gtk
{

  class LIBMM_GTK_SYMEXPORT MessageDialog : public Dialog
  {
  public:
  #ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef MessageDialog CppObjectType;
    typedef MessageDialog_Class CppClassType;
    typedef GtkMessageDialog BaseObjectType;
    typedef GtkMessageDialogClass BaseClassType;
  #endif

    MessageDialog (MessageDialog&& src) noexcept;
    auto
    operator= (MessageDialog&& src) noexcept -> MessageDialog&;

    MessageDialog (const MessageDialog&) = delete;
    auto
    operator= (const MessageDialog&) -> MessageDialog& = delete;

    ~MessageDialog () noexcept override;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

  private:
    friend LIBMM_GTK_SYMEXPORT class MessageDialog_Class;
    static CppClassType messagedialog_class_;

  protected:
    explicit MessageDialog (const Glib::ConstructParams& construct_params);
    explicit MessageDialog (GtkMessageDialog* castitem);

  #endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

  #ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
  #endif

    auto
    gobj () -> GtkMessageDialog*
    {
      return reinterpret_cast<GtkMessageDialog*> (gobject_);
    }

    auto
    gobj () const -> const GtkMessageDialog*
    {
      return reinterpret_cast<GtkMessageDialog*> (gobject_);
    }

  private:
  public:
    explicit MessageDialog (const Glib::ustring& message,
                            bool use_markup = false,
                            MessageType type = MessageType::INFO,
                            ButtonsType buttons = ButtonsType::OK,
                            bool modal = false);
    MessageDialog (Gtk::Window& parent,
                   const Glib::ustring& message,
                   bool use_markup = false,
                   MessageType type = MessageType::INFO,
                   ButtonsType buttons = ButtonsType::OK,
                   bool modal = false);

    auto
    set_message (const Glib::ustring& message, bool use_markup = false) -> void;

    auto
    set_secondary_text (const Glib::ustring& text, bool use_markup = false)
        -> void;

    auto
    get_message_area () -> Box*;

    auto
    get_message_area () const -> const Box*;

    auto
    property_message_type () -> Glib::PropertyProxy<MessageType>;

    auto
    property_message_type () const -> Glib::PropertyProxy_ReadOnly<MessageType>;

    auto
    property_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_text () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_use_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_secondary_text () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_secondary_text () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_secondary_use_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_secondary_use_markup () const
        -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_message_area () const -> Glib::PropertyProxy_ReadOnly<Box*>;

  public:
  public:
  protected:
  };

} // namespace Gtk

namespace Glib
{
  LIBMM_GTK_SYMEXPORT auto
  wrap (GtkMessageDialog* object, bool take_copy = false) -> Gtk::MessageDialog*;
} // namespace Glib

#endif

#endif
