// SPDX-License-Identifier: LGPL-2.1-or-later

#ifndef _LIBADWAITAMM_MESSAGEDIALOG_H
#define _LIBADWAITAMM_MESSAGEDIALOG_H

#include <libmm/adw/mm-adwconfig.hxx>

#include <libmm/glib/ustring.hxx>
#include <sigc++/sigc++.h>

#include <libmm/gtk/mm-gtk.hxx>

#ifndef DOXYGEN_SHOULD_SKIP_THIS
using AdwMessageDialog = struct _AdwMessageDialog;
using AdwMessageDialogClass = struct _AdwMessageDialogClass;
#endif

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace adw
{
  class LIBMM_ADW_SYMEXPORT MessageDialog_Class;
}
#endif

namespace adw
{

  enum class LIBMM_ADW_SYMEXPORT ResponseAppearance
  {
    DEFAULT,
    SUGGESTED,
    DESTRUCTIVE
  };

} // namespace adw

#ifndef DOXYGEN_SHOULD_SKIP_THIS
namespace glib
{

  template <>
  class LIBMM_ADW_SYMEXPORT Value<adw::ResponseAppearance>
    : public glib::Value_Enum<adw::ResponseAppearance>
  {
  public:
    static auto
    value_type () -> GType G_GNUC_CONST;
  };

} // namespace glib
#endif

namespace adw
{

  class LIBMM_ADW_SYMEXPORT MessageDialog : public gtk::Window
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
    explicit MessageDialog (const glib::ConstructParams& construct_params);
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
    explicit MessageDialog (gtk::Window* transient_for,
                            const glib::ustring& heading,
                            const glib::ustring& body);

    auto
    add_response (const glib::ustring& id, const glib::ustring& label) -> void;

    auto
    get_body () const -> glib::ustring;

    auto
    get_body_use_markup () const -> bool;

    auto
    get_close_response () const -> glib::ustring;

    auto
    get_default_response () const -> glib::ustring;

    auto
    get_extra_child () const -> gtk::Widget*;

    auto
    get_heading () const -> glib::ustring;

    auto
    get_heading_use_markup () const -> bool;

    auto
    get_response_appearance (const glib::ustring& response) const
        -> ResponseAppearance;

    auto
    get_response_enabled (const glib::ustring& response) const -> bool;

    auto
    get_response_label (const glib::ustring& response) const -> glib::ustring;

    auto
    has_response (const glib::ustring& response) const -> bool;

    auto
    response (const glib::ustring& response) -> void;

    auto
    set_body (const glib::ustring& body) -> void;

    auto
    set_body_use_markup (bool use_markup) -> void;

    auto
    set_close_response (const glib::ustring& response) -> void;

    auto
    set_default_response (const glib::ustring& response) -> void;

    auto
    set_extra_child (gtk::Widget* child) -> void;

    auto
    set_heading (const glib::ustring& heading) -> void;

    auto
    set_heading_use_markup (bool use_markup) -> void;

    auto
    set_response_appearance (const glib::ustring& response,
                             ResponseAppearance appearance) -> void;

    auto
    set_response_enabled (const glib::ustring& response, bool enabled) -> void;

    auto
    set_response_label (const glib::ustring& response,
                        const glib::ustring& label) -> void;

    auto
    property_body () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_body () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_body_use_markup () -> glib::PropertyProxy<bool>;

    auto
    property_body_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    property_close_response () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_close_response () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_default_response () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_default_response () const
        -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_extra_child () -> glib::PropertyProxy<gtk::Widget*>;

    auto
    property_extra_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>;

    auto
    property_heading () -> glib::PropertyProxy<glib::ustring>;

    auto
    property_heading () const -> glib::PropertyProxy_ReadOnly<glib::ustring>;

    auto
    property_heading_use_markup () -> glib::PropertyProxy<bool>;

    auto
    property_heading_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>;

    auto
    signal_response (const glib::ustring& response = {})
        -> glib::SignalProxyDetailed<void (const glib::ustring&)>;

    virtual auto
    response_vfunc (const glib::ustring& response) -> void;

  public:
  public:
  protected:
    virtual auto
    on_response (const glib::ustring& response) -> void;
  };

} // namespace adw

namespace glib
{

  auto
  wrap (AdwMessageDialog* object, bool take_copy = false) -> adw::MessageDialog*;
}

#endif
