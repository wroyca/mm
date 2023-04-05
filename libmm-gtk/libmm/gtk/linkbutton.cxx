// SPDX-License-Identifier: LGPL-2.1-or-later

#include <libmm/glib/mm-glib.hxx>

#include <libmm/gtk/linkbutton.hxx>
#include <libmm/gtk/linkbutton_p.hxx>

#include <gtk/gtk.h>

namespace
{

  static auto
  LinkButton_signal_activate_link_callback (GtkLinkButton* self, void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<bool ()>;

    auto obj = dynamic_cast<LinkButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          return static_cast<int> ((*static_cast<SlotType*> (slot)) ());
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static auto
  LinkButton_signal_activate_link_notify_callback (GtkLinkButton* self,
                                                   void* data) -> gboolean
  {
    using namespace gtk;
    using SlotType = sigc::slot<void ()>;

    auto obj = dynamic_cast<LinkButton*> (
        glib::ObjectBase::_get_current_wrapper ((GObject*) self));

    if (obj)
    {
      try
      {
        if (const auto slot = glib::SignalProxyNormal::data_to_slot (data))
          (*static_cast<SlotType*> (slot)) ();
      }
      catch (...)
      {
        glib::exception_handlers_invoke ();
      }
    }

    using RType = gboolean;
    return RType ();
  }

  static const glib::SignalProxyInfo LinkButton_signal_activate_link_info = {
      "activate-link",
      (GCallback) &LinkButton_signal_activate_link_callback,
      (GCallback) &LinkButton_signal_activate_link_notify_callback};

} // namespace

namespace glib
{

  auto
  wrap (GtkLinkButton* object, bool take_copy) -> gtk::LinkButton*
  {
    return dynamic_cast<gtk::LinkButton*> (
        glib::wrap_auto ((GObject*) (object), take_copy));
  }

} // namespace glib

namespace gtk
{

  auto
  LinkButton_Class::init () -> const glib::Class&
  {
    if (!gtype_)
    {
      class_init_func_ = &LinkButton_Class::class_init_function;

      register_derived_type (gtk_link_button_get_type ());
    }

    return *this;
  }

  auto
  LinkButton_Class::class_init_function (void* g_class, void* class_data) -> void
  {
    const auto klass = static_cast<BaseClassType*> (g_class);
    CppClassParent::class_init_function (klass, class_data);
  }

  auto
  LinkButton_Class::wrap_new (GObject* o) -> glib::ObjectBase*
  {
    return manage (new LinkButton ((GtkLinkButton*) (o)));
  }

  LinkButton::LinkButton (const glib::ConstructParams& construct_params)
    : gtk::Button (construct_params)
  {
  }

  LinkButton::LinkButton (GtkLinkButton* castitem)
    : gtk::Button ((GtkButton*) (castitem))
  {
  }

  LinkButton::LinkButton (LinkButton&& src) noexcept
    : gtk::Button (std::move (src))
  {
  }

  auto
  LinkButton::operator= (LinkButton&& src) noexcept -> LinkButton&
  {
    gtk::Button::operator= (std::move (src));
    return *this;
  }

  LinkButton::~LinkButton () noexcept
  {
    destroy_ ();
  }

  LinkButton::CppClassType LinkButton::linkbutton_class_;

  auto
  LinkButton::get_type () -> GType
  {
    return linkbutton_class_.init ().get_type ();
  }

  auto
  LinkButton::get_base_type () -> GType
  {
    return gtk_link_button_get_type ();
  }

  LinkButton::LinkButton ()
    : glib::ObjectBase (nullptr),
      gtk::Button (glib::ConstructParams (linkbutton_class_.init ()))
  {
  }

  LinkButton::LinkButton (const glib::ustring& uri, const glib::ustring& label)
    : glib::ObjectBase (nullptr),
      gtk::Button (glib::ConstructParams (linkbutton_class_.init (),
                                          "uri",
                                          uri.c_str (),
                                          "label",
                                          label.c_str (),
                                          nullptr))
  {
  }

  auto
  LinkButton::get_uri () const -> glib::ustring
  {
    return glib::convert_const_gchar_ptr_to_ustring (
        gtk_link_button_get_uri (const_cast<GtkLinkButton*> (gobj ())));
  }

  auto
  LinkButton::set_uri (const glib::ustring& uri) -> void
  {
    gtk_link_button_set_uri (gobj (), uri.c_str ());
  }

  auto
  LinkButton::get_visited () const -> bool
  {
    return gtk_link_button_get_visited (const_cast<GtkLinkButton*> (gobj ()));
  }

  auto
  LinkButton::set_visited (bool visited) -> void
  {
    gtk_link_button_set_visited (gobj (), static_cast<int> (visited));
  }

  auto
  LinkButton::signal_activate_link () -> glib::SignalProxy<bool ()>
  {
    return glib::SignalProxy<bool ()> (this,
                                       &LinkButton_signal_activate_link_info);
  }

  auto
  LinkButton::property_uri () -> glib::PropertyProxy<glib::ustring>
  {
    return glib::PropertyProxy<glib::ustring> (this, "uri");
  }

  auto
  LinkButton::property_uri () const -> glib::PropertyProxy_ReadOnly<glib::ustring>
  {
    return glib::PropertyProxy_ReadOnly<glib::ustring> (this, "uri");
  }

  auto
  LinkButton::property_visited () -> glib::PropertyProxy<bool>
  {
    return glib::PropertyProxy<bool> (this, "visited");
  }

  auto
  LinkButton::property_visited () const -> glib::PropertyProxy_ReadOnly<bool>
  {
    return glib::PropertyProxy_ReadOnly<bool> (this, "visited");
  }

} // namespace gtk
