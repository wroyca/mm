// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/adw/messagedialog.hxx>
#include <libmm/adw/messagedialog_p.hxx>

#include <adwaita.h>
#include <libmm/gtk/mm-gtk.hxx>

namespace Adw
{

}

namespace
{

  static auto
  MessageDialog_signal_response_callback (AdwMessageDialog* self,
                                          const gchar* p0,
                                          void* data) -> void
  {
    using namespace Adw;
    using SlotType = sigc::slot<void (const Glib::ustring&)>;

    auto obj = dynamic_cast<MessageDialog*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = Glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) (
              Glib::convert_const_gchar_ptr_to_ustring (p0));
      }
      catch (...)
      {
        Glib::exception_handlers_invoke ();
      }
    }
  }

  static const Glib::SignalProxyInfo MessageDialog_signal_response_info = {
      "response",
      (GCallback) &MessageDialog_signal_response_callback,
      (GCallback) &MessageDialog_signal_response_callback};

} // namespace

auto
Glib::Value<Adw::ResponseAppearance>::value_type () -> GType
{
  return adw_response_appearance_get_type ();
}

namespace Glib
{

  auto
  wrap (AdwMessageDialog* object, bool take_copy) -> Adw::MessageDialog*
  {
    return dynamic_cast<Adw::MessageDialog*> (
        Glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace Glib

namespace Adw
{

  auto
  MessageDialog_Class::init () -> const Glib::Class&
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->response_vfunc (Glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
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
    const auto obj_base = static_cast<Glib::ObjectBase*> (
        Glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj_base && obj_base->is_derived_ ())
    {
      const auto obj = dynamic_cast<CppObjectType* const> (obj_base);
      if (obj)
      {
        try
        {
          obj->on_response (Glib::convert_const_gchar_ptr_to_ustring (p0));
          return;
        }
        catch (...)
        {
          Glib::exception_handlers_invoke ();
        }
      }
    }

    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (self)));

    if (base && base->response)
      (*base->response) (self, p0);
  }

  auto
  MessageDialog_Class::wrap_new (GObject* o) -> Glib::ObjectBase*
  {
    return new MessageDialog ((AdwMessageDialog*) (o));
  }

  MessageDialog::MessageDialog (const Glib::ConstructParams& construct_params)
    : Gtk::Window (construct_params)
  {
  }

  MessageDialog::MessageDialog (AdwMessageDialog* castitem)
    : Gtk::Window ((GtkWindow*) (castitem))
  {
  }

  MessageDialog::MessageDialog (MessageDialog&& src) noexcept
    : Gtk::Window (std::move (src))
  {
  }

  auto
  MessageDialog::operator= (MessageDialog&& src) noexcept -> MessageDialog&
  {
    Gtk::Window::operator= (std::move (src));
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

  MessageDialog::MessageDialog (Gtk::Window* transient_for,
                                const Glib::ustring& heading,
                                const Glib::ustring& body)
    : Glib::ObjectBase (nullptr),
      Gtk::Window (
          Glib::ConstructParams (messagedialog_class_.init (),
                                 "transient_for",
                                 (GtkWindow*) Glib::unwrap (transient_for),
                                 "heading",
                                 heading.c_str (),
                                 "body",
                                 body.c_str (),
                                 nullptr))
  {
  }

  auto
  MessageDialog::add_response (const Glib::ustring& id,
                               const Glib::ustring& label) -> void
  {
    adw_message_dialog_add_response (gobj (), id.c_str (), label.c_str ());
  }

  auto
  MessageDialog::get_body () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_body (const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_body_use_markup () const -> bool
  {
    return adw_message_dialog_get_body_use_markup (
        const_cast<AdwMessageDialog*> (gobj ()));
  }

  auto
  MessageDialog::get_close_response () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_close_response (
            const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_default_response () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_default_response (
            const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_extra_child () const -> Gtk::Widget*
  {
    return Glib::wrap (adw_message_dialog_get_extra_child (
        const_cast<AdwMessageDialog*> (gobj ())));
  }

  auto
  MessageDialog::get_heading () const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
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
  MessageDialog::get_response_appearance (const Glib::ustring& response) const -> ResponseAppearance
  {
    return static_cast<ResponseAppearance> (
        adw_message_dialog_get_response_appearance (
            const_cast<AdwMessageDialog*> (gobj ()),
            response.c_str ()));
  }

  auto
  MessageDialog::get_response_enabled (const Glib::ustring& response) const -> bool
  {
    return adw_message_dialog_get_response_enabled (
        const_cast<AdwMessageDialog*> (gobj ()),
        response.c_str ());
  }

  auto
  MessageDialog::get_response_label (const Glib::ustring& response) const -> Glib::ustring
  {
    return Glib::convert_const_gchar_ptr_to_ustring (
        adw_message_dialog_get_response_label (
            const_cast<AdwMessageDialog*> (gobj ()),
            response.c_str ()));
  }

  auto
  MessageDialog::has_response (const Glib::ustring& response) const -> bool
  {
    return adw_message_dialog_has_response (
        const_cast<AdwMessageDialog*> (gobj ()),
        response.c_str ());
  }

  auto
  MessageDialog::response (const Glib::ustring& response) -> void
  {
    adw_message_dialog_response (gobj (), response.c_str ());
  }

  auto
  MessageDialog::set_body (const Glib::ustring& body) -> void
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
  MessageDialog::set_close_response (const Glib::ustring& response) -> void
  {
    adw_message_dialog_set_close_response (gobj (), response.c_str ());
  }

  auto
  MessageDialog::set_default_response (const Glib::ustring& response) -> void
  {
    adw_message_dialog_set_default_response (gobj (), response.c_str ());
  }

  auto
  MessageDialog::set_extra_child (Gtk::Widget* child) -> void
  {
    adw_message_dialog_set_extra_child (gobj (),
                                        (GtkWidget*) Glib::unwrap (child));
  }

  auto
  MessageDialog::set_heading (const Glib::ustring& heading) -> void
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
  MessageDialog::set_response_appearance (const Glib::ustring& response,
                                          ResponseAppearance appearance) -> void
  {
    adw_message_dialog_set_response_appearance (
        gobj (),
        response.c_str (),
        static_cast<AdwResponseAppearance> (appearance));
  }

  auto
  MessageDialog::set_response_enabled (const Glib::ustring& response,
                                       bool enabled) -> void
  {
    adw_message_dialog_set_response_enabled (gobj (),
                                             response.c_str (),
                                             static_cast<int> (enabled));
  }

  auto
  MessageDialog::set_response_label (const Glib::ustring& response,
                                     const Glib::ustring& label) -> void
  {
    adw_message_dialog_set_response_label (gobj (),
                                           response.c_str (),
                                           label.c_str ());
  }

  auto
  MessageDialog::signal_response (const Glib::ustring& response) -> Glib::SignalProxyDetailed<void (const Glib::ustring&)>
  {
    return Glib::SignalProxyDetailed<void (const Glib::ustring&)> (
        this,
        &MessageDialog_signal_response_info,
        response);
  }

  auto
  MessageDialog::property_body () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "body");
  }

  auto
  MessageDialog::property_body () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "body");
  }

  auto
  MessageDialog::property_body_use_markup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "body-use-markup");
  }

  auto
  MessageDialog::property_body_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "body-use-markup");
  }

  auto
  MessageDialog::property_close_response () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "close-response");
  }

  auto
  MessageDialog::property_close_response () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "close-response");
  }

  auto
  MessageDialog::property_default_response () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "default-response");
  }

  auto
  MessageDialog::property_default_response () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this,
                                                        "default-response");
  }

  auto
  MessageDialog::property_extra_child () -> Glib::PropertyProxy<Gtk::Widget*>
  {
    return Glib::PropertyProxy<Gtk::Widget*> (this, "extra-child");
  }

  auto
  MessageDialog::property_extra_child () const -> Glib::PropertyProxy_ReadOnly<Gtk::Widget*>
  {
    return Glib::PropertyProxy_ReadOnly<Gtk::Widget*> (this, "extra-child");
  }

  auto
  MessageDialog::property_heading () -> Glib::PropertyProxy<Glib::ustring>
  {
    return Glib::PropertyProxy<Glib::ustring> (this, "heading");
  }

  auto
  MessageDialog::property_heading () const -> Glib::PropertyProxy_ReadOnly<Glib::ustring>
  {
    return Glib::PropertyProxy_ReadOnly<Glib::ustring> (this, "heading");
  }

  auto
  MessageDialog::property_heading_use_markup () -> Glib::PropertyProxy<bool>
  {
    return Glib::PropertyProxy<bool> (this, "heading-use-markup");
  }

  auto
  MessageDialog::property_heading_use_markup () const -> Glib::PropertyProxy_ReadOnly<bool>
  {
    return Glib::PropertyProxy_ReadOnly<bool> (this, "heading-use-markup");
  }

  auto
  Adw::MessageDialog::on_response (const Glib::ustring& response) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->response)
      (*base->response) (gobj (), response.c_str ());
  }

  auto
  Adw::MessageDialog::response_vfunc (const Glib::ustring& response) -> void
  {
    const auto base = static_cast<BaseClassType*> (
        g_type_class_peek_parent (G_OBJECT_GET_CLASS (gobject_)));

    if (base && base->response)
    {
      (*base->response) (gobj (), response.c_str ());
    }
  }

} // namespace Adw
