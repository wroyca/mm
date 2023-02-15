// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_MESSAGEDIALOG_H
#define _LIBADWAITAMM_MESSAGEDIALOG_H

#include <libmm-adw/mm-adwconfig.hxx>

#include <libmm-glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm-gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwMessageDialog = struct _AdwMessageDialog;
using AdwMessageDialogClass = struct _AdwMessageDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Adw
{
  class MessageDialog_Class;
}
#endif

namespace Adw
{

  enum class ResponseAppearance
  {
    DEFAULT,
    SUGGESTED,
    DESTRUCTIVE
  };

} // namespace Adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace Glib
{

  template <>
  class Value<Adw::ResponseAppearance>
    : public Glib::Value_Enum<Adw::ResponseAppearance>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace Glib
#endif

namespace Adw
{

  class MessageDialog : public Gtk::Window
  {
  public:
#ifndef DOXYGEN_SHOULD_SKIP_THIS
    typedef MessageDialog CppObjectType;
    typedef MessageDialog_Class CppClassType;
    typedef AdwMessageDialog BaseObjectType;
    typedef AdwMessageDialogClass BaseClassType;
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
    friend class MessageDialog_Class;
    static CppClassType messagedialog_class_;

  protected:
    explicit MessageDialog (const Glib::ConstructParams& construct_params);
    explicit MessageDialog (AdwMessageDialog* castitem);

#endif

  public:
    static auto
    get_type () -> GType G_GNUC_CONST;

#ifndef DOXYGEN_SHOULD_SKIP_THIS

    static auto
    get_base_type () -> GType G_GNUC_CONST;
#endif

    auto
    gobj () -> AdwMessageDialog*
    {
      return reinterpret_cast<AdwMessageDialog*> (gobject_);
    }

    auto
    gobj () const -> const AdwMessageDialog*
    {
      return reinterpret_cast<AdwMessageDialog*> (gobject_);
    }

  private:
  public:
    explicit MessageDialog (Gtk::Window* transient_for,
                            const Glib::ustring& heading,
                            const Glib::ustring& body);

    auto
    add_response (const Glib::ustring& id, const Glib::ustring& label) -> void;

    auto
    get_body () const -> Glib::ustring;

    auto
    get_body_use_markup () const -> bool;

    auto
    get_close_response () const -> Glib::ustring;

    auto
    get_default_response () const -> Glib::ustring;

    auto
    get_extra_child () const -> Gtk::Widget*;

    auto
    get_heading () const -> Glib::ustring;

    auto
    get_heading_use_markup () const -> bool;

    auto
    get_response_appearance (const Glib::ustring& response) const
        -> ResponseAppearance;

    auto
    get_response_enabled (const Glib::ustring& response) const -> bool;

    auto
    get_response_label (const Glib::ustring& response) const -> Glib::ustring;

    auto
    has_response (const Glib::ustring& response) const -> bool;

    auto
    response (const Glib::ustring& response) -> void;

    auto
    set_body (const Glib::ustring& body) -> void;

    auto
    set_body_use_markup (bool use_markup) -> void;

    auto
    set_close_response (const Glib::ustring& response) -> void;

    auto
    set_default_response (const Glib::ustring& response) -> void;

    auto
    set_extra_child (Gtk::Widget* child) -> void;

    auto
    set_heading (const Glib::ustring& heading) -> void;

    auto
    set_heading_use_markup (bool use_markup) -> void;

    auto
    set_response_appearance (const Glib::ustring& response,
                             ResponseAppearance appearance) -> void;

    auto
    set_response_enabled (const Glib::ustring& response, bool enabled) -> void;

    auto
    set_response_label (const Glib::ustring& response,
                        const Glib::ustring& label) -> void;

    auto
    property_body () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_body () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_body_use_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_body_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_close_response () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_close_response () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_default_response () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_default_response () const
        -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_extra_child () -> Glib::PropertyProxy<Gtk::Widget*>;

    auto
    property_extra_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>;

    auto
    property_heading () -> Glib::PropertyProxy<Glib::ustring>;

    auto
    property_heading () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>;

    auto
    property_heading_use_markup () -> Glib::PropertyProxy<bool>;

    auto
    property_heading_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_response (const Glib::ustring& response = {})
        -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>;

    virtual auto
    response_vfunc (const Glib::ustring& response) -> void;

  public:
  public:
  protected:
    virtual auto
    on_response (const Glib::ustring& response) -> void;
  };

} // namespace Adw

namespace Glib
{

  auto
  wrap (AdwMessageDialog* object, bool take_copy = false) -> Adw::MessageDialog*;
}

#endif
