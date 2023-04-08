// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/messagedialog.hxx>
#include <libmm/adw/messagedialog_p.hxx>

#include <adwaita.h>
#include <libmm/gtk/mm-gtk.hxx>

namespace adw
{

}

namespace
{

  static auto
  MessageDialog_signal_response_callback (AdwMessageDialog* self,
                                          const gchar* p0,
                                          void* data) -> void
  {
    using namespace adw;
    using SlotType = sigc::slot<void (const glib::ustring&)>;

    auto obj = dynamic_cast<MessageDialog*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }
  }

  static const glib::SignalProxyInfo MessageDialog_signal_response_info = {
      "response",
      (GCallback) &MessageDialog_signal_response_callback,
      (GCallback) &MessageDialog_signal_response_callback};

} // namespace

auto
glib::Value<adw::ResponseAppearance>::value_type () -> GType
{
  return adw_response_appearance_get_type ();
}

namespace glib
{

  auto
  wrap (AdwMessageDialog* object, bool take_copy) -> adw::MessageDialog*
  {
    return dynamic_cast<adw::MessageDialog*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace adw
{

  auto
  MessageDialog_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &MessageDialog_Class::class_init_function;

      register_derived_type (adw_message_dialog_get_type ());
    }

    return *this;
  }

  auto
  MessageDialog_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);

    klass->response = &response_vfunc_callback;

    klass->response = &response_callback;
  }

  auto
  MessageDialog_Class::response_vfunc_callback (AdwMessageDialog* self,
                                                const gchar* p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->response_vfunc (glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    BaseClassType* const base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->response)
      (*base->response) (self, p0);
  }

  auto
  MessageDialog_Class::response_callback (AdwMessageDialog* self,
                                          const gchar* p0) -> void
  {
    const auto obj_base = static_cast<glib::ObjectBase*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_response (glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->response)
      (*base->response) (self, p0);
  }

  auto
  MessageDialog_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return new MessageDialog ((AdwMessageDialog*) (o));
  }

  MessageDialog::MessageDialog (const glib::ConstructParams& construct_params)
    : gtk::Window (construct_params)
  {
  }

  MessageDialog::MessageDialog (AdwMessageDialog* castitem)
    : gtk::Window ((GtkWindow*) (castitem))
  {
  }

  MessageDialog::MessageDialog (MessageDialog&& src) noexcept
    : gtk::Window (std::move (src))
  {
  }

  auto
  MessageDialog::operator= (MessageDialog&& src) noexcept -> MessageDialog&
  {
    gtk::Window::operator= (std::move (src));
    return *this;
  }

  MessageDialog::~MessageDialog () noexcept
  {
    destroy_ ();
  }

  MessageDialog::CppClassType MessageDialog::messagedialog_class_;

  auto
  MessageDialog::get_type () -> GType
  {
    return messagedialog_class_.init ().get_type ();
  }

  auto
  MessageDialog::get_base_type () -> GType
  {
    return adw_message_dialog_get_type ();
  }

  MessageDialog::MessageDialog (gtk::Window* transient_for,
                                const glib::ustring& heading,
                                const glib::ustring& body)
    : glib::ObjectBase (nullptr),
      gtk::Window (
          glib::ConstructParams (messagedialog_class_.init (),
                                 "transient_for",
                                 (GtkWindow*) glib::unwrap (transient_for),
                                 "heading",
                                 heading.c_str (),
                                 "body",
                                 body.c_str (),
                                 nullptr))
  {
  }

  auto
  MessageDialog::add_response (const glib::ustring& id,
                               const glib::ustring& label) -> void
  {
    adw_message_dialog_add_response (gobj (), id.c_str (), label.c_str ());
  }

  auto
  MessageDialog::get_body () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_body (const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_body_use_markup () const -> bool
  {
    return adw_message_dialog_get_body_use_markup (
        const_cast<AdwMessageDialog*> (gobj ()));
  }

  auto
  MessageDialog::get_close_response () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_close_response (
            const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_default_response () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_default_response (
            const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_extra_child () const -> gtk::Widget*
  {
    return glib::wrap (adw_message_dialog_get_extra_child (
        const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_heading () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_heading (
            const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_heading_use_markup () const -> bool
  {
    return adw_message_dialog_get_heading_use_markup (
        const_cast<AdwMessageDialog*> (gobj ()));
  }

  auto
  MessageDialog::get_response_appearance (const glib::ustring& response) const -> ResponseAppearance
  {
    return static_cast<ResponseAppearance> (
        adw_message_dialog_get_response_appearance (
            const_cast<AdwMessageDialog*> (gobj ()),
            response.c_str ()));
  }

  auto
  MessageDialog::get_response_enabled (const glib::ustring& response) const -> bool
  {
    return adw_message_dialog_get_response_enabled (
        const_cast<AdwMessageDialog*> (gobj ()),
        response.c_str ());
  }

  auto
  MessageDialog::get_response_label (const glib::ustring& response) const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_response_label (
            const_cast<AdwMessageDialog*> (gobj ()),
            response.c_str ()));
  }

  auto
  MessageDialog::has_response (const glib::ustring& response) const -> bool
  {
    return adw_message_dialog_has_response (
        const_cast<AdwMessageDialog*> (gobj ()),
        response.c_str ());
  }

  auto
  MessageDialog::response (const glib::ustring& response) -> void
  {
    adw_message_dialog_response (gobj (), response.c_str ());
  }

  auto
  MessageDialog::set_body (const glib::ustring& body) -> void
  {
    adw_message_dialog_set_body (gobj (), body.c_str ());
  }

  auto
  MessageDialog::set_body_use_markup (bool use_markup) -> void
  {
    adw_message_dialog_set_body_use_markup (gobj (),
                                            static_cast<int> (use_markup));
  }

  auto
  MessageDialog::set_close_response (const glib::ustring& response) -> void
  {
    adw_message_dialog_set_close_response (gobj (), response.c_str ());
  }

  auto
  MessageDialog::set_default_response (const glib::ustring& response) -> void
  {
    adw_message_dialog_set_default_response (gobj (), response.c_str ());
  }

  auto
  MessageDialog::set_extra_child (gtk::Widget* child) -> void
  {
    adw_message_dialog_set_extra_child (gobj (),
                                        (GtkWidget*) glib::unwrap (child));
  }

  auto
  MessageDialog::set_heading (const glib::ustring& heading) -> void
  {
    adw_message_dialog_set_heading (gobj (), heading.c_str ());
  }

  auto
  MessageDialog::set_heading_use_markup (bool use_markup) -> void
  {
    adw_message_dialog_set_heading_use_markup (gobj (),
                                               static_cast<int> (use_markup));
  }

  auto
  MessageDialog::set_response_appearance (const glib::ustring& response,
                                          ResponseAppearance appearance) -> void
  {
    adw_message_dialog_set_response_appearance (
        gobj (),
        response.c_str (),
        static_cast<AdwResponseAppearance> (appearance));
  }

  auto
  MessageDialog::set_response_enabled (const glib::ustring& response,
                                       bool enabled) -> void
  {
    adw_message_dialog_set_response_enabled (gobj (),
                                             response.c_str (),
                                             static_cast<int> (enabled));
  }

  auto
  MessageDialog::set_response_label (const glib::ustring& response,
                                     const glib::ustring& label) -> void
  {
    adw_message_dialog_set_response_label (gobj (),
                                           response.c_str (),
                                           label.c_str ());
  }

  auto
  MessageDialog::signal_response (const glib::ustring& response) -> glib::SignalProxyDetailed<void (const glib::ustring&)>
  {
    return glib::SignalProxyDetailed<void (const glib::ustring&)> (
        this,
        &MessageDialog_signal_response_info,
        response);
  }

  auto
  MessageDialog::property_body () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "body"};
  }

  auto
  MessageDialog::property_body () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "body"};
  }

  auto
  MessageDialog::property_body_use_markup () -> glib::PropertyProxy<bool>
  {
    return {this, "body-use-markup"};
  }

  auto
  MessageDialog::property_body_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "body-use-markup"};
  }

  auto
  MessageDialog::property_close_response () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "close-response"};
  }

  auto
  MessageDialog::property_close_response () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "close-response"};
  }

  auto
  MessageDialog::property_default_response () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "default-response"};
  }

  auto
  MessageDialog::property_default_response () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "default-response"};
  }

  auto
  MessageDialog::property_extra_child () -> glib::PropertyProxy<gtk::Widget*>
  {
    return {this, "extra-child"};
  }

  auto
  MessageDialog::property_extra_child () const -> glib::PropertyProxy_ReadOnly<gtk::Widget*>
  {
    return {this, "extra-child"};
  }

  auto
  MessageDialog::property_heading () -> glib::PropertyProxy<glib::ustring>
  {
    return {this, "heading"};
  }

  auto
  MessageDialog::property_heading () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return {this, "heading"};
  }

  auto
  MessageDialog::property_heading_use_markup () -> glib::PropertyProxy<bool>
  {
    return {this, "heading-use-markup"};
  }

  auto
  MessageDialog::property_heading_use_markup () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return {this, "heading-use-markup"};
  }

  auto
  adw::MessageDialog::on_response (const glib::ustring& response) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->response)
      (*base->response) (gobj (), response.c_str ());
  }

  auto
  adw::MessageDialog::response_vfunc (const glib::ustring& response) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->response)
    {
      (*base->response) (gobj (), response.c_str ());
    }
  }

} // namespace adw
